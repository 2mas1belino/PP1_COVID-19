#include "gestaoMembros.h"
#include "gestaoTestagem.h"


void listarConfinamentos(tipoMembro vetorMembro[], int numMembros)
{

    for(int i = 0; i < numMembros; i++)
    {
        if(vetorMembro[i].estadoConfinamento != NAO_CONFINADO)
        {
            printf("\n\n**********************************************************");
            printf("\n\n\t\tMembro: %s", vetorMembro[i].nome);
            printf(" \n\t\tEntidade:");
            if(vetorMembro[i].entidade == ESTUDANTE)
                printf(" Estudante;");
            else if(vetorMembro[i].entidade == DOCENTE)
                printf(" Docente;");
            else
                printf(" Técnico;");
            printf(" \n\t\tEstado Confinamento:");
            if(vetorMembro[i].estadoConfinamento == NAO_CONFINADO)
                printf(" Não Confinado.\n");
            else if(vetorMembro[i].estadoConfinamento == QUARENTENA)
                printf(" Quarentena.\n");
            else
                printf(" Isolamento.\n");
        }
    }
}

void registarMembro(tipoMembro vetorMembros[], int *numMembros, int *numMembrosVacinados)
{
    int posicaoMembro = 0;
    printf("\n-------- REGISTAR MEMBRO -------- ");

    if (*numMembros == MAX_MEMBROS)
        printf("\n\nERRO: Limite máximo de membros registados atingidos!\n");
    else
    {
        do
        {
            vetorMembros[*numMembros].numUtente = lerInteiroDigitos("\n*Número de utente", 9, SIM);
            posicaoMembro = pesquisaMembro(vetorMembros, *numMembros, vetorMembros[*numMembros].numUtente);
            if(posicaoMembro != -1)
                printf("\n\nERRO: Número de Utente indicado já existe.\n");
        }
        while(posicaoMembro != -1);

        lerString("\n*Nome: ", vetorMembros[*numMembros].nome, MAX_STRING, SIM);
        vetorMembros[*numMembros].entidade = lerInteiro("\n*Entidade:\n\n\t[0] - Estudante;\n\t[1] - Docente;\n\t[2] - Técnico.\n\n\tEscolha uma das opções", ESTUDANTE, TECNICO, SIM);
        vetorMembros[*numMembros].dataNascimento = lerData("\n*Data de nascimento (Formato: dd/mm/aaaa):", MIN_ANO, MAX_ANO);
        vetorMembros[*numMembros].estadoConfinamento = lerInteiro("\n*Estado de confinamento:\n\n\t[0] - Não confinado;\n\t[1] - Confinado;\n\t[2] - Quarentena.\n\n\tEscolha uma das opções", 0, QUARENTENA, SIM);
        vetorMembros[*numMembros].estadoVacinacao = lerInteiro("\n*Estado de vacinação:\n\n\t[0] - Não vacinado;\n\t[1] - Vacinado com primeira dose;\n\t[2] - Vacinado com segunda dose;\n\t[3] - Vacinado com terceira dose.\n\n\tEscolha uma das opções", SEM_VACINA, DOSE3, SIM);
        if(vetorMembros[*numMembros].estadoVacinacao != SEM_VACINA)
        {
            vetorMembros[*numMembros].ultimaVacina = lerData("\n*Data da última vacina (Formato: dd/mm/aaaa):", 2019, ANO_ATUAL);
            (*numMembrosVacinados)++;
        }

        printf("\n\nMENSAGEM: O registo do membro foi efetuado com sucesso.\n");
        (*numMembros)++;
    }
}

void escreverFichBinMembros(tipoMembro vetorMembros[], int numMembros, int numMembrosVacinados)
{
    FILE *ficheiro;
    int controlo;

    ficheiro = fopen("dadosMembros.bin","wb");
    if (ficheiro == NULL)
    {
        printf ("\n\nERRO: Não foi possível abrir o ficheiro \"dadosMembros.bin\"!\n");
    }
    else
    {
        controlo = fwrite(&numMembros,sizeof(int),1,ficheiro);
        if (controlo != 1)
            printf("\n\nERRO: Falha na escrita dos dados (1)!\n");
        else
        {
            controlo = fwrite(&numMembrosVacinados,sizeof(int),1,ficheiro);
            controlo = fwrite(vetorMembros,sizeof(tipoMembro),numMembros,ficheiro);
            if(controlo != numMembros)
                printf("\n\nERRO: Falha na escrita dos dados (2)!\n");
            else
                printf("\n\nMENSAGEM: Gravação feita com sucesso.\n");
            fclose(ficheiro);
        }
    }
}

