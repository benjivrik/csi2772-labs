#ifndef PLAYER_H
#define PLAYER_H


#include <cstdlib>
#include <vector>
#include "Hand.h"
#include "Chain.h"


class Player{
    std::string pName; // player name
    Hand* pHand; // player hand
    std::vector<Chain_Base*> pChains; // player chains
    int pCoins;  // number of coins held by the player
    const int MAX_NUM_CHAINS;
    const int ALLOWED_CHAINS;
    public:
        Player(std::string& name): MAX_NUM_CHAINS(3), ALLOWED_CHAINS(2){
            pName = name;
            pCoins = 0;
            pHand = new Hand();

        };
        Player(std::istream&, const CardFactory*): MAX_NUM_CHAINS(3), ALLOWED_CHAINS(2){
            // TO DO
        };
        ~Player(){
            delete pHand;
        };
        Player& operator+=(int coins){
            pCoins += coins;
            return *this;
        };

        Chain_Base& operator[](int i){
            return *(pChains.at(i));
        };

        void takeCard(Card*); // added
        Card* playCard();    // added
        Card* removeCard(); // discard card to the pile

        std::string getName();
        int getNumCoins();
        int getMaxNumChains();
        int getNumChains();
        void buyThirdChain();
        void printHand(std::ostream& output, bool in){
            if(!in){
                output << pHand->top()->getName() << std::endl;
            }else{
                for(int i = 0; i < pHand->numCards(); i++){
                    output << pHand->top()->getName() << " ";
                }
                output << std::endl;
            }
        };
        
        friend std::ostream& operator<<(std::ostream&,  const Player& );
        void savePlayer(int p_id);
        
};


#endif