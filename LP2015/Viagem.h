/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Viagem.h
 * Author: Utilizador
 *
 * Created on 30 de Dezembro de 2015, 13:58
 */

#ifndef VIAGEM_H
#define VIAGEM_H

#include "Utils.h"
#include "Utilizador.h"

//ENUMERAÇÃO DE CONFORTO DO VEICULO
typedef enum conforto {
    BASICO, CONFORTAVEL, LUXUOSO
} Conforto;

//ENUMERAÇÃO DE ESTADO DA VIAGEM
typedef enum estado {
    ACTIVA, REALIZADA, CANCELADA
} Estado;

//ESTRUTURA DE VIAGEM
typedef struct viagem {
    unsigned short int id;
    char localInicio[TAM_LOCAL];
    char localDestino[TAM_LOCAL];
    Date data;
    Hora hora;
    unsigned short int duracaoEstimada;
    Utilizador criador;
    Utilizador participantes[MAX_PARTICIPANTES];
    unsigned short int lugaresDisponiveis;
    Conforto conforto;
    float custoPorViajante;
    Estado estado;
} Viagem;

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* VIAGEM_H */

