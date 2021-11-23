
#ifndef CHAIN_H
#define CHAIN_H

#include <vector>
#include <typeinfo>
#include "Card.h"

class CardFactory;

class Chain_Base{
    protected:
        std::vector<Card*>  chain;
        std::string chainType;
    public:
        int sell(){ return -1;}; // unimplemented
        int getSize();
        std::string getChainType();
        void saveChain(std::ofstream& filename);
  
};

// template <typename T = Card> class Chain : public virtual Chain_Base<T>{
template <typename T = Card> 
class Chain : public virtual Chain_Base{
    // TO DO
    public:
        Chain(){ chainType = typeid(T).name();};
        Chain(std::istream&, const CardFactory*);
        Chain<T>& operator+=(Card* card){

            if(getSize() == 0)
               chainType = typeid(card).name();// update the chain type

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