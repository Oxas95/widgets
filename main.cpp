#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "fenetre.hpp"

int main(){
	Fenetre f(900,600, "test widgets");
	
	while(f.isOpen()){
		f.wait_clic();
	}
	
	exit(0);
}
