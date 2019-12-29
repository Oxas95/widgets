#include "buttonCircle.hpp"

ButtonCircle::ButtonCircle(sf::RenderWindow& f) : WidgetBox(f), circle() {
	boxType = buttonCircle;
	sizeButton[Off] = 0;
	sizeButton[On] = 0;
	stay_activated = true;
	activated = false;
	pushed = false;
}

ButtonCircle::~ButtonCircle() {
	printf("button deleted\n");
}

void ButtonCircle::moveTextTop(widgetStatus usage){
	int y = getHeightText(usage);
	int decalageY = text[usage].getCharacterSize() - y;
	
	text[usage].setPosition(text[usage].getPosition().x , (position[usage].y - decalageY));
}

void ButtonCircle::moveTextBottom(widgetStatus usage){
	int y = getHeightText(usage);
	int decalageY = text[usage].getCharacterSize() - y;
	
	text[usage].setPosition(text[usage].getPosition().x , (position[usage].y - decalageY) + (sizeButton[usage] * 2 - y));
}

void ButtonCircle::moveTextLeft(widgetStatus usage){
	int x = getWidthText(usage);
	text[usage].setPosition(position[usage].x + (sizeButton[usage] * 2 - x) / 2 , text[usage].getPosition().y);
}

void ButtonCircle::moveTextRight(widgetStatus usage){
	int x = getWidthText(usage);
	text[usage].setPosition(position[usage].x + (sizeButton[usage] * 2 - x), text[usage].getPosition().y);
}

void ButtonCircle::moveTextInCenter(widgetStatus usage, bool on_X, bool on_Y){
	int x = getWidthText(usage);
	int y = getHeightText(usage);
	int decalageY = text[usage].getCharacterSize() - y;
	
	if(on_X) x = position[usage].x + (sizeButton[usage] * 2 - x) / 2;
	else x = text[usage].getPosition().x;
	
	if(on_Y) y = (position[usage].y - decalageY) + (sizeButton[usage] * 2 - y) / 2;
	else y = text[usage].getPosition().y;
	
	text[usage].setPosition(x,y);
}

void ButtonCircle::eventNdraw(sf::Vector2i& posClic){
	if(stay_activated == false) activated = false;
	widgetStatus usage = ((activated)? On : Off);
	
	sf::Vector2i centre = position[usage];
	centre.x += sizeButton[usage];
	centre.y += sizeButton[usage];
	
	if((centre.x - posClic.x) * (centre.x - posClic.x) + (centre.y - posClic.y) * (centre.y - posClic.y) <= sizeButton[usage] * sizeButton[usage]){
		activated = !activated;
		pushed = true;
		posClic.x = posClic.y = -10;
	}
	else if(posClic.x != -10 && posClic.y != -10) pushed = false;
	
	usage = ((activated)? On : Off);
	
	centre = position[usage];
	centre.x += sizeButton[usage];
	centre.y += sizeButton[usage];
	
	sf::Vector2i mousePos = sf::Mouse::getPosition(f);
	
	bool hover = false;
	if(changeIfHover){
		if((centre.x - mousePos.x) * (centre.x - mousePos.x) + (centre.y - mousePos.y) * (centre.y - mousePos.y) <= sizeButton[usage] * sizeButton[usage]){
			hover = true;
		}
	}
	
	sf::Color backgroundHoverColor = background[usage], borderHoverColor = borderColor[usage];
	if(hover){
		if(backgroundHoverColor.r + 20 < 256) backgroundHoverColor.r += 20; else backgroundHoverColor.r = 255;
		if(backgroundHoverColor.g + 20 < 256) backgroundHoverColor.g += 20; else backgroundHoverColor.g = 255;
		if(backgroundHoverColor.b + 20 < 256) backgroundHoverColor.b += 20; else backgroundHoverColor.b = 255;
		if(borderHoverColor.r + 20 < 256) borderHoverColor.r += 20; else borderHoverColor.r = 255;
		if(borderHoverColor.g + 20 < 256) borderHoverColor.g += 20; else borderHoverColor.g = 255;
		if(borderHoverColor.b + 20 < 256) borderHoverColor.b += 20; else borderHoverColor.b = 255;
	}
	
	circle.setFillColor(backgroundHoverColor);
	circle.setOutlineColor(borderHoverColor);
	circle.setOutlineThickness(borderSize[usage]);
	circle.setRadius(sizeButton[usage]);
	circle.setPosition(sf::Vector2f(position[usage].x, position[usage].y));
	
	f.draw(circle);
	if(sprite[usage]) f.draw(*sprite[usage]);
	if(text[usage].getCharacterSize() > 0) f.draw(text[usage]);
}

bool ButtonCircle::isActivated(){
	return activated;
}

bool ButtonCircle::isPushed(){
	return pushed;
}

widgetBoxType ButtonCircle::getWidgetBoxType(){
	return boxType;
}
