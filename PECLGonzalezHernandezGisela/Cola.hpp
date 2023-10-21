#include "NodoCola.hpp"
#include <iostream>
using namespace std;

class Cola
{
public:

    Cola(); 
    
    ~Cola();
    
    void insertar(Pedido pedido);
    Pedido eliminar();
    void mostrar();
    Pedido verPrimero();
    
private:
    pnodoCola primero, ultimo;
    int longitud;
};

