#include "textArea.hpp"
#include <queue>

using namespace std;

TextArea::TextArea(sf::RenderWindow& f) : WidgetBox(f) {
	
}

TextArea::~TextArea(){
	
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
	rectangle.setPosition(sf::Vector2f(position[Off].x, position[Off].y));
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
