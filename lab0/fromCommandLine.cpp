#include<iostream>
#include<iomanip>
#include <Stdlib.h>

using namespace std;

int main(int nbre, char* arg[]) {
    if(nbre< 2) {
        cout << endl <<"Vous devez donner au moins un argument !!!!"<<endl;
        exit(2);
    }
    for(int i = 0;i < nbre;i++) {
        cout <<endl <<"L'argument  numero "<<i<<" est "<<arg[i];
    }
    return(0);
}