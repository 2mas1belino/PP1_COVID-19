#ifndef GESTAOTESTAGEM_H_INCLUDED
#define GESTAOTESTAGEM_H_INCLUDED

#include "gestaoMembros.h"
#include "funcoesGenericas.h"

#define MAX_TESTES_PCR 15

#define TESTE_PCR 1
#define TESTE_ANTIGENIO 2

#define NEGATIVO 1
#define POSITIVO 2
#define INCONCLUSIVO 3
#define SEM_RESULTADO -1

#define NAO_CONFINADO 1
#define QUARENTENA 2
#define ISOLAMENTO 3

typedef struct {
    char designacao[MAX_STRING];
    int teste;
    tipoData dataRealizacao;
    int numUtente;
    int resultado;
    tipoHora horaColheita;
    int tempoDuracao;
}tipoTeste;

void listarUmTeste(tipoTeste vetorTeste[], int numTestes, tipoMembro vetorMembro[], int numMembros);
void logTestagem(tipoTeste teste, tipoMembro membro, char resultado[]);
tipoTeste *agendarTeste(tipoTeste *vetorTeste, tipoMembro vetorMembro[], int *numTestes, int *numTestesDiario, int numMembros, int *numTestesRealizados, int *numTestesAgendados);
tipoTeste leDadosTeste();
void atualizarTeste(tipoTeste vetorTeste[], int *numTestes, tipoMembro vetorMembro[], int numMembros, int *numTestesAgendados, int *numTestesRealizados);
int pesquisaTeste(tipoTeste vetorTeste[], int numTestes, char desiganacaoTeste[]);
void listarTestes(tipoTeste vetorTeste[], int numTestes);
void escreverFichBinTestes(tipoTeste *vetorTeste, int numTestes, int numTestesAgendados, int numTestesRealizados);
tipoTeste *lerFichBinTestes(tipoTeste *vetorTeste, int *numTestes, int *numTestesAgendados, int *numTestesRealizados);


#endif // GESTAOTESTAGEM_H_INCLUDED
