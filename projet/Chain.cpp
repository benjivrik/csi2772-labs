#include "headers/Chain.h"

/**
 * @brief retourne le nombre de cartes dans le deck
 * 
 * @return int 
 */
int Chain_Base::getSize(){
    return chain.size();
}

/**
 * @brief Set the ChainType of the Chain_Base
 * 
 * @param chainType 
 */
void Chain_Base::setChainType(std::string chainType){
    chainType = chainType;
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
    std::string line;
    Card* card = nullptr;
    int count = 0;
    while (std::getline(input, line))
    {
        std::istringstream iss(line);
        std::string data;
        if (!(iss >> data)) { 
            // std::cout<< "Empty" <<std::endl;
            continue;
        } 
        // std::cout << data << std::endl; //debug purpose
        count++;
        if(data == "B")       card = new Blue;
        else if(data == "C")  card = new Chili;
        else if(data == "S")  card = new Stink;
        else if(data == "G")  card = new Green;
        else if(data == "s")  card = new soy;
        else if(data == "b")  card = new black;
        else if(data == "R")  card = new Red;
        else if(data == "g")  card = new garden;
        else {
            std::cout << "(Chain Constructor) Check the card name in the file. Value received : " << data << std::endl;
            exit(1);
        }
        //
        if(card != nullptr) (*this)+=card;

    }

    std::cout << "Chain with " << count << " cards initialized from file properly." <<std::endl;
}

/**
 * @brief  counts the number cards in the current chain and returns the number coins 
according to the function Card::getCardsPerCoin
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
 * @brief write chain inside a file
 * 
 * @tparam T 
 * @param filename 
 */
void Chain_Base::saveChain(std::ofstream& filename){
    // std::cout << "Chain Type (Chain)" <<  chainType << std::endl; // Debug purpose
    filename << std::endl << chainType << std::endl;
    for(int i = 0; i < chain.size() ; i++){
        chain.at(i)->saveCard(filename);
        filename << std::endl;
    }

    std::cout << "Chain saved." << std::endl;
}

/**
 * @brief insertion operator to display the chain information
 * 
 * @param output 
 * @param d 
 * @return std::ostream& 
 */
std::ostream& operator<<( std::ostream &output, const Chain<Card*> & d ){
    output << d.chainType << " ";
    for(int i = 0; i < d.chain.size(); i++){
        d.chain.at(i)->print(output);
        output << " ";
    }
    
    return output;
};




/**
 * @brief insertion operator display the chain_base information
 * 
 * @param output 
 * @param d 
 * @return std::ostream& 
 */
std::ostream& operator<<( std::ostream &output, const Chain_Base & d ){
    output << d.chainType << " ";
    for(int i = 0; i < d.chain.size(); i++){
        d.chain.at(i)->print(output);
        output << " ";
    }
    
    return output;
}