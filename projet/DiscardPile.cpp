#include "headers/DiscardPile.h"

/**
 * @brief 
 * 
 * @return Card* 
 */
Card* DiscardPile::pickUp(){
    Card* card;
    card =  this->back();
    this->pop_back();
    return card;
}

/**
 * @brief 
 * 
 * @return Card* 
 */
Card* DiscardPile::top(){
    return  this->front();
}


/**
 * @brief 
 * 
 * @param os 
 */
void  DiscardPile::print(std::ostream& os){
    for(int i = 0; i < this->size(); i++){
        os << this->at(i)->getName()[0]<< std::endl;
    }
}


/**
 * @brief 
 * 
 * @param output 
 * @param dp 
 * @return std::ostream& 
 */
std::ostream& operator<<( std::ostream &output, const DiscardPile& dp ){
    for(int i = 0; i < dp.size(); i++){
        output << dp.at(i)->getName()[0] << std::endl;
    }

    return output;
}

