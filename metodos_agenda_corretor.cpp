#include <iostream>
#include <string>
#include "metodos_agenda_corretor.h"
#include "corretor.h"
#include "imovel.h"
#include "tipoImovel.h"
using namespace std;

void cin_Corretor(){
    int num_corretores;
    cin >> num_corretores;

    std::vector<Corretor*> corretores;

    for(int ii = 0; ii<num_corretores; ii++){
        std::string linha;
        // ler telefone, avaliador, lat, lon
        string telefone; int avaliador; double lat, lng;
        cin >> telefone >> avaliador >> lat >> lng;
        string nome;
        getline(cin >> std::ws, nome); // lê o restante da linha como nome completo

        corretores.push_back(new Corretor(telefone, avaliador, lat, lng, nome));
    }
}


void cin_Imovel(){
    int num_imoveis;
    cin >> num_imoveis;

    vector<Imovel*> imoveis;

    for(int ii = 0; ii<num_imoveis; ii++){
        string tipo; int propId; double lat, lng, preco;
        cin >> tipo >> propId >> lat >> lng >> preco;
        string endereco;
        getline(cin >> std::ws, endereco);

        imoveis.push_back(new Imovel(tipo, propId, lat, lng, preco, endereco));
    }
}
