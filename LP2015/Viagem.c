/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Viagem.h"
#include "Utils.h"
#include "LP_Leitura.h"
#include "Utilizador.h"

void addViagem(Utilizador utilizador, Viagem *viagens, int *contV) {
    Boolean val = FALSE;
    int opcao;
    
    if (*contV == MAX_VIAGENS) {
        printf("Erro: Não existe espaço para adicionar outra viagem.");
    } else {
        viagens[*contV].id = *contV;
        viagens[*contV].criador = utilizador;
        readString(viagens[*contV].localInicio, TAM_LOCAL, "Local Inicio: ");
        readString(viagens[*contV].localDestino, TAM_LOCAL, "Local Destino: ");
        readInt(&viagens[*contV].data.dia, DIA_MIN, DIA_MAX, "Dia: ");
        readInt(&viagens[*contV].data.mes, MES_MIN, MES_MAX, "Mês: ");
        readInt(&viagens[*contV].data.ano, ANO_MIN, ANO_MAX, "Ano: ");
        readInt(&viagens[*contV].hora.hora, HORA_MIN, HORA_MAX, "Hora: ");
        readInt(&viagens[*contV].hora.minuto, MINUTO_MIN, MINUTO_MAX, "Minutos: ");
        readShort(&viagens[*contV].duracaoEstimada, MIN_DURACAO, MAX_DURACAO, "Duracao da viagem(minutos): ");
        readShort(&viagens[*contV].lugaresDisponiveis, MIN_LUGARES, MAX_LUGARES, "Numero de lugares disponiveis: ");
        readInt(&opcao, MIN_CONFORTO, MAX_CONFORTO, "Escolha o conforto do seu carro: \n1- Basico \n2- Confortavel\n3- Luxuoso\nOpcao: ");
        if (opcao == 1)
            viagens[*contV].conforto = BASICO;
        else if (opcao == 2)
            viagens[*contV].conforto = CONFORTAVEL;
        else if (opcao == 3)
            viagens[*contV].conforto = LUXUOSO;
        readFloat(&viagens[*contV].custoPorViajante, MIN_CUSTO, MAX_CUSTO, "Custo por Viajante: ");
        viagens[*contV].estado = ACTIVA;
        (*contV)++;
    }
}

int procurarViagem(Viagem viagens[], int contV, unsigned short int id) {
    int i;
    
    for (i = 0; i < contV; i++) {
        if (viagens[i].id == id)
            return i;
    }
    printf("Erro: Viagem não encontrada!\n");
    return EOF;
}

void listarViagemDetalhes(unsigned short int id, Viagem viagens[], int contV) {
    int pos, i;
    if((pos = procurarViagem(viagens, contV, id)) != EOF) {
        printf("ID: %hu\n", viagens[pos].id);
        printf("Local Inicio: %s\n", viagens[pos].localInicio);
        printf("Local Destino: %s\n", viagens[pos].localDestino);
        printf("Data : %d - %d - %d\n", viagens[pos].data.dia, viagens[i].data.mes, viagens[i].data.ano);
        printf("Hora: %d - %d\n ", viagens[pos].hora.hora, viagens[i].hora.minuto);
        printf("Duração: %hu\n", viagens[pos].duracaoEstimada);
        printf("Criador (BI): %s", viagens[pos].criador);
        printf("Participantes (BI): \n");
        for(i=0; i < MAX_PARTICIPANTES - viagens[pos].lugaresDisponiveis; i++) {
            printf("BI: %ld\n", viagens[pos].participantes[i].bi);
        }
        if(viagens[pos].conforto = 0)
            printf("Conforto: Basico");
        if(viagens[pos].conforto = 1)
            printf("Conforto: Confortavel");
        if(viagens[pos].conforto = 2)
            printf("Conforto: Luxuoso");
        printf("Lugares Disponiveis: %hu\n", viagens[pos].lugaresDisponiveis);
        printf("Custo por Viajante: %f\n", viagens[pos].custoPorViajante);
        if(viagens[pos].estado = 0)
            printf("Viagem activa.\n");
        if(viagens[pos].estado = 1)
            printf("Viagem Realizada.\n");
        if(viagens[pos].estado = 2)
            printf("Viagem Cancelada.\n");
    }
}

void cancelarViagem(Viagem *viagens, unsigned short int id,
        int contV, Utilizador u) {
    
    
}


/*

void listarViagens(Utilizador u, Viagem viagens[]) {

    int i;
    for (i = 0; i < MAX_VIAGENS; i++) {
        if (viagens[i].criador.bi == u.bi) {
            printf("\n-------------------------------------------------------------- ");
            printf("Informações sobre a viagem: \n");
            printf("Id:%hu \n", viagens[i].id);
            printf("local de Incio: %s\n", viagens[i].localInicio);
            printf("local de Fim: %s\n", viagens[i].localDestino);
            printf("Data : %d - %d - %d\n", viagens[i].data.dia, viagens[i].data.mes, viagens[i].data.ano);
            printf("Hora: %d - %d\n ", viagens[i].hora.hora, viagens[i].hora.minuto);
            printf("Duração: %u\n", viagens[i].duracaoEstimada);
            //TODO: listar participantes
            printf("Lugares disponiveis: %hu\n", viagens[i].lugaresDisponiveis);
            if (viagens[i].estado == 1)
                printf("O estado da Viagem é activa.\n");
            else if (viagens[i].estado == 2)
                printf("A viagem ja foi realizada.\n");
            else if (viagens[i].estado == 3)
                printf("A viagem foi cancelada.\n");
        }
    }
}
*/
/*

void listarViagensParticipadas(Utilizador u, Viagem viagens[]) {

    int a, i;
    for (i = 0; i < MAX_VIAGENS; i++) {
        for (a = 0; a < MAX_PARTICIPANTES; a++) {
            if (viagens[i].participantes[a].bi == u.bi) {
                printf("\n-------------------------------------------------------------- ");
                printf("Informações sobre a viagem: \n");
                printf("Id:%hu \n", viagens[i].id);
                printf("local de Incio: %s", viagens[i].localInicio);
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
*/

/*
void cancelarViagem(Utilizador u, Viagem *viagens, Utilizador *utilizadores) {

    Alerta alerta;
    int a, b;
    unsigned short idViagemCancelar;

    listarViagens(u, viagens);
    readShort(&idViagemCancelar, 0, MAX_VIAGENS, "Introduza o id da viagem a cancelar:  ");

    alerta.estado = FALSE;
    alerta.idViagem = idViagemCancelar;
    // alerta.mensagem=("A viagem com o id: %hu, de:%s ate: %s encontra-se cancelada pelo condutor.\n ",idViaCancelar,*viagens[idViaCancelar].localInicio,*viagens[idViaCancelar].localDestino);
    if (viagens[idViagemCancelar].criador.bi == u.bi) {
        viagens[idViagemCancelar].estado = 3;
        for (a = 0; a < MAX_PARTICIPANTES; a++) {
            for (b = 0; b < MAX_UTILIZADORES; b++) {
                if (viagens[idViagemCancelar].participantes[a].bi == utilizadores[b].bi) {
                    alerta.id = utilizadores[b].numeroDeAlertas;
                    utilizadores[b].alertas[utilizadores[b].numeroDeAlertas] = alerta;
                    utilizadores[b].numeroDeAlertas++;
                }
            }
        }
    } else
        printf("Esta viagem não foi criada por si, logo não a pode cancelar.\n");


}
*/

