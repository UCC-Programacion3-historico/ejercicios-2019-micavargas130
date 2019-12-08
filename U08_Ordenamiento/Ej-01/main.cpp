#include <iostream>

using namespace std;

void sortBubble(int v[], int tam) {
    int aux;
    for (int i = 0; i < tam; ++i) {
        for (int j = 0; j < tam-1; ++j) {
            if (v[j] > v[j+1]) {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}

int main() {
    int v[5] = {6, 3, 9, 2, 4};
    sortBubble(v, 5);
    for (int i = 0; i < 5; ++i) {
        cout << v[i] << endl;
    }
}
