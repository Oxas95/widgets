#include "button.hpp"

Button::Button(Fenetre& f) : Widget(f), rectangle(sf::Vector2f(0,0)) {
	sizeButton.x = 0;
	sizeButton.y = 0;
	type = button;
	stay_activated = true;
	activated = false;
}

Button::~Button() {
	if(sprite) delete sprite;
}

void Button::eventNdraw(sf::Vector2i& posClic){
	
	rectangle.setSize(sizeButton.x * 1.f, sizeButton.y * 1.f);
	rectangle.setPosition(sf::Vector2f(position.x, position.y);
	rectangle.setOutlineColor(borderColor);
	
	if(stay_activated == false) activated = false;
	
	if(posClic.x >= position.x && posClic.x <= position.x + sizeButton.x 
	&& posClic.y >= position.y && posClic.y <= position.y + sizeButton.y){
		activated = !activated;
	}
	
	if(stay_activated) rectangle.setFillColor(isUsed);
	else 		       rectangle.setFillColor(notUsed);
	
	f.draw(rectangle);
	if(sprite) f.draw(*sprite);
	
}
