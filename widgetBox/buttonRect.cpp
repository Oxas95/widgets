#include "buttonRect.hpp"

ButtonRect::ButtonRect(sf::RenderWindow& f) : WidgetBox(f), rectangle(sf::Vector2f(0,0)) {
	sizeButton[Off].x = sizeButton[Off].y = 0;
	sizeButton[On].x = sizeButton[On].y = 0;
	stay_activated = true;
	activated = false;
	pushed = false;
}

ButtonRect::~ButtonRect() {
	printf("buttonRect deleted\n");
}

void ButtonRect::moveTextTop(widgetStatus usage){
	int y = getHeightText(usage);
	int decalageY = text[usage].getCharacterSize() - y;
	
	text[usage].setPosition(text[usage].getPosition().x , position[usage].y - decalageY);
}

void ButtonRect::moveTextBottom(widgetStatus usage){
	int y = getHeightText(usage);
	int decalageY = text[usage].getCharacterSize() - y;
	
	text[usage].setPosition(text[usage].getPosition().x , position[usage].y - decalageY + sizeButton[usage].y + borderSize[usage] * 2 - y);
}

void ButtonRect::moveTextLeft(widgetStatus usage){
	text[usage].setPosition(position[usage].x, text[usage].getPosition().y);
}

void ButtonRect::moveTextRight(widgetStatus usage){
	int x = getWidthText(usage);
	text[usage].setPosition(position[usage].x + sizeButton[usage].x + borderSize[usage] * 2 - x, text[usage].getPosition().y);
}

void ButtonRect::moveTextInCenter(widgetStatus usage, bool on_X, bool on_Y){
	int x = getWidthText(usage);
	int y = getHeightText(usage);
	int decalageY = text[usage].getCharacterSize() - y;
	
	if(on_X) x = position[usage].x + (sizeButton[usage].x + borderSize[usage] * 2 - x) / 2;
	else x = text[usage].getPosition().x;
	
	if(on_Y) y = (position[usage].y - decalageY) + (sizeButton[usage].y + borderSize[usage] * 2 - y) / 2;
	else y = text[usage].getPosition().y ;
	
	text[usage].setPosition(x, y);
}

void ButtonRect::eventNdraw(sf::Vector2i& posClic){
	if(stay_activated == false) activated = false;
	widgetStatus usage = ((activated)? On : Off);
	
	int size[2] = {sizeButton[usage].x,sizeButton[usage].y};
	sf::Vector2i pos(position[usage].x + borderSize[usage],position[usage].y + borderSize[usage]);
	if(includeBorderInEvent){
		size[0] += borderSize[usage] * 2;
		size[1] += borderSize[usage] * 2;
		pos.x -= borderSize[usage];
		pos.y -= borderSize[usage];
	}
	
	if(posClic.x >= pos.x && posClic.x <= pos.x + size[0] 
	&& posClic.y >= pos.y && posClic.y <= pos.y + size[1]){
		activated = !activated;
		pushed = true;
		posClic.x = posClic.y = -getID() * 100;
	}
	else if(posClic.x != -getID() * 100 && posClic.y != -getID() * 100) pushed = false;
	
	usage = ((activated)? On : Off);
	
	sf::Vector2i mousePos = sf::Mouse::getPosition(f);
	
	size[0] = sizeButton[usage].x;
	size[1] = sizeButton[usage].y;
	pos.x = position[usage].x + borderSize[usage];
	pos.y = position[usage].y + borderSize[usage];
	if(includeBorderInEvent){
		size[0] += borderSize[usage] * 2;
		size[1] += borderSize[usage] * 2;
		pos.x -= borderSize[usage];
		pos.y -= borderSize[usage];
	}
	
	bool hover = false;
	if(changeIfHover){
		if(mousePos.x >= pos.x && mousePos.x <= pos.x + size[0] 
		&& mousePos.y >= pos.y && mousePos.y <= pos.y + size[1]){
			hover = true;
		}
	}
	sf::Color backgroundHoverColor = background[usage], borderHoverColor = borderColor[usage];
	if(hover){
		if(backgroundHoverColor.r + 20 < 256) backgroundHoverColor.r += 20; else backgroundHoverColor.r -= 20;
		if(backgroundHoverColor.g + 20 < 256) backgroundHoverColor.g += 20; else backgroundHoverColor.g -= 20;
		if(backgroundHoverColor.b + 20 < 256) backgroundHoverColor.b += 20; else backgroundHoverColor.b -= 20;
		if(borderHoverColor.r + 20 < 256) borderHoverColor.r += 20; else borderHoverColor.r = 255;
		if(borderHoverColor.g + 20 < 256) borderHoverColor.g += 20; else borderHoverColor.g = 255;
		if(borderHoverColor.b + 20 < 256) borderHoverColor.b += 20; else borderHoverColor.b = 255;
	}
	
	rectangle.setSize(sf::Vector2f(sizeButton[usage].x * 1.f, sizeButton[usage].y * 1.f));
	rectangle.setPosition(sf::Vector2f(position[usage].x + borderSize[usage], position[usage].y + borderSize[usage]));
	rectangle.setFillColor(backgroundHoverColor);
	rectangle.setOutlineColor(borderHoverColor);
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
	return buttonRect;
}
