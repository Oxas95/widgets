#include "deplacable.hpp"
#include <iostream>

DeplacableRect::DeplacableRect(sf::RenderWindow& f) : DynamicWidget(f) {
	deplacable_x = deplacable_y = true;
	mouse_pressed = false;
	shape = NULL;
}

Deplacable::~Deplacable(){
	if(shape) delete shape;
	printf("deplacable deleted\n");
}

dynamicWidgetType Deplacable::getDynamicWidgetType(){
	return deplacable;
}

void eventNdraw(sf::Vector2i& posClic){
	sf::Event event;
	while (window->pollEvent(event)){
		if (event.type == sf::Event::Closed){
			close();
		}
		if(event.type == sf::Event::MouseButtonPressed){
			mouse_pressed = true;
		}
		
		if(event.type == sf::Event::MouseButtonReleased){
			mouse_pressed = false;
		}
	}
	
	master = mouse_pressed;
	
	
}

void setPosition(int x, int y){
	shape.setPosition(x,y);
}

sf::Vector2i getPosition(){
	return shape.getPosition();
}

void setColor(sf::Color c){
	shape.setFillColor(c);
}

sf::Color getColor(){
	return shape.getFillColor();
}

void setBorderColor(sf::Color c){
	shape.setOutlineColor(c);
}

sf::Color getBorderColor(){
	return shape.getOutlineColor();
}
