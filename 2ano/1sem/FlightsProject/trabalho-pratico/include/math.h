#ifndef MATH_H
#define MATH_H

#include "users.h"
#include "DataStore.h"

/**
 * @brief Calcula o preço de uma reserva
 * @param ppn - preço por noite
 * @param ndn - número de dias
 * @param idn - taxa da cidade
 * @return custo total da reserva
*/
double reserve_cost(unsigned int , int, unsigned int);

/**
 * @brief Calcula a idade do user
 * @param birth_date - data de nascimento
 * @return idade
*/
int calculate_age(char *);

/**
 * @brief Calcula o número de reservas feitas pelo user
 * @param user - struct com as informações do user
 * @param numAndprice - número e preço total das reservas 
*/
void calculate_NumAndPrice_Reservations(const Users *, double *);

/**
 * @brief Calcula o rating médio de um hotel
 * @param hashTable
 * @param hotel_id - ID do hotel
 * @return rating médio do hotel
*/
double hotel_average_rating (const HashTable *, char *);

/**
 * @brief Calcula a receita total de um hotel
 * @param hashTable
 * @param hotel_id - ID do hotel
 * @param begin_date - data de início do período
 * @param end_date - data de fim do período
 * @return receita total do hotel
*/
int hotel_revenue (const HashTable *, char *, char*, char *);

#endif