#include <iostream>
using namespace std;
enum Color { club, diamond, spades, heart };
enum Face { seven, eight, nine, ten, jack, queen, king, ace };
struct Card{
    Color color;
    Face face;
};
int main(){
    
    Card game[32];

    //VOTRE CODE VIENT ICI
    int idx = 0; // index pour le tableau
    for( int c =  club; c <= heart; c = (Color) (c+1) ){
       for(int f = seven ; f <= ace; f = (Face) (f+1) ){
           game[idx].color = (Color) c;  // assigner la couleur
           game[idx++].face = (Face) f;  // assigner la face
       }
    }

    // Display the game array
    // for(int i = 0; i < 32; i++){
    //     cout << "idx : " << i << endl;
    //     cout << "Color : " << game[i].color << "- Face : " << game[i].face << endl;
    // }
}
