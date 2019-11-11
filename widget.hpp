#ifndef widget_hpp
#define widget_hpp

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

typedef enum{
	box,
	dynamic
} widgetType;

typedef enum{
	Off = 0,
	Hover = 2,
	On = 1
} widgetStatus;

class Widget{
	private :
		static int nextID;
	
	protected :
		const int ID;
		sf::RenderWindow& f;
		widgetType type;
		bool master;
		
	public :
		sf::Vector2i position[2];
		sf::Color background[3];
		sf::Color borderColor[3];
		
		int borderSize[2];
		//array-var of size 2 : { status of widget }
		
		bool changeIfHover;
		
		Widget(sf::RenderWindow&);
		virtual ~Widget();
		int getID();
		bool isMaster();
		
		virtual void eventNdraw(sf::Vector2i& posClic) = 0;
		virtual widgetType getWidgetType() = 0;
};

#endif //widget_hpp
