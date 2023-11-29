#ifndef ARBOL_HPP
#define ARBOL_HPP

#include "NodoArbol.hpp"
#include <vector>

using namespace std;

class Arbol
{
public:
    Arbol();
    void insertar(Pedido pedido);
    void pintar();
    void dibujar();
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
