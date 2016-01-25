/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include "Utilizador.h"
#include "Utils.h"

void addUtilizador(Utilizador *utilizadores, int *contU) {
    Boolean val = FALSE;
    
    if (*contU == MAX_UTILIZADORES) {
        printf("Erro: Não existe espaço na base de dados.");
    } else {
        readString(utilizadores[*contU].username, TAM_USERNAME, "Username: ");
        readString(utilizadores[*contU].password, TAM_PASS, "Password: ");
        readLong(&utilizadores[*contU].bi, MIN_BI, MAX_BI, "Número de BI: ");
        readString(utilizadores[*contU].nome, TAM_NOME, "Nome: ");
        readInt(&utilizadores[*contU].dataNascimento.dia, DIA_MIN, DIA_MAX, "Dia: ");
        readInt(&utilizadores[*contU].dataNascimento.mes, MES_MIN, MES_MAX, "Mês: ");
        readInt(&utilizadores[*contU].dataNascimento.ano, ANO_MIN, ANO_MAX, "Ano: ");
        utilizadores[*contU].numeroDeAlertas = 0;
        (*contU)++;
    }
}

/*
void validarUtilizador(Utilizador *utilizador, unsigned short int *contUtilizadores) {
    int i;
    //Utilizador temporario = adicionarUtilizador();
    //temporario.bi = *contUtilizadores + 1;

    if (*contUtilizadores == MAX_UTILIZADORES) {
        printf("Não existe espaço na base de dados.");
    }

    //utilizador[*contUtilizadores] = temporario;
    *contUtilizadores++;
}
*/

void removerUtilizador(Utilizador *utilizador, unsigned int bi, unsigned int *contUtilizadores) {
    int i;
    for (i = 0; i < MAX_UTILIZADORES; i++) {
        if (utilizador[i].bi == bi) {
            //  utilizador[i] = NULL;
            printf("Utilizador eliminado.\n");
        } else if (i++ == MAX_UTILIZADORES) {
            printf("Utilizador não encontrado.\n");
        }
    }
    *contUtilizadores--;

}

int procurarUtilizador(Utilizador utilizadores[], int contU, long int bi) {
    int i;
    
    for (i = 0; i < contU; i++) {
        if (utilizadores[i].bi == bi)
            return i;
    }
    printf("Erro: Utilizador não encontrado!\n");
    return EOF;
}
    
void listarDadosUtilizador(Utilizador utilizadores[], int contU, long int bi) {
    int pos;
    if((pos = procurarUtilizador(utilizadores, contU, bi)) != EOF) {
        printf("BI: %ld\n", utilizadores[pos].bi);
        printf("Username: %s\n", utilizadores[pos].username);
        printf("Password: %s\n", utilizadores[pos].password);
        printf("Nome: %s\n", utilizadores[pos].nome);
        printf("Data de Nascimento: %d/%d/%d\n", utilizadores[pos].dataNascimento.dia, utilizadores[pos].dataNascimento.mes, utilizadores[pos].dataNascimento.ano);
        printf("Número Alertas: %d", utilizadores[pos].numeroDeAlertas);
    }
}

/*
void alterarDados(Utilizador *utilizadores, int *contU) {
    long int bi;
    int posicao, opcao = 0;
    Boolean validar;

    readLong(bi, MIN_BI, MAX_BI, "BI do Utilizador a alterar: \n");
    posicao = procurarUtilizador(utilizadores, *contU, bi);
    if (posicao == EOF) {
        printf("Nao foi encontrado o utlizador. \n");
    } else {
        printf("Escolha uma opcão: \n");
        printf("1- Nome. \n");
        printf("2- Data de aniversario. \n");
        printf("3- Password. \n");
        readInt(opcao, MIN_ID_UTILIZADORES, MAX_ID_UTILIZADORES, "Escolha uma opçÃO: ");

        switch (opcao) {
            case 1:
                do {
                    validar = readString(*utilizadores[posicao].nome, TAM_NOME, "Nome do utilizador: ");
                } while (validar == FALSE);
                printf("Nome alterado com sucesso\n");
            case 2:
                readInt(&utilizadores[posicao].dataNascimento.dia, DIA_MIN, DIA_MAX, "Dia: ");
                readInt(&utilizadores[posicao].dataNascimento.mes, MES_MIN, MES_MAX, "Mês: ");
                readInt(&utilizadores[posicao].dataNascimento.ano, ANO_MIN, ANO_MAX, "Ano: ");
            case 3:
                do {
                    validar = readString(*utilizadores[posicao].nome, TAM_PASS, "Password: ");
                } while (validar == FALSE);

        }
    }
}
*/
    
void criarFicheiroUtilizadores(Utilizador utilizadores[]) {

    FILE *pUtilizadores = fopen("Utilizadores", "w");
    if(pUtilizadores == (FILE *) NULL) {
        puts("Couldn't create file.");
    } else {
        fwrite(utilizadores, sizeof(Utilizador), MAX_UTILIZADORES, pUtilizadores);
        fclose(pUtilizadores);
    }
}
    
void gravarFicheiroUtilizador(Utilizador utilizadores[]) {
    FILE *pUtilizadores = fopen("Utilizadores", "w");
    if(pUtilizadores == (FILE *) NULL) {
        puts("Ficheiro não existe.");
        puts("Não conseguiu gravar.");
    } else {
        fwrite(utilizadores, sizeof(Utilizador), MAX_UTILIZADORES, pUtilizadores);
        puts("Ficheiro gravado.");
        fclose(pUtilizadores);
    }
}
    
Utilizador lerFicheiroUtilizador(Utilizador utilizadores[]) {
    int i;
    FILE *pUtilizador = fopen("Utilizadores", "r");
    if(pUtilizador == (FILE *) NULL) {
        puts("Ficheiro não existe.");
        puts("Criando ficheiro...");
        criarFicheiroUtilizadores(utilizadores);
        gravarFicheiroUtilizador(utilizadores);
        puts("File created");
        gravarFicheiroUtilizador(utilizadores);
    } else {
        fread(utilizadores, sizeof(Utilizador), MAX_UTILIZADORES, pUtilizador);
        fclose(pUtilizador);
    }
}

