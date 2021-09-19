/**
 *  Benjamin Kataliko Viranga 8842942
 *  Laboratoire 1 (Devoir 1) - Exercice 2
 *  CSI2772
 * */


/*Fonction principale main*/
#include "monfichier2.h"
int main(void) {
    char choix;
    int nvolume = 0;//nombre de fois que la fonction volume a été lancee 
    int nsurface = 0;//nombre de fois que la fonction surface a étélancee
    double rayon, hauteur;
    while(1){
        choix = menu();
        switch(choix){
            case '1':
              cout <<endl <<"Calcul de la surface :"<<endl;
              cout <<"Donnez le rayon: ";
              cin >>rayon;
              nsurface = surface(rayon);
              break;
            case '2':
              cout << endl << "Calcul du volume :"<<endl;
              cout << "Donnez le rayon: ";
              cin >> rayon;
              cout <<"Donnez la hauteur: ";
              cin >>hauteur;
              nvolume = volume(rayon, hauteur);
              break;
            case '3':
              cout <<endl <<"Sortie du programme"<<endl;
              cout <<"La fonction volume a ete lancee "<<nvolume <<" fois"<<endl;
              cout <<"La fonction surface a ete lancee "<<nsurface <<" fois"<<endl;
              exit(0);
            default: 
              break;
        }
    }
}

// surface - pi *r ^ 2
int surface(double const& ray){
    static int nsurface;
    cout << "La surface est : " << Pi*pow(ray,2) << endl;
    return ++nsurface; 
}

// volume - pi * r ^2 * h
int volume(double const& ray, double const& haut){
    static int nvolume;
    cout << "Le volume est " <<  Pi*pow(ray,2) * haut << endl;
    return ++nvolume;
}

/*Fonction menu() :Fonction qui affiche un menu d'option et retourne l'option choisie */
char menu(void){
    char choix;
    cout << endl;
    cout <<"Que souhaitez-vous faire ?:"<<endl;
    cout <<"\t-Calculer la surface du disque de rayon (Tapez 1)"<<endl;
    cout <<"\t-Calculer le volume du cylindre de rayon et hauteur (Tapez 2)"<<endl;
    cout <<"\t-Quittez le programme (Tapez 3)"<<endl ;
    cout <<"Votre choix: ";
    cin  >>choix;
    return (choix);
}
