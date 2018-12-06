#include <TLGE.h>
#include "TileMap.h"
#include "Tile.h"
#include "Token.h"
#include "PauseScene.h"
#include "Soundscene.h"
#include "StartScene.h"
#include "HeroLogic.h"
#include "SpinCameraComponent.h"
#include "ButtonsScene.h"
#include "LevelOne.h"

using namespace TLGE;
using namespace glm;

int main()
{
	GameCore* gameCore = GameCore::GetInstance();

#if defined(__WINDOWS_BUILD__) || defined(_WINDOWS)
	((WindowManager_Windows*)(gameCore->GetWindowManager()))->SetName("ProjetSummer");
	((WindowManager_Windows*)(gameCore->GetWindowManager()))->SetIconFilepath("Data/Icons/Default.ico");
#endif


	Scene* scene = new LevelOne((char*)"Test");
	Scene* buttonsScene = new ButtonsScene(scene);
	Scene* pauseScene = new PauseScene((char*)"Pause");
	Scene* startScene = new StartScene((char*)"StartMenu");
	Scene* soundScene = new SoundScene((char*)"Sound");
	


	gameCore->GetSceneManager()->NextScene((char*)"StartMenu");

	gameCore->Load();
	gameCore->Run();

	return 0;
}