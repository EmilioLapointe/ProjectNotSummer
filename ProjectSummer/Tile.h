#ifndef __TLGE__Tile_H__
#define __TLGE__Tile_H__
#include <TLGE.h>
#include "TileMap.h"

enum tileState
{
	neutral,
	corrupted,
	claimed

};

//struct
//{
//	int m_Neighbour1;
//	int m_Neighbour2;
//	int m_Neighbour3;
//	int m_Neighbour4;
//};

	class Tile : public TLGE::Button
	{
	public:
		//Object in charge is set on creation and cannot be changed
		Tile(TLGE::GameObject* objectInCharge);
		virtual ~Tile();

		void Initialize(int tileState, int width, int height);
		//Regular update. Must be overwritten.
		void Update(float deltaTime);

		void AddHero(TLGE::GameObject* hero);

		//Should load lost or unloaded information(usefull for phone applications)
		//virtual void Load() {}

		void OnClick();

		//Getters
		//change to enums
		int GetState();
		void SetState(int argument);
		void AddIdentity(int argument);
		bool hasHero = false;

		glm::vec3 GetPosition();
		void RaisePosition(float aFloat);
		int GetIdentity() { return identity; }

		int m_Neighbour1;
		int m_Neighbour2;
		int m_Neighbour3;
		int m_Neighbour4;

	protected:
		TLGE::GameObject* myHero;
		int m_state;
		int identity;
		TLGE::GameObject* m_SceneObject;
		TLGE::Texture* claimedTexture;
		TLGE::Texture* neutralTexture;
		TLGE::Texture* corruptedTexture;
		//TLGE::GameObject* claimedTile;
		tileState myState;
	};

#endif