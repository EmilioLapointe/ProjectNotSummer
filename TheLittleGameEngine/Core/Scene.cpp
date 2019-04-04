#include "EnginePCH.h"
namespace TLGE
{

	Scene::Scene(char* aName)
	{
		m_name = aName;
		m_ObjectRoot = new GameObject("Root");
		m_ObjectRoot->AddComponent<Transform>();
		m_ObjectRoot->SetScene(this);
		GameCore::GetInstance()->GetSceneManager()->AddScene(this);
	}

	Scene::~Scene()
	{

	}

	void Scene::LoadContent()
	{
		for (std::vector<System*>::iterator it = m_Systems.begin(); it != m_Systems.end(); it++)
		{
			(*it)->Load();
		}
		m_ObjectRoot->Load();
	}

	void Scene::OnEvent(Event* aEvent)
	{
		for (unsigned int i = 0; i < m_Systems.size(); i++)
		{
			m_Systems[i]->HandleEvent(aEvent);
		}
		m_ObjectRoot->OnEvent(aEvent);
	}

	void Scene::Update(float aDeltatime)
	{
		m_ObjectRoot->Update(aDeltatime);

		Tween::Update(this, aDeltatime);

		for (std::vector<System*>::iterator it = m_Systems.begin(); it != m_Systems.end(); it++)
		{
			(*it)->Update(aDeltatime);
		}
	}

	void Scene::AddGameObject(GameObject* object)
	{
		m_ObjectRoot->AddChild(object);
		object->SetScene(this);
	}

	void Scene::RemoveGameObject(std::string name)
	{
		m_ObjectRoot->RemoveChild(name);
	}
	void Scene::DeleteGameObject(std::string name)
	{
		m_ObjectRoot->GetChild(name)->~GameObject();
	}
	GameObject* Scene::GetGameObject(std::string name)
	{
		//TODO: fix 0 to nullptr
		//TODO: double check if this is intentional
		return 0;
	}
}
