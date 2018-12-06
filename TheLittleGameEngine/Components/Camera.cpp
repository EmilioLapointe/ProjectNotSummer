#include "EnginePCH.h"

namespace TLGE
{
	Camera::Camera(GameObject* aObjectInCharge):
		Component(aObjectInCharge),
		m_projTransformValid(false),
		m_isPerspective(false),
		m_projectionTransform(1.0f),
		m_near(0.1f),
		m_fovY(45.0f),
		m_orthoHalfBox(100.0f)
	{
		aObjectInCharge->RequireComponent<Transform>();
	}
	Camera::~Camera()
	{
		//nothing to do
	}

	void Camera::Update(float aDeltaTime)
	{
		//nothing to do
	}

	void Camera::HandleEvent(Event* aEvent)
	{
		if (strcmp(aEvent->GetType(), "RESIZE") == 0)
		{
			m_projTransformValid = false;
		}
	}

	glm::mat4 Camera::GetViewTransform()
	{
		return glm::inverse(m_objectInCharge->GetComponent<Transform>()->GetWorldTransform());
	}

	glm::mat4 Camera::GetProjectionTransform()
	{
		if (m_projTransformValid)
		{
			return m_projectionTransform;
		}

		ValidateProjectionTransform();
		return m_projectionTransform;
	}

	void Camera::ValidateProjectionTransform()
	{
		m_ratio = ((float)(GameCore::GetInstance()->GetWindowManager()->GetWidth())) / ((float)(GameCore::GetInstance()->GetWindowManager()->GetHeight()));
		if (m_ratio == 0.0f)
		{
			m_ratio = 1.0f;
		}
		//TODO: make this not hard coded
		if (m_isPerspective)
		{
			m_projectionTransform = glm::perspective(m_fovY, m_ratio, m_near, 1000.0f);
		}
		else
		{
			m_projectionTransform = glm::ortho(-m_orthoHalfBox * m_ratio, m_orthoHalfBox * m_ratio, -m_orthoHalfBox, m_orthoHalfBox, -m_orthoHalfBox, m_orthoHalfBox);
		}
	}
}