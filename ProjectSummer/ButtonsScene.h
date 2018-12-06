#pragma once

#include <TLGE.h>

class ButtonsScene : public TLGE::Scene
{
public:
	ButtonsScene(Scene* aScene);
	~ButtonsScene();
private:
	TLGE::GameObject* m_PauseButton;
};