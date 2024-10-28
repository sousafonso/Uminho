#ifndef USERTABLE_H
#define USERTABLE_H

#include "users.h"
#include "UserNode.h"

/**
 * @file UserTable.h
 * @brief Este ficheiro contém as declarações de structs e funções relacionadas aos users.
 */

/**
 * @struct UsersTable
 * @brief Estrutura que representa uma lista ligada de users.
 */
typedef struct userstable UsersTable;

/**
 * @brief Busca todos os nós de users da tabela
 *
 * @param userTable - Apontador para a estrutura de dados da tabela de users
 * @param node - Índice do nó do user desejado
 * @return Apontador para os nós dos users na lista (UsersTable)
 */
UserNode *get_user_node(const UsersTable *, int);

/**
 * @brief Busca o tamanho máximo da tabela de users
 *
 * @param userTable - Apontador para a UsersTable
 * @return Tamanho máximo da tabela de users
 */
int get_user_table_size(const UsersTable *);

/**
 * @brief Busca o tamanho da tabela de users
 *
 * @param userTable - Apontador para a UsersTable
 * @return Tamanho da tabela de users
 */
int get_user_table_occupied(const UsersTable *);

/**
 * @brief Função que inicializa a struct UsersTable
 *
 * @return Apontador para a nova estrutura de dados
 */
UsersTable *create_user_table(void);

/**
 * @brief Função que insere um novo user na lista
 * @param user_id - ID do user
 * @param newUser - Apontador para o user a ser inserido
 * @param userTable - Apontador para a struct
 */
void insert_user(char *, Users *, UsersTable *);

/**
 * @brief Função que procura um user na tabela de users
 *
 * @param user_id - ID do user
 * @param userTable - Apontador para a struct
 * @return Apontador para o user encontrado ou NULL se não for encontrado
 */
Users *find_user(char *, UsersTable *);

/**
 * @brief Ordena os users de uma usersTable
 *
 * @param usersTable - Apontador para a struct
 */
void sort_users_table(UsersTable *);

/**
 * @brief Função que libera a memória alocada para a tabela de users
 *
 * @param userTable - Apontador para a struct
 */
void free_user_table(UsersTable *);

#endif