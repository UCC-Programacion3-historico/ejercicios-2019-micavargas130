#include <iostream>
#include "../Cola/Cola.h"
using namespace std;
int main() {
    Cola<int> A;
    Cola<int> B;
    std::cout << "Ejercicio 04/01\n" << std::endl;
    int ea, eb, c=0, i=0;
    int a = 0, b=0;


     do {
        a++;
        cout << "Ingrese elmentos para COLA 1:";
        cin >> ea;
        A.encolar(ea);
    }while (ea != 00);

     do {
        b++;
        cout << "Ingrese elmentos para COLA 2:";
        cin >> eb;
        B.encolar(eb);

    }while (eb != 00);

    if (a == b) {
        cout << "COLA 1 y COLA 2 tienen el mismo largo" << endl;
        while (i<b){
            i++;

            if (A.peek()==B.peek())
            {
                A.desencolar();
                B.desencolar();
                c++;}
        }

                if (c != b) { cout << "LAS DOS COLAS SON DIFERENTES"; }
                else {cout << "LAS DOS COLAS SON IDENTICAS";}



    }


}