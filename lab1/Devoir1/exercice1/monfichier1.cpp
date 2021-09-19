/**
 *  Benjamin Kataliko Viranga 8842942
 *  Laboratoire 1 (Devoir 1) - Exercice 1
 *  CSI2772
 * */

#include "monfichier1.h"
// convertir un integer en octal
// return la valeur octal obtenue en int
// avec recursion
int convert_int_to_octal(int value){
    if(value == 0){
        return 0;
    }else{
        // ajouter les unites de maniere recursive en octal
        return value%8 + 10 * convert_int_to_octal(value/8);
    }
}

// decimal to octal sans recursion
int convert_int_to_octal_no_rec(int value){
    int octalValue = 0; 
    int value_divided_by_eight = value;  // initial value set at the given parameter 
    int unitPosition = 1;  // pour ajouter le decimal correspondant à la position adéquate

    while(value_divided_by_eight != 0){
        octalValue +=  (value_divided_by_eight% 8) * unitPosition;
        unitPosition *=  10;
        value_divided_by_eight /=8; // proceder à la prochaine division
    }

    return octalValue;
}

// convertir un integer en hexadecimal
// return la representation en string
string convert_int_to_hex(int value){
    char hex[100]; // un array de char 
    sprintf(hex, "%x", value); // utiliser la fonction sprintf() pour confirmer au format hexadecimal
    return hex;
}


string convert_int_to_hex_other(int value){
    string hexValues = "0123456789ABCDEF";
    int value_divided_by_sixteen =  value; // initially at value
    int unitPosition;
    string hex = ""; // return value
    
    while(value_divided_by_sixteen !=  0){
        // chercher l'index de la valeur correspondante dans le array de hex
        hex = hexValues[value_divided_by_sixteen%16] + hex;
        // proceder avec la division par 16
        value_divided_by_sixteen /= 16; 
    }

    return hex;

}

int main(){
    cout << "Taille en octets d'un caractère : " << sizeof(char) << endl;
    cout << "Taille en octets d'un entier : " << sizeof(int) << endl;
    cout << "Taille en octets d'un reel : " << sizeof(float) << endl;
    cout << "Taille en octets d'un double : " << sizeof(double) << endl;
    cout << "Taille en octets d'un entier court : " << sizeof(short int) << endl;
    cout << "Taille en octets d'un entier non signe : " << sizeof(unsigned int) << endl;

    float input_reel;
    int   input_entier;
    char  input_char;

    cout << "Entrer un entier :" ;
    cin >> input_entier;
    cout << "Affichage en octal :" << convert_int_to_octal(input_entier) << endl;
    cout << "Affichage en hexa :" << convert_int_to_hex(input_entier) << endl;

    cout << "Entrer un entier :" << endl;
    cin  >> input_entier;
    cout << "Affichage en octal :" << oct << input_entier << endl;
    // cout << "Affichage en octal :" << convert_int_to_octal_no_rec(input_entier) << endl; // autre possibilite

    cout << "Affichage en hexa :" << hex << input_entier << endl; 
    // cout << "Affichage en hexa :" << convert_int_to_hex_other(input_entier) << endl;  // autre possibilite 

    cout << "Entrer un reel :" ;
    cin  >> input_reel;
    cout << setprecision(3) << fixed << input_reel << endl; // sans notation scientifique
    cout << setprecision(3) << scientific << input_reel << endl; // avec notation scientifique 

    cout << "Entrer un caractere :";
    cin >> input_char;
    cout << input_char << endl;
    cout << hex << (int) input_char;


    return 0;
}