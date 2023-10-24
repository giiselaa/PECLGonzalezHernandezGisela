#include "NodoLista.hpp"

NodoLista::NodoLista(Pedido pedido, NodoLista* sig)
{
    valor = pedido;
    siguiente = sig;
}

NodoLista::~NodoLista()
{
}

