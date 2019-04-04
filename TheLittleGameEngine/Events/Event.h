#ifndef __TLGE__EVENT_H__
#define __TLGE__EVENT_H__

namespace TLGE
{
	/**************************************************************************
	* Event is the class that any event in the system inherits from. It is    *
	* the class that will be passed around whenever anything important        *
	* happens.                                                                *
	*                                                                         *
	* Important notes:                                                        *
	*	-Event is an abstract class and cannot be instantiated                *
	*	-Inheriting Events should name themselves in their constructor        *
	***************************************************************************/
	class Event
	{
	public:
		//Event type is set on creation and cannot be changed
		Event() { m_type = (char*)"UNDEFINED"; }
		virtual ~Event() {}

		//Getters
		char* GetType() { return m_type; }
		bool GetHandled() { return m_handled; }

		//Setters
		void SetHandled(bool handled) { m_handled = handled; }

	protected:
		char* m_type;
		bool m_handled{false};
	};
}

#endif