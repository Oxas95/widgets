#ifndef RadioBox_hpp
#define RadioBox_hpp

#include "widgetBox.hpp"

class RadioBox : public WidgetBox {
	
	private :
		sf::RectangleShape rectangle;
		bool pushed;
		bool stay_activated;
	
	public :
		bool activated;
		sf::Vector2i sizeButton;
		
		RadioBox(sf::RenderWindow&);
		~RadioBox();
		
		widgetBoxType getWidgetBoxType();
		
		void setBorderSize(widgetStatus, int); //borderSize locked to size 1
		
		//for each status of position and borderSize, values are always equals. you can put Off or On, there is no difference
		void setPosition(widgetStatus, int x, int y);
		sf::Vector2i getPosition(widgetStatus);
		//so you can use these functions
		void setPosition(int x, int y);
		sf::Vector2i getPosition();
		
		void moveTextTop(widgetStatus usage);
		void moveTextBottom(widgetStatus usage);
		void moveTextLeft(widgetStatus usage);
		void moveTextRight(widgetStatus usage);
		void moveTextInCenter(widgetStatus usage, bool on_X, bool on_Y);
		void eventNdraw(sf::Vector2i& posClic);
		bool isPushed();
};

#endif //RadioBox_hpp
