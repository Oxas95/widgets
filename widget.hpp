#ifndef widget_hpp
#define widget_hpp

#include "fenetre.hpp"
#include <iostream>
#include <string>

typedef enum{
	undefined,
	button
} widgetType;

class Widget{
	private :
		static int nextID;
	
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
		
	
		Widget(Fenetre&);
		virtual ~Widget();
		void setText(const char* str, int sizeText, sf::Color textColor);
		const char* getText();
		void loadImage(const char* path); //set path to NULL to remove image
		widgetType getWidgetType();
		int getID();
		bool isMaster();
		
		virtual void eventNdraw(sf::Vector2i& posClic) = 0;
};

#endif //widget_hpp
