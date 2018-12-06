#pragma once

#include <TLGE.h>

class SceneLink : public TLGE::Component
{
public:
	SceneLink(TLGE::GameObject* objectInCharge);
	~SceneLink();

	void Update(float deltaTime);

	void SetOtherScene(TLGE::Scene* other) { m_other = other; }
private:
	TLGE::Scene* m_other;
};