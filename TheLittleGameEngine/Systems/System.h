#ifndef __TLGE__SYSTEM_H__
#define __TLGE__SYSTEM_H__

namespace TLGE
{
	class Scene;
	class Event;

	/**************************************************************************
	* System is one of the 3 parts of the entity, component, system pattern.  *
	* It provides an entire subsystem of functionality to the engine. It is   *
	* intended for use on scene wide effects on (or using) components.        *
	*                                                                         *
	* Important notes:                                                        *
	*	-System instances should be unique and tied strongly to their         *
	*		respective scene                                                  *
	*	-System is an abstract class and cannot be instantiated               *
	***************************************************************************/
	class System
	{
	public:
		//Scene in charge is set on creation and cannot be changed
		System(Scene* sceneInCharge);
		virtual ~System();

		//Regular update. Must be overwritten.
		virtual void Update(float deltaTime) = 0;

		//Should load lost or unloaded information(usefull for phone applications)
		virtual void Load() {}

		//Gets called whenever an event happens
		virtual void HandleEvent(Event* event) {}

		//Getters
		Scene* GetSceneInCharge() { return m_sceneInCharge; }
		bool GetActive() { return m_active; }

		//Setters
		void SetActive(bool active) { m_active = active; }

	protected:
		Scene* m_sceneInCharge;
		bool m_active;
	};
}

#endif