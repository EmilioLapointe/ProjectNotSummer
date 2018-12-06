#include "EnginePCH.h"

namespace TLGE
{
	System::System(Scene* aSceneInCharge) :
		m_sceneInCharge(aSceneInCharge),
		m_active(true)
	{
		assert(aSceneInCharge);
	}
	System::~System()
	{
		//nothing to do
	}
}