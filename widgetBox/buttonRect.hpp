#ifndef buttonRect_hpp
#define buttonRect_hpp

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "widgetBox.hpp"

class ButtonRect : public WidgetBox{
	private :
		sf::RectangleShape rectangle;
		bool activated;
		bool pushed;
		
	public :
		sf::Vector2i sizeButton[2];
		bool stay_activated;
		bool includeBorderInEvent;
		
	public :
		ButtonRect(sf::RenderWindow&);
		~ButtonRect();
		void moveTextTop(Byte usage);
		void moveTextBottom(Byte usage);
		void moveTextLeft(Byte usage);
		void moveTextRight(Byte usage);
		void moveTextInCenter(Byte usage, bool on_X, bool on_Y);
		void eventNdraw(sf::Vector2i& posClic);
		bool isActivated();
		bool isPushed();
		
		widgetBoxType getWidgetBoxType();
};

#endif //button_hpp
