/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   testes.c
 * Author: thiago
 *
 * Created on 27 de Novembro de 2018, 07:29
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "headers/testes.h"
#include "headers/graph.h"

int procedimento_Guloso(float p) {
    structGraph graph = returnGraph();
    nosCoord* nosFontes = returnNosFontes();

    //Conjunto solução, onde os nos pegos aleatoriamente serão armazenados
    nosCoord conjS[10];
    int cont_conjS = 0;


    if (nosFontes[0].contTransitividade >= (p / 100) * graph.arcos) {

        printf("Metodo guloso \n");
        printf("\tTotal de nos: %d \n", 1);

        return 1;
    }

    int somaNosAtingidos = nosFontes[0].contTransitividade;

    conjS[0].contTransitividade = nosFontes[0].contTransitividade;

    while (somaNosAtingidos < (p / 100) * graph.arcos) {
        somaNosAtingidos += cont_conjS;
        cont_conjS++;

        if (somaNosAtingidos > (p / 100) * graph.arcos) {

            printf("Metodo guloso \n");
            printf("\tTotal de nos: %d \n", cont_conjS);

            return cont_conjS;
        }
    }
}

int procedimento_Aleatorio(long int seed, float p) {

    structGraph graph = returnGraph();
    nosCoord* nosFontes = returnNosFontes();

    //Armazena o total de nós atingidos pelos conjunto solução
    int somaNosAtingidos = 0;

    //COntagem de elementos do conjunto soução
    int cont_conjS = 0;

    //Contagem das coordenadas == 1. Usada tambem no controle do realloc
    int contId = 0; // 

    //Conjunto solução, onde os nos pegos aleatoriamente serão armazenados
    nosCoord* conjS = NULL;

    /*
     * Para simplificar a escolha arbitaria, optamos por adcionar um ID unico para
     * cada coordenada da matriz que contém 1.
     */
    for (int i = 0; i < graph.nos; i++) {
        for (int j = 0; j < graph.nos; j++) {
            if (graph.matriz[i][j] == 1) {

                if (conjS == NULL) {
                    conjS = malloc(sizeof (nosCoord));
                } else {
                    conjS = realloc(conjS, sizeof (nosCoord)*(contId + 1));
                }

                conjS[contId].id = contId;
                conjS[contId].x = i;
                conjS[contId].y = j;

                contId++;
            }
        }
    }


    srand(seed);
    /* 
     * Realizara o armazenamento dos nos coletados aleatorioamente
     * p / 100) * graph.arcos = verificar se a porcentagem solicitada ja foi atingida 
     */
    while (somaNosAtingidos <= (p / 100) * graph.arcos) {
        int id = rand() % contId;

        /* Excluindo os demais nos pertencetes a memsa linha */
        if (conjS[id].id != -1) {
            conjS[id].id = -1;

            cont_conjS++;

            /* Cardinalidade do nó sorteado */
            for (int i = 0; i < graph.nos; i++) {
                somaNosAtingidos += graph.matriz[conjS[id].x][i];
            }

            /* Excluindo os outros nos que estão na mesma linha do sorteado */
            for (int i = 0; i < contId; i++) {
                if (conjS[i].x == conjS[id].x) {
                    conjS[i].id = -1;
                }
            }
        }
    }
    printf("Metodo aleatorio \n");
    printf("\tTotal de nos: %d \n", cont_conjS);

    return cont_conjS;
}




