#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/FlightsTable.h"
#include "../include/flights.h"


typedef struct flightstable {
    Flights **flights;
    int flightSize;
} FlightsTable;

Flights *get_flight_node(const FlightsTable *flightTable, int node){
    if(flightTable == NULL) return NULL;
    if(flightTable->flights[node]) return flightTable->flights[node];
    return NULL;
}

int get_flight_table_size(const FlightsTable *flightTable){
    if(flightTable->flightSize) return flightTable->flightSize;
    return 0;
}

//função que cria a flightTable
FlightsTable *create_flight_table(void){
    FlightsTable *flightTable = (FlightsTable*)malloc(sizeof(FlightsTable));
    if(!flightTable) {
        perror("Erro ao alocar memória para a tabela de flights");
        exit(EXIT_FAILURE);
    }
    flightTable->flightSize = 512;
    flightTable->flights = malloc(sizeof(Flights *) * 512);
    if (!flightTable->flights) {
        perror("Erro ao alocar memória para a tabela de flights");
        free(flightTable);
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < 512; i++) flightTable->flights[i] = NULL;
    return flightTable;
}

//insere um novo flight
void insert_flight(char *flight_id, Flights *newFlight, FlightsTable *flightTable) {
    int total_flights = atoi(flight_id);  
    int size = flightTable->flightSize;
    if(total_flights >= size){
        flightTable->flightSize += total_flights;
        flightTable->flights = realloc(flightTable->flights,sizeof(Flights *) * flightTable->flightSize);
        for(int i = size; i < flightTable->flightSize; i++) flightTable->flights[i] = NULL;
    }
    if(flightTable->flights[total_flights] == NULL) flightTable->flights[total_flights] = newFlight;
    else{
        Flights *unexpected = flightTable->flights[total_flights];
        for(;get_next_flight(unexpected); unexpected = get_next_flight(unexpected));
        set_F_next(unexpected, newFlight);
    } 
}

//procura um flight
Flights *find_flight(char* flight_id, FlightsTable *flightTable) {
    int flight = atoi(flight_id);
    if(flight < flightTable->flightSize && flightTable->flights[flight]) return flightTable->flights[flight];
    return NULL;  // Flight não encontrado
}

//free na flight table
void free_flight_table(FlightsTable *flightTable){
    int total_flights = flightTable->flightSize;
    for (int i = 0; i < total_flights; i++) {
        for(Flights *aux = flightTable->flights[i]; aux; aux = get_next_flight(aux)) free_flight(aux);
    }
    free(flightTable->flights);
    free(flightTable);
}