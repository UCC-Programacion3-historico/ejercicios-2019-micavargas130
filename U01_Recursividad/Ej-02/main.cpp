#include <iostream>
#include "sumatoria.h"
using  namespace std;
int main() {
    std::cout << "Ejercicio 01/02\n" << std::endl;
    int *arr;
    int n;

    cout<<"ingrese largo del arreglo"<<endl;
    cin>>n;

    arr= new int [n];

    for (int i=0; i<n; i++)
    {cin>>arr[i];}

    cout<<"\nla suma es:";
    cout<<sumatoria(arr,n);


    return 0;
}