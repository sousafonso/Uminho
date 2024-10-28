#ifndef SORT_H
#define SORT_H

#include "reservations.h"
#include "flights.h"
#include "users.h"

/**
 * @file sort.h
 * @brief Este ficheiro contém funções de ordenação
 */

/**
 * @brief Ordena um array de reservas
 *
 * @param reservations - Array de apontadores para estruturas das reservas
 * @param l Índice esquerdo do array.
 * @param r Índice direito do array.
 */
void reservation_sort(Reservations **, int , int );

/**
 * @brief Ordena um array de voos
 *
 * @param reservations - Array de apontadores para estruturas dos voos
 * @param l Índice esquerdo do array.
 * @param r Índice direito do array.
 */
void flight_sort(Flights **, int , int );

/**
 * @brief Ordena um array de inteiros e strings.
 *
 * @param airplanes - Nome dos aeroportos
 * @param total_passengers - Array de inteiros que representam o número total de passageiros para cada aeroporto
 * @param l - Índice esquerdo do array
 * @param r - Índice direito do array
 */
void sort_arrays(char *, int *, int , int );

/**
 * @brief Ordena um array de atrasos
 *
 * @param quantos_atrasos - Array de atrasos a ser ordenado
 * @param l - Índice esquerdo do array
 * @param r - Índice direito do array
 */
void sort_int_array(int *, int , int );

/**
 * @brief Ordena as medianas de atrasos
 *
 * @param airplanes - Array de aeroportos
 * @param medianas - Array de doubles com as medianas
 * @param l - Índice esquerdo do array.
 * @param r - Índice direito do array.
 */
void sort_arrays_double(char *, double *, int , int ); 

/**
 * @brief Ordena um array de users
 *
 * @param reservations - Array de apontadores para estruturas dos users
 * @param l Índice esquerdo do array.
 * @param r Índice direito do array.
 */

void user_sort(Users **, int , int );

/**
 * @brief Ordena um array de users pelo seu id
 *
 * @param reservations - Array de apontadores para estruturas dos users
 * @param l Índice esquerdo do array.
 * @param r Índice direito do array.
 */

void user_ID_sort(Users **, int , int );

#endif