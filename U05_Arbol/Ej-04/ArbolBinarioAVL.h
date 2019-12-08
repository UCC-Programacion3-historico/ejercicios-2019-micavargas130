//
// Created by micav on 26/11/2019.
//

#ifndef PROGRAMACION3_ARBOLBINARIOAVL_H
#define PROGRAMACION3_ARBOLBINARIOAVL_H
#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

#include <stdexcept>
#include <iostream>
#include "NodoArbolAVL.h"
#include "../Arbol/Lista.h"


using namespace std;

template<class T>
class ArbolBinarioAVL {
private:

    T dato;
    NodoArbolAVL<T> *raiz;
    unsigned int tamanio;
    NodoArbolAVL<T> *a;
    int izq;
    int der;
    //Lista<T> li;
   // Lista<T> li2;


public:

    ArbolBinarioAVL();

    /**
     * Agrega un dato al árbol
     * @param clave Clave para agregar el dato
     * @param dato Dato a agregar
     */
    void put(T dato) {
        raiz = put(dato, raiz);
    }

    /**
     * Busca un dato en el árbol. Si no esta el dato en el árbol
     * tira una excepción
     * @param clave Valor a buscar
     * @return el valor buscado
     */
    T search(T dato) {
        return search(dato, raiz);
    }

    void remove(T dato);

    void preorder();

    void inorder();

    void postorder();

    ~ArbolBinarioAVL();

    NodoArbolAVL<T> *ImagenEspecular (){ return ImagenEspecular(raiz);}

    bool esVacio();

    void print();

    T contarPorNivel();

    int SumarHojas();

    T contarHastaNivel(int n);

    int chicoGrande();

private:

    NodoArbolAVL<T> *put(T dato, NodoArbolAVL<T> *r);

    int chicoGrande(NodoArbolAVL<T> *r);

    T search(T dato, NodoArbolAVL<T> *r);

    int contarPorNivel(NodoArbolAVL<T> *r);

    NodoArbolAVL<T> *ImagenEspecular (NodoArbolAVL<T> *r);

    void preorder(NodoArbolAVL<T> *r);

    void inorder(NodoArbolAVL<T> *r);

    int contarHastaNivel(NodoArbolAVL<T> *r,int n);

    void posorder(NodoArbolAVL<T> *r);

    NodoArbolAVL<T> *remove(T dato, NodoArbolAVL<T> *r);

    NodoArbolAVL<T> *buscarMax(NodoArbolAVL<T> *r, bool *encontre);

    int SumarHojas(NodoArbolAVL<T> *r);

    int altura(NodoArbolAVL<T> *r) {
        if (r == nullptr)
            return -1;
        else
            return r->altura;
    }

    NodoArbolAVL<T> *rotarIzq(NodoArbolAVL<T> *k2) {
        NodoArbolAVL<T> *k1 = k2->izq;
        k2->izq = k1->der;
        k1->der = k2;
        k2->altura = max(altura(k2->izq), altura(k2->der)) + 1;
        k1->altura = max(altura(k1->izq), k2->altura) + 1;
        return k1;
    }


    NodoArbolAVL<T> *rotarDer(NodoArbolAVL<T> *k1) {
        NodoArbolAVL<T> *k2 = k1->der;
        k1->der = k2->izq;
        k2->izq = k1;
        k1->altura = max(altura(k1->izq), altura(k1->der)) + 1;
        k2->altura = max(altura(k2->der), k1->altura) + 1;
        return k2;
    }

    NodoArbolAVL<T> *rotarDobleIzq(NodoArbolAVL<T> *k3) {
        k3->izq = rotarDer(k3->izq);
        return rotarIzq(k3);
    }

    NodoArbolAVL<T> *rotarDobleDer(NodoArbolAVL<T> *k1) {
        k1->der = rotarIzq(k1->der);
        return rotarDer(k1);
    }

    int max(int a, int b) {
        if (a > b)
            return a;
        else
            return b;
    }

    void print(bool esDerecho, const std::string &identacion, NodoArbolAVL<T> *r);


};


/**
 * Constructor del Arbol
 * @tparam K Clave por la cual va a ordenar el árbol
 * @tparam T Valor guardado por el árbol
 */
template<class T>
ArbolBinarioAVL<T>::ArbolBinarioAVL() {
    tamanio = 0;
    raiz = nullptr;
}


