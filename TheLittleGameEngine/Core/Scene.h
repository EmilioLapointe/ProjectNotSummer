#ifndef _TLGE__Scene_H__
#define _TLGE__Scene_H__

#include <string>

#include "..\Core\GameObject.h"

namespace TLGE
{
	class SceneManager;
	class System;

	//no enum for gamestate/machine

	class Scene
	{
	public:
		Scene(char* aName);
		virtual ~Scene();

		virtual void LoadContent();

		virtual void OnEvent(Event* event);
		virtual void Update(float deltatime);

		template<typename T> void AddSystem()
		{
			//Create new of supposed System
			T* temp = new T(this);

			//Trying to cast it into a system to check validity
			if (dynamic_cast<System*>(temp))
			{
				//Checking for doubles of the system
				for (std::vector<System*>::iterator it = m_Systems.begin(); it != m_Systems.end(); it++)
				{
					if (dynamic_cast<T*>(*it))
					{
						return;
					}
				}

				//If we get here then we can add the system to the list
				m_Systems.push_back((System*)temp);
			}
		}
		template<typename T> T* GetSystem()
		{
			//TODO: Make this more efficient (dynamic cast and iterator)
			for (std::vector<System*>::iterator it = m_Systems.begin(); it != m_Systems.end(); it++)
			{
				if (dynamic_cast<T*>(*it))
				{
					return dynamic_cast<T*>(*it);
				}
			}
			//TODO: fix 0 to nullptr
			return 0;
		}
		
		void AddGameObject(GameObject* object);
		void RemoveGameObject(std::string name);
		void DeleteGameObject(std::string name);

		//Getters
		char* GetName() { return m_name; }
		GameObject* GetGameObject(std::string name);
		bool IsActive() { return m_Active; }
		template<typename T> std::vector<T*> GetComponents()
		{
			std::vector<T*> components = GetComponents<T>(m_ObjectRoot);
			return components;
		}

		//Setters
		void SetActive(bool aBool) { m_Active = aBool; }

	protected:
		bool m_Active;
		GameObject* m_ObjectRoot;
		char* m_name;
		std::vector<System*> m_Systems;

		template<class T> static std::vector<T*> GetComponents(GameObject* in)
		{
			std::vector<T*> components;

			//Get the children
			std::vector<GameObject*> children = in->GetChildren();

			for (std::vector<GameObject*>::iterator it = children.begin(); it != children.end(); it++)
			{
				std::vector<T*> childComponents = GetComponents<T>(*it);
				components.insert(components.end(), childComponents.begin(), childComponents.end());
			}

			T* selfC = in->GetComponent<T>();
			//TODO: fix 0 to nullptr
			if (selfC != 0)
			{
				components.push_back(in->GetComponent<T>());
			}

			return components;
		}
	};
}

#endif //_TLGE__Scene_H__
