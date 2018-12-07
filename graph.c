
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "headers/graph.h"

/* Struct para armazenamento dos dados dos grafos */
 structGraph graph;


/*******************************************************************************
 *Coleta a quantidade de nós e a quantidade de arestas do grafo lido
 * @param file: arquivo que sera lido
 *******************************************************************************/
void coletar_caracteristicasGrafo(FILE* file) {
    char line[100];
    char* token;

    while (!feof(file)) {
        fgets(line, 100, file);

        /* Verificar se o primeiro caracter da linha é 'p' */
        if (line[0] == 'p') {
            token = strtok(line, " ");

            int check = 1;

            while (token != NULL) {
                token = strtok(NULL, " ");
                check++;

                /* 
                 * Como a linha é composta da seguinte maneira: string string int int;
                 * Para armazenamos os 2 inteiros bastar adcionar um contador iniciando em 1;
                 * Quando este contador for maior que 2 signfica que os proximos 2 tokens são inteiros;
                 * Basta apenas convertelos para o tipo int com a função atoi() e armazena-los nas variaveis
                 *  */
                if (check > 2) {
                    /* check == 3 -> Quantidades de nós */
                    if (check == 3) {
                        graph.nos = atoi(token);
                    }
                    /* check == 4 -> Quantidade de arestas */
                    if (check == 4) {
                        graph.arcos = atoi(token);
                        break;
                    }
                }
            }
        }
    }
    
    printf("Grafo de %d nós e %d arcos. \n",graph.nos,graph.arcos);
}

/*******************************************************************************
 *Realiza a alocação da matriz em memória 
 @param arquivo do grafo
 *******************************************************************************/
void alocarMatriz(FILE* file) {

    rewind(file); /* Retorna o ponteiro para o inicio do arquivo para que ele 
                  * possa ser lido novamente. */

    graph.matriz = malloc(graph.nos * (sizeof (int*)));
    for (int i = 0; i < graph.nos; i++) {
        graph.matriz[i] = malloc(graph.nos * (sizeof (int)));
    }

    if (graph.matriz == NULL) {
        printf("Ocorreu um erro durante a alocação. \n");
        exit(EXIT_FAILURE);
    }

    /* Prenchimento da matriz com 0 */
    for (int i = 0; i < graph.nos; i++) {
        for (int j = 0; j < graph.nos; j++) {
            graph.matriz[i][j] = 0;
        }
    }

    int parOrdenado[2];
    char line[100];
    char* token;
    int pos;

    while (fgets(line, 100, file)) {
        /* Preenchimento da matriz de adjacência */
        if (line[0] == 'e') {
            token = strtok(line, " ");
            pos = 0;

            while (token != NULL) {
                if (strcmp(token, "e") == 0) {
                    token = strtok(NULL, " ");
                    continue;
                }

                parOrdenado[pos] = atoi(token);
                pos++;
                token = strtok(NULL, " ");
            }

            graph.matriz[parOrdenado[0] - 1][parOrdenado[1] - 1] = 1;
        }
    }

    /* Calculo do fecho transitivo */
    for (int i = 0; i < graph.nos; i++) {
        for (int j = 0; j < graph.nos; j++) {
            for (int k = 0; k < graph.nos; k++) {
                if (graph.matriz[i][j] == 1) {
                    if (graph.matriz[j][k] == 1) {
                        if (graph.matriz[i][k] != 1) {
                            graph.matriz[i][k] = 1;
                        }
                    }
                }
            }
        }
    }

    armazenamentoNosFontes();
}



/*******************************************************************************
 *Armazena todos os nos fontes da matriz em um vetor 
 * Armazenamento dos nós fontes em subconjunto
 * Para um nó ser considerado fonte é ele deve ter apenas arcos de saida e nenhum de 
 * entrada. Para realizar a identificação dos nós fontes em uma matriz de adjacência
 * basta verificar as colunas que possuem apenas 0. 
 *******************************************************************************/

//Variavel que armazena o total de nos fontes coletados
static int contNosFontes = 0;
nosCoord* nosFontes = NULL;

void armazenamentoNosFontes() {
    int cont, contLinha, j;

    for (int i = 0; i < graph.nos; i++) {
        cont = 0;
        contLinha = 0;
        for (j = 0; j < graph.nos; j++) {
            //Contagem de 0 das colunas
            if (graph.matriz[j][i] == 0) {
                cont++;
            }
        }

        /* Se a cont for igual a ordem da matriz significa que este é um nó fonte,
         portando será armazendo em uma estrutura dinâmica*/
        if (cont == graph.nos) {
            if (nosFontes == NULL) {
                nosFontes = malloc(sizeof (nosCoord));
            } else {
                nosFontes = realloc(nosFontes, (contNosFontes + 1) * sizeof (nosCoord));
            }

            /* Calcula a quantidade de nos atingidos */
            for (int k = 0; k < graph.nos; k++) {
                if (graph.matriz[i][k] == 1) {
                    contLinha++;
                }
            }

            nosFontes[contNosFontes].y = i;
            nosFontes[contNosFontes].contTransitividade = contLinha;

            contNosFontes++;
        }
    }
    /* Armazena a quantidade de nós fontes contidos no grafo de entrada */
    graph.contNosFontes = contNosFontes;
    printf("Total de nós fontes: %d \n\n",contNosFontes);
    ordenacao_NosFontes();
}

/*******************************************************************************
 * Ordenação dos nós fontes em ordem decrescente de grau de transitivadade
 * Essa ordenação é realizada para ficar mais simples a realização do procedimento
 * guloso. Foi utilizado o selection sort para realziar a ordenação.
 *******************************************************************************/
void ordenacao_NosFontes() {
    int max;
    nosCoord aux;

    for (int i = 0; i < graph.contNosFontes; i++) {
        max = i;
        for (int j = i + 1; j < graph.contNosFontes; j++) {
            if (nosFontes[j].contTransitividade > nosFontes[max].contTransitividade) {
                max = j;
            }
        }

        aux.contTransitividade = nosFontes[i].contTransitividade;
        aux.y = nosFontes[i].y;

        nosFontes[i].contTransitividade = nosFontes[max].contTransitividade;
        nosFontes[i].y = nosFontes[max].y;

        nosFontes[max].contTransitividade = aux.contTransitividade;
        nosFontes[max].y = aux.y;
    }
}

/*******************************************************************************
 * Calcula a intersecção entre os nos fontes da matriz 
 *******************************************************************************/
int calculo_interseccao(int contNos) {
    int nosAtingidos = 0, somaLinha = 0;
    int indice = nosFontes[0].y;
    structGraph graphCopia = graph;

    for (int i = 0; i < graph.nos; i++) {
        for (int j = 0; j < graph.nos; j++) {
            if (graph.matriz[i][j] == 1) {
                if (graph.matriz[indice][j] == 0) {
                    graphCopia.matriz[indice][j] = 1;
                }
            }
        }
    }

    for (int i = 0; i < graph.nos; i++) {
        somaLinha += graphCopia.matriz[indice][i];
    }

    return somaLinha;
}

/*******************************************************************************
 * IMprime a matriz que foi carregada 
 *******************************************************************************/
void imprimir_Matriz() {
    printf("\n\n");
    for (int i = 0; i < graph.nos; i++) {
        for (int j = 0; j < graph.nos; j++) {
            printf("%d ", graph.matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

structGraph returnGraph() {
    return graph;
}

nosCoord * returnNosFontes() {
    return nosFontes;
}