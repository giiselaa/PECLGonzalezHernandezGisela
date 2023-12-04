#include "NodoArbol.hpp"

NodoArbol::NodoArbol(Pedido pedido)
{
    this->pedido = pedido;
    this->izq = nullptr;
    this->der = nullptr;
}

NodoArbol::~NodoArbol() {}

