/*MonFichier3.cpp : Ex3 Devoir2 CSI2772A*/

#include <iostream>
using namespace std;

int** triangleInf(int n)
{
	//VOTRE VIENT ICI
	int* data[n];
	for(int ligne = 0; ligne < n; ligne++){
		for(int p = 0; p < n ; p++){
			if(ligne == 0)
				*(data[ligne]) = 1;
			else{
				if(p > ligne) // 0 si p > n
					*(data[ligne]+p) = 0;
				else{
					// Valeur de (n-1, p-1) + valeur de (n-1, p) si 0 < p ≤n 
					*(data[ligne]+p) = *(data[ligne-1]+(p-1)) + *(data[ligne-1]+p); 
				}
			} 
		}
	}

    int** return_data = data; 

	return return_data;
}

int main() {
	int** tab;
	const int size = 10;
	tab = triangleInf(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j <= i; j++)
			cout << tab[i][j] << " ";
		cout << endl;
	}
}