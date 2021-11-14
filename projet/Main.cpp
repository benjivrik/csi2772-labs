
#include "Main.h"

using namespace std;



int main(){

    // >>>>>>>  testing Deck <<<<<<<<<< //
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

    cout << "Enter the name of the first player : ";
    cin  >> p1_name;
    cout << std::endl;
    cout << "Enter the name of the second player : ";
    cin  >> p2_name;
    cout << std::endl;

    // initialize the component
    const int MAX_NUM_PLAYER = 2;
    Player p1(p1_name);
    Player p2(p2_name);
    // Player** pArr =  new Player*[MAX_NUM_PLAYER];
    // pArr[0] = &p1;
    // pArr[1] = &p2;
  
    DiscardPile dp;
    CardFactory* cf = CardFactory::getFactory();
    Deck deck = cf -> getDeck();
    TradeArea trAr;
    Table tb(p1,p2,dp,trAr,deck);
    char user_input[2];

    bool savedGame;
  
    // load game from saved file here
    cout << "Do you want to reload a game?" << endl;
    // search for file; if not found continue

    // proceed with the game loop
    while(deck.size() != 0){
       std::cout << "Number of card left in Deck : " << deck.size() << std::endl;
       std::cout << "Do you want to pause the game ? (y/n)" << std::endl;
       cin >> user_input;
       if(user_input[0] == 'y'){
           // proceed with the logic for pausing the game
       }
       else{ // proceed with the game
           for(int i = 0; i < MAX_NUM_PLAYER; i++){
               // proceed with the logic
               Player* p = tb.getPlayer(i);  // get the current player
           }
       }
       deck.draw(); // remove this line when the logic is implemented
    }


    return 0;
};

