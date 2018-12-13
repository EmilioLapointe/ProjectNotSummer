#ifndef __TLGE__EvilLogic_H__
#define __TLGE__EvilLogic_H__
#include <TLGE.h>
#include "Tile.h"

enum EvilState
{
	inCase2
};

class EvilLogic;

class EvilLogic :public TLGE::Component
{
public:
	EvilLogic(TLGE::GameObject* objectInCharge);
	virtual ~EvilLogic();

	void Update(float deltaTime);

	void MoveEvil();
	void NextStep();

	void SetStartingTile(Tile* aTile, int mapWith, int mapHeight);

	void AddTileMapReference(TLGE::Component* aComponent);

	TLGE::Component* myTileMap;

private:
	int maxNumMoves = 3;
	int numMovesTaken = 3;
	int movesDone = 0;
	bool moving = false;
	Tile *tempTile;//used for checking tiles in order from hero
	glm::vec3 heightOffset = glm::vec3(0.0f, 5.0f, 0.0f);
	glm::vec3 tempPosition = glm::vec3(0.0f, 0.0f, 0.0f);
	int maxRandomNum;

	bool CheckIfNeighbour(int aTile);
	//std::vector<Tile*> tilePosition;
};

#endif

