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
	
	Button b2(f);
	b2.position.x = 70;
	b2.position.y = 70;
	b2.sizeButton.x = 50;
	b2.sizeButton.y = 50;
	b2.stay_activated = false;
	
	ManagerGUI mg(f);
	
	mg.addWidget(&b);
	mg.addWidget(&b2);
	
	while(f.isOpen()){
		f.clear();
		mg.useWidgets();
		f.display();
	}
	
	exit(0);
}
