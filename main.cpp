#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "fenetre.hpp"
#include "widgetBox/buttonRect.hpp"
#include "managerGUI.hpp"

int main(){
	Fenetre f;
	f.resize(3);
	
	ButtonRect b(f.getWindow());
	b.position[whenNotUsed].x = 10;		b.position[whenNotUsed].y = 10;
	b.position[whenUsed].x = 20;		b.position[whenUsed].y = 20;
	b.sizeButton[whenNotUsed].x = 100;	b.sizeButton[whenNotUsed].y = 100;
	b.sizeButton[whenUsed].x = 80;		b.sizeButton[whenUsed].y = 80;
	b.background[whenNotUsed] = sf::Color::White;
	b.background[whenUsed] = sf::Color::White;
	b.setText(zero,"X",50,sf::Color::Black);
	b.setText(un,"V",40,sf::Color::Black);
	b.moveTextInCenter(zero,true,true);
	b.moveTextInCenter(un,true,true);
	
	ButtonRect b2(f.getWindow());
	b2.sizeButton[whenNotUsed].x = 300;	b2.sizeButton[whenNotUsed].y = 200;
	b2.sizeButton[whenUsed].x = 300;	b2.sizeButton[whenUsed].y = 200;
	b2.position[whenNotUsed].x = f.getLargeur() - b2.sizeButton[whenNotUsed].x;
	b2.position[whenNotUsed].y = 0;
	b2.position[whenUsed] = b2.position[whenNotUsed];
	b2.background[whenNotUsed] = sf::Color::Red;
	b2.background[whenUsed] = sf::Color::Red;
	b2.stay_activated = false;
	b2.setText(zero,"Quitter",40,sf::Color::Black);
	b2.moveTextInCenter(zero,true,true);
	
	
	ManagerGUI mg(f.getWindow());
	
	mg.addWidget(&b);
	mg.addWidget(&b2);
	
	while(f.isOpen()){
		f.clear(sf::Color::White);
		mg.useWidgets();
		f.display();
		if(b2.isPushed()) f.close();
	}
	
	exit(0);
}
