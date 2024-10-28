#ifndef TIME_H
#define TIME_H

/**
 * @file time.h
 * @brief Este ficheiro contém as declarações de structs e funções relacionadas a cálculos temporais.
 */

/**
 * @struct DateTime
 * @brief Estrutura que representa um formato de data.
 */
struct DateTime;

/**
 * @brief Calcula o número de dias entre 2 datas no formato YYYY/MM/DD
 *
 * @param data1 - data inicial
 * @param data2 - data final 
 * @return diferença de dias
*/
int days_time(char *, char *);

/**
 * @brief Calcula o tempo de atraso de um voo
 *
 * @param chegada_fake - data de chegada prevista
 * @param chegada_real - data de chegada real
 * @return tempo de atraso
*/
int calculate_tempo_atraso(char *, char *);

/**
 * @brief Comparar duas datas no formato yyyy/mm/dd hh:mm:ss
 *
 * @param begin_date - data inicial
 * @param end_date - data final
 * @return diferença entre datas
*/
int days_time_all(char *, char *);

/**
 * @brief Calcula a diferença de tempo entre duas datas, em segundos
 *
 * @param begin_date - data inicial
 * @param end_date - data final
 * @return diferença entre datas
*/
int seconds_time_all(char *, char *);

#endif