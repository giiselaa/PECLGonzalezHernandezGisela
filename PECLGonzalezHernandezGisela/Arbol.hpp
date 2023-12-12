#ifndef ARBOL_HPP
#define ARBOL_HPP

#include "NodoArbol.hpp"
#include "Lista.hpp"
#include <vector>
#include <iostream>

using namespace std;

class Arbol
{
public:
    Arbol();
    void insertar(Pedido pedido);
    void pintar();
    void dibujar();
    void mostrarEstandar();
    void mostrarUrgentes();
    void inordenMostrar();
    void recorrerEstandar(pnodoAbb);
    void recorrerUrgente(pnodoAbb);
    void recorrerInorden(pnodoAbb, bool);
    void busquedaNumSegMenor(pnodoAbb);
    void busquedaNumSegMayor(pnodoAbb);
    void idMenor();
    void busquedaIdMenor(pnodoAbb, pnodoAbb&);
    void idMayor();
    void busquedaIdMayor(pnodoAbb, pnodoAbb&);
    void busquedaPedidos();
    void mostrarPedidosNodosHoja(pnodoAbb);
    void mostrarPedidosNodosHojaArbol();
    void eliminarNodoArbol(int);
    void recorrerArbol(pnodoAbb &nodo, int);
    void eliminarNodo(pnodoAbb &nodo);
    pnodoAbb encontrarSucesor(pnodoAbb nodo);
    int numNodos();
    int numNodos(pnodoAbb);
    int impares();
    int impares(pnodoAbb);
    ~Arbol();

private:
    pnodoAbb raiz;
    pnodoAbb insertar(pnodoAbb, Pedido);
    void pintar(pnodoAbb);
    void dibujarNodo(vector<string>& output, vector<string>& linkAbove, pnodoAbb nodo, int nivel, int minPos,
                     char linkChar);
    int altura(pnodoAbb);
};

#endif // ARBOL_HPP
