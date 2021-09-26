/*MonFichier4.h : Ex4 Devoir2 CSI2772A*/

#include <iostream>
#include <process.h>		//necessaire a la fonction exit() 
#include <string.h>		//necessaire aux fonctions strcmp, strcpy..
#include <limits.h>		// pour la macro INT_MAX 
using namespace std;

const int size_ch = 20;		//taille maximale d'une chaine de caracteres
const int nb_ch = 5;		//Nombre de chaines traitees

void display(char* tab[], int const& nbre);			//affiche les chaines
char menu(void);						//affiche un menu et retourne le choix
void replace(char* tab[], int const& nbre, int const& size); 	//remplace une chaine par une autre
void trier(char* tab[], int const& nbre);				//tri par insertion

