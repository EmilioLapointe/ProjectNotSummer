#pragma once
#include "TLGE.h"

class ScaleComponent : public TLGE::Button
{
public:
	ScaleComponent(TLGE::GameObject* objectInCharge);
	~ScaleComponent();

	void OnClick();

	void Update(float deltaTime);


private:
	bool m_big;
	float m_scale;
};
	void TestCallback();