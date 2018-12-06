#ifndef __TLGE__BackButton_H__
#define __TLGE__BackButton_H__
#include <TLGE.h>

	class BackButton : public TLGE::Button
	{
	public:
		//Object in charge is set on creation and cannot be changed
		BackButton(TLGE::GameObject* objectInCharge);
		virtual ~BackButton();

		void Update(float deltaTime);

		void OnClick();
	};

#endif