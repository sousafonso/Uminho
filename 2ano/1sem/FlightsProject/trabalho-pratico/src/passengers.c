#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/passengers.h"

typedef struct passengers {
    char *flight_id;
    char *user_id;
    struct passengers *next;
} Passengers;

char *get_passenger_flight_id(const Passengers *passenger) {
    if(passenger == NULL) return NULL;
    if(passenger->flight_id){
        char *flight_id = strdup(passenger->flight_id);
        return flight_id;
    }
    return NULL;
}

char *get_passenger_user_id(const Passengers *passenger) {
    if(passenger == NULL) return NULL;
    if(passenger->user_id){
        char *user_id = strdup(passenger->user_id);
        return user_id;
    }
    return NULL;
}

Passengers *get_next_passenger(const Passengers *passenger) {
    if(passenger == NULL) return NULL;
    if(passenger->next){
        return passenger->next;
    }
    return NULL;
}

Passengers *new_passengers(void){
    Passengers *new_passengers = (Passengers*)malloc(sizeof(Passengers));

    if (new_passengers != NULL){
        // Set default values to NULL
        new_passengers->flight_id = NULL;
        new_passengers->user_id = NULL;
        new_passengers->next = NULL;

    }

    return new_passengers;
}

void set_P_flight_id(Passengers *passengers, char *flight_id){
    if(passengers->flight_id) {
    free(passengers->flight_id);
    passengers->flight_id = NULL;
    }
    if (flight_id) {
        passengers->flight_id = strdup(flight_id);
    }
}

void set_P_user_id(Passengers *passengers, char *user_id){
    if(passengers->user_id) {
    free(passengers->user_id);
    passengers->user_id = NULL;
    }
    if (user_id) {
        passengers->user_id = strdup(user_id);
    }
}

void set_P_next(Passengers *passengers, Passengers *next){
    if(passengers->next) {
    free(passengers->next);
    passengers->next = NULL;
    }
    if (next) {
        passengers->next = next;
    }
}

void free_passengers(Passengers *passengers){
    if (passengers != NULL){
        if(passengers->user_id){
            free(passengers->user_id);
            passengers->user_id = NULL;
        }
        if(passengers->flight_id){
            free(passengers->flight_id);
            passengers->flight_id = NULL;
        }
        free(passengers);
        passengers = NULL;
    }
}
