#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/math.h"
#include "../include/users.h"
#include "../include/time.h"
#include "../include/DataStore.h"

double reserve_cost(unsigned int ppn, int ndn, unsigned int idc){
    double siu = (double) idc / 100;
    return ppn * ndn + ppn * ndn * siu;
}

//Funções auxiliares para a query1 (users)
int calculate_age(char *birth_date){
    //data atual
    int age = 0;
    int ano = 2023;
    int mes = 10;
    int dia = 1;
    char *data_nascimento = malloc(sizeof(char) * 11);
    strcpy(data_nascimento, birth_date);

    char *token = strtok(data_nascimento, "/\0");
    int next = 0;
    while (token != NULL) {
        if(next == 0) age = ano - atoi(token);
        if(next == 1){
            mes -= atoi(token);
            if(mes < 0) {
                age--;
                break;
            }
            else if(mes > 0) break;
        }
        if(next == 2){
            dia -= atoi(token);
            if(dia < 0) {
                age--;
                break;
            }
        }
        next++;
        token = strtok(NULL, "/");
    }

    free(data_nascimento);
    data_nascimento = NULL;

    return age;
}

//calcula o numero e o preco das reservas
void calculate_NumAndPrice_Reservations(const Users *user, double *values) {
    int count = get_current_user_reservation(user);
    double totalExpenses = 0;

    for(int i = 0; i < count; i++){
        Reservations *reservations = get_user_reservation(user, i);
        unsigned int currentPPN = get_price_per_night(reservations);
        char *currentBeginDay = get_begin_date(reservations);
        char *currentEndDate = get_end_date(reservations);
        unsigned int currentTax = get_tax(reservations);

        totalExpenses += reserve_cost(currentPPN, days_time(currentBeginDay, currentEndDate), currentTax);
        free(currentBeginDay);
        currentBeginDay = NULL;
        free(currentEndDate);
        currentEndDate = NULL;
    }
    values[0] = (double) count;
    values[1] = totalExpenses;
}

//calcula o average do rating num hotel
double hotel_average_rating (const HashTable *hashTable, char *hotel_id)  { 
    int sum = 0;
    int key = atoi(hotel_id + 3);
    ReservationNode *reservationNode = get_reservation_node(get_reservation_table(hashTable), key);
    if(reservationNode == NULL) return 0;
    int size = get_reservation_node_occupied(reservationNode);
    Reservations **reservations = get_all_reservations(reservationNode);

    for(int i = 0; i < size; i++)  sum += get_rating(reservations[i]);
    return (double) sum / size;
}

//calcula a receita de um hotel
int hotel_revenue (const HashTable *hashTable, char *hotel_id, char* begin_date, char *end_date)  { 
    int revenue = 0;
    int key = atoi(hotel_id + 3);
    ReservationNode *reservationNode = get_reservation_node(get_reservation_table(hashTable), key);
    if(reservationNode == NULL) return 0;
    Reservations **reservations = get_all_reservations(reservationNode);
    int reservSize = get_reservation_node_occupied(reservationNode);

    for(int i = 0; i < reservSize; i++){
        Reservations *currentReservation = reservations[i];
        int num_noites = 0;
        int currentReservationPPN = get_price_per_night(currentReservation);
        char *currentReservationBeginDate = get_begin_date(currentReservation);
        char *currentReservationEndDate = get_end_date(currentReservation);

        if(days_time_all(begin_date, currentReservationBeginDate) >= 0 && days_time_all(currentReservationEndDate, end_date) >= 0){
            num_noites = days_time(currentReservationBeginDate, currentReservationEndDate);

        } else if(days_time_all(begin_date, currentReservationBeginDate) >= 0 && days_time_all(currentReservationEndDate, end_date) <= 0 && days_time_all(currentReservationBeginDate, end_date) >= 0){
            num_noites = days_time(currentReservationBeginDate, end_date) + 1;

        } else if(days_time_all(begin_date, currentReservationBeginDate) <= 0 && days_time_all(currentReservationEndDate, end_date) >= 0 && days_time_all(currentReservationEndDate, begin_date) <= 0){
            num_noites = days_time(begin_date, currentReservationEndDate);

        } else if(days_time_all(begin_date, currentReservationBeginDate) <= 0 && days_time_all(currentReservationEndDate, end_date) <= 0){
            num_noites = days_time(begin_date, end_date) + 1;
        }

        int total_price = currentReservationPPN * num_noites;
           
        revenue += total_price;

        free(currentReservationBeginDate);
        currentReservationBeginDate = NULL;
        free(currentReservationEndDate);
        currentReservationEndDate = NULL;
    } 
    return revenue;
}