#ifndef __WOBBLE_COMPONENT__
#define __WOBBLE_COMPONENT__

#include "TLGE.h"

class WobbleComponent : public TLGE::Component
{
public:
	WobbleComponent(TLGE::GameObject* objectInCharge);
	~WobbleComponent();
	void Update(float deltaTime);

	void AddOffset(float offset);
private:
	float m_timeSinceStart;
};

#endif