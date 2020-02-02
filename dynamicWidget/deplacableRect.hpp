#ifndef deplacableRect_hpp
#define deplacableRect_hpp

#include "dynamicWidget.hpp"

class DeplacableRect : public DynamicWidget {
	protected :
	
	
	public :
		DeplacableRect(sf::RenderWindow&);
		~DeplacableRect();
		dynamicWidgetType getDynamicWidgetType();
};

#endif //deplacableRect_hpp
