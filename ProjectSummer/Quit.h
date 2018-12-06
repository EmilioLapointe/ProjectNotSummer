#ifndef __TLGE__Quit_H__
#define __TLGE__Quit_H__
#include <TLGE.h>

	class Quit : public TLGE::Button
	{
	public:
		//Object in charge is set on creation and cannot be changed
		Quit(TLGE::GameObject* objectInCharge);
		virtual ~Quit();

		//Regular update. Must be overwritten.
		void Update(float deltaTime);

		//Should load lost or unloaded information(usefull for phone applications)
		//virtual void Load() {}

		void OnClick();
	};

#endif