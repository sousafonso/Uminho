#ifndef TOTALATRASOS_H
#define TOTALATRASOS_H

/**
 * @file totalatrasos.h
 * @brief Este ficheiro contém funções relacionadas aos atrasos dos aeroportos
 */

/**
 * @struct TotalAtrasos
 * @brief Estrutura que representa os atrasos de cada aeroporto
 */
typedef struct totalatrasos TotalAtrasos;

/**
 * @brief Cria uma nova estrutura TotalAtrasos
 *
 * @return Apontador para a nova estrutura TotalAtrasos
 */
TotalAtrasos *new_atraso();

/**
 * @brief Obtém um array de atrasos de um aeroporto
 *
 * @param totalAtrasos - Apontador para a estrutura TotalAtrasos
 * @return Apontador para o array de atrasos do aeroporto ou NULL se não houver atrasos
 */
int *get_atrasos(const TotalAtrasos *);

/**
 * @brief Obtém o tamanho atual do array de atrasos de um aeroporto
 *
 * @param totalAtrasos - Apontador para a estrutura TotalAtrasos
 * @return O tamanho atual do array de atrasos
 */
int get_size(const TotalAtrasos *);

/**
 * @brief Obtém um atraso de um aeroporto
 *
 * @param totalAtrasos - Apontador para a estrutura TotalAtrasos
 * @return Apontador para o atraso do aeroporto ou NULL se não houver atrasos
 */
int get_current(const TotalAtrasos *);

/**
 * @brief Adiciona um novo atraso ao array de atrasos de um aeroporto
 *
 * @param totalAtrasos - Apontador para a estrutura TotalAtrasos
 * @param atraso - Valor do atraso a ser adicionado
 */
void set_atraso(TotalAtrasos *, int);

/**
 * @brief Define o tamanho do array de atrasos de um aeroporto
 *
 * @param totalAtrasos - Ponteiro para a estrutura TotalAtrasos
 * @param size - Novo tamanho para o array de atrasos
 */
void set_size(TotalAtrasos *, int);

/**
 * @brief Define o atraso atual registado num aeroporto
 *
 * @param totalAtrasos Apontador para a estrutura TotalAtrasos
 * @param current Novo apontador para o atraso pedido
 */
void set_current(TotalAtrasos *, int);

/**
 * @brief Libera a memória alocada para a estrutura TotalAtrasos
 *
 * @param totalAtrasos - Apontador para a estrutura TotalAtrasos
 */
void free_atrasos(TotalAtrasos *);

#endif