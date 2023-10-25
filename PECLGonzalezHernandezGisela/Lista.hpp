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
    Pedido getPrimero();
    Pedido getUltimo();
    void mostrar();
    void insertarEnOrden(Pedido pedido);
    int getLongitud();
    
private:
    pnodoLista primero, ultimo; 
    int longitud;
};

#endif // LISTA_HPP
