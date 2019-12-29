#include "widget.hpp"

int Widget::nextID = 0;

Widget::Widget(sf::RenderWindow& _f) : ID(nextID), f(_f) {
	nextID++;
	for (int i = 0; i < 2; i++){
		borderColor[i] = sf::Color::Black;
		borderSize[i] = 1;
		position[i].x = position[i].y = -1;
	}
	background[Off] = sf::Color(120,120,120);
	background[On] = sf::Color(180,180,180);
	master = false;
	changeIfHover = false;
	includeBorderInEvent = true;
}

Widget::~Widget() {
	printf("widget deleted\n");
}

widgetType Widget::getWidgetType() {
	return type;
}

int Widget::getID(){
	return ID;
}

bool Widget::isMaster(){
	return master;
}
