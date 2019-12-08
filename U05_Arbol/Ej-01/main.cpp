#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Arbol/ArbolBinarioAVL.h"
using namespace std;
int main() {
    std::cout << "Ejercicio 05/01\n" << std::endl;

    ArbolBinarioAVL<int> A;
    int numeros[31];

    int i, j;

    srand(time(nullptr));
    for (i=0; i<31; i++)
    {
        numeros[i]= (rand() % 400) + 100;
        A.put(numeros[i]);
    }

    cout<<"Numeros del arreglo:";
    for (i=0; i<30; i++)
    {
        cout<<numeros[i]<<endl;
    }

    cout<<"--------------------------";
    A.print();

}
