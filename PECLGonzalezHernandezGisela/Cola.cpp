#include "Cola.hpp"
#include <cstddef>

Cola::Cola()
{
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
}

void Cola::insertar(Pedido pedido)
{
    pnodoCola nuevo;
    nuevo = new NodoCola(pedido);
    if(ultimo)
        ultimo ->siguiente = nuevo;
    
    ultimo = nuevo;
    
    if(!primero)
        primero = nuevo;
    longitud++;
}
void Cola::mostrar()
{
    if (longitud == 0){
       cout<< "\t" <<setw(10) <<" La cola esta vacia " << endl;         
    }else{
    pnodoCola aux = primero;
    while (aux){
        aux->valor.mostrar();
        aux = aux->siguiente;
    }}
    cout <<endl;
}

Pedido Cola::extraer()
{
    pnodoCola nodo;
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



Pedido Cola::verPrimero()
{
    return primero->valor;
}

int Cola::getLongitud()
{
    return this->longitud;
}

Cola::~Cola()
{
    while(primero)
        extraer();
}

