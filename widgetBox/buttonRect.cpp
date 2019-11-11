#include "buttonRect.hpp"

ButtonRect::ButtonRect(sf::RenderWindow& f) : WidgetBox(f), rectangle(sf::Vector2f(0,0)) {
	boxType = buttonRect;
	sizeButton[Off].x = sizeButton[Off].y = 0;
	sizeButton[On].x = sizeButton[On].y = 0;
	stay_activated = true;
	activated = false;
	pushed = false;
}

ButtonRect::~ButtonRect() {
	printf("button deleted\n");
}

void ButtonRect::moveTextTop(widgetStatus usage){
	int y = getHeightText(usage);
	int decalageY = text[usage].getCharacterSize() - y;
	
	text[usage].setPosition(text[usage].getPosition().x , (position[usage].y - decalageY));
}

void ButtonRect::moveTextBottom(widgetStatus usage){
	int y = getHeightText(usage);
	int decalageY = text[usage].getCharacterSize() - y;
	
	text[usage].setPosition(text[usage].getPosition().x , (position[usage].y - decalageY) + (sizeButton[usage].y - y));
}

void ButtonRect::moveTextLeft(widgetStatus usage){
	int x = getWidthText(usage);
	text[usage].setPosition(position[usage].x + (sizeButton[usage].x - x) / 2 , text[usage].getPosition().y);
}

void ButtonRect::moveTextRight(widgetStatus usage){
	int x = getWidthText(usage);
	text[usage].setPosition(position[usage].x + (sizeButton[usage].x - x), text[usage].getPosition().y);
}

void ButtonRect::moveTextInCenter(widgetStatus usage, bool on_X, bool on_Y){
	int x = getWidthText(usage);
	int y = getHeightText(usage);
	int decalageY = text[usage].getCharacterSize() - y;
	
	if(on_X) x = position[usage].x + (sizeButton[usage].x - x) / 2;
	else x = text[usage].getPosition().x;
	
	if(on_Y) y = (position[usage].y - decalageY) + (sizeButton[usage].y - y) / 2;
	else y = text[usage].getPosition().y;
	
	text[usage].setPosition(x,y);
}

void ButtonRect::eventNdraw(sf::Vector2i& posClic){
	if(stay_activated == false) activated = false;
	widgetStatus usage = ((activated)? On : Off);
	
	if(posClic.x >= position[usage].x && posClic.x <= position[usage].x + sizeButton[usage].x 
	&& posClic.y >= position[usage].y && posClic.y <= position[usage].y + sizeButton[usage].y){
		activated = !activated;
		pushed = true;
		posClic.x = posClic.y = -10;
	}
	else if(posClic.x != -10 && posClic.y != -10) pushed = false;
	
	usage = ((activated)? On : Off);
	
	sf::Vector2i mousePos = sf::Mouse::getPosition(f);
	
	widgetStatus hover = usage;
	if(changeIfHover){
		if(mousePos.x >= position[usage].x && mousePos.x <= position[usage].x + sizeButton[usage].x 
		&& mousePos.y >= position[usage].y && mousePos.y <= position[usage].y + sizeButton[usage].y){
			hover = Hover;
		}
	}
	rectangle.setSize(sf::Vector2f(sizeButton[usage].x * 1.f, sizeButton[usage].y * 1.f));
	rectangle.setPosition(sf::Vector2f(position[usage].x, position[usage].y));
	rectangle.setFillColor(background[hover]);
	rectangle.setOutlineColor(borderColor[hover]);
	rectangle.setOutlineThickness(borderSize[usage]);
	
	f.draw(rectangle);
	if(sprite[usage]) f.draw(*sprite[usage]);
	if(text[usage].getCharacterSize() > 0) f.draw(text[usage]);
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
