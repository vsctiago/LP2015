/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include "Utilizador.h"
#include "constants.h"

Utilizador adicionarUtilizador(Utilizador utilizador) {
    bool validar;

    readInt(*utilizador.id, TAM_MIN_ID, TAM_MAX_ID, "Id utilizador: \n");
    do {
        validar = readString(*utilizador.nome, TAM_STRING_NOME, "Nome do utilizador: ");
    } while (validar == false);
    readInt(*utilizador.idade, TAM_MIN_IDADE, TAM_MAX_IDADE, "Id utilizador: \n");   
}

void removerUtilizador(){

}
