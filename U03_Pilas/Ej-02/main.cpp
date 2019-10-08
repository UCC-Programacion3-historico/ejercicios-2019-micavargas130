#include <iostream>
#include "../Pila/Pila.h"
using namespace std;
int main() {
    std::cout << "Ejercicio 03/02\n" << std::endl;
    Pila<int> A;
    Pila<int> B;
    int arr;
    int s = 0,d=0;
    int c = 0;
    int i=0;

    do {
        cout << "ingrese elemetos (ingrese -1 para deternerse):" << endl;
        cin >> arr;
        A.push(arr);
        s++;
    } while (arr != -1);

    do {
        cout << "ingrese elemetos (ingrese -1 para deternerse):" << endl;
        cin >> arr;
        B.push(arr);
        c++;
    } while (arr != -1);

    if (s == c) { cout << "Las longitude de las listas son iguales"<<endl;

        while (i<c)
        { i++;
            if(A.peek() == B.peek())
            {   A.pop();
                B.pop();
                d++;}
        }
        if(d==c)
        cout<<"Las listas son iguales";
        else {cout<<"las listas son diferentes";}

    }
    else {
        cout << "las longitudes de las listas son diferentes";
    }



}