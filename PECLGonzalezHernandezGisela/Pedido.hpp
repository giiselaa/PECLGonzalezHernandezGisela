#include <iostream>
#include <iomanip>

using namespace std;

class Pedido
{
public:
    Pedido();
    
    ~Pedido();
    
    bool esUrgente();
    void mostrar();
    
private:
    char DNI[10];
    bool esUrgente;
    int id;
    int numSeg;
    
    void generarDNI();
    void generarId();
    void generarNumSeg();
};

