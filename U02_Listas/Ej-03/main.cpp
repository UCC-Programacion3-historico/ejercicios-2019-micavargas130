#include <iostream>
#include "../Lista/Lista.h"
using namespace std;
int main() {
    Lista <int> A;
    int e;
    std::cout << "Ejercicio 01/03\n" << std::endl;
    cout<<"ingrese posicion del elemento que desea eliminar";
    cin>>e;
    A.remover(e);
    return 0;

}