#ifndef _TIPOIMOVEL_H_
#define _TIPOIMOVEL_H_

enum TipoImovel{
    CASA,
    APARTAMENTO,
    TERRENO
};

TipoImovel strToTipo(const std::string& tipoStr);
#endif