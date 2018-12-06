#ifndef __TLGE__MOUSE_MOVE_H__
#define __TLGE__MOUSE_MOVE_H__

namespace TLGE
{
	/**************************************************************************
	* MouseMove is passed when a pointer of some sort is moved                *
	***************************************************************************/
	class MouseMove : public Event
	{
	public:
		//Event type is set on creation and cannot be changed
		MouseMove();
		virtual ~MouseMove();

		//Getters
		glm::ivec2 GetPosition() { return m_position; }

		//Setters
		void SetPosition(glm::ivec2 position) { m_position = position; }

	private:
		glm::ivec2 m_position;
	};
}

#endif