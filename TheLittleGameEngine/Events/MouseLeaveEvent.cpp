#include "EnginePCH.h"

namespace TLGE
{
	MouseLeaveEvent::MouseLeaveEvent() :
		Event()
	{
		m_type = (char*)"MOUSE_LEAVE";
	}
	MouseLeaveEvent::~MouseLeaveEvent()
	{
		//nothing to do
	}
}