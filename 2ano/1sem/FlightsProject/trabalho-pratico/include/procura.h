#ifndef PROCURA_H
#define PROCURA_H

#include "DataStore.h"
#include "flights.h"

/**
 * @file procura.h
 * @brief Este ficheiro contém funções de procura, auxiliares para fazer as queries.
 */

/**
 * @brief Encontra todos os voos de uma origem entre duas datas
 *
 * @param hashTable 
 * @param flight_origin - origem dos voos
 * @param begin_date - data de início
 * @param end_data - data final
 * @return Apontador para um array de flights
*/
Flights **find_flights_by_origin_and_date(const HashTable *, char *, char *, char *);

/**
 * @brief Encontra todos os users que começam com um certo prefixo
 *
 * @param hashTable 
 * @param prefix - prefixo
 * @return Apontador para um array de users
*/
Users **find_users_by_prefix(const HashTable *, char *);

#endif