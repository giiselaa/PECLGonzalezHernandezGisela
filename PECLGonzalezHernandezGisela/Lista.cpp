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
        return pedido; 
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
    if (longitud == 0){
       cout<< "\t" <<setw(10) <<" La lista esta vacia " << endl;         
    }else{
    pnodoLista aux = primero;
    while (aux){
        aux->valor.mostrar();
        aux = aux->siguiente;
    }
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

void Lista::insertar(Pedido pedido)
{
    pnodoLista nuevo;
    nuevo = new NodoLista(pedido);
    if(ultimo)
        ultimo ->siguiente = nuevo;
    
    ultimo = nuevo;
    
    if(!primero)
        primero = nuevo;
    longitud++;
}


void Lista::insertarOrdenNumSeg(Pedido pedido)
{
    pnodoLista nodo;
    nodo = new NodoLista(pedido);

    if (!primero || pedido.getNumSeg() < primero->valor.getNumSeg()){
        nodo->siguiente = primero;
        primero = nodo;
    } else {
        pnodoLista actual = primero;

        while (actual->siguiente && pedido.getNumSeg() >= actual->siguiente->valor.getNumSeg()) {
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

