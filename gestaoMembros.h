#ifndef GESTAOMEMBROS_H_INCLUDED
#define GESTAOMEMBROS_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include "funcoesGenericas.h"

#define MIN_ANO 1900
#define MAX_ANO 2050
#define ANO_ATUAL 2022

#define MAX_STRING 50

#define MIN_MEMBROS 1
#define MAX_MEMBROS 200

#define ESTUDANTE 0
#define DOCENTE 1
#define TECNICO 2

#define DOSE1 1
#define DOSE2 2
#define DOSE3 3
#define SEM_VACINA 0

typedef struct {
    int numUtente;
    char nome[MAX_STRING];
    int entidade;
    tipoData dataNascimento;
    int estadoConfinamento;
    int estadoVacinacao;
    tipoData ultimaVacina;
}tipoMembro;

void escreverFichBinMembros(tipoMembro vetorMembros[], int numMembros, int numMembrosVacinados);
void lerFichBinMembros(tipoMembro vetorMembros[], int *numMembros, int *numMembrosVacinados);

void registarMembro(tipoMembro vetorMembros[], int *numMembros, int *numMembrosVacinados);
void listarDadosMembro(tipoMembro vetorMembro[], int numMembros);
void atualizarEstadoVacinacao(tipoMembro vetorMembro[], int numMembros, int *numMembrosVacinados);
void atualizarEstadoConfinamento(tipoMembro vetorMembro[], int numMembros);
int pesquisaMembro(tipoMembro vetorMembro[], int numMembros, int numUtente);

#endif // GESTAOMEMBROS_H_INCLUDED
