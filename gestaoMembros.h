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

#define DOSE1 1
#define DOSE2 2
#define DOSE3 3
#define SEM_VACINA 4

typedef struct {
    int numUtente;
    char nome[MAX_STRING];
    int entidade;
    tipoData dataNascimento;
    int estadoConfinamento;
    int estadoVacinacao;
    tipoData ultimaVacina;
}tipoMembro;

void escreverFichBinario(tipoMembro vetorMembros[], int numMembros);
void lerFichBinario(tipoMembro vetorMembros[], int *numMembros);
//void escreverFichTexto(tipoMembro vetorMembros[], int numMembros);

void registarMembro(tipoMembro vetorMembros[], int *numMembros);
void listarDadosMembro(tipoMembro membro[], int numMembros);
void atualizarEstadoVacinacao(tipoMembro membro[], int numMembros);
void atualizarEstadoConfinamento(tipoMembro membro[], int numMembros);
int pesquisaMembro(tipoMembro vetorMembro[], int numMembros, int numUtente);

#endif // GESTAOMEMBROS_H_INCLUDED
