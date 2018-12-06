#ifndef __SWAP_COMPONENT__
#define __SWAP_COMPONENT__

#include "TLGE.h"

class SwapComponent : public TLGE::Component
{
public:
	SwapComponent(TLGE::GameObject* objectInCharge);
	~SwapComponent();

	void Update(float deltaTime);
	void HandleEvent(TLGE::Event* event);

	//Setters
	void SetOtherMesh(TLGE::Mesh* mesh) { m_otherMesh = mesh; }
	void SetOtherTexture(TLGE::Texture* texture) { m_otherTexture = texture; }

private:
	TLGE::Mesh* m_otherMesh;
	TLGE::Texture* m_otherTexture;
};

#endif