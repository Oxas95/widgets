#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "fenetre.hpp"
#include "widgetBox/buttonRect.hpp"
#include "widgetBox/buttonCircle.hpp"
#include "widgetBox/textArea.hpp"
#include "widgetBox/radioButton.hpp"
#include "managerGUI.hpp"
#include "widgetBox/radioList.hpp"
#include "widgetBox/radioBox.hpp"

using namespace std;

int main(){
	Fenetre f;
	f.resize(3);
	
	RadioBox v(f.getWindow());
	v.setPosition(10, 130);
	v.sizeButton.x = 45;
	v.sizeButton.y = 30;
	v.changeIfHover = false;
	v.setText(Off, "test", v.sizeButton.y - 15 , sf::Color::Black);
	v.moveTextInCenter(Off,true,true);
	v.text[On] = v.text[Off];
	
	RadioButton rb(f.getWindow());
	rb.setPosition(10,10);
	rb.setRadius(15);
	rb.changeIfHover = true;
	rb.setText(Off, "test du text 1", rb.getRadius() * 2 , sf::Color::Black);
	rb.moveTextInCenter(Off,false,true);
	rb.moveTextLeft(Off);
	rb.text[Off].setPosition(rb.text[Off].getPosition().x + rb.getRadius() * 3 + rb.getBorderSize() * 2, rb.text[Off].getPosition().y);
	rb.text[On] = rb.text[Off];
	
	RadioButton rb2(f.getWindow());
	rb2.setPosition(10, rb.getSize() + 20);
	rb2.setRadius(15);
	rb2.changeIfHover = true;
	rb2.setText(Off, "test du text 2", rb.getRadius() * 2 , sf::Color::Black);
	rb2.moveTextInCenter(Off,false,true);
	rb2.moveTextLeft(Off);
	rb2.text[Off].setPosition(rb2.text[Off].getPosition().x + rb2.getRadius() * 3 + rb2.getBorderSize() * 2, rb2.text[Off].getPosition().y);
	rb2.text[On] = rb2.text[Off];
	
	RadioButton rb3(f.getWindow());
	rb3.setPosition(10,30 + rb.getSize() + rb2.getSize());
	rb3.setRadius(15);
	rb3.changeIfHover = true;
	rb3.setText(Off, "test du text 3", rb.getRadius() * 2 , sf::Color::Black);
	rb3.moveTextInCenter(Off,false,true);
	rb3.moveTextLeft(Off);
	rb3.text[Off].setPosition(rb3.text[Off].getPosition().x + rb3.getRadius() * 3 + rb3.getBorderSize() * 2, rb3.text[Off].getPosition().y);
	rb3.text[On] = rb3.text[Off];
	
	RadioList rl(f.getWindow());
	rl.addWidget(&rb);
	rl.addWidget(&rb2);
	rl.addWidget(&rb3);
	
	ManagerGUI mg(f.getWindow());
	mg.addWidget(&rl);
	mg.addWidget(&v);
	
	while(f.isOpen()){
		f.clear(sf::Color::White);
		mg.useWidgets();
		f.display();
		//if(rb.isPushed()) f.close();
	}
	
	//cout << b2.text[Off].getFont()->getInfo().family.c_str() << endl;
	cout << rb.getSize() << endl;
	
	exit(0);
}
