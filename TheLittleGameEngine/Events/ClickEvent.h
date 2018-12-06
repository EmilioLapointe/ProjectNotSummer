#ifndef __TLGE__CLICK_EVENT_H__
#define __TLGE__CLICK_EVENT_H__

namespace TLGE
{
	enum ClickState
	{
		ClickState_JustClicked,
		ClickState_Unclicked,
		NumClickStates,
		ClickState_Invalid
	};

	/**************************************************************************
	* ClickEvent is passed when a pointer of some sort is pressed or released *
	***************************************************************************/
	class ClickEvent : public Event
	{
	public:
		//Event type is set on creation and cannot be changed
		ClickEvent();
		virtual ~ClickEvent();

		//Getters
		glm::ivec2 GetPosition() { return m_position; }
		ClickState GetState() { return m_state; }

		//Setters
		void SetPosition(glm::ivec2 position) { m_position = position; }
		void SetState(ClickState state) { m_state = state; }

	private:
		ClickState m_state;
		glm::ivec2 m_position;
	};
}

#endif