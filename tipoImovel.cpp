#include <iostream>
#include <string>
#include <algorithm>
#include "tipoImovel.h"
using namespace std;

TipoImovel strToTipo(const string& tipoStr){
    
    string tipo = tipoStr;
    transform(tipo.begin(), tipo.end(), tipo.begin(), ::tolower);

    if (tipo == "casa") return CASA;
    if (tipo == "apartamento") return APARTAMENTO;
    if (tipo == "terreno") return TERRENO;

    return INDEFINIDO; 
}