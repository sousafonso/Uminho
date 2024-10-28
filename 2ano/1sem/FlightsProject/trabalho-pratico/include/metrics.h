#ifndef METRICS_H
#define METRICS_H

#include "DataStore.h"
#include "passengers.h"

/**
 * @file metrics.h
 * @brief Este ficheiro contém funções relacionadas com métricas de voos, passageiros e utilizadores.
 */

 /**
 * @struct Metrics
 * @brief Estrutura que representa as métricas de voos, passageiros e utilizadores.
 */
typedef struct metrics Metrics;

/**
 * @brief Obtém o número de voos
 *
 * @param metrics - Estrutura de métricas
 * @return Número de voos
 */
int get_voos(const Metrics *);

/**
 * @brief Obtém o número total de passageiros
 *
 * @param metrics - Estrutura de métricas
 * @return Número total de passageiros
 */
int get_total_passengers(const Metrics *);

/**
 * @brief Obtém o número de novos passageiros
 * @param metrics - Estrutura de métricas
 * @return Número de novos passageiros
 */
int get_new_passengers(const Metrics *);

/**
 * @brief Define o número de voos
 *
 * @param metrics - Estrutura de métricas
 * @param voos - Número de voos a definir
 */
void set_voos(Metrics *, int);

/**
 * @brief Define o número total de passageiros
 *
 * @param metrics - Estrutura de métricas
 * @param passengers - Número total de passageiros a definir
 */
void set_total_passengers(Metrics *, int);

/**
 * @brief Define o número de novos passageiros
 *
 * @param metrics - Estrutura de métricas
 * @param new_passengers - Número de novos passageiros a definir
 */
void set_new_passengers(Metrics *, int);

/**
 * @brief Cria uma nova estrutura
 *
 * @return Apontador para a nova estrutura
 */
Metrics *new_metric();

/**
 * @brief Liberta a memória associada a uma estrutura de métricas
 *
 * @param metrics - Estrutura a libertar
 */
void free_metric(Metrics *);

/**
 * @brief Função que agrega todas as métricas, calcula o número de reservas, voos, utilizadores, passageiros e novos passageiros num dado dia, mês e ano.
 *
 * @param hashTable - Tabela de hash de reservas
 * @param year - Ano a pesquisar
 * @param month - Mês a pesquisar
 * @param day - Dia a pesquisar
 * @param metrics - Estrutura para armazenar as métricas de voos e passageiros
 * @param used_user - Array para armazenar as métricas de utilizadores
 * @param reserv_metrics - Array para armazenar as métricas de reservas
*/
void all_metrics(const HashTable *, int, int, int, Metrics **, int *, int *);

/**
 * @brief Obtém o primeiro ano com utilizadores registados
 *
 * @param hashTable - Tabela de hash
 * @return O primeiro ano com utilizadores registados
 */
int first_year_with_users(const HashTable *);


#endif