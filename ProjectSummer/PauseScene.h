#ifndef __TLGE__PauseScene_H__
#define __TLGE__PauseScene_H__


#include "Quit.h"
#include "Sound.h"
#include "BackButton.h"
#include <TLGE.h>

	class PauseScene : public TLGE::Scene
	{
	public:
		PauseScene(char* aName);
		virtual ~PauseScene();

	protected:
		TLGE::GameObject* mblarg;
		TLGE::GameObject* mblarg2;
		TLGE::GameObject* mblarg3;
		TLGE::GameObject* mblarga[100];
	};

#endif