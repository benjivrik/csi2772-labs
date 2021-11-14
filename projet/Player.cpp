#include "Player.h"

/**
 * @brief Get the Name object
 * 
 * @return std::string 
 */
std::string Player::getName(){
    return this->pName;
}

Card* Player::playCard(){
    Card* card = nullptr;
    if (pHand->numCards() < 0)
        std::cout << "(PlayCard) Not enough card in hand for player : " << pName << std::endl;
    else{
        if(pChains.size() < MAX_NUM_CHAINS){
            card = pHand->top(); // should be play here...
            Chain_Base* new_chain;
            if(card->getName() == "Blue") new_chain = new Chain<Blue>;
            else if(card->getName() == "Chili") new_chain = new Chain<Chili>;
            else if(card->getName() == "Stink") new_chain = new Chain<Stink>;
            else if(card->getName() == "Green") new_chain = new Chain<Green>;
            else if(card->getName() == "soy")   new_chain = new Chain<soy>;
            else if(card->getName() == "black") new_chain = new Chain<black>;
            else if(card->getName() == "Red")   new_chain = new Chain<Red>;
            else if(card->getName() == "garden")new_chain = new Chain<garden>;
            else {
                std::cout << "(playCard) Check the card name. Value received : " << card->getName() << std::endl;
                new_chain = nullptr; 
                exit(1);
              
            }
            pChains.push_back(new_chain);

        }else{
            std::cout << "Player " <<pName << "has reached the maximum allowed value of chain ("<<MAX_NUM_CHAINS<<")." << std::endl;
           // item should be sold ?
        }
    }
    return card; 
}
/**
 * @brief 
 * 
 * @return int 
 */
int Player::getMaxNumChains(){
    return MAX_NUM_CHAINS;
}


/**
 * @brief 
 * 
 * @return int 
 */
int Player::getNumChains(){
    int counter; 
    for(int i = 0; i < pChains.size(); i++){
        if( (pChains.at(i))->getSize() > 0) counter++;
    }
    return counter;
}

/**
 * @brief 
 * 
 */
void Player::buyThirdChain(){

}


/**
 * @brief 
 * 
 */

void Player::takeCard(Card* card){
    *pHand += card;  // add the card in the player hand
}


/**
 * @brief 
 * 
 */
Card* Player::removeCard(){
    return pHand->play();
}

/**
 * @brief 
 * 
 * @return int 
 */
int Player::getNumCoins(){
    return pCoins;
}


/**
 * @brief 
 * 
 * @param output 
 * @param player 
 * @return std::ostream 
 */
std::ostream operator<<(std::ostream& output, const Player& player){
    // TO DO
    return output;
}