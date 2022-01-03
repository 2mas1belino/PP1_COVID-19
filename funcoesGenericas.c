#include <stdio.h>
#include <string.h>

#include "funcoesGenericas.h"

void divisorCMD()
{
    printf("\n\n=========================================================================================\n\n");
}

void lerSring(char msg[], char texto[], int tamanho, int obrigatorio)
{
    int tamTexto;

    do
    {
        printf(" %s", msg);
        fgets(texto, tamanho, stdin);
        tamTexto = strlen(texto);
        if (tamTexto == 1 && obrigatorio == SIM) // significa que o utilizador s� clicou no ENTER
            printf("\nERRO: O Campo � Obrigat�rio.\n");
    }
    while (tamTexto == 1 && obrigatorio == SIM);

    if (texto[tamTexto-1] != '\n')
        limparBuffer();
    else
        texto[tamTexto-1] = '\0';
}

void escreverData (tipoData data)
{
    printf("%02d/%02d/%d", data.dia, data.mes, data.ano);
}

tipoData lerData(char msg[], int minAno, int maxAno)
{
    tipoData data;
    int controlo, maxDia, erro = 0;

    do
    {
        erro = 0;
        do
        {
            printf(" %s", msg);
            controlo = scanf("%d/%d/%d", &data.dia, &data.mes, &data.ano);
            limparBuffer();
            if (controlo != 3) // retorno do scanf
                printf("\nERRO: Formato de Data Inv�lido.\n");
        }
        while (controlo != 3);

        if (data.ano < minAno || data.ano > maxAno)
        {
            printf("\nERRO: Ano Inv�lido\n");
            erro = 1;
        }
        else
        {
            switch(data.mes)
            {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                maxDia = 31;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                maxDia = 30;
                break;
            case 2:
                if (data.ano%400==0 || (data.ano%4==0 && data.ano%100!=0))
                    maxDia = 29;
                else
                    maxDia = 28;
                break;
            default:
                printf("\nERRO: M�s Inv�lido.\n");
                erro = 1;
            }
            if (data.dia < 1 || data.dia > maxDia)
            {
                printf("\nERRO: Dia inv�lido.\n");
                erro = 1;
            }
        }
    }
    while (erro);

    return data;
}


int lerInteiro (char msg[], int limMin, int limMax, int obrigatorio)
{
    int num, controlo;

    do
    {
        printf(" %s [%d, %d]: ", msg, limMin, limMax);
        controlo = scanf("%d", &num);
        if (controlo != 1)
            if(obrigatorio == SIM)
                printf("\nERRO: O campo � obrigat�rio.\n");
        limparBuffer();
        if (num < limMin || num > limMax)
            printf("\n\nERRO: O valor introduzido est� fora do intervalo solicitado.");
    }
    while (controlo != 1 || num < limMin || num > limMax);
    return num;
}

int lerInteiroDigitos (char msg[], int tamanho, int obrigatorio)
{
    int num, controlo, numDigitos;

    do
    {
        printf(" %s: ", msg);
        controlo = scanf("%d", &num);
        if (controlo != 1)
            if(obrigatorio == SIM)
                printf("\nERRO: O campo � obrigat�rio!\n");
        limparBuffer();

        numDigitos = 0;

        //divide o int por 10 "apagando" as casas unit�rias e conta � medida que as apaga at� que o int seja 0

        while(num!=0)
        {
            num/=10;
            numDigitos++;
        }

        if (numDigitos < tamanho || numDigitos > tamanho)
            printf("\nERRO: Insira um n�mero de utente v�lido!\n");
    }
    while (numDigitos < tamanho || numDigitos > tamanho);
    return num;
}

float lerFloat (char msg[], float limMin, float limMax)
{
    float num;
    int controlo;

    do
    {
        printf(" %s [%.2f, %.2f]: ", msg, limMin, limMax);
        controlo = scanf("%f", &num);
        limparBuffer();
        if (controlo != 1 || num < limMin || num > limMax)
            printf("\n\nERRO: O valor introduzido est� fora do intervalo solicitado.");
    }
    while (controlo != 1 || num < limMin || num > limMax);
    return num;
}


void limparBuffer(void)
{
    char chr;
    do
    {
        chr = getchar();
    }
    while (chr != '\n' && chr != EOF);
}
