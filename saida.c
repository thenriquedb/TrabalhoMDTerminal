/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   arquivoDOT.c
 * Author: thiago
 *
 * Created on 5 de Dezembro de 2018, 12:32
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "headers/graph.h"

void gerarArquivoDot() {
    nosCoord* nosFonte = returnNosFontes();
    structGraph graph = returnGraph();

    FILE* pDot = fopen("dot/saida.dot", "w");
    if (pDot == NULL) {
        printf("Erro ao gerar o arquivo dot. \n");
        exit(EXIT_FAILURE);
    }

    fprintf(pDot, "digraph\n");
    fprintf(pDot, "{\n");

    /* Nos fontes serão coloridos de amarelos*/
    for (int i = 0; i < graph.contNosFontes; i++) {
        fprintf(pDot, "%d [fillcolor=yellow, style=filled];\n", nosFonte[i].y);
    }

    /* E os demais de vermelho */
    for (int i = 0; i < graph.nos; i++) {
        for (int j = 0; j < graph.nos; j++) {
            if (graph.matriz[i][j] == 1) {
                 fprintf(pDot, "%d -> %d [color=red];\n", i, j);
            }
        }

        fprintf(pDot, "}");
    }
            fclose(pDot);
}

void gerarArquivoLog(long int seed, int dsize) {

    nosCoord* nosFonte = returnNosFontes();
    structGraph graph;
    char line[300];

    FILE* pLog = fopen("log/fileLog.log", "w");
    if (pLog == NULL) {
        printf("Erro ao gerar o arquivo log. \n");
        exit(EXIT_FAILURE);
    } else
        fprintf(pLog, "INSTANCE \t NODES \t ARCS \t  SEED \t    METHOD   DSIZE\n");


    fgets(line, 300, pLog);
  //  fprintf(pLog, "%s \t %3d \t %3d \t %3d \t %c \t %3d \n", "nome_arquivo.txt", graph.nos, graph.arcos, seed, 'g', dsize);


    fclose(pLog);
}
