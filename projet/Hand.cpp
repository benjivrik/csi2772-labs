#include "headers/Hand.h"

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

/**
 * @brief 
 * 
 * @param pos 
 * @return Card* 
 */
Card* Hand::getCard(int pos){
    Card* card = nullptr; // removed card to return
    if(pos > pHand.size()-1){
        std::cout << "(getCard) The index "  << pos << " can not be used. Current size of the hand = " << pHand.size() << std::endl;
    }else{
        std::queue <Card*, std::list<Card*>> temp; // temp player hand
        Card* temp_card = nullptr;  // temp card
        int find_idx = 0;
        while(!pHand.empty()){

            if(find_idx == pos){
                // get the element
                card = pHand.front();
            }
            temp_card = pHand.front(); // get the card
            pHand.pop();     // add it in the temporary queue
            temp.push(temp_card); // add the card in the queue
            
        }

        // get the initial elements without the removed card inside pHand
        while(!temp.empty()){
            
            temp_card = temp.front(); // get the card
            temp.pop();     // add it in the temporary queue
            pHand.push(temp_card); // add the card in the queue
            
        }
    }

   
    return card;  
}

/**
 * @brief 
 * 
 */

std::ostream& operator<<( std::ostream& output, Hand& hand){
    for( int pos = 0; pos < hand.numCards() ; pos++ ){
        output << hand.getCard(pos) << std::endl;
    }
    return output;
};


/**
 * 
 * @brief write the card inside a file
 * 
 */
void Hand::saveHand(std::ofstream& filename){

    Card* card = nullptr; // removed card to return
    std::queue <Card*, std::list<Card*>> temp; // temp player hand
    Card* temp_card = nullptr;  // temp card
    int find_idx = 0;
    while(!pHand.empty()){
        temp_card = pHand.front(); // get the card
        temp_card -> saveCard(filename);
        filename << std::endl;
        pHand.pop();     // add it in the temporary queue
        temp.push(temp_card); // add the card in the queue
    }

    // get the initial elements without the removed card inside pHand
    while(!temp.empty()){
        
        temp_card = temp.front(); // get the card
        temp.pop();     // add it in the temporary queue
        pHand.push(temp_card); // add the card in the queue
        
    }

    std::cout << "Hand saved." << std::endl;
}
