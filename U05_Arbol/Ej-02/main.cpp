#include <iostream>
#include "../Arbol/ArbolBinarioAVL.h"
using namespace std;
int main() {
    std::cout << "Ejercicio 05/02\n" << std::endl;

    ArbolBinarioAVL<int> A;

    int n,dato;
    cout<<"ingrese cantidad de elementos:";
    cin>>n;
    cout<<"ingrese elementos del arbol";
    for (int i=0; i<n; i++)
    {
        cin>>dato;
        A.put(dato);
    }
    cout<<"INORDER:"<<endl;
    A.inorder();
    cout<<"PREORDER:"<<endl;
    A.preorder();
    cout<<"POSTORDER:"<<endl;
    A.posorder();
}
