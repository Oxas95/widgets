#ifndef input_hpp
#define input_hpp

#include "fenetre.hpp"
#include <iostream>
#include <string>

using namespace std;

class Input{
    private :
        char* str;
        int id;
        static int nbInstance;
        static int nbInstanceActif;
        static int focus;
        sf::Vector2i posInput;
        int sizeText; //police
        int maxChar;
        Fenetre w;
        int cursor;
        int sizebar;
        
    public :
        static sf::Vector2i clic;
		
        Input(Fenetre& w, sf::Vector2i posInput, int sizeText, int maxChar, int sizebar);
        ~Input();
        char* getString();
        void drawInput();
        static void get_event(Fenetre& w, sf::Keyboard::Key& k, bool pressed);
};


#endif //input_hpp
