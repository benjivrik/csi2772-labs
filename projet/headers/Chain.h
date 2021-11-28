
#ifndef CHAIN_H
#define CHAIN_H

#include <vector>
#include <typeinfo>
#include <sstream>
#include <cstdlib>
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
        Chain_Base& operator+=(Card* card){
            if(getSize() == 0)
               chainType = typeid(card).name();// update the chain type

            // std::cout << "(Chain_Base.h) chainType : " << chainType << std::endl; // debug purpose
            chain.push_back(card);
            return *this;
        };
        friend std::ostream& operator<<( std::ostream &output, const Chain_Base & d );
};

// template <typename T = Card> class Chain : public virtual Chain_Base<T>{
template <typename T = Card> 
class Chain : public virtual Chain_Base{
    public:
        Chain(){ 
            chainType = typeid(T).name();
            // std::cout << "(Chain_Base.h) chainType : " << chainType << std::endl; // debug purpose
        };
        Chain(std::istream&, const CardFactory*);
        // add the card to the chain using the operator+=
        Chain<T>& operator+=(Card* card){

            if(getSize() == 0)
               chainType = typeid(card).name();// update the chain type

            // std::cout << "(Chain.h) chainType : " << chainType << std::endl; // debug purpose
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