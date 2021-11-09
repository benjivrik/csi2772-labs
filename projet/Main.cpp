
#include "Main.h"

using namespace std;



int main(){

    // testing Deck
    unsigned seed = 0;
    // srand(time(0));
    // g++ .\Main.cpp .\Card.cpp .\Deck.cpp -std=c++11

    CardFactory* cf = CardFactory::getFactory();
    
    Deck d = cf -> getDeck();

    cout << "Deck Size : " << d.size() << endl;

    for(int i = 0; i < d.size(); i++){
        cout << "id=" << i << ":" << d.at(i)->getName() << endl;
        // cout << "TEST" << endl;
        // d.at(i)->print(std::cout);
        // cout << endl;
    }

    
    std::shuffle(d.begin(), d.end(), std::default_random_engine(seed)); // shuffle 


    cout << "> Displaying shuffled setup. <" << endl;

    for(int i = 0; i < d.size(); i++){
        cout << "id=" << i << ":" << d.at(i)->getName() << endl;
    }
    
    return 0;
};

