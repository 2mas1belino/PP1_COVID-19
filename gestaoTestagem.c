#include <stdio.h>

#include "gestaoMembros.h"
#include "gestaoTestagem.h"

void logTestagem(tipoTeste teste, tipoMembro membro, char resultado[])
{
    FILE * ficheiro;

    ficheiro  = fopen("logTestagem.txt", "a");

    if (ficheiro == NULL)
    {
        printf("\n\nERRO: Não foi possível abrir o ficheiro \"logTestagem.txt\"!\n");
    }
    else
    {
        fprintf(ficheiro, "\nResultado: %s", resultado);
        fprintf(ficheiro, "\nNr. Utente: %d", teste.numUtente);
        fprintf(ficheiro, "\nNome: %s", membro.nome);
        fprintf(ficheiro, "\nEstado de Vacinação: %d", membro.estadoVacinacao);

        fclose(ficheiro);
    }
}

int pesquisaTeste(tipoTeste vetorTeste[], int numTestes, int idTeste){
    int posicao = -1;

    for(int i = 0; i < numTestes; i++) {
        if(idTeste == vetorTeste[i].id) {
            posicao = i;
            i = numTestes;
        }
    }
    return posicao;
}

void atualizarTeste(tipoTeste vetorTeste[], int *numTestes)
{
    int idTeste;
    int posicaoTeste;

    if(*numTestes == 0)
        printf("\n\nERRO: Não existem testes registados.\n");
    else {
        idTeste = lerInteiro("\n Indique o código do Teste: ", 1, vetorTeste[*numTestes-1].id, SIM);
        posicaoTeste = pesquisaTeste(vetorTeste, *numTestes, idTeste);
        vetorTeste[posicaoTeste].numUtente = lerInteiroDigitos("\nInsira o Número de Utente: ",9, SIM);
        vetorTeste[posicaoTeste].dataRealizacao = lerData("\nInsira a Data de Realização do Teste: ", ANO_ATUAL, ANO_ATUAL);
        vetorTeste[posicaoTeste].teste = lerInteiro("\n[1] - PCR; \n[2] - Antigénio;\n\nEscolha uma das opções: ",TESTE_PCR,TESTE_ANTIGENIO,SIM);
    }
}

void agendarTeste(tipoTeste vetorTeste[], tipoMembro vetorMembro[], int *numTestes, int *numTestesDiario, int numMembros)
{
    int numUtenteTemporario;
    int posicaoMembro;

    if(numMembros == 0)
        printf("\n\nERRO: Nenhum membro registado, por favor registe um membro!");
    else if(*numTestesDiario >= MAX_TESTES_PCR)
        printf("\n\nERRO: Limite maximo de testes PCR realizados!");
    else
    {
        if(*numTestes == 0)
            vetorTeste[*numTestes].id = 1;
        else
            vetorTeste[*numTestes-1].id += 1;

        numUtenteTemporario = lerInteiroDigitos("\nInsira o Número de Utente: ",9, SIM);

        posicaoMembro = pesquisaMembro(vetorMembro,numMembros, numUtenteTemporario);

        if(posicaoMembro != -1) {
            vetorTeste[*numTestes].numUtente = numUtenteTemporario;
            vetorTeste[*numTestes].dataRealizacao = lerData("\nInsira a Data de Realização do Teste: ", ANO_ATUAL, ANO_ATUAL);
            vetorTeste[*numTestes].teste = lerInteiro("\n[1] - PCR; \n[2] - Antigénio; \n\nEscolha uma das opções: ",TESTE_PCR,TESTE_ANTIGENIO,SIM);
            (*numTestes)++;
            if(vetorTeste[*numTestes].teste == TESTE_PCR)
                (*numTestesDiario)++;
        }
        else {
            printf("\n\nERRO: Número de Utente indicado não está associado a nenhum Membro!");
        }
    }
}
