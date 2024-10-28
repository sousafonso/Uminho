#ifndef RESERVATIONNODE_H
#define RESERVATIONNODE_H

#include "reservations.h"

/**
 * @file ReservationNode.h
 * @brief Este ficheiro contém funções relacionadas com as reservations.
 */

/**
 * @struct ReservationNode
 * @brief Estrutura para representar um nó de uma reserva
 */
typedef struct reservationode ReservationNode;

/**
 * @brief Busca todas as reservations no nó
 *
 * @param reservationNode - Apontador para a estrutura de dados ReservationNode
 * @return Todas as Reservations no nó
 */
Reservations **get_all_reservations(const ReservationNode *);

/**
 * @brief Busca o número de reservas ocupados no nó
 *
 * @param reservationNode - Apontador para a estrutura de dados ReservationNode
 * @return Número de reservas ocupados no nó
 */
int get_reservation_node_occupied(const ReservationNode *);

/**
 * @brief Busca o número máximo de reservas ocupados no nó
 *
 * @param reservationNode - Apontador para a estrutura de dados ReservationNode
 * @return Número máximo de reservas ocupados no nó
 */
int get_reservation_node_size(const ReservationNode *);

/**
 * @brief Busca todas as reservations no nó
 *
 * @param reservationNode - Apontador para a estrutura de dados ReservationNode
 * @param reservation - Apontador para a ultima reserva a ser definida
 */
void set_one_reservation(ReservationNode *, Reservations *);

/**
 * @brief Busca todas as reservations no nó
 *
 * @param reservationNode - Apontador para a estrutura de dados ReservationNode
 * @param reservations - Apontador para todas as reservas a serem definidas
 */
void set_all_reservations(ReservationNode *, Reservations **);

/**
 * @brief Define o número de reservas ocupados no nó
 *
 * @param reservationNode - Apontador para a estrutura de dados reservationNode
 * @param howOccupied - Número de reservas a serem definidos como ocupados
 */
void set_reservation_node_occupied(ReservationNode *, int);

/**
 * @brief Define o número max de reservas ocupados no nó
 *
 * @param reservationNode - Apontador para a estrutura de dados reservationNode
 * @param size - Número maximo de reservas a serem definidos como ocupados
 */
void set_reservation_node_size(ReservationNode *, int);

/**
 * @brief      function that initializes the reservation node
*/
ReservationNode *create_reservation_node(void);

/**
 * @brief     function that frees the reservation node
 * @param      reservationNode - struct of reservation node
*/
void free_reservation_node(ReservationNode *);

#endif