#include <iostream>
using namespace std;
#include "../Lista/Lista.h"
#include "../Lista/nodo.h"
#ifndef FNINVIERTE_H
#define FNINVIERTE_H


//template <class T>
//void fnInvierte (Lista<T> *lis) {



template <class T>
void fnInvierte (Lista<T> *lis){

    int b=lis->getTamanio();
    for (int i=0; i<(b/2); i++)
    {
        lis->moverUlti(i);
        b--;
        lis->moverPri(lis->getDato(b));
    }
}





#endif //FNINVIERTE_H
