
#ifndef CHAIN_H
#define CHAIN_H

#include <vector>
#include <typeinfo>
#include "Card.h"

class CardFactory;

class Chain_Base{
    protected:
        std::vector<Card*>  chain;

    public:
        virtual int sell() = 0;
        int getSize();
  
};

// template <typename T = Card> class Chain : public virtual Chain_Base<T>{
template <typename T = Card> 
class Chain : public virtual Chain_Base{
    // TO DO
    public:
        Chain(){};
        Chain(std::istream&, const CardFactory*);
        Chain<T>& operator+=(Card* card){
            if(typeid(T) == typeid(card) ){
                chain.push_back(card);
                return *this;
            } 
            else throw std::bad_exception("Illegal Type");
        };
        int sell();
        friend std::ostream& operator<<( std::ostream &output, const Chain<Card*> & d );
  
};

#endif