#ifndef widget_hpp
#define widget_hpp

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Byte/Byte.hpp"

typedef enum{
	box,
	dynamic
} widgetType;

#define whenNotUsed zero
#define whenUsed un

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
		sf::Color background[2];
		sf::Color borderColor[2];
		
		int borderSize[2];
		//array-var of size 2 : { when not used, when used }
	
		Widget(sf::RenderWindow&);
		virtual ~Widget();
		int getID();
		bool isMaster();
		
		virtual void eventNdraw(sf::Vector2i& posClic) = 0;
		virtual widgetType getWidgetType() = 0;
};

#endif //widget_hpp
