#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "fenetre.hpp"
#include "widgetBox/buttonRect.hpp"
#include "widgetBox/buttonCircle.hpp"
#include "managerGUI.hpp"

using namespace std;

int main(){
	Fenetre f;
	f.resize(3);
	
	ButtonRect b(f.getWindow());
	b.position[Off].x = 10;		b.position[Off].y = 10;
	b.position[On].x = 20;		b.position[On].y = 20;
	b.sizeButton[Off].x = 100;	b.sizeButton[Off].y = 100;
	b.sizeButton[On].x = 80;	b.sizeButton[On].y = 80;
	b.borderSize[Off] = b.borderSize[On] = 10;
	b.background[Off] = sf::Color::White;
	b.background[On] = sf::Color::White;
	b.setText(Off,"X",50,sf::Color::Black);
	b.setText(On,"V",40,sf::Color::Black);
	b.moveTextInCenter(Off,true,true);
	b.moveTextInCenter(On,true,true);
	b.changeIfHover = true;
	
	ButtonRect b2(f.getWindow());
	b2.sizeButton[Off].x = 300;	b2.sizeButton[Off].y = 200;
	b2.sizeButton[On].x = 300;	b2.sizeButton[On].y = 200;
	b2.position[Off].x = f.getLargeur() - b2.sizeButton[Off].x;
	b2.position[Off].y = 0;
	b2.position[On] = b2.position[Off];
	b2.background[Off] = sf::Color::Red;
	b2.background[On] = sf::Color::Red;
	b2.stay_activated = false;
	b2.setText(Off,"Quitter",40,sf::Color::Black);
	b2.moveTextInCenter(Off,true,true);
	
	ButtonCircle bc(f.getWindow());
	bc.sizeButton[Off] = bc.sizeButton[On] = 40;
	bc.position[Off].x = 250; bc.position[Off].y = 250;
	bc.position[On].x = 250; bc.position[On].y = 250;
	bc.background[Off] = bc.background[On];
	bc.borderColor[Off] = sf::Color::Blue;
	bc.borderColor[On] = sf::Color::Cyan;
	bc.borderSize[Off] = bc.borderSize[On] = 20;
	bc.changeIfHover = true;
	bc.setText(Off,"X",50,sf::Color::Black);
	bc.setText(On,"V",40,sf::Color::Black);
	bc.moveTextInCenter(Off,true,true);
	bc.moveTextInCenter(On,true,true);
	
	ManagerGUI mg(f.getWindow());
	
	mg.addWidget(&b);
	mg.addWidget(&b2);
	mg.addWidget(&bc);
	
	while(f.isOpen()){
		f.clear(sf::Color::White);
		mg.useWidgets();
		f.display();
		if(b2.isPushed()) f.close();
	}
	
	cout << b.text[Off].getFont()->getInfo().family.c_str() << endl;
	
	exit(0);
}
