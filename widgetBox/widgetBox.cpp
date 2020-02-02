#include "widgetBox.hpp"
#include <iostream>
#include <string>

using namespace std;

const char* parseString(widgetBoxType w){
	string s;
	switch(w){
		case buttonRect 	: 	s = "buttonRect"; 		break;
		case buttonCircle 	: 	s = "buttonCircle";		break;
		case textArea 		: 	s = "textArea";			break;
		case radioButton 	: 	s = "radioButton";		break;
		case radioBox 		: 	s = "radioBox";			break;
		default 			: 	s = "undefined";		break;
	}
	return s.c_str();
}

WidgetBox::WidgetBox(sf::RenderWindow& f) : Widget(f) {
	sprite[Off] = NULL;
	sprite[On] = NULL;
	setText(Off, "", 0, sf::Color::Black, position[Off], "ttf/F25_Bank_Printer.ttf");
	setText(On, "", 0, sf::Color::Black, position[On], "ttf/F25_Bank_Printer.ttf");
	for (int i = 0; i < 2; i++){
		borderColor[i] = sf::Color::Black;
		borderSize[i] = 1;
		position[i].x = position[i].y = -1;
	}
	background[Off] = sf::Color(120,120,120);
	background[On] = sf::Color(180,180,180);
	changeIfHover = false;
	includeBorderInEvent = true;
}

WidgetBox::~WidgetBox() {
	if(sprite[Off]) delete sprite[Off];
	if(sprite[On]) delete sprite[On];
	printf("widgetBox deleted\n");
}

void WidgetBox::setText(widgetStatus usage, const char* str, int sizeText, sf::Color textColor, sf::Vector2i textPosition, const char* ttfPath){
	setText(usage, str, sizeText, textColor, textPosition);
	setText(usage,ttfPath);
}

void WidgetBox::setText(widgetStatus usage, const char* str, int sizeText, sf::Color textColor, sf::Vector2i textPosition) {
	setText(usage, str, sizeText, textColor);
	text[usage].setPosition(textPosition.x, textPosition.y);
}

void WidgetBox::setText(widgetStatus usage, const char* str, int sizeText, sf::Color textColor) {
	text[usage].setString(str);
	text[usage].setCharacterSize(sizeText);
	text[usage].setFillColor(textColor);
}

void WidgetBox::setText(widgetStatus usage, const char* ttfPath){
	if (font[usage].loadFromFile(ttfPath)) text[usage].setFont(font[usage]);
}

int WidgetBox::getWidthText(widgetStatus usage){
	sf::FloatRect fr = text[usage].getLocalBounds();
	float largeurTexte = fr.width;
	return (int) largeurTexte;
}

int WidgetBox::getHeightText(widgetStatus usage){
	int characterSize = text[usage].getCharacterSize();
	std::string String = text[usage].getString().toAnsiString();
	bool bold = (text[usage].getStyle() & sf::Text::Bold);
	int MaxHeight = 0;

	for (unsigned int i = 0; i < text[usage].getString().getSize(); i++){
		char c = String.at(i);
		const sf::Glyph& currentGlyph = font[usage].getGlyph(c, characterSize, bold);
		int Height = currentGlyph.bounds.height;
		if (MaxHeight < Height) MaxHeight = Height;
	}
	return MaxHeight;
}

void WidgetBox::loadImage(widgetStatus usage, const char* path) {
	if(!path)
		if(sprite[usage]) delete sprite[usage], sprite[usage] = NULL;
	
	if(texture[usage].loadFromFile(path)) {
		if(sprite[usage]) delete sprite[usage];
		sprite[usage] = new sf::Sprite();
		sprite[usage]->setTexture(texture[usage]);
	}
}

sf::Vector2i WidgetBox::getPosition(widgetStatus w){
	return position[w];
}

void WidgetBox::setPosition(widgetStatus w, int x, int y){
	position[w].x = x;
	position[w].y = y;
}

int WidgetBox::getBorderSize(widgetStatus w){
	return borderSize[w];
}

void WidgetBox::setBorderSize(widgetStatus w, int i){
	borderSize[w] = i;
}

widgetType WidgetBox::getWidgetType() {
	return widgetBox;
}
