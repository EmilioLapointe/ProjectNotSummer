#ifndef __TLGE__MOUSE_LEAVE_EVENT_H__
#define __TLGE__MOUSE_LEAVE_EVENT_H__

namespace TLGE
{
	/**************************************************************************
	* MouseLeaveEvent is passed when a pointer of some sort leaves the window *
	***************************************************************************/
	class MouseLeaveEvent : public Event
	{
	public:
		//Event type is set on creation and cannot be changed
		MouseLeaveEvent();
		virtual ~MouseLeaveEvent();
	};
}

#endif