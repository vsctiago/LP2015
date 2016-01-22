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

#include "Viagem.h"
#include "Alerta.h"
#include"constants.h"
#ifndef UTILIZADOR_H
#define UTILIZADOR_H


/**
 * Valida os dados recolhidos, se estiver tudo bem adiciona ao array de utilizadores
 * @param utilizador
 * @param contadorUti
 */


/**
 * Função que remove o utilizador, segundo o id enviado.
 * @param utilizador
 * @param utilizadorId
 * @param contadorUti
 */


/**
 * Procura o utilizador vaziado no id do utilizador.
 * @param utilizadores
 * @param idUtilizador
 * @return 
 */

/**
 * Possibilita a alteração de dados de utilizadores já existentes.
 * @param utilizadores
 */







typedef struct date {
    int dia;
    int mes;
    int ano;
} Date;

typedef struct utilizador {
    int id;
    char nome[100];
    Date dataNascimento;
    //data de nascimento
    char pass[MAX_PASS];
    Viagem viagens[100];
    Alerta alertas[100];
} Utilizador;


/**
 * Esta função lê os dados do novo utilizador
 * @return Utilizador 
 */

Utilizador adicionarUtilizador();

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* UTILIZADOR_H */

