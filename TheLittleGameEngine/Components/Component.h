#ifndef __TLGE__COMPONENT_H__
#define __TLGE__COMPONENT_H__

namespace TLGE
{
	class GameObject;
	class Event;

	/**************************************************************************
	* Component is one of the 3 parts of the entity, component, system        *
	* pattern. It defines functionality and stored information for game       *
	* objects. The System class will act on specific components as needed.    *
	*                                                                         *
	* Important notes:                                                        *
	*	-Component instances should be unique and tied strongly to their      *
	*		respective game object                                            *
	*	-Component is an abstract class and cannot be instantiated            *
	***************************************************************************/
	class Component
	{
	public:
		//Object in charge is set on creation and cannot be changed
		Component(GameObject* objectInCharge);
		virtual ~Component();

		//Regular update. Must be overwritten.
		virtual void Update(float deltaTime) = 0;
		//Update that happens after the normal and fixed(only if there is one at this time) updates
		virtual void LateUpdate(float deltaTime) {}
		//Update that happens every FIXED_UPDATE_TIMESTEP seconds
		virtual void FixedUpdate() {}

		//Should load lost or unloaded information(usefull for phone applications)
		virtual void Load() {}

		//Gets called whenever an event happens
		virtual void HandleEvent(Event* event) {}

		//Getters
		GameObject* GetObjectInCharge() { return m_objectInCharge; }

	protected:
		GameObject* m_objectInCharge;
	};
}

#endif