#include "Lista.hpp"
#include <cstddef>

Lista::Lista()
{
    primero = NULL;
    ultimo = NULL;
    longitud = 0; 
}

Pedido Lista::resto()
{
    pnodoLista nodo;
    Pedido pedido;
    nodo = primero;
    if(!nodo){
        return pedido; //Pedido()
    }

        primero = nodo->siguiente;
        pedido = nodo->valor;
        delete nodo;
        if(!primero){
            ultimo = NULL;
        }
        longitud--;
        return pedido;
}

void Lista::mostrar()
{
    pnodoLista aux = primero;
    cout<<"\t"<<" El contenido de la lista es: " << endl;
    while (aux){
        aux->valor.mostrar();
        aux = aux->siguiente;
    }
    cout <<endl;
}

void Lista::insertarEnOrden(Pedido pedido) 
{
    pnodoLista nodo;
    nodo = new NodoLista(pedido);

    if (!primero || pedido.getId() < primero->valor.getId()){
        nodo->siguiente = primero;
        primero = nodo;
    } else {
        pnodoLista actual = primero;

        while (actual->siguiente && pedido.getId() >= actual->siguiente->valor.getId()) {
            actual = actual->siguiente;
        }

        nodo->siguiente = actual->siguiente;
        actual->siguiente = nodo;
    }
    pnodoLista ultimo = primero;
    while (ultimo->siguiente) {
        ultimo = ultimo->siguiente;
    }
    ultimo->siguiente = nullptr;
    longitud++;
}

int Lista::getLongitud()
{
    return this->longitud;
}

Pedido Lista::getPrimero()
{
    return primero -> valor;
}

Pedido Lista::getUltimo()
{
    pnodoLista actual = primero;
    while(actual){
        ultimo = actual;
        actual = actual->siguiente;
    }
    return ultimo->valor;
}

Lista::~Lista()
{
    while(primero)
        resto();
}

