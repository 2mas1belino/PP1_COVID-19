#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gestaoTestagem.h"

tipoTeste *lerFichBinTestes(tipoTeste *vetorTeste, int *numTestes, int *numTestesAgendados, int *numTestesRealizados)
{
    FILE *ficheiro;

    ficheiro = fopen("dadosTeste.bin","rb");
    if (ficheiro == NULL)
    {
        printf ("\n\nERRO: N�o foi poss�vel abrir o ficheiro \"dadosMembros.bin\"!");
    }
    else
    {
        fread(&(*numTestes),sizeof(int),1,ficheiro);
        vetorTeste = realloc(vetorTeste, (*numTestes) * sizeof(tipoTeste));
        if (vetorTeste == NULL && *numTestes != 0)
        {
            printf("\n\nERRO: Erro ao reservar a memoria (1)!");
            *numTestes = 0;
        }
        else
        {
            fread(&*numTestesAgendados,sizeof(int),1,ficheiro);
            fread(&*numTestesRealizados,sizeof(int),1,ficheiro);
            fread(vetorTeste,sizeof(tipoTeste),*numTestes,ficheiro);
        }
        fclose(ficheiro);
    }
    return vetorTeste;
}

void escreverFichBinTestes(tipoTeste *vetorTeste, int numTestes, int numTestesAgendados, int numTestesRealizados)
{
    int controlo;
    FILE *ficheiro;

    ficheiro = fopen("dadosTeste.bin", "wb");
    if(ficheiro == NULL)
        printf ("\n\nERRO: N�o foi poss�vel abrir o ficheiro \"dadosTeste.bin\"!");
    else
    {
        controlo = fwrite(&numTestes,sizeof(int),1,ficheiro);
        if (controlo != 1)
            printf("\n\nERRO: Falha na escrita dos dados (1)!");
        else
        {
            controlo = fwrite(&numTestesAgendados,sizeof(int),1,ficheiro);
            controlo = fwrite(&numTestesRealizados,sizeof(int),1,ficheiro);
            controlo = fwrite(vetorTeste,sizeof(tipoTeste),numTestes,ficheiro);
            if(controlo != numTestes)
            {
                printf("\n\nERRO: Falha na escrita dos dados (3)!");
            }
            else
            {
                printf("\n\nMENSAGEM: Grava��o feita com sucesso.\n\n");
            }
            fclose(ficheiro);
        }
    }
}
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
        fprintf(ficheiro, "\n\n==================================\n\n");
        fclose(ficheiro);
    }
}

void listarUmTeste(tipoTeste vetorTeste[], int numTestes, tipoMembro vetorMembro[], int numMembros)
{
    int posicaoTeste = 0, posicaoMembro = 0;
    char designacao[MAX_STRING];

    printf("\n-------- MOSTRAR DADOS DO TESTES -------- ");

    if(numTestes == 0)
        printf("\nATEN��O: Ainda n�o foram inseridos testes.");
    else
    {
        do
        {
            lerString(" \n\nIndique a designa��o do teste: ", designacao, MAX_STRING, SIM);

            posicaoTeste = pesquisaTeste(vetorTeste,numTestes,designacao);

            if(posicaoTeste == -1)
            {
                printf(" \n\nERRO: A designa��o indicada nao corresponde a nenhum teste.\n");
            }
        }
        while(posicaoTeste == -1);

        posicaoMembro = pesquisaMembro(vetorMembro, numMembros,vetorTeste[posicaoTeste].numUtente);

        printf("\n\n---------------------------------------------------------------------------------------------\n");
        printf(" \n\t\tDesigna��o: %s", vetorTeste[posicaoTeste].designacao);
        printf(" \n\t\tN�mero de Utente do membro: %-5d", vetorTeste[posicaoTeste].numUtente);
        printf(" \n\t\tNome do Membro: %s", vetorMembro[posicaoMembro].nome);
        printf(" \n\t\tEntidade:");
        if(vetorMembro[posicaoMembro].entidade == ESTUDANTE)
            printf(" Estudante;");
        else if(vetorMembro[posicaoMembro].entidade == DOCENTE)
            printf(" Docente;");
        else
            printf(" T�cnico;");
        printf(" \n\t\tTeste: ");
        if(vetorTeste[posicaoTeste].teste == TESTE_PCR)
            printf("PCR");
        else
            printf("ANTIG�NIO");
        printf(" \n\t\tData do Teste: ");
        escreverData(vetorTeste[posicaoTeste].dataRealizacao);
        printf(" \n\t\tHora de Colheita do Teste: ");
        escreverHora(vetorTeste[posicaoTeste].horaColheita);
        printf(" \n\t\tDura��o do Teste: %d ", vetorTeste[posicaoTeste].tempoDuracao);

        switch(vetorTeste[posicaoTeste].resultado)
        {
        case POSITIVO:
            printf(" \n\t\tResultado: POSITIVO");
            break;
        case NEGATIVO:
            printf(" \n\t\tResultado: NEGATIVO");
            break;
        case INCONCLUSIVO:
            printf(" \n\t\tResultado: INCONCLUSIVO");
            break;
        default:
            printf(" \n\t\tResultado: SEM RESULTADO");
        }
        printf("\n\n---------------------------------------------------------------------------------------------\n");

    }
}

