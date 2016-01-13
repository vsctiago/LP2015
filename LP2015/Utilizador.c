/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include "Utilizador.h"
#include "constants.h"
#include <stdbool.h>

Utilizador adicionarUtilizador() {
    bool validar;
    Utilizador utilizador;

    do {
        validar = readString(*utilizador.nome, TAM_STRING_NOME, "Nome do utilizador: ");
    } while (validar == false);
    readInt(*utilizador.dataNascimento.dia, DIA_MIN, DIA_MAX, "Dia: ");
    readInt(*utilizador.dataNascimento.mes, MES_MIN, MES_MAX, "Mês: ");
    readInt(*utilizador.dataNascimento.ano, ANO_MIN, ANO_MAX, "Ano: ");
    do {
        validar = readString(*utilizador.nome, MAX_PASS, "Password: ");
    } while (validar == false);


}

void validarUtilizador(Utilizador *utilizador, unsigned int *contadorUti) {
    int i;
    Utilizador temporario = adicionarUtilizador();
    temporario.id = contadorUti;
    for (i = 0; i < MAX_UTILIZADOR; i++) {
        if (utilizador[i].id == temporario.id) {
            printf("Já existe um utilizador com este Id.\n");
            break;
        }
    }
    if (contadorUti == MAX_UTILIZADOR--) {
        printf("Não existe espaço na base de dados.");
        break;
    }

    *utilizador[contadorUti] = temporario;
    *contadorUti++;
}

void removerUtilizador(Utilizador *utilizador, unsigned int utilizadorId, unsigned int *contadorUti) {
    int i;
    for (i = 0; i < MAX_UTILIZADOR; i++) {
        if (utilizador[i]->id == utilizadorId) {
            utilizador[i] = NULL;
            printf("Utilizador eliminado.\n");
        } else if (i == MAX_UTILIZADOR--) {
            printf("Utilizador não encontrado.\n");
        }
    }
    *contadorUti--;
    //funcão de reorganização de array.
}

int procurarUtilizador(Utilizador utilizadores[], unsigned int idUtilizador) {
    int i;
    for (i = 0; i < MAX_UTILIZADOR; i++) {
        if (utilizadores[i].id == idUtilizador) {
            return i;
        }
    }
    printf("Utilizador não encontrado!\n");
    return NULL;
}

void alterarDados(Utilizador *utilizadores) {
    unsigned int idUtilizador;
    int posicao, opcao = 0;
    bool validar;

    readInt(*idUtilizador, TAM_MIN_ID, TAM_MAX_ID, "Id utilizador alterar: \n");
    posicao = procurarUtilizador(utilizadores, idUtilizador);
    if (posicao == NULL) {
        break;
    }
    printf("Escolha uma opcão: \n");
    printf("1- Nome. \n");
    printf("2- Data de aniversario. \n");
    printf("3- Password. \n");
    readInt(*opcao, TAM_MIN_ID, TAM_MAX_ID, "Escolha uma opçÃO: ");

    switch (opcao) {
        case 1:
            do {
                validar = readString(*utilizadores[posicao].nome, TAM_STRING_NOME, "Nome do utilizador: ");
            } while (validar == false);
            printf("Nome alterado com sucesso\n");
        case 2:
            readInt(*utilizadores[posicao].dataNascimento.dia, DIA_MIN, DIA_MAX, "Dia: ");
            readInt(*utilizadores[posicao].dataNascimento.mes, MES_MIN, MES_MAX, "Mês: ");
            readInt(*utilizadores[posicao].dataNascimento.ano, ANO_MIN, ANO_MAX, "Ano: ");
        case 3:
            do {
                validar = readString(*utilizadores[posicao].nome, MAX_PASS, "Password: ");
            } while (validar == false);

    }
}
