#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

#include "funcoesGenericas.h"
#include "gestaoMenu.h"
#include "gestaoMembros.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");

    tipoMembro vetorMembros[MAX_MEMBROS];
    int numMembros = 0;
    int numTestesRealizados = 0;
    int numTestesAgendados = 0;
    int numMembrosVacinados = 0;
    int opcao1, opcao2;

    do
    {
        opcao1 = menuPrincipal(numMembros, numTestesRealizados, numTestesAgendados, numMembrosVacinados);
        switch(opcao1)
        {
        case 1:
            do
            {
                opcao2 = menuMembros(numMembros, 1);
                switch (opcao2)
                {
                case 1 :
                    divisorCMD();
                    registarMembro(vetorMembros, &numMembros);
                    break;
                case 2:
                    divisorCMD();
                    listarDadosMembro(vetorMembros, numMembros);
                    break;
                case 0:
                    //fazer que volte para o menu principal
                    break;
                default:
                    printf("\n\nERRO: Opção inválida!\n\n");
                }
            }
            while(opcao2 != 0);
            break;
        case 2:
            divisorCMD();
            atualizarEstadoVacinacao(vetorMembros, numMembros);
            break;
        case 3:
            divisorCMD();
            atualizarEstadoConfinamento(vetorMembros, numMembros);
            break;
        case 4:
            divisorCMD();
            do
            {
                opcao2 = menuTestes(numTestesRealizados);
                switch (opcao2)
                {
                case 1 :
                    divisorCMD();
                    registarMembro(vetorMembros, &numMembros);
                    break;
                case 2:
                    divisorCMD();
                    listarDadosMembro(vetorMembros, numMembros);
                    break;
                default:
                    printf("\n\nERRO: Opção inválida!\n\n");
                }
            }
            while(opcao2 != 0);
            break;
        case 5:
            divisorCMD();
            escreverFichBinario(vetorMembros, numMembros);
            break;
        case 6:
            divisorCMD();
            lerFichBinario(vetorMembros, &numMembros);
            break;
        case 0:
            divisorCMD();
            break;
        default:
            printf("\n\nERRO: Opção inválida!");
        }
    }
    while(opcao1 != 0);
    return 0;
}
