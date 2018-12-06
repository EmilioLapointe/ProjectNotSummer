#ifndef __TLGE__Sound_H__
#define __TLGE__Sound_H__
#include <TLGE.h>

	class Sound : public TLGE::Button
	{
	public:
		//Object in charge is set on creation and cannot be changed
		Sound(TLGE::GameObject* objectInCharge);
		virtual ~Sound();

		void Update(float deltaTime);

		void OnClick();
	};

#endif