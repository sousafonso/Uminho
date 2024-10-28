#ifndef OUTPUT_H
#define OUTPUT_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <ncurses.h>

#include "DataStore.h"

/**
 * @file output.h
 * @brief Este ficheiro contém funções para fazer o output.
 */

/**
 * @brief Criar um novo ficheiro.
 *
 * @return Apontador para uma string contendo o nome do arquivo criado.
 */
char *create_file(void);

/**
 * @brief Criar um novo ficheiro, no modo interativo.
 *
 * @return Apontador para uma string contendo o nome do arquivo criado.
 */
char *create_file_INT(void);

/**
 * @brief Escreve informações da Query 1 (utilizador) no ficheiro
 *
 * @param name -Nome
 * @param sex -Sexo
 * @param age -Idade
 * @param country_code -Código do país
 * @param passport -Número do passaporte
 * @param num_flights -Número de voos
 * @param num_reservations -Número de reservas
 * @param total_spent -Gasto total
 * @param checkF -Formato do output
 */
void output_to_file_1U(char *, char, int, char *, char *, int, int, double, int);

/**
 * @brief Escreve informações da Query 1 (voo) no ficheiro
 *
 * @param companhia -Nome da companhia aérea
 * @param aviao -Modelo do avião
 * @param origem -Aeroporto de origem
 * @param destino -Aeroporto de destino
 * @param partida_est -Data de partida estimada
 * @param chegada_est -Data de chegada estimada
 * @param num_passageiros -Número de passageiros
 * @param tempo_atraso -Tempo de atraso do voo
 * @param checkF -Formato do output
 */
void output_to_file_1F(char *, char *, char *, char *, char *, char *, int, int, int);

/**
 * @brief Escreve informações da Query 1 (reserva) no ficheiro
 *
 * @param hotel_id -ID do hotel
 * @param hotel_name -Nome do hotel
 * @param stars -Classificação do hotel em estrelas
 * @param begin_date -Data de início da reserva
 * @param end_date -Data de término da reserva
 * @param breakfast -Inclusão de pequeno-almoço
 * @param num_noites -Número de noites
 * @param total_price -Preço total da reserva
 * @param checkF - Formato do output
 */
void output_to_file_1R(char *, char *, int, char *, char *, char *, int, double, int);

/**
 * @brief Escreve informações da Query 2 no ficheiro
 *
 * @param id
 * @param date - Data da reserva ou voo
 * @param type
 * @param checkF - Formato do output
 * @param int
 * @param filename - Nome do ficheiro
 */
void output_to_file_2(char *, char *, char *, int, int, char *);

/**
 * @brief Escreve informações da Query 3 no ficheiro
 *
 * @param rating Média do rating
 * @param checkF - Formato do output
 */
void output_to_file_3(double , int );

/**
 * @brief Escreve informações da Query 4 no ficheiro
 *
 * @param reservationId - ID da reserva
 * @param beginDate - Data de início da reserva
 * @param endDate - Data de término da reserva
 * @param userID - ID do user
 * @param rating - Classificação da reserva
 * @param total_price - Preço total da reserva
 * @param checkF - Formato do output
 * @param filename - Nome do ficheiro
 * @param int
 */
void output_to_file_4(char *, char *, char *, char *, unsigned int, double, int, char *, int);

/**
 * @brief Escreve informações da Query 5 no ficheiro
 *
 * @param id - ID do voo
 * @param schedule_departure_date - Data de partida prevista
 * @param destination - Destino do voo
 * @param airline - Companhia aérea do voo
 * @param plane_model - Modelo do avião
 * @param checkF - Formato do output
 * @param filename - Nome do ficheiro
 * @param int
 */
void output_to_file_5(char* , char* ,char*  ,char*  ,char* , int , char* , int );

/**
 * @brief Escreve informações da Query 6 no ficheiro
 *
 * @param aeroporto - Nome do aeroporto
 * @param total_passageiros - Número total de passageiros
 * @param checkF - Formato do output
 * @param filename - Nome do ficheiro
 * @param int
 */
void output_to_file_6(char* , int , int , char* , int );

/**
 * @brief Escreve informações da Query 7 no ficheiro
 *
 * @param aeroporto - Nome do aeroporto
 * @param mediana - Mediana de atrasos
 * @param checkF - Formato do output
 * @param filename - Nome do ficheiro
 * @param int
 */
void output_to_file_7(char* , double , int , char* , int );

/**
 * @brief Escreve informações da Query 8 no ficheiro

 * @param totalRevenue - Receita total
 * @param checkF - Formato do output
 */
void output_to_file_8 (int, int);

/**
 * @brief Escreve informações da Query 9 no arquivo de saída.
 *
 * @param userName Nome do user
 * @param userId ID do user
 * @param checkF - Formato do output
 * @param filename - Nome do ficheiro
 * @param int
 */
void output_to_file_9 (char *, char *, int, char *,int);

/**
 * @brief Criar um novo ficheiro, sem nada
 *
 * @return Apontador para uma string contendo o nome do arquivo criado.
 */
void output_to_file_9_2 (void);

/**
 * @brief Escreve informações da Query 10 no ficheiro
 *
 * @param args Número total de argumentos recebidos
 * @param year_month_day Ano, mês e dia
 * @param new_users Número de novos users
 * @param flights Número total de voos
 * @param passengers Número de passageiros
 * @param unique_passengers Número de passageiros únicos
 * @param new_reservations Número de novas reservas
 * @param checkF - Formato do output
 * @param filename - Nome do ficheiro
 * @param int
 */
void output_to_file_10 (int, int, int , int , int , int , int , int , char *, int );

/**
 * @brief Criar um novo ficheiro com palavras sabias
 */
void output_to_file_rip ();

#endif