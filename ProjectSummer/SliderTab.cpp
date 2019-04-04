#include "SliderTab.h"
#include <TLGE.h>
#include "SpinCameraComponent.h"

using namespace TLGE;

SliderTab::SliderTab(TLGE::GameObject* aObjectInCharge) :
	Button(aObjectInCharge),
	minimumBound(minimumBound),
	maximumBound(maximumBound)
{
	//follow value
	//bound it so it doesnt out of bounds
	//0-100 value
	//starts at 500
	amIHorizontal = true;
	thisTab = aObjectInCharge;
}

SliderTab::~SliderTab()
{
	//nothing to do
}

void SliderTab::Update(float adeltatime)
{
	if (follow)
	{
		if (MousePos1 < minimumBound + GetObjectInCharge()->GetParent()->GetComponent<Transform>()->GetPosition().x)
		{
			MousePos1 = minimumBound + GetObjectInCharge()->GetParent()->GetComponent<Transform>()->GetPosition().x;
		}
		else if (MousePos1 > maximumBound + GetObjectInCharge()->GetParent()->GetComponent<Transform>()->GetPosition().x)
		{
			MousePos1 = maximumBound + GetObjectInCharge()->GetParent()->GetComponent<Transform>()->GetPosition().x;
		}
		//position.x=MousPos;
		oldPosition=thisTab->GetComponent<Transform>()->GetPosition();
		if (amIHorizontal)
		{
			thisTab->GetComponent<Transform>()->SetPosition(glm::vec3(MousePos1 - GetObjectInCharge()->GetParent()->GetComponent<Transform>()->GetPosition().x, oldPosition.y, oldPosition.z));
		}
		if (!amIHorizontal)
		{
			thisTab->GetComponent<Transform>()->SetPosition(glm::vec3(oldPosition.x, MousePos1 - GetObjectInCharge()->GetParent()->GetComponent<Transform>()->GetPosition().x, oldPosition.z));
		}
		//thisTab->GetComponent<Transform>()->SetPosition()
		//thisTab.position.x = MousePos;
	}

	if (m_camera != nullptr)
	{
		float val = ((thisTab->GetComponent<Transform>()->GetPosition().x - minimumBound) / (maximumBound - minimumBound));
		m_camera->SetZoom(val);
	}
}

void SliderTab::OnClick()
{
	TLGE::GameCore::GetInstance()->GetSoundManager()->PlaySound("Data/Sounds/Scream.wav");

	follow = true;
}

void SliderTab::OnUnClick()
{
	follow = false;
}

void SliderTab::HandleEvent(TLGE::Event* aEvent)
{
	Button::HandleEvent(aEvent);
	if (strcmp(aEvent->GetType(), "MOUSE_MOVE") == 0)
	{
		MousePos = GetWorldPosOfScreenpos((*(thisTab->GetScene()->GetSystem<TLGE::Graphics>()->GetCurrentCamera())), thisTab->GetComponent<Transform>()->GetPosition(), glm::vec3(0.0f, 0.0f, -1.0f), ((MouseMove*)aEvent)->GetPosition());
		if (amIHorizontal)
		{
			MousePos1 = MousePos.x;
		}
		else
		{
			MousePos1 = MousePos.y;
		}
	}
}

glm::vec3 SliderTab::GetWorldPosOfScreenpos(TLGE::Camera cam, const glm::vec3 &planePoint, const glm::vec3 &planeNormal, const glm::ivec2 &screenPos)
{
	TLGE::Transform* camTransform = cam.GetObjectInCharge()->GetComponent<TLGE::Transform>();
	glm::quat invCamRot = glm::inverse(camTransform->GetQuatRotation());
	glm::vec3 camPos = camTransform->GetPosition();

	if (cam.IsPerspective())
	{
		float ratio = static_cast<float>(TLGE::GameCore::GetInstance()->GetWindowManager()->GetWidth()) / static_cast<float>(TLGE::GameCore::GetInstance()->GetWindowManager()->GetHeight());

		float height = cam.GetNear() * tan(cam.GetFovY()) * 2;
		float width = ratio * height;

		glm::vec3 ray(width, height, cam.GetNear());
		ray = invCamRot* ray * glm::inverse(invCamRot);
		ray = glm::normalize(ray);


		return camPos + ray * (glm::dot(planePoint - camPos, planeNormal) / glm::dot(planeNormal, ray));
	}
	else
	{
		glm::vec3 clickPos;
		float orthoBoxsize = cam.GetOrthoHalfBox() * 2;
		float ratio = cam.GetRatio();
		glm::vec2 orthoBox(orthoBoxsize * ratio, orthoBoxsize);

		float ScreenWidth = static_cast<float>(GameCore::GetInstance()->GetWindowManager()->GetWidth());
		float ScreenHeight = static_cast<float>(GameCore::GetInstance()->GetWindowManager()->GetHeight());

		glm::vec2 actualScreenPos = screenPos;
		actualScreenPos.x -= ScreenWidth*0.5f;
		actualScreenPos.y -= ScreenHeight*0.5f;

		clickPos.x = (orthoBox.x * actualScreenPos.x) / ScreenWidth;
		clickPos.y = (orthoBox.y * -actualScreenPos.y) / ScreenHeight;

		clickPos = invCamRot * clickPos * glm::inverse(invCamRot);
		clickPos += camPos;

		glm::vec3 camFoward(0, 0, 1);
		camFoward = invCamRot* camFoward * glm::inverse(invCamRot);

		glm::vec3 retVal = clickPos + camFoward * (glm::dot(planePoint - clickPos, planeNormal) / glm::dot(planeNormal, camFoward));
		return retVal;
	}
}

void SliderTab::BindLimits(float amin, float amax)
{
	minimumBound = amin;
	maximumBound = amax;
}