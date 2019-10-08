#include "../Lista/Lista.h"

#ifndef UNION_H
#define UNION_H


template<class T>
Lista<T> *unir(Lista<T> &lisA, Lista<T> &lisB) {

    Lista<T> A(lisA);

    for (int i=0; i<lisB.getTamanio();i++)
    {
        A.insertarUltimo(lisB.getDato(i));

    }

    return  A;
}


#endif //UNION_H
