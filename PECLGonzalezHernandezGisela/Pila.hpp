#ifndef PILA_HPP
#define PILA_HPP
#include "NodoPila.hpp"
#include <iostream>

using namespace std;

class Pila
{
public:
    Pila();
    
    ~Pila();
    void insertar(Pedido pedido);
    Pedido extraer();
    Pedido cima();
    void mostrar();
    void desapilar();
    int getLongitud();
    
private:
    pnodoPila ultimo;
    int longitud;
};

#endif