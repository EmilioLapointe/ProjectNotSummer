#include "ButtonsScene.h"
#include "PauseButton.h"
#include "SceneLink.h"
#include "Prefabs\SliderPrefab.h"
#include "SpinCameraComponent.h"
#include "SliderTab.h"

using namespace TLGE;
using namespace std;

ButtonsScene::ButtonsScene(Scene* aScene):
	Scene("ButtonsScene")
{
	AddSystem<Graphics>();


	m_PauseButton = new GameObject("PauseButton");
	AddGameObject(m_PauseButton);
	m_PauseButton->AddComponent<Transform>();
	m_PauseButton->GetComponent<Transform>()->SetPosition(glm::vec3(0.0f, 80.0f, 0.0f));
	m_PauseButton->AddComponent<Sprite>();
	m_PauseButton->GetComponent<Sprite>()->CreateSprite(glm::vec2(20), (char*)"Data/Textures/Water.png", (char*)"Data/Shaders/Temp3DXZ.vert", (char*)"Data/Shaders/Temp3DXZ.frag");
	m_PauseButton->AddComponent<PauseButton>()->CreateButtonFromSprite();


	GameObject* spinSlider = new SliderPrefab("SpinSlider");
	spinSlider->GetComponent<Transform>()->SetPosition(glm::vec3(0.0f, 50.0f, 0.0f));
	AddGameObject(spinSlider);

	vector<SpinCameraComponent*> cameraComponents = aScene->GetComponents<SpinCameraComponent>();
	if (cameraComponents.size() > 0)
	{
		SpinCameraComponent* firstInstance = cameraComponents[0];
		firstInstance->SetControlledBySlider(true);
		GameObject* temp = spinSlider->GetChild("SpinSlider-Dongle");
		temp->GetComponent<SliderTab>()->SetCamera(firstInstance);
	}

	GameObject* link = new GameObject("SceneLink");
	link->AddComponent<SceneLink>()->SetOtherScene(aScene);
	AddGameObject(link);
}
ButtonsScene::~ButtonsScene()
{
	//nothing to do
}