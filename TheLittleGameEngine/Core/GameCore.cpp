#include "EnginePCH.h"

namespace TLGE
{
	//TODO: fix 0 to nullptr
	GameCore* GameCore::m_instance = 0;

	GameCore::GameCore()
	{
		m_sceneManager = new SceneManager();
#if defined(__WINDOWS_BUILD__) || defined(_WINDOWS)
		m_soundManager = new SoundManagerWin32();
#elif defined(__WINDOWS_BUILD__) || defined(_WINDOWS)
		m_soundManager = new SoundManagerAndroid();
#endif
	}

	GameCore* GameCore::GetInstance()
	{
		//TODO: fix 0 to nullptr
		if (m_instance == 0)
		{
			m_instance = new GameCore();
		}
		return m_instance;
	}
	GameCore::~GameCore()
	{
		//TODO: fix 0 to nullptr
		assert(m_sceneManager != 0);
		delete m_sceneManager;

		for (unsigned int i = 0; i < m_eventQueue.size(); i++)
		{
			delete m_eventQueue[i];
		}
	}

	void GameCore::Load()
	{
		m_windowManager->CreateGameWindow();
		m_windowManager->CreateGLContext();

		m_sceneManager->LoadContent();

		Resource::LoadAllResources();
	}

	void GameCore::Run()
	{
		UpdateCurentTime();

		glCullFace(GL_FRONT);
		glEnable(GL_CULL_FACE);
		glEnable(GL_DEPTH_TEST);

		glDepthFunc(GL_LESS);

		// turn on alpha blending.
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

#if defined(__WINDOWS_BUILD__)
		bool running = true;
		while (running)
		{
			UpdateCurentTime();
			running = !DoOneFrame();
		}
#endif
	}

	bool GameCore::DoOneFrame()
	{
		bool hasQuit = false;

		m_windowManager->ReceiveInput();

		for (unsigned int i = 0; i < m_eventQueue.size(); i++)
		{
			m_tempQueue.push_back(m_eventQueue[i]);
		}
		m_eventQueue.clear();

		for (std::vector<Event*>::iterator it = m_tempQueue.begin(); it != m_tempQueue.end(); it++)
		{
			if (strcmp((*it)->GetType(), "ON_QUIT") == 0)
			{
				hasQuit = true;
			}
			else if (strcmp((*it)->GetType(), "RESIZE") == 0)
			{
				m_windowManager->SetWidth(((ResizeEvent*)(*it))->GetSize().x);
				m_windowManager->SetHeight(((ResizeEvent*)(*it))->GetSize().y);
			}
			m_sceneManager->OnEvent(*it);
			delete *it;
		}
		m_tempQueue.clear();


		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		m_sceneManager->Update(((float)(m_currentTime - m_lastTime)) * 0.001f);

		m_windowManager->SwapCurrentBuffer();

		return hasQuit;
	}

	void GameCore::UpdateCurentTime()
	{
		m_lastTime = m_currentTime;

#if defined(__WINDOWS_BUILD__)
		m_currentTime = GetTickCount();
#elif defined(__ANDROID_BUILD__)
		timespec time;

		clock_gettime(CLOCK_MONOTONIC, &time);

		m_currentTime = time.tv_sec * 1000 + ((double)time.tv_nsec) * 0.000001;
#endif
	}

	void GameCore::AddEvent(Event* aEvent)
	{
		m_eventQueue.push_back(aEvent);
	}
}
