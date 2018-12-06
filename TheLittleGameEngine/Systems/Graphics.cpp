#include "EnginePCH.h"

namespace TLGE
{
	Graphics::Graphics(Scene* aSceneInCharge) :
		System(aSceneInCharge),
		//TODO: fix 0 to nullptr
		m_currentCamera(0)
	{

	}
	Graphics::~Graphics()
	{

	}

	void Graphics::Update(float aDeltaTime)
	{
		std::vector<Model*> models = m_sceneInCharge->GetComponents<Model>();

		for (std::vector<Model*>::iterator it = models.begin(); it != models.end(); it++)
		{
			(*it)->Draw();
		}
	}

	void Graphics::Load()
	{
		//nothing to do
	}

	void Graphics::HandleEvent(Event* aEvent)
	{
		if (strcmp(aEvent->GetType(), "RESIZE") == 0)
		{
			glViewport(0, 0, ((ResizeEvent*)aEvent)->GetSize().x, ((ResizeEvent*)aEvent)->GetSize().y);
		}
	}

	Camera* Graphics::GetCurrentCamera()
	{
		if (m_currentCamera)
		{
			return m_currentCamera;
		}
		else
		{
			std::vector<Camera*> cameras = m_sceneInCharge->GetComponents<Camera>();
			if (cameras.size() > 0)
			{
				m_currentCamera = cameras[0];
				return m_currentCamera;
			}
			else
			{
				GameObject* camera = new GameObject("TLGE_DefaultCamera");
				camera->AddComponent<Camera>();
				m_sceneInCharge->AddGameObject(camera);

				m_currentCamera = camera->GetComponent<Camera>();
				return m_currentCamera;
			}
		}
	}
	void Graphics::SetCurrentCamera(GameObject* aObject)
	{
		if (aObject->GetComponent<Camera>())
		{
			m_currentCamera = aObject->GetComponent<Camera>();
		}
		else
		{
			m_currentCamera = aObject->AddComponent<Camera>();
		}
	}
}