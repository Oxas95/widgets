#ifndef managerGUI_hpp
#define managerGUI_hpp

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
		
		void eventNdraw();
	
	public :
		ManagerList* widgetList;
		sf::Vector2i lastClicPosition;
		sf::Keyboard::Key eventKey;
		bool isPressedKey;
		
		ManagerGUI(Fenetre&);
		~ManagerGUI();
		
		void addWidget(Widget* w);
		void delWidget(bool freeMemWidget);
		void delWidgetID(int ID, bool freeMemWidget);
		void useWidgets();
		int getSizeList();
		Widget* getWidget(int i);
		Widget* getWidgetWithID(int ID);
};

#endif //managerGUI_hpp
