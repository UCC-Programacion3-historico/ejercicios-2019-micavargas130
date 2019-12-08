#include <iostream>
#include "../Arbol/ArbolBinarioAVL.h"
using namespace std;

int main() {
    std::cout << "Ejercicio 05/02\n" << std::endl;
    int n;
    ArbolBinarioAVL<int> A;

    for (int i=0; i<5; i++)
    {std::cin>>n;
     A.put(n);}

    A.print();

    cout<<endl;
   A.ImagenEspecular();

   A.print();

}
