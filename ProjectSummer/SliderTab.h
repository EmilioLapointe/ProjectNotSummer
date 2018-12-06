#ifndef _TLGE_SliderTab_H__
#define _TLGE_SliderTab_H__
#include <TLGE.h>

class SliderTab : public TLGE::Button
{
public:

	float MousePos1;
	glm::vec3 MousePos;
	bool follow = false;
	bool amIHorizontal;
	float minimumBound;//probably integrat
	float maximumBound;//probably integrate
	float value = 50.0f;
	float Xposition=0.0f;
	TLGE::GameObject* thisTab;
	glm::vec3 oldPosition;

	SliderTab(TLGE::GameObject* objectInCharge); //take in more arguments
	virtual ~SliderTab();

	void Update(float detaTime);

	void OnClick();

	void OnUnClick();

	void HandleEvent(TLGE::Event* event);

	void BindLimits(float amin, float amax);
	void SetHorizontal(bool horizontal) { amIHorizontal = horizontal; }

	glm::vec3 GetWorldPosOfScreenpos(TLGE::Camera cam, const glm::vec3 &planePoint, const glm::vec3 &planeNormal, const glm::ivec2 &screenPos);


 };
#endif // !_TLGE_SliderTab_H__
