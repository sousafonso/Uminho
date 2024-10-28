#ifndef RESERVATIONTABLE_H
#define RESERVATIONTABLE_H

#include "ReservationNode.h"
#include "reservations.h"

/**
 * @file ReservationTable.h
 * @brief Este ficheiro contém as declarações de structs e funções relacionadas às reservations.
 */

/**
 * @struct ReservationsTable
 * @brief Estrutura que representa uma lista ligada de voos.
 */
typedef struct reservationstable ReservationsTable;

/**
 * @brief Busca todos os nós de reservas da tabela
 *
 * @param ReservationTable - Apontador para a estrutura de dados da tabela de reservas
 * @param node - Índice do nó da reserva desejada
 * @return Apontador para os nós das reservas na lista (ReservationsTable)
 */
ReservationNode *get_reservation_node(const ReservationsTable *, int);

/**
 * @brief Busca o tamanho máximo da tabela de reservas
 *
 * @param ReservationTable - Apontador para a ReservationTable
 * @return Tamanho máximo da tabela de reservas
 */
int get_reservation_table_size(const ReservationsTable *);

/**
 * @brief Função que inicializa a struct ReservationTable
 *
 * @return Apontador para a nova estrutura de dados
 */
ReservationsTable *create_reservation_table(void);

/**
 * @brief Função que insere uma nova reserva na lista
 *
 * @param flight_id - ID da reserva
 * @param newReservation - Apontador para a reserva a ser inserida
 * @param ReservationTable - Apontador para a struct
 */
void insert_reservation(char *, Reservations *, ReservationsTable *);

/**
 * @brief Função que procura uma reserva na tabela de reservas
 *
 * @param reservation_id - ID da reserva
 * @param ReservationTable - Apontador para a struct
 * @return Apontador para a reserva encontrada ou NULL se não for encontrada
 */
Reservations *find_reservation(char *, ReservationsTable *);

/**
 * @brief Função que libera a memória alocada para a tabela de reservas
 *
 * @param ReservationTable - Apontador para a struct
 */
void free_reservation_table(ReservationsTable *);

#endif