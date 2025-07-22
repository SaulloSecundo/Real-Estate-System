#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <limits>
#include <iomanip>
#include "funcoes_auxiliares.h"

using namespace std;

constexpr double EARTH_R = 6371.0; // Raio da Terra em km

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
//método para leitura das entradas referentes aos clientes 
void lerClientes(vector<Cliente*> &clientes){
    int num_clientes;
    cin >> num_clientes;

    for(int ii = 0; ii<num_clientes; ii++){
        string linha;
        // ler telefone, avaliador, lat, lon
        string telefone;
        cin >> telefone;
        string nome;
        getline(cin >> std::ws, nome); // lê o restante da linha como nome completo

        clientes.push_back(new Cliente(telefone, nome));
    }
}

//método para leitura das entradas referentes aos 
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

//Função para conversão de um tempo total, em minutos, para horas e minutos faltantes
void hora_minuto(int &horas, int &minutos, int &tempo_acumulado, double distancia){
    int tempo_chegada = static_cast<int>(distancia * 2);
    
    int tempo_visita = tempo_acumulado + tempo_chegada;
    horas = tempo_visita / 60;
    minutos = tempo_visita % 60;

    tempo_acumulado = tempo_visita + 60; // 1h de visita após a chegada
}

//método para estruturar a agenda de visitas de cada corretor
//Aqui, os imóveis a serem visitados e seus respectivos horários de visita são organizados de forma a tornar eficiente o deslocamento de cada avaliador 
void definirAgenda(vector<Corretor *> &avaliadores, vector<vector<Imovel *>> &imoveisDistribuidos, vector<vector<Imovel*>> &agendaVisitas, vector<vector<Horario*>> &horarioVisitas){

    for (size_t ii = 0; ii < avaliadores.size(); ii++) {
        double latAtual = avaliadores[ii]->lat;
        double lngAtual = avaliadores[ii]->lng;

        int horas = 0;
        int minutos = 0;
        int tempo_acumulado = 9*60;

        // Enquanto houver imóveis atribuídos a este avaliador
        while (true) {
            int idImovel = -1;

            //atribui um valor do tipo double inicial à variável de controle da menor distância. 
            double menorDist = numeric_limits<double>::max();

            //percorre todos os imóveis de um determinado (ii) avaliador
            //Esse loop foi definido para conseguir a menor distância entre a posição atual do avaliador e um imóvel dentre um subconjuntos de imóveis ainda não visitados
            //Caso ainda existam imóveis não visitados, a distância é calculada e o id do imóvel mais próximo é armazenado
            for (size_t jj = 0; jj < imoveisDistribuidos[ii].size(); jj++) {
                Imovel* imv = imoveisDistribuidos[ii][jj];
                if (!imv->visitado) {
                    double d = haversine(latAtual, lngAtual, imv->getLat(), imv->getLng());
                    if (d < menorDist) {
                        menorDist = d;
                        idImovel = jj;
                    }
                }
            }

            //Para controle do loop (while). Se todos os imóveis de um determinado avaliador tiverem sido visitados, idImovel continuará sendo igual a -1 e o loop encerra

            if (idImovel == -1) break; // todos visitados

        
            Imovel* imovel_a_visitar = imoveisDistribuidos[ii][idImovel];
            imovel_a_visitar->visitado = true;
            agendaVisitas[ii].push_back(imovel_a_visitar);
            
            hora_minuto(horas, minutos, tempo_acumulado, menorDist); //calcula o horário em horas e minutos da visita registrada, dado o tempo acumulado em minutos;
            horarioVisitas[ii].push_back(new Horario(horas, minutos));

            latAtual = imovel_a_visitar->getLat();  // atualiza posição para o próximo cálculo
            lngAtual = imovel_a_visitar->getLng();
        }
    }
}

//método para imprimir os imóveis a serem visitados por cada corretor avaliador em seus respectivos horários 
void imprimirAgenda(vector<Corretor*> &avaliadores, vector<vector<Imovel *>> &agendaVisitas, vector<vector<Horario*>> &horarioVisitas){
    
    for(size_t ii = 0; ii < avaliadores.size(); ii++){
        std::cout << "Corretor " << avaliadores[ii]->getId() << std::endl;
        for(size_t jj = 0; jj < agendaVisitas[ii].size(); jj++){
            std::cout << std::setfill('0') << std::setw(2) << horarioVisitas[ii][jj]->hora << ":" 
                    << std::setw(2) << horarioVisitas[ii][jj]->minuto << " Imóvel " << agendaVisitas[ii][jj]->getId() << std::endl;
        }
        if(ii < (avaliadores.size() - 1)){
            cout<<endl;
        }
    }
}

//método para desalocar os objetos criados com "new" nas ED vector
//utilizado para liberar a memória alocada pelos processos anteriores
void DesalocarObjetos(vector<Corretor*> &corretores, vector<Cliente*> &clientes, vector<Imovel*> &imoveis, vector<vector<Horario*>> &horarioVisitas) {
    // Deleta corretores
    for (Corretor* c : corretores)
        delete c;
    corretores.clear();

    // Deleta imóveis
    for (Imovel* imv : imoveis)
        delete imv;
    imoveis.clear();

    // Deleta objetos Horario* criados com new
    for (auto& vetorHorarios : horarioVisitas) {
        for (Horario* h : vetorHorarios)
            delete h;
        vetorHorarios.clear();
    }
    horarioVisitas.clear();
}