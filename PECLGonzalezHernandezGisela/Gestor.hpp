#ifndef GESTOR_HPP
#define GESTOR_HPP
#include "Pila.hpp"
#include "Cola.hpp"

class Gestor
{
public:

    Gestor();
    void generarPedidosAleatorios(int cantidad);
    void mostrarPedidosEnPila();
    void borrarPedidosPila();
    void encolarPedidos();
    int longitudPila();
    int pedidosEnSalaA();
    int pedidosEnSalaB();
    int pedidosEnSalaC();
    int pedidosEnSalaD();
    ~Gestor();
    
private:
    Pila pila;
    int maxPedidos;
    
    Cola colaA;
    Cola colaB;
    Cola colaC;
    Cola colaD;
};

#endif