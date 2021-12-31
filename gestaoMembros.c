#include <stdio.h>
#include <string.h>

#include "funcoesGenericas.h"
#include "gestaoMembros.h"

//int lerNumUtente

void lerDadosMembro(tipoMembro vetorMembros[], int *numMembros)
{

    printf("\n-------- REGISTAR MEMBRO -------- ");

    if (*numMembros == MAX_MEMBROS)
        printf("\n\nERRO: Limite m�ximo de membros registados atingidos!");
    else
    {
        vetorMembros[*numMembros].numUtente = lerInteiro("\n*N�mero de utente", 0, 999999999, SIM);
        //if numUtente j� existe perguntar se quer efetivamente adicionar um membro ou n�o
        lerSring("\n*Nome: ", vetorMembros[*numMembros].nome, MAX_STRING, SIM);
        vetorMembros[*numMembros].entidade = lerInteiro("\n*Entidade:\n\n\t0 - Estudante;\n\t1 - Docente;\n\t2 - T�cnico.\n\n\tEscolha uma das op��es", 0, 2, SIM);
        vetorMembros[*numMembros].dataNascimento = lerData("\n*Data de nascimento (Formato: dd/mm/aaaa):", MIN_ANO, MAX_ANO);
        vetorMembros[*numMembros].estadoConfinamento = lerInteiro("\n*Estado de confinamento:\n\n\t0 - N�o confinado;\n\t1 - Confinado;\n\t2 - Quarentena.\n\n\tEscolha uma das op��es", 0, 2, SIM);
        vetorMembros[*numMembros].estadoVacinacao = lerInteiro("\n*Estado de vacina��o:\n\n\t0 - N�o vacinado;\n\t1 - Vacinado com primeira dose;\n\t2 - Vacinado com segunda dose;\n\t3 - Vacinado com terceira dose.\n\n\tEscolha uma das op��es", 0, 3, SIM);
        vetorMembros[*numMembros].ultimaVacina = lerData("\n*Data da �ltima vacina (Formato: dd/mm/aaaa):", 2019, ANO_ATUAL);
        (*numMembros)++;
    }
}

void listarDadosMembro(tipoMembro membro[], int numMembros) {
    printf("\n-------- MOSTRAR DADOS MEMBRO -------- ");

    if(numMembros == 0)
        printf("\nATEN��O: Ainda n�o foram inseridos membros.");
    else {
        for(int i = 0; i < numMembros; i++) {
            printf("\n\n---------------------------------------------------------------------------------------------\n");
            printf(" \nMembro numero: %-3d", i+1);
            printf(" \nN�mero de Utente: %-5d", membro[i].numUtente);
            printf(" \nNome: %s",membro[i].nome);
            printf(" \nData Nascimento: ");
            escreverData(membro[i].dataNascimento);
            printf(" \nEntidade:");
            if(membro[i].entidade = 0)
                printf(" Estudante.");
            else if(membro[i].entidade = 1)
                printf(" Docente.");
            else
                printf(" T�cnico.");

            printf(" \nEstado Confinamento ");
            if(membro[i].estadoConfinamento = 0)
                printf(" N�o Confinado.");
            else if(membro[i].estadoConfinamento = 1)
                printf(" Quarentena.");
            else
                printf(" Isolamento.");

            printf(" \nEstado Vacina��o ");
            if(membro[i].estadoVacinacao = 0)
                printf(" Sem Vacina.");
            else if(membro[i].estadoVacinacao = 1)
                printf(" 1� Dose da Vacina.");
            else if(membro[i].estadoVacinacao = 2)
                printf(" 2� Dose da Vacina.");
            else
                printf(" 3� Dose da Vacina.");
        }
    }
}







