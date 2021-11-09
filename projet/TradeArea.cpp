#include "TradeArea.h"

// Description :
bool TradeArea::legal (Card* card){

    bool found = false;
    std::list<Card*>::iterator i;
    for( i = tradeAr.begin(); i != tradeAr.end(); i++){
        if( (*i)->getName() == card->getName()) found = true;
    }

    return found;
}


// Description :
Card* TradeArea::trade (std::string card){

    Card* found;
    std::list<Card*>::iterator i;

    for(i = tradeAr.begin(); i != tradeAr.end(); i++){
        if( (*i)->getName() == card) found = *i;
    }

    return found;
}

// Description
int TradeArea::numCards(){ return tradeAr.size(); }

std::istream& operator>>( std::istream &input, const CardFactory* cf){
    // TO DO
};