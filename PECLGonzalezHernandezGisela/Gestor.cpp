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

int Gestor::longitudPila()
{
    return this -> pila.getLongitud();
}

void Gestor::borrarPedidosPila()
{
    while((pila.getLongitud()) > 0) {
        pila.desapilar();
    }
}

/*
void Gestor :: encolarPedidos()
{
    //codigo extrae de la pila y los encola en la estación
    while ((pila.getLongitud()) > 0) {
        Pedido pedido = pila.extraer();
    }
}
 */

Gestor::~Gestor()
{
}
