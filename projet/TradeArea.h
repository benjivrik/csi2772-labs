#ifndef TRADEAREA_H
#define TRADEAREA_H

#include "Card.h"
#include <list>

class CardFactory;

class TradeArea{
     std::list<Card*> tradeAr; 
     public:
        TradeArea(){};
        TradeArea(std::istream&, const CardFactory*){};
        TradeArea& operator+=(Card* card){
             tradeAr.push_back(card);
        };
        bool legal(Card*);
        Card* trade(std::string);
        int numCards();
        // friend ostream& operator<<( ostream &output );
        friend std::istream& operator>>( std::istream&, const CardFactory* );
};

#endif