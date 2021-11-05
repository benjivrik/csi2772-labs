#include "CardFactory.h"

CardFactory* CardFactory::instance = 0; // initialize the instance to 0

Deck<Card*> CardFactory::getDeck(){
    unsigned seed = 0;
    std::shuffle(deck.begin(), deck.end(), std::default_random_engine(seed)); // shuffle 
    return deck;
}