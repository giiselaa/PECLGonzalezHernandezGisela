#include "Arbol.hpp"


Arbol::Arbol() 
{
 raiz = nullptr; 
}

void Arbol::insertar(Pedido pedido) 
{
    raiz = insertar(raiz, pedido); 
}

pnodoAbb Arbol::insertar(pnodoAbb nodo, Pedido pedidoI)
{
    if(!nodo)
        return new NodoArbol(pedidoI);
    if(pedidoI.getNumSeg() <= nodo->pedido.getNumSeg())
        nodo->izq = insertar(nodo->izq, pedidoI);
    else
        nodo->der = insertar(nodo->der, pedidoI);
    return nodo;
}

void Arbol::pintar()
{
    pintar(raiz);
    cout << '\n';
}

void Arbol::pintar(pnodoAbb nodo)
{
    if(!nodo)
        return;
    pintar(nodo->izq);
    cout << nodo -> pedido.getNumSeg() << " ";
    pintar(nodo->der);
}

int Arbol::altura(pnodoAbb nodo)
{
    if(!nodo)
        return 0;
    return 1 + max(altura(nodo->izq), altura(nodo->der));
}

void Arbol::dibujarNodo(vector<string>& output, vector<string>& linkAbove, pnodoAbb nodo, int nivel, int p,
                        char linkChar)
{
    if(!nodo)
        return;

    int h = output.size();
    string SP = " ";

    if(p < 0) {
        string extra(-p, ' ');
        for(string& s : output)
            if(!s.empty())
                s = extra + s;
        for(string& s : linkAbove)
            if(!s.empty())
                s = extra + s;
    }
    if(nivel < h - 1)
        p = max(p, (int)output[nivel + 1].size());
    if(nivel > 0)
        p = max(p, (int)output[nivel - 1].size());
    p = max(p, (int)output[nivel].size());

    if(nodo->izq) {
        int numeroQueQuieroImprimirEnElArbol =
            nodo->izq->pedido.getNumSeg(); 
        string izqdato = SP + to_string(numeroQueQuieroImprimirEnElArbol) + SP;
        dibujarNodo(output, linkAbove, nodo->izq, nivel + 1, p - izqdato.size(), 'L');
        p = max(p, (int)output[nivel + 1].size());
    }

    int space = p - output[nivel].size();
    if(space > 0)
        output[nivel] += string(space, ' ');
    int numeroQueQuieroImprimirEnElArbol =
        nodo->pedido.getNumSeg();
    string nododato = SP + to_string(numeroQueQuieroImprimirEnElArbol) + SP;
    output[nivel] += nododato;

    space = p + SP.size() - linkAbove[nivel].size();
    if(space > 0)
        linkAbove[nivel] += string(space, ' ');
    linkAbove[nivel] += linkChar;

    if(nodo->der)
        dibujarNodo(output, linkAbove, nodo->der, nivel + 1, output[nivel].size(), 'R');
}

void Arbol::dibujar()
{
    int h = altura(raiz);
    vector<string> output(h), linkAbove(h);
    dibujarNodo(output, linkAbove, raiz, 0, 5, ' ');

    for(int i = 1; i < h; i++) {
        for(int j = 0; j < linkAbove[i].size(); j++) {
            if(linkAbove[i][j] != ' ') {
                int size = output[i - 1].size();
                if(size < j + 1)
                    output[i - 1] += string(j + 1 - size, ' ');
                int jj = j;
                if(linkAbove[i][j] == 'L') {
                    while(output[i - 1][jj] == ' ')
                        jj++;
                    for(int k = j + 1; k < jj - 1; k++)
                        output[i - 1][k] = '_';
                } else if(linkAbove[i][j] == 'R') {
                    while(output[i - 1][jj] == ' ')
                        jj--;
                    for(int k = j - 1; k > jj + 1; k--)
                        output[i - 1][k] = '_';
                }
                linkAbove[i][j] = '|';
            }
        }
    }

    cout << '\n' << '\n';
    for(int i = 0; i < h; i++) {
        if(i)
            cout << linkAbove[i] << '\n';
        cout << output[i] << '\n';
    }
    cout << '\n' << '\n';
}


int Arbol::numNodos(){
    
    return numNodos(raiz);
}

int Arbol::numNodos(pnodoAbb nodo){
    
    if (nodo == NULL) {
        return 0;
    }else{
        return 1 + numNodos(nodo -> izq) + numNodos(nodo -> der);
    }
}

int Arbol::impares(){
    return impares(raiz);
}

int Arbol::impares(pnodoAbb nodo){
    
    int cont = 0;
    
    if(nodo == NULL){
        return 0;
    }else{
        if (nodo -> pedido.getNumSeg() % 2 != 0){
            cont = cont + 1;
        }
        return cont + impares(nodo -> izq) + impares(nodo -> der);
    }
}

void Arbol::mostrarEstandar(){
    recorrerEstandar(raiz -> izq);
}

void Arbol::recorrerEstandar(pnodoAbb nodo){
        if(nodo != NULL){
            recorrerEstandar(nodo -> izq);
            nodo -> pedido.mostrar();
            recorrerEstandar(nodo -> der);
        }
}

