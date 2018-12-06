#ifndef __TLGE__HeroLogic_H__
#define __TLGE__HeroLogic_H__
#include <TLGE.h>
#include "Tile.h"

enum HeroState
{
	inCase
};

class HeroLogic;

class HeroLogic:public TLGE::Component
{
public:
	HeroLogic(TLGE::GameObject* objectInCharge);
	virtual ~HeroLogic();

	void Update(float deltaTime);

	void MoveHero();
	void CancelMove();
	void NextStep();
	void AddMove(Tile* position);//,float identity);

	bool GetMoving() { return moving; }

	void SetStartingTile(Tile* aTile);
	void AddTileMapReference(TLGE::Component* aComponent);

	TLGE::Component* myTileMap;


private:
	int maxNumMoves = 3;
	int numMovesTaken = 0;
	int movesDone = 0;
	bool moving = false;
	Tile *tempTile;//used for checking tiles in order from hero
	glm::vec3 tempPosition=glm::vec3(0.0f,0.0f,0.0f);
	
	bool CheckIfNeighbour(Tile* aTile);
	std::vector<Tile*> tilePosition;
};

#endif

