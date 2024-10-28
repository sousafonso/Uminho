#ifndef WINDOWS_H
#define WINDOWS_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <ncurses.h>

#include "output.h"
#include "queries.h"

/**
 * @file windows.h
 * @brief Este ficheiro contém as declarações de structs e funções relacionadas às windows geradas no modo interativo.
 */

/**
 * @struct WindowNode
 * @brief Estrutura que representa uma window com o seu conteúdo.
 */
typedef struct WindowNode WindowNode;

/**
 * @brief Esta função cria windows nais quais é reproduzido o output no modo interativo.
 */
void Windows(void);


#endif