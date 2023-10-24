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
    cout<<"\t"<<" El contenido de la cola es: " << endl;
    while (aux){
        aux->valor.mostrar();
        aux = aux->siguiente;
    }
    cout <<endl;
}
//falla
void Lista::insertarEnOrden(Pedido pedido) {
    pnodoLista nodo = new NodoLista(pedido);
    
    if (!primero || pedido.id < primero->valor.id) {
        nodo->siguiente = primero;
        primero = nodo;
    } else {
        pnodoLista actual = primero;

        while (actual->siguiente && pedido.id >= actual->siguiente->valor.id) {
            actual = actual->siguiente;
        }

        nodo->siguiente = actual->siguiente;
        actual->siguiente = nodo;
    }
}

int Lista::getLongitud()
{
    return this->longitud;
}

Lista::~Lista()
{
    
}

