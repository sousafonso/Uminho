#ifndef PASSENGERTABLE_H
#define PASSENGERTABLE_H

#include "PassengerNode.h"

/**
 * @file PassengerTable.h
 * @brief Este ficheiro contém funções relacionadas com os passengers.
 */

/**
 * @struct PassengerTable
 * @brief Estrutura para representar uma lista de passageiros
 */
typedef struct passengerstable PassengersTable;

/**
 * @brief Obtém todos os nós de passageiros da tabela
 *
 * @param passengerTable - Apontador para a estrutura de dados
 * @return Array de apontadores para os nós de passageiros na tabela
 */
PassengerNode **get_all_passenger_nodes(const PassengersTable *);


/**
 * @brief Obtém um nó de passageiro específico da tabela
 *
 * @param passengerTable - Apontador para a estrutura de dados PassengerTable
 * @param node - Índice do nó a ser obtido
 * @return Apontador para o nó na posição especificada
 */
PassengerNode *get_passenger_node(const PassengersTable *, int);

/**
 * @brief Obtém o tamanho da tabela de passageiros
 *
 * @param passengerTable - Apontador para a estrutura de dados PassengerTable
 * @return Tamanho da tabela de passageiros
 */
int get_passenger_table_size(const PassengersTable *);

/**
 * @brief Função que cria a passengerTable
 *
 * @param table_size - Tamanho inicial da tabela
 * @return Apontador para a nova estrutura
 */
PassengersTable *create_passenger_table(int);

/**
 * @brief Insere um novo passageiro na tabela de passageiros
 *
 * @param flight_id - ID do voo associado ao passageiro
 * @param newPassenger - Apontador para a nova estrutura de dados
 * @param passengerTable - Apontador para a estrutura de dados
 */
void insert_passenger(char *, Passengers *, PassengersTable *);

/**
 * @brief Procura um passageiro na tabela de passageiros
 *
 * @param flight_id - ID do voo associado ao passageiro
 * @param user_id - ID do utilizador associado ao passageiro
 * @param passengerTable - Apontador para a estrutura de dados
 * @return Apontador para a estrutura de dados do passageiro encontrado ou NULL se não encontrado
 */
Passengers *find_passenger(int , char *, PassengersTable *);

/**
 * @brief Libera a memória alocada para a tabela de passageiros
 *
 * @param passengerTable - Apontador para a estrutura de dados
 */
void free_passenger_table(PassengersTable *);

#endif