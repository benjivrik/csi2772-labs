
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
       std::cout << "Do you want to pause and save the game ? (y/n)" << std::endl;
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
             
               // Play topmost card from Hand.
               p->takeCard(deck->draw());

               // 
               if(trAr->numCards() > 0) {
                   // do something here
               }

               // Play topmost card from Hand.
               std::cout << std::endl << "Playing card ..." << std::endl;
               p->playCard();

               // If chain is ended, cards for chain are removed and player receives coin(s).
               std::cout << std::endl << "> Play top most card ? (y) or Discard card to Discard Pile? (n) " << std::endl;

               std::cin >> user_input; 

               if(user_input[0] == 'y'){
                   // Play the now topmost card from Hand. 
                   p -> playCard();
               }else{
                   int idx; 
                   Card* card = nullptr;
                   // Show the player's full hand and player selects an arbitrary card
                   std::cout << std::endl << "Player " << i+1 << " Hand: " << std::endl;
                   p->printHand(std::cout, true);
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

               // attempting to add card inside the trade area
            //    *trAr+=(p->removeCard());

             
              
              
               // p->printHand(std::cout, false);

               
              
               if(p->getNumCards() > 0)
                 //   *dp+= (p->removeCard()); // send a card to the discard pile

               std::cout << std::endl << "> Discard Pile all cards : " ;
               dp->print(std::cout);
               std::cout << std::endl;
               
           }
       }
       deck->draw(); // remove this line when the logic is implemented
    }


    return 0;
};

