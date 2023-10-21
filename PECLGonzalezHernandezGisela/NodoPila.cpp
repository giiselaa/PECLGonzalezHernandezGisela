#include "NodoPila.hpp"

NodoPila::NodoPila(Pedido pedido, NodoPila* sig)
{
    valor = pedido;
    siguiente = sig;
}

NodoPila::~NodoPila()
{
}


