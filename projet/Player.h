#ifndef PLAYER_H
#define PLAYER_H


#include <vector>
#include "Hand.h"
#include "Chain.h"

class Player{
    std::string pName; // player name
    Hand* pHand; // player hand
    std::vector<Chain_Base*> pChains; // player chains
    int pCoins;  // number of coins held by the player
    const int MAX_NUM_CHAINS;
    public:
        Player(std::string& name): MAX_NUM_CHAINS(3){
            pName = name;
            pHand = new Hand();

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

        std::string getName();
        int getNumCoins();
        int getMaxNumChains();
        int getNumChains();
        void buyThirdChain();
        void printHand(std::ostream& output, bool in){
            if(in){
                output << pHand->top()->getName() << std::endl;
            }else{
                for(int i = 0; i < pHand->numCards(); i++){
                    output << pHand->top()->getName() << " ";
                }
                output << std::endl;
            }
        }
        
};


#endif