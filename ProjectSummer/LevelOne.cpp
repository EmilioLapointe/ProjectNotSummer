#include "LevelOne.h"
#include "Hero.h"
#include "HeroLogic.h"
#include "Evil.h"
#include "EvilLogic.h"
#include "SpinCameraComponent.h"

using namespace TLGE;

LevelOne::LevelOne(char* aName) :
	Scene(aName)
{
	AddSystem<Graphics>();

	//m_Hero = new GameObject((char*)"Hero");
	GameObject* hero = new Hero((char*)"Hero");
	hero->AddComponent<Transform>();
	//m_Hero->AddChild(new Hero((char*)"Hero"));
	AddGameObject(hero);
	hero->GetComponent<Transform>()->SetPosition(glm::vec3(0.0f, 12.0f, 0.0f));
	hero->GetComponent<Transform>()->SetScale(glm::vec3(2.0f, 2.0f, 2.0f));
	//hero->GetComponent<Transform>()->RotateX(90);

	//m_Hero = new GameObject((char*)"Hero");
	GameObject* evil1 = new Evil((char*)"Evil");
	evil1->AddComponent<Transform>();
	//m_Hero->AddChild(new Hero((char*)"Hero"));
	AddGameObject(evil1);
	evil1->GetComponent<Transform>()->SetPosition(glm::vec3(60.0f, 5.0f, 0.0f));
	evil1->GetComponent<Transform>()->SetScale(glm::vec3(2.0f, 2.0f, 2.0f));
	//evil1->GetComponent<Transform>()->RotateX(90);

	GameObject* tileMap = new GameObject((char*)"TileMap");
	AddGameObject(tileMap);
	tileMap->AddComponent<TileMap>();
	tileMap->GetComponent<TileMap>()->SetHero(hero);
	tileMap->GetComponent<TileMap>()->SetEvil(evil1);
	//std::vector<int> test[]
	tileMap->GetComponent<TileMap>()->Initialize(6, 8);

	hero->GetComponent<HeroLogic>()->AddTileMapReference(tileMap->GetComponent<TileMap>());
	evil1->GetComponent<EvilLogic>()->AddTileMapReference(tileMap->GetComponent<TileMap>());

	hero->GetComponent<HeroLogic>()->SetStartingTile(tileMap->GetComponent<TileMap>()->GetTile(0));
	evil1->GetComponent<EvilLogic>()->SetStartingTile(tileMap->GetComponent<TileMap>()->GetTile(17), tileMap->GetComponent<TileMap>()->GetLength(), tileMap->GetComponent<TileMap>()->GetWidth());

	GameObject* camera = new GameObject("Camera");
	camera->AddComponent<Transform>()->SetPosition(glm::vec3(0.0f, 0.0f, 80.0f));
	camera->AddComponent<Camera>()->SetIsPerspective(true);
	camera->AddComponent<SpinCameraComponent>();
	AddGameObject(camera);
}

LevelOne::~LevelOne()
{

}