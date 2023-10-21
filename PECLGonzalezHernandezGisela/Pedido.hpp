#include <iostream>
#include <iomanip>

using namespace std;

class Pedido
{
public:
    Pedido();
    bool esUrgenteP();
    void mostrar();
    ~Pedido();
    
private:
    char DNI[10];
    bool esUrgente;
    int id;
    int numSeg;
    
    void generarDNI();
    void generarId(bool);
    void generarNumSeg(bool);
};

