#include "Evil.h"
#include "WobbleComponent.h"

using namespace TLGE;

Evil::Evil(char* aName) :
	GameObject(aName)
{
	char headString[] = "-Head";
	char bodyString[] = "-Body";
	char rightShoulderString[] = "-RightShoulder";
	char leftShoulderString[] = "-LeftShoulder";
	char rightHandString[] = "-RightHand";
	char leftHandString[] = "-LeftHand";

	char* headStringFull = new char[strlen(headString) + strlen(aName) + 1];
	char* bodyStringFull = new char[strlen(bodyString) + strlen(aName) + 1];
	char* rightShoulderStringFull = new char[strlen(rightShoulderString) + strlen(aName) + 1];
	char* leftShoulderStringFull = new char[strlen(leftShoulderString) + strlen(aName) + 1];
	char* rightHandStringFull = new char[strlen(rightHandString) + strlen(aName) + 1];
	char* leftHandStringFull = new char[strlen(leftHandString) + strlen(aName) + 1];

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
#endif

	GameObject* head = new GameObject(headStringFull);
	GameObject* body = new GameObject(bodyStringFull);
	GameObject* rightShoulder = new GameObject(rightShoulderString);
	GameObject* leftShoulder = new GameObject(leftShoulderStringFull);
	GameObject* rightHand = new GameObject(rightHandStringFull);
	GameObject* leftHand = new GameObject(leftHandStringFull);

	delete[] headStringFull;
	delete[] bodyStringFull;
	delete[] rightShoulderStringFull;
	delete[] leftShoulderStringFull;
	delete[] rightHandStringFull;
	delete[] leftHandStringFull;

	//TODO:shorten to use only one copy of shader and texture
	head->AddComponent<OBJModel>()->CreateOBJ((char*)"Data/OBJs/Evil-Head.obj", (char*)"Data/Textures/DiffuseMap-Evil.png", (char*)"Data/Shaders/Temp3DXZ.vert", (char*)"Data/Shaders/Temp3DXZ.frag");
	body->AddComponent<OBJModel>()->CreateOBJ((char*)"Data/OBJs/Evil-Body.obj", (char*)"Data/Textures/DiffuseMap-Evil.png", (char*)"Data/Shaders/Temp3DXZ.vert", (char*)"Data/Shaders/Temp3DXZ.frag");
	rightShoulder->AddComponent<OBJModel>()->CreateOBJ((char*)"Data/OBJs/Evil-RightShoulder.obj", (char*)"Data/Textures/DiffuseMap-Evil.png", (char*)"Data/Shaders/Temp3DXZ.vert", (char*)"Data/Shaders/Temp3DXZ.frag");
	leftShoulder->AddComponent<OBJModel>()->CreateOBJ((char*)"Data/OBJs/Evil-LeftShoulder.obj", (char*)"Data/Textures/DiffuseMap-Evil.png", (char*)"Data/Shaders/Temp3DXZ.vert", (char*)"Data/Shaders/Temp3DXZ.frag");
	rightHand->AddComponent<OBJModel>()->CreateOBJ((char*)"Data/OBJs/Evil-RightHand.obj", (char*)"Data/Textures/DiffuseMap-Evil.png", (char*)"Data/Shaders/Temp3DXZ.vert", (char*)"Data/Shaders/Temp3DXZ.frag");
	leftHand->AddComponent<OBJModel>()->CreateOBJ((char*)"Data/OBJs/Evil-LeftHand.obj", (char*)"Data/Textures/DiffuseMap-Evil.png", (char*)"Data/Shaders/Temp3DXZ.vert", (char*)"Data/Shaders/Temp3DXZ.frag");

	head->AddComponent<WobbleComponent>()->AddOffset(0.4f);
	body->AddComponent<WobbleComponent>();
	rightShoulder->AddComponent<WobbleComponent>()->AddOffset(0.2f);
	leftShoulder->AddComponent<WobbleComponent>()->AddOffset(0.2f);
	rightHand->AddComponent<WobbleComponent>()->AddOffset(0.3f);
	leftHand->AddComponent<WobbleComponent>()->AddOffset(0.5f);

	AddChild(head);
	AddChild(body);
	AddChild(rightShoulder);
	AddChild(leftShoulder);
	AddChild(rightHand);
	AddChild(leftHand);
}
Evil::~Evil()
{
	//nothing to do
}