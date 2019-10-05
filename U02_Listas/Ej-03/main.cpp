#include <iostream>
#include "../Lista/Lista.h"

#include <iostream>
using namespace std;

struct Nodo
{

    int dato;
    Nodo *siguiente;
public:
    Nodo *getSiguiente()  {
        return siguiente;
    }

    void setSiguiente(Nodo*siguiente) {
        this->siguiente = siguiente;
    }
};

class Lista
{
    Nodo *h; //primer elemento
public:
    void inicializa ();
    bool Vacia ();
    int tamanio ();
    void mostrar ();
    void ingresarDato (int);
    void eliminarDato (int);


};

void Lista::inicializa()
{
    h=NULL; //primer puntero apunta a NULL
}

bool Lista::Vacia()
{ if (h==NULL) return true;
    else return false;
}

int Lista::tamanio()
{
    int cont=0;
    Nodo *aux;
    aux=h;
    while (aux != NULL)   //mientras que aux no sea Nulo
    { cont++;  //va a ir sumando la cantidad de nodos que hay
        aux=aux->siguiente; //se mueve la posicion del auxiliar al siguiente elemento en la lista}

        return cont;
    }
}

void Lista::mostrar()
{
    Nodo *aux;
    aux=h;
    while (aux !=NULL)
    { cout<<aux->dato<<endl;  //me muestra el dato
        aux=aux->siguiente; //pasa al siguiente elemento de la lista
    }
}


void Lista::ingresarDato (int d)
{
    Nodo *aux2 = new Nodo;
    aux2->dato=d;
    aux2->siguiente=NULL;
    if (Vacia())
        h=aux2;
    else
    {
        Nodo *aux;
        aux=h;
        while (aux->siguiente != NULL)
        {
            aux=aux->siguiente;
        }

        aux->siguiente=aux2;
    }


}

void Lista::eliminarDato(int pos)
{

    Nodo *aux=h, *aBorrar;  //puntero que apunta al inicio
    int posActual=0; //comienza en cero

    while (aux != NULL && posActual <pos-1) //so el incio es distinto de NULL y la posicion actual esta antes que la que ingresamos
    {
        aux =aux->siguiente;  //el inicio apunta al siguiente
        posActual++; //aumenta en uno la posicion actual
    }

    if (aux == NULL)
    {cout<<"el elemento no existe";}

    else if (pos==0)
    { h = h->siguiente;
        delete aux;
        return;}

    else if (aux->siguiente == NULL)
    { throw 404;}

    aBorrar = aux->getSiguiente();  //el elemento que debe borrarse va a ser a donde apunta el aux (siguiente)
    aux->setSiguiente(aBorrar->getSiguiente()); //aux pasa a apuntar al que le sigue de aBorrar
    delete aBorrar;  //borramos aBorrar
}

int main ()
{
    int t,d,e,n;

    Lista A;


    A.inicializa();

    cout<<"INGRESE EL LARGO DE SU LISTA:"<<endl;
    cin>>n;
    for (int i=0;i<n;i++) {

        cout<<"INSERTE DATO:"<<endl;
        cin>>d;
        A.ingresarDato(d);
        cout<<"\nLISTA:"<<endl;
        A.mostrar();}

    cout<<"INGRESE POSICION DEL DATO QUE DESEA ELIMINAR"<<endl;
    cin>>e;
    A.eliminarDato(e);

    cout<<endl;
    A.mostrar();

}