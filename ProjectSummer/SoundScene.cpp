#include "SoundScene.h"
using namespace TLGE;

	SoundScene::SoundScene(char* aName):
		Scene(aName)
	{
		AddSystem<Graphics>();

		mblarga[0] = new GameObject((char*)"Background");
		//mblarg->AddComponent<Button>();//why not work
		AddGameObject(mblarga[0]);
		mblarga[0]->AddComponent<Transform>();
		mblarga[0]->GetComponent<Transform>()->SetPosition(glm::vec3(30.0f, 0.0f, -1.0f));
		mblarga[0]->AddComponent<Sprite>();
		//sprite should include transform, search to see if it exists if so link if not create it and add it.
		mblarga[0]->GetComponent<Sprite>()->CreateSprite(glm::vec2(800.0f), (char*)"Data/Textures/Water.png", (char*)"Data/Shaders/Temp3DXZ.vert", (char*)"Data/Shaders/Temp3DXZ.frag");

		mblarga[1] = new GameObject((char*)"SliderSoundFX");
		//mblarg->AddComponent<Tile>();//why not work
		AddGameObject(mblarga[1]);
		mblarga[1]->AddComponent<Transform>();
		mblarga[1]->GetComponent<Transform>()->SetPosition(glm::vec3(30.0f, -40.0f, 0.0f));
		mblarga[1]->AddComponent<Sprite>();
		mblarga[1]->GetComponent<Sprite>()->CreateSprite(glm::vec2(100.0f, 10.0f), (char*)"Data/Textures/SliderGroove.png", (char*)"Data/Shaders/Temp3DXZ.vert", (char*)"Data/Shaders/Temp3DXZ.frag");

		mblarga[2] = new GameObject((char*)"SliderMusic");
		//mblarg->AddComponent<Button>();//why not work
		AddGameObject(mblarga[2]);
		mblarga[2]->AddComponent<Transform>();
		mblarga[2]->GetComponent<Transform>()->SetPosition(glm::vec3(30.0f, 10.0f, 0.0f));
		mblarga[2]->AddComponent<Sprite>();
		//sprite should include transform, search to see if it exists if so link if not create it and add it.
		mblarga[2]->GetComponent<Sprite>()->CreateSprite(glm::vec2(100.0f, 10.0f), (char*)"Data/Textures/SliderGroove.png", (char*)"Data/Shaders/Temp3DXZ.vert", (char*)"Data/Shaders/Temp3DXZ.frag");


		mblarga[3] = new GameObject((char*)"SliderMaster");
		//mblarg->AddComponent<Button>();//why not work
		AddGameObject(mblarga[3]);
		mblarga[3]->AddComponent<Transform>();
		mblarga[3]->GetComponent<Transform>()->SetPosition(glm::vec3(30.0f, 60.0f, 0.0f));
		mblarga[3]->AddComponent<Sprite>();
		//sprite should include transform, search to see if it exists if so link if not create it and add it.
		mblarga[3]->GetComponent<Sprite>()->CreateSprite(glm::vec2(100.0f, 10.0f), (char*)"Data/Textures/SliderGroove.png", (char*)"Data/Shaders/Temp3DXZ.vert", (char*)"Data/Shaders/Temp3DXZ.frag");


		mblarga[4] = new GameObject((char*)"MusicDongle");
		//mblarg->AddComponent<Button>();//why not work
		AddGameObject(mblarga[4]);
		mblarga[4]->AddComponent<Transform>();
		mblarga[4]->GetComponent<Transform>()->SetPosition(glm::vec3(30.0f, 10.0f, 1.0f));
		mblarga[4]->AddComponent<Sprite>();
		//sprite should include transform, search to see if it exists if so link if not create it and add it.
		mblarga[4]->GetComponent<Sprite>()->CreateSprite(glm::vec2(16.0f), (char*)"Data/Textures/SliderTab.png", (char*)"Data/Shaders/Temp3DXZ.vert", (char*)"Data/Shaders/Temp3DXZ.frag");
		mblarga[4]->AddComponent<SliderTab>()->CreateButtonFromSprite();
		mblarga[4]->GetComponent<SliderTab>()->BindLimits(-10.0f, 70.0f);


		mblarga[8] = new GameObject((char*)"SFXDongle");
		//mblarg->AddComponent<Button>();//why not work
		AddGameObject(mblarga[8]);
		mblarga[8]->AddComponent<Transform>();
		mblarga[8]->GetComponent<Transform>()->SetPosition(glm::vec3(30.0f, -40.0f, 1.0f));
		mblarga[8]->AddComponent<Sprite>();
		//sprite should include transform, search to see if it exists if so link if not create it and add it.
		mblarga[8]->GetComponent<Sprite>()->CreateSprite(glm::vec2(16.0f), (char*)"Data/Textures/SliderTab.png", (char*)"Data/Shaders/Temp3DXZ.vert", (char*)"Data/Shaders/Temp3DXZ.frag");
		mblarga[8]->AddComponent<SliderTab>()->CreateButtonFromSprite();
		mblarga[8]->GetComponent<SliderTab>()->BindLimits(-10.0f, 70.0f);


		mblarga[9] = new GameObject((char*)"MasterDongle");
		//mblarg->AddComponent<Button>();//why not work
		AddGameObject(mblarga[9]);
		mblarga[9]->AddComponent<Transform>();
		mblarga[9]->GetComponent<Transform>()->SetPosition(glm::vec3(30.0f, 60.0f, 1.0f));
		mblarga[9]->AddComponent<Sprite>();
		//sprite should include transform, search to see if it exists if so link if not create it and add it.
		mblarga[9]->GetComponent<Sprite>()->CreateSprite(glm::vec2(16.0f), (char*)"Data/Textures/SliderTab.png", (char*)"Data/Shaders/Temp3DXZ.vert", (char*)"Data/Shaders/Temp3DXZ.frag");
		mblarga[9]->AddComponent<SliderTab>()->CreateButtonFromSprite();
		mblarga[9]->GetComponent<SliderTab>()->BindLimits(-10.0f, 70.0f);

		mblarga[5] = new GameObject((char*)"MusicTag");
		//mblarg->AddComponent<Button>();//why not work
		AddGameObject(mblarga[5]);
		mblarga[5]->AddComponent<Transform>();
		mblarga[5]->GetComponent<Transform>()->SetPosition(glm::vec3(-50.0f, 10.0f, 0.0f));
		mblarga[5]->AddComponent<Sprite>();
		//sprite should include transform, search to see if it exists if so link if not create it and add it.
		mblarga[5]->GetComponent<Sprite>()->CreateSprite(glm::vec2(60.0f), (char*)"Data/Textures/Music tag.png", (char*)"Data/Shaders/Temp3DXZ.vert", (char*)"Data/Shaders/Temp3DXZ.frag");


		mblarga[6] = new GameObject((char*)"SFXTag");
		//mblarg->AddComponent<Button>();//why not work
		AddGameObject(mblarga[6]);
		mblarga[6]->AddComponent<Transform>();
		mblarga[6]->GetComponent<Transform>()->SetPosition(glm::vec3(-50.0f, -40.0f, 1.0f));
		mblarga[6]->AddComponent<Sprite>();
		//sprite should include transform, search to see if it exists if so link if not create it and add it.
		mblarga[6]->GetComponent<Sprite>()->CreateSprite(glm::vec2(60.0f), (char*)"Data/Textures/SFX tag.png", (char*)"Data/Shaders/Temp3DXZ.vert", (char*)"Data/Shaders/Temp3DXZ.frag");


		mblarga[7] = new GameObject((char*)"MasterTag");
		//mblarg->AddComponent<Button>();//why not work
		AddGameObject(mblarga[7]);
		mblarga[7]->AddComponent<Transform>();
		mblarga[7]->GetComponent<Transform>()->SetPosition(glm::vec3(-50.0f, 60.0f, 1.0f));
		mblarga[7]->AddComponent<Sprite>();
		//sprite should include transform, search to see if it exists if so link if not create it and add it.
		mblarga[7]->GetComponent<Sprite>()->CreateSprite(glm::vec2(60.0f), (char*)"Data/Textures/Master tag.png", (char*)"Data/Shaders/Temp3DXZ.vert", (char*)"Data/Shaders/Temp3DXZ.frag");
		//mblarga[7]->AddComponent<Model>()->
		//head->AddComponent<OBJModel>()->CreateOBJ("Data/OBJs/Hero-Head.obj", "Data/Textures/DiffuseMap-Hero.png", "Data/Shaders/Temp3DXZ.vert", "Data/Shaders/Temp3DXZ.frag");//////this


		//CHECK
		mblarga[10] = new GameObject((char*)"BackButton");
		//mblarg->AddComponent<Button>();//why not work
		AddGameObject(mblarga[10]);
		mblarga[10]->AddComponent<Transform>();
		mblarga[10]->GetComponent<Transform>()->SetPosition(glm::vec3(0.0f, -80.0f, 2.0f));
		mblarga[10]->AddComponent<Sprite>();
		//sprite should include transform, search to see if it exists if so link if not create it and add it.
		mblarga[10]->GetComponent<Sprite>()->CreateSprite(glm::vec2(48.0f, 32.0f), (char*)"Data/Textures/ButtonBack.png", (char*)"Data/Shaders/Temp3DXZ.vert", (char*)"Data/Shaders/Temp3DXZ.frag");
		mblarga[10]->AddComponent<BackButton>()->CreateButtonFromSprite();
	}
	SoundScene::~SoundScene()
	{
		//nothing to do
	}