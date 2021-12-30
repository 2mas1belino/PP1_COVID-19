#include <stdio.h>
#include <string.h>
#include "gestaoMenu.h"
#include "funcoesGenericas.h"

int menuPrincipal(int nrMembros, int nrTestesAgendados, int nrTestesRealizados, int nrMembrosVacinados) {

    int opcao;

    printf("*************************************************");
    printf("\n*\t\tGESTAO COVID-19\t\t\t*");
    printf("\n*************************************************");
    printf("\n\n[1] - Estados de vacina��o;");
    printf("\n[2] - Estados de confinamento;");
    printf("\n[3] - Agendar teste de diagn�stico;");
    printf("\n[4] - Listar dados de testes de diagn�stico;");
    printf("\n[5] - Alterar a data de agendamento de teste de diagn�stico;");
    printf("\n[6] - Informa��es de testagem;");
    printf("\n[0] - Sair.");
    printf("\n\nEscolha uma das op��es: ");

    scanf("%c",opcao);
    limparBuffer();

    return opcao;
}
