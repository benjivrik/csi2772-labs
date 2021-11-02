
class DiscardPile{
    public:
        DiscardPile();
        DiscardPile(istream&, const CardFactory*);
        DiscardPile& operator+=(Card*);
        Card* pickUp();
        Card* top();
        void print(std::ostream&);
         // friend ostream& operator<<( ostream &output );
        friend istream& operator>>( istream &input, const CardFactory* );
};