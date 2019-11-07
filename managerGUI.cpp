#include "managerGUI.hpp"

ManagerGUI::ManagerGUI() {
	widgetList = NULL;
	sizeList = 0;
}

ManagerGUI::~ManagerGUI() {
	delWidget(false);
}

//ajoute en début de liste un widget
void ManagerGUI::addWidget(Widget* w) {
	ManagerList* newWidget = new ManagerList();
	newWidget->widget = w;
	newWidget->next = widgetList;
	widgetList = newWidget;
	sizeList++;
}

//supprime le widget au début de la liste, la mémoire alloué au widget peut être libéré si voulu
void ManagerGUI::delWidget(bool freeMemWidget) {
	if(widgetList){
		ManagerList* del = widgetList;
		widgetList = widgetList->next;
		if(freeMemWidget) delete del->widget;
		delete del;
		sizeList--;
	}
}

ManagerList* delWidgetID(ManagerList* ml, int ID, freeMemWidget){
	if(!ml) return NULL;
	else if(ml->widget->getID() = ID){
		ManagerList* del = ml;
		ml = ml->next;
		if(freeMemWidget) delete del->widget;
		delete del;
		return ml;
	}
	else {
		ml->next = delWidgetID(ml->next, ID, freeMemWidget);
		return ml;
	}
}

void ManagerGUI::delWidgetID(int ID, bool freeMemWidget){
	widgetList = delWidgetID(widgetList, ID, freeMemWidget);
}

void ManagerGUI::useWidgets(){
	eventNdraw();
	ManagerList* ml = widgetList;
	while(ml){
		ml->widget->eventNdraw(lastClicPosition);
		ml = ml->next;
	}
}

int ManagerGUI::getSizeList(){
	return sizeList;
}

Widget* ManagerGUI::getWidget(int i){
	if(i < 0 || i >= sizeList) return NULL;
	ManagerList* ml = widgetList;
	for(int j = 0; j < i; j++) ml = ml->next;
	return ml->widget;
}

Widget* ManagerGUI::getWidgetWithID(int ID){
	if(i < 0 || i >= sizeList) return NULL;
	ManagerList* ml = widgetList;
	for(int j = 0; j < i; j++) ml = ml->next;
	return ml->widget;
}

//indique si un widget de la liste est maître
bool otherIsMaster(ManagerList* ml){
	if(ml){
		if(ml->widget->isMaster() && ml->widget->getWidgetType() != button) return true;
		else return otherIsMaster(ml->next);
	}
	else return false;
}

void ManagerGUI::eventNdraw(){
	if(!otherIsMaster()) masterID = -1;
	if(masterID = ID){
		sf::Event event;
		while (f.getWindow()->pollEvent(event)){
			if (event.type == sf::Event::Closed){
				f.close();
			}
			else if(event.type == sf::Event::KeyPressed){
				isPressedKey = true;
				eventKey = event.key.code;
			}
			
			else if(event.type == sf::Event::KeyReleased){
				isPressedKey = false;
				eventKey = event.key.code;
			}
			
			else if (event.type == sf::Event::MouseButtonPressed){
				if (event.mouseButton.button == sf::Mouse::Left){
					lastClicPosition = sf::Mouse::getPosition(*(f.getWindow()));
				}
				eventKey = sf::Keyboard::Unknown;
			}
			else eventKey = sf::Keyboard::Unknown;
		}
	}
	masterID = -1;
}
