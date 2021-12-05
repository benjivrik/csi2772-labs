#include "headers/Main.h"
#include <fstream>
#include <sstream>


using namespace std;


int main(){
    std::cout << "-------------------------------------------"<< std::endl;
    std::cout << "(FALL2021) - CSI2772 -  Project (Card Game)" << std::endl;
    std::cout << " > Student name : Benjamin Kataliko "<< std::endl;
    std::cout << " > Student number: 8842942 "<< std::endl;
    std::cout << " > Student name : Mamadou Diallo "<< std::endl;
    std::cout << " > Student number: 8883933 "<< std::endl;
    std::cout << "-------------------------------------------" << std::endl ;
    std::cout << std::endl;

    std::string p1_name;
    std::string p2_name;
    std::string winner_name;

    // initialize the components
    const int MAX_NUM_PLAYER = 2;
    Player* p1 = nullptr;
    Player* p2 = nullptr;
    // array of players
    Player** pArr =  new Player*[MAX_NUM_PLAYER];
    DiscardPile* dp = new DiscardPile;
    CardFactory* cf = CardFactory::getFactory();
    Deck* deck =  nullptr;
    TradeArea* trAr = new TradeArea;
    Table* tb = new Table(*p1,*p2,*dp, *trAr, *deck, *cf);

    char user_input[2];
    bool savedGame;

    // load game from saved file here
    std::cout << "Do you want to reload a game?(y/n)" << std::endl;
    std::cin >> user_input;

    // search for file; if not found continue
    if(user_input[0] == 'y'){
        
        // reload deck
        tb-> reloadDeck();
        deck = tb ->getDeck();

        tb -> reloadPlayer(1); // get the player 1
        tb -> reloadPlayer(2); // get the player 2

        p1 = tb -> getPlayer(1);
        p2 = tb -> getPlayer(2);

        tb -> reloadDiscardPile();   // reload the discard pile
        dp = tb -> getDiscardPile(); // get the discard pile

        tb -> reloadTradeArea();
        trAr = tb -> getTradeArea(); // get the trade area
        
    } else {
        cout << std::endl;
        cout << "Enter the name of the first player : ";
        cin  >> p1_name;
        cout << std::endl;
        cout << "Enter the name of the second player : ";
        cin  >> p2_name;
        cout << std::endl;

        p1 = new Player(p1_name);
        p2 = new Player(p2_name);

        pArr[0] = p1;
        pArr[1] = p2;

        tb = new Table(*p1,*p2,*dp, *trAr, *deck, *cf);

        deck = tb -> getDeck();        // get the deck
        dp   = tb -> getDiscardPile(); // get the discard pile
        trAr = tb -> getTradeArea();   // get the trade area

        std::cout << "Initializing  each player with 5 cards. " << std::endl;
        std::cout << "Current size of the deck : " << deck -> size() << std::endl;

        // initialize 5 cards to hand of each player
        for(int player = 0 ; player < MAX_NUM_PLAYER ; player++){
            for(int card = 0; card < 5; card++){
                pArr[player]->takeCard(deck->draw());
            }
        }
    }
  
    // proceed with the game loop
    while(deck->size() != 0){
       std::cout << "Number of card left in Deck : " << deck->size() << std::endl;
       std::cout << std::endl << ">>>>>>>>>>> Do you want to pause and save the game ? (y/n)" << std::endl;
       std::cin >> user_input;
       if(user_input[0] == 'y'){
           // proceed with the logic for pausing the game
           tb -> saveTable();
           std::cout << "Game saved. Bye." << std::endl;
           break;
       }
       else{ // proceed with the game
           for(int i = 0; i < MAX_NUM_PLAYER; i++){

               // display table
               std::cout << std::endl <<  ">>>> Table information: <<<<" << std::endl << std::endl << *tb << std::endl;

               // proceed with the logic
               std::cout << std::endl;
               std::cout << ">>>> Player " << i+1 << " turn. " << std::endl;
               std::cout << std::endl;

               Player* p = tb -> getPlayer(i);  // get the current player
             
               std::cout <<  "> Drawing top card from deck..." << std::endl;
               //  Player draws top card from Deck
               p->takeCard(deck->draw());

               std::cout << std::endl << "> Player " << i+1 << " Hand: " << std::endl;
               p->printHand(std::cout, true);
               std::cout << std::endl;

               // Add bean cards from the TradeArea to chains or discard them
               if(trAr->numCards() > 0) {
                   bool cardAdded = false;
                   // Add bean cards from the TradeArea to chains or discard them
                   for( Card* card : trAr->getListOfCards() ){
                        for( Chain_Base* chain : *(p->getChains()) ){
                            if(card->getName() == chain->getChainType()){
                               *chain += trAr->trade(card->getName());
                               cardAdded = true;
                            }
                        }

                        // discard the card to the discard pile if the card was not added
                        if(!cardAdded){
                           std::cout << "> Card : " ;
                           card->print(std::cout);
                           std::cout << " added to the discard pile " << std::endl;
                           *dp+=trAr->trade(card->getName());
                        }
                   }
               }

               std::cout << std::endl << "> Playing topmost card from Hand (" << p->getHand()->top()->getName()[0] <<")" << std::endl;
               // Play topmost card from Hand.
               // If chain is ended, cards for chain are removed and player receives coin(s).
               p->playCard();

               std::cout << std::endl <<  *p << std::endl;

               std::cout << std::endl << "> Player " << i+1 << " Hand: " << std::endl;
               p->printHand(std::cout, true);
               std::cout << std::endl;

               std::cout << std::endl << "> Play top most card ? (y) or Discard card to Discard Pile? (n) " << std::endl;


               std::cin >> user_input; 

               if(user_input[0] == 'y'){

                   std::cout <<  "> Playing topmost card from Hand (" << p->getHand()->top()->getName()[0] <<")" << std::endl;
                   // Play the now topmost card from Hand. 
                   p -> playCard();

                   std::cout << std::endl <<  *p << std::endl;

                   std::cout << std::endl << "> Player " << i+1 << " Hand: " << std::endl;
                   p->printHand(std::cout, true);
                   std::cout << std::endl;

               }else{

                   int idx; 
                   Card* card = nullptr;
                   // Show the player's full hand and player selects an arbitrary card
                   std::cout << std::endl << "> Player " << i+1 << " Hand: " << std::endl;
                   p->printHand(std::cout, true);
                   
                   // p->printHand(std::cout, false);
                   std::cout << "Current size of the hand : " << p->getNumCards() << std::endl;
                   std::cout << "Enter the index of the card you would like to remove : " << std::endl;
                   std::cin  >> idx;

                   // Discard the arbitrary card from the player's hand and place it on the discard pile.
                   card = p->removeCard(idx);
                   if(card == nullptr)
                      std::cout << "Card not could be removed. Please check the entered index : " << idx << std::endl;
                  
                   // enter the proper index
                   while(card == nullptr){
                      std::cout << "Current size of the hand : " << p->getNumCards() << std::endl;
                      std::cout << "Enter the index of the card you would like to remove : " << std::endl;
                      std::cin  >> idx;
                      // Discard the arbitrary card from the player's hand and place it on the discard pile.
                      card = p->removeCard(idx);
                   }
                   
                   // add the card to the discard pile
                   std::cout << "> Card : " ;
                   card->print(std::cout);
                   std::cout << " added to the discard pile " << std::endl;
                   *dp+= card;
               }

               // Draw three cards from the deck and place cards in the trade area
               std::cout << std::endl << ">>>> Drawing three cards from the deck to the trade area. " << std::endl << std::endl;
               for(int drw = 0 ;  drw < 3; drw++){
                   *trAr += (deck -> draw());
               }

               std::cout << "> Trade Area : " << *trAr << std::endl;

               // std::cout << "Dp size : " << dp->size() << std::endl;
               // while top card of discard pile matches an existing card in the trade area
               if(dp->size() > 0){
                   while( trAr->legal(dp-> top())){
                        // draw the top-most card from the discard pile and place it in the trade area
                        *trAr += (dp->pickUp());
                    }
               }

               std::cout << std::endl;

               for(Card* card : trAr->getListOfCards()){
                   std::cout << std::endl << "> Do you want to chain the card [";
                   card -> print(std::cout);
                   std::cout << "]? (y/n) " << std::endl;
                   std::cin >> user_input; 

                   if(user_input[0] == 'y'){
                      // chain the card.
                      p -> playCard(trAr -> trade(card->getName()),  true);

                      std::cout << std::endl <<  *p << std::endl;

                      std::cout << std::endl << "> Player " << i+1 << " Hand: " << std::endl;
                      p->printHand(std::cout, true);
                      std::cout << std::endl;

                    }else{
                      
                      std::cout << std::endl << "> card left in the trade area." << std::endl;
                                         
                    }

               }
               
               // Draw two cards from Deck and add the cards to the player's hand (at the back).
               for(int i = 0; i < 2; i++){
                   p -> takeCard(deck->draw());
               }

               std::cout << std::endl << "> Player " << i+1 << " Hand: " << std::endl;
               p->printHand(std::cout, true);
               std::cout << std::endl;

               std::cout << std::endl << "> Discard Pile all cards : " ;
               dp->print(std::cout);
               std::cout << std::endl;
               
           }
       }
    } // end of while loop with deck

    if(deck->size() == 0){
       tb->win(winner_name);
       std::cout << std::endl << "> The winner is : " << winner_name << std::endl;
    }
    
    return 0;
};

