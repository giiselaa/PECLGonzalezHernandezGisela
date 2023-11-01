#ifndef GESTOR_HPP
#define GESTOR_HPP
#include "Pila.hpp"
#include "Cola.hpp"
#include "Lista.hpp"
#include "Pedido.hpp"

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
    void borraPedidosListas();
    void reiniciar();
    void buscarPedidos();
    int longitudPila();
    int pedidosEnSalaA();
    int pedidosEnSalaB();
    int pedidosEnSalaC();
    int pedidosEnSalaD();
    int pedidosEnListaEstandar();
    int pedidosEnListaUrgentes();
    int generarId(Pedido pedido);
    int generarNumSeg(Pedido pedido);
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
    Pedido pedidoE;
    Pedido pedidoU;
    int arrayId[48];
    int arrayNumSeg[48];
    int tamanoArrayId;
    int tamanoArrayNumSeg;
};

#endif