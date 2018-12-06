#include "FPSMeter.h"


FPSMeter::FPSMeter(TLGE::GameObject* objectInCharge):
	Component(objectInCharge)
{

}


void FPSMeter::Update(float deltaTime)
{
	m_objectInCharge->GetComponent<TLGE::Transform>()->SetPosition(glm::vec3(0, deltaTime * 100, 0));
}