#include <stdio.h>
#include <string.h>

#include "funcoesGenericas.h"
#include "gestaoMembros.h"
#include "gestaoTestagem.h"

void escreverFichBinario(tipoMembro vetorMembros[], int numMembros)
{
    FILE *ficheiro;
    int controlo;

    ficheiro = fopen("dadosMembros.bin","wb");
    if (ficheiro == NULL)
    {
        printf ("\n\nERRO: Não foi possível abrir o ficheiro \"dadosMembros.bin\"!");
    }
    else
    {
        controlo = fwrite(&numMembros,sizeof(int),1,ficheiro);
        if (controlo != 1)
        {
            printf("\n\nERRO: Falha na escrita dos dados (1)!");
        }
        else
        {
            controlo = fwrite(vetorMembros,sizeof(tipoMembro),numMembros,ficheiro);
            if(controlo != numMembros)
            {
                printf("\n\nERRO: Falha na escrita dos dados (2)!");
            }
            else
            {
                printf("\n\nMENSAGEM: Gravação feita com sucesso.\n\n");
            }
            fclose(ficheiro);
        }
    }
}

void lerFichBinario(tipoMembro vetorMembros[], int *numMembros)
{
    FILE *ficheiro;
    int controlo;

    ficheiro = fopen("dadosMembros.bin","rb");
    if (ficheiro == NULL)
    {
        printf ("\n\nERRO: Não foi possível abrir o ficheiro \"dadosMembros.bin\"!");
    }
    else
    {
        controlo = fread(&*numMembros,sizeof(int),1,ficheiro);
        if (controlo != 1)
        {
            printf("\n\nERRO: Falha na leitura dos dados (1)!");
        }
        else
        {
            controlo = fread(vetorMembros,sizeof(tipoMembro),*numMembros,ficheiro);
            if(controlo != *numMembros)
            {
                printf("\n\nERRO: Falha na leitura dos dados (2)!");
            }
            else
            {
                printf("\n\nMENSAGEM: Leitura feita com sucesso.\n\n");
            }
            fclose(ficheiro);
        }
    }
}

/*void escreverFichTexto(tipoMembro vetorMembros[], int numMembros)
{
    FILE *ficheiro;
    int i;
    ficheiro = fopen("dadosMembros.txt","w");
    if (ficheiro == NULL)
    {
        printf ("\n\nERRO: Não foi possível abrir o ficheiro m\"dadosMembros.txt\"!");
    }
    else
    {
        fprintf(ficheiro,"%d\n", numMembros);
        for (i=0; i<numMembros; i++)
        {
            fprintf(ficheiro,"%d\n",vetorMembros[i].numUtente);
            fprintf(ficheiro,"%s\n",vetorMembros[i].nome);
            fprintf(ficheiro,"%d\n",vetorMembros[i].entidade);
            fprintf(ficheiro,"%d\n",vetorMembros[i].dataNascimento.dia);
            fprintf(ficheiro,"%d\n",vetorMembros[i].dataNascimento.mes);
            fprintf(ficheiro,"%d\n",vetorMembros[i].dataNascimento.ano);
            fprintf(ficheiro,"%d\n",vetorMembros[i].estadoConfinamento);
            fprintf(ficheiro,"%d\n",vetorMembros[i].estadoVacinacao);
            fprintf(ficheiro,"%d\n",vetorMembros[i].ultimaVacina.dia);
            fprintf(ficheiro,"%d\n",vetorMembros[i].ultimaVacina.mes);
            fprintf(ficheiro,"%d\n",vetorMembros[i].ultimaVacina.ano);
        }
        fclose(ficheiro);
    }
}*/

