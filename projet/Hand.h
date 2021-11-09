#ifndef HAND_H
#define HAND_H

#include "Card.h"

#include <queue>
#include <list>

class Hand{
    std::queue <Card*, list<Card*>> pHand; // player hand
    public:
        Hand();
        Hand& operator+=(Card *);
        Card* play();
        Card* top();
        Card* operator[](int);
        // friend ostream& operator<<( ostream &output );
        friend istream& operator>>( istream &input, const CardFactory* );

};

#endif 