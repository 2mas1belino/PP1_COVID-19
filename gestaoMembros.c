#include <stdio.h>
#include <string.h>

#include "funcoesGenericas.h"
#include "gestaoMembros.h"

/*void agendarTeste(tipoTeste teste[], tipoMembro membro[], int *numTestes){
    if(*numTestes >= 15) {
       printf("\n\nERRO: Limite maximo de testes realizados no dia ");
       escreverData(teste.dataRealizacao);
    }
}*/

void atualizarEstadoConfinamento(tipoMembro membro[], int numMembros) {
    int valorConfinamento, numUtente, posicaoMembro = -1;

    if(numMembros == 0)
        printf("\n\nERRO: Não existem membros registados.\n\n");
    else {
        printf("\n**********************************************************");
        do {
            printf("\nIndique o Número de Utente do membro: ");
            numUtente = lerInteiroDigitos("", 9, SIM);

            for(int i = 0; i <= numMembros; i++) {
                if(numUtente = membro[i].numUtente)
                    posicaoMembro = i;
            }

            if(posicaoMembro == -1)
                printf("\nERRO: O Número de Utente inserido não é válido.");

        } while(posicaoMembro == -1);

        printf("\n**********************************************************");
        printf("\nIndique o Estado de Confinamento de %s", membro[posicaoMembro].nome);
        printf("\n[1] - Não Confinado;");
        printf("\n[2] - Quarentena;");
        printf("\n[3] - Isolamento Profilático;");
        printf("\n[0] - Voltar.");
        printf("\n\nEscolha uma das opções: ");

        valorConfinamento = lerInteiro("",0,3,SIM);
        if(valorConfinamento == 0)
            return;
        else {
            membro[posicaoMembro].estadoConfinamento = valorConfinamento;
            printf("\nEstado de vacinação atualizado com sucesso.");
        }
    }
}

void atualizarEstadoVacinacao(tipoMembro membro[], int numMembros) {
    int valorVacina, numUtente, posicaoMembro = -1;

    if(numMembros == 0)
        printf("\n\nERRO: Não existem membros registados.\n\n");
    else {
        printf("\n**********************************************************");
        do {
            printf("\nIndique o Numero de Utente do membro: ");
            numUtente = lerInteiroDigitos("", 9, SIM);

            for(int i = 0; i <= numMembros; i++) {
                if(numUtente = membro[i].numUtente)
                    posicaoMembro = i;
            }

            if(posicaoMembro == -1)
                printf("\nERRO: O Número de Utente inserido não é válido.");

        } while(posicaoMembro == -1);

        printf("\n**********************************************************");
        printf("\nIndique o Estado de Vacinação de %s", membro[posicaoMembro].nome);
        printf("\n[1] - Primeira Dose;");
        printf("\n[2] - Segunda Dose;");
        printf("\n[3] - Terceira Dose;");
        printf("\n[4] - Sem Vacina;");
        printf("\n[0] - Voltar.");
        printf("\n\nEscolha uma das opções: ");

        valorVacina = lerInteiro("",0,4,SIM);

        if(valorVacina == 0) // Opção Voltar
            return;
        else {
            membro[posicaoMembro].estadoVacinacao = valorVacina;
            printf("\nEstado de vacinação atualizado com sucesso.");
        }
    }
}

void registarMembro(tipoMembro vetorMembros[], int *numMembros)
{

    printf("\n-------- REGISTAR MEMBRO -------- ");

    if (*numMembros == MAX_MEMBROS)
        printf("\n\nERRO: Limite máximo de membros registados atingidos!");
    else
    {
        vetorMembros[*numMembros].numUtente = lerInteiroDigitos("\n*Número de utente", 9, SIM);
        //if numUtente já existe perguntar se quer efetivamente adicionar um membro ou não
        lerSring("\n*Nome: ", vetorMembros[*numMembros].nome, MAX_STRING, SIM);
        vetorMembros[*numMembros].entidade = lerInteiro("\n*Entidade:\n\n\t0 - Estudante;\n\t1 - Docente;\n\t2 - Técnico.\n\n\tEscolha uma das opções", 0, 2, SIM);
        vetorMembros[*numMembros].dataNascimento = lerData("\n*Data de nascimento (Formato: dd/mm/aaaa):", MIN_ANO, MAX_ANO);
        vetorMembros[*numMembros].estadoConfinamento = lerInteiro("\n*Estado de confinamento:\n\n\t0 - Não confinado;\n\t1 - Confinado;\n\t2 - Quarentena.\n\n\tEscolha uma das opções", 0, 2, SIM);
        vetorMembros[*numMembros].estadoVacinacao = lerInteiro("\n*Estado de vacinação:\n\n\t0 - Não vacinado;\n\t1 - Vacinado com primeira dose;\n\t2 - Vacinado com segunda dose;\n\t3 - Vacinado com terceira dose.\n\n\tEscolha uma das opções", 0, 3, SIM);
        vetorMembros[*numMembros].ultimaVacina = lerData("\n*Data da última vacina (Formato: dd/mm/aaaa):", 2019, ANO_ATUAL);
        (*numMembros)++;
    }
}

void listarDadosMembro(tipoMembro membro[], int numMembros) {
    printf("\n-------- MOSTRAR DADOS MEMBRO -------- ");

    if(numMembros == 0)
        printf("\nATENÇÃO: Ainda não foram inseridos membros.");
    else {
        for(int i = 0; i < numMembros; i++) {
            printf("\n\n---------------------------------------------------------------------------------------------\n");
            printf(" \n\t\tMembro numero: %-3d", i+1);
            printf(" \n\t\tNúmero de Utente: %-5d", membro[i].numUtente);
            printf(" \n\t\tNome: %s",membro[i].nome);
            printf(" \n\t\tData Nascimento: ");
            escreverData(membro[i].dataNascimento);
            printf(" \n\t\tEntidade:");
            if(membro[i].entidade == 0)
                printf(" Estudante;");
            else if(membro[i].entidade == 1)
                printf(" Docente;");
            else
                printf(" Técnico;");

            printf(" \n\t\tEstado Confinamento:");
            if(membro[i].estadoConfinamento == 1)
                printf(" Não Confinado;");
            else if(membro[i].estadoConfinamento == 2)
                printf(" Quarentena;");
            else
                printf(" Isolamento;");

            printf(" \n\t\tEstado Vacinação:");
            if(membro[i].estadoVacinacao == 4)
                printf(" Sem Vacina;");
            else if(membro[i].estadoVacinacao == 1)
                printf(" 1ª Dose da Vacina;");
            else if(membro[i].estadoVacinacao == 2)
                printf(" 2ª Dose da Vacina;");
            else
                printf(" 3ª Dose da Vacina;");
            printf("\n\n---------------------------------------------------------------------------------------------\n");

        }
    }
}
