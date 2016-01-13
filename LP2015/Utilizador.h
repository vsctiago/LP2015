/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Utilizador.h
 * Author: Utilizador
 *
 * Created on 30 de Dezembro de 2015, 13:20
 */
#include"constants.h"
#ifndef UTILIZADOR_H
#define UTILIZADOR_H

/**
 * Esta função lê os dados do novo utilizador
 * @return Utilizador 
 */
Utilizador adicionarUtilizador();

/**
 * Valida os dados recolhidos, se estiver tudo bem adiciona ao array de utilizadores
 * @param utilizador
 * @param contadorUti
 */
void validarUtilizador(Utilizador *utilizador, unsigned int *contadorUti);

/**
 * Função que remove o utilizador, segundo o id enviado.
 * @param utilizador
 * @param utilizadorId
 * @param contadorUti
 */
void removerUtilizador(Utilizador *utilizador, unsigned int utilizadorId, unsigned int *contadorUti);

/**
 * Procura o utilizador vaziado no id do utilizador.
 * @param utilizadores
 * @param idUtilizador
 * @return 
 */
int procurarUtilizador(Utilizador utilizadores[], unsigned int idUtilizador) ;

/**
 * Possibilita a alteração de dados de utilizadores já existentes.
 * @param utilizadores
 */
void alterarDados(Utilizador *utilizadores);


typedef struct date {
    unsigned int dia;
    unsigned int mes;
    unsigned int ano;
};

typedef struct utilizador {
    unsigned int id;
    char nome[];
    date dataNascimento;
    //data de nascimento
    char pass[MAX_PASS];
    Viagem viagens[];
    Alerta alertas[];
} Utilizador;

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* UTILIZADOR_H */

