#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "funcoesGenericas.h"
#include "gestaoMenu.h"
#include "gestaoMembros.h"
#include "gestaoTestagem.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");

    tipoMembro vetorMembros[MAX_MEMBROS];
    tipoTeste *vetorTeste;

    vetorTeste = NULL;

    int numMembros = 0;
    int numTestes = 0, numTestesDiario = 0, numTestesRealizados = 0, numTestesAgendados = 0, numMembrosVacinados = 0;
    int opcao1, opcao2;

    lerFichBinario(vetorMembros, &numMembros);

    do
    {
        opcao1 = menuPrincipal(numMembros, numTestesAgendados, numTestesRealizados, numMembrosVacinados);
        switch(opcao1)
        {
        case 1:
            do
            {
                opcao2 = menuMembros(numMembros, numMembrosVacinados);
                switch (opcao2)
                {
                case 1 :
                    divisorCMD();
                    registarMembro(vetorMembros, &numMembros, &numMembrosVacinados);
                    break;
                case 2:
                    divisorCMD();
                    listarDadosMembro(vetorMembros, numMembros, vetorTeste, numTestes);
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
            atualizarEstadoVacinacao(vetorMembros, numMembros, &numMembrosVacinados);
            break;
        case 3:
            divisorCMD();
            atualizarEstadoConfinamento(vetorMembros, numMembros);
            break;
        case 4:
            divisorCMD();
            do
            {
                opcao2 = menuTestes(numTestes, numTestesAgendados, numTestesRealizados);
                switch (opcao2)
                {
                case 1 :
                    divisorCMD();
                    vetorTeste = agendarTeste(vetorTeste, vetorMembros, &numTestes, &numTestesDiario, numMembros, &numTestesRealizados, &numTestesAgendados);
                    break;
                case 2:
                    divisorCMD();
                    atualizarTeste(vetorTeste, &numTestes,vetorMembros,numMembros);
                    break;
                case 3:
                    divisorCMD();
                    listarTestes(vetorTeste,numTestes);
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

    free(vetorTeste);
    return 0;
}
