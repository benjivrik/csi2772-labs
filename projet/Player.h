#ifndef PLAYER_H
#define PLAYER_H

class Player{
    public:
        Player(std::string&);
        std::string getName();
        int getNumCoins();
        Player& operator+=(int);
        int getMaxNumChains();
        Chain& operator[](int i);
        void buyThirdChain();
        void printHand(std::ostream&, bool);
        
};

#endif 