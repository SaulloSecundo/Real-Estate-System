#ifndef _FUNCOES_AUXILIARES_H_
#define _FUNCOES_AUXILIARES_H_

void lerCorretores(std::vector<Corretor *> &corretores);
void lerImoveis(std::vector<Imovel *> &imoveis);
void corretoresAvaliadores(std::vector<Corretor *> &avaliadores, std::vector<Corretor *> &corretores);
void distribuirImoveis(std::vector<std::vector<Imovel *>> &imoveisDistribuidos, std::vector<Imovel *> &imoveis, std::vector<Corretor *> &avaliadores);

#endif