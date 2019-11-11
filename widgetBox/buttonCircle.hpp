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
		
	public :
		ButtonCircle(sf::RenderWindow&);
		~ButtonCircle();
		void moveTextTop(widgetStatus usage);
		void moveTextBottom(widgetStatus usage);
		void moveTextLeft(widgetStatus usage);
		void moveTextRight(widgetStatus usage);
		void moveTextInCenter(widgetStatus usage, bool on_X, bool on_Y);
		void eventNdraw(sf::Vector2i& posClic);
		bool isActivated();
		bool isPushed();
		
		widgetBoxType getWidgetBoxType();
};

#endif //button_hpp
