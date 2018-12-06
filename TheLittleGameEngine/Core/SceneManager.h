#ifndef _TLGE__SceneManager_H__
#define _TLGE__SceneManager_H__

namespace TLGE
{
	class Scene;

	class SceneManager
	{
		std::vector<Scene*> SceneList;
		std::vector<Scene*> ActiveScenes;

	public:

		SceneManager();
		~SceneManager();

		void AddScene(Scene* aScene);

		void Back();
		void NextScene(std::string name);
		void RemoveScene(char* name);
		Scene* GetScene();
		//remove active scene??
		void LoadContent();
		void OnEvent(Event* event);
		void Update(float aDelta);

	private:
		void DoNextScenes();
		void DoBack();
		std::vector<std::string> nextScenesAdditive;
		bool hasBacked;
	};
}

#endif //_TLGE__SceneManager_H__
