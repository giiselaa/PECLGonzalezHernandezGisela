#include "NodoCola.hpp"

NodoCola::NodoCola(Pedido pedido, NodoCola* sig)
{
    valor = pedido;
    siguiente = sig;
}

NodoCola::~NodoCola()
{
}

