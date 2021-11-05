#include "Deck.h"
#include <algorithm>

class CardFactory{
    private:
        Deck<Card*> deck;
        CardFactory(){};
    public:
        static CardFactory* instance;
        static CardFactory* getFactory(){
            if(!instance)
                instance = new CardFactory;
            return instance;
        };
        Deck<Card*> getDeck();
};

