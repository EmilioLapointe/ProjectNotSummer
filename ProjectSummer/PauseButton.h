#ifndef __TLGE__PauseButton_H__
#define __TLGE__PauseButton_H__
#include <TLGE.h>

	class PauseButton : public TLGE::Button
	{
	public:
		//Object in charge is set on creation and cannot be changed
		PauseButton(TLGE::GameObject* objectInCharge);
		virtual ~PauseButton();

		void Update(float deltaTime);

		void OnClick();
	};

#endif