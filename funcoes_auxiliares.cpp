#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "funcoes_auxiliares.h"
#include "corretor.h"
#include "imovel.h"
#include "tipoImovel.h"
using namespace std;

//método para leitura das entradas referentes aos corretores 
void lerCorretores(vector<Corretor*>& corretores){
    int num_corretores;
    cin >> num_corretores;

    for(int ii = 0; ii<num_corretores; ii++){
        string linha;
        // ler telefone, avaliador, lat, lon
        string telefone; int avaliador; double lat, lng;
        cin >> telefone >> avaliador >> lat >> lng;
        string nome;
        getline(cin >> std::ws, nome); // lê o restante da linha como nome completo

        corretores.push_back(new Corretor(telefone, avaliador, lat, lng, nome));
    }
}

//Metodo de leitura dos imoveis 
void lerImoveis(vector<Imovel*>& imoveis){
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
void distribuirImoveis(vector<vector<Imovel *>> &imoveisDistribuidos, vector<Imovel *> &imoveis, vector<Corretor *> &avaliadores){
    for(size_t ii = 0; ii < imoveis.size(); ii++){
        //a função mod garante a distribuição circular dos imóveis, voltando para o primeiro avaliador quando todos já tiverem sido percorridos
        size_t id_avaliador = ii % avaliadores.size();
        imoveisDistribuidos[id_avaliador].push_back(imoveis[ii]);
    }
}


constexpr double EARTH_R = 6371.0; // Raio da Terra em km

double haversine(double lat1, double lon1, double lat2, double lon2) {
    auto deg2rad = [](double d){ return d * M_PI / 180.0; };
    double dlat = deg2rad(lat2 - lat1);
    double dlon = deg2rad(lon2 - lon1);
    double a = std::pow(std::sin(dlat/2), 2) +
               std::cos(deg2rad(lat1)) * std::cos(deg2rad(lat2)) *
               std::pow(std::sin(dlon/2), 2);
    double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));
    return EARTH_R * c;
}

vector<vector<Imovel* >> agendaVisitas(avaliadores.size());
for(int ii=0; ii<avaliadores.size(); ii++){
    for(const auto& c: imoveisDistribuidos){
        int idImovel = 0;
        double menorDist = std::numeric_limits<double>::max();
        for(int jj = 0; jj<c.size(); jj++){
            if(!c[jj].visitado){
                double d = haversine(avaliadores[ii].getLat(), avaliadores[ii].getLng(), c[jj].getLat(), c[jj].getLng());
                if (d < menorDist) {
                    menorDist = d;
                    idImovel = jj;
                }
                
            }
        }
        for(int jj = 0; jj<c.size(); jj++){
            if(jj==idImovel){
                agendaVisitas[ii].push_back(c[jj]);
            }
        }

    }
}

std::vector<std::vector<Imovel*>> agendaVisitas(avaliadores.size());

for (int ii = 0; ii < avaliadores.size(); ii++) {
    double latAtual = avaliadores[ii].lat;
    double lngAtual = avaliadores[ii].lng;

    // Enquanto houver imóveis atribuídos a este avaliador
    while (true) {
        int idImovel = -1;
        double menorDist = std::numeric_limits<double>::max();

        for (int jj = 0; jj < imoveisDistribuidos[ii].size(); jj++) {
            Imovel* imv = imoveisDistribuidos[ii][jj];
            if (!imv->visitado) {
                double d = haversine(latAtual, lngAtual, imv->getLat(), imv->getLng());
                if (d < menorDist) {
                    menorDist = d;
                    idImovel = jj;
                }
            }
        }

        if (idImovel == -1) break; // todos visitados

        Imovel* next = imoveisDistribuidos[ii][idImovel];
        next->visitado = true;
        agendaVisitas[ii].push_back(next);

        latAtual = next->getLat();  // atualiza posição para o próximo cálculo
        lngAtual = next->getLng();
    }
}