#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/users.h"

typedef struct users {
    char *id;
    char *name;
    //char *email; //n se usa
    //char *phone_number; //n se usa
    char *birth_date;
    char sex;
    char *passport;
    char *country_code;
    //char *address; //n se usa
    char *acc_creation;
    //char *payment; //n se usa
    char *status;
    struct users *next;

    Flights **user_flights;
    int current_user_flight;
    int max_user_flights;

    Reservations **user_reservations;
    int current_user_reservation;
    int max_user_reservations;
} Users;

Users *new_user(void){
    Users *new_user = (Users*)malloc(sizeof(Users));

    if (new_user != NULL){
        new_user->id = NULL;
        new_user->name = NULL;
        //new_user->email = NULL;
       //new_user->phone_number = NULL;
        new_user->birth_date = NULL;
        new_user->sex = '\0';
        new_user->passport = NULL;
        new_user->country_code = NULL;
        //new_user->address = NULL;
        new_user->acc_creation = NULL;
        //new_user->payment = NULL;
        new_user->status = NULL;
        new_user->next = NULL;

        new_user->current_user_flight = 0;
        new_user->max_user_flights = 30;
        new_user->user_flights = malloc(sizeof(Flights *) * 30);
        for(int i = 0; i < 30; i++) new_user->user_flights[i] = NULL;
        new_user->current_user_reservation = 0;
        new_user->max_user_reservations = 30;
        new_user->user_reservations = malloc(sizeof(Reservations *) * 30);
        for(int i = 0; i < 30; i++) new_user->user_reservations[i] = NULL;
    }

    return new_user;
}

char *get_user_id(const Users *user) {
    if(user == NULL) return NULL;
    if(user->id){
        char *id = strdup(user->id);
        return id;
    }
    return NULL;
}

char *get_user_name(const Users *user) {
    if(user == NULL) return NULL;
    if(user->name){
        char *name = strdup(user->name);
        return name;
    }
    return NULL;
}

char *get_user_birth_date(const Users *user) {
    if(user == NULL) return NULL;
    if(user->birth_date){
        char *birth_date = strdup(user->birth_date);
        return birth_date;
    }
    return NULL;
}

char get_user_sex(const Users *user) {
    if(user == NULL) return '\0';
    return user->sex;
}

char *get_user_passport(const Users *user) {
    if(user == NULL) return NULL;
    if(user->passport){
        char *passport = strdup(user->passport);
        return passport;
    }
    return NULL;
}

char *get_user_country_code(const Users *user) {
    if(user == NULL) return NULL;
    if(user->country_code){
        char *country_code = strdup(user->country_code);
        return country_code;
    }
    return NULL;
}

char *get_user_acc_creation(const Users *user) {
    if(user == NULL) return NULL;
    if(user->acc_creation){
        char *acc_creation = strdup(user->acc_creation);
        return acc_creation;
    }
    return NULL;
}


// Getter function for status
char *get_user_status(const Users *user) {
    if(user == NULL) return NULL;
    if(user->status){
        char *status = strdup(user->status);
        return status;
    }
    return NULL;
}

// Getter function for next
Users *get_next_user(const Users *user) {
    if(user == NULL) return NULL;
    if(user->next){
        return user->next;
    }
    return NULL;
}

// Setters for Users
// set user id
void set_U_id(Users *user, char *id){
    if(user->id) {
    free(user->id);
    user->id = NULL;
    }
    if (id) {
        user->id = strdup(id);
    }
}

void set_U_name(Users *user, char *name){
    if(user->name) {
    free(user->name);
    user->name = NULL;
    }
    if (name) {
        user->name = strdup(name);
    }
}

void set_U_birth_date(Users *user, char *birth_date){
    if(user->birth_date) {
    free(user->birth_date);
    user->birth_date = NULL;
    }
    if (birth_date) {
        user->birth_date = strdup(birth_date);
    }
}

void set_U_passport(Users *user, char *passport){
    if(user->passport) {
    free(user->passport);
    user->passport = NULL;
    }
    if (passport) {
        user->passport = strdup(passport);
    }
}

