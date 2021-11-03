#include "Card.h"
using namespace std;

// Card

// destructor
Card::~Card() {}

// Blue
Blue::Blue(std::string name){
    this->name = name;
}
/**
 * 
 * add description here
 * 
 * */
int Blue::getCardsPerCoin(int coins){
    int numCards = -1; // default to -1 : invalid
    switch (coins)
    {
    case 1:
        numCards = 4;
        break;
    case 2:
        numCards = 6;
        break;
    case 3:
        numCards = 8;
        break;
    case 4:
        numCards = 10;
        break;
    default:
        cout << "(Blue) - Check the value of coins passed getCardsPerCoin. Value received : " << coins << endl;
        break;
    }

    return  numCards;
}

/**
 * 
 * add description here
 * 
 * */
string Blue::getName(){
    return this->name;
}

/**
 * 
 * add description here
 * 
 * */

void Blue::print(std::ostream& out){
    //TO DO
}

// Chili
Chili::Chili(std::string name){
    this->name = name;
}

/**
 * 
 * add description here
 * 
 * */
string Chili::getName(){
    return this->name;
}

/**
 * 
 * add description here
 * 
 * */
int Chili::getCardsPerCoin(int coins){
    int numCards = -1; // default to -1 : invalid
    switch (coins)
    {
    case 1:
        numCards = 3;
        break;
    case 2:
        numCards = 6;
        break;
    case 3:
        numCards = 8;
        break;
    case 4:
        numCards = 9;
        break;
    default:
        cout << "(Chili) - Check the value of coins passed getCardsPerCoin. Value received : " << coins << endl;
        break;
    }

    return  numCards;
}
/**
 * 
 * add description here
 * 
 * */

void Chili::print(std::ostream& out){
    //TO DO
}

// Stink
Stink::Stink(std::string name){
    this->name = name;
}

/**
 * 
 * add description here
 * 
 * */
string Stink::getName(){
    return this->name;
}

/**
 * 
 * add description here
 * 
 * */
int Stink::getCardsPerCoin(int coins){
    int numCards = -1; // default to -1 : invalid
    switch (coins)
    {
    case 1:
        numCards = 3;
        break;
    case 2:
        numCards = 5;
        break;
    case 3:
        numCards = 7;
        break;
    case 4:
        numCards = 8;
        break;
    default:
        cout << "(Stink) - Check the value of coins passed getCardsPerCoin. Value received : " << coins << endl;
        break;
    }

    return  numCards;
}
/**
 * 
 * add description here
 * 
 * */

void Stink::print(std::ostream& out){
    //TO DO
}

// Green
Green::Green(std::string name){
    this->name = name;
}
/**
 * 
 * add description here
 * 
 * */
string Green::getName(){
    return this->name;
}
/**
 * 
 * add description here
 * 
 * */
int Green::getCardsPerCoin(int coins){
    int numCards = -1; // default to -1 : invalid
    switch (coins)
    {
    case 1:
        numCards = 3;
        break;
    case 2:
        numCards = 5;
        break;
    case 3:
        numCards = 6;
        break;
    case 4:
        numCards = 7;
        break;
    default:
        cout << "(Green) - Check the value of coins passed getCardsPerCoin. Value received : " << coins << endl;
        break;
    }

    return  numCards;
}
/**
 * 
 * add description here
 * 
 * */

void Green::print(std::ostream& out){
    //TO DO
}

// soy
soy::soy(std::string name){
    this->name = name;
}

/**
 * 
 * add description here
 * 
 * */
string soy::getName(){
    return this->name;
}

/**
 * 
 * add description here
 * 
 * */
int soy::getCardsPerCoin(int coins){
    int numCards = -1; // default to -1 : invalid
    switch (coins)
    {
    case 1:
        numCards = 2;
        break;
    case 2:
        numCards = 4;
        break;
    case 3:
        numCards = 6;
        break;
    case 4:
        numCards = 7;
        break;
    default:
        cout << "(soy) - Check the value of coins passed getCardsPerCoin. Value received : " << coins << endl;
        break;
    }

    return  numCards;
}
/**
 * 
 * add description here
 * 
 * */

void soy::print(std::ostream& out){
    //TO DO
}

// black
black::black(std::string name){
    this->name = name;
}

/**
 * 
 * add description here
 * 
 * */
string black::getName(){
    return this->name;
}

/**
 * 
 * add description here
 * 
 * */
int black::getCardsPerCoin(int coins){
    int numCards = -1; // default to -1 : invalid 
    switch (coins)
    {
    case 1:
        numCards = 2;
        break;
    case 2:
        numCards = 4;
        break;
    case 3:
        numCards = 5;
        break;
    case 4:
        numCards = 6;
        break;
    default:
        cout << "(black) - Check the value of coins passed getCardsPerCoin. Value received : " << coins << endl;
        break;
    }

    return  numCards;
}

/**
 * 
 * add description here
 * 
 * */

void black::print(std::ostream& out){
    //TO DO
}

// Red
Red::Red(std::string name){
    this->name = name;
}

/**
 * 
 * add description here
 * 
 * */
string Red::getName(){
    return this->name;
}

/**
 * 
 * add description here
 * 
 * */
int Red::getCardsPerCoin(int coins){
    int numCards = -1; // default to -1 : invalid
    switch (coins)
    {
    case 1:
        numCards = 2;
        break;
    case 2:
        numCards = 3;
        break;
    case 3:
        numCards = 4;
        break;
    case 4:
        numCards = 5;
        break;
    default:
        cout << "(Red) - Check the value of coins passed getCardsPerCoin. Value received : " << coins << endl;
        break;
    }

    return  numCards;
}

/**
 * 
 * add description here
 * 
 * */

void Red::print(std::ostream& out){
    //TO DO
}

// garden
garden::garden(std::string name){
    this->name = name;
}

/**
 * 
 * add description here
 * 
 * */
string garden::getName(){
    return this->name;
}

/**
 * 
 * add description here
 * 
 * */
int garden::getCardsPerCoin(int coins){
    int numCards = -1; // default to -1 : invalid
    switch (coins)
    {
    case 1:
        numCards = 0;
        break;
    case 2:
        numCards = 2;
        break;
    case 3:
        numCards = 3;
        break;
    case 4:
        numCards = 0;
        break;
    default:
        cout << "(garden) - Check the value of coins passed getCardsPerCoin. Value received : " << coins << endl;
        break;
    }

    return  numCards;
}

/**
 * 
 * add description here
 * 
 * */

void garden::print(std::ostream& out){
    //TO DO
}
