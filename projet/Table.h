#ifndef TABLE_H
#define TABLE_H

#include "Player.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "TradeArea.h"

class Table{
    Player p1;
    Player p2;
    DiscardPile dp;
    TradeArea TradeAr;
    public:
        bool win(std::string&);
        void printHand(bool);
        // friend ostream& operator<<( ostream &output );
        friend istream& operator>>( istream &input, const CardFactory* );

};

#endif