#include <iostream>
#include <vector>
#include "corretor.h"
#include "imovel.h"
#include "cliente.h"
#include "funcoes_auxiliares.h"

using namespace std;

int main(){

    //EDs vector que serão úteis ao longo da execução do programa
    vector<Corretor*> corretores;
    vector<Cliente*> clientes;
    vector<Imovel*> imoveis;
    vector<Corretor*> avaliadores;
    vector<vector<Imovel*>> imoveisDistribuidos;
    vector<vector<Imovel*>> agendaVisitas;
    vector<vector<Horario*>> horarioVisitas;

    // leitura
    lerCorretores(corretores);
    lerClientes(clientes);
    lerImoveis(imoveis);

    // lógica para filtras os corretores avaliadores
    corretoresAvaliadores(avaliadores, corretores);

    // inicializa as linhas dos vetores 2D
    imoveisDistribuidos.resize(avaliadores.size());
    agendaVisitas.resize(avaliadores.size());
    horarioVisitas.resize(avaliadores.size());

    distribuirImoveis(imoveisDistribuidos, imoveis, avaliadores);
    definirAgenda(avaliadores, imoveisDistribuidos, agendaVisitas, horarioVisitas);


    // impressão
    imprimirAgenda(avaliadores, agendaVisitas, horarioVisitas);

    // desalocar
    DesalocarObjetos(corretores, clientes, imoveis, horarioVisitas);

    return 0;
}