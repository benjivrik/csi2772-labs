#ifndef TRADEAREA_H
#define TRADEAREA_H

#include "Card.h"
#include <list>
#include <sstream>
#include <cstdlib>


class CardFactory;

class TradeArea{
     std::list<Card*> tradeAr; 
     public:
        TradeArea(){};
        TradeArea(std::istream& input, const CardFactory* cf){
            std::string line;
            Card* card = nullptr;
            int count = 0;
            while (std::getline(input, line))
            {
                std::istringstream iss(line);
                std::string data;
                if (!(iss >> data)) { 
                    // std::cout<< "Empty" <<std::endl;
                    continue;
                } 
                // std::cout << data << std::endl; //debug purpose
                count++;
                if(data == "B")       card = new Blue;
                else if(data == "C")  card = new Chili;
                else if(data == "S")  card = new Stink;
                else if(data == "G")  card = new Green;
                else if(data == "s")  card = new soy;
                else if(data == "b")  card = new black;
                else if(data == "R")  card = new Red;
                else if(data == "g")  card = new garden;
                else {
                    std::cout << "(TradeArea Constructor) Check the card name in the file. Value received : " << data << std::endl;
                    exit(1);
                }
                //
                if(card != nullptr) tradeAr.push_back(card);

            }

            std::cout << "TradeArea with " << count << " cards initialized from file properly." <<std::endl;
        };
        TradeArea& operator+=(Card* card){
             if(this->legal(card)){
                 tradeAr.push_back(card);
             }else{
                 std::cout<< "The card [" << card->getName() << "] can not be added to the Trade Area." << std::endl;
             }
             
             return *this;
        };
        bool legal(Card*);
        Card* trade(std::string);
        int numCards();
        friend std::ostream& operator<<( std::ostream&, const TradeArea&  );
        void saveTradeArea(std::ofstream& filename);

};

#endif