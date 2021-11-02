
class Table{
    public:
        bool win(std::string&);
        void printHand(bool);
        // friend ostream& operator<<( ostream &output );
        friend istream& operator>>( istream &input, const CardFactory* );

};