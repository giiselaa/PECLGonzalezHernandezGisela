#include <iostream>
#include "Pedido.hpp"
using namespace std;

class NodoPila
{
public:
    NodoPila(Pedido pedido, NodoPila* sig = NULL);
    ~NodoPila();
    
private:
    Pedido valor;
    NodoPila* siguiente;
    friend class Pila;
};

typedef NodoPila* pnodoPila;
