#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h> 
#include "DataStore.h"
#include "queries.h"

/**
 * @file interpreter.h
 * @brief Este ficheiro contém funções relacionadas com a intrepretação dos inputs fornecidos
 */

/**
 * @brief Lê a linha do ficheiro de input, e manda para a query correta
 * @param hashTable - hash table com os dados todos
 * @param line - linha de input
*/
void interpreta(const HashTable *, char *);

/**
 * @brief Lê a linha que o utilizador introduziu, e manda para a query correta
 * @param hashTable - hash table com os dados todos
 * @param line - linha de input
 * @return 1 se o utilizador sair, 0 caso contrário
*/
int interpreta_interativo(const HashTable *, char *);

#endif