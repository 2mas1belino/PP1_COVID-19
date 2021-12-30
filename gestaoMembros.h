#ifndef GESTAOMEMBROS_H_INCLUDED
#define GESTAOMEMBROS_H_INCLUDED

#include "funcoesGenericas.h"

#define MAX_STRING 50
#define MAX_MEMBROS 200

#define ESTUDANTE 0
#define DOCENTE 1
#define TECNICO 2

#define NAO_CONFINADO 0
#define QUARENTENA 1
#define ISOLAMENTO 2

#define SEM_VACINA 0
#define DOSE1 1
#define DOSE2 2
#define DOSE3 3

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


#endif // GESTAOMEMBROS_H_INCLUDED
