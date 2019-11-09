#include "button.hpp"

Button::Button(Fenetre& f) : Widget(f), rectangle(sf::Vector2f(0,0)) {
	type = button;
	sizeButton.x = 0;
	sizeButton.y = 0;
	stay_activated = true;
	activated = false;
	pushed = false;
}

Button::~Button() {
	
}

void Button::eventNdraw(sf::Vector2i& posClic){
	
	rectangle.setSize(sf::Vector2f(sizeButton.x * 1.f, sizeButton.y * 1.f));
	rectangle.setPosition(sf::Vector2f(position.x, position.y));
	
	if(stay_activated == false) activated = false;
	
	if(posClic.x >= position.x && posClic.x <= position.x + sizeButton.x 
	&& posClic.y >= position.y && posClic.y <= position.y + sizeButton.y){
		activated = !activated;
		pushed = true;
		posClic.x = posClic.y = -10;
	}
	else if(posClic.x != -10 && posClic.y != -10) pushed = false;
	
	Byte usage = ((activated)? un : zero);
	rectangle.setFillColor(background[usage]);
	rectangle.setOutlineColor(borderColor[usage]);
	rectangle.setOutlineThickness(borderSize[usage]);
	
	
	f.draw(rectangle);
	if(sprite[usage]) f.draw(*sprite[usage]);
	if(sizeText[usage] > 0) f.write(text[usage].c_str(), sizeText[usage], textColor[usage], textPosition[usage].x, textPosition[usage].y);
}

bool Button::isActivated(){
	return activated;
}

bool Button::isPushed(){
	return pushed;
}
