#ifndef widget_hpp
#define widget_hpp

#include "fenetre.hpp"
#include <iostream>
#include <string>

typedef enum{
	undefined,
	button
} widgetType;

typedef enum{
	zero = 0,
	un = 1
} Byte;

#define whenNotUsed 0
#define whenUsed 1

class Widget{
	private :
		static int nextID;
	
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
		
		int borderSize[2];
		int sizeText[2];
		sf::Color textColor[2];
		sf::Vector2i textPosition[2];
		//array-var of size 2 : { when not used, when used }
	
		Widget(Fenetre&);
		virtual ~Widget();
		void setText(Byte usage, const char* str, int sizeText, sf::Color textColor, sf::Vector2i textPosition);
		const char* getText(Byte usage);
		void loadImage(Byte usage, const char* path); //set path to NULL to remove image
		widgetType getWidgetType();
		int getID();
		bool isMaster();
		
		virtual void eventNdraw(sf::Vector2i& posClic) = 0;
};

#endif //widget_hpp
