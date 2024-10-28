#ifndef USERNODE_H
#define USERNODE_H

#include "users.h"

/**
 * @file UserNode.h
 * @brief Este ficheiro contém funções relacionadas com os users.
 */

/**
 * @struct UserNode
 * @brief Estrutura para representar um nó de um user
 */
typedef struct usernode UserNode;

/**
 * @brief Obtém o array de users no nó
 *
 * @param UserNode - Apontador para a estrutura de dados UserNode
 * @return Apontador para o array de users no nó
 */
Users **get_first_user(const UserNode *);

/**
 * @brief Obtém o número máx de users
 *
 * @param UserNode - Apontador para a estrutura de dados UserNode
 * @return Número máx de users
 */
int get_last_user(const UserNode *);

/**
 * @brief Busca o número de users ocupados no nó
 *
 * @param UserNode - Apontador para a estrutura de dados UserNode
 * @return Número de users ocupados no nó
 */
int get_user_node_occupied(const UserNode *);

/**
 * @brief Busca a key de um nó
 *
 * @param UserNode - Apontador para a estrutura de dados UserNode
 * @return key do nó
 */
int get_user_node_key(const UserNode *);

/**
 * @brief Define o primeiro user no nó
 *
 * @param UserNode - Apontador para a estrutura de dados UserNode
 * @param user - Apontador para o primeiro user a ser definido
 */
void set_first_user(UserNode *, Users **);

/**
 * @brief Define um user no nó
 *
 * @param UserNode - Apontador para a estrutura de dados UserNode
 * @param user - Apontador para o primeiro user a ser definido
 */
void set_one_user(UserNode *, Users *);

/**
 * @brief Define o número max de users no nó
 *
 * @param UserNode - Apontador para a estrutura de dados UserNode
 * @param user - número max de users a ser definido
 */
void set_last_user(UserNode *, int);

/**
 * @brief Define o número de users ocupados no nó
 *
 * @param UserNode - Apontador para a estrutura de dados UserNode
 * @param howOccupied - Número de users a serem definidos como ocupados
 */
void set_user_node_occupied(UserNode *, int);

/**
 * @brief Define a key de um nó
 *
 * @param UserNode - Apontador para a estrutura de dados UserNode
 * @param key - do nó
 */
void set_user_node_key(UserNode *, int);

/**
 * @brief Função que inicializa um novo nó de user
 *
 * @return Apontador para a nova estrutura de dados UserNode
 */
UserNode *create_user_node(void);

/**
 * @brief Função que libera a memória alocada para o nó
 * @param UserNode - Apontador para a estrutura de dados UserNode
 */
void free_user_node(UserNode *);

/**
 * @brief Procura a posição de um user node dependendo da key
 * @param UserNode - Apontador para a estrutura de dados UserNode
 * @param used_keys - número de keys já usadas
 */
int find_key(int , UserNode **, int);

#endif