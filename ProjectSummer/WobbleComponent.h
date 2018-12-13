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
	
	void Start();
	void Pause();
	void Stop();
	void SmoothStop();

	bool IsWobbling() const { return m_isWobbling; }
	float GetAmplitude() const { return m_amplitude; }
	void SetAmplitude(const float amplitude) { m_amplitude = amplitude; }

private:
	float m_timeSinceStart;
	float m_amplitude;
	bool m_isWobbling;
	bool m_shouldStop;
};

#endif