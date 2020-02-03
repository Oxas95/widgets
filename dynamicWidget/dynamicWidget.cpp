#include "dynamicWidget.hpp"
#include <exception>
#include <string>
#include <iostream>

using namespace std;

const char* parseString(dynamicWidgetType w){
	string s;
	switch(w){
		case deplacable		 	: 	s = "deplacable"; 			break;
		case deplacableRect 	: 	s = "deplacableRect"; 		break;
		case deplacableCircle 	: 	s = "deplacableCircle";		break;
		default 				: 	s = "undefined";			break;
	}
	return s.c_str();
}

DynamicWidget::DynamicWidget(sf::RenderWindow& f) : Widget(f) {
	val = NULL;
	position.x = 0;
	position.y = 0;
}

DynamicWidget::~DynamicWidget(){
	printf("dynamicWidget deleted\n");
}

void DynamicWidget::setPosition(int x, int y){
	position.x = x;
	position.y = y;
}

sf::Vector2i DynamicWidget::getPosition(){
	return position;
}

int DynamicWidget::getVal(){
	if(val == NULL) throw string("Null Pointer Exception on dynamicWidget with ID %d\n",getID());
	return *val;
}

void DynamicWidget::setVal(int* i){
	val = i;
}

widgetType DynamicWidget::getWidgetType(){
	return dynamicWidget;
}
