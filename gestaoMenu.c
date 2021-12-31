#include <stdio.h>
#include <string.h>
#include "gestaoMenu.h"
#include "funcoesGenericas.h"

void divisorCMD() {
    printf("\n\n=========================================================================================\n\n");
}

int menuPrincipal(int nrMembros, int nrTestesAgendados, int nrTestesRealizados, int nrMembrosVacinados) {

    int opcao;

    printf("\n**********************************************************");
    printf("\n*\t\t\tGESTAO COVID-19\t\t\t *");
    printf("\n**********************************************************");
    printf("\n   Membros registados: %4d\tTestes realizados: %4d", nrMembros, nrTestesRealizados);
    printf("\n   Testes agendados: %6d\tMembros vacinados: %4d", nrTestesAgendados, nrMembrosVacinados);
    printf("\n**********************************************************");
    printf("\n[1] - Gerir membros;");
    printf("\n[2] - Estados de vacinação;");
    printf("\n[3] - Estados de confinamento;");
    printf("\n[4] - Gerir testes de diagnóstico;");
    printf("\n[0] - Sair.");
    printf("\n\nEscolha uma das opções: ");

    scanf("%d",&opcao);
    limparBuffer();

    return opcao;
}

int menuMembros(int numMembros, int numMembrosVacinados) {
    divisorCMD();
    int opcao;

    printf("\n**********************************************************");
    printf("\n*\t\t\tGESTAO COVID-19 - MEMBROS\t *");
    printf("\n**********************************************************");
    printf("\n   Membros registados: %4d", numMembros);
    printf("\n   Membros vacinados: %4d", numMembrosVacinados);
    printf("\n**********************************************************");
    printf("\n[1] - Adicionar Membro;");
    printf("\n[2] - Listar todos Membros;");
    printf("\n[0] - Sair.");
    printf("\n\nEscolha uma das opções: ");

    scanf("%d",&opcao);
    limparBuffer();

    return opcao;
}

