#include "Hand.h"

/**
 * @brief 
 * 
 * @return Card* 
 */
Card* Hand::play(){
    Card* card = pHand.front();
    pHand.pop(); // remove the first element
    return card;
}

/**
 * @brief 
 * 
 * @return Card* 
 */
Card* Hand::top(){
    return pHand.front();
}

/**
 * @brief 
 * 
 * @return int 
 */
int Hand::numCards(){
    return pHand.size();
}

