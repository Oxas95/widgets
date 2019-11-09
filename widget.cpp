#include "widget.hpp"

#define defaultColorNotUsed sf::Color(120,120,120)
#define defaultColorIsUsed sf::Color(140,140,140)

int Widget::nextID = 0;

Widget::Widget(Fenetre& _f) : ID(nextID), f(_f), position(-1,-1) {
	nextID++;
	for (int i = 0; i < 2; i++){
		sprite[i] = NULL;
		borderColor[i] = sf::Color::Black;
		text[i] = "";
		sizeText[i] = 0;
		textColor[i] = sf::Color::Black;
		textPosition[i] = position;
		borderSize[i] = 1;
	}
	background[0] = defaultColorNotUsed;
	background[1] = defaultColorIsUsed;
	master = false;
}

Widget::~Widget() {
	if(sprite[0]) delete sprite[0];
	if(sprite[1]) delete sprite[1];
	printf("sprites button deleted\n");
}

void Widget::setText(Byte usage, const char* str, int sizeText, sf::Color textColor, sf::Vector2i textPosition) {
	text[usage] = str;
	this->sizeText[usage] = sizeText;
	this->textColor[usage] = textColor;
	this->textPosition[usage] = textPosition;
}

const char* Widget::getText(Byte usage) {
	return text[usage].c_str();
}

void Widget::loadImage(Byte usage, const char* path) {
	if(!path)
		if(sprite[usage]) delete sprite[usage], sprite[usage] = NULL;
	
	if(texture[usage].loadFromFile(path)) {
		if(sprite[usage]) delete sprite[usage];
		sprite[usage] = new sf::Sprite();
		sprite[usage]->setTexture(texture[usage]);
	}
}

widgetType Widget::getWidgetType() {
	return type;
}

int Widget::getID(){
	return ID;
}

bool Widget::isMaster(){
	return master;
}
