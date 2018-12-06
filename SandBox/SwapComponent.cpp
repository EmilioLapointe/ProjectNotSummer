#include "SwapComponent.h"

using namespace TLGE;

SwapComponent::SwapComponent(GameObject* aObjectInCharge) :
	Component(aObjectInCharge)
{
	//nothing to do
}
SwapComponent::~SwapComponent()
{
	//nothing to do
}

void SwapComponent::Update(float deltaTime)
{
	//nothing to do
}
void SwapComponent::HandleEvent(Event* aEvent)
{
	if (strcmp(aEvent->GetType(), "KEY") == 0 && ((TLGE::KeyEvent*)(aEvent))->GetState() == TLGE::KeyState_JustPressed)
	{
#ifdef WIN32
		if (((TLGE::KeyEvent*)(aEvent))->GetKey() == VK_SPACE)
		{
			Model* model = m_objectInCharge->GetComponent<Model>();
			Mesh* tempMesh = model->GetMesh();
			Texture* tempTexture = model->GetTexture();

			model->SetMesh(m_otherMesh);
			model->SetTexture(m_otherTexture);

			m_otherMesh = tempMesh;
			m_otherTexture = tempTexture;
		}
#endif // WIN32
	}
}