/**
 * Destructor del Arbol
 */
template<class T>
ArbolBinarioAVL<T>::~ArbolBinarioAVL() {
    //TODO: hacer destructor
}


/**
 * Elimina un dato del árbol
 * @param clave Clave para identificar el nodo a borrar
 */
template<class T>
void ArbolBinarioAVL<T>::remove(T dato) {
    raiz = remove(dato, raiz);
}


/**
 * Informa si un árbol esta vacío
 * @return
 */
template<class T>
bool ArbolBinarioAVL<T>::esVacio() {
    return raiz == nullptr;
}
/**
 * Recorre un árbol en preorden
 */
template<class T>
void ArbolBinarioAVL<T>::preorder() {
    preorder(raiz);
}


/**
 * Recorre un árbol en orden
 */
template<class T>
void ArbolBinarioAVL<T>::inorder() {
    inorder(raiz);
}

/**
 * Recorre un árbol en postorden
 */
template<class T>
void ArbolBinarioAVL<T>::postorder() {
    postorder(raiz);
}

/**
 * Muestra un árbol por consola
 */
template<class T>
void ArbolBinarioAVL<T>::print() {
    print(true, "", raiz);
}

/**
 * Agrega un dato al árbol
 * @param clave Clave para agregar el dato
 * @param dato Dato a agregar
 */
template<class T>
NodoArbolAVL<T> *ArbolBinarioAVL<T>::put(T dato, NodoArbolAVL<T> *r) {

    if (r == nullptr) {
        tamanio++;
        return new NodoArbolAVL<T>(dato);
    }

    if (dato < r->dato) {
        r->izq = put(dato, r->izq);
        if (altura(r->izq) - altura(r->der) == 2) {
            if (dato < r->izq->dato)
                r = rotarIzq(r);
            else
                r = rotarDobleIzq(r);
        }
    } else if (dato > r->dato) {
        r->der = put(dato, r->der);
        if (altura(r->der) - altura(r->izq) == 2) {
            if (dato > r->der->dato)
                r = rotarDer(r);
            else
                r = rotarDobleDer(r);
        }
    } else {
        r->ocurrencia++;

    }


    if (altura(r->izq) > altura(r->der))
        r->altura = altura(r->izq) + 1;
    else
        r->altura = altura(r->der) + 1;

}

/**
 * Busca un dato en el árbol. Si no esta el dato en el árbol
 * tira una excepción
 * @param clave Valor a buscar
 * @return el valor buscado
 */
template<class T>
T ArbolBinarioAVL<T>::search(T dato, NodoArbolAVL<T> *r) {
    if (r == nullptr) {
        throw std::out_of_range("Elemento no encontrado");
    }
    if (r->dato == dato)
        return r->dato;
    if (r->dato > dato)
        return search(dato, r->izq);
    else
        return search(dato, r->der);
}

template<class T>
void ArbolBinarioAVL<T>::preorder(NodoArbolAVL<T> *r) {
    if (r == nullptr)
        return;

    std::cout << r->dato << " ";
    preorder(r->izq);
    preorder(r->der);

}

template<class T>
void ArbolBinarioAVL<T>::inorder(NodoArbolAVL<T> *r) {
    if (r == nullptr)
        return;
    inorder(r->izq);
    std::cout << (r->dato) << r->ocurrencia << '\n';
    inorder(r->der);

}


template<class T>
void ArbolBinarioAVL<T>::posorder(NodoArbolAVL<T> *r) {
    if (r == nullptr)
        return;

    posorder(r->izq);
    posorder(r->der);
    std::cout << r->dato << " ";
}

template<class T>
NodoArbolAVL<T> *ArbolBinarioAVL<T>::remove(T dato, NodoArbolAVL<T> *r) {
    NodoArbolAVL<T> *aux;
    if (r == nullptr) {
        throw 404;
    }
    if (r->dato == dato) {
        // Borrar nodo
        if (r->izq == nullptr && r->der == nullptr) {
            delete r;
            return nullptr;
        } else if (r->izq == nullptr && r->der != nullptr) {
            aux = r->der;
            delete r;
            return aux;
        } else if (r->izq != nullptr && r->der == nullptr) {
            aux = r->izq;
            delete r;
            return aux;
        } else if (r->izq != nullptr && r->der != nullptr) {
            bool enc;
            if (r->izq->der != nullptr) {
                aux = buscarMax(r->izq, &enc);
                aux->der = r->der;
                aux->izq = r->izq;
            } else {
                aux = r->izq;
                r->izq->der = r->der;
            }
            delete r;
            return aux;
        }
    } else if (r->dato > dato) {
        r->izq = remove(dato, r->izq);
    } else {
        r->der = remove(dato, r->der);
    }
    return r;
}


