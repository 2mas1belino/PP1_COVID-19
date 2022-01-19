#include <stdio.h>
#include <string.h>

#include "funcoesGenericas.h"
#include "gestaoMembros.h"
#include "gestaoTestagem.h"

int menuPrincipal(int nrMembros, int nrTestesAgendados, int nrTestesRealizados, int nrMembrosVacinados)
{

    int opcao;

    printf("\n**********************************************************");
    printf("\n*\t\t\tGESTAO COVID-19\t\t\t *");
    printf("\n**********************************************************");
    printf("\n   Membros registados: %4d\tTestes realizados: %4d", nrMembros, nrTestesRealizados);
    printf("\n   Testes agendados: %6d\tMembros vacinados: %4d", nrTestesAgendados, nrMembrosVacinados);
    printf("\n**********************************************************");
    printf("\n[1] - Gerir membros;");
    printf("\n[2] - Gerir Estados de vacinação;");
    printf("\n[3] - Gerir Estados de confinamento;");
    printf("\n[4] - Gerir testes de diagnóstico;");
    printf("\n[5] - Gravar dados em ficheiro;");
    printf("\n[6] - Ler dados em ficheiro;");
    printf("\n[0] - Sair.");
    printf("\n\nEscolha uma das opções: ");

    scanf("%d",&opcao);
    limparBuffer();

    return opcao;
}

int menuMembros(int numMembros, int numMembrosVacinados)
{
    int opcao;

    printf("\n**********************************************************");
    printf("\n*\t\tGESTAO COVID-19 - MEMBROS\t\t *");
    printf("\n**********************************************************");
    printf("\n   Membros registados: %4d", numMembros);
    printf("\n   Membros vacinados: %4d", numMembrosVacinados);
    printf("\n**********************************************************");
    printf("\n[1] - Adicionar Membro;");
    printf("\n[2] - Listar todos Membros;");
    printf("\n[0] - Voltar.");
    printf("\n\nEscolha uma das opções: ");

    scanf("%d",&opcao);
    limparBuffer();

    return opcao;
}

int menuTestes(int numTestes, int numTestesAgendados, int numTestesRealizados)
{
    int opcao;

    printf("\n**********************************************************");
    printf("\n*\t\tGESTAO COVID-19 - TESTES\t\t *");
    printf("\n**********************************************************");
    printf("\n   Testes Realizados: %4d \tTestes Agendados: %4d\n   Total de Testes: %4d",numTestesRealizados, numTestesAgendados, numTestes);
    printf("\n**********************************************************");
    printf("\n[1] - Agendar Teste;");
    printf("\n[2] - Atualizar Teste;");
    printf("\n[3] - Listar Testes;");
    printf("\n[4] - Pesquisar um Teste;");
    printf("\n[0] - Voltar.");
    printf("\n\nEscolha uma das opções: ");

    scanf("%d",&opcao);
    limparBuffer();

    return opcao;
}

int menuConfinamento()
{
    int opcao;

    printf("\n**********************************************************");
    printf("\n*\t\tGESTAO COVID-19 - CONFINAMENTOS\t\t *");
    printf("\n**********************************************************");
    printf("\n[1] - Atualizar estado de Confinamento;");
    printf("\n[2] - Listar casos de Confinamento;");
    printf("\n[0] - Voltar.");
    printf("\n\nEscolha uma das opções: ");

    scanf("%d",&opcao);
    limparBuffer();

    return opcao;
}
