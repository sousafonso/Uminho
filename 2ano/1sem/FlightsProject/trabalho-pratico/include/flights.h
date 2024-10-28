#ifndef FLIGHTS_H
#define FLIGHTS_H

/**
 * @file flights.h
 * @brief Este ficheiro contém as declarações de structs e funções relacionadas aos flights
 */

/**
 * @struct Flights
 * @brief Estrutura que representa um flight.
 */
typedef struct flights Flights;

/**
 * @brief Busca o ID do voo
 *
 * @param flight - Apontador para a estrutura de dados do voo
 * @return Apontador para o ID do voo
 */
char *get_flight_id(const Flights *);

/**
 * @brief Busca a companhia aérea
 *
 * @param flight - Apontador para a estrutura de dados do voo
 * @return Apontador para o nome da companhia aérea
 */
char *get_airline(const Flights *);

/**
 * @brief Busca o modelo do avião
 *
 * @param flight - Apontador para a estrutura de dados do voo
 * @return Apontador para o modelo do avião
 */
char *get_model(const Flights *);

/**
 * @brief Busca o número de assentos disponíveis
 *
 * @param flight - Apontador para a estrutura de dados do voo
 * @return Número de assentos disponíveis
 */
int get_sits(const Flights *);

/**
 * @brief Busca a origem do voo
 *
 * @param flight - Apontador para a estrutura de dados do voo
 * @return Apontador para a origem do voo
 */
char *get_origem(const Flights *);

/**
 * @brief Busca o destino do voo
 *
 * @param flight - Apontador para a estrutura de dados do voo
 * @return Apontador para o destino do voo
 */
char *get_destino(const Flights *);

/**
 * @brief Busca a data de partida prevista
 *
 * @param flight - Apontador para a estrutura de dados do voo
 * @return Apontador para a data de partida prevista
 */
char *get_dep(const Flights *);

/**
 * @brief Busca a data de partida real
 *
 * @param flight - Apontador para a estrutura de dados do voo
 * @return Apontador para a data de partida real
 */
char *get_rdep(const Flights *);

/**
 * @brief Busca a data de chegada prevista
 *
 * @param flight - Apontador para a estrutura de dados do voo
 * @return Apontador para a data de chegada prevista
 */
char *get_arr(const Flights *);

/**
 * @brief Busca a data de chegada real
 *
 * @param flight - Apontador para a estrutura de dados do voo
 * @return Apontador para a data de chegada real
 */
char *get_rarr(const Flights *);

/**
 * @brief Busca o ano do voo
 *
 * @param flight - Apontador para a estrutura de dados do voo
 * @return Apontador para o ano do voo
 */
char *get_year(const Flights *);

/**
 * @brief Busca o próximo voo na lista
 *
 * @param flight - Apontador para a estrutura de dados do voo
 * @return Apontador para o próximo voo
 */
Flights *get_next_flight(const Flights *);

/**
 * @brief Busca o aeroporto atual com base nos aeroportos existentes
 *
 * @param existing_airports - String com os aeroportos existentes
 * @return Apontador para a primeira das três letras do aeroporto atual
 */
char *get_current_airport (const char *);

/**
 * @brief Cria uma nova estrutura de dados para representar um voo
 *
 * @return Apontador para a nova estrutura de dados do voo
 */
Flights *new_flight(void);

/**
 * @brief Define o ID do voo
 *
 * @param flight Apontador para a estrutura de dados do voo
 * @param id Apontador para o novo ID do voo
 */
void set_F_flight_id(Flights *, char *);

/**
 * @brief Define a companhia aérea do voo
 *
 * @param flight - Apontador para a estrutura de dados do voo
 * @param airline - Apontador para o nome da companhia aérea
 */
void set_F_airline(Flights *, char *);

/**
 * @brief Define a origem do voo
 *
 * @param flight - Apontador para a estrutura de dados do voo
 * @param origem - Apontador para a nova origem do voo
 */
void set_F_origem(Flights *, char *);

/**
 * @brief Define o modelo do avião do voo
 *
 * @param flight - Apontador para a estrutura de dados do voo
 * @param model - Apontador para o novo modelo do avião
 */
void set_F_model(Flights *, char *);

/**
 * @brief Define o destino do voo
 *
 * @param flight - Apontador para a estrutura de dados do voo
 * @param destino - Apontador para o novo destino do voo
 */
void set_F_destino(Flights *, char *);

/**
 * @brief Define a data de partida prevista do voo
 *
 * @param flight - Apontador para a estrutura de dados do voo
 * @param dep - Apontador para a nova data de partida prevista
 */
void set_F_dep(Flights *, char *);

/**
 * @brief Define a data de partida real do voo
 *
 * @param flight - Apontador para a estrutura de dados do voo
 * @param rdep - Apontador para a nova data de partida real
 */
void set_F_rdep(Flights *, char *);

/**
 * @brief Define a data de chegada prevista do voo
 *
 * @param flight - Apontador para a estrutura de dados do voo
 * @param arr - Apontador para a nova data de chegada prevista
 */
void set_F_arr(Flights *, char *);

/**
 * @brief Define a data de chegada real do voo
 *
 * @param flight - Apontador para a estrutura de dados do voo
 * @param rarr - Apontador para a nova data de chegada real
 */
void set_F_rarr(Flights *, char *);

/**
 * @brief Define o número de assentos disponíveis no voo
 *
 * @param flight - Apontador para a estrutura de dados do voo
 * @param sits - Número de assentos disponíveis
 */
void set_F_sits (Flights *, int);

/**
 * @brief Define o próximo voo na lista
 *
 * @param flight - Apontador para a estrutura de dados do voo
 * @param next - Apontador para o próximo voo
 */
void set_F_next(Flights *, Flights *);

/**
 * @brief Libera a memória alocada para a estrutura de dados do voo
 *
 * @param flight - Apontador para a estrutura de dados do voo.
 */
void free_flight(Flights *);

#endif