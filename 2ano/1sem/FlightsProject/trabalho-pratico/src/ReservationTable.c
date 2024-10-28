#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/ReservationTable.h"
#include "../include/ReservationNode.h"
#include "../include/reservations.h"

typedef struct reservationstable {
    ReservationNode **reservations;
    int hotelSize;
} ReservationsTable;

ReservationNode *get_reservation_node(const ReservationsTable *reservationTable, int node){
    if(reservationTable == NULL) return NULL;
    if(reservationTable->reservations[node]) return reservationTable->reservations[node];
    return NULL;
}

int get_reservation_table_size(const ReservationsTable *reservationTable){
    if(reservationTable->hotelSize) return reservationTable->hotelSize;
    return 0;
}

//função que cria a reservationTable
ReservationsTable *create_reservation_table(void){
    ReservationsTable *reservationTable = (ReservationsTable*)malloc(sizeof(ReservationsTable));
    if(!reservationTable) {
        perror("Erro ao alocar memória para a tabela de reservations");
        exit(EXIT_FAILURE);
    }
    
    reservationTable->hotelSize = 1610;
    reservationTable->reservations = malloc(sizeof(ReservationNode *) * 1610);
    if (!reservationTable->reservations) {
        perror("Erro ao alocar memória para a tabela de reservations");
        free(reservationTable);
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < 1610; i++) reservationTable->reservations[i] = NULL;
    return reservationTable;
}

//insere um novo reservation
void insert_reservation(char *hotel_id, Reservations *newReservation, ReservationsTable *reservationTable) {
    int total_hotels = atoi(hotel_id + 3);  
    int size = reservationTable->hotelSize;
    if(total_hotels >= size){
        reservationTable->hotelSize = total_hotels + 110;
        reservationTable->reservations = realloc(reservationTable->reservations,sizeof(ReservationNode *) * reservationTable->hotelSize);
        for(int i = size; i < reservationTable->hotelSize; i++) reservationTable->reservations[i] = NULL;
    }
    if(reservationTable->reservations[total_hotels] == NULL) reservationTable->reservations[total_hotels] = create_reservation_node();
    ReservationNode *currentReservation = reservationTable->reservations[total_hotels];  

    int reservSize = get_reservation_node_occupied(currentReservation);
    if(reservSize >= get_reservation_node_size(currentReservation)){
        set_reservation_node_size(currentReservation, get_reservation_node_size(currentReservation) + reservSize);
        Reservations **reservations = get_all_reservations(currentReservation);
        reservations = realloc(reservations,sizeof(Reservations *) * get_reservation_node_size(currentReservation));
        for(int i = reservSize; i < get_reservation_node_size(currentReservation); i++) reservations[i] = NULL;
        set_all_reservations(currentReservation, reservations);
    }
    set_one_reservation(currentReservation, newReservation);
}

static Reservations *reservation_merge(int reservation_id, Reservations **reservations, int used_reservations){
    if(used_reservations == 0) return NULL;
    int middle = used_reservations/2;
    char *current_reservation_id = get_reservation_id(reservations[middle]);
    int id = atoi(current_reservation_id + 4);
    free(current_reservation_id);
    current_reservation_id = NULL;
    if(id == reservation_id) return reservations[middle];
    if(id > reservation_id) return reservation_merge(reservation_id, reservations, middle);
    else return reservation_merge(reservation_id, reservations + middle + 1, used_reservations - middle - 1);
}

//procura um reservation
Reservations *find_reservation(char* reservation_id, ReservationsTable *reservationTable) {
    int size = reservationTable->hotelSize;
        int id = atoi(reservation_id + 4);
    for(int i = 0; i < size; i++){
        
        ReservationNode *reservationNode = reservationTable->reservations[i];
        if(reservationNode == NULL) continue;
        int reservSize = get_reservation_node_occupied(reservationNode);
        Reservations **current = get_all_reservations(reservationNode);
        
        Reservations *return_me = reservation_merge(id,current,reservSize);
        if (return_me != NULL) {
            return return_me;
        }
    }
    return NULL;  // Passageiro não encontrado
}

//free na reservation table
void free_reservation_table(ReservationsTable *reservationTable){
    int total_hotels = reservationTable->hotelSize;
    for (int i = 0; i < total_hotels; i++) {
        ReservationNode *current_reservation = reservationTable->reservations[i];
        free_reservation_node(current_reservation);
    }
    free(reservationTable->reservations);
    free(reservationTable);
}