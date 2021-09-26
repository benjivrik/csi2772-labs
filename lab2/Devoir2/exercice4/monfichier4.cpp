/*MonFichier4.cpp : Ex4 Devoir2 CSI2772A*/

#include "MonFichier4.h"

int main() {
	char* chaine[nb_ch];		//tableau de pointeurs sur caractere(s)
	char choix;			//variable pour le choix saisi dans menu()

	cout << endl << "Saisissez les 5 chaines de caracteres en les terminant par une tabulation et un retour chariot :" << endl;

	for (int i = 0;i < nb_ch;i++) {
		chaine[i] = new char[size_ch];	//reservation de memoire pour une chaine
		cin.getline(chaine[i], size_ch, '\t');	//saisie de la chaine
		cin.ignore(INT_MAX, '\n');		//on ignore les retours chariot
	}

	display(chaine, nb_ch);


	while (1) {
		choix = menu();

		switch (choix)
		{
		case '1':	display(chaine, nb_ch);
			break;
		case '2':	replace(chaine, nb_ch, size_ch);
			break;
		case '3':	trier(chaine, nb_ch);
			break;
		case '4':	exit(0);
		default:	break;
		}
	}
}





/********************************************************************************/
/* Fonction menu Fournie */
/********************************************************************************/
char menu(void)
{
	char choix;

	cout << endl << endl << "\t\tMenu" << endl << endl;
	cout << "1) Affichage des chaines de caracteres." << endl;
	cout << "2) Remplacement d'une chaine par une autre" << endl;
	cout << "3) Tri des chaines" << endl;
	cout << "4) Sortie du programme." << endl << endl;
	cout << "Votre choix :";
	cin >> choix;

	return(choix);

}

/********************************************************************************/
/*La fonction display qui affiche les chaines de caract�res*/
/********************************************************************************/
void display(char* tab[], int const& nbre)
{

	//VOTRE VIENT ICI
    string to_display = "";

    // copy initial address of the array to proceed with display
    char* tab_cpy[nbre];
    for(int idx = 0; idx < nbre; idx++){
       tab_cpy[idx] = tab[idx];
    }
    
    // afficher les strings
    for(int pos = 0; pos < nbre; pos++){
        while(*(tab[pos])){
            to_display += *(tab[pos]);
            *(tab[pos])++; // move pointer
        }
        cout << "La chaine " << pos << " est " << to_display << endl;
        to_display="";
    }

    // get the initial position of the pointers
    for(int idx = 0; idx < nbre; idx++){
       tab[idx] = tab_cpy[idx];
    }
    
}

/*************************************************************/
/*La fonction replace qui remplace une chaine par une autre*/
void replace(char* tab[], int const& nbre, int const& size)
{
	int numero;		//la chaine a modifier

	cout << endl << "Donnez le numero de la chaine a modifier: ";
	cin.ignore(INT_MAX, '\n');
	cin >> numero;


	//VOTRE VIENT ICI


    cout << endl << "Entrez votre nouvelle chaine en la terminant par une tabulation et un retour chariot : " << endl; // entrez votre nouvelle chaine
    delete tab[numero];
    tab[numero] = new char[size];
    cin.ignore(INT_MAX, '\n');		//on ignore les retours chariot
	cin.getline(tab[numero], size, '\t');	//saisie de la chaine

}

/********************************************************************************/
/*La fonction trier qui trie les chaines */
/********************************************************************************/
void trier(char* tab[], int const& nbre)
{
	//VOTRE VIENT ICI
    char* ref_value; //  valeur a l'index de reference

    for(int i = 1; i < nbre; i++){
        
        int k; // initialize the index before the reference

        // initialiser la valeur de comparaison
        ref_value = tab[i];

        // comparer les elements avant l'index de reference
        for(k = i-1; k >= 0; k--){
            if(strcmp(tab[k], ref_value) > 0){ // comparer les string
                tab[k+1] = tab[k]; // deplacer les elements superieur a la reference
            }else{
                break; // stop the for loop if tab[k] < ref_value
            }   
        }

        // initializer le ref_value a la position adequate
        tab[k+1] =  ref_value;

    }
}

