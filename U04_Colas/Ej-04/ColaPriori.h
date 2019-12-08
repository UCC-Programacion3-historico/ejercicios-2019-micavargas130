#include "Cola.h"
class ColaPrioridad
{
public:
    Cola <int> *colas;
    int tamanio;  //ingreso el tamanio de la cola
    ColaPrioridad(int cant) //constructor
    {  tamanio = cant;
        colas = new Cola<int>[cant];
    }

    void encolar (int d, int prioridad) {
        if (prioridad >= 0 && prioridad < tamanio)
            colas[prioridad].encolar(d);
        else
            throw 252;
    }

    int desencolar() {
        for (int i = 0; i < tamanio; i++) {
            if (!colas[i].esVacia())
                return colas[i].desencolar();
        }
        throw 404;
    }

};




