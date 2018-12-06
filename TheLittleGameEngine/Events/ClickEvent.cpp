#include "EnginePCH.h"

namespace TLGE
{
	ClickEvent::ClickEvent():
		Event(),
		m_state(ClickState_Invalid),
		m_position(0)
	{
		m_type = (char*)"CLICK";
	}
	ClickEvent::~ClickEvent()
	{
		//nothing to do
	}
}