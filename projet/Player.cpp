#include "headers/Player.h"
#include <string>

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
        if(pChains.size() <= ALLOWED_CHAINS){
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
            std::cout << "Player " <<pName << "has reached the maximum allowed value of chain ("<<ALLOWED_CHAINS<<")." << std::endl;
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
    Card* card = nullptr;
    if(pCoins % 3 == 0){
        pCoins -= 3;
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
        throw "NotEnoughCoins";
    }
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
std::ostream& operator<<(std::ostream& output, const Player& player){

    output << player.pName << " " << player.pCoins << std::endl;
    for(auto chain : player.pChains){
        output << chain;
        output << std::endl;
    }

    return output;
}

/**
 * 
 * @brief write the card inside a file
 * 
 */
void Player::savePlayer(int p_id){
    
    std::ofstream file;
    char id[2];
    sprintf(id, "%d", p_id);
    std::string filename ="Saved-P"+std::string(id)+"-Hand.txt";

    file.open(filename);
    pHand->saveHand(file);

    file.close();

    file.open("Saved-P"+std::string(id)+"-Chains.txt");
    file.close();

    std::cout << "Player-"+std::string(id) << " saved. " << std::endl;
}