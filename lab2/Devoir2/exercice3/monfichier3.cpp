/*MonFichier3.cpp : Ex3 Devoir2 CSI2772A*/

#include <iostream>
using namespace std;

int** triangleInf(int n)
{
	static int matrix[100][100]; // garder la trace du tableau

	for(int i = 0; i < n; i++){
		for(int p = 0; p < n; p++){
			if(p==0){
				matrix[i][p] = 1;
			}else{
				if(p > i){
					matrix[i][p] = 0;
				}else{
                    matrix[i][p] = matrix[i-1][p-1] + matrix[i-1][p];
				}
			}
		}
	}
    // iniialiser le tableau de pointeur
	static int* row_pointer[100];

	for(int i = 0; i < n; i++){
		row_pointer[i] = matrix[i];
	}


	return row_pointer;
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
