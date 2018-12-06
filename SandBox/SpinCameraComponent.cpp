#include "SpinCameraComponent.h"

using namespace TLGE;

SpinCameraComponent::SpinCameraComponent(GameObject* aObjectInCharge):
	Component(aObjectInCharge),
	m_mouseClicked(false),
	m_velocity(0.0f),
	m_lastMouseX(0),
	m_zRot(0.0f)
{
	//nothing to do
}
SpinCameraComponent::~SpinCameraComponent()
{
	//nothing to do
}

void SpinCameraComponent::Update(float aDeltaTime)
{
	Transform* trans = m_objectInCharge->GetComponent<Transform>();

	if (m_mouseClicked)
	{
		trans->RotateY(m_velocity * PI);
		m_zRot += m_velocity * PI;
		m_velocity = 0;
	}
	else
	{
		if (m_velocity != 0)
		{
			trans->RotateY(m_velocity * PI);
			m_zRot += m_velocity * PI;
			m_velocity *= 0.93f;

			if ((m_velocity > 0) && (m_velocity < 0.001f))
			{
				m_velocity = 0;
			}
			else if ((m_velocity < 0) && (m_velocity > -0.001f))
			{
				m_velocity = 0;
			}
		}
	}

	trans->SetPosition(glm::vec3(80.0f * sinf(m_zRot), 0.0f, 80.0f * cosf(m_zRot)));
}

void SpinCameraComponent::HandleEvent(TLGE::Event* aEvent)
{
	if (strcmp(aEvent->GetType(), "CLICK") == 0)
	{
		ClickEvent* click = (ClickEvent*)aEvent;
		if (click->GetState() == ClickState_JustClicked)
		{
			m_mouseClicked = true;
			m_lastMouseX = click->GetPosition().x;
			m_velocity = 0;
		}
		else if (click->GetState() == ClickState_Unclicked)
		{
			m_mouseClicked = false;
		}
	}
	else if (strcmp(aEvent->GetType(), "MOUSE_MOVE") == 0)
	{
		int newMousePos = ((MouseMove*)aEvent)->GetPosition().x;

		unsigned int screenWidth = GameCore::GetInstance()->GetWindowManager()->GetWidth();

		if(m_mouseClicked)
			m_velocity += ((float)m_lastMouseX - (float)newMousePos) / (float)screenWidth;

		m_lastMouseX = newMousePos;
	}
}