#include "Sound.h"
#include <TLGE.h>

	Sound::Sound(TLGE::GameObject* aObjectInCharge):
		Button(aObjectInCharge)
	{
		
	}

	Sound::~Sound()
	{
		//nothing to do
	}

	void Sound::Update(float adeltatime)
	{

	}

	void Sound::OnClick()
	{

		TLGE::GameCore::GetInstance()->GetSceneManager()->GetScene()->SetActive(false);
		TLGE::GameCore::GetInstance()->GetSceneManager()->NextScene((char*)"Sound");

	}