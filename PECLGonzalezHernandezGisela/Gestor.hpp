#include "pila.hpp"

class Gestor
{
public:
    Gestor();
    void generarPedidosAleatorios(int cantidad);
    void mostrarPedidosEnPila();
    void borrarPedidosPila();
    int longitudPila();
    ~Gestor();
    
private:
    Pila pila;
    int maxPedidos;
};

