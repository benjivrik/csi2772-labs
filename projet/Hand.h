#ifndef HAND_H
#define HAND_H

#include "Card.h"

#include <queue>
#include <list>

class CardFactory;

class Hand{
    std::queue <Card*, std::list<Card*>> pHand; // player hand
    public:
        Hand(){};
        Hand& operator+=(Card* card){
            pHand.push(card);
        };
        Card* play();
        Card* top();
        Card* operator[](int pos){
            Card* card = nullptr; // removed card to return
            std::queue <Card*, std::list<Card*>> temp; // temp player hand
            Card* temp_card = nullptr;  // temp card
            int find_idx = 0;
            while(!pHand.empty()){
                if(find_idx == pos){
                    // do not add the element in the temporary queue
                    card = pHand.front();
                    pHand.pop();
                }
                else
                {
                    temp_card = pHand.front(); // get the card
                    pHand.pop();     // add it in the temporary queue
                    temp.push(temp_card); // add the card in the queue
                }
            }

            // get the initial elements without the removed card inside pHand
            while(!temp.empty()){
              
                temp_card = temp.front(); // get the card
                temp.pop();     // add it in the temporary queue
                pHand.push(temp_card); // add the card in the queue
                
            }
            return card;  
        };
        // friend ostream& operator<<( ostream &output );
        friend std::istream& operator>>( std::istream&, const CardFactory* );

};

#endif 