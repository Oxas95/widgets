#ifndef buttonCircle_hpp
#define buttonCircle_hpp

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "widgetBox.hpp"

class ButtonCircle : public WidgetBox{
	private :
		sf::CircleShape circle;
		bool activated;
		bool pushed;
		
	public :
		int sizeButton[2];
		bool stay_activated;
		bool includeBorderInEvent;
		
	public :
		ButtonCircle(sf::RenderWindow&);
		~ButtonCircle();
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
