
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
        void setChainType(std::string chainType);
        void saveChain(std::ofstream& filename);
        Chain_Base& operator+=(Card* card){

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
        /**
         * @brief Construct a new Chain object
         * 
         */
        Chain(){ 
            chainType = typeid(T).name();
            if(std::isdigit(chainType.at(0)) ){
                // std::cout<< "The collected digit is : " << chainType.at(0) << std::endl; // debug purpose
                chainType =  chainType.substr(1,chainType.size()); // remove the first unexpected digit in the type name
            }
        };
        Chain(std::istream&, const CardFactory*);
        /**
         * @brief add the card to the chain using the operator+=
         * 
         * @param card 
         * @return Chain<T>& 
         */
        Chain<T>& operator+=(Card* card){

            if(getSize() == 0)
               chainType = typeid(card).name();// update the chain type

            // std::cout << "(Chain.h) chainType : " << chainType << std::endl; // debug purpose
            if(typeid(T) == typeid(card) ){
                chain.push_back(card);
                return *this;
            } 
            else throw "IllegalType";
        };
        int sell();
        friend std::ostream& operator<<( std::ostream &output, const Chain<Card*> & d );
        
};

#endif