void listarTestes(tipoTeste vetorTeste[], int numTestes)
{
    printf("\n-------- MOSTRAR DADOS TESTES -------- ");

    if(numTestes == 0)
        printf("\nATEN��O: Ainda n�o foram inseridos testes.");
    else
    {
        for(int i = 0; i < numTestes; i++)
        {
            printf("\n\n---------------------------------------------------------------------------------------------\n");
            printf(" \n\t\tDesigna��o: %s", vetorTeste[i].designacao);
            printf(" \n\t\tN�mero de Utente do membro: %-5d", vetorTeste[i].numUtente);
            printf(" \n\t\tTeste: ");
            if(vetorTeste[i].teste == TESTE_PCR)
                printf("PCR");
            else
                printf("ANTIG�NIO");
            printf(" \n\t\tData do Teste: ");
            escreverData(vetorTeste[i].dataRealizacao);
            printf(" \n\t\tHora de Colheita do Teste: ");
            escreverHora(vetorTeste[i].horaColheita);
            printf(" \n\t\tDura��o do Teste: %d ", vetorTeste[i].tempoDuracao);
            switch(vetorTeste[i].resultado)
            {
            case POSITIVO:
                printf(" \n\t\tResultado: POSITIVO");
                break;
            case NEGATIVO:
                printf(" \n\t\tResultado: NEGATIVO");
                break;
            case INCONCLUSIVO:
                printf(" \n\t\tResultado: INCONCLUSIVO");
                break;
            default:
                printf(" \n\t\tResultado: SEM RESULTADO");
            }
            printf("\n\n---------------------------------------------------------------------------------------------\n");
        }
    }
}

int pesquisaTeste(tipoTeste vetorTeste[], int numTestes, char desiganacaoTeste[])
{
    int posicao = -1;

    for(int i = 0; i < numTestes; i++)
    {
        if(strcmp(vetorTeste[i].designacao,desiganacaoTeste) == 0)
        {
            posicao = i;
            i = numTestes;
        }
    }
    return posicao;
}

