#include <stdio.h>

#include "gestaoMembros.h"
#include "gestaoTestagem.h"

void logTestagem(tipoTeste teste, tipoMembro membro, char resultado[])
{
    FILE * ficheiro;

    ficheiro  = fopen("logTestagem.txt", "a");

    if (ficheiro == NULL)
    {
        printf("\n\nERRO: N�o foi poss�vel abrir o ficheiro \"logTestagem.txt\"!\n");
    }
    else
    {
        fprintf(ficheiro, "\nResultado: %s", resultado);
        fprintf(ficheiro, "\nNr. Utente: %d", teste.numUtente);
        fprintf(ficheiro, "\nNome: %s", membro.nome);
        fprintf(ficheiro, "\nEstado de Vacina��o: %d", membro.estadoVacinacao);

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
        printf("\n\nERRO: N�o existem testes registados.\n");
    else {
        idTeste = lerInteiro("\n Indique o c�digo do Teste: ", 1, vetorTeste[*numTestes-1].id, SIM);
        posicaoTeste = pesquisaTeste(vetorTeste, *numTestes, idTeste);
        vetorTeste[posicaoTeste].numUtente = lerInteiroDigitos("\nInsira o N�mero de Utente: ",9, SIM);
        vetorTeste[posicaoTeste].dataRealizacao = lerData("\nInsira a Data de Realiza��o do Teste: ", ANO_ATUAL, ANO_ATUAL);
        vetorTeste[posicaoTeste].teste = lerInteiro("\n[1] - PCR; \n[2] - Antig�nio;\n\nEscolha uma das op��es: ",TESTE_PCR,TESTE_ANTIGENIO,SIM);
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

        numUtenteTemporario = lerInteiroDigitos("\nInsira o N�mero de Utente: ",9, SIM);

        posicaoMembro = pesquisaMembro(vetorMembro,numMembros, numUtenteTemporario);

        if(posicaoMembro != -1) {
            vetorTeste[*numTestes].numUtente = numUtenteTemporario;
            vetorTeste[*numTestes].dataRealizacao = lerData("\nInsira a Data de Realiza��o do Teste: ", ANO_ATUAL, ANO_ATUAL);
            vetorTeste[*numTestes].teste = lerInteiro("\n[1] - PCR; \n[2] - Antig�nio; \n\nEscolha uma das op��es: ",TESTE_PCR,TESTE_ANTIGENIO,SIM);
            (*numTestes)++;
            if(vetorTeste[*numTestes].teste == TESTE_PCR)
                (*numTestesDiario)++;
        }
        else {
            printf("\n\nERRO: N�mero de Utente indicado n�o est� associado a nenhum Membro!");
        }
    }
}
