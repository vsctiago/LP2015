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
    char localInicio[100];
    char localDestino[100];
    Date data;
    Hora hora;
    unsigned short int duracaoEstimada;
    unsigned int criador;
    unsigned int participantes[100];
    unsigned short int lugaresDisponiveis[100];
    Conforto conforto;
    double custoPorViajante;
    
} Viagem;

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* VIAGEM_H */

