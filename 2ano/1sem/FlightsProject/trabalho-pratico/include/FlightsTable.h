#ifndef FLIGHTSTABLE_H
#define FLIGHTSTABLE_H

#include "flights.h"

/**
 * @file FlightsTable.h
 * @brief Este ficheiro contém as declarações de structs e funções relacionadas aos flights.
 */

/**
 * @struct FligthsTable
 * @brief Estrutura que representa uma lista ligada de voos.
 */
typedef struct flightstable FlightsTable;

/**
 * @brief Busca todos os nós de voos da tabela
 *
 * @param flightTable - Apontador para a estrutura de dados da tabela de voos
 * @param node - Índice do nó do voo desejado
 * @return Apontador para um dos nós dos voos na lista (FlightsTable)
 */
Flights *get_flight_node(const FlightsTable *, int);

/**
 * @brief Busca o tamanho máximo da tabela de voos
 *
 * @param flightTable - Apontador para a FlightsTable
 * @return Tamanho máximo da tabela de voos
 */
int get_flight_table_size(const FlightsTable *);

/**
 * @brief Função que inicializa a struct FlightsTable
 *
 * @return Apontador para a nova estrutura de dados
 */
FlightsTable *create_flight_table(void);

/**
 * @brief Função que insere um novo voo na lista
 *
 * @param flight_id - ID do voo
 * @param newFlight - Apontador para o voo a ser inserido
 * @param flightTable - Apontador para a struct
 */
void insert_flight(char *, Flights *, FlightsTable *);

/**
 * @brief Função que procura um voo na tabela de voos
 *
 * @param flight_id - ID do voo
 * @param flightTable - Apontador para a struct
 * @return Apontador para o voo encontrado ou NULL se não for encontrado
 */
Flights *find_flight(char *, FlightsTable *);

/**
 * @brief Função que libera a memória alocada para a tabela de voos
 *
 * @param flightTable - Apontador para a struct
 */
void free_flight_table(FlightsTable *);

#endif