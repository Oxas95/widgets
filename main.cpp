#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "fenetre.hpp"
#include "button.hpp"
#include "managerGUI.hpp"

int main(){
	Fenetre f;
	f.resize(2);
	Button b(f);
	b.position.x = 10;
	b.position.y = 10;
	b.sizeButton.x = 50;
	b.sizeButton.y = 50;
	b.background[whenNotUsed] = sf::Color::White;
	b.background[whenUsed] = sf::Color::White;
	b.setText(zero,"X",0,sf::Color::Black, sf::Vector2i(b.position.x + (b.sizeButton.x - f.getFont("X", 30)) / 2, b.position.y + (b.sizeButton.y - 30) / 2.4f));
	b.setText(un,"V",30,sf::Color::Black, sf::Vector2i(b.position.x + (b.sizeButton.x - f.getFont("V", 30)) / 2, b.position.y + (b.sizeButton.y - 30) / 2.4f));
	
	Button b2(f);
	b2.sizeButton.x = 200;
	b2.sizeButton.y = 200;
	b2.position.x = f.getLargeur() - b2.sizeButton.x;
	b2.position.y = 0;
	b2.background[whenNotUsed] = sf::Color::Red;
	b2.stay_activated = false;
	b2.setText(zero,"Quitter",40,sf::Color::Black, sf::Vector2i(b2.position.x + (b2.sizeButton.x - f.getFont("Quitter", 40)) / 2, b2.position.y + (b2.sizeButton.y - 40) / 2.4f));
	
	
	ManagerGUI mg(f);
	
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
