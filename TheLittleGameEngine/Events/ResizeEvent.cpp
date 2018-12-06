#include "EnginePCH.h"

namespace TLGE
{
	ResizeEvent::ResizeEvent() :
		Event()
	{
		m_type = (char*)"RESIZE";
	}
	ResizeEvent::~ResizeEvent()
	{
		//nothing to do
	}
}