#ifndef managerGUI_hpp
#define managerGUI_hpp

#include "listWidget.hpp"

class ManagerGUI : public ListWidget {
	protected :
		int masterID;
		void eventNdraw();
		sf::RenderWindow& f;
	
	public :
		sf::Vector2i lastClicPosition;
		sf::Keyboard::Key eventKey;
		bool isPressedKey;
		
		ManagerGUI(sf::RenderWindow&);
		~ManagerGUI();
		
		virtual void useWidgets();
		int getMasterID();
};

#endif //managerGUI_hpp
