#ifndef __TLGE__CAMERA_H__
#define __TLGE__CAMERA_H__

namespace TLGE
{
	/**************************************************************************
	* Camera is a component that identifies an object as a camera             *
	***************************************************************************/
	class Camera : public Component
	{
	public:
		//Object in charge is set on creation and cannot be changed
		Camera(GameObject* objectInCharge);
		virtual ~Camera();

		//Regular update.
		virtual void Update(float deltaTime);

		//Gets called whenever an event happens
		virtual void HandleEvent(Event* event);

		//Returns the inverse of the camera's transform
		virtual glm::mat4 GetViewTransform();

		//Special getter for the projection transform
		glm::mat4 GetProjectionTransform();

		//Getters
		bool IsPerspective() { return m_isPerspective; }
		float GetNear() { return m_near; }
		float GetFovY() { return m_fovY; }
		float GetOrthoHalfBox() { return m_orthoHalfBox; }
		float GetRatio() { return m_ratio; }

		//Setters
		void SetIsPerspective(bool as) { m_isPerspective = as; }

	protected:
		//Creates a valid projection transform using camera info
		void ValidateProjectionTransform();

		bool m_projTransformValid;

		bool m_isPerspective;
		glm::mat4 m_projectionTransform;

		float m_near;
		float m_fovY;
		float m_ratio;
		float m_orthoHalfBox;
	};
}

#endif