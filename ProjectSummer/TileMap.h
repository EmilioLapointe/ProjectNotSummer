#ifndef __TLGE__TileMap_H__
#define __TLGE__TileMap_H__
#include <TLGE.h>
#include <sstream>
#include "Tile.h"
#include "PauseButton.h"
#include "Hero.h"
#include "Evil.h"
#include "ButtonsScene.h"

enum Turn
{
	playerTurn,
	movementTurn,
	enemyTurn
};

class Tile;

class TileMap: public TLGE::Component
{
public:
	//Object in charge is set on creation and cannot be changed
	TileMap(TLGE::GameObject* objectInCharge);
	virtual ~TileMap();

	void Initialize(int width, int length);
	//std::vector<int*> corrupted
	//Regular update. Must be overwritten.
	void Update(float deltaTime) { }

	//Should load lost or unloaded information(usefull for phone applications)
	virtual void Load() {}

	//Gets called whenever an event happens
	virtual void HandleEvent(TLGE::Event* event) {}

	Tile* GetTile(int aInt);

	Turn GetTurn();
	void SetTurn(Turn aTurn);
	std::vector<int> getSurroundingTiles(Tile* tileIndex);

	int GetWidth() { return m_mapWidth; }
	int GetLength() { return m_mapLength; }

	void SetHero(TLGE::GameObject* hero) { m_Hero = hero; }
	void SetEvil(TLGE::GameObject* evil) { m_Evil1 = evil; }

	void StartEnemyTurn();

protected:
	int m_mapWidth;//height
	int m_mapLength;
	Turn m_Turn;
	std::vector<int> m_corruptTiles;
	//std::vector<GameObject*> TileObject;
	TLGE::GameObject* m_TileObject[1000];
	TLGE::GameObject* m_Hero;

	TLGE::GameObject* m_Evil1;
	//int corruptiion rate/difficulty
};

#endif