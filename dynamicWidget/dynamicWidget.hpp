#ifndef dynamicWidget_hpp
#define dynamicWidget_hpp

#include "../widget.hpp"

typedef enum {
	deplacable
	deplacableRect,
	deplacableCircle
} dynamicWidgetType;

const char* parseString(dynamicWidgetType);

class DynamicWidget : public Widget {
	
	protected :
		sf::Vector2i position;
		int* val;
	
	public :
		DynamicWidget(sf::RenderWindow&);
		~DynamicWidget();
		
		void setPosition(int x, int y);
		sf::Vector2i getPosition();
		
		int getVal();
		void setVal(int*);
		
		widgetType getWidgetType();
		virtual dynamicWidgetType getDynamicWidgetType() = 0;
		virtual void eventNdraw(sf::Vector2i& posClic) = 0;
};

#endif //dynamicWidget_hpp
