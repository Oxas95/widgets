#ifndef managerGUI_hpp
#define managerGUI_hpp

#include "fenetre.hpp"
#include "widget.hpp"

namespace listManager {

	typedef struct ManagerListWidget{
		Widget* widget;
		ManagerListWidget* next;
	} ManagerList;

} using namespace listManager;

class ManagerGUI {
	private :
		int sizeList;
		int masterID;
		ManagerList* widgetList;
		sf::RenderWindow& f;
		void eventNdraw();
	
	public :
		sf::Vector2i lastClicPosition;
		sf::Keyboard::Key eventKey;
		bool isPressedKey;
		
		ManagerGUI(sf::RenderWindow&);
		~ManagerGUI();
		
		void addWidget(Widget* w);
		void delWidget();
		void delWidgetID(int ID);
		void useWidgets();
		int getSizeList();
		Widget* getWidget(int i);
		Widget* getWidgetWithID(int ID);
};

#endif //managerGUI_hpp
