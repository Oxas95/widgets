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
		sf::Texture texture;
		std::string text;
		
	public :
		sf::Vector2i position;
		sf::Color notUsed;
		sf::Color isUsed;
		sf::Color borderColor;
		sf::Sprite* sprite; //is set to public to customize the sprite, but can be loaded with loadImage(const char*)
		
		
		int sizeText;
		sf::Color textColor;
		sf::Vector2i textPosition;
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
