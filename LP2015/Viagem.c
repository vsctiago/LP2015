/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Viagem.h"
<<<<<<< HEAD
#include "Utils.h"
#include "LP_Leitura.h"
#include "Utilizador.h"

void adicionarViagem(int id, Viagem *viagens[], int *contViagens) {

    Viagem temporaria;
    Boolean validar = FALSE;
    int opcao = 0;
    temporaria.id = *contViagens;
    temporaria.criador = id;
    printf("-----------Adicionar Viagem -----------------\n\n");
    readString(&temporaria.localInicio, TAM_NOME, "Local de incio: ");
    readString(&temporaria.localInicio, TAM_NOME, "Local de fim: ");
    printf("------ Data da viagem: \n");
    readInt(&temporaria.data.dia, DIA_MIN, DIA_MAX, "Dia: ");
    readInt(&temporaria.data.mes, MES_MIN, MES_MAX, "Mês: ");
    readInt(&temporaria.data.ano, ANO_MIN, ANO_MAX, "Ano: ");
    printf("------ Hora da viagem: \n");
    readInt(&temporaria.hora.hora, HORA_MIN, HORA_MAX, "Hora: ");
    readInt(&temporaria.hora.minuto, MINUTO_MIN, MINUTO_MAX, "Minutos: ");
    readInt(&temporaria.duracaoEstimada, MIN_DURACAO, MAX_DURACAO, "Duracao da viagem(minutos): ");
    readInt(&temporaria.lugaresDisponiveis, MIN_LUGARES, MAX_LUGARES, "Numero de lugares disponiveis: ");

    readInt(&opcao, MIN_CONFORTO, MAX_CONFORTO, "Escolha o conforto do seu carro: \n1-Basico \n2- Confortavel\n3- Luxuoso ");
    if (opcao == 1)
        temporaria.conforto = 1;
    else if (opcao == 2)
        temporaria.conforto = 2;
    else if (opcao == 3)
        temporaria.conforto = 3;
    temporaria.estado = 1;
    readDouble(&temporaria.custoPorViajante, MIN_VALOR_VIAGEM, MAX_VALOR_VIAGEM, "Valor da viagem por pessoa:  ");

    //validar a data
    if (opcao = 1) {

    } else {
        printf("\n\n\n\n Viagens adicionada com sucesso!\n");
        *viagens[*contViagens] = temporaria;
        *contViagens++;
    }
}

void listarViagens(unsigned short int idUtilizador, Viagem viagens[]) {

    int i;
    for (i = 0; i < MAX_VIAGENS; i++) {
        if (viagens[i].criador == idUtilizador) {
            printf("\n-------------------------------------------------------------- ");
            printf("Informações sobre a viagem: \n");
            printf("Id:%hu \n", viagens[i].id);
            printf("local de Incio: ");
            puts(viagens[i].localInicio);
            printf("local de Fim: ");
            puts(viagens[i].localDestino);
            printf("Data : %d - %d - %d\n", viagens[i].data.dia, viagens[i].data.mes, viagens[i].data.ano);
            printf("Hora: %d - %d\n ", viagens[i].hora.hora, viagens[i].hora.minuto);
            printf("Duração: %u\n", viagens[i].duracaoEstimada);
            //listar participantes
            printf("Lugares disponiveis: %hu\n", viagens[i].lugaresDisponiveis);
            if (viagens[i].estado == 1)
                printf("O estado da Viagem é activa.\n");
            else if (viagens[i].estado == 2)
                printf("A viagem ja foi realizada.\n");
            else
                printf("A viagem foi cancelada.\n");
        }
    }
}

void listarViagensParticipadas(unsigned short int idUtilizador, Viagem viagens[]) {

    int a, i;
    for (i = 0; i < MAX_VIAGENS; i++) {
        for (a = 0; a < MAX_PARTICIPANTES; a++) {
            if (viagens[i].participantes[a] == idUtilizador) {
                printf("\n-------------------------------------------------------------- ");
                printf("Informações sobre a viagem: \n");
                printf("Id:%hu \n", viagens[i].id);
                printf("local de Incio: ");
                puts(viagens[i].localInicio);
                printf("local de Fim: ");
                puts(viagens[i].localDestino);
                printf("Data : %d - %d - %d\n", viagens[i].data.dia, viagens[i].data.mes, viagens[i].data.ano);
                printf("Hora: %d - %d\n ", viagens[i].hora.hora, viagens[i].hora.minuto);
                printf("Duração: %u\n", viagens[i].duracaoEstimada);
                //listar participantes
                printf("Lugares disponiveis: %hu\n", viagens[i].lugaresDisponiveis);
                if (viagens[i].estado == 1)
                    printf("O estado da Viagem é activa.\n");
                else if (viagens[i].estado == 2)
                    printf("A viagem ja foi realizada.\n");
                else
                    printf("A viagem foi cancelada.\n");
            }
        }
    }
}

void cancelarViagem(unsigned short int idUtilizador, Viagem *viagens, Utilizador *utilizadores) {

    Alerta alerta;
    int a, b;
    unsigned short idViaCancelar;

    listarViagens(idUtilizador, viagens);
    readShort(&idViaCancelar, 0, MAX_VIAGENS, "Introduza o id da viagem a cancelar:  ");

    alerta.estado = FALSE;
    alerta.idViagem = idViaCancelar;
    // alerta.mensagem=("A viagem com o id: %hu, de:%s ate: %s encontra-se cancelada pelo condutor.\n ",idViaCancelar,*viagens[idViaCancelar].localInicio,*viagens[idViaCancelar].localDestino);
    if (viagens[idViaCancelar].criador == idUtilizador) {
        viagens[idViaCancelar].estado = 3;
        for (a = 0; a < MAX_PARTICIPANTES; a++) {
            for (b = 0; b < MAX_UTILIZADORES; b++) {
                if (viagens[idViaCancelar].participantes[a] == utilizadores[b].id) {
                    alerta.id = utilizadores[b].numeroDeAlertas;
                    utilizadores[b].alertas[utilizadores[b].numeroDeAlertas] = alerta;
                    utilizadores[b].numeroDeAlertas++;
                }
            }
        }
    } else
        printf("Esta viagem não foi criada por si, logo não a pode cancelar.\n");


}
=======
>>>>>>> 1a3740bbaf35defe22704f1fa49af1368c0ac29b

