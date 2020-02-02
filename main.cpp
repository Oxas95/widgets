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

void on(Fenetre& f, ManagerGUI& mg){
	while(f.isOpen()){
		f.clear(sf::Color::White);
		mg.useWidgets();
		f.display();
	}
}

void text_button_test(){
	Fenetre f;
	f.resize(3);
	
	ButtonRect b2(f.getWindow());
	b2.sizeButton[Off].x = 300;	b2.sizeButton[Off].y = 200;
	b2.sizeButton[On].x = 300;	b2.sizeButton[On].y = 200;
	b2.setPosition(Off, f.getLargeur() - b2.sizeButton[Off].x, 0);
	b2.setPosition(On, f.getLargeur() - b2.sizeButton[Off].x, 0);
	b2.background[Off] = sf::Color::Red;
	b2.background[On] = sf::Color::Red;
	b2.stay_activated = false;
	b2.setText(Off,"Quitter",40,sf::Color::Black);
	b2.moveTextInCenter(Off,true,true);
	
	TextArea ta(f.getWindow());
	
	ta.setText(Off,"Bonjour\nje suis etudiant en fac\net je cherche un cahier perdu",20,sf::Color::Red,sf::Vector2i(20,150));
	
	ManagerGUI mg(f.getWindow());
	
	mg.addWidget(&b2);
	mg.addWidget(&ta);
	
	on(f,mg);
}

void buttonRect_buttonCircle_test(){
	Fenetre f;
	f.resize(3);
	
	ButtonRect b(f.getWindow());
	b.setPosition(Off, 10, 10);
	b.setPosition(On, 20, 20);
	b.sizeButton[Off].x = 100;	b.sizeButton[Off].y = 100;
	b.sizeButton[On].x = 80;	b.sizeButton[On].y = 80;
	b.setBorderSize(Off,10); b.setBorderSize(On,20);
	b.background[Off] = sf::Color::White;
	b.background[On] = sf::Color::White;
	b.setText(Off,"X",50,sf::Color::Black);
	b.setText(On,"V",40,sf::Color::Black);
	b.moveTextInCenter(Off,true,true);
	b.moveTextInCenter(On,true,true);
	b.includeBorderInEvent = true;
	b.changeIfHover = true;
	
	ButtonRect b2(f.getWindow());
	b2.sizeButton[Off].x = 300;	b2.sizeButton[Off].y = 200;
	b2.sizeButton[On].x = 300;	b2.sizeButton[On].y = 200;
	b2.setPosition(Off, f.getLargeur() - b2.sizeButton[Off].x, 0);
	b2.setPosition(On, f.getLargeur() - b2.sizeButton[Off].x, 0);
	b2.background[Off] = sf::Color::Red;
	b2.background[On] = sf::Color::Red;
	b2.stay_activated = false;
	b2.setText(Off,"Quitter",40,sf::Color::Black);
	b2.moveTextInCenter(Off,true,true);
	
	ButtonCircle bc(f.getWindow());
	bc.sizeButton[Off] = bc.sizeButton[On] = 40;
	bc.setPosition(Off,250,250);
	bc.setPosition(On,250,250);
	bc.background[Off] = bc.background[On];
	bc.borderColor[Off] = sf::Color::Blue;
	bc.borderColor[On] = sf::Color::Cyan;
	bc.setBorderSize(Off,20); bc.setBorderSize(On,20);
	bc.changeIfHover = true;
	bc.setText(Off,"X",50,sf::Color::Black);
	bc.setText(On,"V",40,sf::Color::Black);
	bc.moveTextInCenter(Off,true,true);
	bc.moveTextInCenter(On,true,true);
	
	ManagerGUI mg(f.getWindow());
	
	mg.addWidget(&b);
	mg.addWidget(&b2);
	mg.addWidget(&bc);
	
	on(f,mg);
}

void radiolist_radiobox_test(){
	Fenetre f;
	f.resize(3);
	ManagerGUI mg(f.getWindow());
	
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
	
	mg.addWidget(&rl);
	mg.addWidget(&v);
	
	on(f,mg);
}

int main(){
	//cout << b2.text[Off].getFont()->getInfo().family.c_str() << endl;
	//cout << rb.getSize() << endl;
	
	radiolist_radiobox_test();
	buttonRect_buttonCircle_test();
	text_button_test();
	
	exit(0);
}
