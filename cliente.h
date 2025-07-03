#ifndef _CLIENTE_H_
#define _CLIENTE_H_

class Cliente {
private:
    static int nextId;
    int id;
    std::string telefone;
    std::string nome;    
public:
    Cliente(std::string telefone, std::string nome);
    void setTelefone(std::string new_telefone);
};

#endif