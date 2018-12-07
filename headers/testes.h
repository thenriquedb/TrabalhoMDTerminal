/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   testes.h
 * Author: thiago
 *
 * Created on 27 de Novembro de 2018, 07:32
 */

#ifndef TESTES_H
#define TESTES_H


/********************************************************************************
* O procedimento guloso consite em pegar sempre o nó de maior transitividade e veri-
* ficar se o percentual desejado já foi atingido.
* @param porcentagem que deseja atingir
*********************************************************************************/
int procedimento_Guloso(float p);

/********************************************************************************
* Procedimento aleatorio consite pegar um nó qualquer e verificar sua difusão. Em
* seguida adciona-lo em um conjunto S de solução e verificar se o percentual desejado
* ja foi atingido.
* @param semente para gerar número aleatorio
* @param percentual de difusão que deseja atingir . 
*********************************************************************************/
int procedimento_Aleatorio(long int seed, float p);

#endif /* TESTES_H */

