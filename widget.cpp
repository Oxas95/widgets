#include "widget.hpp"
#include <iostream>
#include <string>

using namespace std;

const char* parseString(widgetType w){
	string s;
	
	switch(w){
		case widgetBox 		: 	s = "widgetBox";			break;
		case dynamicWidget 	: 	s = "dynamicWidget";		break;
		case radioList 		: 	s = "radioList";			break;
		default				:	s = "undefined";			break;
	}
	return s.c_str();
}

int Widget::nextID = 0;

Widget::Widget(sf::RenderWindow& _f) : ID(nextID), f(_f) {
	nextID++;
	master = false;
}

Widget::~Widget() {
	printf("widget deleted\n");
}

int Widget::getID(){
	return ID;
}

bool Widget::isMaster(){
	return master;
}
