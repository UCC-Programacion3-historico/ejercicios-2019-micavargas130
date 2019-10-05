#include "../Lista/Lista.h"

#ifndef UNION_H
#define UNION_H


template<class T>
Lista<T> *unir(Lista<T> &lisA, Lista<T> &lisB) {

    Lista<T> temp(lisA);

    for (int i=0; i<lisB.getTamanio();i++)
    {
        temp.insertarUltimo(lisB.getDato(i));

    }

    return new Lista<T>(temp);
}


#endif //UNION_H
