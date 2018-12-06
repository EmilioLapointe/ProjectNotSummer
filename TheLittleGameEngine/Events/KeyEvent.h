#ifndef __TLGE__KEY_EVENT_H__
#define __TLGE__KEY_EVENT_H__

namespace TLGE
{
	enum KeyState
	{
		KeyState_JustPressed,
		KeyState_Unpressed,
		NumKeyStates,
		KeyState_Invalid
	};

	/**************************************************************************
	* KeyEvent is passed when a key of some sort is pressed or released       *
	*                                                                         *
	* Important notes:                                                        *
	*	- visit https://msdn.microsoft.com/en-us/library/windows/desktop/dd375731(v=vs.85).aspx 
	*		for key codes                                                     *
 	***************************************************************************/
	class KeyEvent : public Event
	{
	public:
		//Event type is set on creation and cannot be changed
		KeyEvent();
		virtual ~KeyEvent();

		//Getters
		unsigned char GetKey() { return m_key; }
		KeyState GetState() { return m_state; }

		//Setters
		void SetKey(unsigned char key) { m_key = key; }
		void SetState(KeyState state) { m_state = state; }

	private:
		KeyState m_state;
		unsigned char m_key;
	};
}

#endif