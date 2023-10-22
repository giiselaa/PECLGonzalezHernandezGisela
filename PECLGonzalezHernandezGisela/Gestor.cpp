#include "Gestor.hpp"

Gestor::Gestor()
{
    maxPedidos = 0;
}

void Gestor::generarPedidosAleatorios(int cantidad) 
{
    if  (maxPedidos<4){
    for (int i = 0; i < cantidad; i++) {
        Pedido nuevoPedido;
        pila.insertar(nuevoPedido);
    }
    cout << "Se generaron y almacenaron " << cantidad << " pedidos aleatorios en la pila.\n";
    maxPedidos++;
    }
    else{
    cout << "Has generado el numero maximo de pedidos";
    }
}

void Gestor::mostrarPedidosEnPila() 
{
    pila.mostrar();
}

void Gestor::borrarPedidosPila()
{
    while((pila.getLongitud()) > 0){
        pila.desapilar();
    }
}

int Gestor::longitudPila()
{
    return this -> pila.getLongitud();
}
Gestor::~Gestor()
{
}
