#include "headers/Card.h"
using namespace std;

// Card

/**
 * @brief Destroy the Card:: Card object
 * 
 */
Card::~Card() {}

/**
 * @brief Construct a new Blue:: Blue object
 * 
 * @param name 
 */
Blue::Blue(std::string name){
    this->name = name;
}
/**
 * @brief 
 * 
 * @param coins 
 * @return int 
 */
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
 * @brief 
 * 
 * @return string 
 */
string Blue::getName(){
    return this->name;
}

/**
 * @brief 
 * 
 * @param out 
 */
void Blue::print(std::ostream& out){
    out << this->getName()[0] << std::endl;
}

/**
 * @brief Construct a new Chili:: Chili object
 * 
 * @param name 
 */
Chili::Chili(std::string name){
    this->name = name;
}

/**
 * @brief 
 * 
 * @return string 
 */
string Chili::getName(){
    return this->name;
}

/**
 * @brief 
 * 
 * @param coins 
 * @return int 
 */
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
 * @brief 
 * 
 * @param out 
 */
void Chili::print(std::ostream& out){
    out << this->getName()[0] << std::endl;
}

/**
 * @brief Construct a new Stink:: Stink object
 * 
 * @param name 
 */
Stink::Stink(std::string name){
    this->name = name;
}

/**
 * @brief 
 * 
 * @return string 
 */
string Stink::getName(){
    return this->name;
}


/**
 * @brief 
 * 
 * @param coins 
 * @return int 
 */
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
 * @brief 
 * 
 * @param out 
 */
void Stink::print(std::ostream& out){
    out << this->getName()[0] << std::endl;
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
    out << this->getName()[0] << std::endl;
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
    out << this->getName()[0] << std::endl;
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
    out << this->getName()[0] << std::endl;
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
    out << this->getName()[0] << std::endl;
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
   out << this->getName()[0] ;
}


/**
 * @brief 
 * 
 */
std::ostream& operator << (std::ostream& out, Card& card) 
{ 
    card.print(out);
    return out; 
} 


/**
 * 
 * @brief write the card inside a file
 * 
 */
void Card::saveCard(std::ofstream& filename){
    filename << *this;
}