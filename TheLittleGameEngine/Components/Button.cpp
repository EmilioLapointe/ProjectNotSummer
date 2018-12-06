#include "EnginePCH.h"

namespace TLGE
{
	Button::Button(GameObject* objectInCharge):
		Component(objectInCharge),
		m_halfDimentions(0),
		m_isClicked(false)
	{
		objectInCharge->RequireComponent<Transform>();
	}
	Button::~Button()
	{
		//nothing to do
	}

	void Button::Update(float aDeltaTime)
	{
		//nothing to do
	}

	void Button::HandleEvent(Event* aEvent)
	{
		if (strcmp(aEvent->GetType(), "CLICK") == 0)
		{
			ClickEvent* click = (ClickEvent*)aEvent;

			if (click->GetState() == ClickState_Unclicked && m_isClicked)
			{
				m_isClicked = false;
				OnUnClick();
			}

			if (click->GetState() == ClickState_JustClicked)
			{

				//Get the transforms to turn the corners from model space to clip space
				glm::mat4 worldTansform = m_objectInCharge->GetComponent<Transform>()->GetWorldTransform();
				Camera* camera = m_objectInCharge->GetScene()->GetSystem<Graphics>()->GetCurrentCamera();
				glm::mat4 fullTransform = camera->GetProjectionTransform() * camera->GetViewTransform() * worldTansform;

				//Transform corners to view space
				glm::vec4 topLeft4 = fullTransform * glm::vec4((m_halfDimentions * glm::vec2(-1.0f, 1.0f)), 0.0f, 1.0f);
				glm::vec2 topLeft = topLeft4 / topLeft4.w;
				glm::vec4 topRight4 = fullTransform * glm::vec4((m_halfDimentions * glm::vec2(1.0f, 1.0f)), 0.0f, 1.0f);
				glm::vec2 topRight = topRight4 / topRight4.w;
				glm::vec4 bottomLeft4 = fullTransform * glm::vec4((m_halfDimentions * glm::vec2(-1.0f, -1.0f)), 0.0f, 1.0f);
				glm::vec2 bottomLeft = bottomLeft4 / bottomLeft4.w;
				glm::vec4 bottomRight4 = fullTransform * glm::vec4((m_halfDimentions * glm::vec2(1.0f, -1.0f)), 0.0f, 1.0f);
				glm::vec2 bottomRight = bottomRight4 / bottomRight4.w;

				//Transform the click position into something usable
				glm::vec2 clickPos((float)(click->GetPosition().x) / GameCore::GetInstance()->GetWindowManager()->GetWidth(), (float)(click->GetPosition().y) / GameCore::GetInstance()->GetWindowManager()->GetHeight());
				clickPos = (clickPos * 2.0f) - 1.0f;
				clickPos.y *= -1;

				//Used for this http://www.geeksforgeeks.org/wp-content/uploads/polygon31.png
				bool linesCrosedIsImpair = false;

				//Check if click is in button area
				if (((topLeft.y < clickPos.y) != (topRight.y < clickPos.y)) && ((((topRight.x - topLeft.x) * (clickPos.y - topLeft.y)) / (topRight.y - topLeft.y)) + topLeft.x) > clickPos.x)
				{
					linesCrosedIsImpair = !linesCrosedIsImpair;
				}
				if (((topRight.y < clickPos.y) != (bottomRight.y < clickPos.y)) && ((((bottomRight.x - topRight.x) * (clickPos.y - topRight.y)) / (bottomRight.y - topRight.y)) + topRight.x) > clickPos.x)
				{
					linesCrosedIsImpair = !linesCrosedIsImpair;
				}
				if (((bottomRight.y < clickPos.y) != (bottomLeft.y < clickPos.y)) && ((((bottomLeft.x - bottomRight.x) * (clickPos.y - bottomRight.y)) / (bottomLeft.y - bottomRight.y)) + bottomRight.x) > clickPos.x)
				{
					linesCrosedIsImpair = !linesCrosedIsImpair;
				}
				if (((bottomLeft.y < clickPos.y) != (topLeft.y < clickPos.y)) && ((((topLeft.x - bottomLeft.x) * (clickPos.y - bottomLeft.y)) / (topLeft.y - bottomLeft.y)) + bottomLeft.x) > clickPos.x)
				{
					linesCrosedIsImpair = !linesCrosedIsImpair;
				}

				if (linesCrosedIsImpair)
				{
					m_isClicked = true;
					OnClick();
				}
			}
		}
	}

	void Button::CreateButtonFromSprite()
	{
		Sprite* sprite = m_objectInCharge->GetComponent<Sprite>();
		
		//TODO: replace with nullptr
		if (sprite != 0)
		{
			m_halfDimentions = sprite->GetSize() / 2.0f;
		}

		return;
	}
}