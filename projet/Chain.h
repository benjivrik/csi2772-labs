
template <typename T = Card> class Chain_Base :  public std::vector<T>{
    public:
        Chain_Base();

};

// template <typename T = Card> class Chain : public virtual Chain_Base<T>{
class Chain{
    // TO DO
    public:
        Chain(istream&, const CardFactory*);
        // Chain<T>& operator+=(Card*);
        int sell();
};