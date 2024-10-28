#ifndef PARSER_H
#define PARSER_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "DataStore.h"

/**
 * @file parser.h
 * @brief Este ficheiro contém funções para verificar se os dados introduzidos estão corretos.
 */

/**
 * @brief Função geral para analisar ficheiros e atualizar as estruturas de dados correspondentes.
 *
 * @param filename - O nome do ficheiro a ser analisado.
 * @param hashtable - A tabela de dados para armazenar os dados.
 * @param argSize
 */
void parser(char *, HashTable *, int);

#endif