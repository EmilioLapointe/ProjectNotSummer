#ifndef __TLGE__GRAPHICS_H__
#define __TLGE__GRAPHICS_H__

namespace TLGE
{
	class Scene;
	class Event;

	/**************************************************************************
	* Graphics is the visual system of The Little Game Engine. It looks for   *
	* model components and draws them on screen.                              *
	*                                                                         *
	* Important notes:                                                        *
	*	-Graphics is tied to OpenGL ES 2.0 and must be changed if the         *
	*		graphics library is changed                                       *
	***************************************************************************/
	class Graphics : public System
	{
	public:
		//Scene in charge is set on creation and cannot be changed
		Graphics(Scene* sceneInCharge);
		virtual ~Graphics();

		//Regular update
		void Update(float deltaTime);

		//Loads lost or unloaded information(usefull for phone applications)
		void Load();

		//Gets called whenever an event happens
		void HandleEvent(Event* event);

		//Special getter for the camera to handle special cases
		Camera* GetCurrentCamera();
		//Special Setter for the camera to take in a gameObject insted of the component
		void SetCurrentCamera(GameObject* object);

		//Setters
		void SetCurrentCamera(Camera* camera) { m_currentCamera = camera; }

	private:
		Camera* m_currentCamera;
	};
}

#endif