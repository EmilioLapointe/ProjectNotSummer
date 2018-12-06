#include "Quit.h"
#include <TLGE.h>

	Quit::Quit(TLGE::GameObject* aObjectInCharge):
		Button(aObjectInCharge)
	{
		
	}

	Quit::~Quit()
	{
		//nothing to do
	}

	void Quit::Update(float adeltatime)
	{

	}

	void Quit::OnClick()
	{
		//CHECK
		TLGE::GameCore* Core = TLGE::GameCore::GetInstance();
		//if core scenemanager on scene start
		if (strcmp("StartMenu", Core->GetSceneManager()->GetScene()->GetName()) == 0)
		{
			Core->AddEvent(new TLGE::OnQuitEvent());
		}
		else
		{
			Core->GetSceneManager()->GetScene()->SetActive(false);
			Core->GetSceneManager()->NextScene((char*)"StartMenu");
		}

		//else
		// nextscene menu
		//Core->GetSceneManager()->GetScene();//need to add functionality
		//Core->GetSoundManager()->PlaySound("Data/Sounds/Scream.wav");


	}