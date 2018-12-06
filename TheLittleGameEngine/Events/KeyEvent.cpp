#include "EnginePCH.h"

namespace TLGE
{
	KeyEvent::KeyEvent() :
		Event(),
		m_state(KeyState_Invalid),
		m_key(0)
	{
		m_type = (char*)"KEY";
	}
	KeyEvent::~KeyEvent()
	{
		//nothing to do
	}
}