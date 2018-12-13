#include "WobbleComponent.h"

using namespace TLGE;

WobbleComponent::WobbleComponent(GameObject* aObjectInCharge):
	Component(aObjectInCharge),
	m_timeSinceStart(0.0f),
	m_amplitude(1.0f),
	m_isWobbling(true),
	m_shouldStop(false)
{
	//nothing to do
}
WobbleComponent::~WobbleComponent()
{
	//nothing to do
}
void WobbleComponent::Update(float aDeltaTime)
{
	if (!m_isWobbling)
	{
		return;
	}

	float prevModification = sinf(m_timeSinceStart) * m_amplitude;

	Transform* trasformToModify = m_objectInCharge->GetComponent<Transform>();
	glm::vec3 currentPosition = trasformToModify->GetPosition();
	float unmodifiedY = currentPosition.y - prevModification;

	m_timeSinceStart += aDeltaTime;
	m_timeSinceStart = fmod(m_timeSinceStart, PI * 2);

	float nextModification = sinf(m_timeSinceStart) * m_amplitude;
	
	if (m_shouldStop)
	{
		if ((prevModification >= 0 && nextModification < 0) ||
			(prevModification <= 0 && nextModification > 0))
		{
			m_shouldStop = false;
			m_isWobbling = false;
			m_timeSinceStart = 0;
			nextModification = 0;
		}
	}

	currentPosition.y = unmodifiedY + nextModification;
	trasformToModify->SetPosition(currentPosition);
}

void WobbleComponent::AddOffset(float aOffset)
{
	m_timeSinceStart += aOffset;
}

void WobbleComponent::Start()
{
	m_isWobbling = true;
	m_shouldStop = false;
}
void WobbleComponent::Pause()
{
	m_isWobbling = false;
}
void WobbleComponent::Stop()
{
	m_isWobbling = false;
	m_timeSinceStart = 0;
	m_shouldStop = false;
}
void WobbleComponent::SmoothStop()
{
	m_shouldStop = true;
}