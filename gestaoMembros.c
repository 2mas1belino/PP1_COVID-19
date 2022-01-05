#include <stdio.h>
#include <string.h>

#include "funcoesGenericas.h"
#include "gestaoMembros.h"
#include "gestaoTestagem.h"


int pesquisaMembro(tipoMembro vetorMembro[], int numMembros, int numUtente) {
    int posicao = -1;
    for(int i = 0; i < numMembros; i++) {
        if(numUtente == vetorMembro[i].numUtente) {
            posicao = i;
            i = numMembros;
        }
    }
    return posicao;
}

void atualizarEstadoConfinamento(tipoMembro vetorMembro[], int numMembros)
{
    int valorConfinamento, numUtente, posicaoMembro = -1;

    if(numMembros == 0)
        printf("\n\nERRO: N�o existem membros registados.\n\n");
    else
    {
        printf("\n**********************************************************");
        do
        {
            numUtente = lerInteiroDigitos("\nIndique o N�mero de Utente do membro: ",9,SIM);
            posicaoMembro = pesquisaMembro(vetorMembro,numMembros,numUtente);

            if(posicaoMembro == -1)
                printf("\nERRO: O N�mero de Utente inserido n�o � v�lido.");

        }
        while(posicaoMembro == -1);

        printf("\n**********************************************************");
        printf("\nIndique o Estado de Confinamento de %s", vetorMembro[posicaoMembro].nome);
        printf("\n[1] - N�o Confinado;");
        printf("\n[2] - Quarentena;");
        printf("\n[3] - Isolamento Profil�tico;");
        printf("\n[0] - Voltar.");
        printf("\n\nEscolha uma das op��es: ");

        valorConfinamento = lerInteiro("",0,ISOLAMENTO,SIM);

        if(valorConfinamento != 0){
            vetorMembro[posicaoMembro].estadoConfinamento = valorConfinamento;
            printf("\nEstado de vacina��o atualizado com sucesso.");
        }
    }
}

void atualizarEstadoVacinacao(tipoMembro vetorMembro[], int numMembros)
{
    int valorVacina, numUtente, posicaoMembro = -1;

    if(numMembros == 0)
        printf("\n\nERRO: N�o existem membros registados.\n\n");
    else
    {
        printf("\n**********************************************************");
        do
        {
            numUtente = lerInteiroDigitos("\nIndique o N�mero de Utente do membro: ",9 ,SIM);
            posicaoMembro = pesquisaMembro(vetorMembro,numMembros,numUtente);

            if(posicaoMembro == -1)
                printf("\nERRO: O N�mero de Utente inserido n�o � v�lido.");
        }
        while(posicaoMembro == -1);

        printf("\n**********************************************************");
        printf("\nIndique o Estado de Vacina��o de %s", vetorMembro[posicaoMembro].nome);
        printf("\n[1] - Primeira Dose;");
        printf("\n[2] - Segunda Dose;");
        printf("\n[3] - Terceira Dose;");
        printf("\n[4] - Sem Vacina;");
        printf("\n[0] - Voltar.");
        printf("\n\nEscolha uma das op��es: ");

        valorVacina = lerInteiro("",0,SEM_VACINA,SIM);

        if(valorVacina != 0)
            vetorMembro[posicaoMembro].estadoVacinacao = valorVacina;
            printf("\nEstado de vacina��o atualizado com sucesso.");
    }
}

void registarMembro(tipoMembro vetorMembros[], int *numMembros)
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

void listarDadosMembro(tipoMembro membro[], int numMembros)
{
    printf("\n-------- MOSTRAR DADOS MEMBRO -------- ");

    if(numMembros == 0)
        printf("\nATEN��O: Ainda n�o foram inseridos membros.");
    else
    {
        for(int i = 0; i < numMembros; i++)
        {
            printf("\n\n---------------------------------------------------------------------------------------------\n");
            printf(" \n\t\tMembro numero: %-3d", i+1);
            printf(" \n\t\tN�mero de Utente: %-5d", membro[i].numUtente);
            printf(" \n\t\tNome: %s",membro[i].nome);
            printf(" \n\t\tData Nascimento: ");
            escreverData(membro[i].dataNascimento);
            printf(" \n\t\tEntidade:");
            if(membro[i].entidade == ESTUDANTE)
                printf(" Estudante;");
            else if(membro[i].entidade == DOCENTE)
                printf(" Docente;");
            else
                printf(" T�cnico;");

            printf(" \n\t\tEstado Confinamento:");
            if(membro[i].estadoConfinamento == NAO_CONFINADO)
                printf(" N�o Confinado;");
            else if(membro[i].estadoConfinamento == QUARENTENA)
                printf(" Quarentena;");
            else
                printf(" Isolamento;");

            printf(" \n\t\tEstado Vacina��o:");
            if(membro[i].estadoVacinacao == SEM_VACINA)
                printf(" Sem Vacina;");
            else if(membro[i].estadoVacinacao == DOSE1)
                printf(" 1� Dose da Vacina;");
            else if(membro[i].estadoVacinacao == DOSE2)
                printf(" 2� Dose da Vacina;");
            else
                printf(" 3� Dose da Vacina;");
            printf("\n\n---------------------------------------------------------------------------------------------\n");

        }
    }
}
