# Real-Estate-System

Este projeto simula o funcionamento de uma imobiliária, permitindo o cadastro de corretores, clientes e imóveis, além de organizar a agenda de visitas dos avaliadores com base na localização e tempo de deslocamento.

## Funcionalidades

- Cadastro de corretores (avaliadores), clientes e imóveis
- Distribuição dos imóveis entre os avaliadores
- Cálculo de distâncias geográficas usando a fórmula de Haversine
- Agendamento de visitas com base no algoritmo do vizinho mais próximo
- Impressão da agenda com horários organizados

## Estrutura do Projeto

- `main.cpp`: Função principal e controle de execução
- `corretor.{h,cpp}`: Classe do corretor (avaliador)
- `cliente.{h,cpp}`: Classe do cliente
- `imovel.{h,cpp}`: Classe dos imóveis
- `tipoImovel.{h,cpp}`: Enumeração ou classe auxiliar para tipo de imóvel
- `funcoes_auxiliares.{h,cpp}`: Funções utilitárias como distribuição e agendamento
- `Makefile`: Script de build

## Como compilar

Abra o terminal no diretório do projeto e execute:

```bash
make
```

Para limpar os arquivos objeto e o executável:

```bash 
make clean
```


## Como executar 

Execute com um arquivo de entrada e compare com o gabarito 

```bash
./imobiliaria < teste1_entrada.txt > minha_saida1.txt
diff minha_saida1.txt teste1_saida.txt
```

## Sobre o agendamento

	•	O tempo de deslocamento entre imóveis é calculado como:
tempo = distância_em_km * 2 minutos
	•	Cada visita leva 60 minutos.
	•	O horário inicial dos avaliadores é 09:00 da manhã.

## Autores

Desenvolvido por Saulo Secundo e Yasmin Azevedo