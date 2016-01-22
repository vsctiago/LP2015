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

#ifndef UTILIZADOR_H
#define UTILIZADOR_H

#include "Utils.h"

typedef struct utilizador {
    int id;
    char nome[TAM_NOME];
    Date dataNascimento;
    char password[TAM_PASS];
    //Viagem viagens[MAX_VIAGENS];
    //Alerta alertas[MAX_ALERTAS];
} Utilizador;

Utilizador adicionarUtilizador();

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* UTILIZADOR_H */

