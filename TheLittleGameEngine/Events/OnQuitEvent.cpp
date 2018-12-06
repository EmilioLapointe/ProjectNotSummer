#include "EnginePCH.h"

namespace TLGE
{
	OnQuitEvent::OnQuitEvent() :
		Event()
	{
		m_type = (char*)"ON_QUIT";
	}
	OnQuitEvent::~OnQuitEvent()
	{
		//nothing to do
	}
}