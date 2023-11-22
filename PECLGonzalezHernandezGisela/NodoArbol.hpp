#ifndef NODOARBOL_HPP
#define NODOARBOL_HPP
#include <iostream>
#include "Pedido.hpp"

class NodoArbol
{
public:
    NodoArbol(Pedido pedido);
    ~NodoArbol();

private:
    Pedido pedido; //variable para almacenar el pedido en cada nodo
    NodoArbol* izq;
    NodoArbol* der;

    friend class Arbol;
};

typedef NodoArbol* pnodoAbb;
#endif // NODOARBOL_HPP
