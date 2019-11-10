#ifndef widgetBox_hpp
#define widgetBox_hpp

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "../widget.hpp"

typedef enum{
	undefined,
	buttonRect,
	buttonCircle
} widgetBoxType;

class WidgetBox : public Widget{
	protected :
		sf::Font font[2];
		widgetBoxType boxType;
		
	public :
		sf::Sprite* sprite[2]; //is set to public to customize the sprite, but can be loaded with loadImage(const char*)
		sf::Texture texture[2];
		
		sf::Text text[2];
		//array-var of size 2 : { when not used, when used }
	
		WidgetBox(sf::RenderWindow&);
		virtual ~WidgetBox();
		void setText(Byte usage, const char* str, int sizeText, sf::Color textColor, sf::Vector2i textPosition, const char* ttfPath);
		void setText(Byte usage, const char* str, int sizeText, sf::Color textColor, sf::Vector2i textPosition);
		void setText(Byte usage, const char* str, int sizeText, sf::Color textColor);
		void setText(Byte usage, const char* ttfPath);
		int getWidthText(Byte usage);
		int getHeightText(Byte usage);
		void loadImage(Byte usage, const char* path); //set path to NULL to remove image
		
		virtual void eventNdraw(sf::Vector2i& posClic) = 0;
		widgetType getWidgetType();
		
		virtual widgetBoxType getWidgetBoxType() = 0;
};

#endif //widgetBox_hpp
