
#include "headers/Main.h"
#include <fstream>
#include <sstream>

using namespace std;



int main(){

    // >>>>>>>>>>>  testing Deck <<<<<<<<<< //
    // unsigned seed = 0;
    // // srand(time(0));
    // // g++ .\Main.cpp .\Card.cpp .\Deck.cpp -std=c++11
    // CardFactory* cf = CardFactory::getFactory();
    // Deck d = cf -> getDeck();
    // cout << "Deck Size : " << d.size() << endl;
    // for(int i = 0; i < d.size(); i++){
    //     cout << "id=" << i << ":" << d.at(i)->getName() << endl;
    //     // cout << "TEST" << endl;
    //     // d.at(i)->print(std::cout);
    //     // cout << endl;
    // }
    // std::shuffle(d.begin(), d.end(), std::default_random_engine(seed)); // shuffle 
    // cout << "> Displaying shuffled setup. <" << endl;
    // for(int i = 0; i < d.size(); i++){
    //     cout << "id=" << i << ":" << d.at(i)->getName() << endl;
    // }
    // >>>>>>>>>>>>>>>>>>>>>>>>>>>>|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<//
    

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
    Deck* deck =  cf -> getDeck();
    TradeArea* trAr = new TradeArea;
    Table* tb = new Table(*p1,*p2,*dp, *trAr, *deck, *cf);
    // Table tb(*p1,*p2,*dp, *trAr, *deck, *cf);

    char user_input[2];
    bool savedGame;

    // load game from saved file here
    std::cout << "Do you want to reload a game?(y/n)" << std::endl;
    std::cin >> user_input;
    // search for file; if not found continue
    if(user_input[0] == 'y'){
        std::ifstream deckFile("Saved-Deck.txt");
        std::cout << "Deck file opened status : " << deckFile.is_open() << std::endl;
        if(deckFile.is_open()){
            deck = new Deck(deckFile,cf);
        }else{
            // file not found
            std::cout << "Saved-Deck.txt not found. The deck has been generated from the CardFactory." << std::endl;
        }

        tb -> reloadPlayer(1); // get the player 1
        tb -> reloadPlayer(2); // get the player 2

        p1 = tb -> getPlayer(1);
        p2 = tb -> getPlayer(2);

        
        
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
               std::cout << "Table : " << std::endl << tb << std::endl;

               // proceed with the logic
               std::cout << std::endl;
               std::cout << "Player " << i+1 << " turn. " << std::endl;
               std::cout << std::endl;

               Player* p = tb -> getPlayer(i);  // get the current player

               // Play topmost card from Hand.
               p->takeCard(deck->draw());

               // 
               if(trAr->numCards() > 0) {
                   // do something here
               }else{
                   // do something here
               }

               // Play topmost card from Hand.
               std::cout << "Player " << i+1 << " Hand: " << std::endl;
               p->playCard();
               p->printHand(std::cout, true);
               p->printHand(std::cout, false);

          
           }
       }
       deck->draw(); // remove this line when the logic is implemented
    }


    return 0;
};

