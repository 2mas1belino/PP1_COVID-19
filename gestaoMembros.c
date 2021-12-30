#include <stdio.h>
#include <string.h>

#include "funcoesGenericas.h"
#include "gestaoMembros.h"

//int lerNumUtente

void lerDadosMembro(tipoMembro vetorMembros[], int *numMembros)
{

    printf("\n-------- REGISTAR MEMBRO -------- ");
    int i;

    if (*numMembros == MAX_MEMBROS)
    {
        printf("\n\nERRO: Limite máximo de membros registados atingidos!");
    }
    else
    {
        vetorMembros[*numMembros].numUtente = lerInteiro("\n*Número de utente", 0, 999999999, SIM);
        //if numUtente já existe perguntar se quer efetivamente adicionar um membro ou não
        lerSring("\n*Nome: ", vetorMembros[i].nome, MAX_STRING, SIM);
        vetorMembros[*numMembros].entidade = lerInteiro("\n*Entidade:\n\n\t0 - Estudante;\n\t1 - Docente;\n\t2 - Técnico.\n\n\tEscolha uma das opções", 0, 2, SIM);
        vetorMembros[*numMembros].dataNascimento = lerData("\n*Data de nascimento (Formato: dd/mm/aaaa):", MIN_ANO, MAX_ANO);
        vetorMembros[*numMembros].estadoConfinamento = lerInteiro("\n*Estado de confinamento:\n\n\t0 - Não confinado;\n\t1 - Confinado;\n\t2 - Quarentena.\n\n\tEscolha uma das opções", 0, 2, SIM);
        vetorMembros[*numMembros].estadoVacinacao = lerInteiro("\n*Estado de vacinação:\n\n\t0 - Não vacinado;\n\t1 - Vacinado com primeira dose;\n\t2 - Vacinado com segunda dose;\n\t3 - Vacinado com terceira dose.\n\n\tEscolha uma das opções", 0, 3, SIM);
        vetorMembros[*numMembros].ultimaVacina = lerData("\n*Data da última vacina (Formato: dd/mm/aaaa):", 2019, ANO_ATUAL);
        (*numMembros)++;
    }
}
