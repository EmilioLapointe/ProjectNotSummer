#ifndef __TLGE__StartScene_H__
#define __TLGE__StartScene_H__

#include "Quit.h"
#include "Level_1.h"
#include "Sound.h"
#include <TLGE.h>

	class StartScene : public TLGE::Scene
	{
	public:
		//Object in charge is set on creation and cannot be changed
		StartScene(char* name);
		virtual ~StartScene();

	protected:
		TLGE::GameObject* mblarg;
		TLGE::GameObject* mblarg2;
		TLGE::GameObject* mblarg3;
		TLGE::GameObject* mblarga[100];
	};

#endif