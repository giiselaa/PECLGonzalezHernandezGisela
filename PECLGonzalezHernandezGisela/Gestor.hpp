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
    void generarId(bool esUrgente);
    void generarNumSeg(bool esUrgente);
    void eliminarElemento(int* array, int index, int& size);
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
    int arrayId[49];
    int arrayNumSeg[49];
    int tamanoArrayId;
    int tamanoArrayNumSeg;
};

#endif