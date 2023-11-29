#include "Gestor.hpp"
#include <random>
Gestor::Gestor()
{
    maxPedidos = 0;
    tamanoArrayNumSeg = 0;
    tamanoArrayId = 0;
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
        int numSeg = generarNumSeg(pedido);
        pedido.setNumSeg(numSeg);
        int id = generarId(pedido);
        pedido.setId(id);
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

int Gestor::generarNumSeg(Pedido pedido){
    int NumSegS;
    bool existe;
    do {
        if(pedido.esUrgenteP()){
            NumSegS = rand() % 499 + 501;
        } else {
            NumSegS = rand() % 499 + 1;
        }
        existe = false;
        for(int i = 0; i < tamanoArrayNumSeg; i++){
            if(arrayNumSeg[i] == NumSegS){
                existe = true;
                break;
            }
        }

    } while(existe);
    if(tamanoArrayNumSeg<48){
        arrayNumSeg[tamanoArrayNumSeg] = NumSegS;
        tamanoArrayNumSeg++;
    } 
    return NumSegS;

}

int Gestor::generarId(Pedido pedido){
    int idN;
    bool existe;
    do {
        if(pedido.esUrgenteP()){
            idN = rand() % 49 + 51;
        } else {
            idN = rand() % 49 + 1;
        }
        existe = false;
        for(int i = 0; i < tamanoArrayId; i++){
            if(arrayId[i] == idN){
                existe = true;
                break;
            }
        }

    } while(existe);
    if(tamanoArrayId<48){
        arrayId[tamanoArrayId] = idN;
        tamanoArrayId++;
    }
    return idN;

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
     cout<< "\t" <<setw(10)<< " El contenido de la cola A es: " << endl; 
     colaA.mostrar();
     cout<< "\t" <<setw(10)<< " El contenido de la cola B es: " << endl;
     colaB.mostrar();
}

void Gestor::muestraPedidosSalasCyD(){
    cout<< "\t" <<setw(10)<< " El contenido de la cola C es: " << endl;
    colaC.mostrar();
    cout<< "\t" <<setw(10)<< " El contenido de la cola D es: " << endl;
    colaD.mostrar();

}

void Gestor::borraPedidosColas(){
    while(colaA.getLongitud() > 0){
        colaA.eliminar();
    }

    while(colaB.getLongitud() > 0){
        colaB.eliminar();
    }

    while(colaC.getLongitud() > 0){
         colaC.eliminar();
    }
    
    while(colaD.getLongitud() > 0){
         colaD.eliminar();
    }

    maxPedidos = pila.getLongitud();

    for(int i = 0; i < tamanoArrayId; i++){
         arrayId[i] = 0;
    }
    for(int i = 0; i < tamanoArrayNumSeg; i++){
         arrayNumSeg[i] = 0;
    }
        
    tamanoArrayId = 0;
    tamanoArrayNumSeg = 0;
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
    cout<< "\t" <<setw(10)<< " El contenido de la lista estandar es: " << endl;
        estandar.mostrar();
    }

void Gestor::muestraPedidosUrgentes(){
    cout<< "\t" <<setw(10)<< " El contenido de la lista urgente es: " << endl;
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
    for(int i = 0; i < tamanoArrayId; i++){
         arrayId[i] = 0;
    }
    for(int i = 0; i < tamanoArrayNumSeg; i++){
         arrayNumSeg[i] = 0;
    }
        
    tamanoArrayId = 0;
    tamanoArrayNumSeg = 0;
    
}

void Gestor::buscarPedidos(){
    
    pedidoE = estandar.getPrimero();
    pedidoU = urgente.getUltimo();
    cout<< "\t" <<setw(10)<< " El pedido de mayor prioridad dentro de los estandar es: " << endl;
    pedidoE.mostrar();
    cout<< "\t" <<setw(10)<< " El pedido de menor prioridad dentro de los urgentes es: " << endl;
    pedidoU.mostrar();
}

void Gestor::insertarPedidosEnArbol(){

    for(int i = 0; i < estandar.getLongitud(); i++){
        Pedido pedido = estandar.resto();
        arbol.insertar(pedido);
    }
    for(int i = 0; i < urgente.getLongitud(); i++){
        Pedido pedido = urgente.resto();
        arbol.insertar(pedido);
    }
    
} 

int Gestor::pedidosEnArbol(){
    return arbol.numNodos();
}

void Gestor::crearDibujarAbb(){
    
    Pedido pedidoAux;
    pedidoAux.setNumSeg(500);
    
    arbol.insertar(pedidoAux);
    insertarPedidosEnArbol();
    arbol.dibujar();
}

void Gestor::mostrarEstandarArbol(){
    cout<< "\t" << setw(10) << " Los pedidos estandar almacenados son: " << endl;
    arbol.mostrarEstandar();
}

void Gestor::mostrarUrgenteArbol(){
    cout<< "\t" << setw(10) << " Los pedidos urgentes almacenados son: " << endl;
    arbol.mostrarUrgentes();
}

/**
 * escribimos aqui el codigo de antes de la R
 */
 
void Gestor::contarImpares(){
    cout << "\t" <<setw(10)<< " El arbol tiene " << arbol.impares() << " pedidos con numero de seguimiento impar" << endl;
}


Gestor::~Gestor()
{
}


