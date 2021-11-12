#include "Chain.h"

/**
 * @brief 
 * 
 * @return int 
 */
int Chain_Base::getSize(){
    return chain.size();
}

/**
 * @brief Get the Chain Type 
 * 
 * @return std::string 
 */
std::string Chain_Base::getChainType(){
    return chainType;
}
/**
 * @brief Construct a new Chain< T>:: Chain object
 * 
 * @tparam T 
 * @param input 
 * @param cf 
 */
template <typename T> 
Chain<T>::Chain(std::istream& input, const CardFactory* cf){
    // TO DO
}

/**
 * @brief // add description here
 * 
 * @tparam T 
 * @return int 
 */
template <typename T> 
int Chain<T>::sell(){
    T elem; // initialize a card item to access the method getCardsPerCoin
    int value = 0;
    int max_coins = 4;
    if(chain.size() > 0){
        // check the coin value;
        for(int coin = 1;  coin <= max_coins; coin++ ){
            if(chain.size() == elem.getCardsPerCoin(coin)){
                value  = coin;
                break;
            }else if (chain.size() < elem.getCarsPerCoin(coin)){
                value = coin-1;  // get the lower value for the coin
                break;
            }
        }
    }
    return value;
}

/**
 * @brief 
 * 
 * @param output 
 * @param d 
 * @return std::ostream& 
 */
std::ostream& operator<<( std::ostream &output, const Chain<Card*> & d ){

    output << d.chain.at(0)->getName() << " ";
    for(int i = 0; i < d.chain.size(); i++){
        d.chain.at(i)->print(output);
        output << " ";
    }

    return output;
};
