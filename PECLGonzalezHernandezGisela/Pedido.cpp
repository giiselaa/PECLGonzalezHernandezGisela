#include "Pedido.hpp"
#include <cstdlib>

Pedido::Pedido()
{
    this->esUrgente = (rand() % 2); 
    this->generarDNI();
    this->id = 0;
    this->numSeg = 0;
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
    bool existe = false;
    
    if(esUrgente){
        id = (rand() % 49) + 51;
    }else{
        id = (rand() % 49) + 1;
    }
    
    for (int i = 0; i < tamanoArrayId; i++) {
        if (id == arrayId[i]) {
            existe = true;
        }
    }
    
     if (!existe) {
        if (tamanoArrayId < 48) {
            arrayId[tamanoArrayId] = id;
            tamanoArrayId++;
        }
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
    bool existe = false;
    
    if(esUrgente){
        numSeg = (rand() % 499) + 501;
    }else{
        numSeg = (rand() % 499) + 1;
    }
    
    for (int i = 0; i < tamanoArraySeg; i++) {
        if (numSeg == arraySeg[i]) {
            existe = true;
        }
    }
    
     if (!existe) {
        if (tamanoArraySeg < 48) {
            arraySeg[tamanoArraySeg] = numSeg;
            tamanoArraySeg++;
        }
     }
}

bool Pedido::esUrgenteP()
{
    return this->esUrgente;
}

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
    if(!id==0){
    cout << "\t" << setw(10) << " El pedido " << id << " que pertenece al DNI " << DNI << " con el numero de seguimiento "<< numSeg << " es de prioridad:" << urgencia << endl;
    }else{
         cout << "\t" << setw(10) << " El pedido " << "que pertenece al DNI " << DNI << " es de prioridad:" << urgencia << endl;
    }
}

Pedido::~Pedido()
{
    
}

