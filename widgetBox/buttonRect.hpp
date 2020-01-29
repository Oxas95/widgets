#ifndef buttonRect_hpp
#define buttonRect_hpp

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "widgetBox.hpp"

class ButtonRect : public WidgetBox{
	protected :
		sf::RectangleShape rectangle;
		bool activated;
		bool pushed;
		
	public :
		sf::Vector2i sizeButton[2];
		bool stay_activated;
		
		ButtonRect(sf::RenderWindow&);
		virtual ~ButtonRect();
		void moveTextTop(widgetStatus usage);
		void moveTextBottom(widgetStatus usage);
		void moveTextLeft(widgetStatus usage);
		void moveTextRight(widgetStatus usage);
		void moveTextInCenter(widgetStatus usage, bool on_X, bool on_Y);
		virtual void eventNdraw(sf::Vector2i& posClic);
		bool isActivated();
		bool isPushed();
		
		virtual widgetBoxType getWidgetBoxType();
};

#endif //button_hpp
