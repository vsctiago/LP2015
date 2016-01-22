/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Utilizador
 *
 * Created on 28 de Dezembro de 2015, 14:58
 */

#include <stdio.h>
#include <stdlib.h>

#include "Utilizador.h"
#include "LP_Leitura.h"

/*
 * 
 */
int main(int argc, char** argv) {

    Utilizador utilizadores[MAX_UTILIZADORES];
    int contUtilizadores;
    int contViagens;
    
    //validarUtilizador(&utilizadores, &cont);

    //printf( "%d", utilizadores[0].dataNascimento.ano);
    
    Boolean val;
    val = true;
    printf("%d\n", val);
    val = false;
    printf("%d\n", val);

    return (EXIT_SUCCESS);
}

