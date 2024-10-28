#ifndef PASSENGERS_H
#define PASSENGERS_H

/**
 * @file passengers.h
 * @brief Este ficheiro contém funções relacionadas com os passengers.
 */

/**
 * @struct Passengers
 * @brief Estrutura para representar um passageiro
 */
typedef struct passengers Passengers;

/**
 * @brief Obtém o ID do voo associado ao passageiro
 *
 * @param passenger - Apontador para a estrutura de dados
 * @return Cópia do ID do voo associado ao passageiro
 */
char *get_passenger_flight_id(const Passengers *);

/**
 * @brief Obtém o ID do utilizador associado ao passageiro
 *
 * @param passenger - Apontador para a estrutura de dados
 * @return Cópia do ID do utilizador associado ao passageiro
 */
char *get_passenger_user_id(const Passengers *);

/**
 * @brief Obtém o próximo passageiro na sequência
 *
 * @param passenger - Apontador para a estrutura de dados
 * @return Apontador para o próximo passageiro na sequência
 */
Passengers *get_next_passenger(const Passengers *);

/**
 * @brief Cria uma nova estrutura de dados (Passengers)
 *
 * @return Apontador para a nova estrutura de dados
 */
Passengers *new_passengers(void);

/**
 * @brief Define o ID do voo associado ao passageiro
 *
 * @param passengers - Apontador para a estrutura de dados
 * @param flight_id - ID do voo a ser definido
 */
void set_P_flight_id(Passengers*, char *);

/**
 * @brief Define o ID do utilizador associado ao passageiro
 *
 * @param passengers - Apontador para a estrutura de dados
 * @param user_id - ID do utilizador a ser definido
 */
void set_P_user_id(Passengers*, char *);

/**
 * @brief Define o próximo passageiro na sequência
 *
 * @param passengers - Apontador para a estrutura de dados
 * @param next - Apontador para o próximo passageiro a ser definido
 */
void set_P_next(Passengers*, Passengers*);

/**
 * @brief Libera a memória alocada para a estrutura de dados dos passageiros
 *
 * @param passengers Apontador para a estrutura de dados
 */
void free_passengers(Passengers *);

#endif