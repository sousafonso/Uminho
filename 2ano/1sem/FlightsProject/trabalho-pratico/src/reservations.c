#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/reservations.h"

typedef struct reservations {
    char *id;
    char *user_id;
    char *hotel_id;
    char *hotel_name;
    unsigned int stars;
    unsigned int tax;
    //char *address; //n se usa
    char *begin_date;
    char *end_date;
    unsigned int price_per_night;
    char *breakfast;
    //char *details; //n se usa
    unsigned int rating;
    //char *comments;//n se usa
    struct reservations *next;
} Reservations;

// Getter for Reservations
char *get_reservation_id(const Reservations *reservation) {
    if(reservation == NULL) return NULL;
    if(reservation->id){
        char *id = strdup(reservation->id);
        return id;
    }
    return NULL;
}

char *get_reserv_user_id(const Reservations *reservation) {
    if(reservation == NULL) return NULL;
    if(reservation->user_id){
        char *user_id = strdup(reservation->user_id);
        return user_id;
    }
    return NULL;
}

char *get_hotel_id(const Reservations *reservation) {
    if(reservation == NULL) return NULL;
    if(reservation->hotel_id){
        char *hotel_id = strdup(reservation->hotel_id);
        return hotel_id;
    }
    return NULL;
}

char *get_hotel_name(const Reservations *reservation) {
    if(reservation == NULL) return NULL;
    if(reservation->hotel_name){
        char *hotel_name = strdup(reservation->hotel_name);
        return hotel_name;
    }
    return NULL;
}

unsigned int get_stars(const Reservations *reservation) {
    if(reservation == NULL) return 0;
    return reservation->stars;
}

unsigned int get_tax(const Reservations *reservation) {
    if(reservation == NULL) return 0;
    return reservation->tax;
}

char *get_begin_date(const Reservations *reservation) {
    if(reservation == NULL) return NULL;
    if(reservation->begin_date){
        char *begin_date = strdup(reservation->begin_date);
        return begin_date;
    }
    return NULL;
}

char *get_end_date(const Reservations *reservation) {
    if(reservation == NULL) return NULL;
    if(reservation->end_date){
        char *end_date = strdup(reservation->end_date);
        return end_date;
    }
    return NULL;
}

unsigned int get_price_per_night(const Reservations *reservation) {
    if(reservation == NULL) return 0;
    return reservation->price_per_night;
}

char *get_breakfast(const Reservations *reservation) {
    if(reservation == NULL) return NULL;
    if(reservation->breakfast != NULL){
        char *breakfast_copy = strdup(reservation->breakfast);
        return breakfast_copy;
    }
    return NULL;
}


unsigned int get_rating(const Reservations *reservation) {
    if(reservation == NULL) return 0;
    return reservation->rating;
}

Reservations *get_next_reservation(const Reservations *reservation) {
    if(reservation == NULL) return NULL;
    if(reservation->next){
        return reservation->next;
    }
    return NULL;
}

Reservations *new_reservation(void){
    Reservations *new_reservation = (Reservations *)malloc(sizeof(Reservations));

    if (new_reservation != NULL){
        new_reservation->id = NULL;
        new_reservation->user_id = NULL;
        new_reservation->hotel_id = NULL;
        new_reservation->hotel_name = NULL;
        new_reservation->begin_date = NULL;
        new_reservation->breakfast = NULL;
        new_reservation->stars = 0;
        new_reservation->tax = 0;
        new_reservation->price_per_night = 0;
       // new_reservation->address = NULL;
        new_reservation->end_date = NULL;
        //new_reservation->details = NULL;
        new_reservation->rating = 0;
        //new_reservation->comments = NULL;
        new_reservation->next = NULL;

    }

    return new_reservation;
}


void set_R_reservation_id(Reservations *reservation, char *id){
    if(reservation->id) {
    free(reservation->id);
    reservation->id = NULL;
    }
    if (id) {
        reservation->id = strdup(id);
    }
}

void set_R_user_id(Reservations *reservation, char *user_id){
    if(reservation->user_id) {
    free(reservation->user_id);
    reservation->user_id = NULL;
    }
    if (user_id) {
        reservation->user_id = strdup(user_id);
    }
}

void set_R_hotel_id(Reservations *reservation, char *hotel_id){
    if(reservation->hotel_id) {
    free(reservation->hotel_id);
    reservation->hotel_id = NULL;
    }
    if (hotel_id) {
        reservation->hotel_id = strdup(hotel_id);
    }
}

void set_R_hotel_name(Reservations *reservation, char *hotel_name){
    if(reservation->hotel_name) {
    free(reservation->hotel_name);
    reservation->hotel_name = NULL;
    }
    if (hotel_name) {
        reservation->hotel_name = strdup(hotel_name);
    }
}

void set_R_begin_date(Reservations *reservation, char *begin_date){
    if(reservation->begin_date) {
    free(reservation->begin_date);
    reservation->begin_date = NULL;
    }
    if (begin_date) {
        reservation->begin_date = strdup(begin_date);
    }
}

void set_R_breakfast(Reservations *reservation, char *breakfast){
    if(reservation->breakfast) {
    free(reservation->breakfast);
    reservation->breakfast = NULL;
    }
    if (breakfast) {
        reservation->breakfast = strdup(breakfast);
    }
    else if(breakfast == NULL){
        reservation->breakfast = NULL;
    }
}

void set_R_stars(Reservations *reservation, unsigned int stars){
    reservation->stars = stars;
}

void set_R_tax(Reservations *reservation, unsigned int tax){
    reservation->tax = tax;
}

void set_R_price_per_night(Reservations *reservation, unsigned int price_per_night){
    reservation->price_per_night = price_per_night;
}

void set_R_end_date(Reservations *reservation, char *end_date){
    if(reservation->end_date) {
    free(reservation->end_date);
    reservation->end_date = NULL;
    }
    if (end_date) {
        reservation->end_date = strdup(end_date);
    }
}

void set_R_rating(Reservations *reservation, unsigned int rating){
    reservation->rating = rating;
}

void set_R_next(Reservations *reservation, Reservations *next){
    if(reservation->next) {
    free(reservation->next);
    reservation->next = NULL;
    }
    if (next) {
        reservation->next = next;
    }
}

// libertar memoria - reservation
void free_reservation(Reservations *reservation){
    if (reservation != NULL){
        if(reservation->id) free(reservation->id);
        if(reservation->user_id) free(reservation->user_id);
        if(reservation->hotel_id) free(reservation->hotel_id);
        if(reservation->hotel_name) free(reservation->hotel_name);
        if(reservation->begin_date) free(reservation->begin_date);
        if(reservation->breakfast) free(reservation->breakfast);
        //if(reservation->address) free(reservation->address);
        if(reservation->end_date) free(reservation->end_date);
        //if(reservation->details) free(reservation->details);
        //if(reservation->comments) free(reservation->comments);
        free(reservation);
    }
}