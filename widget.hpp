#ifndef widget_hpp
#define widget_hpp

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

typedef enum{
	widgetBox,
	dynamicWidget,
	radioList
} widgetType;

const char* parseString(widgetType);

typedef enum{
	Off = 0,
	On = 1
} widgetStatus;

class Widget{
	private :
		static int nextID;
	
	protected :
		const int ID;
		sf::RenderWindow& f;
		bool master;
		
	public :
		
		Widget(sf::RenderWindow&);
		virtual ~Widget();
		int getID();
		bool isMaster();
		
		virtual void eventNdraw(sf::Vector2i& posClic) = 0;
		virtual widgetType getWidgetType() = 0;
};

#endif //widget_hpp
