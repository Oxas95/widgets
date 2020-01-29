#ifndef radioButton_hpp
#define radioButton_hpp

#include "widgetBox.hpp"

class RadioButton : public WidgetBox{
	
	private :
		sf::CircleShape externCircle;
		sf::CircleShape circle;
		
		bool pushed;
		int sizeButton;
		bool stay_activated;
	
	public :
		sf::Color externBorderColor;
		bool activated;
		
		RadioButton(sf::RenderWindow&);
		~RadioButton();
		
		void eventNdraw(sf::Vector2i& posClic);
		
		widgetBoxType getWidgetBoxType();
		
		void moveTextTop();
		void moveTextBottom();
		void moveTextLeft();
		void moveTextRight();
		void moveTextInCenter(bool on_X, bool on_Y);
		
		bool isPushed();
		
		int getRadius();
		int getSize();
		void setRadius(int);
		
		//for each status of position and borderSize, values are always equals. you can put Off or On, there is no difference
		void setPosition(widgetStatus, int x, int y);
		sf::Vector2i getPosition(widgetStatus);
		//so you can use these functions
		void setPosition(int x, int y);
		sf::Vector2i getPosition();
		
		//size can't be changed, this override for setter don't do nothing to lock value of borderSize
		int getBorderSize(widgetStatus);
		void setBorderSize(widgetStatus, int);
		int getBorderSize();
		void setBorderSize(int);
		
		//text[On] is not used

};

#endif //radioButton_hpp
