
#include <iostream>
#include "../Ej-02/Pila.h"
#include "../Cola/Cola.h"
using namespace std;

int main() {
    Pila<char> A;
    Cola<char> B;
    char palabra= ' ';

    bool b = true;

    std::cout << "Ejercicio 04/02\n" << std::endl;
    cout << "Ingrese frase (pulse 0 para detener): ";

    B.encolar('0'); //debe enconlar 0 para que no lo cuente luego
    while (palabra != '0'){

        cin>>palabra;
        A.push(palabra);
        B.encolar(palabra);
    }

    while (!A.esVacia() && b)
    {b= A.pop() == B.desencolar();}

    if (b) {cout << "\nEs un polidromo"; }

    else { cout << "\nNo es un palidromo"; }


    return 0;


}