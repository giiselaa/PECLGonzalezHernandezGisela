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
    
private:
    char DNI[10];
    bool esUrgente;
    int id;
    int numSeg;
    
    void generarDNI();
    void generarId(bool);
    void generarNumSeg(bool);
};


#endif