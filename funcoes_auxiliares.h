#ifndef _FUNCOES_AUXILIARES_H_
#define _FUNCOES_AUXILIARES_H_

//para definir o horário (em horas e minutos) de cada visita
struct Horario {
    int hora;
    int minuto;

    Horario(int h = 0, int m = 0) : hora(h), minuto(m) {}
};

void lerCorretores(std::vector<Corretor *> &corretores);
void lerImoveis(std::vector<Imovel *> &imoveis);
void corretoresAvaliadores(std::vector<Corretor *> &avaliadores, std::vector<Corretor *> &corretores);
void distribuirImoveis(std::vector<std::vector<Imovel *>> &imoveisDistribuidos, std::vector<Imovel *> &imoveis, std::vector<Corretor *> &avaliadores);
void hora_minuto(int &horas, int &minutos, double distancia);
void definirAgenda(std::vector<Corretor *> &avaliadores, std::vector<std::vector<Imovel *>> &imoveisDistribuidos, std::vector<std::vector<Imovel*>> agendaVisitas, std::vector<std::vector<Horario*>> &horarioVisitas);
#endif