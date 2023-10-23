#include "Gestor.hpp"

Gestor::Gestor()
{
    maxPedidos = 0;
}

void Gestor::generarPedidosAleatorios(int cantidad) 
{
    if  (maxPedidos<48){
    for (int i = 0; i < cantidad; i++) {
        Pedido nuevoPedido;
        pila.insertar(nuevoPedido);
        maxPedidos++;
    }
    cout << "Se generaron y almacenaron " << cantidad << " pedidos aleatorios en la pila.\n";
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
    maxPedidos=0;
}


void Gestor :: encolarPedidos()
{
    while ((pila.getLongitud()) > 0) {
        Pedido pedido = pila.extraer();
        if (!pedido.esUrgenteP()){ //si no es urgente a A o B
            if (colaA.getLongitud() < colaB.getLongitud()){
                colaA.insertar(pedido);
            }else{
                colaB.insertar(pedido);
            }
        }else{ // si es urgente a B o C
            if (colaC.getLongitud() < colaD.getLongitud()){
                colaC.insertar(pedido);
            }else{
                colaD.insertar(pedido);
            }
        }
            
    }
}

int Gestor :: pedidosEnSalaA()
{
   return colaA.getLongitud();
}

int Gestor :: pedidosEnSalaB()
{
    return colaB.getLongitud();
}

int Gestor :: pedidosEnSalaC()
{
    return colaC.getLongitud();
}

int Gestor :: pedidosEnSalaD()
{
    return colaD.getLongitud();
}

void Gestor::muestraPedidosSalasAyB(){
     colaA.mostrar();
     colaB.mostrar();
}

void Gestor::muestraPedidosSalasCyD(){
    colaC.mostrar();
    colaD.mostrar();

}

void Gestor::borraPedidosColas(){
  while(colaA.getLongitud()>0){
      colaA.eliminar();
      }
  while(colaB.getLongitud()>0){
      colaB.eliminar();
      }
  while(colaC.getLongitud()>0){
      colaC.eliminar();
      }
  while(colaD.getLongitud()>0){
      colaD.eliminar();
      }
    maxPedidos=0;
    }




Gestor::~Gestor()
{
}


