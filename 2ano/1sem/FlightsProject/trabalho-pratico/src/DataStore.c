#include <stdio.h>
#include <stdlib.h>
#include "../include/DataStore.h"
#include "../include/FlightsTable.h"
#include "../include/PassengerTable.h"
#include "../include/UserTable.h"
#include "../include/ReservationTable.h"

// Estrutura das tabelas de hash
typedef struct hashtable{
    UsersTable *userTable;
    PassengersTable *passengerTable;
    ReservationsTable *reservationTable;
    FlightsTable *flightTable;
} HashTable;

HashTable *create_hash_table(void){
    HashTable *hashTable = malloc(sizeof(HashTable));
    hashTable->passengerTable = NULL;
    hashTable->userTable = create_user_table();
    hashTable->flightTable = create_flight_table();
    hashTable->reservationTable = create_reservation_table();
    return hashTable;
}

void complete_hash_table(HashTable *hashTable, int size){
    hashTable->passengerTable = create_passenger_table(size);
}

UsersTable *get_user_table(const HashTable *hashTable){
    if(hashTable->userTable) return hashTable->userTable;
    return NULL;
}

PassengersTable *get_passenger_table(const HashTable *hashTable){
    if(hashTable->passengerTable) return hashTable->passengerTable;
    return NULL;
}

ReservationsTable *get_reservation_table(const HashTable *hashTable){
    if(hashTable->reservationTable) return hashTable->reservationTable;
    return NULL;
}

FlightsTable *get_flight_table(const HashTable *hashTable){
    if(hashTable->flightTable) return hashTable->flightTable;
    return NULL;
}

//free na passenger table
void free_hash_table(HashTable *hashTable){
    free_passenger_table(hashTable->passengerTable);
    free_user_table(hashTable->userTable);
    free_flight_table(hashTable->flightTable);
    free_reservation_table(hashTable->reservationTable);
    free(hashTable);
}