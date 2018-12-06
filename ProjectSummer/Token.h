#ifndef __TLGE__TOKEN_H__
#define __TLGE__TOKEN_H__

#include <TLGE.h>

	class Token : public TLGE::Component
	{
	public:
		//Object in charge is set on creation and cannot be changed
		Token(TLGE::GameObject* objectInCharge);
		virtual ~Token();

		void Initialize(int type, bool disabele = false);
		//Regular update. Must be overwritten.
		void Update(float deltaTime);

		//Should load lost or unloaded information(usefull for phone applications)
		virtual void Load() {}

		//Gets called whenever an event happens
		virtual void HandleEvent(TLGE::Event* event) {}

		//Getters

		void SetType(int argument);
		void SetDisabled(int argument);
		int GetType();
		int GetDisabled();

	protected:
		int m_tokenType;
		//tilemovement?
		bool m_disabeled;
	};

#endif