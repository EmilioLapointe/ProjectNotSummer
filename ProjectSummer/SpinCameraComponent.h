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

	void SetZoom(float zoom) { m_currentZoom = zoom; }
	void SetControlledBySlider(bool controlled) { m_controlledBySlider = controlled; }

	void HandleEvent(TLGE::Event* event);
private:
	bool m_mouseClicked;
	float m_velocity;
	unsigned int m_latestMouseXs[FRAMES_CHECKED_COUNT];
	unsigned int m_currentFrame;
	float m_zRot;

	//These do not include the Y axis
	float m_maxDistanceFromTarget;
	float m_minDistanceFromTarget;

	float m_maxHeight;
	float m_minHeight;

	float m_currentZoom;

	bool m_zoomingOut;
	bool m_zoomingIn;

	bool m_startedInTheUpperHalf;
	bool m_controlledBySlider{false};
};

#endif