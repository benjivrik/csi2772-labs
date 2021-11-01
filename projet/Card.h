
#include <iostream>
#include <string.h>
using namespace std;

class Card{
    public:
    virtual int getCardsPerCoin(int coins);
    virtual string getName();
    virtual void print(ostream& out);
};

class Blue : public virtual Card {
    public:
        Blue();
        int getCardsPerCoin(int coins);
        string getName();
    // TO DO
};
class Chili : public virtual Card {
    // TO DO
    public:
        Chili();
        int getCardsPerCoin(int coins);
        string getName();
};
class Stink : public virtual Card {
    // TO DO
    public:
        Stink();
        int getCardsPerCoin(int coins);
        string getName();
};
class Green : public virtual Card {
    // TO DO
    public:
        Green();
        int getCardsPerCoin(int coins);
        string getName();
};
class soy : public virtual Card {
    // TO DO
    public:
        soy();
        int getCardsPerCoin(int coins);
        string getName();
};
class black : public virtual Card {
    // TO DO
    public:
        black();
        int getCardsPerCoin(int coins);
        string getName();
};
class garden : public virtual Card {
    // TO DO
    public:
        garden();
        int getCardsPerCoin(int coins);
        string getName();
};