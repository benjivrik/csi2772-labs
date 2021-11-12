#ifndef TABLE_H
#define TABLE_H

#include "Player.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "TradeArea.h"

class Table{
    Player* p1;
    Player* p2;
    DiscardPile* dp;
    TradeArea* TradeAr;
    public:
        Table(Player& p_one, Player& p_two, DiscardPile& d_pile, TradeArea& tr_arr){
            p1 = &p_one;
            p2 = &p_two;
            dp = &d_pile;
            TradeAr = &tr_arr;
        }
        bool win(std::string&);
        void printHand(bool);
        // friend ostream& operator<<( ostream &output );
        // friend std::istream& operator>>( std::istream &input, const CardFactory* );

};

#endif