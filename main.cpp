#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "fenetre.hpp"
#include "widgetBox/buttonRect.hpp"
#include "widgetBox/buttonCircle.hpp"
#include "widgetBox/textArea.hpp"
#include "managerGUI.hpp"

using namespace std;

int main(){
	Fenetre f;
	f.resize(3);
	
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
	
	TextArea ta(f.getWindow());
	
	ta.setText(Off,"Bonjour\nje suis etudiant en fac\net je cherche un cahier perdu",5,sf::Color::Red,sf::Vector2i(20,20));
	
	ManagerGUI mg(f.getWindow());
	
	mg.addWidget(&b2);
	mg.addWidget(&ta);
	
	while(f.isOpen()){
		f.clear(sf::Color::White);
		mg.useWidgets();
		f.display();
		if(b2.isPushed()) f.close();
	}
	
	cout << b2.text[Off].getFont()->getInfo().family.c_str() << endl;
	
	exit(0);
}
