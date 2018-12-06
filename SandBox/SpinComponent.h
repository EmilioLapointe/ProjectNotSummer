#pragma once
#include "TLGE.h"

class SpinComponent : TLGE::Component
{
public:
	SpinComponent(TLGE::GameObject* objectInCharge);
	~SpinComponent();

	void Update(float deltaTime);

	void HandleEvent(TLGE::Event* event);

private:
	bool m_x;
	bool m_y;
	bool m_z;
};