void atualizarTeste(tipoTeste vetorTeste[], int *numTestes, tipoMembro vetorMembro[], int numMembros, int *numTestesAgendados, int *numTestesRealizados)
{
    char desiganacaoTeste[MAX_STRING];
    int posicaoTeste, manterValores = 0, posicaoMembro, resultadoTesteAntigo;

    if(*numTestes == 0)
        printf("\n\nERRO: N�o existem testes registados.\n");
    else
    {
        lerString("\n Indique o c�digo do Teste: ", desiganacaoTeste, MAX_STRING, SIM);
        posicaoTeste = pesquisaTeste(vetorTeste, *numTestes, desiganacaoTeste);
        if(posicaoTeste != -1)
        {

            printf("\nDeseja manter o mesmo numero de utente? ( %d )\n[1] - Sim; \n[2] - N�o\n\nEscolha uma das op��es: ",vetorTeste[posicaoTeste].numUtente);
            manterValores = lerInteiro("",1,2,NAO);
            if(manterValores == 2)
            {
                do
                {
                    vetorTeste[posicaoTeste].numUtente = lerInteiroDigitos("\nInsira o N�mero de Utente: ",9, NAO);
                    posicaoMembro = pesquisaMembro(vetorMembro, numMembros, vetorTeste[posicaoTeste].numUtente);
                    if(posicaoMembro == -1)
                        printf("\n\nERRO: N�mero de Utente inv�lido!");

                }
                while(posicaoMembro == -1);

                manterValores = 0;
            }

            printf("\nDeseja manter a mesma data do teste? ( ");
            escreverData(vetorTeste[posicaoTeste].dataRealizacao);
            manterValores = lerInteiro(" )\n[1] - Sim; \n[2] - N�o\n\nEscolha uma das op��es: ",1,2,NAO);
            if(manterValores == 2)
            {
                vetorTeste[posicaoTeste].dataRealizacao = lerData("\nInsira a nova Data de Realiza��o do Teste: ", ANO_ATUAL, ANO_ATUAL);
                manterValores = 0;
            }

            printf("\nDeseja manter a mesma hora de colheita? ( ");
            escreverHora(vetorTeste[posicaoTeste].horaColheita);
            manterValores = lerInteiro(" )\n[1] - Sim; \n[2] - N�o\n\nEscolha uma das op��es: ",1,2,NAO);
            if(manterValores == 2)
            {
                vetorTeste[posicaoTeste].horaColheita = lerHoraCompleta("\nInsira a nova Hora de Colheita do Teste: ", MIN_HORA, MAX_HORA, MIN_MINUTO, MAX_MINUTO);
                manterValores = 0;
            }

            printf("\nDeseja manter o mesmo Tempo de Dura��o? ( %d )", vetorTeste[posicaoTeste].tempoDuracao);
            manterValores = lerInteiro(" )\n[1] - Sim; \n[2] - N�o\n\nEscolha uma das op��es: ",1,2,NAO);
            if(manterValores == 2)
            {
                vetorTeste[posicaoTeste].tempoDuracao = lerInteiro("\nInsira o tempo de dura��o do Teste: ", MIN_MINUTO, MAX_MINUTO, NAO);
                manterValores = 0;
            }


            resultadoTesteAntigo = vetorTeste[posicaoMembro].resultado;

            printf("\nDeseja manter o resultado do teste? ");

            switch(vetorTeste[posicaoMembro].resultado)
            {
            case NEGATIVO:
                printf("( Negativo );");
                break;
            case POSITIVO:
                printf("( Positivo );");
                break;
            case INCONCLUSIVO:
                printf("( Inconclusivo );");
                break;
            case SEM_RESULTADO:
                printf("( Sem resultado );");
                break;
            }
            manterValores = lerInteiro("\n[1] - Sim; \n[2] - N�o\n\nEscolha uma das op��es: ",1,2,NAO);

            if(manterValores == 2)
            {
                vetorTeste[posicaoTeste].resultado = lerInteiro("\nIndique o resultado do teste:\n[1] - Negativo; \n[2] - Positivo; \n[3] - Inconlusivo", NEGATIVO, INCONCLUSIVO,NAO);
                manterValores = 0;
                if(resultadoTesteAntigo == -1 && vetorTeste[posicaoMembro].resultado != -1)
                {
                    (*numTestesAgendados)--;
                    (*numTestesRealizados)++;
                }
                if(resultadoTesteAntigo != -1 && vetorTeste[posicaoMembro].resultado == -1)
                {
                    (*numTestesAgendados)++;
                    (*numTestesRealizados)--;
                }
            }

            posicaoMembro = pesquisaMembro(vetorMembro, numMembros, vetorTeste[posicaoTeste].numUtente);

            printf("\n\nPOSICAO MEMBRO %d", posicaoMembro);
            printf("\n\nEstado confinamento %d", vetorMembro[posicaoMembro].estadoConfinamento);

            switch(vetorTeste[posicaoTeste].resultado)
            {
            case POSITIVO:
                vetorMembro[posicaoMembro].estadoConfinamento = ISOLAMENTO;
                break;
            case INCONCLUSIVO:
                vetorMembro[posicaoMembro].estadoConfinamento = QUARENTENA;
                break;
            case NEGATIVO:
                vetorMembro[posicaoMembro].estadoConfinamento = NAO_CONFINADO;
                break;
            }
        }
        else
            printf("\n\nERRO: A designa��o indicada n�o corresponde a nenhum teste!");
    }
}

