#include "TileMap.h"
#include "HeroLogic.h"
#include "EvilLogic.h"
using namespace TLGE;
	TileMap::TileMap(GameObject* aObjectInCharge):
		Component(aObjectInCharge)
	{
		m_Turn = playerTurn;
	}

	TileMap::~TileMap()
	{
		//nothing to do

	}

	Turn TileMap::GetTurn()
	{
		return m_Turn;
	}

	void TileMap::SetTurn(Turn aTurnType)
	{
		m_Turn = aTurnType;
	}

	std::vector<int> TileMap::getSurroundingTiles(Tile* TileIndex)
	{
		std::string name = TileIndex->GetObjectInCharge()->GetName().substr(4, 4);

		int asInt;
		std::vector<int> avector;
		

		//modu for the top
			//modu for the side
			
		//do so

		std::stringstream ss;
		ss << name;
		ss >> asInt;
		ss.str("");
		ss.clear();

		if (asInt % m_mapWidth == 1)
		{
			//do nothing as its on this edge
		}
		else
		{
			avector.push_back(asInt-1);
		}

		if (asInt % m_mapWidth == 0)
		{
			//do nothing as its on this edge
		}
		else
		{
			avector.push_back(asInt + 1);
		}


		if (asInt % m_mapLength == 1)
		{
			//do nothing as its on this edge
		}
		else
		{
			avector.push_back(asInt - 1);
		}

		if (asInt % m_mapLength == 0)
		{
			//do nothing as its on this edge
		}
		else
		{
			avector.push_back(asInt + 1);
		}

		return avector;


	}
	//std::vector<int*> corruptedTiles
	void TileMap::Initialize(int width, int length)
	{
		m_mapWidth = width;
		m_mapLength = length;

		int numTiles = width * length;
		float tileSize = 20;

		for (int i = 0; i < numTiles; i++)
		{
			std::stringstream ss;
			ss << i;
			std::string number = ss.str();
			std::string tileNumber = "Tile" + number;

			GameObject* TileModel = new GameObject("TileModel");
			TileModel->AddComponent<Transform>()->SetScale(glm::vec3(2.5f));
			TileModel->GetComponent<Transform>()->SetRotation(glm::vec3(-PI * 0.5, 0.0f, 0.0f));
			TileModel->AddComponent<OBJModel>()->CreateOBJ((char*)"Data/OBJs/TileNeutral.obj", (char*)"Data/Textures/DiffuseMap-TileNeutral.png", (char*)"Data/Shaders/Temp3DXZ.vert", (char*)"Data/Shaders/Temp3DXZ.frag");

			GameObject* TileModel1 = new GameObject("TileModel1");
			TileModel1->AddComponent<Transform>()->SetScale(glm::vec3(2.5f));
			TileModel1->GetComponent<Transform>()->SetRotation(glm::vec3(-PI * 0.5, 0.0f, 0.0f));
			TileModel1->AddComponent<OBJModel>()->CreateOBJ((char*)"Data/OBJs/TileGood.obj", (char*)"Data/Textures/DiffuseMap-TileGood.png", (char*)"Data/Shaders/Temp3DXZ.vert", (char*)"Data/Shaders/Temp3DXZ.frag");
			TileModel1->GetComponent<OBJModel>()->SetVisible(false);

			m_TileObject[i] = new GameObject(tileNumber);
			//m_TileObject[i]->GetComponent<Tile>()->Initialize(0);//Tilesate
			GetObjectInCharge()->AddChild(m_TileObject[i]);
			m_TileObject[i]->AddComponent<Transform>();
			m_TileObject[i]->GetComponent<Transform>()->SetPosition(glm::vec3(0.0f, 0.0f, 0.0f));
			m_TileObject[i]->AddComponent<Sprite>();
			m_TileObject[i]->GetComponent<Sprite>()->CreateSprite(glm::vec2(tileSize), (char*)"Data/Textures/NeutralTile.png", (char*)"Data/Shaders/Temp3DXZ.vert", (char*)"Data/Shaders/Temp3DXZ.frag");
			m_TileObject[i]->AddComponent<Tile>()->CreateButtonFromSprite();
			m_TileObject[i]->GetComponent<Tile>()->AddHero(m_Hero);
			m_TileObject[i]->GetComponent<Tile>()->AddIdentity(i);
			m_TileObject[i]->AddChild(TileModel);
			m_TileObject[i]->AddChild(TileModel1);
			m_TileObject[i]->GetComponent<Tile>()->Initialize(1, m_mapLength, m_mapWidth);


			TileModel->GetComponent<Transform>()->SetPosition(glm::vec3(0.0f, -6.0f, -9.0f));


			//m_TileObject[i]->AddComponent<OBJModel>()->CreateOBJ(.obj,texture png file, vertex shader,frag shader);

			//hero or evil sandbox


			//addcomponenet tile
			//addcomponent 3d model ask Emilio
			//put in correct state
			//look up a*pathfinder for maping or bomberan
		}
		////////////////////placing tiles properly on map
		int index = 0;
		float y = 100.0f;
		float value = tileSize+3.0f;
		for (int i = 0; i < m_mapWidth; i++)
		{
			y -=value;
			float x = -100.0f;
			for (int a = 0; a < m_mapLength; a++)
			{
				x +=value;
				m_TileObject[index]->GetComponent<Transform>()->SetPosition(glm::vec3(x, 0.0f, y));
				m_TileObject[index]->GetComponent<Transform>()->SetRotation(glm::vec3(-PI * 0.5f,0.0f,0.0f));
				index += 1;
			}

		}
		/////////////////////////////////////////////////
		//default that never changes
	}

	//void TileMap::Update(float aDeltaTime)
	//{
	//	if (m_Turn == movementTurn&& m_Hero->GetComponent<HeroLogic>()->GetMoving()==false)
	//	{
	//		m_Turn = enemyTurn;
	//	}
	//}
	void TileMap::StartEnemyTurn()
	{
		m_Turn = enemyTurn;
		m_Evil1->GetComponent<EvilLogic>()->MoveEvil();
		
	}

	Tile* TileMap::GetTile(int aInt)
	{
		return m_TileObject[aInt]->GetComponent<Tile>();
	}
