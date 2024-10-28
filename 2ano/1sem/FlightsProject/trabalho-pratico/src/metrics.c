#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/metrics.h"
#include "../include/passengers.h"
#include "../include/DataStore.h"


typedef struct metrics {
    int voos;
    int passengers;
    int new_passengers;
} Metrics;

int get_voos(const Metrics *metrics){
    if(metrics && metrics->voos) return metrics->voos;
    else return 0;
}

int get_total_passengers(const Metrics *metrics){
    if(metrics && metrics->passengers) return metrics->passengers;
    else return 0;
}

int get_new_passengers(const Metrics *metrics){
    if(metrics && metrics->new_passengers) return metrics->new_passengers;
    else return 0;
}

void set_voos(Metrics *metrics, int voos){
    if(metrics) metrics->voos = voos;
}

void set_total_passengers(Metrics *metrics, int passengers){
    if(metrics) metrics->passengers = passengers;
}

void set_new_passengers(Metrics *metrics, int new_passengers){
    if(metrics) metrics->new_passengers = new_passengers;
}

Metrics *new_metric(void){
    Metrics *metrics = (Metrics *)malloc(sizeof(Metrics));
    metrics->voos = 0;
    metrics->passengers = 0;
    metrics->new_passengers = 0;
    return metrics;
}

void free_metric(Metrics *metrics){
    if(metrics) free(metrics);
}

