#include "widget.hpp"

#define defaultColorNotUsed sf::Color(120,120,120)
#define defaultColorIsUsed sf::Color(140,140,140)

int Widget::nextID = 0;

Widget::Widget(Fenetre& _f) : f(_f), position(-1,-1) {
	ID = nextID++;
	notUsed = defaultColorNotUsed;
	isUsed = defaultColorIsUsed;
	sprite = NULL;
	borderColor = sf::Color::Black;
	text = "";
	sizeText = 0;
	textColor = sf::Color::Black;
	master = false;
}

Widget::~Widget() {
	
}

void Widget::setText(const char* str) {
	texte = str;
}

const char* Widget::getText() {
	return texte.c_str();
}

void Widget::loadImage(const char* path) {
	if(!path)
		if(sprite) delete sprite, sprite = NULL;
	
	if(texture.loadFromFile(path)) {
		if(sprite) delete sprite;
		sprite = new sf::Sprite();
		sprite->setTexture(texture);
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
