/*Ex2 devoir4 CSI2772A*/


#include <iostream> 
#include "myFile2.h"
using namespace std;


// definition de la classe SetInt
SetInt::SetInt(int tab[] , int size){
    this->elem = new int[size];
    int* elem_cpy =  this->elem;
    for(int i = 0; i < size; i++){
        *(elem_cpy+i) = tab[i];  // copie des elts du tableau dans l'ensemble
    }
    this->size = size;
}

SetInt::~SetInt(){
    delete elem;
}

SetInt::SetInt(const SetInt& v){
    int* elem_v_cpy = v.elem;
    this->size = v.size;
     this->elem = new int[this->size]; // allocate a new array
    for(int i = 0 ; i < this->size; i++){ // copy the elements
        *(this->elem+i) = *(elem_v_cpy+i);
    }
}

void SetInt::add(int value){
    // iterate to check if the elem does not already exist
    bool elem_found = false; 
    int current_size = this -> size; // current_size
    int * new_array;

    // verifier si l'element existe deja
    for(int i = 0 ; i < current_size; i++){
        if( *(this->elem+i) == value )
            elem_found = true;
    }


    if(!elem_found){ // ajouter l'element si inexistant

       new_array = new int[++this->size];
       // get the old element from elem before the update
       for(int i = 0 ; i < current_size; i++){
           new_array[i] = this->elem[i];
       }
       new_array[current_size] = value;
       this->elem = new_array;
    }

}

void SetInt::remove(int value){
    if(this->size != 0) {
        int saved_index = -1; // index ou l'element retirE se trouvait
        for(int i = 0;  i < this->size; i++){
            if(*(this->elem+i) == value){
                saved_index = i;  // get the index of the element
            }
        }
        if(saved_index != -1){ // the element was found in the set
            // move up all the elements that happened to be after the remove element
            // if saved_index was not at the last index
            for(int i = saved_index;  i < this->size-1; i++){
                *(this->elem+i) = *(this->elem+i+1); // get the next element and assign it to the previous spot
            }
            
            this->size--; // decrease the number of element
        }else{
            cout << "The element " << value << " was not found in the set." << endl;
        }
   
    }else{
        cout << "There is no element to remove. The list is empty." <<endl;
    }


}

int SetInt::nbElem(){
    return this->size;
}

int* SetInt::tabElem(){
    int* tab;
    if(this->size == 0) tab = NULL; // retourner NULL si la liste est vide
    else {
       tab = new int[this->size];
       for(int i = 0;  i < this->size; i++){
           tab[i] = *(this->elem + i);
       }
    }

    return tab;
}

bool SetInt::contains(int value){
    bool elem_found = false; 

    for(int i = 0 ; i < this->size; i++){
        if( *(this->elem+i) == value )
            elem_found = true;
    }

    return elem_found;
}

bool SetInt::containsIn(int n, int& pos){
    bool elem_found = false; 

    for(int i = 0 ; i < this->size; i++){
        if( ( i == pos) && ( *(this->elem+i) == n) )
            elem_found = true;
    }

    return elem_found;
}

int main() {
    SetInt a; 	// object creation
    int* tab;

    while (a.nbElem() < 5)
    {
        cout << "add an int element" << endl;
        int elem;
        cin >> elem;
        a.add(elem);

    }
    cout << "a contains 10 :" << a.contains(10) << endl;
    cout << "remove 10 " << endl;
    a.remove(10);
    cout << "a contains 10 :" << a.contains(10) << endl;
    cout << "a contains :" << a.nbElem() << " elements " << endl;
    tab = a.tabElem();
    cout << "Les elements de a sont :" << endl;
    for (int i =0; i<a.nbElem(); i++)
        cout << tab[i] << endl;

    return 0;
}