void Arbol::mostrarUrgentes(){
    recorrerUrgente(raiz -> der);
}

void Arbol::recorrerUrgente(pnodoAbb nodo){
    if(nodo != NULL){
        recorrerUrgente(nodo -> izq);
        nodo-> pedido.mostrar();
        recorrerUrgente(nodo -> der);
    }
}

void Arbol::recorrerInorden(pnodoAbb nodo, bool esRaiz) {
    if (nodo != NULL) {
        recorrerInorden(nodo->izq, false); 

        if (!esRaiz) {
            nodo-> pedido.mostrar(); 
        }

        recorrerInorden(nodo->der, false); 
    }
}

void Arbol::inordenMostrar() {
    recorrerInorden(raiz, true); 
}


void Arbol::busquedaNumSegMenor(pnodoAbb nodo) {
    if (!nodo) {
        return;
    }
    while (nodo->izq) {
        nodo = nodo->izq;
    }
    nodo->pedido.mostrar(); 
}

void Arbol::busquedaNumSegMayor(pnodoAbb nodo) {
    if (!nodo) {
        return;
    }
    while (nodo->der) {
        nodo = nodo->der;
    }
    nodo -> pedido.mostrar();
}

void Arbol::idMenor() {
    pnodoAbb nodoMenor = nullptr;
    busquedaIdMenor(raiz->der, nodoMenor);

    if (nodoMenor) {
        nodoMenor->pedido.mostrar();
    } else {
        return;
    }
}

void Arbol::busquedaIdMenor(pnodoAbb nodo, pnodoAbb& nodoMenor) {
    if (!nodo) {
        return;
    }
    busquedaIdMenor(nodo->der, nodoMenor);
        if (!nodoMenor || nodo->pedido.getId() < nodoMenor->pedido.getId()) {
            nodoMenor = nodo;
        }
    busquedaIdMenor(nodo->izq, nodoMenor);
}

void Arbol::idMayor() {
    pnodoAbb nodoMayor = nullptr;
    busquedaIdMayor(raiz->der, nodoMayor);

    if (nodoMayor) {
        nodoMayor->pedido.mostrar();
    } else {
        return;
    }
}

void Arbol::busquedaIdMayor(pnodoAbb nodo, pnodoAbb& nodoMayor) {
    if (!nodo) {
        return;
    }
    busquedaIdMayor(nodo->der, nodoMayor);

        if (!nodoMayor || nodo->pedido.getId() > nodoMayor->pedido.getId()) {
            nodoMayor = nodo;
        }
    busquedaIdMayor(nodo->izq, nodoMayor);
}

void Arbol::busquedaPedidos() {
    
    cout << "\t" << setw(10) << " El pedido estandar con menor numero de seguimiento es: " << endl;
    busquedaNumSegMenor(raiz->izq);
    cout << "\t" << setw(10) << " El pedido estandar con mayor numero de seguimiento es: " << endl;
    busquedaNumSegMayor(raiz->der);
    cout << "\t" << setw(10) << " El pedido urgente con menor numero de id es: " << endl;
    idMenor();
    cout << "\t" << setw(10) << " El pedido urgente con mayor numero de id es: " << endl;
    idMayor();
    
}

void Arbol::mostrarPedidosNodosHoja(pnodoAbb nodo) {
    if (nodo != NULL) {
        if (nodo->izq == NULL && nodo->der == NULL) {
            nodo->pedido.mostrar();
        }
        mostrarPedidosNodosHoja(nodo->izq);
        mostrarPedidosNodosHoja(nodo->der);
    }
}

void Arbol::mostrarPedidosNodosHojaArbol() {
    mostrarPedidosNodosHoja(raiz);
}

void Arbol::eliminarNodoArbol(int numSegE){
    recorrerArbol(raiz,numSegE);
}

void Arbol::recorrerArbol(pnodoAbb &nodo, int numSegE) {
    if (nodo != NULL) {
        if (numSegE < nodo -> pedido.getNumSeg()){
            recorrerArbol(nodo->izq, numSegE); 
        }else if (numSegE > nodo -> pedido.getNumSeg()){
           recorrerArbol(nodo->der, numSegE); 
        }else {
            eliminarNodo(nodo);
            return; 
        }
    }
}

void Arbol::eliminarNodo(pnodoAbb &nodo) {
    if (nodo->izq == NULL) {
        pnodoAbb temp = nodo->der;
        delete nodo;
        nodo = temp;
    } else if (nodo->der == NULL) {
        pnodoAbb temp = nodo->izq;
        delete nodo;
        nodo = temp;
    } else {
        pnodoAbb sucesor = encontrarSucesor(nodo->der);
        nodo->pedido = sucesor->pedido;
        eliminarNodo(sucesor);
    }
}

pnodoAbb Arbol::encontrarSucesor(pnodoAbb nodo) {
    while (nodo->izq != NULL) {
        nodo = nodo->izq;
    }
    return nodo;
}

Arbol::~Arbol() {}

