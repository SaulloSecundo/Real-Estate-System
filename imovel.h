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
    float lat;
    float lng;
    TipoImovel tipo;
public:
    Imovel(std::string tipo, int proprietarioId, float lat, float lng, double preco, std::string endereco);
    int getId();
    float getLat();
    float getLng();
};
#endif