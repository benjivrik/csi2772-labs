
#ifndef CHAIN_H
#define CHAIN_H

#include <vector>
#include "Card.h"

class Chain_Base
    protected:
        vector<Card*>  chain;

    public:
        virtual int sell() = 0;
        int getSize(){return chain.size();}
  
};

// template <typename T = Card> class Chain : public virtual Chain_Base<T>{
template <typename T = Card> 
class Chain : public Chain_Base{
    // TO DO
    public:
        Chain(){};
        Chain(istream&, const CardFactory*);
        Chain<T>& operator+=(Card*);
        int sell();
        friend std::ostream& operator<<( std::ostream &output, const Chain<Card*> & d );
  
};

#endif