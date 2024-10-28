#ifndef STATISTICS_H
#define STATISTICS_H
#include "DataStore.h"

/**
 * @file statistics.h
 * @brief Este ficheiro contém funções relacionadas à verificação de valores.
 */

/**
 * @brief Verifica se uma string é composta apenas por números.
 *
 * @param str - A string a ser verificada.
 * @return 1 se a string for composta apenas por números, 0 caso contrário.
 */
int are_numbers(char *);

/**
 * @brief Verifica se um email é válido.
 *
 * @param email - O email a ser verificado.
 * @return 1 se o email for válido, 0 caso contrário.
 */
int check_email(char *);

/**
 * @brief Verifica se um código de país é válido.
 *
 * @param code - O código de país a ser verificado.
 * @return 1 se o código de país for válido, 0 caso contrário.
 */
int check_country_code(char *);


/**
 * @brief Verifica se uma origem/destino é válido.
 *
 * @param str - A origem/destino a ser verificado.
 * @return 1 se a origem/destino for válido, 0 caso contrário.
 */
int check_origem_destino(char *);

/**
 * @brief Verifica se o estado de uma conta é válido.
 *
 * @param status - A string a ser verificada.
 * @return 1 se a string for "active" ou "inactive", 0 caso contrário.
 */
int check_account_status(char *);

/**
 * @brief Verifica se as origens e destinos dos voos são iguais.
 *
 * @param origem - A origem do voo.
 * @param destino - A destino do voo.
 * @return 1 se as origens e destinos forem iguais, 0 caso contrário.
 */
int check_airports(char *, char *);

/**
 * @brief Verifica se o número de estrelas de um hotel é válido.
 *
 * @param stars - O número de estrelas do hotel.
 * @return 1 se for um número entre 1 e 5, 0 caso contrário.
 */
int check_hotel_stars(char *);

/**
 * @brief Verifica se a taxa da cidade é um número positivo.
 *
 * @param tax - A taxa da cidade.
 * @return 1 se for um número positivo, 0 caso contrário.
 */
int check_city_tax(char *);


/**
 * @brief Verifica se o preço por noite de um hotel é um número positivo.
 *
 * @param price - O preço por noite do hotel.
 * @return 1 se for um número positivo, 0 caso contrário.
 */
int check_price_per_night(char *);

/**
 * @brief Verifica se a opção de café da manhã de um hotel é válida.
 *
 * @param line - A opção de café da manhã do hotel.
 * @return 1 se for uma opção válida, 0 caso contrário.
 */
int check_includes_breakfast(char *);

/**
 * @brief Verifica se a avaliação de um hotel é um número entre 1 e 5.
 *
 * @param rating - A avaliação do hotel.
 * @return 1 se for um número entre 1 e 5, 0 caso contrário.
 */
int check_hotel_rating(char *);

/**
 * @brief Converte todos os caracteres de uma string para maiúsculas.
 *
 * @param str - A string a ser convertida.
 */
void make_upper(char *);

/**
 * @brief Verifica se um número está dentro de um intervalo.
 *
 * @param num - O número a ser verificado.
 * @param min - O valor mínimo do intervalo.
 * @param max - O valor máximo do intervalo.
 * @return 1 se o número estiver dentro do intervalo, 0 caso contrário.
 */
int is_within_range(int, int ,int);

/**
 * @brief Verifica se o formato da data "aaaa/mm/dd" é válido.
 *
 * @param date - A data a ser verificada.
 * @return 1 se o formato for válido, 0 caso contrário.
 */
int check_date_format2(char *);

/**
 * @brief Verifica se uma data é válida.
 *
 * @param date_str - A data a ser verificada.
 * @return 1 se a data for válida, 0 caso contrário.
 */
int is_date_correct(char *);

/**
 * @brief Verifica se o formato da hora "aaaa/mm/dd hh:mm:ss" é válido.
 *
 * @param time_str - A hora a ser verificada.
 * @return 1 se o formato for válido, 0 caso contrário.
 */
int check_time_format(char *);

/**
 * @brief Verifica se o identificador é um ID de reserva, voo ou utilizador.
 *
 * @param id - O identificador a ser verificado.
 * @return 1 se for um ID de reserva, 2 se for um ID de voo, 3 se for um ID de utilizador, 0 caso contrário.
 */
int check_if_reserv_flight_or_user(char *);

/**
 * @brief Verifica se uma opção de café da manhã é válida.
 *
 * @param breakfast - A opção de café da manhã a ser verificada.
 * @return 1 se a opção for válida, 0 caso contrário.
 */
int correct_breakfast(char *);

/**
 * @brief Verifica se uma conta está ativa ou inativa.
 *
 * @param status - O estado da conta a ser verificado.
 * @return 1 se a conta estiver ativa, 2 se estiver inativa, 0 caso contrário.
 */
int check_active(char *);

/**
 * @brief Compara dois IDs de reserva.
 *
 * @param currentId - O primeiro ID de reserva a ser comparado.
 * @param nextId - O segundo ID de reserva a ser comparado.
 * @return A diferença entre os IDs.
 */
int compara_reservation_id(char *, char *);


/**
 * @brief Verifica o tipo de consulta (flights, reservations) com base em uma string.
 *
 * @param type - A string a ser verificada.
 * @return 1 se for "flights", 2 se for "reservations", -1 caso contrário.
 */
int check_type(char *);

/**
 * @brief Verifica se um aeroporto já existe.
 *
 * @param flight - O conjunto de voos.
 * @param origem - A origem a ser verificada.
 * @return 1 se a origem já existir, 0 caso contrário.
 */
int airport_already_exists(const Flights *, char *);

#endif
