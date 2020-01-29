#include "dynamicWidget.hpp"
#include <exception>
#include <string>

using namespace std;

DynamicWidget::DynamicWidget(sf::RenderWindow& f) : Widget(f) {
	val = NULL;
}

DynamicWidget::~DynamicWidget(){
	
}

void DynamicWidget::setPosition(int x, int y){
	position.x = x;
	position.y = y;
}

sf::Vector2i DynamicWidget::getPosition(){
	return position;
}

int DynamicWidget::getVal(){
	if(val == NULL) throw string("Null Pointer Exception");
	return *val;
}

void DynamicWidget::setVal(int* i){
	val = i;
}
