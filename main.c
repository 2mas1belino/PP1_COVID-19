#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "funcoesGenericas.h"
#include "gestaoMenu.h"
#include "gestaoMembros.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int opcao, numMembros = 0;
    tipoMembro vetorMembros[MAX_MEMBROS];

    //opcao = menuPrincipal(numMembros, 1, 1, 1);
    lerDadosMembro(vetorMembros, &numMembros);
    return 0;
}
