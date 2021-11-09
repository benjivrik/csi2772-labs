#include <vector>
#include <iostream>


template <typename T> 
class DiscardPile:  public std::vector<T>{
    public:
        DiscardPile(): std::vector<T>(){};
        // DiscardPile(istream&, const CardFactory*): std::vector<T>();
        DiscardPile& operator+=(Card* c){
            this->push_back(c);
            return *this;
        };
        Card* pickUp();
        Card* top();
        void print(std::ostream&);
         // friend ostream& operator<<( ostream &output );
        // friend istream& operator>>( istream &input, const CardFactory* );
};