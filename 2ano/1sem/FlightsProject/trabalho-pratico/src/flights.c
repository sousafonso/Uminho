#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/flights.h"

typedef struct flights {
    char *id;
    char *airline;     // companhia aérea 
    char *model;       // modelo do avião
    int sits;
    char *origem;
    char *destino;
    char *dep;         // data de partida prevista
    char *arr;        // data de chegada prevista
    char *rdep;        // data de partida real
    char *rarr;      // data de chegada real
    //char *pilot; //n se usa      --- nome do piloto
    //char *copilot; //n se usa    --- nome do copiloto
    //char *notes;  // n se usa    --- notas sobre o voo
    struct flights *next;
} Flights;


char *get_flight_id(const Flights *flight) {
    if(flight == NULL) return NULL;
    if(flight->id){
        char *id = strdup(flight->id);
        return id;
    }
    return NULL;
}

char *get_airline(const Flights *flight) {
    if(flight == NULL) return NULL;
    if(flight->airline){
        char *airline = strdup(flight->airline);
        return airline;
    }
    return NULL;
}

char *get_model(const Flights *flight) {
    if(flight == NULL) return NULL;
    if(flight->model){
        char *model = strdup(flight->model);
        return model;
    }
    return NULL;
}

int get_sits(const Flights *flight) {
    if(flight == NULL) return 0;
    return flight->sits;
}

char *get_origem(const Flights *flight) {
    if(flight == NULL) return NULL;
    if(flight->origem){
        char *origem = strdup(flight->origem);
        return origem;
    }
    return NULL;
}

char *get_destino(const Flights *flight) {
    if(flight == NULL) return NULL;
    if(flight->destino){
        char *destino = strdup(flight->destino);
        return destino;
    }
    return NULL;
}

char *get_dep(const Flights *flight) {
    if(flight == NULL) return NULL;
    if(flight->dep){
        char *dep = strdup(flight->dep);
        return dep;
    }
    return NULL;
}

char *get_rdep(const Flights *flight) {
    if(flight == NULL) return NULL;
    if(flight->rdep){
        char *rdep = strdup(flight->rdep);
        return rdep;
    }
    return NULL;
}

char *get_arr(const Flights *flight) {
    if(flight == NULL) return NULL;
    if(flight->arr){
        char *arr = strdup(flight->arr);
        return arr;
    }
    return NULL;
}

char *get_rarr(const Flights *flight) {
    if(flight == NULL) return NULL;
    if(flight->rarr){
        char *rarr = strdup(flight->rarr);
        return rarr;
    }
    return NULL;
}

Flights *get_next_flight(const Flights *flight) {
    if(flight == NULL) return NULL;
    if(flight->next){
        return flight->next;
    }
    return NULL;
}

//busca as 3 letras de um aeroporto
char *get_current_airport (const char *existing_airports){
    char origem[4];
    origem[0] = existing_airports[0];
    origem[1] = existing_airports[1];
    origem[2] = existing_airports[2];
    origem[3] = '\0';
    return strdup(origem);
}

Flights *new_flight(void){
    Flights *new_flight = (Flights*)malloc(sizeof(Flights));

    if (new_flight != NULL){
        new_flight->id = NULL;
        new_flight->airline = NULL;
        new_flight->origem = NULL;
        new_flight->model = NULL;
        new_flight->destino = NULL;
        new_flight->dep = NULL;
        new_flight->rdep = NULL;
        new_flight->arr = NULL;
        new_flight->rarr = NULL;
        new_flight->sits = 0;
        //new_flight->copilot = NULL;
        //new_flight->pilot = NULL;
        //new_flight->notes = NULL;
        new_flight->next = NULL;

    }

    return new_flight;
}


void set_F_flight_id(Flights *flight, char *id){
    if(flight->id) {
    free(flight->id);
    flight->id = NULL;
    }
    if (id) {
        flight->id = strdup(id);
    }
}

void set_F_airline(Flights *flight, char *airline){
    if(flight->airline) {
    free(flight->airline);
    flight->airline = NULL;
    }
    if (airline) {
        flight->airline = strdup(airline);
    }
}

void set_F_origem(Flights *flight, char *origem){
    if(flight->origem) {
    free(flight->origem);
    flight->origem = NULL;
    }
    if (origem) {
        flight->origem = strdup(origem);
    }
}

void set_F_model(Flights *flight, char *model){
    if(flight->model) {
    free(flight->model);
    flight->model = NULL;
    }
    if (model) {
        flight->model = strdup(model);
    }
}

void set_F_destino(Flights *flight, char *destino){
    if(flight->destino) {
    free(flight->destino);
    flight->destino = NULL;
    }
    if (destino) {
        flight->destino = strdup(destino);
    }
}

void set_F_dep(Flights *flight, char *dep){
    if(flight->dep) {
    free(flight->dep);
    flight->dep = NULL;
    }
    if (dep) {
        flight->dep = strdup(dep);
    }
}

void set_F_rdep(Flights *flight, char *rdep){
    if(flight->rdep) {
    free(flight->rdep);
    flight->rdep = NULL;
    }
    if (rdep) {
        flight->rdep = strdup(rdep);
    }
}

void set_F_arr(Flights *flight, char *arr){
    if(flight->arr) {
    free(flight->arr);
    flight->arr = NULL;
    }
    if (arr) {
        flight->arr = strdup(arr);
    }
}

void set_F_rarr(Flights *flight, char *rarr){
    if(flight->rarr) {
    free(flight->rarr);
    flight->rarr = NULL;
    }
    if (rarr) {
        flight->rarr = strdup(rarr);
    }
}

void set_F_sits(Flights *flight, int sits){
    flight->sits = sits;
}

void set_F_next(Flights *flight, Flights *next){
    if(flight->next) {
    free(flight->next);
    flight->next = NULL;
    }
    if (next) {
        flight->next = next;
    }
}

void free_flight(Flights *flight){
    if (flight != NULL){
        if(flight->id) free(flight->id);
        if(flight->airline) free(flight->airline);
        if(flight->origem) free(flight->origem);
        if(flight->model) free(flight->model);
        if(flight->destino) free(flight->destino);
        if(flight->dep) free(flight->dep);
        if(flight->rdep) free(flight->rdep);
        if(flight->arr) free(flight->arr);
        if(flight->rarr) free(flight->rarr);
        //if(flight->copilot) free(flight->copilot);
        //if(flight->pilot) free(flight->pilot);
        //if(flight->notes) free(flight->notes);
        free(flight);
    }
}