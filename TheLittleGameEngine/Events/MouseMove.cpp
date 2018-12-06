#include "EnginePCH.h"

namespace TLGE
{
	MouseMove::MouseMove() :
		Event(),
		m_position(0)
	{
		m_type = (char*)"MOUSE_MOVE";
	}
	MouseMove::~MouseMove()
	{
		//nothing to do
	}
}