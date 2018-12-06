#include "Hero.h"
#include "WobbleComponent.h"
#include "HeroLogic.h"

using namespace TLGE;

Hero::Hero(char* aName):
	GameObject(aName)
{
	AddComponent<Transform>();
	AddComponent<HeroLogic>();


	char headString[] = "-Head";
	char bodyString[] = "-Body";
	char rightShoulderString[] = "-RightShoulder";
	char leftShoulderString[] = "-LeftShoulder";
	char rightHandString[] = "-RightHand";
	char leftHandString[] = "-LeftHand";
	char crystalString[] = "-Crystal";
	char ringString[] = "-Ring";

	char* headStringFull = new char[strlen(headString) + strlen(aName) + 1];
	char* bodyStringFull = new char[strlen(bodyString) + strlen(aName) + 1];
	char* rightShoulderStringFull = new char[strlen(rightShoulderString) + strlen(aName) + 1];
	char* leftShoulderStringFull = new char[strlen(leftShoulderString) + strlen(aName) + 1];
	char* rightHandStringFull = new char[strlen(rightHandString) + strlen(aName) + 1];
	char* leftHandStringFull = new char[strlen(leftHandString) + strlen(aName) + 1];
	char* crystalStringFull = new char[strlen(crystalString) + strlen(aName) + 1];
	char* ringStringFull = new char[strlen(ringString) + strlen(aName) + 1];

#ifdef WIN32
	strcpy_s(headStringFull, strlen(headString) + strlen(aName) + 1, aName);
	strcat_s(headStringFull, strlen(headString) + strlen(aName) + 1, headString);
	strcpy_s(bodyStringFull, strlen(bodyString) + strlen(aName) + 1, aName);
	strcat_s(bodyStringFull, strlen(bodyString) + strlen(aName) + 1, bodyString);
	strcpy_s(rightShoulderStringFull, strlen(rightShoulderString) + strlen(aName) + 1, aName);
	strcat_s(rightShoulderStringFull, strlen(rightShoulderString) + strlen(aName) + 1, rightShoulderString);
	strcpy_s(leftShoulderStringFull, strlen(leftShoulderString) + strlen(aName) + 1, aName);
	strcat_s(leftShoulderStringFull, strlen(leftShoulderString) + strlen(aName) + 1, leftShoulderString);
	strcpy_s(rightHandStringFull, strlen(rightHandString) + strlen(aName) + 1, aName);
	strcat_s(rightHandStringFull, strlen(rightHandString) + strlen(aName) + 1, rightHandString);
	strcpy_s(leftHandStringFull, strlen(leftHandString) + strlen(aName) + 1, aName);
	strcat_s(leftHandStringFull, strlen(leftHandString) + strlen(aName) + 1, leftHandString);
	strcpy_s(crystalStringFull, strlen(crystalString) + strlen(aName) + 1, aName);
	strcat_s(crystalStringFull, strlen(crystalString) + strlen(aName) + 1, crystalString);
	strcpy_s(ringStringFull, strlen(ringString) + strlen(aName) + 1, aName);
	strcat_s(ringStringFull, strlen(ringString) + strlen(aName) + 1, ringString);
#else
	strcpy(headStringFull, aName);
	strcat(headStringFull, headString);
	strcpy(bodyStringFull, aName);
	strcat(bodyStringFull, bodyString);
	strcpy(rightShoulderStringFull, aName);
	strcat(rightShoulderStringFull, rightShoulderString);
	strcpy(leftShoulderStringFull, aName);
	strcat(leftShoulderStringFull, leftShoulderString);
	strcpy(rightHandStringFull, aName);
	strcat(rightHandStringFull, rightHandString);
	strcpy(leftHandStringFull, aName);
	strcat(leftHandStringFull, leftHandString);
	strcpy(crystalStringFull, aName);
	strcat(crystalStringFull, crystalString);
	strcpy(ringStringFull, aName);
	strcat(ringStringFull, ringString);
#endif // WIN32

	GameObject* head = new GameObject(headStringFull);
	GameObject* body = new GameObject(bodyStringFull);
	GameObject* rightShoulder = new GameObject(rightShoulderString);
	GameObject* leftShoulder = new GameObject(leftShoulderStringFull);
	GameObject* rightHand = new GameObject(rightHandStringFull);
	GameObject* leftHand = new GameObject(leftHandStringFull);
	GameObject* crystal = new GameObject(crystalStringFull);
	GameObject* ring = new GameObject(ringStringFull);

	delete[] headStringFull;
	delete[] bodyStringFull;
	delete[] rightShoulderStringFull;
	delete[] leftShoulderStringFull;
	delete[] rightHandStringFull;
	delete[] leftHandStringFull;
	delete[] crystalStringFull;
	delete[] ringStringFull;

	//TODO:shorten to use only one copy of shader and texture
	head->AddComponent<OBJModel>()->CreateOBJ((char*)"Data/OBJs/Hero-Head.obj", (char*)"Data/Textures/DiffuseMap-Hero.png", (char*)"Data/Shaders/Temp3DXZ.vert", (char*)"Data/Shaders/Temp3DXZ.frag");
	body->AddComponent<OBJModel>()->CreateOBJ((char*)"Data/OBJs/Hero-Body.obj", (char*)"Data/Textures/DiffuseMap-Hero.png", (char*)"Data/Shaders/Temp3DXZ.vert", (char*)"Data/Shaders/Temp3DXZ.frag");
	rightShoulder->AddComponent<OBJModel>()->CreateOBJ((char*)"Data/OBJs/Hero-RightShoulder.obj", (char*)"Data/Textures/DiffuseMap-Hero.png", (char*)"Data/Shaders/Temp3DXZ.vert", (char*)"Data/Shaders/Temp3DXZ.frag");
	leftShoulder->AddComponent<OBJModel>()->CreateOBJ((char*)"Data/OBJs/Hero-LeftShoulder.obj", (char*)"Data/Textures/DiffuseMap-Hero.png", (char*)"Data/Shaders/Temp3DXZ.vert", (char*)"Data/Shaders/Temp3DXZ.frag");
	rightHand->AddComponent<OBJModel>()->CreateOBJ((char*)"Data/OBJs/Hero-RightHand.obj", (char*)"Data/Textures/DiffuseMap-Hero.png", (char*)"Data/Shaders/Temp3DXZ.vert", (char*)"Data/Shaders/Temp3DXZ.frag");
	leftHand->AddComponent<OBJModel>()->CreateOBJ((char*)"Data/OBJs/Hero-LeftHand.obj", (char*)"Data/Textures/DiffuseMap-Hero.png", (char*)"Data/Shaders/Temp3DXZ.vert", (char*)"Data/Shaders/Temp3DXZ.frag");
	crystal->AddComponent<OBJModel>()->CreateOBJ((char*)"Data/OBJs/Hero-Crystal.obj", (char*)"Data/Textures/DiffuseMap-Hero.png", (char*)"Data/Shaders/Temp3DXZ.vert", (char*)"Data/Shaders/Temp3DXZ.frag");
	ring->AddComponent<OBJModel>()->CreateOBJ((char*)"Data/OBJs/Hero-Ring.obj", (char*)"Data/Textures/DiffuseMap-Hero.png", (char*)"Data/Shaders/Temp3DXZ.vert", (char*)"Data/Shaders/Temp3DXZ.frag");

	head->AddComponent<WobbleComponent>()->AddOffset(0.4f);
	body->AddComponent<WobbleComponent>();
	rightShoulder->AddComponent<WobbleComponent>()->AddOffset(0.2f);
	leftShoulder->AddComponent<WobbleComponent>()->AddOffset(0.2f);
	rightHand->AddComponent<WobbleComponent>()->AddOffset(0.3f);
	leftHand->AddComponent<WobbleComponent>()->AddOffset(0.5f);
	ring->AddComponent<WobbleComponent>()->AddOffset(PI);

	AddChild(head);
	AddChild(body);
	AddChild(rightShoulder);
	AddChild(leftShoulder);
	AddChild(rightHand);
	AddChild(leftHand);
	AddChild(crystal);
	AddChild(ring);
}
Hero::~Hero()
{
	//nothing to do
}