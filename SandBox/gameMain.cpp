#include <TLGE.h>

#include "SpinComponent.h"
#include "ScaleComponent.h"
#include "SwapComponent.h"
#include "SpinCameraComponent.h"
#include "Hero.h"
#include "Evil.h"
#include "FPSMeter.h"

using namespace TLGE;
using namespace glm;

int main()
{
	GameCore* gameCore = GameCore::GetInstance();

#if defined(__WINDOWS_BUILD__) || defined(_WINDOWS)
	((WindowManager_Windows*)(gameCore->GetWindowManager()))->SetName("ProjetSummer");
	((WindowManager_Windows*)(gameCore->GetWindowManager()))->SetIconFilepath("Data/Icons/Default.ico");
#endif

	Scene* scene = new Scene((char*)"Test");
	scene->AddSystem<Graphics>();

	GameObject* camera = new GameObject("Camera");
	camera->AddComponent<Transform>()->SetPosition(vec3(0.0f, 0.0f, 80.0f));
	camera->AddComponent<Camera>()->SetIsPerspective(true);
	camera->AddComponent<SpinCameraComponent>();
	scene->AddGameObject(camera);

	GameObject* testObject = new Hero("testObj");
	scene->AddGameObject(testObject);

	//GameObject* testObject = new GameObject("testObj");
	//scene->AddGameObject(testObject);

	//Mesh* corruptedMesh = new Mesh();
	//Mesh* goodMesh = new Mesh();

	//corruptedMesh->CreateMeshFromOBJ((char*)"Data/OBJs/TileCorrupted.obj");
	//goodMesh->CreateMeshFromOBJ((char*)"Data/OBJs/TileGood.obj");

	//Texture* corruptedTexture = new Texture();
	//Texture* goodTexture = new Texture();

	//corruptedTexture->CreateTexture((char*)"Data/Textures/DiffuseMap-TileCorrupted.png");
	//goodTexture->CreateTexture((char*)"Data/Textures/DiffuseMap-TileGood.png");

	//ShaderProgram* program = new ShaderProgram();
	//program->CreateProgram((char*)"Data/Shaders/Temp3DXZ.vert", (char*)"Data/Shaders/Temp3DXZ.frag");
	//program->AddUniformRequirement(ShaderUniforms_Texture);
	//program->AddUniformRequirement(ShaderUniforms_WorldTransform);
	//program->AddUniformRequirement(ShaderUniforms_ViewTransform);
	//program->AddUniformRequirement(ShaderUniforms_ProjectionTransform);

	//testObject->AddComponent<Model>()->SetProgram(program);
	//testObject->GetComponent<Model>()->SetMesh(goodMesh);
	//testObject->GetComponent<Model>()->SetTexture(goodTexture);

	//testObject->AddComponent<SwapComponent>()->SetOtherMesh(corruptedMesh);
	//testObject->GetComponent<SwapComponent>()->SetOtherTexture(corruptedTexture);

	testObject->AddComponent<Transform>();
	testObject->GetComponent<Transform>()->SetPosition(vec3(0.0f, 0.0f, 0.0f));
	//testObject->GetComponent<Transform>()->SetScale(vec3(0.5f, 0.5f, 0.5f));
	testObject->GetComponent<Transform>()->SetScale(vec3(8.0f, 8.0f, 8.0f));

	//testObject->AddComponent<Sprite>();
	//vec2 size = vec2(100.0f, 100.0f);
	//testObject->GetComponent<Sprite>()->CreateSprite(size,"Data/Textures/Water.png", "Data/Shaders/Temp3DXZ.vert", "Data/Shaders/Temp3DXZ.frag");

	GameObject* FPS = new GameObject("testObj");
	scene->AddGameObject(FPS);
	FPS->AddComponent<Transform>();
	FPS->AddComponent<FPSMeter>();
	FPS->AddComponent<Sprite>();
	vec2 FPSsize = vec2(10.0f, 10.0f);
	FPS->GetComponent<Sprite>()->CreateSprite(FPSsize, "Data/Textures/SliderTab.png", "Data/Shaders/Temp3DXZ.vert", "Data/Shaders/Temp3DXZ.frag");

	//testObject->AddComponent<OBJModel>();
	//testObject->GetComponent<OBJModel>()->CreateOBJ("Data/OBJs/Guy.obj", "Data/Textures/Guy.png", "Data/Shaders/Temp3DXZ.vert", "Data/Shaders/Temp3DXZ.frag");

	//testObject->AddComponent<SpinComponent>();
	testObject->AddComponent<ScaleComponent>()->CreateButtonFromSprite();

	gameCore->GetSceneManager()->NextScene((char*)"Test");

	gameCore->Load();
	gameCore->Run();

	return 0;
}