
class Hand{
    public:
        Hand();
        Hand& operator+=(Card *);
        Card* play();
        Card* top();
        Card* operator[](int);
        // friend ostream& operator<<( ostream &output );
        friend istream& operator>>( istream &input, const CardFactory* );

};
