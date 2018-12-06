#include "EvilLogic.h"
#include "Tile.h"

EvilLogic::EvilLogic(TLGE::GameObject* aObjectInCharge) :
	Component(aObjectInCharge)
{
	//tempTile = nullptr;
	//tilePosition = std::vector<glm::vec3>();
}

EvilLogic::~EvilLogic()
{

}

void EvilLogic::Update(float aDeltaTime)
{
	//if enemyturn
	if (moving)
	{
		m_objectInCharge->GetComponent<TLGE::Transform>()->SetPosition(tempPosition);
		if (glm::distance(tempTile->GetPosition(), m_objectInCharge->GetComponent<TLGE::Transform>()->GetPosition()) <= 0.01)
		{
			NextStep();
		}
	}

}

void EvilLogic::MoveEvil()
{
	//randomize value
	std::srand((unsigned)time(0));
	int a;
	a = (std::rand() % maxRandomNum);
	while (!CheckIfNeighbour(a))
	{
		a = (std::rand() % maxRandomNum);
	}
	tempTile = ((TileMap*)myTileMap)->GetTile(a);
	//tempTile = this->GetObjectInCharge()->GetComponent<TileMap>()->GetTile(a);
	m_objectInCharge->GetComponent<TLGE::Transform>()->SetRotation(glm::lookAt(m_objectInCharge->GetComponent<TLGE::Transform>()->GetPosition(), glm::vec3(20.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0)));
	TLGE::Tween::NewTween(GetObjectInCharge()->GetScene(), &tempPosition, m_objectInCharge->GetComponent<TLGE::Transform>()->GetPosition(), tempTile->GetPosition(), 1.0f, TweenFunc_Linear);
	moving = true;
}

void EvilLogic::NextStep()
{
	movesDone++;
	if (movesDone < numMovesTaken)
	{
		MoveEvil();
	}
	else
	{
		//numMovesTaken = 0;
		movesDone = 0;
		moving = false;
		//tempTile = tilePosition.back();
		//tilePosition.clear();
		//playerturn set
		//this->GetObjectInCharge()->GetComponent<TileMap>()->SetTurn(playerTurn);
		//this->GetObjectInCharge()->GetScene()->GetGameObject("TileMap")->GetComponent<TileMap>()->SetTurn(playerTurn);
		((TileMap*)myTileMap)->SetTurn(playerTurn);
	}
}

//needed
bool EvilLogic::CheckIfNeighbour(int aTileIndex)
{
	if (tempTile->m_Neighbour1 == aTileIndex)
		return true;
	if (tempTile->m_Neighbour2 == aTileIndex)
		return true;
	if (tempTile->m_Neighbour3 == aTileIndex)
		return true;
	if (tempTile->m_Neighbour4 == aTileIndex)
		return true;

	return false;

}

//needed
void EvilLogic::SetStartingTile(Tile* aTile, int mapwidth, int mapheight)
{
	tempTile = aTile;
	maxRandomNum = mapwidth*mapheight;
}

void EvilLogic::AddTileMapReference(TLGE::Component* aComponent)
{
	myTileMap = aComponent;
}
