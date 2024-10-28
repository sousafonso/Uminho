#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/PassengerTable.h"
#include "../include/PassengerNode.h"

typedef struct passengerstable {
    PassengerNode **passengers;
    int passengerSize;
} PassengersTable;

PassengerNode **get_all_passenger_nodes(const PassengersTable *passengerTable){
    if(passengerTable == NULL) return NULL;
    if(passengerTable->passengers) return passengerTable->passengers;
    return NULL;
}

PassengerNode *get_passenger_node(const PassengersTable *passengerTable, int node){
    if(passengerTable == NULL) return NULL;
    if(passengerTable->passengers[node]) return passengerTable->passengers[node];
    return NULL;
}

int get_passenger_table_size(const PassengersTable *passengerTable){
    if(passengerTable->passengerSize) return passengerTable->passengerSize;
    return 0;
}

//função que cria a passengerTable
PassengersTable *create_passenger_table(int table_size){
    PassengersTable *passengerTable = (PassengersTable*)malloc(sizeof(PassengersTable));
    if(!passengerTable) {
        perror("Erro ao alocar memória para a tabela de passengers");
        exit(EXIT_FAILURE);
    }
    passengerTable->passengerSize = table_size;
    passengerTable->passengers = malloc(sizeof(PassengerNode *) * table_size);
    if (!passengerTable->passengers) {
        perror("Erro ao alocar memória para a tabela de passengers");
        free(passengerTable);
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < table_size; i++) passengerTable->passengers[i] = NULL;
    return passengerTable;
}

//insere um novo passenger
void insert_passenger(char *flight_id, Passengers *newPassenger, PassengersTable *passengerTable) {
    int total_flights = atoi(flight_id);  
    int size = passengerTable->passengerSize;
    if(total_flights >= size){
        passengerTable->passengerSize += total_flights;
        passengerTable->passengers = realloc(passengerTable->passengers,sizeof(PassengerNode *) * passengerTable->passengerSize);
        for(int i = size; i < passengerTable->passengerSize; i++) passengerTable->passengers[i] = NULL;
    }
    if(passengerTable->passengers[total_flights] == NULL) passengerTable->passengers[total_flights] = create_passenger_node();
    PassengerNode *currentPassenger = passengerTable->passengers[total_flights];  

    set_first_passenger(currentPassenger, newPassenger);
    set_last_passenger(currentPassenger, newPassenger);
}

//procura um passenger
Passengers *find_passenger(int flight_id, char* user_id, PassengersTable *passengerTable) {
    Passengers* current =get_first_passenger(passengerTable->passengers[flight_id]);
    while (current != NULL) {
        char *passengerUserId = get_passenger_user_id(current);
        if (strcmp(passengerUserId, user_id) == 0) {
            free(passengerUserId);
            return current;
        }
        free(passengerUserId);
        current = get_next_passenger(current);
    }
    return NULL;  // Passageiro não encontrado
}

//free na passenger table
void free_passenger_table(PassengersTable *passengerTable){
    int total_flights = passengerTable->passengerSize;
    for (int i = 0; i < total_flights; i++) {
        PassengerNode* current_passenger = passengerTable->passengers[i];
        free_passenger_node(current_passenger);
    }
    free(passengerTable->passengers);
    free(passengerTable);
}