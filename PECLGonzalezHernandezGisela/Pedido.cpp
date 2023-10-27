#include "Pedido.hpp"
#include <cstdlib>
#define NULL 0

Pedido::Pedido()
{
    this->esUrgente = (rand() % 2); 
    this->generarDNI();
    this->id = NULL;
    this->numSeg = NULL;
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

void Pedido::setNumSeg(){
    this->generarNumSeg( this->esUrgente);
    }

void Pedido::setId(){
    this->generarId( this->esUrgente);
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
//???
int Pedido::getId()
{
    return this->id;
}

void Pedido::mostrar()
{
    string urgencia = "estandar ";
    if(esUrgente){
        urgencia = "urgente";
    }
    if(!id==NULL){
    cout << "\t" << setw(10) << " El pedido " << id << " que pertenece a el DNI " << DNI << " con el numero de seguimiento "<< numSeg << " es de prioridad:" << urgencia << endl;
    }else{
         cout << "\t" << setw(10) << " El pedido " << "que pertenece a el DNI " << DNI << " es de prioridad:" << urgencia << endl;
    }
}

Pedido::~Pedido()
{
    
}

