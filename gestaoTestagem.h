#ifndef GESTAOTESTAGEM_H_INCLUDED
#define GESTAOTESTAGEM_H_INCLUDED

#include "funcoesGenericas.h"

#define MAX_TESTES_PCR 15

#define TESTE_PCR 1
#define TESTE_ANTIGENIO 2

#define NEGATIVO 1
#define POSITIVO 2
#define INCONCLUSIVO 3

#define NAO_CONFINADO 1
#define QUARENTENA 2
#define ISOLAMENTO 3


typedef struct {
    int id;
    int teste;
    tipoData dataRealizacao;
    int numUtente;
    int resultado;
    tipoHora horaColheita;
    tipoHora tempoDuracao;
}tipoTeste;

void agendarTeste(tipoTeste vetorTeste[], tipoMembro vetorMembro[], int *numTestes, int *numTestesDiario, int numMembros);
void atualizarTeste(tipoTeste vetorTeste[], int *numTestes);
int pesquisaTeste(tipoTeste vetorTeste[], int numTestes, int idTeste);

#endif // GESTAOTESTAGEM_H_INCLUDED
