#include <iostream>
#include <string>
#include "cliente.h"
using namespace std;

int Cliente::nextId = 1;

Cliente::Cliente(string telefone, string nome){
    this->id = nextId++;
    this->telefone = telefone;
    this->nome = nome;
}

void Cliente::setTelefone(string new_telefone){
    this->telefone = new_telefone;
}