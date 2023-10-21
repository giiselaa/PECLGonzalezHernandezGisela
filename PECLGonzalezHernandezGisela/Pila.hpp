#include "NodoPila.hpp"
#include <iostream>

using namespace std;

class Pila
{
public:
    Pila();
    
    ~Pila();
    void insertar(Pedido pedido);
    Pedido extraer();
    Pedido cima();
    void mostrar();
    int getLongitud();
    
private:
    pnodoPila ultimo;
    int longitud;
};