#ifndef PASSENGERNODE_H
#define PASSENGERNODE_H

#include "passengers.h"

/**
 * @file PassengerNode.h
 * @brief Este ficheiro contém funções relacionadas com os passengers.
 */

/**
 * @struct PassengerNode
 * @brief Estrutura para representar um nó de um passageiro
 */
typedef struct passengernode PassengerNode;

/**
 * @brief Obtém o primeiro passageiro no nó
 *
 * @param passengerNode - Apontador para a estrutura de dados PassengerNode
 * @return Apontador para o primeiro passageiro no nó
 */
Passengers *get_first_passenger(const PassengerNode *);

/**
 * @brief Obtém o último passageiro no nó
 *
 * @param passengerNode - Apontador para a estrutura de dados PassengerNode
 * @return Apontador para o último passageiro no nó
 */
Passengers *get_last_passenger(const PassengerNode *);

/**
 * @brief Busca o número de passageiros ocupados no nó
 *
 * @param passengerNode - Apontador para a estrutura de dados PassengerNode
 * @return Número de passageiros ocupados no nó
 */
int get_passenger_node_occupied(const PassengerNode *);

/**
 * @brief Define o primeiro passageiro no nó
 *
 * @param passengerNode - Apontador para a estrutura de dados PassengerNode
 * @param passenger - Apontador para o primeiro passageiro a ser definido
 */
void set_first_passenger(PassengerNode *, Passengers *);

/**
 * @brief Define o último passageiro no nó
 *
 * @param passengerNode - Apontador para a estrutura de dados PassengerNode
 * @param passenger - Apontador para o último passageiro a ser definido
 */
void set_last_passenger(PassengerNode *, Passengers *);

/**
 * @brief Define o número de passageiros ocupados no nó
 *
 * @param passengerNode - Apontador para a estrutura de dados PassengerNode
 * @param howOccupied - Número de passageiros a serem definidos como ocupados
 */
void set_passenger_node_occupied(PassengerNode *, int);


/**
 * @brief Função que inicializa um novo nó de passageiro
 *
 * @return Apontador para a nova estrutura de dados PassengerNode
 */
PassengerNode *create_passenger_node(void);

/**
 * @brief Função que libera a memória alocada para o nó
 * @param passengerNode Apontador para a estrutura de dados PassengerNode
 */
void free_passenger_node(PassengerNode *);

#endif