#ifndef buttonCircle_hpp
#define buttonCircle_hpp

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "widgetBox.hpp"

class ButtonCircle : public WidgetBox{
	protected :
		sf::CircleShape circle;
		bool activated;
		bool pushed;
		
	public :
		int sizeButton[2]; //this size is the radius of the button. to get the full size, calcul sizeButton[] * 2 + borderSize[] * 2
		bool stay_activated;
		
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
