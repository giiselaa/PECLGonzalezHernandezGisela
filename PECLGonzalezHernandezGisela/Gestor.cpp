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
        bool urgencia = pedido.esUrgenteP();
        generarNumSeg(urgencia);
        pedido.setNumSeg(arrayNumSeg[tamanoArrayNumSeg-1]);
        generarId(urgencia);
        pedido.setId(arrayId[tamanoArrayId-1]);
        if (!pedido.esUrgenteP()){ //si no es urgente a A o B
            if (colaA.getLongitud() <= colaB.getLongitud()){
                colaA.insertar(pedido);
            }else{
                colaB.insertar(pedido);
            }
        }else{ // si es urgente a B o C
            if (colaC.getLongitud() <= colaD.getLongitud()){
                colaC.insertar(pedido);
            }else{
                colaD.insertar(pedido);
            }
        }
            
    }
}
void Gestor::generarNumSeg(bool esUrgente){
    int NumSegS;
    bool existe = true;
    while(existe){
        if(esUrgente){
            NumSegS = (rand() % 499) + 501;
        } else {
            NumSegS = (rand() % 499) + 1;
        }
        existe = false;
        for(int i = 0; i < tamanoArrayNumSeg; i++){
            if(arrayNumSeg[i] == NumSegS){
                existe = true;
                break;
            }
        }
    }   
     
    arrayNumSeg[tamanoArrayNumSeg++] = NumSegS;
}

void Gestor::generarId(bool esUrgente){
    int idN;
    bool existe = true;
    while(existe){
        if(esUrgente){
            idN = (rand() % 49) + 51;
        } else {
            idN = (rand() % 49) + 1;
        }
        existe = false;
        for(int i = 0; i < tamanoArrayId; i++){
            if(arrayId[i] == idN){
                existe = true;
                break;
            }
        }
    } 
    arrayId[tamanoArrayId++] = idN;

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
    while(colaA.getLongitud() > 0){
        Pedido pedido = colaA.extraer();
        int idPedido = pedido.getId();
        int index = -1;

        for(int i = 0; i < tamanoArrayId; i++){
            if(arrayId[i] == idPedido){
                index = i;
                break;
            }
        }

        if(index != -1){
            //eliminarElemento(arrayId, index, tamanoArrayId);
            eliminarElemento(arrayNumSeg, index, tamanoArrayNumSeg);
        }
    }

    while(colaB.getLongitud() > 0){
        Pedido pedido = colaB.extraer();
        int idPedido = pedido.getId();
        int index = -1;

        for(int i = 0; i < tamanoArrayId; i++){
            if(arrayId[i] == idPedido){
                index = i;
                break;
            }
        }

        if(index != -1){
           // eliminarElemento(arrayId, index, tamanoArrayId);
            eliminarElemento(arrayNumSeg, index, tamanoArrayNumSeg);
        }
    }

    while(colaC.getLongitud() > 0){
        Pedido pedido = colaC.extraer();
        int idPedido = pedido.getId();
        int index = -1;

        for(int i = 0; i < tamanoArrayId; i++){
            if(arrayId[i] == idPedido){
                index = i;
                break;
            }
        }

        if(index != -1){
            //eliminarElemento(arrayId, index, tamanoArrayId);
            eliminarElemento(arrayNumSeg, index, tamanoArrayNumSeg);
        }
    }

    while(colaD.getLongitud() > 0){
        Pedido pedido = colaD.extraer();
        int idPedido = pedido.getId();
        int index = -1;

        for(int i = 0; i < tamanoArrayId; i++){
            if(arrayId[i] == idPedido){
                index = i;
                break;
            }
        }

        if(index != -1){
            //eliminarElemento(arrayId, index, tamanoArrayId);
            eliminarElemento(arrayNumSeg, index, tamanoArrayNumSeg);
        }
    }

    maxPedidos = pila.getLongitud() + estandar.getLongitud() + urgente.getLongitud();
}


void Gestor::eliminarElemento(int* array, int index, int& tamano) {
    for (int i = index; i < tamano - 1; i++) {
        array[i] = array[i + 1];
    }
}
void Gestor::enlistarPedidos(){
    Pedido pedido;
    
    while(colaA.getLongitud()>0){
        pedido = colaA.extraer();
        estandar.insertarEnOrden(pedido);
    }
     while(colaB.getLongitud()>0){
        pedido = colaB.extraer();
        estandar.insertarEnOrden(pedido);
    }
    while(colaC.getLongitud()>0){
        pedido = colaC.extraer();
        urgente.insertarEnOrden(pedido);
    }
    while(colaD.getLongitud()>0){
        pedido = colaD.extraer();
        urgente.insertarEnOrden(pedido);
    }
   
}

int Gestor::pedidosEnListaEstandar()
{
    return estandar.getLongitud();
}

int Gestor::pedidosEnListaUrgentes()
{
    return urgente.getLongitud();
}

void Gestor::muestraPedidosEstandar(){
        estandar.mostrar();
    }

void Gestor::muestraPedidosUrgentes(){
        urgente.mostrar();
    }
    
void Gestor::borraPedidosListas(){
    while(estandar.getLongitud() > 0){
        estandar.resto();
    }
    while(urgente.getLongitud() > 0){
        urgente.resto();
    }
}
    
void Gestor::reiniciar(){
    borrarPedidosPila();
    borraPedidosColas();
    borraPedidosListas();
    
}

void Gestor::buscarPedidos(){
    
    pedidoE = estandar.getPrimero();
    pedidoU = urgente.getUltimo();
    
    pedidoE.mostrar();
    pedidoU.mostrar();
}

Gestor::~Gestor()
{
}


