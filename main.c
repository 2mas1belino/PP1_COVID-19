#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "funcoesGenericas.h"
#include "gestaoMenu.h"
#include "gestaoMembros.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");

    tipoMembro vetorMembros[MAX_MEMBROS];
    int  numMembros = 0;
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
                      lerDadosMembro(vetorMembros, &numMembros);
                      break;
                case 2:
                      listarDadosMembro(vetorMembros, numMembros);
                      break;
                }
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 0:
                break;
            default:
                printf("\nERRO: opção inválida\n\n");
        }
    } while(opcao != 0);

    printf("BBBBB");
    return 0;
}
