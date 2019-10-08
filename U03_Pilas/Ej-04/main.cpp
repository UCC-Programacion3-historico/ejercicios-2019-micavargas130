#include <iostream>
#include "../Pila/Pila.h"
using namespace std;

int main() {
    std::cout << "Ejercicio 03/04\n" << std::endl;
    Pila <float> A;

    int c= 0;
    int e=0;
    char m;
    int n;

    cout<<"ingrese cantidad de caracteres";
    cin>>n;

    for (int i=0; i<n;i++)
    {
    cout<<"ingrese expresion matematica"<<endl;
    cin>>m;
    A.push(m);
    e++;



    if (m==40 || m==91 || m==125)
     c++; }

    for (int i=0; i<e;i++)
    {
        int tope=A.pop();
        if (tope==41|| tope==93 || tope==123)
        {c--;}

    }

    if (c==0) cout<<"TODOS LOS SIGNOS ESTAN BALANCEADOS";
    else cout<<"HAY SIGNOS SIN CERRAR";
}





