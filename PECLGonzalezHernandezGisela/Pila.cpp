#include "Pila.hpp"

Pila::Pila()
{
    ultimo = NULL;
    longitud = 0;
}


void Pila::insertar(Pedido pedido)
{
    pnodoPila nuevo;
    nuevo = new NodoPila(pedido, ultimo);
    ultimo = nuevo;
    longitud++;
}


Pedido Pila::extraer()
{
    pnodoPila nodo;
    Pedido pedido;
    if(!ultimo)
        return Pedido();
    nodo = ultimo;
    ultimo = nodo->siguiente;
    pedido = nodo ->valor;
    longitud--;
    delete nodo;
    return pedido;
}


Pedido Pila::cima()
{
    if(!ultimo)
        return Pedido();
    return ultimo->valor;
}


void Pila::mostrar()
{
    pnodoPila aux = ultimo;
    cout << "\t" << setw(10) << " El contenido de la pila es: " <<endl;
    while(aux){
        aux->valor.mostrar();
        aux = aux->siguiente;
    }
      cout << endl;
}


void Pila::desapilar()
{
    pnodoPila nodo;
    nodo = ultimo;
    ultimo = nodo -> siguiente;
    longitud--;
    delete nodo; 
}


int Pila::getLongitud()
{
    return this->longitud;
}


Pila::~Pila()
{
    pnodoPila aux;
    while(ultimo){
        aux = ultimo;
        ultimo = ultimo->siguiente;
        delete aux;
    }
}