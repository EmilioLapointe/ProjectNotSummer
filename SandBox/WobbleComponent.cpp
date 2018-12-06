#include "WobbleComponent.h"

using namespace TLGE;

WobbleComponent::WobbleComponent(GameObject* aObjectInCharge):
	Component(aObjectInCharge),
	m_timeSinceStart(0.0f)
{
	//nothing to do
}
WobbleComponent::~WobbleComponent()
{
	//nothing to do
}
void WobbleComponent::Update(float aDeltaTime)
{
	m_timeSinceStart += aDeltaTime;
	m_timeSinceStart = fmod(m_timeSinceStart, PI * 2);

	Transform* toModify = m_objectInCharge->GetComponent<Transform>();
	glm::vec3 position = toModify->GetPosition();
	position.y = sinf(m_timeSinceStart) / 4;
	toModify->SetPosition(position);
}

void WobbleComponent::AddOffset(float aOffset)
{
	m_timeSinceStart += aOffset;
}