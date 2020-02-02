#include "deplacableRect.hpp"
#include <iostream>

DeplacableRect::DeplacableRect(sf::RenderWindow& f) : DynamicWidget(f) {
	
}

DeplacableRect::~DeplacableRect(){
	printf("deplacableRect deleted\n");
}

dynamicWidgetType DeplacableRect::getDynamicWidgetType(){
	return deplacableRect;
}
