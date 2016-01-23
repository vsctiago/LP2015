/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include "Utilizador.h"
#include "Utils.h"
#include <stdbool.h>

Utilizador adicionarUtilizador() {
    double validar = 0;
    Utilizador utilizador;

    readString(utilizador.nome, TAM_NOME, "Nome do utilizador: ");
    readInt(&utilizador.dataNascimento.dia, DIA_MIN, DIA_MAX, "Dia: ");
    readInt(&utilizador.dataNascimento.mes, MES_MIN, MES_MAX, "Mês: ");
    readInt(&utilizador.dataNascimento.ano, ANO_MIN, ANO_MAX, "Ano: ");
    readString(&utilizador.password, TAM_PASS, "Password: ");
    utilizador.numeroDeAlertas = 0;
    return utilizador;
}

void validarUtilizador(Utilizador *utilizador, unsigned short int *contUtilizadores) {
    int i;
    Utilizador temporario = adicionarUtilizador();
    temporario.id = *contUtilizadores + 1;

    for (i = 0; i < MAX_UTILIZADORES; i++) {
        if (utilizador[i].id == temporario.id) {
            printf("Já existe um utilizador com este Id.\n");
            break;
        }
    }
    if (*contUtilizadores == MAX_UTILIZADORES) {
        printf("Não existe espaço na base de dados.");
    }

    utilizador[*contUtilizadores] = temporario;
    *contUtilizadores++;
}

void removerUtilizador(Utilizador *utilizador, unsigned int utilizadorId, unsigned int *contUtilizadores) {
    int i;
    for (i = 0; i < MAX_UTILIZADORES; i++) {
        if (utilizador[i].id == utilizadorId) {
            //  utilizador[i] = NULL;
            printf("Utilizador eliminado.\n");
        } else if (i++ == MAX_UTILIZADORES) {
            printf("Utilizador não encontrado.\n");
        }
    }
    *contUtilizadores--;

}

int procurarUtilizador(Utilizador utilizadores[], unsigned int idUtilizador) {
    int i;
    for (i = 0; i < MAX_UTILIZADORES; i++) {
        if (utilizadores[i].id == idUtilizador) {
            return i;
        }
    }
    printf("Utilizador não encontrado!\n");
    return EOF;
}

void alterarDados(Utilizador *utilizadores) {
    int idUtilizador;
    int posicao, opcao = 0;
    Boolean validar;

    readInt(idUtilizador, MIN_ID_UTILIZADORES, MAX_ID_UTILIZADORES, "Id utilizador alterar: \n");
    posicao = procurarUtilizador(utilizadores, idUtilizador);
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
                } while (validar == false);
                printf("Nome alterado com sucesso\n");
            case 2:
                readInt(&utilizadores[posicao].dataNascimento.dia, DIA_MIN, DIA_MAX, "Dia: ");
                readInt(&utilizadores[posicao].dataNascimento.mes, MES_MIN, MES_MAX, "Mês: ");
                readInt(&utilizadores[posicao].dataNascimento.ano, ANO_MIN, ANO_MAX, "Ano: ");
            case 3:
                do {
                    validar = readString(*utilizadores[posicao].nome, TAM_PASS, "Password: ");
                } while (validar == false);

        }
    }
}

