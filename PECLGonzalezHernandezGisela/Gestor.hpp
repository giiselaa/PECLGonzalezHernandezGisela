#include "pila.hpp"

class Gestor
{
public:
    Gestor();
    void generarPedidosAleatorios(int cantidad);
    void mostrarPedidosEnPila();
    void borrarPedidosPila();
    //void encolarPedidos();
    int longitudPila();
    ~Gestor();
    
private:
    Pila pila;
    int maxPedidos;
};

