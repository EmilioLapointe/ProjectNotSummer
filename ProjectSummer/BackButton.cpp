#include "BackButton.h"
#include <TLGE.h>

	BackButton::BackButton(TLGE::GameObject* aObjectInCharge):
		Button(aObjectInCharge)
	{
		
	}

	BackButton::~BackButton()
	{
		//nothing to do
	}

	void BackButton::Update(float adeltatime)
	{

	}

	void BackButton::OnClick()
	{
		//CHECK
		TLGE::GameCore::GetInstance()->GetSceneManager()->Back();

	}