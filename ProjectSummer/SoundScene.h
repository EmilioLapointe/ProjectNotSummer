#ifndef __TLGE__SoundScene_H__
#define __TLGE__SoundScene_H__

#include "BackButton.h"
#include "SliderTab.h"
#include <TLGE.h>

	class SoundScene : public TLGE::Scene
	{
	public:
		//Object in charge is set on creation and cannot be changed
		SoundScene(char* name);
		virtual ~SoundScene();

	protected:
		TLGE::GameObject* mblarg;
		TLGE::GameObject* mblarg2;
		TLGE::GameObject* mblarg3;
		TLGE::GameObject* mblarga[100];
	};

#endif