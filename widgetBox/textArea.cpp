#include "textArea.hpp"
#include <queue>

using namespace std;

TextArea::TextArea(sf::RenderWindow& f) : WidgetBox(f) {
	
}

TextArea::~TextArea(){
	
}

void TextArea::moveTextTop(){
	int y = getHeightText(Off);
	int decalageY = text[Off].getCharacterSize() - y;
	
	text[Off].setPosition(text[Off].getPosition().x , position[Off].y - decalageY + 1);
}

void TextArea::moveTextBottom(){
	int y = getHeightText(Off);
	int decalageY = text[Off].getCharacterSize() - y;
	
	text[Off].setPosition(text[Off].getPosition().x , position[Off].y - decalageY + size.y + borderSize[Off] - y + 1);
}

void TextArea::moveTextLeft(){
	text[Off].setPosition(position[Off].x, text[Off].getPosition().y);
}

void TextArea::moveTextRight(){
	int x = getWidthText(Off);
	text[Off].setPosition(position[Off].x + size.x + borderSize[Off] - x - 1, text[Off].getPosition().y);
}

void TextArea::moveTextInCenter(bool on_X, bool on_Y){
	int x = getWidthText(Off);
	int y = getHeightText(Off);
	int decalageY = text[Off].getCharacterSize() - y;
	
	if(on_X) x = position[Off].x + (size.x + borderSize[Off] + 1 - x) / 2;
	else x = text[Off].getPosition().x;
	
	if(on_Y) y = (position[Off].y - decalageY) + (size.y + borderSize[Off] + 1 - y) / 2;
	else y = text[Off].getPosition().y ;
	
	text[Off].setPosition(x, y);
}

void TextArea::drawText(){
	if(text[Off].getCharacterSize() > 0) {
		
		string s = text[Off].getString().toAnsiString();
		int posY = (int) text[Off].getPosition().y;
		int line = 1;
		string sub = "";
		unsigned int i;
		for(i = 0; i < s.length(); i++){
			if(s[i] == '\n'){
				text[Off].setString(sub.c_str());
				text[Off].setPosition(text[Off].getPosition().x, posY + (text[Off].getCharacterSize() * line) + ((int)(text[Off].getCharacterSize() / 4) * (line - 1)));
				f.draw(text[Off]);
				line++;
				sub = "";
			}
			else 
				sub = sub + s[i];
		}
		
		text[Off].setString(sub.c_str());
		text[Off].setPosition(text[Off].getPosition().x, posY + (text[Off].getCharacterSize() * line) + ((int)(text[Off].getCharacterSize() / 4) * (line - 1)));
		f.draw(text[Off]);
		
		text[Off].setPosition(text[Off].getPosition().x,posY);
		text[Off].setString(s.c_str());
	}
}

void TextArea::eventNdraw(sf::Vector2i& posClic){
	rectangle.setSize(sf::Vector2f(size.x * 1.f, size.y * 1.f));
	rectangle.setPosition(sf::Vector2f(position[Off].x + borderSize[Off], position[Off].y + borderSize[Off]));
	rectangle.setFillColor(background[Off]);
	rectangle.setOutlineColor(borderColor[Off]);
	rectangle.setOutlineThickness(borderSize[Off]);
	
	f.draw(rectangle);
	if(sprite[Off]) f.draw(*sprite[Off]);
	drawText();
	//f.draw(text[Off]);
}

widgetBoxType TextArea::getWidgetBoxType(){
	return textArea;
}
