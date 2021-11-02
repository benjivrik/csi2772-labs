class TradeArea{
     public:
        TradeArea();
        TradeArea(istream&, const CardFactory*);
        TradeArea& operator+=(Card*);
        bool legal(Card*);
        Card* trade(string);
        int numCards();
        // friend ostream& operator<<( ostream &output );
        friend istream& operator>>( istream &input, const CardFactory* );
};