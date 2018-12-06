#ifndef __TLGE__WINDOW_MANAGER_H__
#define __TLGE__WINDOW_MANAGER_H__

namespace TLGE
{
	/**************************************************************************
	* WindowManager is the class in charge of creating and managing the       *
	* window. It is also in charge of creating the openGL context.            *
	*                                                                         *
	* Important notes:                                                        *
	*	-WindowManager is an interface and simply provides the function names *
	*		and parameters                                                    *
	*	-WindowManager is an abstract class and cannot be instantiated        *
	***************************************************************************/
	class WindowManager
	{
	public:
		WindowManager() {}
		virtual ~WindowManager() {}

		//This function should create an empty window of the right size
		virtual void CreateGameWindow() = 0;
		
		//This function should create the gl context and make it current as well as load the functions that are needed from openGL
		virtual void CreateGLContext() = 0;

		//This function should destroy the gl context
		virtual void DestroyGLContext() = 0;

		//This function should swap the buffers if doublebuffering
		virtual void SwapCurrentBuffer() = 0;

		//This function should check for inputs and create events based on them
		virtual void ReceiveInput() = 0;

		//Getters
		unsigned int GetWidth() { return m_width; }
		unsigned int GetHeight() { return m_height; }

		//Setters
		void SetWidth(unsigned int width) { m_width = width; }
		void SetHeight(unsigned int height) { m_height = height; }

	protected:
		unsigned int m_width;
		unsigned int m_height;
	};
}

#endif