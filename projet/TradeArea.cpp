#include "TradeArea.h"

/**
 * @brief 
 * 
 * @param card 
 * @return true 
 * @return false 
 */
bool TradeArea::legal (Card* card){

    bool found = false;
    std::list<Card*>::iterator i;
    for( i = tradeAr.begin(); i != tradeAr.end(); i++){
        if( (*i)->getName() == card->getName()) found = true;
    }

    return found;
}


/**
 * @brief 
 * 
 * @param card 
 * @return Card* 
 */
Card* TradeArea::trade (std::string card){

    Card* found;
    std::list<Card*>::iterator i;

    for(i = tradeAr.begin(); i != tradeAr.end(); i++){
        if( (*i)->getName() == card) found = *i;
    }

    return found;
}

/**
 * @brief 
 * 
 * @return int 
 */
int TradeArea::numCards(){ return tradeAr.size(); }



/**
 * @brief 
 * 
 * @param input 
 * @param cf 
 * @return std::istream& 
 */
std::istream& operator>>( std::istream &input, const CardFactory* cf){
    // TO DO
    return input;
};