#pragma once

#include <TLGE.h>

class FPSMeter : public TLGE::Component
{
	public:
	FPSMeter(TLGE::GameObject* objectInCharge);
	void Update(float deltaTime);
};