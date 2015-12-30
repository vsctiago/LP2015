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

typedef enum conforto {
    BASICO, CONFORTAVEL, LUXUOSO
} Conforto;

typedef struct viagem {
    unsigned int id;
    char localInicio[];
    char localDestino[];
    //data/hora TODO
    unsigned short int duracaoEstimada;
    unsigned int criador;
    unsigned int participantes[];
    unsigned short int lugaresDisponiveis[];
    Conforto conforto;
    double custoPorViajante;
    bool realizada;
} Viagem;

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* VIAGEM_H */

