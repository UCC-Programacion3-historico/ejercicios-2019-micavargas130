#include <iostream>

using namespace std;

void shellsort(float v[], int n) {
    int salto = n / 2;
    float aux;
    while (salto > 0) {
        for (int i = salto; i < n; ++i) {
            int j = i - salto;
            while (j >= 0) {
                int k = j + salto;
                if (v[j] <= v[k])
                    j = -1;
                else {
                    aux = v[j];
                    v[j] = v[j + 1];
                    v[j + 1] = aux;
                    j -= salto;
                }
            }
        }
        salto = salto / 2;
    }
}

int main() {
    float v[10] = {5.2, 10, 6.5, 1.2, 8.7, 2.9, 4, 7.1, 0.5, 1};
    cout << "Ordenamiento por Shellsort" << endl;
    shellsort(v, 10);
    for (int i = 0; i < 10; ++i) {
        cout << v[i] << endl;
    }
}
