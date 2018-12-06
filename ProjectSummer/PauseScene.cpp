#include "PauseScene.h"
using namespace TLGE;

	PauseScene::PauseScene(char* aName):
		Scene(aName)
	{
		AddSystem<Graphics>();

		mblarg3 = new GameObject((char*)"Background");
		//mblarg->AddComponent<Button>();//why not work
		AddGameObject(mblarg3);
		mblarg3->AddComponent<Transform>();
		mblarg3->GetComponent<Transform>()->SetPosition(glm::vec3(0.0f, 0.0f, -1.0f));
		mblarg3->AddComponent<Sprite>();
		//sprite should include transform, search to see if it exists if so link if not create it and add it.
		mblarg3->GetComponent<Sprite>()->CreateSprite(glm::vec2(200.0f), (char*)"Data/Textures/Water.png", (char*)"Data/Shaders/Temp3DXZ.vert", (char*)"Data/Shaders/Temp3DXZ.frag");



		//check
		mblarga[0] = new GameObject((char*)"SoundButton");
		//mblarg->AddComponent<Tile>();//why not work

		AddGameObject(mblarga[0]);
		mblarga[0]->AddComponent<Transform>();
		mblarga[0]->GetComponent<Transform>()->SetPosition(glm::vec3(0.0f, 40.0f, 0.0f));
		mblarga[0]->AddComponent<Sprite>();
		mblarga[0]->GetComponent<Sprite>()->CreateSprite(glm::vec2(60.0f), (char*)"Data/Textures/ButtonOptions.png", (char*)"Data/Shaders/Temp3DXZ.vert", (char*)"Data/Shaders/Temp3DXZ.frag");
		mblarga[0]->AddComponent<Sound>()->CreateButtonFromSprite();


		//check
		mblarg2 = new GameObject((char*)"QuitButton");
		//mblarg->AddComponent<Button>();//why not work
		AddGameObject(mblarg2);
		mblarg2->AddComponent<Transform>();
		mblarg2->GetComponent<Transform>()->SetPosition(glm::vec3(0.0f, -50.0f, 0.0f));
		mblarg2->AddComponent<Sprite>();
		//sprite should include transform, search to see if it exists if so link if not create it and add it.
		mblarg2->GetComponent<Sprite>()->CreateSprite(glm::vec2(60.0f, 40.0f), (char*)"Data/Textures/ButtonQuit.png", (char*)"Data/Shaders/Temp3DXZ.vert", (char*)"Data/Shaders/Temp3DXZ.frag");
		mblarg2->AddComponent<Quit>()->CreateButtonFromSprite();


		//CHECK
		mblarg = new GameObject((char*)"BackButton");
		//mblarg->AddComponent<Button>();//why not work
		AddGameObject(mblarg);
		mblarg->AddComponent<Transform>();
		mblarg->GetComponent<Transform>()->SetPosition(glm::vec3(0.0f, -75.0f, 0.0f));
		mblarg->AddComponent<Sprite>();
		//sprite should include transform, search to see if it exists if so link if not create it and add it.
		mblarg->GetComponent<Sprite>()->CreateSprite(glm::vec2(20.0f), (char*)"Data/Textures/ButtonBack.png", (char*)"Data/Shaders/Temp3DXZ.vert", (char*)"Data/Shaders/Temp3DXZ.frag");
		mblarg->AddComponent<BackButton>()->CreateButtonFromSprite();
	}
	PauseScene::~PauseScene()
	{
		//nothing to do
	}