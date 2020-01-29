#ifndef dynamicWidget_hpp
#define dynamicWidget_hpp

#include "../widget.hpp"

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
};

#endif //dynamicWidget_hpp
