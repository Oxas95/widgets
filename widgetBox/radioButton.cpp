#include "radioButton.hpp"

RadioButton::RadioButton(sf::RenderWindow& f) : WidgetBox(f) {
	boxType = radioButton;
	sizeButton = 0;
	stay_activated = true;
	activated = false;
	pushed = false;
	externCircle.setOutlineThickness(1);
	externCircle.setFillColor(sf::Color::Transparent);
	externBorderColor = sf::Color::Black;
	borderSize[Off] = borderSize[On] = 0;
	borderColor[Off] = borderColor[On] = sf::Color::Transparent;
	background[Off] = sf::Color::Transparent;
	background[On] = sf::Color::Blue;
}

RadioButton::~RadioButton(){
	printf("Radio Button deleted\n");
}

int RadioButton::getSize(){
	return sizeButton * 2 + borderSize[Off] * 2 + 2;
}

int RadioButton::getRadius(){
	return sizeButton;
}

void RadioButton::setRadius(int v){
	externCircle.setRadius(v);
	sizeButton = v * 2 / 3 - 1;
	borderSize[Off] = borderSize[On] = v / 3 + ((v % 3 > 0)? 1 : 0 );
}

void RadioButton::setPosition(widgetStatus w, int x, int y){
	externCircle.setPosition(x,y);
	position[Off].x = x;
	position[On].x = x;
	position[Off].y = y;
	position[On].y = y;
}

sf::Vector2i RadioButton::getPosition(widgetStatus w){
	return position[Off];
}

void RadioButton::setPosition(int x, int y){
	setPosition(Off,x,y);
}

sf::Vector2i RadioButton::getPosition(){
	return getPosition(Off);
}

void RadioButton::eventNdraw(sf::Vector2i& posClic){
	if(stay_activated == false) activated = false;
	widgetStatus usage = ((activated)? On : Off);
	
	sf::Vector2i centre = position[usage];
	centre.x += sizeButton + borderSize[usage] + 1;
	centre.y += sizeButton + borderSize[usage] + 1;
	
	int size = sizeButton;
	if(includeBorderInEvent) size += borderSize[usage];
	
	if((centre.x - posClic.x) * (centre.x - posClic.x) + (centre.y - posClic.y) * (centre.y - posClic.y) <= size * size){
		activated = !activated;
		pushed = true;
		posClic.x = posClic.y = -getID() * 100;
	}
	else if(posClic.x != -getID() * 100 && posClic.y != -getID() * 100) pushed = false;
	
	usage = ((activated)? On : Off);
	
	centre = position[usage];
	centre.x += sizeButton + borderSize[usage] + 1;
	centre.y += sizeButton + borderSize[usage] + 1;
	
	sf::Vector2i mousePos = sf::Mouse::getPosition(f);
	
	size = sizeButton;
	if(includeBorderInEvent) size += borderSize[usage];
	
	bool hover = false;
	if(changeIfHover){
		if((centre.x - mousePos.x) * (centre.x - mousePos.x) + (centre.y - mousePos.y) * (centre.y - mousePos.y) <= size * size){
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
	
	circle.setFillColor(backgroundHoverColor);
	circle.setOutlineColor(borderHoverColor);
	circle.setOutlineThickness(borderSize[usage]);
	circle.setRadius(sizeButton);
	circle.setPosition(sf::Vector2f(position[usage].x + borderSize[usage] + 1, position[usage].y + borderSize[usage] + 1));
	externCircle.setOutlineColor(externBorderColor);
	f.draw(circle);
	f.draw(externCircle);
	f.draw(text[Off]);
}

void RadioButton::moveTextTop(){
	int y = getHeightText(Off);
	int decalageY = text[Off].getCharacterSize() - y;
	
	text[Off].setPosition(text[Off].getPosition().x , position[Off].y - decalageY + 1);
}

void RadioButton::moveTextBottom(){
	int y = getHeightText(Off);
	int decalageY = text[Off].getCharacterSize() - y;
	
	text[Off].setPosition(text[Off].getPosition().x , position[Off].y - decalageY + sizeButton * 2 + borderSize[Off] * 2 - y + 1);
}

void RadioButton::moveTextLeft(){
	moveTextInCenter(true,false);
	text[Off].setPosition(position[Off].x, text[Off].getPosition().y);
}

void RadioButton::moveTextRight(){
	int x = getWidthText(Off);
	text[Off].setPosition(position[Off].x + sizeButton * 2 + borderSize[Off] * 2 - x - 1, text[Off].getPosition().y);
}

void RadioButton::moveTextInCenter(bool on_X, bool on_Y){
	int x = getWidthText(Off);
	int y = getHeightText(Off);
	int decalageY = text[Off].getCharacterSize() - y;
	
	if(on_X) x = position[Off].x + ((sizeButton + borderSize[Off] + 1) * 2 - x) / 2;
	else x = text[Off].getPosition().x;
	
	if(on_Y) y = (position[Off].y - decalageY) + ((sizeButton + borderSize[Off] + 1) * 2 - y) / 2;
	else y = text[Off].getPosition().y ;
	
	text[Off].setPosition(x, y);
}

widgetBoxType RadioButton::getWidgetBoxType(){
	return radioButton;
}

bool RadioButton::isPushed(){
	return pushed;
}

int RadioButton::getBorderSize(widgetStatus w){ return borderSize[Off];}
void RadioButton::setBorderSize(widgetStatus, int){}
int RadioButton::getBorderSize(){ return getBorderSize(Off);}
void RadioButton::setBorderSize(int){}
