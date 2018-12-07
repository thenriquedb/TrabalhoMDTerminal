/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   arquivoDOT.h
 * Author: thiago
 *
 * Created on 5 de Dezembro de 2018, 12:32
 */

#ifndef ARQUIVODOT_H
#define ARQUIVODOT_H

/********************************************************************************
* Gerar o arquivo no formato dot
*********************************************************************************/
void gerarArquivoDot();


/********************************************************************************
* Gerar o arquivo log onde sera salvo os dados da execução
* @param Arquivo de entrada;
* @param Arquivo de saida;
* @param Semente;
* @param Metodo de teste (guloso ou aleatorio);
* @param Quantidade de nos pegos (Retorno das funções do procedimento aleatorio e guloso);
*********************************************************************************/
 void gerarArquivoLog(char* arqE,char* arqS, long int seed, char* method, int dsize);

#endif /* ARQUIVODOT_H */

