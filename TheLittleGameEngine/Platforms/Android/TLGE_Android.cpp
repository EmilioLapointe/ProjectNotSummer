#include "EnginePCH.h"

android_app* g_pAndroidApp = 0;
bool g_allIsNew = true;

//Makes sure nothing does what this does
#undef android_main
void android_main(struct android_app* state)
{
	g_pAndroidApp = state;

	struct TLGEngine engine;
	memset(&engine, 0, sizeof(engine));
	state->userData = &engine;
	state->onAppCmd = AndroidHandleCommand;
	state->onInputEvent = AndroidHandleInput;
	engine.app = state;

	engine.gameCore = TLGE::GameCore::GetInstance();

	TLGE::WindowManager_Android* windowManager = new TLGE::WindowManager_Android(state, &engine);
	engine.gameCore->SetWindowManager(windowManager);

	TLGE::SoundManagerAndroid* soundManager = new TLGE::SoundManagerAndroid();
	engine.gameCore->SetSoundManager(soundManager);

	int ident;
	int events;
	struct android_poll_source* source;


	while (true)
	{
		while ((ident = ALooper_pollAll(0, NULL, &events, (void**)&source)) >= 0)
		{
			// Process this event.
			if (source != NULL)
			{
				source->process(state, source);
			}
		}
		// Check if we are exiting.
		if (state->destroyRequested != 0) {
			engine.gameCore->GetWindowManager()->DestroyGLContext();
			return;
		}

		// Drawing is throttled to the screen update rate, so there
		// is no need to do timing here.
		engine_draw_frame(&engine);
	}
}
//Invalidates the auto made main
#define android_main UserAndroidMain

void AndroidHandleCommand(struct android_app* app, int32_t cmd)
{
	struct TLGEngine* engine = (struct TLGEngine*)app->userData;
	switch (cmd) 
	{
	case APP_CMD_INIT_WINDOW:
		// The window is being shown, get it ready.
		if (g_allIsNew)
		{
			User_main();
			g_allIsNew = false;
		}
		else if (engine->app->window != NULL) {
			((TLGEngine*)(app->userData))->gameCore->GetWindowManager()->CreateGLContext();
		}
		break;
	case APP_CMD_TERM_WINDOW:
		// The window is being hidden or closed, clean it up.
		((TLGEngine*)(app->userData))->gameCore->GetWindowManager()->DestroyGLContext();
		break;
	}
}

int32_t AndroidHandleInput(struct android_app* app, AInputEvent* event)
{
	//struct TLGEngine* engine = (struct TLGEngine*)app->userData;
	if (AInputEvent_getType(event) == AINPUT_EVENT_TYPE_MOTION) 
	{
		TLGE::MouseMove* move = new TLGE::MouseMove();
		move->SetPosition(glm::ivec2(AMotionEvent_getX(event, 0), AMotionEvent_getY(event, 0)));
		TLGE::GameCore::GetInstance()->AddEvent(move);

		if (AInputEvent_getSource(event) == AINPUT_SOURCE_TOUCHSCREEN)
		{
			int action = AKeyEvent_getAction(event) & AMOTION_EVENT_ACTION_MASK;
			if (action == AMOTION_EVENT_ACTION_DOWN)
			{
				TLGE::ClickEvent* click = new TLGE::ClickEvent();
				click->SetPosition(glm::ivec2(AMotionEvent_getX(event, 0), AMotionEvent_getY(event, 0)));
				click->SetState(TLGE::ClickState_JustClicked);
				TLGE::GameCore::GetInstance()->AddEvent(click);
			}
			else if (action == AMOTION_EVENT_ACTION_UP)
			{
				TLGE::ClickEvent* click = new TLGE::ClickEvent();
				click->SetPosition(glm::ivec2(AMotionEvent_getX(event, 0), AMotionEvent_getY(event, 0)));
				click->SetState(TLGE::ClickState_Unclicked);
				TLGE::GameCore::GetInstance()->AddEvent(click);
			}
			return 1;
		}
	}
	return 0;
}

void engine_draw_frame(struct TLGEngine* engine) 
{
	if (engine->display == NULL) 
	{
		// No display.
		return;
	}

	engine->gameCore->UpdateCurentTime();
	if (engine->gameCore->DoOneFrame())
	{
		ANativeActivity_finish(engine->app->activity);
		g_allIsNew = true;
	}
}
