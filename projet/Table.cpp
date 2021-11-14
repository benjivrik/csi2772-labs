#include "Table.h"


/**
 * @brief 
 * 
 * @param pName 
 * @return true 
 * @return false 
 */
bool Table::win(std::string& pName){
    bool win = false;
    if(deck->size() == 0){
      
       if(p1->getNumCoins() > p2->getNumCoins()){
           pName = p1->getName();
       }
       else if(p1 ->getNumCoins() < p2->getNumCoins()){
           pName = p2->getName();
       }
       else{ //  equality
           pName = "Equality";
       }

       win = true;
    }
    return win;
}

/**
 * @brief 
 * 
 * @param in 
 */
void Table::printHand(bool in){
     Player* current = currentPlayer == 0 ? p1 : p2; // get the current player
     current -> printHand(std::cout, in);
}

/**
 * @brief 
 * 
 * @param id 
 * @return Player* 
 */
Player* Table::getPlayer(int id){
    currentPlayer = id;
    if (id==0) return p1;
    else return p2;
}


/**
 * @brief 
 * 
 * @param output 
 * @param tb 
 * @return std::ostream 
 */
std::ostream operator<<(std::ostream& output, const Table& tb){
    // TO DO
    return output;
}