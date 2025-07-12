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
    vector<Corretor*> avaliadores;
    vector<Cliente*> clientes;
    vector<Imovel*> imoveis;
    vector<vector<Imovel*>> imoveisDistribuidos;
    vector<vector<Imovel*>> agendaVisitas;
    vector<vector<Horario*>> horarioVisitas;


    lerCorretores(corretores);
    lerClientes(clientes);
    lerImoveis(imoveis);
    corretoresAvaliadores(avaliadores, corretores);
    distribuirImoveis(imoveisDistribuidos, imoveis, avaliadores);
    definirAgenda(avaliadores, imoveisDistribuidos, agendaVisitas, horarioVisitas);
    imprimirAgenda(avaliadores, agendaVisitas, horarioVisitas);
    DesalocarObjetos(corretores, clientes, imoveis, horarioVisitas);


    return 0;
}