#include "EnginePCH.h"

namespace TLGE
{
	SceneManager::SceneManager():
		hasBacked(false)
	{

	}
	SceneManager::~SceneManager()
	{
		ActiveScenes.clear();

		for (std::vector<Scene*>::iterator it = SceneList.begin(); it != SceneList.end(); it++)
		{
			delete (*it);
		}
		SceneList.clear();
	}
	void SceneManager::Back()
	{
		hasBacked = true;
	}
	void SceneManager::DoBack()
	{
		if (hasBacked)
		{
			std::vector<Scene*>::iterator it = ActiveScenes.end();
			it--;
			(*it)->SetActive(false);
			ActiveScenes.pop_back();
			it = ActiveScenes.end();
			it--;
			(*it)->SetActive(true);

			hasBacked = false;
		}
	}
	void SceneManager::NextScene(std::string name)
	{
		nextScenesAdditive.push_back(name);
	}
	void SceneManager::DoNextScenes()
	{
		for (unsigned int i = 0; i < nextScenesAdditive.size(); i++)
		{
			for (std::vector<Scene*>::iterator it = SceneList.begin(); it != SceneList.end(); it++)
			{
				if (strcmp((*it)->GetName(), nextScenesAdditive[i].c_str()) == 0)
				{
					(*it)->SetActive(true);
					ActiveScenes.push_back(*it);
				}
			}
		}
		nextScenesAdditive.clear();
	}
	void SceneManager::Update(float aDelta)
	{
		DoNextScenes();
		DoBack();
		for (std::vector<Scene*>::iterator it = ActiveScenes.begin(); it != ActiveScenes.end(); it++)
		{
			if ((*it)->IsActive())
			{
				(*it)->Update(aDelta);
			}
		}
	}

	void SceneManager::LoadContent()
	{
		DoNextScenes();
		DoBack();
		if (SceneList.size() > 0)
		{
			for (std::vector<Scene*>::iterator it = SceneList.begin(); it < SceneList.end(); it++)
			{
				(*it)->LoadContent();
			}
		}
	}
	void SceneManager::OnEvent(Event* aEvent)
	{
		DoNextScenes();
		DoBack();
		for (std::vector<Scene*>::iterator it = ActiveScenes.end(); it != ActiveScenes.begin();)
		{
			it--;
			if ((*it)->IsActive())
			{
				(*it)->OnEvent(aEvent);
			}
		}
		DoNextScenes();
		DoBack();
	}
	void SceneManager::RemoveScene(char* name)
	{
		bool found = false;
		if (SceneList.size() > 0)
		{
			for (std::vector<Scene*>::iterator it = SceneList.begin(); it != SceneList.end(); it++)
			{
				if (strcmp((*it)->GetName(), name) == 0)
				{
					SceneList.erase(it);
					found = true;
					break;
				}
			}

		}
		if (found == false)
		{
			for (std::vector<Scene*>::iterator it = ActiveScenes.begin(); it != ActiveScenes.end(); it++)
			{
				if (strcmp((*it)->GetName(), name) == 0)
				{
					ActiveScenes.erase(it);
					break;
				}
			}
		}
	}

	void SceneManager::AddScene(Scene* aScene)
	{
		SceneList.push_back(aScene);
	}

	Scene* SceneManager::GetScene()
	{
		//CHECK
		std::vector<Scene*>::iterator it = ActiveScenes.end();
		it--;
		return *it;
	}
}