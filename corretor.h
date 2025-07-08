#ifndef _CORRETOR_H_
#define _CORRETOR_H_

class Corretor {
private:
    static int nextId;
    int id;
    std::string telefone;
    std::string nome;
    bool avaliador;   
public:
    float lat;
    float lng;
    Corretor(std::string telefone, bool avaliador, float lat, float lng, std::string nome);
    void setTelefone(std::string new_telefone);
    int getId();
    bool getAvaliador();
};
#endif