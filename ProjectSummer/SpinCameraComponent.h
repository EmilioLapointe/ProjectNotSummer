#ifndef __SPIN_CAMERA_COMPONENT__
#define __SPIN_CAMERA_COMPONENT__

#include "TLGE.h"

const unsigned int FRAMES_CHECKED_COUNT = 3;

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
	unsigned int m_latestMouseXs[FRAMES_CHECKED_COUNT];
	unsigned int m_currentFrame;
	float m_zRot;
};

#endif