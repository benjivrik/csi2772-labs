#include <iostream>

class Card{
    public:
    virtual int getCardsPerCoin(int coins);
    virtual std::string getName();
    virtual void print(std::ostream& out);
};

class Blue : public virtual Card {
    std::string name;
    public:
        Blue(std::string name = "Blue");
        int getCardsPerCoin(int coins);
        std::string getName();
    // TO DO
};
class Chili : public virtual Card {
    // TO DO
    std::string name;
    public:
        Chili(std::string name = "Chili");
        int getCardsPerCoin(int coins);
        std::string getName();
};
class Stink : public virtual Card {
    // TO DO
    std::string name;
    public:
        Stink(std::string name = "Stink");
        int getCardsPerCoin(int coins);
        std::string getName();
};
class Green : public virtual Card {
    // TO DO
    std::string name;
    public:
        Green(std::string name = "Green");
        int getCardsPerCoin(int coins);
        std::string getName();
};
class soy : public virtual Card {
    // TO DO
    std::string name;
    public:
        soy(std::string name="soy");
        int getCardsPerCoin(int coins);
        std::string getName();
};
class black : public virtual Card {
    // TO DO
    std::string name;
    public:
        black(std::string name= "black");
        int getCardsPerCoin(int coins);
        std::string getName();
};

class Red : public virtual Card {
    // TO DO
    std::string name;
    public:
        Red(std::string = "Red");
        int getCardsPerCoin(int coins);
        std::string getName();
};


class garden : public virtual Card {
    // TO DO
    std::string name;
    public:
        garden(std::string = "garden");
        int getCardsPerCoin(int coins);
        std::string getName();
};