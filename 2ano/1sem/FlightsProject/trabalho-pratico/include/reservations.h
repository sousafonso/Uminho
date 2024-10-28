#ifndef RESERVATIONS_H
#define RESERVATIONS_H

/**
 * @file reservations.h
 * @brief Este ficheiro contém funções relacionadas com os reservations
 */

/**
 * @struct Reservations
 * @brief Estrutura para representar uma reservation
 */
typedef struct reservations Reservations;

/**
 * @brief Obtém o ID da reserva
 *
 * @param reservations - Apontador para a estrutura de dados
 * @return Cópia do ID da reserva
 */
char *get_reservation_id(const Reservations *);

/**
 * @brief Obtém o ID do user da reserva
 *
 * @param reservations - Apontador para a estrutura de dados
 * @return Cópia do ID do user
 */
char *get_reserv_user_id(const Reservations *);

/**
 * @brief Obtém o ID do hotel da reserva
 *
 * @param reservations - Apontador para a estrutura de dados
 * @return Cópia do ID do hotel da reserva
 */
char *get_hotel_id(const Reservations *);

/**
 * @brief Obtém o nome do hotel da reserva
 *
 * @param reservations - Apontador para a estrutura de dados
 * @return Cópia do nome do hotel da reserva
 */
char *get_hotel_name(const Reservations *);

/**
 * @brief Obtém as estrelas do hotel
 *
 * @param reservations - Apontador para a estrutura de dados
 * @return Cópia das estrelas do hotel
 */
unsigned int get_stars(const Reservations *);

/**
 * @brief Obtém a taxa da cidade
 *
 * @param reservations - Apontador para a estrutura de dados
 * @return Cópia da taxa da cidade
 */
unsigned int get_tax(const Reservations *);

/**
 * @brief Obtém a data de início da reserva
 *
 * @param reservations - Apontador para a estrutura de dados
 * @return Cópia da data de início da reserva
 */
char *get_begin_date(const Reservations *);

/**
 * @brief Obtém a data final da reserva
 *
 * @param reservations - Apontador para a estrutura de dados
 * @return Cópia da data final da reserva
 */
char *get_end_date(const Reservations *);

/**
 * @brief Obtém o o preço por noite da reserva
 *
 * @param reservations - Apontador para a estrutura de dados
 * @return Cópia do preço por noite da reserva
 */
unsigned int get_price_per_night(const Reservations *);

/**
 * @brief Obtém o status do pequeno-almoço da reserva
 *
 * @param reservations - Apontador para a estrutura de dados
 * @return Cópia do status do pequeno-almoço da reserva
 */
char *get_breakfast(const Reservations *);

/**
 * @brief Obtém o rating do hotel
 *
 * @param reservations - Apontador para a estrutura de dados
 * @return Cópia do rating do hotel
 */
unsigned int get_rating(const Reservations *);

/**
 * @brief Obtém a próxima da reserva
 *
 * @param reservations - Apontador para a estrutura de dados
 * @return Cópia da próxima reserva
 */
Reservations *get_next_reservation(const Reservations *);

/**
 * @brief Cria a uma nova reserva
 * @return Cópia da nova reserva
 */
Reservations *new_reservation(void);

/**
 * @brief Define o id da reserva
 *
 * @param reservations - Apontador para a estrutura de dados
 * @param id - id a definir
 */
void set_R_reservation_id(Reservations *, char *);

/**
 * @brief Define o user id da reserva
 *
 * @param reservations - Apontador para a estrutura de dados
 * @param id - id do user a definir
 */
void set_R_user_id(Reservations *, char *);

/**
 * @brief Define o id do hotel da reserva
 *
 * @param reservations - Apontador para a estrutura de dados
 * @param id - id do hotel a definir
 */
void set_R_hotel_id(Reservations *, char *);

/**
 * @brief Define o nome do hotel da reserva
 *
 * @param reservations - Apontador para a estrutura de dados
 * @param nome - nome do hotel a definir
 */
void set_R_hotel_name(Reservations *, char *);

/**
 * @brief Define data de início da reserva
 *
 * @param reservations - Apontador para a estrutura de dados
 * @param begin_date - data de início a definir
 */
void set_R_begin_date(Reservations *, char *);

/**
 * @brief Define o status do pequeno-almoço da reserva
 *
 * @param reservations - Apontador para a estrutura de dados
 * @param breakfast - status do pequeno-almoço a definir
 */
void set_R_breakfast(Reservations *, char *);

/**
 * @brief Define as estrelas da reserva
 *
 * @param reservations - Apontador para a estrutura de dados
 * @param stars - estrelas a definir
 */
void set_R_stars(Reservations *, unsigned int);

/**
 * @brief Define as taxa da cidade
 *
 * @param reservations - Apontador para a estrutura de dados
 * @param tax - taxa da cidade a definir
 */
void set_R_tax(Reservations *, unsigned int);

/**
 * @brief Define o preço por noite
 *
 * @param reservations - Apontador para a estrutura de dados
 * @param ppn - preço por noite a definir
 */
void set_R_price_per_night(Reservations *, unsigned int);

/**
 * @brief Define data de fim da reserva
 *
 * @param reservations - Apontador para a estrutura de dados
 * @param end_date - data de fim a definir
 */
void set_R_end_date(Reservations *, char *);

/**
 * @brief Define o rating da reserva
 *
 * @param reservations - Apontador para a estrutura de dados
 * @param rating - rating da reserva a definir
 */
void set_R_rating(Reservations *, unsigned int);

/**
 * @brief Define a próxima reserva
 *
 * @param reservations - Apontador para a estrutura de dados
 * @param next - próxima reserva a definir
 */
void set_R_next(Reservations *, Reservations *);

/**
 * @brief Libera a memória alocada para a estrutura de dados das reservas
 *
 * @param reservations - Apontador para a estrutura de dados
 */
void free_reservation(Reservations *);

#endif