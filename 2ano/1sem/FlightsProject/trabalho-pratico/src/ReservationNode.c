#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/ReservationNode.h"
#include "../include/reservations.h"

typedef struct reservationode{
    Reservations **reservation;
    int nodeSize;
    int howOccupied; //quantos reservations tem neste nodo
} ReservationNode;

Reservations **get_all_reservations(const ReservationNode *reservationNode){
    if(reservationNode == NULL) return NULL;
    if(reservationNode->reservation) return reservationNode->reservation;
    return NULL;
}

int get_reservation_node_occupied(const ReservationNode *reservationNode){
    if(reservationNode == NULL) return 0;
    if(reservationNode->howOccupied) return reservationNode->howOccupied;
    return 0;
}

int get_reservation_node_size(const ReservationNode *reservationNode){
    if(reservationNode == NULL) return 0;
    if(reservationNode->nodeSize) return reservationNode->nodeSize;
    return 0;
}

void set_one_reservation(ReservationNode *reservationNode, Reservations *reservation){
    if(reservationNode == NULL) return;
    int occupied = reservationNode->howOccupied;
    reservationNode->howOccupied++;
    if(reservationNode->reservation) reservationNode->reservation[occupied] = reservation;
}

void set_all_reservations(ReservationNode *reservationNode, Reservations **reservations){
    if(reservationNode == NULL) return;
    reservationNode->reservation = reservations;
}

void set_reservation_node_occupied(ReservationNode *reservationNode, int occupied){
    if(reservationNode) reservationNode->howOccupied = occupied;
}

void set_reservation_node_size(ReservationNode *reservationNode, int size){
    if(reservationNode) reservationNode->nodeSize = size;
}

ReservationNode *create_reservation_node(void){
    ReservationNode *reservationNode = (ReservationNode*)malloc(sizeof(ReservationNode));
    if(!reservationNode) {
        perror("Erro ao alocar memória para a tabela de reservations");
        exit(EXIT_FAILURE);
    }
    reservationNode->howOccupied = 0;
    reservationNode->nodeSize = 32768;
    reservationNode->reservation = malloc(sizeof(Reservations *) * 32768);
    if (!reservationNode->reservation) {
        perror("Erro ao alocar memória para o node de reservations");
        free(reservationNode);
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < 32768; i++) reservationNode->reservation[i] = NULL;
    return reservationNode;
}

void free_reservation_node(ReservationNode *reservationNode){
    if(reservationNode == NULL) return;
    int size = reservationNode->howOccupied;
    for(int i = 0; i < size; i++) free_reservation(reservationNode->reservation[i]);
    free(reservationNode->reservation);
    free(reservationNode);
}