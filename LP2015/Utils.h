/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   constants.h
 * Author: Alexandre
 *
 * Created on 12 de Janeiro de 2016, 21:52
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H

//CONSTANTES
#define MAX_UTILIZADORES 100
#define MAX_VIAGENS 100
#define MAX_ALERTAS 100
#define MAX_PARTICIPANTES 10

#define MIN_ID_UTILIZADORES 0
#define MAX_ID_UTILIZADORES 9999
#define TAM_PASS 20
#define TAM_NOME 50
#define TAM_MENSAGEM 100
#define MIN_IDADE 18
#define MAX_IDADE 120

#define DIA_MIN 1
#define DIA_MAX 31
#define MES_MIN 1
#define MES_MAX 12
#define ANO_MIN 1900
#define ANO_MAX 2100
#define HORA_MIN 0
#define HORA_MAX 23
#define MINUTO_MIN 0
#define MINUTO_MAX 59
#define MIN_DURACAO 10
#define MAX_DURACAO 1000
#define MIN_LUGARES 2
#define MAX_LUGARES 10
#define MIN_CONFORTO 1
#define MAX_CONFORTO 3
#define MIN_VALOR_VIAGEM 1
#define MAX_VALOR_VIAGEM 100

//ESTRUTURA BOOLEAN
typedef enum boolean {
    FALSE = 0, TRUE
} Boolean;

//ESTRUTURA DATE
typedef struct date {
    int dia;
    int mes;
    int ano;
} Date;

//ESTRUTURA HORA
typedef struct hora {
    int hora;
    int minuto;
} Hora;


#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* CONSTANTS_H */

