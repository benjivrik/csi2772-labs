#include "headers/DiscardPile.h"

/**
 * @brief  returns and removes the top card from the discard pile.
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
 * @brief returns but does not remove the top card from the discard pile.
 * 
 * @return Card* 
 */
Card* DiscardPile::top(){
    return  this->front();
}


/**
 * @brief permet d'inserer toutes les cartes du DiscardPile dans le ostream
 * 
 * @param os 
 */
void  DiscardPile::print(std::ostream& os){
    for(int i = 0; i < this->size(); i++){
        os << this->at(i)->getName()[0]<< std::endl;
    }
}


/**
 * @brief insertion operator to display the discard pile object
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

/**
 * @brief write the discard pile inside a file
 * 
 * @param filename 
 */
void DiscardPile::saveDiscardPile(std::ofstream& filename){
    for(int i = 0;  i < this->size() ; i++){
        this->at(i)->saveCard(filename);
        filename << std::endl;
    }
    std::cout << "Discard Pile saved." << std::endl;
}