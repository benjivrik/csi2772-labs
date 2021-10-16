
#include <iostream>
using namespace std;

#include "myFile.h"
#include "Card.h"
#include "CardsSet.h"
#include "Player.h"
void Card::write(){
	string card_color;
	string card_value;
	char buff[10]; // used in itoa() later below. 

	switch (this->col)
	{
	case club:
		/* code */
		card_color = "Clubs";
		break;
	case diamond:
		/* code */
		card_color = "Diamonds";
		break;
	case heart:
		/* code */
		card_color = "Hearts";
		break;
	case spade:
		/* code */
		card_color = "Spades";
		break;
	default:
	    cout << "Please check the card color in write() function. Something went wrong. " << endl;
		card_color = "???";
		break;
	}

	switch (this->val)
	{
	case 1 :
	    card_value = "Ace";
	    break;
	case 11:
		/* code */
        card_value = "Jack";
		break;
	case 12:
		/* code */
		card_value = "Queen";
		break;
	case 13:
		/* code */
		card_value = "King";
		break;
	default:
		itoa(this->val, buff, 10); // convert the value to string in char array
		card_value = string(buff); // convert the value to string
		break;
	}

	cout << card_value << " of " << card_color << endl;
}

//
void CardsSet::novSet(){
	int idx = 0;
    for( int c =  club; c <= spade; c = (color) (c+1) ){
       for(int f = 1 ; f <= 13; f++ ){
           set[idx++] = Card((color) c, f);
       }
    }
	
}

//
void CardsSet::shuffle(){
	int idx; 
	int num_shuffle_left = 52; // nombre de shuffle restant dans la loupe
	int array_size = 52;       // size of the array to shuffle
	Card temp_card; 
    srand(time(0)); // starting point for producing the random numbers
	while(num_shuffle_left-- > 0){
		idx =  rand() % array_size;    // get the position to swap
		temp_card = this->set[idx] ; // get the card at the generated index
		this->set[idx] =  set[num_shuffle_left-1]; // using num_shuffle_left as index for grabbing the card to swap in the array;
		set[num_shuffle_left-1] = temp_card; // swap element at num_shuffle_left-1 with the one at idx
	}

}

//
Card CardsSet::take(){

	int idx;
	int array_size = 52;
	Card to_return;
	srand(time(0));
	idx = rand() % array_size; // get the index of the card
	to_return = this->set[idx];
	cout << "You get Card : " ;
	to_return.write();
	cout << endl;
	number++;
    
	return to_return;
     
}
//
Card CardsSet::lookIn(int no){
	return this->set[no-1];
}

void CardsSet::put(Card k){
     
}
//
int Player::play(){
	// to do
	return 0;
}

int Player::countPoints(){
	// to do
	return 0;
}

//
int main() {
	CardsSet packet;
	Player you(packet, false);
	Player me(packet, true);
	char answer[3];
	bool continuous = true;
	cout << "Hello! " << endl;
	while (continuous)
	{
		cout << "A new game? " << endl;
		cin >> answer;
		continuous = answer[0] == 'y';
		if (continuous)
		{
			packet.novSet();
			packet.shuffle();
			packet.take();
			int p1 = you.play();
			if (p1 > 21) {
				cout << "You lost! " << endl;
			}
			else if (p1 == 21) {
				cout << "You won! " << endl;
			}
			else // the computer must play
			{
				int p2 = me.play();
				if (p2 <= 21 && p2 >= p1) {
					cout << "You lost! " << endl;
				}
				else {
					cout << "You won! " << endl;
				}
			}
		}
	}
	return 0;
}


