#ifndef COLA_HPP
#define COLA_HPP
#include "NodoCola.hpp"
#include <iostream>
using namespace std;

class Cola
{
public:

    Cola(); 
    
    ~Cola();
    
    void insertar(Pedido pedido);
    void mostrar();
    Pedido verPrimero();
    int getLongitud();
    Pedido extraer();
    
private:
    pnodoCola primero, ultimo;
    int longitud;
};

#endif
