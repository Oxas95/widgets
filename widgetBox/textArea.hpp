#ifndef textArea_hpp
#define textArea_hpp

#include "widgetBox.hpp"

class TextArea : protected widgetBox {
	private :
		
	
	public :
		TextArea(sf::RenderWindow&);
		~TextArea();
		
		void eventNdraw(sf::Vector2i& posClic);
		widgetBoxType getWidgetBoxType();
		
};

#endif textArea_hpp
