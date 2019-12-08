#include <iostream>
#include "../Pila/Pila.h"

int main() {
    char arr[10];
    Pila<char> P;

    std::cout << "Ingrese palabra" << std::endl;
    std::cin >> arr;
    for (int i = 0; arr[i] != '\0'; i++) {
        if (arr[i] >= 'a' && arr[i] <= 'z') {
            std::cout << arr[i];
        }
        if (arr[i] == ')') {
            while (P.peek() != '(') {
                std::cout << P.pop();
            }
            P.pop();       
        }
        try {
            if ((arr[i] == '+' || arr[i] == '-') && (P.peek() == '+' || P.peek() == '-')) {
                std::cout << P.pop();
                P.push(arr[i]);
            }
            if ((arr[i] == '*' || arr[i] == '/') && (P.peek() == '*' || P.peek() == '/')) {
                std::cout << P.pop();
                P.push(arr[i]);
            }
        } catch (int e) {
        }
        if (arr[i] == '(' || arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/' || arr[i] == '^')
            P.push(arr[i]);
    }
    while (!P.esVacia())
        std::cout << P.pop();

}
