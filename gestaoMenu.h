#ifndef GESTAOMENU_H_INCLUDED
#define GESTAOMENU_H_INCLUDED

#include "funcoesGenericas.h"

int menuPrincipal(int nrMembros, int nrTestesAgendados, int nrTestesRealizados, int nrMembrosVacinados);
int menuMembros(int numMembros, int numMembrosVacinados);
int menuTestes(int numTestes, int numTestesAgendados, int numTestesRealizados);
int menuConfinamento();

#endif // GESTAOMENU_H_INCLUDED
