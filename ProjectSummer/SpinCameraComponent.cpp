#include "SpinCameraComponent.h"

using namespace TLGE;

SpinCameraComponent::SpinCameraComponent(GameObject* aObjectInCharge):
	Component(aObjectInCharge),
	m_mouseClicked(false),
	m_velocity(0.0f),
	m_currentFrame(0),
	m_zRot(0.0f),
	m_maxDistanceFromTarget(0.0f),
	m_minDistanceFromTarget(150.0f),
	m_maxHeight(150.0f),
	m_minHeight(20.0f),
	m_currentZoom(0.0f)
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

	glm::vec3 oldRot = trans->GetEulerRotation();

	if (m_mouseClicked)
	{
		m_zRot += m_velocity * PI;
		m_velocity = 0;
	}
	else
	{
		if (m_velocity != 0)
		{
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

	if (m_zoomingIn)
	{
		m_currentZoom -= aDeltaTime;
		if (m_currentZoom < 0)
		{
			m_currentZoom = 0;
		}
	}
	if (m_zoomingOut)
	{
		m_currentZoom += aDeltaTime;
		if (m_currentZoom > 1.0f)
		{
			m_currentZoom = 1.0f;
		}
	}

	float distance = m_minDistanceFromTarget + ((m_maxDistanceFromTarget - m_minDistanceFromTarget) * m_currentZoom);
	float height = m_minHeight + ((m_maxHeight - m_minHeight) * m_currentZoom);

	float tilt = (PI * m_currentZoom * 0.5f);


	trans->SetPosition(glm::vec3(distance * sinf(m_zRot), height, distance * cosf(m_zRot)));
	trans->SetRotation(glm::vec3(-tilt, m_zRot, 0.0f));
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
			if (static_cast<unsigned int>(click->GetPosition().y) > GameCore::GetInstance()->GetWindowManager()->GetHeight() / 2)
			{
				m_startedInTheUpperHalf = true;
			}
			else
			{
				m_startedInTheUpperHalf = false;
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
			if (m_startedInTheUpperHalf)
			{
				m_velocity += (static_cast<float>(m_latestMouseXs[nextFrame]) - static_cast<float>(newMousePos)) / static_cast<float>(screenWidth);
			}
			else
			{
				m_velocity -= (static_cast<float>(m_latestMouseXs[nextFrame]) - static_cast<float>(newMousePos)) / static_cast<float>(screenWidth);
			}
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
	else if (strcmp(aEvent->GetType(), "KEY") == 0)
	{
		KeyEvent* key = static_cast<KeyEvent*>(aEvent);
		if (key->GetKey() == 'U')
		{
			if (key->GetState() == KeyState_JustPressed)
			{
				m_zoomingOut = true;
			}
			else if (key->GetState() == KeyState_Unpressed)
			{
				m_zoomingOut = false;
			}
		}
		else if (key->GetKey() == 'J')
		{
			if (key->GetState() == KeyState_JustPressed)
			{
				m_zoomingIn = true;
			}
			else if (key->GetState() == KeyState_Unpressed)
			{
				m_zoomingIn = false;
			}
		}
	}
}