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

typedef struct utilizador {
    unsigned int id;
    char nome[];
    unsigned short int idade;
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