void all_metrics(const HashTable *hashTable, int year, int month, int day, Metrics **metrics, int *user_metrics, int *reservation_metrics){

    FlightsTable *flightsTable = get_flight_table(hashTable);
    int max_flights = get_flight_table_size(flightsTable);
    int usedFlights[max_flights];
    for(int i = 0; i < max_flights; i++) usedFlights[i] = 0;

    if(month == -1 && day == -1){
        UsersTable *usersTable = get_user_table(hashTable);
        int size = get_user_table_occupied(usersTable);
        for (int i = 0; i < size; i++) {
            Users **user_list = get_first_user(get_user_node(usersTable, i));
            int userSize = get_user_node_occupied(get_user_node(usersTable, i));
            for(int i = 0; i < userSize; i++){
                Users *user = user_list[i];
                char *currentAccCreation = get_user_acc_creation(user);

                int user_year = 0;
                for (int i = 0; i < 4; ++i) user_year = user_year * 10 + (currentAccCreation[i] - '0');
                
                user_metrics[user_year - year]++;

                free(currentAccCreation);
                currentAccCreation = NULL;






                int *oncePerYear[2023 - year + 1];
                for(int k = 0; k < 2023 - year + 1; k++) oncePerYear[k] = 0;

                Flights **flight = get_user_flights(user);
                int flightSize = get_current_user_flight(user);
                for(int k = 0; k < flightSize; k++){

                    char *currentDepDate = get_dep(flight[k]);
                    char *flightId = get_flight_id(flight[k]);
                    int id = atoi(flightId);
                    
                    int flight_year = 0;
                    for (int i = 0; i < 4; ++i) flight_year = flight_year * 10 + (currentDepDate[i] - '0');
                    
                    if(usedFlights[id] == 0){
                        metrics[flight_year - year]->voos++;
                        usedFlights[id]++;
                    }
                    metrics[flight_year - year]->passengers++;

                    if(oncePerYear[flight_year - year] == 0){
                        metrics[flight_year - year]->new_passengers++;
                        oncePerYear[flight_year - year]++;
                    }

                    free(currentDepDate);
                    currentDepDate = NULL;
                    free(flightId);
                    flightId = NULL;
                }
                




                Reservations **reservation = get_user_reservations(user);
                int reservSize = get_current_user_reservation(user);
                for(int k = 0; k < reservSize; k++){
                    char *currentBeginDate = get_begin_date(reservation[k]);

                    int reservation_year = 0;
                    for (int i = 0; i < 4; ++i) reservation_year = reservation_year * 10 + (currentBeginDate[i] - '0');
                    
                    reservation_metrics[reservation_year - year]++;

                    free(currentBeginDate);
                    currentBeginDate = NULL;
                }
            }
        }
    } else if(day == -1){
        UsersTable *usersTable = get_user_table(hashTable);
        int size = get_user_table_occupied(usersTable);
        for (int i = 0; i < size; i++) {
            Users **user_list = get_first_user(get_user_node(usersTable, i));
            int userSize = get_user_node_occupied(get_user_node(usersTable, i));
            for(int i = 0; i < userSize; i++){
                Users *user = user_list[i];
                char *currentAccCreation = get_user_acc_creation(user);

                int user_year = 0;
                for (int i = 0; i < 4; ++i) user_year = user_year * 10 + (currentAccCreation[i] - '0');
              
                if(user_year == year){
                    int user_month = 0;
                    for (int i = 0; i < 2; ++i) user_month = user_month * 10 + (currentAccCreation[i + 5] - '0');
                    
                    user_metrics[user_month - 1]++;
                }

                free(currentAccCreation);
                currentAccCreation = NULL;






                int *oncePerMonth[12];
                for(int k = 0; k < 12; k++) oncePerMonth[k] = 0;

                Flights **flight = get_user_flights(user);
                int flightSize = get_current_user_flight(user);
                for(int k = 0; k < flightSize; k++){

                    char *currentDepDate = get_dep(flight[k]);
                    char *flightId = get_flight_id(flight[k]);
                    int id = atoi(flightId);
                    
                    int flight_year = 0;
                    for (int i = 0; i < 4; ++i) flight_year = flight_year * 10 + (currentDepDate[i] - '0');
                    
                    if(flight_year == year){
                        int flight_month = 0;
                        for (int i = 0; i < 2; ++i) flight_month = flight_month * 10 + (currentDepDate[i + 5] - '0');

                        if(usedFlights[id] == 0){
                            metrics[flight_month - 1]->voos++;
                            usedFlights[id]++;
                        }
                        metrics[flight_month - 1]->passengers++;

                        if(oncePerMonth[flight_month - 1] == 0){
                            metrics[flight_month - 1]->new_passengers++;
                            oncePerMonth[flight_month - 1]++;
                        }
                    }

                    free(currentDepDate);
                    currentDepDate = NULL;
                    free(flightId);
                    flightId = NULL;
                }
                




                Reservations **reservation = get_user_reservations(user);
                int reservSize = get_current_user_reservation(user);
                for(int k = 0; k < reservSize; k++){
                    char *currentBeginDate = get_begin_date(reservation[k]);

                    int reservation_year = 0;
                    for (int i = 0; i < 4; ++i) reservation_year = reservation_year * 10 + (currentBeginDate[i] - '0');
                    if(reservation_year == year){
                        int reservation_month = 0;
                        for (int i = 0; i < 2; ++i) reservation_month = reservation_month * 10 + (currentBeginDate[i + 5] - '0');
                        
                        reservation_metrics[reservation_month - 1]++;
                    }
                    free(currentBeginDate);
                    currentBeginDate = NULL;
                }
            }
        }
    } else {
        UsersTable *usersTable = get_user_table(hashTable);
        int size = get_user_table_occupied(usersTable);
        for (int i = 0; i < size; i++) {
            Users **user_list = get_first_user(get_user_node(usersTable, i));
            int userSize = get_user_node_occupied(get_user_node(usersTable, i));
            for(int i = 0; i < userSize; i++){
                Users *user = user_list[i];
                char *currentAccCreation = get_user_acc_creation(user);

                int user_year = 0;
                for (int i = 0; i < 4; ++i) user_year = user_year * 10 + (currentAccCreation[i] - '0');
              
                if(user_year == year){
                    int user_month = 0;
                    for (int i = 0; i < 2; ++i) user_month = user_month * 10 + (currentAccCreation[i + 5] - '0');
                    
                    if(user_month == month){
                        int user_day = 0;
                        for (int i = 0; i < 2; ++i) user_day = user_day * 10 + (currentAccCreation[i + 8] - '0');
                        
                        user_metrics[user_day - 1]++;
                    }
                }

                free(currentAccCreation);
                currentAccCreation = NULL;






                int *oncePerDay[31];
                for(int k = 0; k < 31; k++) oncePerDay[k] = 0;

                Flights **flight = get_user_flights(user);
                int flightSize = get_current_user_flight(user);
                for(int k = 0; k < flightSize; k++){

                    char *currentDepDate = get_dep(flight[k]);
                    char *flightId = get_flight_id(flight[k]);
                    int id = atoi(flightId);
                    
                    int flight_year = 0;
                    for (int i = 0; i < 4; ++i) flight_year = flight_year * 10 + (currentDepDate[i] - '0');
                    
                    if(flight_year == year){
                        int flight_month = 0;
                        for (int i = 0; i < 2; ++i) flight_month = flight_month * 10 + (currentDepDate[i + 5] - '0');

                        if(flight_month == month){
                            int flight_day = 0;
                            for (int i = 0; i < 2; ++i) flight_day = flight_day * 10 + (currentDepDate[i + 8] - '0');

                            if(usedFlights[id] == 0){
                                metrics[flight_day - 1]->voos++;
                                usedFlights[id]++;
                            }
                            metrics[flight_day - 1]->passengers++;

                            if(oncePerDay[flight_day - 1] == 0){
                                metrics[flight_day - 1]->new_passengers++;
                                oncePerDay[flight_day - 1]++;
                            }
                        }
                    }

                    free(currentDepDate);
                    currentDepDate = NULL;
                    free(flightId);
                    flightId = NULL;
                }
                




                Reservations **reservation = get_user_reservations(user);
                int reservSize = get_current_user_reservation(user);
                for(int k = 0; k < reservSize; k++){
                    char *currentBeginDate = get_begin_date(reservation[k]);

                    int reservation_year = 0;
                    for (int i = 0; i < 4; ++i) reservation_year = reservation_year * 10 + (currentBeginDate[i] - '0');
                    if(reservation_year == year){
                        int reservation_month = 0;
                        for (int i = 0; i < 2; ++i) reservation_month = reservation_month * 10 + (currentBeginDate[i + 5] - '0');
                        
                        if(reservation_month == month){
                            int reservation_day = 0;
                            for (int i = 0; i < 2; ++i) reservation_day = reservation_day * 10 + (currentBeginDate[i + 8] - '0');
                            
                            reservation_metrics[reservation_day - 1]++;
                        }
                    }
                    free(currentBeginDate);
                    currentBeginDate = NULL;
                }
            }
        }
    }
}

int first_year_with_users(const HashTable *hashTable){
    int year = 2023;
    int newYear = 2023;
    UsersTable *usersTable = get_user_table(hashTable);
    int size = get_user_table_occupied(usersTable);
    for (int i = 0; i < size; i++) {
        Users **user_list = get_first_user(get_user_node(usersTable, i));
        int userSize = get_user_node_occupied(get_user_node(usersTable, i));
        for(int i = 0; i < userSize; i++){
            Users *user = user_list[i];
            char *currentAccCreation = get_user_acc_creation(user);

            char copyYear[5];
            strncpy(copyYear, currentAccCreation, 4);
            copyYear[4] = '\0';
            newYear = atoi(copyYear);
            if (newYear < year) year = newYear;

            free(currentAccCreation);
            currentAccCreation = NULL;
        }
    }
    return year;
}