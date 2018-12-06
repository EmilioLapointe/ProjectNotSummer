#ifndef __SPIN_CAMERA_COMPONENT__
#define __SPIN_CAMERA_COMPONENT__

#include "TLGE.h"

class SpinCameraComponent: public TLGE::Component
{
public:
	SpinCameraComponent(TLGE::GameObject* objectInCharge);
	~SpinCameraComponent();

	void Update(float deltaTime);

	void HandleEvent(TLGE::Event* event);
private:
	bool m_mouseClicked;
	float m_velocity;
	unsigned int m_lastMouseX;
	float m_zRot;
};

#endif