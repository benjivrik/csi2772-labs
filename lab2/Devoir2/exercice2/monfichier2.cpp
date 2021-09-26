/*MonFichier2.cpp : Ex2 Devoir2 CSI2772A*/

#include "monfichier2.h"

int main() {
	int monTab[size_tab] = { 2,4,8,20,3,55,87,13,2,5 };

	cout << "Affichage du tableau non trie :" << endl;
	for (int i = 0;i < size_tab;i++) {
		cout << monTab[i] << endl;
	}
	trier(monTab, size_tab);
	cout << "\nAffichage du tableau trie :" << endl;
	for (int i = 0;i < size_tab;i++) {
		cout << monTab[i] << endl;
	}
}

void trier(int tab[], int size)
{

    int ref_value; //  valeur a l'index de reference

    for(int i = 1; i < size; i++){
        
        int k; // initialize the index before the reference

        // initialiser la valeur de comparaison
        ref_value = tab[i];

        // comparer les elements avant l'index de reference
        for(k = i-1; k >= 0; k--){
            if(tab[k] > ref_value){
                tab[k+1] = tab[k]; // deplacer les elements superieur a la reference
            }else{
                break; // stop the for loop if tab[k] < ref_value
            }   
        }

        // initializer le ref_value a la position adequate
        tab[k+1] =  ref_value;

    }
}
