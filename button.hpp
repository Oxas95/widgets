#ifndef button_hpp
#define button_hpp

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "widget.hpp"

class Button : public Widget{
	private :
		sf::RectangleShape rectangle;
		bool activated;
		
	public :
		sf::Vector2i sizeButton;
		bool stay_activated;
		
	public :
		Button(Fenetre&);
		~Button();
		void eventNdraw(sf::Vector2i& posClic);
};

#endif //button_hpp
