#ifndef DATASTORE_H
#define DATASTORE_H

#include "UserTable.h"
#include "PassengerTable.h"
#include "ReservationTable.h"
#include "FlightsTable.h"

/**
 * @file DataStore.h
 * @brief Este ficheiro contém as definições de estruturas e as declarações de funções para a manipulação da tabela de hash
 */

/**
 * @struct HashTable
 * @brief Struct que representa a tabela de hash principal.
 */
typedef struct hashtable HashTable;

/**
 * @brief Cria e inicializa uma nova tabela de hash principal
 *
 * @return Nova tabela de hash
 */
HashTable *create_hash_table(void);

/**
 * @brief Completa a tabela de hash principal, criando a tabela de passageiros com o tamanho especificado
 *
 * @param hashTable
 * @param size - Tamanho para a tabela de passageiros
 */
void complete_hash_table(HashTable *, int);

/**
 * @brief Obtém a tabela de users na tabela de hash
 *
 * @param hashTable
 * @return Apontador para a tabela de utilizadores.
 */
UsersTable *get_user_table(const HashTable *);

/**
 * @brief Obtém a tabela de passageiros na tabela de hash
 *
 * @param hashTable
 * @return Apontador para a tabela de passageiros
 */
PassengersTable *get_passenger_table(const HashTable *);

/**
 * @brief Obtém a tabela de reservations na tabela de hash
 *
 * @param hashTable
 * @return Apontador para a tabela de reservations
 */
ReservationsTable *get_reservation_table(const HashTable *);

/**
 * @brief Obtém a tabela de flights na tabela de hash
 *
 * @param hashTable
 * @return Apontador para a tabela de flights
 */
FlightsTable *get_flight_table(const HashTable *);

/**
 * @brief Liberta a memória associada à tabela de hash
 *
 * @param hashTable
 */
void free_hash_table(HashTable *);

#endif