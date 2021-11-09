#include "Deck.h"
using namespace std;

// draw
 Card* Deck::draw(){
    Card* card =  this->back(); // get the last added card
    this->pop_back(); // remove the last element from the deck
    return card;  
}
//Deck
Deck& Deck::operator=(const Deck& d){
    for(int i = 0 ; i < d.size() && i < 104; i++){
        this->push_back(d[i]);
    }
}
// <<
ostream& operator<<( ostream &output, const Deck &d ){
     for(int i = 0; i < d.size(); i++){
        output << d.at(i)->getName() << endl;
    }

    return output;
}

// >>
// ostream& operator<<( ostream &output, const Deck &d ){
//      for(int i = 0; i < this->size(); i++){
//         output << d.at(i)->getName() << endl;
//     }

//     return output;
// }




