#ifndef __TLGE__Level_1_H__
#define __TLGE__Level_1_H__
#include <TLGE.h>

	class Level_1 : public TLGE::Button
	{
	public:
		//Object in charge is set on creation and cannot be changed
		Level_1(TLGE::GameObject* objectInCharge);
		virtual ~Level_1();


		void Update(float deltaTime);

		void OnClick();
	};

#endif