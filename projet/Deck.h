#include <iostream>
#include <string.h>
#include <vector>
#include <Card.h>
using namespace std;

template <typename T = Card> class Deck: public std::vector<T>{
     public :
        const int NUMBER_OF_CARDS;
        Deck();
        T* draw();
        friend ostream& operator<<( ostream &output );
        friend istream& operator>>( istream &input );
};