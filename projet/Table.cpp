#include "headers/Table.h"


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
std::ostream& operator<<( std::ostream& output,  const Table&  tb){

        output << "Player 1 :" << std::endl << *tb.p1 << std::endl;
        output << "Player 2 :" << std::endl << *tb.p2 << std::endl;
        output << "Discard Pile :" << std::endl << *tb.dp << std::endl;
        output << "Trade Area :" << std::endl << *tb.tradeAr << std::endl;

        return output;
};


/**
 * 
 * @brief write the game into the related file
 * 
 */
void Table::saveTable(){
    
    std::ofstream file;

    file.open("Saved-Deck.txt", std::ios::trunc);
    deck->saveDeck(file);

    file.close();

    file.open("Saved-DiscardPile.txt", std::ios::trunc);
    dp->saveDiscardPile(file);
    file.close();

    file.open("Saved-TradeArea.txt", std::ios::trunc);
    tradeAr->saveTradeArea(file);
    file.close();

    p1->savePlayer(1);
    p2->savePlayer(2);

}

/**
 * @brief 
 * 
 */
void Table::reloadPlayer(int p_id){
    std::ifstream file;
    char id[2];
    sprintf(id, "%d", p_id);
    std::string filename ="Saved-P"+std::string(id)+".txt";
    file.open(filename);
    if(file.is_open()){
        if(p_id == 1){
            p1 = new Player(file, cf);
        }else{ // p_id should be equal to 2
            p2 = new Player(file, cf);
        }
    }

    file.close();
    
}