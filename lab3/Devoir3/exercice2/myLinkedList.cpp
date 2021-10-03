/*Ex2 - Devoir 3 CSI2772A*/

#include "myLinkedList.h"

int main()
{
	Evaluation* first = NULL;	//Pointer on the first element of the list
						//the list is empty, so initialization to NULL
	int number = 0;			//number of elements in the linked  list 
	int choice;			//choice for the menu

	do
	{
		cout << endl << endl << "1) Display  of the complete linked list.\n";
		cout << "2) Insert an element\n";
		cout << "3) Remove an element.\n";
		cout << "4) Calculation of the class average.\n";
		cout << "5) Exit the program.\n" << endl << endl;
		cout << "Your choice ??:";
		cin >> choice;

		switch (choice)
		{
		case 1: display(first);
			break;
		case 2: first = add(first, number);
			break;
		case 3: first = remove(first, number);
			break;
		case 4: average(first, number);
			break;
		case 5: exit(0);
		default:
			break;
		}
	} while (1);
	return 0;
}



/*
*add() Function*
**/
Evaluation* add(Evaluation* p, int& number)
{
	// VOTRE CODE VIENT ICI
    // --
    Evaluation* cp = new Evaluation; // allocate number+1 evaluation
	Evaluation* cp_cpy = cp; // keep a copy of the reference of the beginning of the Evaluation array cp.

    Evaluation* toBeAdded = new Evaluation;
    int pos = 0;

    
    cout << "After which element you want to insert ? (0 for start) : ";
    cin >> pos;
    cout<< endl;
	// valider l'input
	while( (pos < 0) || (pos > number)) {
		cout << "The number can not be above the available number of items  ("<< number <<") or lower than zero." << endl;
		cout << "You entered " << pos << "." << endl;
		cout << "Please enter a valid number : ";
		cin  >> pos;
		cout << endl;
	}

    number++; // increase the number of the element since we are adding element

    cout << "Entering the item from the chained list." << endl;
    cout << "Enter the student : ";
    cin.ignore(INT_MAX, '\n');
    cin.getline(toBeAdded -> student, 20);
    cout << endl;
    cout << "Enter the grade : ";
	// cin.ignore(INT_MAX, '\n');
    cin  >> toBeAdded -> grade;
    cout << endl;

    for(int i = 0; i < number; i++)
	{
        if( i == pos ){ // inserer l'element

            strcpy( cp -> student, toBeAdded -> student); // copier le string de toBeAdded dans le array student
			(cp) -> grade = toBeAdded -> grade;
			delete toBeAdded;  // delete the allocated space
			cp -> next = new Evaluation;  // initialize a new node
			cp = cp -> next; // move the pointer
        } else { 
			// copy the items of the initial list 
            strcpy((cp) -> student,(p) -> student);
            (cp) -> grade = (p) -> grade;
			cp -> next = new Evaluation;
			cp = cp -> next;
			p = p -> next;

		}
    }

    // the last element should be null
	cp = cp_cpy;
	for(int i =0; i < number; i++){
		if(i == (number - 1)){
			cp -> next = NULL;  // doing this because the loop before is creating a new node for next for every iteration.
			break;
		}
		cp =  cp -> next;
	}

    delete p; // delete initial list


	return cp_cpy;
}


/**
*remove() Function*
**/

Evaluation* remove(Evaluation* p, int& number)
{
	//VOTRE CODE VIENT ICI
	Evaluation* cp_cpy = p; // keep initial reference
	Evaluation* previous; // element precedent
	int pos;
	int iter = 1;

	cout << "What is the number of the element, you want to delete : ";
	cin.ignore(INT_MAX, '\n');
	cin >> pos;
    cout << endl;
	if(number == 0)
	   cout << "There is no element to remove in the list."<< endl;
	else {
		while( (pos < 1) || (pos > number)) {
			cout << "The number can not be above the available number of items  ("<< number <<") or lower than 1." << endl;
			cout << "You entered " << pos << "." << endl;
			cout << "Please enter a valid number : ";
			cin  >> pos;
			cout << endl;
		}
	}

	//
	while(p  != NULL){
		if(iter == pos){

			if(pos == 1){
				// remove the first element
				cp_cpy = p->next;
				delete p;
				number--;
			}else{
				if(p->next != NULL) {
					previous -> next = p -> next; // bouger le pointeur
					delete p; // supprimer l'element pointE par p
				} 
				else {previous -> next = NULL;} 
				number--;
				
			}
			break;
		}
		previous = p;
		p = p -> next;
		iter++;
	}
     
	return cp_cpy;

}



/**
*display() Function *
**/
void display(Evaluation* p)
{
			
	//VOTRE CODE VIENT ICI
	Evaluation* tmp; 
	tmp = p;
	if( tmp == NULL)
		cout << "There is no element inside the list." << endl;
    else{
		while( tmp != NULL ){
			cout << "The student : " << tmp -> student << endl;
			cout << "The age is : "<< tmp -> grade << endl;
			tmp = tmp->next;
		}
	}
	
}



/**
*average() Function *
***/
int average(Evaluation* p, int const& nbre)
{
	//VOTRE CODE VIENT ICI
	Evaluation * tmp = p;
    double avg = 0;
	if(p == NULL) return 0; 
	while(tmp != NULL){
		avg += tmp -> grade;
		tmp = tmp -> next;
	}
    // average
	avg /= nbre;

	cout << "The average is : " << setprecision(2) << fixed  <<  avg <<  endl;
	

	return 1;
}






