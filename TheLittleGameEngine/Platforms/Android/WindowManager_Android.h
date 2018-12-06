#ifndef __TLGE__WINDOW_MANAGER_ANDROID_H__
#define __TLGE__WINDOW_MANAGER_ANDROID_H__

#include "../../Core/WindowManager.h"

struct TLGEngine {
	struct android_app* app;

	EGLDisplay display;
	EGLSurface surface;
	EGLContext context;

	TLGE::GameCore* gameCore;
};

namespace TLGE
{
	/**************************************************************************
	* WindowManager_Android implements the WindowManager interface on Windows *
	*                                                                         *
	* Important notes:                                                        *
	*	-This is an Android specific class and should not be loaded on other  *
	*		platforms                                                         *
	***************************************************************************/
	class WindowManager_Android : public WindowManager
	{
	public:
		WindowManager_Android(android_app* state, TLGEngine* engine);
		virtual ~WindowManager_Android();

		//This function creates an empty window of the right size with the right name and the right icon
		virtual void CreateGameWindow();

		//This function creates the gl context and makes it current as well as loads the functions that are needed from openGL
		virtual void CreateGLContext();

		//This function creates the gl contex
		virtual void DestroyGLContext();

		//This function swaps the buffers
		virtual void SwapCurrentBuffer();

		//This function checks for inputs and creates events based on them
		virtual void ReceiveInput();

	private:
		struct android_app* m_state;
		struct TLGEngine* m_engine;
		EGLDisplay m_display;
		EGLConfig m_config;
		EGLSurface m_surface;
	};
}

#endif