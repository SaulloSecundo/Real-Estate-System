#include <iostream>
#include <string>
#include <vector>
#include "funcoes_auxiliares.h"
#include "corretor.h"
#include "imovel.h"
#include "tipoImovel.h"
using namespace std;

//método para leitura das entradas referentes aos corretores 
void lerCorretores(std::vector<Corretor*>& corretores){
    int num_corretores;
    cin >> num_corretores;

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


void lerImoveis(std::vector<Imovel*>& imoveis){
    int num_imoveis;
    cin >> num_imoveis;

    for(int ii = 0; ii<num_imoveis; ii++){
        string tipo; int propId; double lat, lng, preco;
        cin >> tipo >> propId >> lat >> lng >> preco;
        string endereco;
        getline(cin >> std::ws, endereco);

        imoveis.push_back(new Imovel(tipo, propId, lat, lng, preco, endereco));
    }
}

//Este método é utilizado para filtrar os corretores 'avaliadores' da lista de corretores inseridos na entrada
void corretoresAvaliadores(std::vector<Corretor *> &avaliadores, std::vector<Corretor *> &corretores){

    for(const auto& c: corretores){
        if(c->getAvaliador()){
            avaliadores.push_back(c);
        }
    }
}
//Este método faz a distribuição (Round-Robin) de imóveis para cada avaliador filtrado da lista de corretores anteriormente
//Para isso, um vetor de vetor de imóveis é criado, onde cada linha contém os imóveis atribuídos a cada avaliador
void distribuirImoveis(std::vector<std::vector<Imovel *>> &imoveisDistribuidos, std::vector<Imovel *> &imoveis, std::vector<Corretor *> &avaliadores){
    for(size_t ii = 0; ii < imoveis.size(); ii++){
        //a função mod garante a distribuição circular dos imóveis, voltando para o primeiro avaliador quando todos já tiverem sido percorridos
        size_t id_avaliador = ii % avaliadores.size();
        imoveisDistribuidos[id_avaliador].push_back(imoveis[ii]);
    }
}