int pesquisaMembro(tipoMembro vetorMembro[], int numMembros, int numUtente)
{
    int posicao = -1;
    for(int i = 0; i < numMembros; i++)
    {
        if(numUtente == vetorMembro[i].numUtente)
        {
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
        printf("\n\nERRO: Não existem membros registados.\n\n");
    else
    {
        printf("\n**********************************************************");
        do
        {
            numUtente = lerInteiroDigitos("\nIndique o Número de Utente do membro: ",9,SIM);
            posicaoMembro = pesquisaMembro(vetorMembro,numMembros,numUtente);

            if(posicaoMembro == -1)
                printf("\nERRO: O Número de Utente inserido não é válido.");

        }
        while(posicaoMembro == -1);

        printf("\n**********************************************************");
        printf("\nIndique o Estado de Confinamento de %s", vetorMembro[posicaoMembro].nome);
        printf("\n[1] - Não Confinado;");
        printf("\n[2] - Quarentena;");
        printf("\n[3] - Isolamento Profilático;");
        printf("\n[0] - Voltar.");
        printf("\n\nEscolha uma das opções: ");

        valorConfinamento = lerInteiro("",0,ISOLAMENTO,SIM);

        if(valorConfinamento != 0)
        {
            vetorMembro[posicaoMembro].estadoConfinamento = valorConfinamento;
            printf("\nEstado de vacinação atualizado com sucesso.");
        }
    }
}

void atualizarEstadoVacinacao(tipoMembro vetorMembro[], int numMembros)
{
    int valorVacina, numUtente, posicaoMembro = -1;

    if(numMembros == 0)
        printf("\n\nERRO: Não existem membros registados.\n\n");
    else
    {
        printf("\n**********************************************************");
        do
        {
            numUtente = lerInteiroDigitos("\nIndique o Número de Utente do membro: ",9,SIM);
            posicaoMembro = pesquisaMembro(vetorMembro,numMembros,numUtente);

            if(posicaoMembro == -1)
                printf("\nERRO: O Número de Utente inserido não é válido.");
        }
        while(posicaoMembro == -1);

        printf("\n**********************************************************");
        printf("\nIndique o Estado de Vacinação de %s", vetorMembro[posicaoMembro].nome);
        printf("\n[1] - Primeira Dose;");
        printf("\n[2] - Segunda Dose;");
        printf("\n[3] - Terceira Dose;");
        printf("\n[4] - Sem Vacina;");
        printf("\n[0] - Voltar.");
        printf("\n\nEscolha uma das opções: ");

        valorVacina = lerInteiro("",0,SEM_VACINA,SIM);

        if(valorVacina != 0)
            vetorMembro[posicaoMembro].estadoVacinacao = valorVacina;
        printf("\nEstado de vacinação atualizado com sucesso.");
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

void listarDadosMembro(tipoMembro membro[], int numMembros)
{
    printf("\n-------- MOSTRAR DADOS MEMBRO -------- ");

    if(numMembros == 0)
        printf("\nATENÇÃO: Ainda não foram inseridos membros.");
    else
    {
        for(int i = 0; i < numMembros; i++)
        {
            printf("\n\n---------------------------------------------------------------------------------------------\n");
            printf(" \n\t\tMembro numero: %-3d", i+1);
            printf(" \n\t\tNúmero de Utente: %-5d", membro[i].numUtente);
            printf(" \n\t\tNome: %s",membro[i].nome);
            printf(" \n\t\tData Nascimento: ");
            escreverData(membro[i].dataNascimento);
            printf(" \n\t\tEntidade:");
            if(membro[i].entidade == ESTUDANTE)
                printf(" Estudante;");
            else if(membro[i].entidade == DOCENTE)
                printf(" Docente;");
            else
                printf(" Técnico;");

            printf(" \n\t\tEstado Confinamento:");
            if(membro[i].estadoConfinamento == NAO_CONFINADO)
                printf(" Não Confinado;");
            else if(membro[i].estadoConfinamento == QUARENTENA)
                printf(" Quarentena;");
            else
                printf(" Isolamento;");

            printf(" \n\t\tEstado Vacinação:");
            if(membro[i].estadoVacinacao == SEM_VACINA)
                printf(" Sem Vacina;");
            else if(membro[i].estadoVacinacao == DOSE1)
                printf(" 1ª Dose da Vacina;");
            else if(membro[i].estadoVacinacao == DOSE2)
                printf(" 2ª Dose da Vacina;");
            else
                printf(" 3ª Dose da Vacina;");
            printf("\n\n---------------------------------------------------------------------------------------------\n");
        }
    }
}

