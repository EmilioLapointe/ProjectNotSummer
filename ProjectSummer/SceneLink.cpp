#include "SceneLink.h"

using namespace TLGE;

SceneLink::SceneLink(GameObject* aObjectInCharge):
	Component(aObjectInCharge),
	m_other(nullptr)
{
	//ntohing to do
}
SceneLink::~SceneLink()
{

}

void SceneLink::Update(float aDeltaTime)
{
	if (!m_other->IsActive())
	{
		m_other->SetActive(true);
	}
}