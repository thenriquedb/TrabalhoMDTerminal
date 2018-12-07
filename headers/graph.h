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

typedef struct {
    int nos;
    int arcos;
    int** matriz;
    int contNosFontes;
} structGraph;

typedef struct {
    int x, y;
    int id;
    int contTransitividade;
} nosCoord;


void coletar_caracteristicasGrafo(FILE* file);

void alocarMatriz(FILE* file);

void imprimir_Matriz();

structGraph returnGraph();

void armazenamentoNosFontes();

int calculo_interseccao();

void ordenacao_NosFontes();

nosCoord * returnNosFontes();

//FILE * returnArquivo();

#endif /* FILES_H */

