#ifndef NODOCOLA_HPP
#define NODOCOLA_HPP

class NodoCola
{
public:
    NodoCola(int v, NodoCola*sig=NULL);
    ~NodoCola();
    
    
private:
    int valor;
    NodoCola* siguiente;
    
    friend class Cola;
};

typedef NodoCola* pnodoCola;
#endif // NODOCOLA_HPP
