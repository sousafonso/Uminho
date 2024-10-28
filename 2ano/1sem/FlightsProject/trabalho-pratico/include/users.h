#ifndef USERS_H
#define USERS_H
#include "flights.h"
#include "reservations.h"

/**
 * @file users.h
 * @brief Este ficheiro contém funções relacionadas com os users.
 */

/**
 * @struct Users
 * @brief Estrutura para representar um user
 */
typedef struct users Users;

/**
 * @brief Cria uma nova estrutura de dados (Users)
 *
 * @return Apontador para a nova estrutura de dados
 */
Users *new_user(void);

/**
 * @brief Obtém o ID do user
 *
 * @param user - Apontador para a estrutura de dados
 * @return Cópia do ID do user
 */
char *get_user_id(const Users *);

/**
 * @brief Obtém o nome do user
 *
 * @param user - Apontador para a estrutura de dados
 * @return Cópia do nome do user
 */
char *get_user_name(const Users *);

/**
 * @brief Obtém a data de aniversário do user
 *
 * @param user - Apontador para a estrutura de dados
 * @return Cópia da data de aniversário do user
 */
char *get_user_birth_date(const Users *);

/**
 * @brief Obtém o sexo do user
 *
 * @param user - Apontador para a estrutura de dados
 * @return Cópia do sexo do user
 */
char get_user_sex(const Users *);

/**
 * @brief Obtém o passaporte do user
 *
 * @param user - Apontador para a estrutura de dados
 * @return Cópia do passaporte do user
 */
char *get_user_passport(const Users *);

/**
 * @brief Obtém o código do país do user
 *
 * @param user - Apontador para a estrutura de dados
 * @return Cópia do código do país do user
 */
char *get_user_country_code(const Users *);

/**
 * @brief Obtém a data de criação da conta do user
 *
 * @param user - Apontador para a estrutura de dados
 * @return Cópia da data de criação da conta do user
 */
char *get_user_acc_creation(const Users *);

/**
 * @brief Obtém o status do user
 *
 * @param user - Apontador para a estrutura de dados
 * @return Cópia do status do user
 */
char *get_user_status(const Users *);

/**
 * @brief Obtém o próximo user
 *
 * @param user - Apontador para a estrutura de dados
 * @return Cópia do próximo do user
 */
Users *get_next_user(const Users *);

/**
 * @brief Define o ID do user
 *
 * @param users - Apontador para a estrutura de dados
 * @param user_id - ID do user a ser definido
 */
void set_U_id(Users *, char *);

/**
 * @brief Define o nome do user
 *
 * @param users - Apontador para a estrutura de dados
 * @param name - nome do user a ser definido
 */
void set_U_name(Users *, char *);

/**
 * @brief Define a data de aniversário do user
 *
 * @param users - Apontador para a estrutura de dados
 * @param birth_date - data de aniversário do user a ser definida
 */
void set_U_birth_date(Users *, char *);

/**
 * @brief Define o sexo do user
 *
 * @param users - Apontador para a estrutura de dados
 * @param sex - sexo do user a ser definido
 */
void set_U_sex(Users *, char);

/**
 * @brief Define o passaporte do user
 *
 * @param users - Apontador para a estrutura de dados
 * @param passport - passaporte do user a ser definido
 */
void set_U_passport(Users *, char *);

/**
 * @brief Define o código do país do user
 *
 * @param users - Apontador para a estrutura de dados
 * @param code - código do país do user a ser definido
 */
void set_U_country_code(Users *, char *);

/**
 * @brief Define a data de criação de conta do user
 *
 * @param users - Apontador para a estrutura de dados
 * @param acc_creation - data de criação de conta do user a ser definida
 */
void set_U_acc_creation(Users *, char *);

/**
 * @brief Define o status do user
 *
 * @param users - Apontador para a estrutura de dados
 * @param status - status do user a ser definido
 */
void set_U_status(Users *, char *);

/**
 * @brief Define o próximo user
 *
 * @param users - Apontador para a estrutura de dados
 * @param users - Próximo user a ser definido
 */
void set_U_next(Users *, Users *);

/**
 * @brief Define os voos de um user
 *
 * @param users - Apontador para a estrutura de dados
 * @param flights - Voos a definir
 */
void set_user_flights(Users *, Flights *);

/**
 * @brief Define as reservas de um user
 *
 * @param users - Apontador para a estrutura de dados
 * @param reservations - Reservas a definir
 */
void set_user_reservations(Users *, Reservations *);

/**
 * @brief Libera a memória alocada para a estrutura de dados dos users
 *
 * @param passengers Apontador para a estrutura de dados
 */
void free_user(Users *);

/**
 * @brief Transforma um char numa int
 *
 * @param char - nome
 */
int hash_user(char *);

/**
 * @brief Obtém os flights do user
 *
 * @param user - Apontador para a estrutura de dados
 * @return Estrutura com os flights do user
 */
Flights **get_user_flights(const Users *);

/**
 * @brief Obtém número de voos do user
 *
 * @param user - Apontador para a estrutura de dados
 * @return búmero de voos do user
 */
int get_current_user_flight(const Users *);

/**
 * @brief Número máximo de voos que cada user pode ter
 *
 * @param user - Apontador para a estrutura de dados
 * @return Número máximo de voos
 */
int get_max_user_flights(const Users *);

/**
 * @brief Obtém os reservas do user
 *
 * @param user - Apontador para a estrutura de dados
 * @return Estrutura com as reservas do user
 */
Reservations **get_user_reservations(const Users *);

/**
 * @brief Obtém uma reserva do user
 *
 * @param user - Apontador para a estrutura de dados
 * @return Estrutura com a reserva do user
 */
Reservations *get_user_reservation(const Users *, int i);

/**
 * @brief Obtém o número de reservas do user
 *
 * @param user - Apontador para a estrutura de dados
 * @return número de reservas do user
 */
int get_current_user_reservation(const Users *);

/**
 * @brief Número máximo de reservas que cada user pode ter
 *
 * @param user - Apontador para a estrutura de dados
 * @return Número máximo de reservas
 */
int get_max_user_reservations(const Users *);

#endif