#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "funcoesGenericas.h"
#include "gestaoMenu.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int opcao;

    opcao = menuPrincipal(2, 2, 2, 2);
    return 0;
}
