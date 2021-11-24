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
        Player(std::istream& input, const CardFactory* cf): MAX_NUM_CHAINS(3), ALLOWED_CHAINS(2){
            std::string line;
            std::string chainType;
            Card* card = nullptr;
            int  chain_idx = -1; // keep track of the idx of the chain being added from the text file
            int  count = 0; // number of cards received
            bool nameInitialized   = false;
            bool handInitialized   = false;
            bool chainsInitialized = false;
            bool chainTypeInitialized = false;
            
            while (std::getline(input, line))
            {
                std::istringstream iss(line);
                std::string data;
                if (!(iss >> data)) { 
                    // std::cout<< "Empty" <<std::endl;
                    continue;
                } 
                // get the name on the first file
                if(!nameInitialized) {
                    pName = data;
                    nameInitialized = true;
                    continue;
                }

                // initialized the hand
                if(!handInitialized){
                    if(data == "-chains"){
                        handInitialized = true; // we have reached the end of the hand content
                        continue;
                    } 
                    else{
                        // std::cout << data << std::endl; //debug purpose
                        count++;
                        if(data == "B")       card = new Blue;
                        else if(data == "C")  card = new Chili;
                        else if(data == "S")  card = new Stink;
                        else if(data == "G")  card = new Green;
                        else if(data == "s")  card = new soy;
                        else if(data == "b")  card = new black;
                        else if(data == "R")  card = new Red;
                        else if(data == "g")  card = new garden;
                        else {
                            std::cout << "(Player Constructor) Check the card name in the file. Value received : " << data << std::endl;
                            exit(1);
                        }
                      //
                      if(card != nullptr) *pHand+=card;
                   }
                }

                // initialize the chains
                if(!chainsInitialized && handInitialized){ // wait for the chain to be initialized 

                    if(data == "-end-chains") {
                        chainsInitialized = true;
                        continue;
                    }
                    else{
                       if(data == "---"){
                           chainTypeInitialized = false;
                           continue; // get the chain data
                       }else{
                           if(!chainTypeInitialized){
                             // the first line is the chain type
                             chainType = data;
                             chainTypeInitialized = true;

                             Chain_Base* new_chain;
                             if(chainType == "Blue") new_chain = new Chain<Blue>;
                             else if(chainType == "Chili") new_chain = new Chain<Chili>;
                             else if(chainType == "Stink") new_chain = new Chain<Stink>;
                             else if(chainType == "Green") new_chain = new Chain<Green>;
                             else if(chainType == "soy")   new_chain = new Chain<soy>;
                             else if(chainType == "black") new_chain = new Chain<black>;
                             else if(chainType == "Red")   new_chain = new Chain<Red>;
                             else if(chainType == "garden")new_chain = new Chain<garden>;
                             else {
                                    std::cout << "(Player Constructor) Check the chain type. Value received : " << chainType << std::endl;
                                    new_chain = nullptr; 
                                    exit(1);
                             }
                             // add the chain if it has been initialized
                             if(new_chain != nullptr) {
                                 pChains.push_back(new_chain);
                                 chain_idx++;
                             }
                                

                          }else{
                              card = nullptr;
                              // collect the card
                              if(data == "B")       card = new Blue;
                              else if(data == "C")  card = new Chili;
                              else if(data == "S")  card = new Stink;
                              else if(data == "G")  card = new Green;
                              else if(data == "s")  card = new soy;
                              else if(data == "b")  card = new black;
                              else if(data == "R")  card = new Red;
                              else if(data == "g")  card = new garden;
                              else {
                                  std::cout << "(Player Constructor) Check the card name in the file. Value received : " << data << std::endl;
                                  exit(1);
                              }
                              if(chain_idx != -1 && card != nullptr){
                                  *(pChains.at(chain_idx))+=card;
                              }else{
                                  std::cout << "(Player Constructor) No chain has been added so far. chain_idx : " << chain_idx << std::endl;
                              }
                            
                          }
                       }
                    }// else block
                }// end of if
            }// end of while loop

            std::cout << "Player initialized from file properly." <<std::endl;
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