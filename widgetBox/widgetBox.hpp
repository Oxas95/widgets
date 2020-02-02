#ifndef widgetBox_hpp
#define widgetBox_hpp

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "../widget.hpp"

typedef enum{
	undefined,
	buttonRect,
	buttonCircle,
	textArea,
	radioButton,
	radioBox
} widgetBoxType;

const char* parseString(widgetBoxType);

class WidgetBox : public Widget{
	protected :
		sf::Font font[2];
		
		sf::Vector2i position[2];
		int borderSize[2];
		
	public :
		sf::Sprite* sprite[2]; //is set to public to customize the sprite, but can be loaded with loadImage(const char*)
		sf::Texture texture[2];
		
		sf::Text text[2];
		//array-var of size 2 : { status of widget }
		
		
		sf::Color background[2];
		sf::Color borderColor[2];
		
		bool changeIfHover;
		bool includeBorderInEvent;
		
		
		WidgetBox(sf::RenderWindow&);
		virtual ~WidgetBox();
		//if sizeText = 0 the text will not be displayed
		void setText(widgetStatus, const char* str, int sizeText, sf::Color textColor, sf::Vector2i textPosition, const char* ttfPath);
		void setText(widgetStatus, const char* str, int sizeText, sf::Color textColor, sf::Vector2i textPosition);
		void setText(widgetStatus, const char* str, int sizeText, sf::Color textColor);
		void setText(widgetStatus, const char* ttfPath);
		int getWidthText(widgetStatus);
		int getHeightText(widgetStatus);
		void loadImage(widgetStatus, const char* path); //set path to NULL to remove image
		
		
		virtual sf::Vector2i getPosition(widgetStatus);
		virtual void setPosition(widgetStatus, int x, int y);
		virtual int getBorderSize(widgetStatus);
		virtual void setBorderSize(widgetStatus, int);
		
		virtual void eventNdraw(sf::Vector2i& posClic) = 0;
		widgetType getWidgetType();
		
		virtual widgetBoxType getWidgetBoxType() = 0;
};

#endif //widgetBox_hpp