void lerFichBinMembros(tipoMembro vetorMembros[], int *numMembros, int *numMembrosVacinados)
{
    FILE *ficheiro;
    int controlo;

    ficheiro = fopen("dadosMembros.bin","rb");
    if (ficheiro == NULL)
    {
        printf ("\n\nERRO: Não foi possível abrir o ficheiro \"dadosMembros.bin\"!\n");
    }
    else
    {
        controlo = fread(&*numMembros,sizeof(int),1,ficheiro);
        if (controlo != 1)
            printf("\n\nERRO: Falha na leitura dos dados (1)!\n");
        else
        {
            controlo = fread(&*numMembrosVacinados,sizeof(int),1,ficheiro);
            controlo = fread(vetorMembros,sizeof(tipoMembro),*numMembros,ficheiro);
            if(controlo != *numMembros)
                printf("\n\nERRO: Falha na leitura dos dados (2)!\n");
            else
                printf("\n\nMENSAGEM: Leitura feita com sucesso.\n");
            fclose(ficheiro);
        }
    }
}

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

void atualizarEstadoVacinacao(tipoMembro vetorMembro[], int numMembros, int *numMembrosVacinados)
{
    int valorVacinaNova, numUtente, posicaoMembro = -1, valorVacinaAntigo;

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
                printf("\nERRO: O Número de Utente inserido não é válido.\n");
        }
        while(posicaoMembro == -1);

        valorVacinaAntigo = vetorMembro[posicaoMembro].estadoVacinacao;

        printf("\n**********************************************************");
        printf("\nIndique o Estado de Vacinação de %s", vetorMembro[posicaoMembro].nome);
        printf("\n[1] - Primeira Dose;");
        printf("\n[2] - Segunda Dose;");
        printf("\n[3] - Terceira Dose;");
        printf("\n[4] - Sem Vacina;");
        printf("\n[0] - Voltar.");
        printf("\n\nEscolha uma das opções: ");

        valorVacinaNova = lerInteiro("",0,SEM_VACINA,SIM);

        if(valorVacinaAntigo != valorVacinaNova)
        {
            if(valorVacinaNova != 0)
                vetorMembro[posicaoMembro].estadoVacinacao = valorVacinaNova;

            if(valorVacinaNova != valorVacinaAntigo && valorVacinaAntigo == SEM_VACINA)
                (*numMembrosVacinados)++;
            else
                (*numMembrosVacinados)--;
        }

        printf("\nEstado de vacinação atualizado com sucesso.");
    }
}

void listarDadosMembro(tipoMembro vetorMembro[], int numMembros)
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
            printf(" \n\t\tNúmero de Utente: %-5d", vetorMembro[i].numUtente);
            printf(" \n\t\tNome: %s",vetorMembro[i].nome);
            printf(" \n\t\tData Nascimento: ");
            escreverData(vetorMembro[i].dataNascimento);
            printf(" \n\t\tEntidade:");
            if(vetorMembro[i].entidade == ESTUDANTE)
                printf(" Estudante;");
            else if(vetorMembro[i].entidade == DOCENTE)
                printf(" Docente;");
            else
                printf(" Técnico;");

            printf(" \n\t\tEstado Confinamento:");
            if(vetorMembro[i].estadoConfinamento == NAO_CONFINADO)
                printf(" Não Confinado;");
            else if(vetorMembro[i].estadoConfinamento == QUARENTENA)
                printf(" Quarentena;");
            else
                printf(" Isolamento;");

            printf(" \n\t\tEstado Vacinação:");
            if(vetorMembro[i].estadoVacinacao == SEM_VACINA)
                printf(" Sem Vacina;");
            else if(vetorMembro[i].estadoVacinacao == DOSE1)
                printf(" 1ª Dose da Vacina;");
            else if(vetorMembro[i].estadoVacinacao == DOSE2)
                printf(" 2ª Dose da Vacina;");
            else
                printf(" 3ª Dose da Vacina;");
            printf("\n\n---------------------------------------------------------------------------------------------\n");
        }
    }
}

