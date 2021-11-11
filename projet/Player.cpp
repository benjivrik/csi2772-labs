#include "Player.h"

/**
 * @brief Get the Name object
 * 
 * @return std::string 
 */
std::string Player::getName(){
    return this->pName;
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


