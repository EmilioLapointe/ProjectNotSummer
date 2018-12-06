#include "SpinCameraComponent.h"

using namespace TLGE;

SpinCameraComponent::SpinCameraComponent(GameObject* aObjectInCharge):
	Component(aObjectInCharge),
	m_mouseClicked(false),
	m_velocity(0.0f),
	m_currentFrame(0),
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

	trans->SetPosition(glm::vec3(150.0f * sinf(m_zRot), 20.0f, 150.0f * cosf(m_zRot)));
}

void SpinCameraComponent::HandleEvent(TLGE::Event* aEvent)
{
	if (strcmp(aEvent->GetType(), "CLICK") == 0)
	{
		ClickEvent* click = static_cast<ClickEvent*>(aEvent);
		if (click->GetState() == ClickState_JustClicked)
		{
			m_mouseClicked = true;
			for (int i = 0; i < FRAMES_CHECKED_COUNT; i++)
			{
				m_latestMouseXs[i] = click->GetPosition().x;
			}
			m_currentFrame = 0;
			m_velocity = 0;
		}
		else if (click->GetState() == ClickState_Unclicked)
		{
			for (int i = 0; i < FRAMES_CHECKED_COUNT; i++)
			{
				m_latestMouseXs[i] = 0;
			}
			m_currentFrame = 0;
			m_mouseClicked = false;
		}
	}
	else if (strcmp(aEvent->GetType(), "MOUSE_MOVE") == 0)
	{
		int newMousePos = static_cast<MouseMove*>(aEvent)->GetPosition().x;

		unsigned int screenWidth = GameCore::GetInstance()->GetWindowManager()->GetWidth();
		unsigned int nextFrame = (m_currentFrame + 1) % FRAMES_CHECKED_COUNT;

		if (m_mouseClicked)
		{
			m_velocity += (static_cast<float>(m_latestMouseXs[nextFrame]) - static_cast<float>(newMousePos)) / static_cast<float>(screenWidth);
			m_latestMouseXs[nextFrame] = newMousePos;
			m_currentFrame = nextFrame;
		}
	}
	else if (strcmp(aEvent->GetType(), "MOUSE_LEAVE") == 0)
	{
		unsigned int nextFrame = (m_currentFrame + 1) % FRAMES_CHECKED_COUNT;
		unsigned int screenWidth = GameCore::GetInstance()->GetWindowManager()->GetWidth();

		m_velocity += (static_cast<float>(m_latestMouseXs[nextFrame]) - static_cast<float>(m_latestMouseXs[m_currentFrame])) / static_cast<float>(screenWidth);
		for (int i = 0; i < FRAMES_CHECKED_COUNT; i++)
		{
			m_latestMouseXs[i] = 0;
		}
		m_currentFrame = 0;
		
		m_mouseClicked = false;
	}
}