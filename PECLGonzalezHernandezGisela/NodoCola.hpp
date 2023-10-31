#ifndef NODOCOLA_HPP
#define NODOCOLA_HPP
#include "Pedido.hpp"
class NodoCola
{
public:
    NodoCola(Pedido pedido, NodoCola*sig=NULL);
    ~NodoCola();
    
    
private:
    Pedido valor;
    NodoCola* siguiente;
    friend class Cola;
};

typedef NodoCola* pnodoCola;
#endif // NODOCOLA_HPP
