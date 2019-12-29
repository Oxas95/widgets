#ifndef textArea_hpp
#define textArea_hpp

#include "widgetBox.hpp"

class TextArea : public WidgetBox {
	// all 'On' parts are not used, only the 'Off' part is used 
	// (exemple in widgetBox : sprite[Off], text[Off],... are used to draw)
	// The 'On' part can store what you want)
	
	private :
		sf::RectangleShape rectangle;
	
	public :
		
		sf::Vector2i size;
		
		TextArea(sf::RenderWindow&);
		~TextArea();
		
		void eventNdraw(sf::Vector2i& posClic);
		void drawText();
		widgetBoxType getWidgetBoxType();
		
};

#endif //textArea_hpp
