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
#include <time.h>
#include "Viagem.h"
#include "Utilizador.h"
#include "LP_Leitura.h"

/*
 * 
 */
int main(int argc, char** argv) {

    Utilizador utilizadores[MAX_UTILIZADORES];
    Viagem viagens[MAX_VIAGENS];
    int contUtilizadores=0;
    int contViagens=0;

    //validarUtilizador(&utilizadores, &cont);

    //printf( "%d", utilizadores[0].dataNascimento.ano);

    adicionarViagem(1,&viagens,&contViagens);
    printf("ID: %hu\n", viagens[0].id);
    printf("Local Inicio: %s\n", viagens[0].localInicio);
    printf("Local Destino: %s\n", viagens[0].localDestino);
    printf("Hora: %d:%d\n", viagens[0].hora.hora, viagens[0].hora.minuto);
    printf("Data: %d/%d/%d\n", viagens[0].data.dia, viagens[0].data.mes, viagens[0].data.ano);
    printf("Duração: %hu\n", viagens[0].duracaoEstimada);
    printf("%u\n", viagens[0].criador);
    printf("%d\n", viagens[0].conforto);
    printf("%lf\n", viagens[0].custoPorViajante);
    printf("%d\n", viagens[0].estado);
    


    
   

    return (EXIT_SUCCESS);
}

