#ifndef deplacableRect_hpp
#define deplacableRect_hpp

#include "deplacable.hpp"

class DeplacableRect : public Deplacable {	
	protected :
		sf::Shape* shape;
		
	public :
		
		DeplacableRect(sf::RenderWindow&);
		~DeplacableRect();
		dynamicWidgetType getDynamicWidgetType();
		void eventNdraw(sf::Vector2i& posClic);
};

#endif //deplacableRect_hpp
