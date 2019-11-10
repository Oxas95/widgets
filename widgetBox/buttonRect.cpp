#include "buttonRect.hpp"

ButtonRect::ButtonRect(sf::RenderWindow& f) : WidgetBox(f), rectangle(sf::Vector2f(0,0)) {
	boxType = buttonRect;
	sizeButton[whenNotUsed].x = sizeButton[whenNotUsed].y = 0;
	sizeButton[whenUsed].x = sizeButton[whenUsed].y = 0;
	stay_activated = true;
	activated = false;
	pushed = false;
	includeBorderInEvent = false;
}

ButtonRect::~ButtonRect() {
	printf("button deleted\n");
}

void ButtonRect::moveTextTop(Byte usage){
	int y = getHeightText(usage);
	int decalageY = text[usage].getCharacterSize() - y;
	
	text[ByteToInt(usage)].setPosition(text[ByteToInt(usage)].getPosition().x , (position[usage].y - decalageY));
}

void ButtonRect::moveTextBottom(Byte usage){
	int y = getHeightText(usage);
	int decalageY = text[usage].getCharacterSize() - y;
	
	text[ByteToInt(usage)].setPosition(text[ByteToInt(usage)].getPosition().x , (position[usage].y - decalageY) + (sizeButton[usage].y - y));
}

void ButtonRect::moveTextLeft(Byte usage){
	int x = getWidthText(usage);
	text[ByteToInt(usage)].setPosition(position[usage].x + (sizeButton[usage].x - x) / 2 , text[ByteToInt(usage)].getPosition().y);
}

void ButtonRect::moveTextRight(Byte usage){
	int x = getWidthText(usage);
	text[ByteToInt(usage)].setPosition(position[usage].x + (sizeButton[usage].x - x), text[ByteToInt(usage)].getPosition().y);
}

void ButtonRect::moveTextInCenter(Byte usage, bool on_X, bool on_Y){
	int x = getWidthText(usage);
	int y = getHeightText(usage);
	int decalageY = text[usage].getCharacterSize() - y;
	
	if(on_X) x = position[usage].x + (sizeButton[usage].x - x) / 2;
	else x = text[ByteToInt(usage)].getPosition().x;
	
	if(on_Y) y = (position[usage].y - decalageY) + (sizeButton[usage].y - y) / 2;
	else y = text[ByteToInt(usage)].getPosition().y;
	
	text[ByteToInt(usage)].setPosition(x,y);
}

void ButtonRect::eventNdraw(sf::Vector2i& posClic){
	if(stay_activated == false) activated = false;
	Byte usage = ((activated)? un : zero);
	if(includeBorderInEvent) sizeButton[usage].x += borderSize[usage], sizeButton[usage].y += borderSize[usage];
	
	
	if(posClic.x >= position[usage].x && posClic.x <= position[usage].x + sizeButton[usage].x 
	&& posClic.y >= position[usage].y && posClic.y <= position[usage].y + sizeButton[usage].y){
		activated = !activated;
		pushed = true;
		posClic.x = posClic.y = -10;
	}
	else if(posClic.x != -10 && posClic.y != -10) pushed = false;
	
	if(includeBorderInEvent) sizeButton[usage].x -= borderSize[usage], sizeButton[usage].y -= borderSize[usage];
	usage = ((activated)? un : zero);
	if(includeBorderInEvent) sizeButton[usage].x += borderSize[usage], sizeButton[usage].y += borderSize[usage];
	
	rectangle.setSize(sf::Vector2f(sizeButton[usage].x * 1.f, sizeButton[usage].y * 1.f));
	rectangle.setPosition(sf::Vector2f(position[usage].x, position[usage].y));
	rectangle.setFillColor(background[usage]);
	rectangle.setOutlineColor(borderColor[usage]);
	rectangle.setOutlineThickness(borderSize[usage]);
	
	f.draw(rectangle);
	if(sprite[usage]) f.draw(*sprite[usage]);
	if(text[usage].getCharacterSize() > 0) f.draw(text[usage]);
	
	if(includeBorderInEvent) sizeButton[usage].x -= borderSize[usage], sizeButton[usage].y -= borderSize[usage];
}

bool ButtonRect::isActivated(){
	return activated;
}

bool ButtonRect::isPushed(){
	return pushed;
}

widgetBoxType ButtonRect::getWidgetBoxType(){
	return boxType;
}
