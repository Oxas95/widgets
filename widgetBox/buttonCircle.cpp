#include "buttonCircle.hpp"

ButtonCircle::ButtonCircle(sf::RenderWindow& f) : WidgetBox(f), rectangle(sf::Vector2f(0,0)) {
	boxType = buttonCircle;
	sizeButton[whenNotUsed] = 0;
	sizeButton[whenUsed] = 0;
	stay_activated = true;
	activated = false;
	pushed = false;
	includeBorderInEvent = false;
}

ButtonCircle::~ButtonCircle() {
	printf("button deleted\n");
}

void ButtonCircle::moveTextTop(Byte usage){
	int y = getHeightText(usage);
	int decalageY = text[usage].getCharacterSize() - y;
	
	text[ByteToInt(usage)].setPosition(text[ByteToInt(usage)].getPosition().x , (position[usage].y - decalageY));
}

void ButtonCircle::moveTextBottom(Byte usage){
	int y = getHeightText(usage);
	int decalageY = text[usage].getCharacterSize() - y;
	
	text[ByteToInt(usage)].setPosition(text[ByteToInt(usage)].getPosition().x , (position[usage].y - decalageY) + (sizeButton.y - y));
}

void ButtonCircle::moveTextLeft(Byte usage){
	int x = getWidthText(usage);
	text[ByteToInt(usage)].setPosition(position[usage].x + (sizeButton * 2 - x) / 2 , text[ByteToInt(usage)].getPosition().y);
}

void ButtonCircle::moveTextRight(Byte usage){
	int x = getWidthText(usage);
	text[ByteToInt(usage)].setPosition(position[usage].x + (sizeButton * 2 - x), text[ByteToInt(usage)].getPosition().y);
}

void ButtonCircle::moveTextInCenter(Byte usage, bool on_X, bool on_Y){
	int x = getWidthText(usage);
	int y = getHeightText(usage);
	int decalageY = text[usage].getCharacterSize() - y;
	
	if(on_X) x = position[usage].x + (sizeButton[usage] * 2 - x) / 2;
	else x = text[ByteToInt(usage)].getPosition().x;
	
	if(on_Y) y = (position[usage].y - decalageY) + (sizeButton[usage] * 2 - y) / 2;
	else y = text[ByteToInt(usage)].getPosition().y;
	
	text[ByteToInt(usage)].setPosition(x,y);
}

void ButtonCircle::eventNdraw(sf::Vector2i& posClic){
	if(stay_activated == false) activated = false;
	Byte usage = ((activated)? un : zero);
	if(includeBorderInEvent) sizeButton[usage] += borderSize[usage];
	
	if((position[usage].x - posClic.x) * (position[usage].x - posClic.x) + (position[usage].y - posClic.y) * (position[usage].y - posClic.y) <= sizeButton[usage] * sizeButton[usage]){
		activated = !activated;
		pushed = true;
		posClic.x = posClic.y = -10;
	}
	else if(posClic.x != -10 && posClic.y != -10) pushed = false;
	
	if(includeBorderInEvent) sizeButton[usage] -= borderSize[usage];
	usage = ((activated)? un : zero);
	if(includeBorderInEvent) sizeButton[usage] += borderSize[usage];
	
	circle.setFillColor(background[usage]);
	circle.setOutlineColor(borderColor[usage]);
	circle.setOutlineThickness(borderSize[usage]);
	circle.setSize(sizeButton[usage] * 2));
	circle.setPosition(sf::Vector2f(position[usage].x, position[usage].y));
	
	f.draw(circle);
	if(sprite[usage]) f.draw(*sprite[usage]);
	if(text[usage].getCharacterSize() > 0) f.draw(text[usage]);
	
	if(includeBorderInEvent) sizeButton[usage] -= borderSize[usage];
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
