#ifndef TABLE_H
#define TABLE_H

#include "Player.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "TradeArea.h"

class Table{
    Player* p1;
    Player* p2;
    int currentPlayer; // id of the current player
    DiscardPile* dp;
    TradeArea* TradeAr;
    Deck* deck;
    
    public:
        Table(Player& p_one, Player& p_two, DiscardPile& d_pile, TradeArea& tr_arr, Deck& dck){
            p1 = &p_one;
            p2 = &p_two;
            dp = &d_pile;
            TradeAr = &tr_arr;
            deck = &dck;
        }
        bool win(std::string&);
        void printHand(bool);
        Player* getPlayer(int);
        friend std::ostream& operator<<( std::ostream&,  const Table& );
        // friend std::istream& operator>>( std::istream &input, const CardFactory* );

};

#endif