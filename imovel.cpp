#include <iostream>
#include <string>
#include "imovel.h"
#include "tipoImovel.h"
using namespace std;

int Imovel::nextId = 1;

Imovel::Imovel(string tipo, int proprietarioId, float lat, float lng, double preco, string endereco){
    this->id = nextId++;
    this->tipo = strToTipo(tipo);
    this->proprietarioId = proprietarioId;
    this->lat = lat;
    this->lng = lng;
    this->preco = preco;
    this->endereco = endereco;
}

int Imovel::getId(){
    return this->id;
}

float Imovel::getLat(){
    return this->lat;
}

float Imovel::getLng(){
    return this->lat;
}