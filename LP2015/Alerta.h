/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alerta.h
 * Author: Utilizador
 *
 * Created on 30 de Dezembro de 2015, 14:00
 */

#ifndef ALERTA_H
#define ALERTA_H

#include "Utils.h"


//ESTRUTURA ALERTA
typedef struct alerta {
    unsigned short int idViagem;
    unsigned int id;
    char mensagem[100];
    Boolean estado;
} Alerta;


#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* ALERTA_H */

