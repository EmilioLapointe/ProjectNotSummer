#include "Tile.h"
#include <TLGE.h>
#include "HeroLogic.h"

	Tile::Tile(TLGE::GameObject* aObjectInCharge):
		Button(aObjectInCharge)
	{
		m_SceneObject = aObjectInCharge->GetParent();
		m_Neighbour1 = -1;
		m_Neighbour2 = -1;
		m_Neighbour3 = -1;
		m_Neighbour4 = -1;
		claimedTexture = new TLGE::Texture();
		claimedTexture->CreateTexture((char*)"Data/Textures/ClaimedTile.png");
		neutralTexture = new TLGE::Texture();
		neutralTexture->CreateTexture((char*)"Data/Textures/NeutralTile.png");
		corruptedTexture = new TLGE::Texture();
		corruptedTexture->CreateTexture((char*)"Data/Textures/InfectedTile.png");
	}

	Tile::~Tile()
	{
		//nothing to do
	}

	void Tile::Initialize(int TileState, int width, int height)
	{
		m_state = TileState;

		if(!(identity%width ==width-1))
		m_Neighbour1 = identity + 1;
		if(!(identity % width==0))
		m_Neighbour2 = identity - 1;
		if(identity>=width)
		m_Neighbour3 = identity - width;
		if(!(identity>(width*(height-1)-1)))
		m_Neighbour4 = identity + width;
	}
	int Tile::GetState()
	{
		return m_state;
	}

	void Tile::SetState(int argument)
	{
		m_state = argument;
		if (m_state == 1)
		{
			//this->
			//TODO/////////////////////////////////////
			//want to get child of tile claimedTile to change its visibility
			//and do the same for neutral tile
			//no getchild functinality? should I just hard reference? with a variable that stores it
			//this->GetObjectInCharge()->GetComponent<TLGE::Sprite>()->SetTexture(neutralTexture);

			this->GetObjectInCharge()->GetComponent<TLGE::Sprite>()->SetTexture(claimedTexture);//SetTexture((char*)"Data/Textures/NeutTile.png");
			RaisePosition(1.0f);
		}
		else if (m_state ==2)
		{
			this->GetObjectInCharge()->GetComponent<TLGE::Sprite>()->SetTexture(corruptedTexture);//SetTexture((char*)"Data/Textures/NeutTile.png");
			RaisePosition(1.0f);
		}
		//this->GetObjectInCharge()->GetComponent<TLGE::Sprite>()->SetTexture(claimedTexture);//SetTexture((char*)"Data/Textures/NeutTile.png");
		//RaisePosition(1.0f);
						//change to 3d
	}

	void Tile::Update(float adeltatime)
	{

	}

	void Tile::AddHero(TLGE::GameObject* hero)
	{
		myHero = hero;
	}

	void Tile::OnClick()
	{
		
		//TLGE::GameCore::GetInstance()->GetSceneManager
		if (playerTurn == m_SceneObject->GetComponent<TileMap>()->GetTurn())
		{
			//TLGE::GameCore::GetInstance()->GetSoundManager()->PlaySound("Data/Sounds/Scream.wav");
			//this->GetObjectInCharge()->GetName();
			//std::vector<int> avector = ((TileMap*)m_SceneObject)->getSurroundingTiles(this);//what I use this for?
			

			

			myHero->GetComponent<HeroLogic>()->AddMove(this);// , identity);//add this tile reference
			
			if (myHero->GetComponent<HeroLogic>()->GetMoving())
			{
				m_SceneObject->GetComponent<TileMap>()->SetTurn(movementTurn);
			}

		}
		else
		{
			//do nothing as its the computers turn
		}
		//if player turn = true and player is 1 away then move player and purify tile

	}

	void Tile::AddIdentity(int aIdentity)
	{
		identity = aIdentity;
	}

	glm::vec3 Tile::GetPosition()
	{
		return this->GetObjectInCharge()->GetComponent<TLGE::Transform>()->GetPosition();
	}

	void Tile::RaisePosition(float aFloat)
	{
		//for lifting and revealing what tiles are picked//eventaully changing it to tweeingin?
		this->GetObjectInCharge()->GetComponent<TLGE::Transform>()->SetPosition(glm::vec3(GetPosition().x,aFloat,GetPosition().z));
	}
	//corrupt//claim//neutral function