#include "SliderPrefab.h"

#include "SliderTab.h"

using namespace TLGE;

SliderPrefab::SliderPrefab(char* aName) :
	GameObject(aName)
{
	AddComponent<Transform>();

	char sliderString[] = "-Slider";
	char dongleString[] = "-Dongle";

	char* sliderStringFull = new char[strlen(sliderString) + strlen(aName) + 1];
	char* dongleStringFull = new char[strlen(dongleString) + strlen(aName) + 1];

#ifdef WIN32
	strcpy_s(sliderStringFull, strlen(sliderString) + strlen(aName) + 1, aName);
	strcat_s(sliderStringFull, strlen(sliderString) + strlen(aName) + 1, sliderString);
	strcpy_s(dongleStringFull, strlen(dongleString) + strlen(aName) + 1, aName);
	strcat_s(dongleStringFull, strlen(dongleString) + strlen(aName) + 1, dongleString);
#else
	strcpy(sliderStringFull, aName);
	strcat(sliderStringFull, sliderString);
	strcpy(dongleStringFull, aName);
	strcat(dongleStringFull, dongleString);
#endif // WIN32

	GameObject* slider = new GameObject(sliderStringFull);
	GameObject* dongle = new GameObject(dongleStringFull);

	delete[] sliderStringFull;
	delete[] dongleStringFull;

	slider->AddComponent<Sprite>()->CreateSprite(glm::vec2(100.0f, 10.0f), (char*)"Data/Textures/SliderGroove.png", (char*)"Data/Shaders/Temp3DXZ.vert", (char*)"Data/Shaders/Temp3DXZ.frag");
	dongle->AddComponent<Transform>();
	dongle->GetComponent<Transform>()->SetPosition(glm::vec3(0.0f, 0.0f, 1.0f));
	dongle->AddComponent<Sprite>();
	dongle->GetComponent<Sprite>()->CreateSprite(glm::vec2(16.0f), (char*)"Data/Textures/SliderTab.png", (char*)"Data/Shaders/Temp3DXZ.vert", (char*)"Data/Shaders/Temp3DXZ.frag");
	dongle->AddComponent<SliderTab>()->CreateButtonFromSprite();
	dongle->GetComponent<SliderTab>()->BindLimits(-40.0f, 40.0f);

	AddChild(slider);
	AddChild(dongle);
}
SliderPrefab::~SliderPrefab()
{
	//nothing to do
}