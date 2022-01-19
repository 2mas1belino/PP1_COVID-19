#ifndef ESTRUTURAS_H_INCLUDED
#define ESTRUTURAS_H_INCLUDED

#include "funcoesGenericas.h"
#include "gestaoMembros.h"

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

#endif // ESTRUTURAS_H_INCLUDED
