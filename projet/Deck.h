
template <typename T> class Deck: public std::vector<T>{
     public :
        const int NUMBER_OF_CARDS;
        Deck(int size=104);
        T* draw();
        // friend ostream& operator<<( ostream &output );
        // friend istream& operator>>( istream &input );
};