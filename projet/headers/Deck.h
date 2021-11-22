
#include <iostream>
#include <vector>

#ifndef DECK_H
#define DECK_H

// #include "CardFactory.h"
#include "Card.h"

class CardFactory;

class Deck: public std::vector<Card*>{
     public :
        Deck(): std::vector<Card*>(){};
        Deck(std::istream& input, const CardFactory* cf){};
        Deck(const Deck& d){
            // get the items from d inside this current deck
            for(int i = 0; i < 104; i++){
                this->push_back(d.at(i));
            }
            std::cout << "Deck of size("<<d.size()<<") copied."<<std::endl;
        }
        Card* draw();
        ~Deck(){
            for(int i = 0; i < this->size(); i++){
                // std::cout << "deleting i = " << i << "; name = " << this->at(i)->getName() << std::endl; // DEBUG PURPOSE
                delete this->at(i);
            }
            std::cout << "Deck of size("<<this->size()<<") destroyed."<<std::endl;
        };
        Deck& operator=(const Deck&);
        friend std::ostream& operator<<( std::ostream &output, const Deck& d );
        void saveDeck(std::ofstream& filename);
};

#endif