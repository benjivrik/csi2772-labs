//*monfichier3b.cpp : Ex3b Devoir1 CSI2772A*/
/**
 *  Laboratoire 1 (Devoir 1) - Exercice 3 (b)
 *  CSI2772
 * */


#include <iostream>
#include <vector>

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


/* Fonction trier avec passage Par reference
**
*/
void trier(vector<int>& T) {

	// vecteur temporaire utilisee dans la fonction.
	vector<int> temp_vec(T.size(), 0);
	vector<int>::iterator iter ;  // pour parcourir le vecteur
	int max_idx; // used in loop below
	int index_to_add = T.size()-1; // start adding items from this position
	int imax =  T.size() - 1;

	// copier les element de la reference dans le vecteur temporaire
	for(int i = 0; i <  T.size(); i++){
		temp_vec[i] = T[i];
	}
	
	while(imax > 0){
		iter = temp_vec.begin(); // iterateur mis à la position initial
		// rechercher la valeur maximale du tableau
	    max_idx = rechercheIndex(temp_vec, imax);
		T[index_to_add--] = temp_vec[max_idx]; // ajouter l'element correspondant dans la reference
	    iter += max_idx; // bouger l'iterateur à la position désirée
		temp_vec.erase(iter);   // remove the element found in the previous search
		imax--;   // decrementer la position d'ajout, car on supprime un élément à chaque loop dans le temp_evc
	}

    // add the last element in the vector
	max_idx =  imax;
	T[index_to_add] = temp_vec[max_idx];

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

/* Fonction principale main
**
*/
int main() {
	vector<int> tab;
	tab = saisieTab();
	cout << "Les valeurs de mon tableau sont : ";
	for (int i = 0; i < tab.size(); i++) {
		cout << "\n" << tab[i];

	}
	cout << "\n";
	trier(tab);
	cout << "\nLes valeurs de mon tableau trie sont : ";
	for (int i = 0; i < tab.size(); i++) {
		cout << "\n" << tab[i];

	}

}


