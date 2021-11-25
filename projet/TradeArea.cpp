#include "headers/TradeArea.h"

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

    Card* cardFound;
    std::list<Card*>::iterator i;

    for(i = tradeAr.begin(); i != tradeAr.end(); i++){
        if( (*i)->getName() == card) cardFound = *i;
    }

    return cardFound;
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
 * @param output 
 * @param tr_arr 
 * @return std::ostream 
 */
std::ostream& operator<<(std::ostream& output, const TradeArea& tr_arr){

    for(auto card : tr_arr.tradeAr){
        output << card->getName() << std::endl;
    }

    return output;
}


/**
 * @brief 
 * 
 */
void TradeArea::saveTradeArea(std::ofstream& filename){
    for(auto card: tradeAr){
        card->saveCard(filename);
        filename<<std::endl;
    }

    std::cout << "TradeArea saved." << std::endl;
}
