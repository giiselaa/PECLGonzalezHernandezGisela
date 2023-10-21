#ifndef GESTOR_HPP
#define GESTOR_HPP
#include "pila.hpp"
class Gestor
{
public:
    Gestor();
    void generarPedidosAleatorios(int cantidad);
    void mostrarPedidosEnPila();
    int longitudPila();
    ~Gestor();
private:
    Pila pila;
    int maxPedidos;
};

#endif // GESTOR_HPP
