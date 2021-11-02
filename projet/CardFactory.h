class CardFactory{
    private:
        CardFactory();
        static CardFactory* instance;
    public:
        static CardFactory* getFactory();
        // Deck<Card> getType();
};