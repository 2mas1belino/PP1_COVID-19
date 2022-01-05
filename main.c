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
    int numTestes = 0;
    int opcao = 54;

    do
    {
        opcao = menuPrincipal(numMembros, 1, 1, 1);
        switch(opcao)
        {
            case 1:
                opcao = menuMembros(numMembros, 1);
                switch (opcao)
                {
                case 1 :
                    divisorCMD();
                    registarMembro(vetorMembros, &numMembros);
                    break;
                case 2:
                      divisorCMD();
                      listarDadosMembro(vetorMembros, numMembros);
                      break;
                }
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
                opcao = menuTestes(numTestes);
                switch (opcao)
                {
                case 1 :
                    divisorCMD();
                    registarMembro(vetorMembros, &numMembros);
                    break;
                case 2:
                      divisorCMD();
                      listarDadosMembro(vetorMembros, numMembros);
                      break;
                }
                break;
            case 0:
                divisorCMD();
                break;
            default:
                printf("\nERRO: opção inválida\n\n");
        }
    } while(opcao != 0);
    return 0;
}
