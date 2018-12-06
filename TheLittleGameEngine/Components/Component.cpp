#include "EnginePCH.h"

namespace TLGE
{
	Component::Component(GameObject* aObjectInCharge):
		m_objectInCharge(aObjectInCharge)
	{
		//TODO: fix 0 to nullptr(obj in charge)
		assert(aObjectInCharge != 0 && aObjectInCharge != 0);
	}
	Component::~Component()
	{
		//nothing to do
	}
}