void set_U_country_code(Users *user, char *country_code){
    if(user->country_code) {
    free(user->country_code);
    user->country_code = NULL;
    }
    if (country_code) {
        user->country_code = strdup(country_code);
    }
}

void set_U_acc_creation(Users *user, char *acc_creation){
    if(user->acc_creation) {
    free(user->acc_creation);
    user->acc_creation = NULL;
    }
    if (acc_creation) {
        user->acc_creation = strdup(acc_creation);
    }
}

void set_U_status(Users *user, char *status){
    if(user->status) {
    free(user->status);
    user->status = NULL;
    }
    if (status) {
        user->status = strdup(status);
    }
}

void set_U_sex(Users *user, char sex){
    if(user == NULL) return;
    if(user->sex) user->sex = '\0';
    user->sex = sex;
}

void set_U_next(Users *user, Users *next){
    if(user->next) {
    free(user->next);
    user->next = NULL;
    }
    if (next) {
        user->next = next;
    }
}

// setter function for user flights
void set_user_flights(Users *user, Flights *flight) {
    if(user == NULL) return;
    if(flight == NULL) return;
    int maxF = user->max_user_flights;
    int currentF = user->current_user_flight;
    if(currentF >= maxF){
        user->max_user_flights += 15;
        user->user_flights = realloc(user->user_flights,sizeof(Flights *) * user->max_user_flights);
        for(int i = maxF; i < user->max_user_flights; i++) user->user_flights[i] = NULL;
    }
    user->user_flights[currentF] = flight;
    user->current_user_flight++;
}

// setter function for user reservations
void set_user_reservations(Users *user, Reservations *reservation) {
    if(user == NULL) return;
    if(reservation == NULL) return;
    int maxR = user->max_user_reservations;
    int currentR = user->current_user_reservation;
    if(currentR >= maxR){
        user->max_user_reservations += 15;
        user->user_reservations = realloc(user->user_reservations,sizeof(Reservations *) * user->max_user_reservations);
        for(int i = maxR; i < user->max_user_reservations; i++) user->user_reservations[i] = NULL;
    }
    user->user_reservations[currentR] = reservation;
    user->current_user_reservation++;
}


void free_user(Users *user){
    if (user != NULL){
        if(user->id) free(user->id);
        if(user->name) free(user->name);
        //if(user->email) free(user->email);
        //if(user->phone_number) free(user->phone_number);
        if(user->birth_date) free(user->birth_date);
        if(user->passport) free(user->passport);
        if(user->country_code) free(user->country_code);
        //if(user->address) free(user->address);
        if(user->acc_creation) free(user->acc_creation);
        //if(user->payment) free(user->payment);
        if(user->status) free(user->status);
        if(user->user_flights) free(user->user_flights);
        if(user->user_reservations) free(user->user_reservations);
        free(user);
    }
}

int hash_user(char *id) {
    int hash = 5381;
    int c = 0;

    while (id[c]) {
        hash = hash + c * (int)id[c]; 
        c++;
    }

    //if(hash < 0) return -hash;
    return hash;
}

// Getter function for user flights
Flights **get_user_flights(const Users *user) {
    if(user == NULL) return NULL;
    if(user->user_flights){
        return user->user_flights;
    }
    return NULL;
}

// Getter function for current user flight
int get_current_user_flight(const Users *user) {
    if(user == NULL) return 0;
    return user->current_user_flight;
}

// Getter function for max user flights
int get_max_user_flights(const Users *user) {
    if(user == NULL) return 0;
    return user->max_user_flights;
}

// Getter function for user reservations
Reservations **get_user_reservations(const Users *user) {
    if(user == NULL) return NULL;
    if(user->user_reservations){
        return user->user_reservations;
    }
    return NULL;
}

// Getter function for user reservation
Reservations *get_user_reservation(const Users *user, int i) {
    if(user == NULL) return NULL;
    if(user->user_reservations[i]){
        return user->user_reservations[i];
    }
    return NULL;
}

// Getter function for current user reservation
int get_current_user_reservation(const Users *user) {
    if(user == NULL) return 0;
    return user->current_user_reservation;
}

// Getter function for max user reservations
int get_max_user_reservations(const Users *user) {
    if(user == NULL) return 0;
    return user->max_user_reservations;
}