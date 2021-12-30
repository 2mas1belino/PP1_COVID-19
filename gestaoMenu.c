#include <stdio.h>
#include <string.h>

#include "gestaoMenu.h"
#include "funcoesGenericas.h"

int menuPrincipal(int nrMembros, int nrTestesAgendados, int nrTestesRealizados, int nrMembrosVacinados){

    int opcao;

    printf("\n**********************************************************");
    printf("\n*\t\t GESTAO COVID-19\t\t\t *");
    printf("\n**********************************************************");
    printf("\nMembros registados: %4d\tTestes realizados: %4d", nrMembros, nrTestesRealizados);
    printf("\nTestes agendados: %6d\tMembros vacinados: %4d", nrTestesAgendados, nrMembrosVacinados);
    printf("\n**********************************************************");
    printf("\n[1] - Estados de vacinação;");
    printf("\n[2] - Estados de confinamento;");
    printf("\n[3] - Agendar teste de diagnóstico;");
    printf("\n[4] - Listar dados de testes de diagnóstico;");
    printf("\n[5] - Alterar a data de agendamento de teste de diagnóstico;");
    printf("\n[6] - Informações de testagem;");
    printf("\n[0] - Sair.");
    printf("\n\nEscolha uma das opções: ");

    scanf("%c",opcao);
    limparBuffer();

    return opcao;
}
