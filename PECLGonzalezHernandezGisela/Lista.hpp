#ifndef LISTA_HPP
#define LISTA_HPP
#include "NodoLista.hpp"
#include <iostream>

using namespace std;

class Lista
{
public:
    Lista();
    ~Lista();
    
    Pedido resto();
    void mostrar();
    int getLongitud();
    void insertarEnOrden(Pedido pedido);
    
        
private:
    pnodoLista primero, ultimo; 
    int longitud;
};

#endif // LISTA_HPP