template<class T>
NodoArbolAVL<T> *ArbolBinarioAVL<T>::buscarMax(NodoArbolAVL<T> *r, bool *encontre) {
    NodoArbolAVL<T> *ret;
    *encontre = false;

    if (r->der == nullptr) {
        *encontre = true;
        return r;
    }

    ret = buscarMax(r->der, encontre);
    if (*encontre) {
        r->der = nullptr;
        *encontre = false;
    }

    return ret;

}


template<class T>
void ArbolBinarioAVL<T>::print(bool esDerecho, const std::string &identacion, NodoArbolAVL<T> *r) {
    if (r->der != nullptr) {
        print(true, identacion + (esDerecho ? "     " : "|    "), r->der);
    }
    std::cout << identacion;
    if (esDerecho) {
        std::cout << " /";
    } else {
        std::cout << " \\";
    }
    std::cout << "-- ";
    std::cout << r->dato << std::endl;
    if (r->izq != NULL) {
        print(false, identacion + (esDerecho ? "|    " : "     "), r->izq);
    }
}

template<class T>
int ArbolBinarioAVL<T>::chicoGrande(NodoArbolAVL<T> *r) {

    int nivel = 0;
    int nivel2 = 0;
    if (r == nullptr) { return 0; }
    else {
        int mayor = 0;
        int menor = tamanio;

        int izq = chicoGrande(r->izq) + 1;
        if (r->getDato() > mayor) {
            mayor = r->getDato();
            nivel = izq;
        }
        if (r->getDato() < menor) {
            menor = r->getDato();
            nivel2 = izq;
        }

        int der = chicoGrande(r->der) + 1;


        if (r->getDato() > mayor) {
            mayor = r->getDato();
            nivel = der;
        }
        if (r->getDato() < menor) {
            menor = r->getDato();
            nivel2 = izq;
        }

        return nivel2; //nivel del nodo mas alto
    }
}
template <class T>
int ArbolBinarioAVL<T>::contarPorNivel(NodoArbolAVL<T> *r)
{Lista<int> li;
//Lista<int>li2;
    if (r !=nullptr)
    {
         izq=contarPorNivel(r->izq)+1;
         der=contarPorNivel(r->der)+1;

        if (izq>der)
            return izq;
        else return der;

    }

    return -1;
}
template<class T>
T ArbolBinarioAVL<T>::contarPorNivel() {
    contarPorNivel(raiz);
}

template<class T>
int ArbolBinarioAVL<T>::chicoGrande() {
    chicoGrande(raiz);
}

template<class T>
int ArbolBinarioAVL<T>::contarHastaNivel(NodoArbolAVL<T> *r, int n) {

    if (r==nullptr) { return 0;}


    int sumIzq=contarHastaNivel(r->izq,n-1);
    int sumDer=contarHastaNivel(r->der,n-1);

    if (n>=0){ return sumIzq+sumDer+r->getDato();}

    return sumIzq+sumDer;


    }

template<class T>
T ArbolBinarioAVL<T>::contarHastaNivel(int n) {
    contarHastaNivel(raiz, n);
}

template<class T>
int ArbolBinarioAVL<T>::SumarHojas() {

    SumarHojas(raiz);
}

template<class T>
int ArbolBinarioAVL<T>::SumarHojas(NodoArbolAVL<T> *r) {
    if (r ==nullptr)
    {
        return 0;
    }

    int porIzq=SumarHojas(r->izq);
    int porDer=SumarHojas(r->der);


    return porIzq+porDer+r->getDato();
}

template<class T>
NodoArbolAVL<T> *ArbolBinarioAVL<T>::ImagenEspecular(NodoArbolAVL<T> *r) {

    if ((r== nullptr) || (r->der== nullptr && r->izq==nullptr)){return r;}
    else {
        NodoArbolAVL<T> *aux=r->izq;
        r->izq=r->der;
        r->der=aux;

        return r;

    }

}





#endif //HASHMAP_H
#endif //PROGRAMACION3_ARBOLBINARIOAVL_H
