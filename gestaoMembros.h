#ifndef GESTAOMEMBROS_H_INCLUDED
#define GESTAOMEMBROS_H_INCLUDED

#include "funcoesGenericas.h"

#define MAX_STRING 50

#define MIN_ANO 1900
#define MAX_ANO 2050
#define ANO_ATUAL 2022

#define MIN_MEMBROS 1
#define MAX_MEMBROS 200

#define ESTUDANTE 0
#define DOCENTE 1
#define TECNICO 2

#define NAO_CONFINADO 1
#define QUARENTENA 2
#define ISOLAMENTO 3

#define DOSE1 1
#define DOSE2 2
#define DOSE3 3
#define SEM_VACINA 4

#define TESTE_PCR 0
#define TESTE_ANTIGENIO 1

#define NEGATIVO 0
#define POSITIVO 1

typedef struct {
    int numUtente;
    char nome[MAX_STRING];
    int entidade;
    tipoData dataNascimento;
    int estadoConfinamento;
    int estadoVacinacao;
    tipoData ultimaVacina;
}tipoMembro;

typedef struct {
    int id;
    int teste;
    tipoData dataRealizacao;
    int numUtente;
    int resultado;
    tipoHora horaColheita;
    tipoHora tempoDuracao;
}tipoTeste;

void escreverFichBinario(tipoMembro vetorMembros[MAX_MEMBROS], int numMembros);
void escreveFichTexto(tipoMembro vetorMembros[MAX_MEMBROS], int numMembros);

void registarMembro(tipoMembro vetorMembros[], int *numMembros);
void listarDadosMembro(tipoMembro membro[], int numMembros);
void atualizarEstadoVacinacao(tipoMembro membro[], int numMembros);
void atualizarEstadoConfinamento(tipoMembro membro[], int numMembros);
void agendarTeste(tipoTeste teste[], tipoMembro membro[], int *numTestes);

#endif // GESTAOMEMBROS_H_INCLUDED
