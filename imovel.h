#ifndef _IMOVEL_H_
#define _IMOVEL_H_
#include "tipoImovel.h"

class Imovel {
private:
    static int nextId;
    int id;
    int proprietarioId;
    std::string endereco;
    double preco;
    TipoImovel tipo;
public:
    float lat;
    float lng;
    Imovel(TipoImovel tipo, int proprietarioId, float lat, float lng, double preco, std::string endereco);
};
#endif