#include "EnginePCH.h"

namespace TLGE
{
	Transform::Transform(GameObject* aObjectInCharge):
		Component(aObjectInCharge),
		m_position(0.0f),
		m_scale(1.0f),
		m_rotation(glm::vec3(0.0f, 0.0f, 0.0f)),
		m_matrixUpdated(false),
		m_worldTransform(1.0f)
	{
		//nothing to do
	}
	Transform::~Transform()
	{
		//nothing to do
	}

	void Transform::Update(float aDeltaTime)
	{
		//nothing to do
	}
	void Transform::Load()
	{
		//nothing to do
	}

	glm::mat4 Transform::GetWorldTransform()
	{
		if (!m_matrixUpdated)
		{
			//Reset to identity
			m_worldTransform = glm::mat4(1.0f);
			
			//Apply position
			m_worldTransform = glm::translate(m_worldTransform, m_position);

			//Apply rotation
			m_worldTransform = m_worldTransform * glm::mat4_cast(m_rotation);

			//Apply scale
			m_worldTransform = glm::scale(m_worldTransform, m_scale);

			m_matrixUpdated = true;
		}

		if (GetObjectInCharge()->GetParent())
		{
			if (GetObjectInCharge()->GetParent()->GetComponent<Transform>())
			{
				return GetObjectInCharge()->GetParent()->GetComponent<Transform>()->GetWorldTransform() * m_worldTransform;
			}
		}

		return m_worldTransform;
	}

	void Transform::Translate(glm::vec3 aTranslation)
	{
		m_position += aTranslation;
		m_matrixUpdated = false;
	}

	void Transform::Scale(glm::vec3 aScale)
	{
		m_scale *= aScale;
		m_matrixUpdated = false;
	}

	void Transform::RotateX(float aAngle)
	{
		m_rotation = glm::rotate(m_rotation, aAngle, glm::vec3(1, 0, 0));
		m_matrixUpdated = false;
	}
	void Transform::RotateY(float aAngle)
	{
		m_rotation = glm::rotate(m_rotation, aAngle, glm::vec3(0, 1, 0));
		m_matrixUpdated = false;
	}
	void Transform::RotateZ(float aAngle)
	{
		m_rotation = glm::rotate(m_rotation, aAngle, glm::vec3(0, 0, 1));
		m_matrixUpdated = false;
	}
	void Transform::RotateAxis(float aAngle, glm::vec3 aAxis)
	{
		m_rotation = glm::rotate(m_rotation, aAngle, aAxis);
		m_matrixUpdated = false;
	}

	glm::vec3 Transform::GetEulerRotation()
	{
		return glm::eulerAngles(m_rotation);
	}
	void Transform::SetRotation(glm::vec3 aRotations)
	{
		m_rotation = glm::quat(aRotations);
		m_matrixUpdated = false;
	}
}