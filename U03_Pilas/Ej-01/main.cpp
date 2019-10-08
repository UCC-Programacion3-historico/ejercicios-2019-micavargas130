#include <iostream>
#include "../Pila/Pila.h"

using namespace std;

int main() {
    char arr[100];
    Pila<char> A;

    cout << "Introduzca una palabra" << endl;
    cin >> arr;

    for (int i = 0; arr[i] != '\0'; i++) {
        A.push(arr[i]);
    }

    while (!A.esVacia()) {
        cout << A.pop();
    }

    return 0;
}