#ifndef GESTOR_HPP
#define GESTOR_HPP
#include "Pila.hpp"
#include "Cola.hpp"
#include "Lista.hpp"

class Gestor
{
public:

    Gestor();
    void generarPedidosAleatorios(int cantidad);
    void mostrarPedidosEnPila();
    void borrarPedidosPila();
    void encolarPedidos();
    void muestraPedidosSalasAyB();
    void muestraPedidosSalasCyD();
    void borraPedidosColas();
    void enlistarPedidos();
    void muestraPedidosEstandar();
    void muestraPedidosUrgentes();
    int longitudPila();
    int pedidosEnSalaA();
    int pedidosEnSalaB();
    int pedidosEnSalaC();
    int pedidosEnSalaD();
    int pedidosEnListaEstandar();
    int pedidosEnListaUrgentes();
    
    ~Gestor();
    
private:
    Pila pila;
    int maxPedidos;
    Cola colaA;
    Cola colaB;
    Cola colaC;
    Cola colaD;
    Lista estandar;
    Lista urgente;
};

#endif