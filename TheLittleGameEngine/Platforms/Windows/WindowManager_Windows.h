#ifndef __TLGE__WINDOW_MANAGER_WINDOWS_H__
#define __TLGE__WINDOW_MANAGER_WINDOWS_H__

#include "../../Core/WindowManager.h"

namespace TLGE
{
	/**************************************************************************
	* WindowManager_Windows implements the WindowManager interface on Windows *
	*                                                                         *
	* Important notes:                                                        *
	*	-This is a windows specific class and should not be loaded on other   *
	*		platforms                                                         *
	***************************************************************************/
	class WindowManager_Windows : public WindowManager
	{
	public:
		WindowManager_Windows();
		virtual ~WindowManager_Windows();

		//This function creates an empty window of the right size with the right name and the right icon
		virtual void CreateGameWindow();

		//This function creates the gl context and makes it current as well as loads the functions that are needed from openGL
		virtual void CreateGLContext();

		//This function destroys the gl context
		virtual void DestroyGLContext();

		//This function swaps the buffers
		virtual void SwapCurrentBuffer();

		//This function checks for inputs and creates events based on them
		virtual void ReceiveInput();

		//Getters
		char* GetName() { return m_name; }
		char* GetIconFilepath() { return m_iconFilepath; }

		//Setters
		void SetInstanceHandle(HINSTANCE handle) { m_instanceHandle = handle; }
		void SetShowCommand(int command) { m_showCommand = command; }
		void SetName(char* name) { m_name = name; }
		void SetIconFilepath(char* filepath) { m_iconFilepath = filepath; }

	private:
		HINSTANCE m_instanceHandle;
		int m_showCommand;

		HWND m_windowHandle;
		HDC m_deviceContex;
		HGLRC m_glContextHandle;
		TRACKMOUSEEVENT m_mouseEvent;

		char* m_name;
		char* m_iconFilepath;
	};
}

#endif