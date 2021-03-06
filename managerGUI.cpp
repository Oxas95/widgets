#include "managerGUI.hpp"
#include <stdio.h>
#include <stdlib.h>

ManagerGUI::ManagerGUI(sf::RenderWindow& _f) : ListWidget(), f(_f) {
	isPressedKey = false;
	eventKey = sf::Keyboard::Unknown;
	lastClicPosition.x = -1;
	lastClicPosition.y = -2;
}

ManagerGUI::~ManagerGUI() {
	printf("managerGUI deleted\n");
}

void ManagerGUI::useWidgets(){
	eventNdraw();
	Listwidget* ml = widgetList;
	while(ml){
		ml->widget->eventNdraw(lastClicPosition);
		ml = ml->next;
	}
}

//indique si un widget de la liste est maître
int otherIsMaster(Listwidget* ml){
	if(ml){
		if(ml->widget->isMaster()) return ml->widget->getID();
		else return otherIsMaster(ml->next);
	}
	else return -1;
}

void ManagerGUI::eventNdraw(){
	masterID = otherIsMaster(widgetList);
	if(masterID == -1){
		sf::Event event;
		while (f.pollEvent(event)){
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
					lastClicPosition = sf::Mouse::getPosition(f);
				}
				eventKey = sf::Keyboard::Unknown;
			}
			else eventKey = sf::Keyboard::Unknown;
		}
	}
}

int ManagerGUI::getMasterID(){
	return masterID;
}
