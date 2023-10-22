#ifndef NODOPILA_HPP
#define NODOPILA_HPP
#include <iostream>
#include "Pedido.hpp"

using namespace std;

class NodoPila
{
public:
    NodoPila(Pedido pedido, NodoPila* sig = NULL);
    ~NodoPila();
    
private:
    Pedido valor;
    NodoPila* siguiente;
    friend class Pila;
};

typedef NodoPila* pnodoPila;

#endif