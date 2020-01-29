#ifndef radioList_hpp
#define radioList_hpp

#include "radioButton.hpp"
#include "../listWidget.hpp"

class RadioList : public Widget, protected ListWidget {
	
	private :
		
		int activatedID;
	
	public :
		
		RadioList(sf::RenderWindow&);
		~RadioList();
		
		void addWidget(RadioButton*);
		void delWidget();
		void delWidgetID(int ID);
		int getSizeList();
		RadioButton* getWidget(int i);
		RadioButton* getWidgetWithID(int ID);
		int getActivatedID();
		
		void eventNdraw(sf::Vector2i& posClic);
		widgetType getWidgetType();
};

#endif //radioList_hpp
