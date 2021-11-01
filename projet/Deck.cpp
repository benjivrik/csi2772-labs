#include "Deck.h"

template <typename T = Card> Deck<T>::Deck():NUMBER_OF_CARDS(104), vector<T>(NUMBER_OF_CARDS){
     // add 20 Blue Cards
     for(int i = 0; i <  20;  i++){
         Blue b;
         this->push_back(b);
     }
     // add 18 Chili Cards
     for(int i = 0; i < 18; i++){
         Chili c;
         this->push_back(c);
     }
     // add 16 Stink Cards
     for(int i = 0; i < 16; i++){
         Stink s;
         this->push_back(s);
     }
     // add 14 Green Cards
     for(int i = 0; i < 14; i++){
         Green g;
         this->push_back(g);
     }
     // add 12 soy Cards
     for(int i = 0; i < 12; i++){
         soy s;
         this->push_back(s);
     }
     // add 10 black Cards
     for(int i = 0; i < 12;  i++){
         black b;
         this->push_back(b);
     }
     // add 8 Red  Cards
     for(int i = 0; i < 8; i++){
         Red r;
         this->push_back(r);
     }
     // add 6 garden Cards
     for(int i = 0; i < 6; i++){
         garden g;
         this->push_back(g);
     }

}

template <typename T = Card> T* Deck<T>::draw(){
    // TO DO
}
// implement the friends functions