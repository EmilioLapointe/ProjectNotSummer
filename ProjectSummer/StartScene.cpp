#include "StartScene.h"
using namespace TLGE;

	StartScene::StartScene(char* aName):
		Scene(aName)
	{
		AddSystem<Graphics>();

		mblarg3 = new GameObject("Backgroundafhgkfasgbku");
		AddGameObject(mblarg3);
		mblarg3->AddComponent<Transform>();
		mblarg3->GetComponent<Transform>()->SetPosition(glm::vec3(0.0f, 0.0f, -0.5f));
		mblarg3->AddComponent<Sprite>();
		mblarg3->GetComponent<Sprite>()->CreateSprite(glm::vec2(100), (char*)"Data/Textures/Water.png", (char*)"Data/Shaders/Temp3DXZ.vert", (char*)"Data/Shaders/Temp3DXZ.frag");


		//int a = 0;
		mblarga[0] = new GameObject((char*)"SoundButton");
		//mblarg->AddComponent<Tile>();//why not work
		AddGameObject(mblarga[0]);
		mblarga[0]->AddComponent<Transform>();
		mblarga[0]->GetComponent<Transform>()->SetPosition(glm::vec3(0.0f, -5.0f, 0.0f));
		mblarga[0]->AddComponent<Sprite>();
		mblarga[0]->GetComponent<Sprite>()->CreateSprite(glm::vec2(60.0f, 40.0f), (char*)"Data/Textures/ButtonOptions.png", (char*)"Data/Shaders/Temp3DXZ.vert", (char*)"Data/Shaders/Temp3DXZ.frag");
		mblarga[0]->AddComponent<Sound>()->CreateButtonFromSprite();//add the component of the button logic I want it to have

		mblarga[1] = new GameObject((char*)"Level1Button");
		//mblarg->AddComponent<Tile>();//why not work
		AddGameObject(mblarga[1]);
		mblarga[1]->AddComponent<Transform>();
		mblarga[1]->GetComponent<Transform>()->SetPosition(glm::vec3(0.0f, 65.0f, 0.0f));
		mblarga[1]->AddComponent<Sprite>();
		mblarga[1]->GetComponent<Sprite>()->CreateSprite(glm::vec2(60.0f, 40.0f), (char*)"Data/Textures/ButtonLevelSelect.png", (char*)"Data/Shaders/Temp3DXZ.vert", (char*)"Data/Shaders/Temp3DXZ.frag");
		mblarga[1]->AddComponent<Level_1>()->CreateButtonFromSprite();

		mblarg2 = new GameObject((char*)"QuitButton");
		AddGameObject(mblarg2);
		mblarg2->AddComponent<Transform>();
		mblarg2->GetComponent<Transform>()->SetPosition(glm::vec3(0.0f, -70.0f, 0.0f));
		mblarg2->AddComponent<Sprite>();
		mblarg2->GetComponent<Sprite>()->CreateSprite(glm::vec2(60.0f, 40.0f), (char*)"Data/Textures/ButtonQuit.png", (char*)"Data/Shaders/Temp3DXZ.vert", (char*)"Data/Shaders/Temp3DXZ.frag");
		mblarg2->AddComponent<Quit>()->CreateButtonFromSprite();
	}
	StartScene::~StartScene()
	{
		//nothing to do
	}