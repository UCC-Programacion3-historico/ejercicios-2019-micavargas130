#include <iostream>
#include "../Lista/Lista.h"
using namespace std;
int main() {
    int d, n, p;
    std::cout << "Ejercicio 01/02\n" << std::endl;
    Lista <int> A;
    cout<<"1=ingresar al principio"; "  2=Ingresar en una posicion"; "  3=ingresar atras";
    cin>>d;

    if (d==1)
    {cin>>n;
    A.insertarPrimero(n)}

    else if (d==2)
    {cin>>n;
    cout<<"ingrese posicion:";
    cin>>p;
    A.insertar(p,n);}

    else if (d==3)
    {
        cin>>n;
        A.insertarUltimo(n);
    }
    return 0;
}