#ifndef AEROPORTOS_H
#define AEROPORTOS_H

#include "DataStore.h"

/**
 * @file aeroportos.h
 * @brief Este ficheiro contém funções relacionadas a aeroportos.
 */

/**
 * @brief Criar um novo aeroporto.

 * @param aeroportos - String com o resto dos aerportos
 * @param novo - Novo aeroporto
 */
void new_airport(char *, char *);

/**
 * @brief Criar todos os aeroportos.
 
 * @param hashtable
 * @return todos os aeroportos existentes
 */
char *existing_airports (const HashTable *);

/**
 * @brief Encontra o indice de um aeroporto
 
 * @param all - todos os aeroportos existentes
 * @param aeroporto - um aeroporto
 * @return indice do aeroporto em relacao a all
 */
int current_aeroporto(char *, char *);

#endif