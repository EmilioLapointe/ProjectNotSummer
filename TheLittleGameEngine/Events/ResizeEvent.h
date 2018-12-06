#ifndef __TLGE__RESIZE_EVENT_H__
#define __TLGE__RESIZE_EVENT_H__

namespace TLGE
{
	/**************************************************************************
	* ResizeEvent is passed when the window is resized                        *
	***************************************************************************/
	class ResizeEvent : public Event
	{
	public:
		//Event type is set on creation and cannot be changed
		ResizeEvent();
		virtual ~ResizeEvent();

		//Getters
		glm::ivec2 GetSize() { return m_size; }

		//Setters
		void SetSize(glm::ivec2 size) { m_size = size; }

	private:
		glm::ivec2 m_size;
	};
}

#endif