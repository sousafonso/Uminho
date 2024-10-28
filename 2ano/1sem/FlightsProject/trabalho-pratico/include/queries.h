#ifndef QUERIES_H
#define QUERIES_H

#include "DataStore.h"
#include "output.h"

/**
 * @file queries.h
 * @brief Este ficheiro contém as funções relacionadas diretamente com a execução das queries.
 */

/**
 * @brief Função que executa a query1
 *
 * @param hashtable
 * @param Id - id de um user, voo ou reserva
 * @param int - formato do output
 */
void query1(const HashTable *, char *, int);

/**
 * @brief Função que executa a query2
 *
 * @param hashtable
 * @param Id - id de um voo ou reserva
 * @param type - tipo (voo ou reserva)
 * @param int - formato do output
 */
void query2 (const HashTable *, char *, char *, int);

/**
 * @brief Função que executa a query3
 *
 * @param hashtable
 * @param Id - id de uma reserva
 * @param int - formato do output
 */
void query3 (const HashTable *, char *, int);

/**
 * @brief Função que executa a query4
 *
 * @param hashtable
 * @param Id - id de uma reserva
 * @param int - formato do output
 */
void query4 (const HashTable *, char *, int);

/**
 * @brief Função que executa a query5
 *
 * @param hashtable
 * @param origem - origem dos voos
 * @param begin_date - data de início do período considerado
 * @param end_date - data final do período considerado
 * @param int - formato do output
 */
void query5 (const HashTable *, char *, char *, char *, int);

/**
 * @brief Função que executa a query6
 *
 * @param hashtable
 * @param ano - ano dado
 * @param n - top n de aeroportos considerados
 * @param int - formato do output
 */
void query6 (const HashTable *, char *, int, int);

/**
 * @brief Função que executa a query7
 *
 * @param hashtable
 * @param n - top n de aeroportos considerados
 * @param int - formato do output
 */
void query7 (const HashTable *, int, int);

/**
 * @brief Função que executa a query8
 *
 * @param hashtable
 * @param ID - id do hotel
 * @param begin_date - data de início do período considerado
 * @param end_date - data final do período considerado
 * @param int - formato do output
 */
void query8 (const HashTable *, char *, char *, char *, int);

/**
 * @brief Função que executa a query9
 *
 * @param hashtable
 * @param prefixo - prefixo dado
 * @param int - formato do output
 */
void query9 (const HashTable *, char *, int);

/**
 * @brief Função que executa a query10
 *
 * @param hashtable
 * @param ano - ano dado
 * @param mês - mês dado
 * @param int - formato do output
 */
void query10 (const HashTable *, char *, char *, int);

#endif