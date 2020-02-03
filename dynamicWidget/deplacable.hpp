#ifndef deplacable_hpp
#define deplacable_hpp

#include "dynamicWidget.hpp"

class Deplacable : public DynamicWidget {
	protected :
		bool mouse_pressed;
		sf::Vector2i ecartOrigine;
		sf::Shape* shape;
	
	public :
		
		bool deplacable_x;
		bool deplacable_y;
		
		Deplacable(sf::RenderWindow&);
		virtual ~Deplacable();
		dynamicWidgetType getDynamicWidgetType();
		virtual bool InShape(sf::Vector2i coord) = 0;
		void setPosition(int x, int y);
		sf::Vector2i getPosition();
		void setColor(sf::Color);
		sf::Color getColor();
		void setBorderColor(sf::Color);
		sf::Color getBorderColor();
};

#endif //deplacable_hpp
