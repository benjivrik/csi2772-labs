#include "DiscardPile.h"

template <typename T> Card* DiscardPile<T>::pickUp(){
    return (Card*) this->pop_back();
}

template <typename T> Card*  DiscardPile<T>::top(){
    return (Card*) this->front();
}

template <typename T> void  DiscardPile<T>::print(std::ostream& os){
    for(int i = 0; i < this->size(); i++){
        os << this->at(i)->getName() << std::endl;
    }
}

