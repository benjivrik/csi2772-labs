
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
	    cout << "Please check the card color in write() function. Something went wrong. color: " << card_color << endl;
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
	number = 0;
    for( int c =  club; c <= spade; c = (color) (c+1) ){
       for(int f = 1 ; f <= 13; f++ ){
           set[idx++] = Card((color) c, f);
		   number++; // the number of item in the set
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
	Card to_return;
	//
	if(number > 0){
		to_return = this->set[--number];
		cout << "You get Card : ";
		to_return.write();
		cout << endl;
	}
		
	return to_return;
}

//
Card CardsSet::lookIn(int no){
	return this->set[no-1];
}
//
void CardsSet::put(Card k){
     this->set[number++] =  k; // add the card in the set
}
//
int Player::play(){
	bool add_card = true;
	char answer[3];
	int points = 0;

    // based on the implementation of take(). The total point seems to be calculated on the first packet.take() in the main() function.
	if(!this->computer){ 
		// get the initial card removed when the packet.take() is called in the main() function
		this->inHand.put(this->packet.lookIn(this->packet.numCards()+1)); // +1 since the number of card in the packet is decreased when packet.take() is called.
		//
		points = this->countPoints();
		cout << "Your score is " << points <<" points." <<endl;
	}else{
		cout << endl << "Computer is playing ..." << endl << endl;
	}
	// add card into the player hand
	while(add_card && points < 21){
		
		if(!this->computer) { // the human is playing
			cout << "Any additional card ?" << endl;
			cin >> answer;
	    	add_card = answer[0] == 'y';

			if(add_card){

				this->inHand.put(this->packet.take());
				// count the points in the hand
				points = this->countPoints();
				cout << "Your score is " << points <<" points." <<endl;

			}else{
				add_card = false;
			}
		}else{ // the computer is playing
			this->inHand.put(this->packet.take());
			// count the points in the hand
			points = this->countPoints();

			cout << endl << "Computer score is " << points <<" points." <<endl;

			// choose a random computer answer
			srand(time(0)); // starting point for producing the random numbers
			string possible_answer_str = "yn"; // idx 0 is y and idx 1 is 0
			//
			int idx_rep = rand()%2;

			// get the corresponding char for the computer add_card boolean
			answer[0] = possible_answer_str[idx_rep];

			add_card = answer[0] == 'y';
			
			if(add_card){

				this->inHand.put(this->packet.take());
				// count the points in the hand
				points = this->countPoints();

				cout << "Computer score is " << points <<" points." <<endl;

			}else{
				add_card = false;
			}

		}
	
	}

	this->inHand.empty(); // empty the number of card in the hand;

	if(this->computer) cout << endl <<  "Computer stopped playing..." << endl << endl;

	return points;
}

int Player::countPoints(){
	
	int total_points = 0;
	int number_of_Ace_card = 0;  // comptez le nombre de As trouvé pour évaluer les points

	// comptez les points

	for(int i = 1; i <= this->inHand.numCards() ; i++){
		Card current_card = this->inHand.lookIn(i); // get the corresponding card
		total_points += current_card.value();       // add the value
		if(current_card.value() == 1) number_of_Ace_card++; // an Ace card was found
	}

    // check if the number of point is higher the card Ace
	// si total points >= 21 le As compte pour 1 
	// sinon il compte pour 14
	if(total_points < 21)
	{
	   // remove the value 1 added in the total_points in the previous loop
       total_points -= 1*number_of_Ace_card; 
	   total_points += 14*number_of_Ace_card; // add the value 14 for the card Ace
	}

	return total_points;
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


