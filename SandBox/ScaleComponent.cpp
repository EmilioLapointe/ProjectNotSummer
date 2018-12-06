#include "ScaleComponent.h"

ScaleComponent::ScaleComponent(TLGE::GameObject* aObjectInCharge):
	Button(aObjectInCharge),
	m_big(false),
	m_scale(aObjectInCharge->GetComponent<TLGE::Transform>()->GetScale().x)
{
	//nothing to do
}
ScaleComponent::~ScaleComponent()
{
	//nothing to do
}

void ScaleComponent::Update(float deltaTime)
{
	m_objectInCharge->GetComponent<TLGE::Transform>()->SetScale(glm::vec3(m_scale));
}

void ScaleComponent::OnClick()
{
	TLGE::Transform* trans = m_objectInCharge->GetComponent<TLGE::Transform>();
	if (m_big)
	{
		TLGE::Tween::NewTween(m_objectInCharge->GetScene(), &m_scale, trans->GetScale().x, 0.5f, 0.2f, TweenFunc_Linear);
	}
	else
	{
		TLGE::Tween::NewTween(m_objectInCharge->GetScene(), &m_scale, trans->GetScale().x, 2.0f, 0.2f, TweenFunc_Linear);
	}
	m_big = !m_big;

	TLGE::GameCore::GetInstance()->GetSoundManager()->PlaySound("Data/Sounds/Scream.wav");
}