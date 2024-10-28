#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/PassengerNode.h"
#include "../include/passengers.h"

typedef struct passengernode{
    Passengers *passenger;
    Passengers *last_passenger;
    int howOccupied; //quantos users tem neste nodo
} PassengerNode;

Passengers *get_first_passenger(const PassengerNode *passengerNode){
    if(passengerNode == NULL) return NULL;
    if(passengerNode->passenger) return passengerNode->passenger;
    return NULL;
}

Passengers *get_last_passenger(const PassengerNode *passengerNode){
    if(passengerNode == NULL) return NULL;
    if(passengerNode->last_passenger) return passengerNode->last_passenger;
    return NULL;
}

int get_passenger_node_occupied(const PassengerNode *passengerNode){
    if(passengerNode->howOccupied) return passengerNode->howOccupied;
    return 0;
}

void set_first_passenger(PassengerNode *passengerNode, Passengers *passenger){
    if(passengerNode == NULL || passengerNode->passenger != NULL) return;
    passengerNode->passenger = passenger;
}

void set_last_passenger(PassengerNode *passengerNode, Passengers *newPassenger){
    if(passengerNode == NULL) return;
    
    passengerNode->howOccupied++;
    if(passengerNode->last_passenger == NULL){
        passengerNode->last_passenger = newPassenger;
        return;
    }
    Passengers *last_passenger = passengerNode->last_passenger;
    set_P_next(last_passenger, newPassenger);
    passengerNode->last_passenger = get_next_passenger(last_passenger);
}

void set_passenger_node_occupied(PassengerNode *passengerNode, int howOccupied){
    if(passengerNode) passengerNode->howOccupied = howOccupied;
}

PassengerNode *create_passenger_node(void){
    PassengerNode *passengerNode = (PassengerNode*)malloc(sizeof(PassengerNode));
    if(!passengerNode) {
        perror("Erro ao alocar memória para a tabela de passengers");
        exit(EXIT_FAILURE);
    }
    passengerNode->howOccupied = 0;
    passengerNode->last_passenger = NULL;
    passengerNode->passenger = NULL;
    return passengerNode;
}

void free_passenger_node(PassengerNode *passengerNode){
    if(passengerNode == NULL) return;
    Passengers* current_passenger = passengerNode->passenger;
    while (current_passenger != NULL) {
        Passengers* next_passenger = get_next_passenger(current_passenger);
        free_passengers(current_passenger);
        current_passenger = next_passenger;
    }
    free(passengerNode);
}