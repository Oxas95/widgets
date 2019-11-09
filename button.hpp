#ifndef button_hpp
#define button_hpp

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "widget.hpp"

class Button : public Widget{
	
	/*###  from class Widget :
	protected :
		const int ID;
		Fenetre& f;
		widgetType type;
		bool master;
		std::string text[2];
		
	public :
		sf::Vector2i position;
		sf::Color background[2];
		sf::Color borderColor[2];
		sf::Sprite* sprite[2]; //is set to public to customize the sprite, but can be loaded with loadImage(const char*)
		sf::Texture texture[2];
		
		int sizeText[2];
		sf::Color textColor[2];
		sf::Vector2i textPosition[2];
		//array-var of size 2 : { when not used, when used }
	###*/
	
	private :
		sf::RectangleShape rectangle;
		bool activated;
		bool pushed;
		
	public :
		sf::Vector2i sizeButton;
		bool stay_activated;
		
	public :
		Button(Fenetre&);
		~Button();
		void eventNdraw(sf::Vector2i& posClic);
		bool isActivated();
		bool isPushed();
};

#endif //button_hpp
