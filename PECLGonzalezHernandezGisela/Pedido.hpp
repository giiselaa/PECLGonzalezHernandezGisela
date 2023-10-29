#ifndef PEDIDO_HPP
#define PEDIDO_HPP
#include <iostream>
#include <iomanip>
using namespace std;

class Pedido
{
public:
    Pedido();
   ~Pedido();
   
    bool esUrgenteP();
    void mostrar();
    int getId();
    void setId(int);
    void setNumSeg(int);
private:
    char DNI[10];
    bool esUrgente;
    int id;
    int numSeg;
    
    void generarDNI();
    
};


#endif