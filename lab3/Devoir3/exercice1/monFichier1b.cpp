/*Ex1a - Devoir 3 CSI2772A*/

#include <iostream>
using namespace std;

enum Color { club, diamond, spades, heart };
enum Face { seven, eight, nine, ten, jack, queen, king, ace };

struct Card
{
	Color color;
	Face face;
};

typedef Card Hand[5];

/* testPair() function*/
bool testPair(const Hand& h)
{
	// VOTRE CODE VIENT ICI
    bool pairFound =  false;

    // sizeof(h)/sizeof(h[0]) est la taille du tableau passe en reference
    for(int i = 0; i < sizeof(h)/sizeof(h[0]); i++){
        for(int j = 0; j < sizeof(h)/sizeof(h[0]); j++){
            if(i != j){
                if(h[i].face ==  h[j].face){
                    return true;
                }
            }
        }
    }
    return false;

}


/*Example of main()*/
int main()
{
	bool testPair(const Hand&);
	Hand myHand = { {club,nine}, {diamond, eight}, {spades, ace}, {spades, jack}, {club, ace} };
	cout << "\nI have at least: " << testPair(myHand) << "pair" << endl;
	return 0;
}



