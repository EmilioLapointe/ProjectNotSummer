#include "EnginePCH.h"
#include "TLGE_Windows.h"
namespace TLGE
{
	WindowManager_Windows::WindowManager_Windows() :
		WindowManager(),
		m_name("The Little Game Engine"),
		m_iconFilepath("")
	{
		m_width = 500;
		m_height = 500;
	}
	WindowManager_Windows::~WindowManager_Windows()
	{
		DestroyGLContext();
	}

	void WindowManager_Windows::CreateGameWindow()
	{
		//Adding the engine prefix to the name to get the className
		char* classNamePrefix = "TLGE_";
		unsigned int classNameLength = 1 + strlen(classNamePrefix) + strlen(m_name);
		char* className = (char *)malloc(classNameLength);
		strcpy_s(className, classNameLength, classNamePrefix);
		strcat_s(className, classNameLength, m_name);

		//Creating an instance of a window class and filling it
		WNDCLASSEX windowClass;

		windowClass.cbSize = sizeof(WNDCLASSEX);
		windowClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
		windowClass.lpfnWndProc = WndProc;
		windowClass.cbClsExtra = 0;
		windowClass.cbWndExtra = 0;
		windowClass.hInstance = m_instanceHandle;
		windowClass.hIcon = (HICON)LoadImage(
			NULL,
			m_iconFilepath,
			IMAGE_ICON,
			0,
			0,
			LR_LOADFROMFILE | LR_DEFAULTSIZE
		);
		windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
		windowClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
		windowClass.lpszMenuName = NULL;
		windowClass.lpszClassName = className;
		windowClass.hIconSm = NULL;

		//Attempting to register the window class
		if (!RegisterClassEx(&windowClass))
		{
			MessageBox(NULL, "Failed to register window class", "Fatal Error", NULL);
			return;
		}

		//Attempting to create a window in our window class
		m_windowHandle = CreateWindow(
			className,
			m_name,
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, CW_USEDEFAULT,
			m_width, m_height,
			NULL,
			NULL,
			m_instanceHandle,
			NULL
		);

		//Checking if window was created succesfuly
		if (!m_windowHandle)
		{
			MessageBox(NULL, "Failed to create window", "Fatal Error", NULL);

			return;
		}

		// Activating the window to be shown
		ShowWindow(m_windowHandle, m_showCommand);

		m_mouseEvent.dwFlags = TME_LEAVE;
		m_mouseEvent.hwndTrack = m_windowHandle;

		free(className);
	}

	void WindowManager_Windows::CreateGLContext()
	{
		//Getting the device contex
		m_deviceContex = GetDC(m_windowHandle);

		//Create a pixel format descriptor
		PIXELFORMATDESCRIPTOR pfd =
		{
			sizeof(PIXELFORMATDESCRIPTOR),
			1,
			PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
			PFD_TYPE_RGBA,
			32,                        //Colordepth
			0, 0, 0, 0, 0, 0, 0, 0,
			0,
			0, 0, 0, 0,
			24,                        //Depthbuffer
			8,                        //Stencilbuffer
			0,
			PFD_MAIN_PLANE,
			0,
			0, 0, 0
		};

		//Asking windows for a pixel format
		int pixelFormat = ChoosePixelFormat(m_deviceContex, &pfd);

		//Checking if windows found a pixel format
		if (!pixelFormat)
		{
			MessageBox(NULL, "Failed to choose a pixel format", "Fatal Error", NULL);

			return;
		}

		//Trying to set the pixel format
		if (!SetPixelFormat(m_deviceContex, pixelFormat, &pfd))
		{
			MessageBox(NULL, "Failed to set the pixel format", "Fatal Error", NULL);

			return;
		}

		//Trying to greate a GL rendering context
		HGLRC m_glContextHandle = wglCreateContext(m_deviceContex);

		//Checking if we managed to create a GL rendering context
		if (m_glContextHandle == NULL)
		{
			MessageBox(NULL, "Failed to create a GL rendering context", "Fatal Error", NULL);

			return;
		}

		//Trying to activate the context
		if (!wglMakeCurrent(m_deviceContex, m_glContextHandle))
		{
			MessageBox(NULL, "Failed to make the GL rendering context current", "Fatal Error", NULL);

			return;
		}

		BindFunctions();
	}

	void WindowManager_Windows::DestroyGLContext()
	{
		wglMakeCurrent(m_deviceContex, NULL);
		if (!wglDeleteContext(m_glContextHandle))
		{
			MessageBox(NULL, "Failed to delete the GL rendering context", "Fatal Error", NULL);

			return;
		}
	}

	void WindowManager_Windows::SwapCurrentBuffer()
	{
		SwapBuffers(m_deviceContex);
	}

	void WindowManager_Windows::ReceiveInput()
	{
		MSG msg;

		while (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}