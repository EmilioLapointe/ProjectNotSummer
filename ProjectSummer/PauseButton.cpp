#include "PauseButton.h"
#include <TLGE.h>

	PauseButton::PauseButton(TLGE::GameObject* aObjectInCharge):
		Button(aObjectInCharge)
	{
		
	}

	PauseButton::~PauseButton()
	{
		//nothing to do
	}

	void PauseButton::Update(float adeltatime)
	{
		int i = 0;
	}

	void PauseButton::OnClick()
	{
		//CHECK

		TLGE::GameCore::GetInstance()->GetSceneManager()->GetScene()->SetActive(false);
		TLGE::GameCore::GetInstance()->GetSceneManager()->NextScene((char*)"Pause");

	}