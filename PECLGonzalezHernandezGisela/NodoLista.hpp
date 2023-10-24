#ifndef NODOLISTA_HPP
#define NODOLISTA_HPP
#include <iostream>
#include "Pedido.hpp"

using namespace std;

class NodoLista
{
public:
    NodoLista(Pedido pedido, NodoLista* sig = NULL);
    ~NodoLista();
    
private:
    Pedido valor;
    NodoLista* siguiente;
    friend class Lista;
};

typedef NodoLista* pnodoLista;

#endif // NODOLISTA_HPP
