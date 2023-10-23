#include "Pedido.hpp"
#include <cstdlib>

Pedido::Pedido()
{
    this->esUrgente = (rand() % 2); 
    this->generarDNI();
    this->generarId( this->esUrgente);
    this->generarNumSeg(this->esUrgente);
}

void Pedido::generarDNI()
{
    char letras[] = "TRWAGMYFPDXBNJZSQVHLCKE";
    int numDNI = 0, aux = 1E7;
    for(int i = 0; i < 8; i++) {
        int num = rand() % 10;
        this->DNI[i] = '0' + num;
        numDNI = numDNI + num * aux;
        aux /= 10;
    }
    this->DNI[8] = letras[numDNI % 23];
    this->DNI[9] = '\0';
}

void Pedido::generarId(bool esUrgente)
{
    if(esUrgente){
        id = (rand() % 49) + 51;
    }else{
        id = (rand() % 49) + 1;
    }
}

void Pedido::generarNumSeg(bool esUrgente)
{
    if(esUrgente){
        numSeg = (rand() % 499) + 501;
    }else{
        numSeg = (rand() % 499) + 1;
    }
}

bool Pedido::esUrgenteP()
{
    return this->esUrgente;
}

void Pedido::mostrar()
{
    string urgencia = "estandar ";
    if(esUrgente)
        urgencia = "urgente";
    cout << "\t" << setw(10) << " El pedido " << id << " que pertenece a el DNI " << DNI << " con el numero de seguimiento "<< numSeg << " es de prioridad:" << urgencia << endl;
}

Pedido::~Pedido()
{
    
}

