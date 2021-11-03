
#include "Main.h"
using namespace std;



int main(){

    // testing Deck
    // g++ .\Main.cpp .\Card.cpp .\Deck.cpp -std=c++11
    Deck<Card*> d;

    cout << "Deck Size : " << d.size() << endl;

    for(int i = 0; i < d.size(); i++){
        cout << "id=" << i << ":" << d.at(i)->getName() << endl;
    }
    unsigned seed = 0;

    std::shuffle(d.begin(), d.end(), std::default_random_engine(seed)); // shuffle 

    cout << "> Displaying shuffled setup. <" << endl;

    for(int i = 0; i < d.size(); i++){
        cout << "id=" << i << ":" << d.at(i)->getName() << endl;
    }
    return 0;
};

