#include "Card.h"
#include <vector>

template <typename T> 
class Deck: public std::vector<T>{
     public :
        const int NUMBER_OF_CARDS;
        Deck():NUMBER_OF_CARDS(104), std::vector<T>(){
             // add 20 Blue Cards
             for(int i = 0; i <  20;  i++){
                     Blue* b = new Blue;
                     this->push_back(b);
                
                     
             }
             // add 18 Chili Cards
             for(int i = 0; i < 18; i++){
                     Chili* c = new Chili;
                     this->push_back(c);
             }
             // add 16 Stink Cards
             for(int i = 0; i < 16; i++){
                     Stink* s = new Stink;
                     this->push_back(s);
             }
             // add 14 Green Cards
             for(int i = 0; i < 14; i++){
                     Green* g = new Green;
                     this->push_back(g);
             }
             // add 12 soy Cards
             for(int i = 0; i < 12; i++){
                      soy* s = new soy;
                      this->push_back(s);
             }
             // add 10 black Cards
             for(int i = 0; i < 10;  i++){
                      black* b = new black;
                      this->push_back(b);
             }
             // add 8 Red  Cards
             for(int i = 0; i < 8; i++){
                      Red* r = new Red;
                      this->push_back(r);
             }
             // add 6 garden Cards
             for(int i = 0; i < 6; i++){
                     garden* g = new garden;
                     this->push_back(g);
             }

        };
        Deck(const Deck<T>& d):NUMBER_OF_CARDS(104){
            // get the items from d inside this current deck
            for(int i = 0; i < NUMBER_OF_CARDS; i++){
                this->push_back(d.at(i));
            }
            std::cout << "Deck of size("<<d.size()<<") copied."<<std::endl;
        }
        T* draw();
        ~Deck(){
            for(int i = 0; i < this->size(); i++){
                // std::cout << "deleting i = " << i << "; name = " << this->at(i)->getName() << std::endl; // DEBUG PURPOSE
                delete this->at(i);
            }
            std::cout << "Deck of size("<<this->size()<<") destroyed."<<std::endl;
        };
        // friend ostream& operator<<( ostream &output );
        // friend istream& operator>>( istream &input );
};