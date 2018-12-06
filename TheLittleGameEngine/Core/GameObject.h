#ifndef _TLGE__GameObject_H__
#define _TLGE__GameObject_H__

namespace TLGE
{
	class Component;

	class GameObject
	{
		friend class Scene;
	protected:
		Scene* m_pScene;
		bool m_enabled;
		GameObject* m_parent;
		
		std::string m_Name;
		std::vector<GameObject*> m_Children;
		std::vector<Component*> m_components;

	public:
		GameObject(std::string name);
		virtual ~GameObject();

		void Load();
		virtual void Update(float deltatime);
		virtual void LateUpdate(float deltatime);

		std::string GetName() { return m_Name; }

		bool GetEnabled();
		void SetEnabled(bool enabled);

		void OnEvent(Event* event);

		template<typename T> T* AddComponent()
		{
			//TODO: fix 0 to nullptr
			if (GetComponent<T>() == 0)
			{
				Component* component = (Component*) new T(this);
				m_components.push_back(component);
				return (T*)component;
			}
			else
			{
				return GetComponent<T>();
			}
		}
		//void RemoveComponent(std::string aName);//emillio
		template<typename T> T* GetComponent()
		{
			if (m_components.size() == 0)
				return 0;
			for (std::vector<Component*>::iterator it = m_components.begin(); it != m_components.end(); it++)
			{
				//TODO: delete all dynamic casts
				if (dynamic_cast<T*>(*it))
				{
					return dynamic_cast<T*>(*it);
				}
			}
			//TODO: fix 0 to nullptr
			return 0;
		}

		template<typename T> void RequireComponent()
		{
			//TODO: fix 0 to nullptr
			if (GetComponent<T>() == 0)
			{
				AddComponent<T>();
			}
		}

		void AddChild(GameObject* object);
		void RemoveChild(std::string name);
		GameObject* GetChild(std::string name);//sorts through

		//Getters
		std::vector<GameObject*> GetChildren() { return m_Children; };
		GameObject* GetParent() { return m_parent; }
		Scene* GetScene() { return m_pScene; }

		//Special setter for scene
	private:
		void SetScene(Scene* scene);


	};
}

#endif //_TLGE__GameObject_H__
