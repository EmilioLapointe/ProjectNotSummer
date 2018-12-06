#include "SpinComponent.h"

SpinComponent::SpinComponent(TLGE::GameObject* objectInCharge):
	Component(objectInCharge)
{
	objectInCharge->RequireComponent<TLGE::Transform>();
}
SpinComponent::~SpinComponent()
{
	//nothing to do
}

void SpinComponent::Update(float deltaTime)
{
	TLGE::Transform* trans = m_objectInCharge->GetComponent<TLGE::Transform>();

	trans->RotateX(1.0f * deltaTime * m_x);
	trans->RotateY(1.0f * deltaTime * m_y);
	trans->RotateZ(1.0f * deltaTime * m_z);
}

void SpinComponent::HandleEvent(TLGE::Event* aEvent)
{
	if (strcmp(aEvent->GetType(), "KEY") == 0 && ((TLGE::KeyEvent*)(aEvent))->GetState() == TLGE::KeyState_JustPressed)
	{
		switch (((TLGE::KeyEvent*)(aEvent))->GetKey())
		{
		case 0x58:
			m_x = !m_x;
			break;
		case 0x59:
			m_y = !m_y;
			break;
		case 0x5A:
			m_z = !m_z;
			break;
		}
	}
}