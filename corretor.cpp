#include <iostream>
#include <string>
#include "corretor.h"
using namespace std;

int Corretor::nextId = 1;

Corretor::Corretor(std::string telefone, bool avaliador, float lat, float lng, std::string nome){
    this->id = nextId++;
    this->telefone = telefone;
    this->avaliador = avaliador;
    this->lat = lat;
    this->lng = lng;
    this->nome = nome;
}

Corretor::setTelefone(string new_telefone){
    this->telefone = new_telefone;
}

int Corretor::getId(){
    return this->id;
}

bool Corretor::getAvaliador(){
    return this->avaliador;
}