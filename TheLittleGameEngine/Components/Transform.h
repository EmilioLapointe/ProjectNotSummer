#ifndef __TLGE__TRANSFORM_H__
#define __TLGE__TRANSFORM_H__

//TODO:Implement actual Transform component

namespace TLGE
{
	/**************************************************************************
	* Transform is a class that holds position, rotation and scale            *
	* information for an object                                               *
	***************************************************************************/
	class Transform : public Component
	{
	public:
		//Object in charge is set on creation and cannot be changed
		Transform(GameObject* objectInCharge);
		virtual ~Transform();

		//Regular update.
		void Update(float deltaTime);
		//Loads lost or unloaded information(usefull for phone applications)
		void Load();

		//Returns an updated world transform matrix
		glm::mat4 GetWorldTransform();

		//Translates the object by a vec3
		void Translate(glm::vec3 translation);

		//Scales the object by a vec3
		void Scale(glm::vec3 scale);

		//Rotates on given axis
		void RotateX(float angle);
		void RotateY(float angle);
		void RotateZ(float angle);
		void RotateAxis(float angle, glm::vec3 axis);

		//Euler rotation Getter and setter
		glm::vec3 GetEulerRotation();
		void SetRotation(glm::vec3 rotations);

		//Getters
		glm::vec3 GetPosition() { return m_position; }
		glm::vec3 GetScale() { return m_scale; }
		glm::quat GetQuatRotation() { return m_rotation; }

		//Setters
		void SetPosition(glm::vec3 position) { m_position = position; m_matrixUpdated = false; }
		void SetScale(glm::vec3 scale)		 { m_scale = scale;       m_matrixUpdated = false; }
		void SetRotation(glm::quat rotation) { m_rotation = rotation; m_matrixUpdated = false; }

	private:
		glm::vec3 m_position;
		glm::vec3 m_scale;
		glm::quat m_rotation;
		bool m_matrixUpdated;
		glm::mat4 m_worldTransform;
	};
}

#endif