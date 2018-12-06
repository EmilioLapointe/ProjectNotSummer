#ifndef __TLGE__BUTTON_H__
#define __TLGE__BUTTON_H__

namespace TLGE
{
	/**************************************************************************
	* Button class is a class that is ment to be inherited from. It adds      *
	* button-like functionality to a game object                              *
	*                                                                         *
	* Important notes:                                                        *
	*	-Button does nothing on it's own and shoud be inherited for           *
	*    functionality                                                        *
	***************************************************************************/
	class Button : public Component
	{
	public:
		//Object in charge is set on creation and cannot be changed
		Button(GameObject* objectInCharge);
		virtual ~Button();

		//Regular update. Must be overwritten.
		virtual void Update(float deltaTime);

		//Gets called whenever an event happens
		void HandleEvent(Event* event);

		//This functions uses the existing sprite to create a button
		void CreateButtonFromSprite();

	protected:
		//This function gets called whenever the button is clicked
		virtual void OnClick() {};

		//This function gets called whenever the button is unclicked
		virtual void OnUnClick() {};

	private:
		glm::vec2 m_halfDimentions;

		bool m_isClicked;
	};
}

#endif