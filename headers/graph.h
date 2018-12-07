/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   files.h
 * Author: thiago
 *
 * Created on 17 de Novembro de 2018, 15:15
 */

#ifndef FILES_H
#define FILES_H

/********************************************************************************
* Estrutura onde será salva os dados dos grafos
*********************************************************************************/
typedef struct {
    int nos;
    int arcos;
    int** matriz;
    int contNosFontes;
} structGraph;

/********************************************************************************
* Estrutura para salvar caracteristicas dps nós
*********************************************************************************/
typedef struct {
    int x, y;
    int id;
    int contTransitividade;
} nosCoord;

/********************************************************************************
* Coleta as informações da primeira linha do arquivo do grafo isto é, quantidade
* de nós e quantidade de arcos. 
*********************************************************************************/
void coletar_caracteristicasGrafo(FILE* file);

/********************************************************************************
*Cria uma matriz de adjcência do grafo lido em memoria
*********************************************************************************/
void alocarMatriz(FILE* file);

/********************************************************************************
* Coleta os nos fontes e os salva em uma struct dinamica de mesmo nome.
* Os dados pegos são as suas coordenadas e sua cardinalidade;
*********************************************************************************/
void armazenamentoNosFontes();

/********************************************************************************
* Calcula a interseção entre todos os nós
*********************************************************************************/
int calculo_interseccao();

/********************************************************************************
* Estrutura para salvar caracteristicas dps nós
*********************************************************************************/
void ordenacao_NosFontes();

/********************************************************************************
* Realiza a imprenssão da matriz lida em tela, utilizada mais durante o desenvolvi-
* mento para para facilitar a verificação de daos
*********************************************************************************/
void imprimir_Matriz();

/********************************************************************************
* Retornar a estrutura onde está armazendas as estruturas do grafo lido
*********************************************************************************/
structGraph returnGraph();

/********************************************************************************
* Retorna o vetor de nos fontes
*********************************************************************************/
nosCoord * returnNosFontes();


#endif /* FILES_H */

