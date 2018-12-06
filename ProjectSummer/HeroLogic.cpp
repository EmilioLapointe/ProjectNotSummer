#include "HeroLogic.h"
#include "Tile.h"

HeroLogic::HeroLogic(TLGE::GameObject* aObjectInCharge):
	Component(aObjectInCharge)
{
	//tempTile = nullptr;
	//tilePosition = std::vector<glm::vec3>();
}

HeroLogic::~HeroLogic()
{

}

void HeroLogic::Update(float aDeltaTime)
{
	if (moving)
	{
		m_objectInCharge->GetComponent<TLGE::Transform>()->SetPosition(tempPosition);
		if (glm::distance(tilePosition[movesDone]->GetPosition(), m_objectInCharge->GetComponent<TLGE::Transform>()->GetPosition()) <= 0.01)
		{
			NextStep();
		}
	}

}

void HeroLogic::MoveHero()
{
	//movement phase enum triggered before or in this function
	//call tween//use numMovesTaken
	//this->GetComponent<Transform>()->SetPosition(glm::vec3(10.0f, 0.0f, 0.0f));
	
	m_objectInCharge->GetComponent<TLGE::Transform>()->SetRotation(glm::lookAt(m_objectInCharge->GetComponent<TLGE::Transform>()->GetPosition(), glm::vec3(20.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0)));
	TLGE::Tween::NewTween(GetObjectInCharge()->GetScene(), &tempPosition, m_objectInCharge->GetComponent<TLGE::Transform>()->GetPosition(), tilePosition[movesDone]->GetPosition(), 1.0f, TweenFunc_Linear);
	moving = true;
}

void HeroLogic::AddMove(Tile* aposition)//,float identity)
{
	//can it be next tile?
	//take in tile status
	if (CheckIfNeighbour(aposition))
	{
		tilePosition.push_back(aposition);

		numMovesTaken++;
		tempTile = aposition;
		if (numMovesTaken == maxNumMoves)//change this///well more like add to it
		{
			MoveHero();
		}
	}

}
void HeroLogic::CancelMove()
{
	tilePosition.pop_back();
	//run till you can't popback if cancel
	numMovesTaken--;//replace by size
	tempTile = *tilePosition.end();
}

void HeroLogic::NextStep()
{
	//ClaimToken();
	movesDone++;
	if (movesDone < numMovesTaken)
	{
		MoveHero();
	}
	else
	{
		numMovesTaken = 0;
		movesDone = 0;
		moving = false;
		tempTile = tilePosition.back();
		tilePosition.clear();
		//this->GetObjectInCharge()->GetComponent<TileMap>()->StartEnemyTurn();
		TLGE::GameObject* myObject;
		//myObject = this->GetObjectInCharge()->GetScene()->GetGameObject("TileMap");
		//myObject->GetComponent<TileMap>()->StartEnemyTurn();
		//myTileMap->GetComponent<TileMap>()->StartEnemyTurn();
		((TileMap*)myTileMap)->StartEnemyTurn();//change to setTurn
		//nowenemyPhase enum
	}
}

bool HeroLogic::CheckIfNeighbour(Tile* aTile)
{
	//identity instead??
	if(tempTile->m_Neighbour1 == aTile->GetIdentity())
	return true;
	if (tempTile->m_Neighbour2 == aTile->GetIdentity())
		return true;
	if (tempTile->m_Neighbour3 == aTile->GetIdentity())
		return true;
	if (tempTile->m_Neighbour4 == aTile->GetIdentity())
		return true;

	return false;

}

void HeroLogic::SetStartingTile(Tile* aTile)
{
	tempTile = aTile;
}
void HeroLogic::AddTileMapReference(TLGE::Component* aComponent)
{
	myTileMap = aComponent;
}

//void HeroLogic::ClaimToken()
//{
//	//check if has energy claim and remove it and add it to screen
//}
//update value it moving
