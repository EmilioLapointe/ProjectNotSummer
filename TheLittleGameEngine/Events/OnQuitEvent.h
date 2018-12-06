#ifndef __TLGE__ON_QUIT_EVENT_H__
#define __TLGE__ON_QUIT_EVENT_H__

namespace TLGE
{
	/**************************************************************************
	* OnQuitEvent is passed when the engine is exited somehow                 *
	***************************************************************************/
	class OnQuitEvent : public Event
	{
	public:
		//Event type is set on creation and cannot be changed
		OnQuitEvent();
		virtual ~OnQuitEvent();
	};
}

#endif