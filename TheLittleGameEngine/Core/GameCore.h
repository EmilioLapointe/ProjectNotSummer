#ifndef __TLGE__GAME_CORE_H__
#define __TLGE__GAME_CORE_H__

namespace TLGE
{
	class WindowManager;
	class SceneManager;
	class SoundManager;
	class Event;
	class Resource;

	/**************************************************************************
	* GameCore serves as the entry point for the engine user. It contains     *
	* the scene manager and is the start point for all the events. As such,   *
	* it is also the class that the os comunicates with for any notifications.*
	*                                                                         *
	* Important notes:                                                        *
	*	-GameCore implements the Singleton pattern                            *
	***************************************************************************/
	class GameCore
	{
	private:
		GameCore();

	public:
		virtual ~GameCore();

		//Returns the GameCore Instance and creates it if it does not exist
		static GameCore* GetInstance();

		//Loads lost or unloaded information(usefull for phone applications)
		void Load();

		//Main loop
		void Run();

		//Does one iteration of the game loop
		bool DoOneFrame();

		//Sets m_currentTime to the actual current time
		void UpdateCurentTime();

		//Adds an event to the event queue
		void AddEvent(Event* event);

		//Getters
		SceneManager* GetSceneManager() { return m_sceneManager; }
		WindowManager* GetWindowManager() { return m_windowManager; }
		SoundManager* GetSoundManager() { return m_soundManager; }

		//Setters
		void SetWindowManager(WindowManager* manager) { m_windowManager = manager; }
		void SetSoundManager(SoundManager* manager) { m_soundManager = manager; }

	private:
		static GameCore* m_instance;

		WindowManager* m_windowManager;
		SceneManager* m_sceneManager;
		SoundManager* m_soundManager;

		std::vector<Event*> m_eventQueue;
		std::vector<Event*> m_tempQueue;

		long m_lastTime;
		long m_currentTime;

	};
}

#endif