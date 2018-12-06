#include "EnginePCH.h"

namespace TLGE
{
	WindowManager_Android::WindowManager_Android(android_app* state, TLGEngine* engine):
		WindowManager(),
		m_state(state),
		m_engine(engine)
	{
		m_height = 0;
		m_width = 0;
	}
	WindowManager_Android::~WindowManager_Android()
	{
		//nothing to do
	}

	void WindowManager_Android::CreateGameWindow()
	{
		const EGLint attribs[] = {
			EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
			EGL_BLUE_SIZE, 8,
			EGL_GREEN_SIZE, 8,
			EGL_RED_SIZE, 8,
			EGL_ALPHA_SIZE, 8,
			EGL_DEPTH_SIZE, 8,
			EGL_STENCIL_SIZE, 8,
			EGL_NONE
		};
		EGLint format;
		EGLint numConfigs;

		m_display = eglGetDisplay(EGL_DEFAULT_DISPLAY);

		eglInitialize(m_display, 0, 0);

		/* Here, the application chooses the configuration it desires. In this
		* sample, we have a very simplified selection process, where we pick
		* the first EGLConfig that matches our criteria */
		eglChooseConfig(m_display, attribs, &m_config, 1, &numConfigs);

		/* EGL_NATIVE_VISUAL_ID is an attribute of the EGLConfig that is
		* guaranteed to be accepted by ANativeWindow_setBuffersGeometry().
		* As soon as we picked a EGLConfig, we can safely reconfigure the
		* ANativeWindow buffers to match, using EGL_NATIVE_VISUAL_ID. */
		eglGetConfigAttrib(m_display, m_config, EGL_NATIVE_VISUAL_ID, &format);

		ANativeWindow_setBuffersGeometry(m_engine->app->window, 0, 0, format);

		m_surface = eglCreateWindowSurface(m_display, m_config, m_engine->app->window, NULL);
	}

	void WindowManager_Android::CreateGLContext()
	{
		EGLContext context;
		EGLint w;
		EGLint h;

		EGLint contextAttribs[] = { EGL_CONTEXT_CLIENT_VERSION, 2, EGL_NONE };
		context = eglCreateContext(m_display, m_config, NULL, contextAttribs);

		if (eglMakeCurrent(m_display, m_surface, m_surface, context) == EGL_FALSE) {
			assert(false);
		}

		eglQuerySurface(m_display, m_surface, EGL_WIDTH, &w);
		eglQuerySurface(m_display, m_surface, EGL_HEIGHT, &h);

		m_engine->display = m_display;
		m_engine->context = context;
		m_engine->surface = m_surface;

		m_width = w;
		m_height = h;
	}

	void WindowManager_Android::DestroyGLContext()
	{
		if (m_engine->display != EGL_NO_DISPLAY) {
			eglMakeCurrent(m_engine->display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
			if (m_engine->context != EGL_NO_CONTEXT) {
				eglDestroyContext(m_engine->display, m_engine->context);
			}
			if (m_engine->surface != EGL_NO_SURFACE) {
				eglDestroySurface(m_engine->display, m_engine->surface);
			}
			eglTerminate(m_engine->display);
		}
		m_engine->display = EGL_NO_DISPLAY;
		m_engine->context = EGL_NO_CONTEXT;
		m_engine->surface = EGL_NO_SURFACE;
	}

	void WindowManager_Android::SwapCurrentBuffer()
	{
		eglSwapBuffers(m_engine->display, m_engine->surface);
	}

	void WindowManager_Android::ReceiveInput()
	{
		// Read all pending events.
		int ident;
		int events;
		struct android_poll_source* source;

		// If not animating, we will block forever waiting for events.
		// If animating, we loop until all events are read, then continue
		// to draw the next frame of animation.
		while ((ident = ALooper_pollAll(0, NULL, &events, (void**)&source)) >= 0) 
		{
			// Process this event.
			if (source != NULL) 
			{
				source->process(m_state, source);
			}
		}
	}

}