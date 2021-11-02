using namespace std;

#include "Main.h"


int main(){

    // testing Deck
    Deck<Card> d = Deck<Card>();
    Deck<Card>::iterator iter;

    for(int i = 0; i < d.size(); i++){
        cout << "id " << i << ":" << d.at(i).getName() << endl;
    }

    return 0;
};

