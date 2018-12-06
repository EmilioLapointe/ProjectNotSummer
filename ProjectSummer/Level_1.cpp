#include "Level_1.h"
#include <TLGE.h>

	Level_1::Level_1(TLGE::GameObject* aObjectInCharge):
		Button(aObjectInCharge)
	{
		
	}

	Level_1::~Level_1()
	{
		//nothing to do
	}

	void Level_1::Update(float adeltatime)
	{

	}

	void Level_1::OnClick()
	{
		//CHECK
		TLGE::GameCore::GetInstance()->GetSceneManager()->GetScene()->SetActive(false);
		TLGE::GameCore::GetInstance()->GetSceneManager()->NextScene((char*)"Test");
		TLGE::GameCore::GetInstance()->GetSceneManager()->NextScene((char*)"ButtonsScene");
	}