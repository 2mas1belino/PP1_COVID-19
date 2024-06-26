#ifndef FUNCOESGENERICAS_H_INCLUDED
#define FUNCOESGENERICAS_H_INCLUDED

#define SIM 1
#define NAO 0

#define MIN_HORA 0
#define MAX_HORA 24

#define MIN_MINUTO 0
#define MAX_MINUTO 59

typedef struct
{
    int hora, minuto;
} tipoHora;

typedef struct
{
    int dia, mes, ano;
} tipoData;

void lerString(char msg[], char texto[], int tamanho, int obrigatorio);
int lerInteiro (char msg[], int limMin, int limMax, int obrigatorio);
int lerInteiroDigitos (char msg[], int tamanho, int obrigatorio);
float lerFloat (char msg[], float limMin, float limMax);
tipoData lerData(char msg[], int minAno, int maxAno);
void escreverData (tipoData data);
void limparBuffer(void);
void divisorCMD();
int lerInteiroDigitos (char msg[], int tamanho, int obrigatorio);
tipoHora lerHoraCompleta(char msg[], int minHora, int maxHora, int minMinuto, int maxMinuto);
void escreverHora(tipoHora hora);

#endif // FUNCOESGENERICAS_H_INCLUDED
