/*monfichier3a.cpp : Ex3a Devoir1 CSI2772A*/
/**
 *  Benjamin Kataliko Viranga 8842942
 *  Laboratoire 1 (Devoir 1) - Exercice 3 (a)
 *  CSI2772
 * */


#include <iostream>
# include <vector>

using namespace std;

/* Fonction de selection rechercheIndex qui renvoie l'indice de la valeur max d'un tableau
**
*/
int rechercheIndex(vector<int> T, int imax) {
	if (T.size() < imax - 1) {
		cout << "Erreur ! Tableau trop petit ! " << endl;
		return -1;
	}
	int res = 0;
	for (int i = 1; i <= imax;i++)
		if (T[i] > T[res]) res = i;
	return res;
}


/* Fonction saisieTab pour saisir les valeurs de votre tableau
**
*/
vector<int> saisieTab() {
	int taille;
	cout << " Entrer la taille de votre tableau: ";
	cin >> taille;
	vector<int> res(taille, 0);
	cout << " Saisir les valeurs de votre tableau: \n";
	for (int i = 0; i < taille; i++) {
		cout << " val[ " << i << "] =";
		cin >> res[i];
	}
	cout << "\n";
	return res;
}


/* Fonction trier avec Passage par valeur
**
*/ 
vector<int> trier(vector<int> T) {
	//VOTRE CODE VIENT ICI
	vector<int> to_return(T.size(), 0);
	vector<int>::iterator iter ;  // pour parcourir le vecteur
	int max_idx; // used in loop below
	int index_to_add = T.size()-1; // start adding items from this position
	int imax =  T.size() - 1;
	while(imax > 0){
		iter = T.begin(); // iterateur mis à la position initial
		// rechercher la valeur maximale du tableau
	    max_idx = rechercheIndex(T, imax);
		to_return[index_to_add--] = T[max_idx]; // ajouter l'element correspondant dans le nouveau vecteur
	    iter += max_idx; // bouger l'iterateur à la position désirée
		T.erase(iter);   // remove the element found in the previous search
		imax--;   // decrementer la position d'ajout, car on supprime un élément à chaque loop
	}

    // add the last element in the vector
	max_idx =  imax;
	to_return[index_to_add] = T[max_idx];

	return to_return;
}

/* Fonction principale main
**
*/
int main() {
	vector<int> tab;
	vector<int> tabTrie;
	tab = saisieTab();
	cout << "Les valeurs de mon tableau sont : ";
	for (int i = 0; i < tab.size(); i++) {
		cout << "\n" << tab[i];
	}
	cout << "\n";

	tabTrie = trier(tab);
	cout << "\nLes valeurs de mon tableau trie sont : ";
	for (int i = 0; i < tabTrie.size(); i++) {
		cout << "\n" << tabTrie[i];
		
	}

}