tipoTeste *agendarTeste(tipoTeste *vetorTeste, tipoMembro vetorMembro[], int *numTestes, int *numTestesDiario, int numMembros, int *numTestesRealizados, int *numTestesAgendados)
{
    tipoTeste *pTeste, dados;
    int posicaoMembro, verificaDesignacao;

    pTeste = vetorTeste;

    if(numMembros == 0)
        printf("\n\nERRO: Nenhum membro registado, por favor registe um membro!");
    else if(*numTestesDiario >= MAX_TESTES_PCR)
        printf("\n\nERRO: Limite maximo de testes PCR realizados!");
    else
    {
        dados = leDadosTeste();
        posicaoMembro = pesquisaMembro(vetorMembro,numMembros, dados.numUtente);
        verificaDesignacao = pesquisaTeste(vetorTeste, *numTestes, dados.designacao);

        if(posicaoMembro != -1)
        {
            if(verificaDesignacao == -1)
            {
                vetorTeste = realloc(vetorTeste, (*numTestes+1)*sizeof(tipoTeste));
                if(vetorTeste == NULL)
                {
                    printf("\nERRO: imposs�vel alocar memoria para o teste.");
                    vetorTeste = pTeste;
                }
                else
                {
                    vetorTeste[*numTestes] = dados;

                    if(vetorTeste[*numTestes].resultado == -1)
                        (*numTestesAgendados)++;
                    else
                        (*numTestesRealizados)++;

                    if(vetorTeste[*numTestes].teste == TESTE_PCR)
                        (*numTestesDiario)++;

                    switch(vetorTeste[*numTestes].resultado)
                    {
                    case POSITIVO:
                        vetorMembro[posicaoMembro].estadoConfinamento = ISOLAMENTO;
                        logTestagem(vetorTeste[*numTestes], vetorMembro[posicaoMembro], " POSITIVO");
                        break;
                    case INCONCLUSIVO:
                        vetorMembro[posicaoMembro].estadoConfinamento = QUARENTENA;
                        logTestagem(vetorTeste[*numTestes], vetorMembro[posicaoMembro], " INCONCLUSIVO");
                        break;
                    case NEGATIVO:
                        vetorMembro[posicaoMembro].estadoConfinamento = NAO_CONFINADO;
                        logTestagem(vetorTeste[*numTestes], vetorMembro[posicaoMembro], " NEGATIVO");
                        break;
                    }
                    (*numTestes)++;
                }
            }
            else
                printf("\n\nERRO: Designa��o j� existente. A designa��o de um teste tem que ser unica!");
        }
        else
            printf("\n\nERRO: N�mero de Utente indicado n�o est� associado a nenhum Membro!");
    }
    return vetorTeste;
}

tipoTeste leDadosTeste()
{
    tipoTeste teste;
    int testeRealizado;

    teste.numUtente = lerInteiroDigitos("\nInsira o n�mero de utente do membro: ",9,SIM);
    lerString("\nIndique a designa��o do teste: ", teste.designacao, MAX_STRING, SIM);
    teste.dataRealizacao = lerData("\nInsira a Data de Realiza��o do Teste: ", ANO_ATUAL, ANO_ATUAL);
    teste.horaColheita = lerHoraCompleta("\nInsira a hora de colheita do Teste: ",MIN_HORA, MAX_HORA, MIN_MINUTO, MAX_MINUTO);
    teste.tempoDuracao = lerInteiro("\nInsira o tempo de dura��o do Teste: ", MIN_MINUTO, MAX_MINUTO, SIM);
    teste.teste = lerInteiro("\n[1] - PCR; \n[2] - Antig�nio; \n\nEscolha uma das op��es: ",TESTE_PCR,TESTE_ANTIGENIO,SIM);
    testeRealizado = lerInteiro("\nJ� possui o resultado do teste?\n[1] - Sim; \n[2] - N�o\n\nEscolha uma das op��es: ",1,2,SIM);
    if(testeRealizado == 2)
        teste.resultado = -1; // caso o utilizador nao indique o resultado
    else
        teste.resultado = lerInteiro("\nIndique o resultado do teste:\n[1] - Negativo; \n[2] - Positivo; \n[3] - Inconlusivo. \n\nEscolha uma das op��es: ", NEGATIVO, INCONCLUSIVO,SIM);
    return teste;
}
