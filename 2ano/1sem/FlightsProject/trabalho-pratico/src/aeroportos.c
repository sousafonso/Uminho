#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/aeroportos.h"
#include "../include/DataStore.h"
#include "../include/statistics.h"
#include "../include/FlightsTable.h"

void new_airport(char *airports, char *new_airport){
    int i = 0;
    for(; airports[i]; i++);
    airports[i] = new_airport[0];
    i++;
    airports[i] = new_airport[1];
    i++;
    airports[i] = new_airport[2];
}

char *existing_airports(const HashTable *hashTable){
    int sizeOrigins = 100;
    char *allOrigins = (char *)malloc(sizeOrigins * sizeof(char));
    memset(allOrigins, '\0', sizeOrigins * sizeof(char));
    Flights *sameOrigin = new_flight();
    Flights *currentOrigin = sameOrigin;
    FlightsTable *flightsTable = get_flight_table(hashTable);
    int size = get_flight_table_size(flightsTable);
    for(int i = 0; i < size; i++){
        // Percorrer a lista encadeada correspondente até encontrar o aeroporto com o nome correspondente
        Flights* current = get_flight_node(flightsTable, i);
        while (current != NULL) {
            char *origem = get_origem(current);
            char *destino = get_destino(current);
            
            if (!airport_already_exists(sameOrigin, origem)) {

                set_F_origem(currentOrigin, origem);

                Flights *nextOrigin = new_flight();
                set_F_next(currentOrigin, nextOrigin);
                currentOrigin = get_next_flight(currentOrigin);   
 
                int size = strlen(allOrigins);
                if(size >= sizeOrigins - 10) {
                    sizeOrigins += 100;
                    allOrigins = realloc(allOrigins,sizeOrigins * sizeof(char));
                    memset(allOrigins + sizeOrigins - 100, '\0', 100 * sizeof(char));
                }
                
                new_airport(allOrigins, origem);
            } 
            free(origem);
            origem = NULL;
            
            if (!airport_already_exists(sameOrigin, destino)) {

                set_F_origem(currentOrigin, destino);

                Flights *nextOrigin = new_flight();
                set_F_next(currentOrigin, nextOrigin);
                currentOrigin = get_next_flight(currentOrigin);   
 
                int size = strlen(allOrigins);
                if(size >= sizeOrigins - 10) {
                    sizeOrigins += 100;
                    allOrigins = realloc(allOrigins,sizeOrigins * sizeof(char));
                    memset(allOrigins + sizeOrigins - 100, '\0', 100 * sizeof(char));
                }
                
                new_airport(allOrigins, destino);
            } 
            free(destino);
            destino = NULL;
            
            current = get_next_flight(current);
        }
    }
    for(; sameOrigin; sameOrigin = get_next_flight(sameOrigin)) free_flight(sameOrigin);

    return allOrigins;
}

int current_aeroporto(char *existing_airports, char *locate_airport){
    int local = 0;
    for(int i = 0; existing_airports[i]; i += 3){
        if(existing_airports[i] == locate_airport[0] && existing_airports[i + 1] == locate_airport[1] 
        && existing_airports[i + 2] == locate_airport[2]) return local;
        local++;
    }
    return -1;
}