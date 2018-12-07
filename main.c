/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * Autores: João Pedro Mendonça
 *          THiago Henrique Domingues Botelho
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "headers/graph.h"
#include "headers/testes.h"
#include "headers/arquivoDOT.h"

int main(int argc, char** argv) {

    if(argc != 6) {
        printf("Quantidade de parametros incorretas. \n");
        exit(EXIT_FAILURE);
    }

    /*
    * Parametros recebidos pelo argv
    */
    char metodo[2];  
    char arqEntrada[20];
    char arqSaida[20];

    int seed = atoi(argv[1]); //Semente utilizada na geração de valores aleatorios  
    strcpy (metodo,argv[2]);
    strcpy (arqEntrada,argv[3]);
    strcpy (arqSaida,argv[4]);
    int porcentagem = atoi(argv[5]); //Porcentagem do grafo a ser atingida, passado por parametro

  
    printf("Seed: %d \n",atoi(argv[1]));
    printf("METODO: %s \n",metodo);
    printf("ArqE: %s \n",arqEntrada);
    printf("ArqS: %s \n",arqSaida);
    printf("P: %d \n",porcentagem);

    srand(seed);


    int dsize; // Armazena a quantidade de nos pegos nos procedimentos guloso e aleatorio


    FILE* file;
    file = fopen(arqEntrada, "r");
    if (file == NULL) {
        printf("Ocorreu um erro durante a leitura do arquivo. \n");
        exit(EXIT_FAILURE);
    }


    coletar_caracteristicasGrafo(file);
    alocarMatriz(file);


    if (metodo == 'g') {
        dsize = procedimento_Guloso(porcentagem);
    } else {
        dsize = procedimento_Aleatorio(seed, porcentagem);
    }

    //gerarArquivoDot();

    //  calculo_interseccao();



    //void gerarArquivoLog(char* instance,int nodes,int arcs,long int seed, char* method, int dsize);
    // gerarArquivoLog(seed, dsize);
    
    return (EXIT_SUCCESS); 
}
