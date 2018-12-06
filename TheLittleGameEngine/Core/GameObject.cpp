#include "EnginePCH.h"

namespace TLGE
{
	GameObject::GameObject(std::string name) :
		m_enabled(true),
		m_parent(0)
	{
		m_Name = name;
	}

	GameObject::~GameObject()
	{
	}

	void GameObject::Load()
	{
		for (std::vector<Component*>::iterator it = m_components.begin(); it != m_components.end(); it++)
		{
			(*it)->Load();
		}
		for (std::vector<GameObject*>::iterator it = m_Children.begin(); it != m_Children.end(); it++)
		{
			(*it)->Load();
		}
	}
	void GameObject::Update(float aDeltatime)
	{
		for (std::vector<Component*>::iterator it = m_components.begin(); it != m_components.end(); it++)
		{
			(*it)->Update(aDeltatime);
		}
		for (std::vector<GameObject*>::iterator it = m_Children.begin(); it != m_Children.end(); it++)
		{
			(*it)->Update(aDeltatime);
		}
	}

	void GameObject::LateUpdate(float aDeltatime)
	{
		for (std::vector<Component*>::iterator it = m_components.begin(); it != m_components.end(); it++)
		{
			(*it)->LateUpdate(aDeltatime);
		}
		for (std::vector<GameObject*>::iterator it = m_Children.begin(); it != m_Children.end(); it++)
		{
			(*it)->LateUpdate(aDeltatime);
		}
	}

	bool GameObject::GetEnabled()
	{
		return m_enabled;
	}
	void GameObject::SetEnabled(bool enabled)
	{
		m_enabled = enabled;
	}
	void GameObject::OnEvent(Event* aEvent)
	{
		for (unsigned int i = 0; i < m_components.size(); i++)
		{
			m_components[i]->HandleEvent(aEvent);
		}
		for (unsigned int i = 0; i < m_Children.size(); i++)
		{
			m_Children[i]->OnEvent(aEvent);
		}
	}
	void GameObject::AddChild(GameObject* object)
	{
		m_Children.push_back(object);
		object->SetScene(m_pScene);
		object->m_parent = this;
	}
	void GameObject::RemoveChild(std::string name)
	{
		//itterate through then remove
		std::vector<GameObject*>::iterator it = m_Children.begin();
		while ( it != m_Children.end() && (*it)->GetName()!= name)
		{
			it++;
		}
		(*it)->m_parent = 0;
		m_Children.erase(it);
	}
	GameObject* GameObject::GetChild(std::string name)//sorts through
	{
		std::vector<GameObject*>::iterator it = m_Children.begin();
		while (it != m_Children.end() && (*it)->GetName() != name)
		{
			it++;
		}
		return *it;
	}
	void GameObject::SetScene(Scene* aScene)
	{
		m_pScene = aScene;
		for (unsigned int i = 0; i < m_Children.size(); i++)
		{
			m_Children[i]->SetScene(aScene);
		}
	}
}