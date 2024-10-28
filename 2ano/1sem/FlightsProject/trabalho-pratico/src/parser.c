#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h> //isalpha- ve se é letra
#include <time.h>

#include "../include/DataStore.h"
#include "../include/parser.h"
#include "../include/statistics.h"
#include "../include/flights.h"
#include "../include/users.h"
#include "../include/reservations.h"
#include "../include/passengers.h"
#include "../include/PassengerTable.h"
#include "../include/UserTable.h"

// algoritmo para escrever a linha que contem erros num ficheiro x_errors.csv
static void create_error_file_and_print_line(char *filename, char *line, int argSize) {

    char *file_path = malloc(argSize + 20);
    strncpy(file_path,"Resultados",17);
    strcat(file_path,filename);
    FILE * line_errors = fopen(file_path,"a");
    if (line_errors == NULL) {
    perror("Erro ao abrir1");
    free(file_path);
    file_path = NULL;
    // Tratar o erro de abertura do arquivo, se necessário
    return;
    }
    int x = strlen(line) + 100;
    char * print_line = malloc(sizeof(char) * x);

    strcpy(print_line,line);

    fprintf(line_errors, "%s", print_line);
    fclose(line_errors);
    free(file_path);
    file_path = NULL;
    free(print_line);
    print_line = NULL;
}

//le uma linha do ficheiro dos users
static void parse_user_line(char *line, HashTable *hashTable, int argSize){ 
    // Cópia temporária da linha, pois strtok modifica a string original
    Users *user = new_user();
    char *tmpLine = strdup(line);
    char *token = NULL;
    char *rest = tmpLine;
    int field = 0, check = 1;

    if(rest[0] == ';') check = 0;
    token = strtok_r(NULL,";\n\0", &rest);

    while (token && check) {
        switch (field) {
            case 0: 
                if(rest[0] != ';')set_U_id(user, token);
                else check = 0;
                break;
                
            case 1: 
                if(rest[0] != ';')set_U_name(user,token);
                else check = 0;
                break;

            case 2: 
                if(rest[0] == ';' || !check_email(token))check = 0;
                break;

            case 3:
                if(rest[0] == ';')check = 0;
                break;

            case 4: 
                if(rest[0] != ';' && is_date_correct(token))set_U_birth_date(user,token);
                else check = 0;
                break;

            case 5:
                if(rest[0] != ';')set_U_sex(user,token[0]);
                else check = 0;
                break;

            case 6:
                if(rest[0] != ';')set_U_passport(user,token);
                else check = 0;
                break;

            case 7: 
                if(rest[0] != ';' && check_country_code(token))set_U_country_code(user,token);
                else check = 0;
                break;

            case 8: 
                if(rest[0] == ';')check = 0;
                break;

            case 9: 
                if(rest[0] != ';' && check_time_format(token))set_U_acc_creation(user,token);
                else check = 0;
                break;

            case 10: 
                if(rest[0] == '\n' || rest[0] == '\0') check = 0;
                break;

            case 11: 
                if(check_account_status(token))set_U_status(user,token);
                else check = 0;
                break;

            default: 
                // Lidar com mais campos ou erro
                break;
        }
        field++;
        token = strtok_r(NULL,";\n\0", &rest);
    }
    
    if(check){
        char *birth = get_user_birth_date(user);
        char *acc = get_user_acc_creation(user);
        if(check && strcmp(birth,acc) > 0) check = 0;
        free(birth);
        birth = NULL;
        free(acc);
        acc = NULL;
    }

    // Se check for 1, não houve um erro em algum dos campos
    if (check) {
        // Insere na tabela de hash se todos os campos foram corretamente analisados
        char *userId = get_user_id(user);
        insert_user(userId, user, get_user_table(hashTable));
        free(tmpLine);
        tmpLine = NULL;
        free(userId);
        userId = NULL;
    } else {
        create_error_file_and_print_line("/users_errors.csv", line, argSize);
        free(tmpLine);
        tmpLine = NULL;
        free_user(user);
        user = NULL;
        return;
    }
}

//le uma linha do ficheiro dos flights
static void parse_flight_line (char *line, HashTable *hashTable, int argSize) {
    Flights *flight = new_flight();
    char *tmpLine = strdup(line);
    char *token = NULL;
    char *rest = tmpLine;
    int field = 0, check = 1;
    if(rest[0] == ';') check = 0;
    token = strtok_r(NULL,";\n\0", &rest);

    while (token && check) {
        switch (field) {
            case 0: 
                if(rest[0] != ';')set_F_flight_id(flight, token);
                else check = 0;
                break;

            case 1:
                if(rest[0] != ';')set_F_airline(flight, token);
                else check = 0;
                break;

            case 2:
                if(rest[0] != ';')set_F_model(flight, token);
                else check = 0;
                break;

            case 3:
                if(rest[0] != ';' && are_numbers(token))set_F_sits(flight, atoi(token)); 
                else check = 0;
                break;

            case 4:
                if(rest[0] != ';' && check_origem_destino(token)){
                    make_upper(token);
                    set_F_origem(flight, token);
                } else check = 0;
                break;

            case 5:
                if(rest[0] != ';' && check_origem_destino(token)){
                    make_upper(token);
                    set_F_destino(flight, token);
                } else check = 0;
                break;

            case 6: 
                if(rest[0] != ';' && check_time_format(token))set_F_dep(flight, token);
                else check = 0;
                break;

            case 7:
                if(rest[0] != ';' && check_time_format(token))set_F_arr(flight, token);
                else check = 0;
                break;

            case 8: 
                if(rest[0] != ';' && check_time_format(token))set_F_rdep(flight, token);
                else check = 0;
                break;

            case 9: 
                if(rest[0] != ';' && check_time_format(token))set_F_rarr(flight, token);
                else check = 0;
                break;

            case 10: 
                if(rest[0] == ';') check = 0;
                break;

            case 11:
            //no case 10 ve se este esta vazio ou não
                break;

            case 12:
                break;

            default: 
                // Lidar com mais campos ou erro
                break;
        }
        field++;
        token = strtok_r(NULL,";\n\0", &rest);
    }
    if(check){
        char *dep = get_dep(flight);
        char *arr = get_arr(flight);
        char *rdep = get_rdep(flight);
        char *rarr = get_rarr(flight);

        if(check && strcmp(dep,arr) > 0 && strcmp(dep + 11,arr + 11) > 0) check = 0;
        if(check && strcmp(rdep,arr) > 0 && strcmp(rdep + 11,arr + 11) > 0) check = 0;
        if(check && strcmp(dep,rarr) > 0 && strcmp(dep + 11,rarr + 11) > 0) check = 0;
        if(check && strcmp(arr,rarr) > 0 && strcmp(arr + 11,rarr + 11) > 0) check = 0;

        free(dep);
        dep = NULL;
        free(rdep);
        rdep = NULL;
        free(arr);
        arr = NULL;
        free(rarr);
        rarr = NULL;
    }

    // verifica se existem erros nos campos
    if (check) {
        // Insere na tabela de hash se todos os campos foram corretamente analisados
        char *flightId = get_flight_id(flight);
        insert_flight(flightId, flight, get_flight_table(hashTable));
        free(tmpLine);
        tmpLine = NULL;
        free(flightId);
        flightId = NULL;
    } else {
        create_error_file_and_print_line("/flights_errors.csv", line, argSize);//é suposto ir para "../Resusltados/flight_errors.csv"
        free(tmpLine);
        tmpLine = NULL;
        free_flight(flight);
        flight = NULL;
        return;
    }
}

//le uma linha do ficheiro das reservations
static void parse_reservation_line (char *line, HashTable *hashTable, int argSize) {
    Reservations *reservation = new_reservation();
    char *tmpLine = strdup(line);
    char *token;
    char *rest = tmpLine;
    int field = 0, check = 1;
    Users *user = NULL;

    if(rest[0] == ';') check = 0;
    token = strtok_r(NULL,";\n\0", &rest);
    
    while (token && check) {
        switch (field) {

            case 0:
                if(rest[0] != ';')set_R_reservation_id(reservation, token);
                else check = 0;
                break;

            case 1: 
                if(rest[0] != ';'){
                    user = find_user(token, get_user_table(hashTable));
                    if(user != NULL) set_R_user_id(reservation, token);
                    else check = 0;
                }
                if(rest[0] == ';') check = 0;
                break;

            case 2:
                if(rest[0] != ';')set_R_hotel_id(reservation, token);
                else check = 0;
                break;

            case 3:
                if(rest[0] != ';')set_R_hotel_name(reservation, token);
                else check = 0;
                break;

            case 4: 
                if(rest[0] != ';' && check_hotel_stars(token))set_R_stars(reservation, atoi(token));
                else check = 0;
                break;

            case 5: 
                if(rest[0] != ';' && check_city_tax(token))set_R_tax(reservation, atoi(token));
                else check = 0;
                break;

            case 6:
                if(rest[0] == ';') check = 0;
                break;

            case 7: 
                if(rest[0] != ';' && is_date_correct(token))set_R_begin_date(reservation, token);
                else check = 0;
                break;

            case 8: 
                if(rest[0] != ';' && is_date_correct(token))set_R_end_date(reservation, token);
                else check = 0;
                break;

            case 9:
                if(check_price_per_night(token))set_R_price_per_night(reservation, atoi(token));
                else check = 0;
                if(rest[0] == ';') field++;
                break;

            case 10: 
                if(rest[0] != ';' && check_includes_breakfast(token))set_R_breakfast(reservation, token);
                else check = 0;
                break;

            case 11:
                if(rest[0] == ';') check = 0;
                break;

            case 12: 
                if(check_hotel_rating(token))set_R_rating(reservation, atoi(token));
                else check = 0;
                break;
                
            case 13:
                break;

            default: 
                // Lidar com mais campos ou erro
                break;
            }
        field++;
        token = strtok_r(NULL,";\n\0", &rest);

    }

    if(check){
        char *begin = get_begin_date(reservation);
        char *end = get_end_date(reservation);
        if(check && strcmp(begin,end) >= 0) check = 0;
        free(begin);
        begin = NULL;
        free(end);
        end = NULL;
    }

    // Se check for 1, não houve um erro em algum dos campos
    if (check) {
        // Insere na tabela de hash se todos os campos foram corretamente analisados
        char *reservationHotelId = get_hotel_id(reservation);
        insert_reservation(reservationHotelId, reservation, get_reservation_table(hashTable));
        set_user_reservations(user, reservation);
        free(tmpLine);
        tmpLine = NULL;
        free(reservationHotelId);
        reservationHotelId = NULL;
    } else {
        create_error_file_and_print_line("/reservations_errors.csv", line, argSize);//é suposto ir para "../Resusltados/reservation_errors.csv"
        free(tmpLine);
        tmpLine = NULL;
        free_reservation(reservation);
        reservation = NULL;
        return;
    }
}

//le uma linha do ficheiro dos passengers
static void parse_passenger_line (char *line, HashTable *hashTable, int argSize) {
    Passengers *passenger = new_passengers();
    char *tmpLine = strdup(line);
    char *token;
    char *rest = tmpLine;
    int field = 0, check = 1;
    Users *user = NULL;
    Flights *flight = NULL;

    if(rest[0] == ';') check = 0;
    token = strtok_r(NULL,";\n\0", &rest);
    
    while (token && check) {
        switch (field) {
            case 0: {
                if(rest[0] != '\n' && rest[0] != '\0'){
                    flight = find_flight(token, get_flight_table(hashTable));
                    if(flight != NULL) set_P_flight_id(passenger, token);
                    else check = 0;
                } else check = 0;
                break;
            }

            case 1: {
                user = find_user(token, get_user_table(hashTable));
                if(user != NULL) set_P_user_id(passenger, token);
                else check = 0;
                break;
            }

            default: 
                // Lidar com mais campos ou erro
                break;
        }
        field++;
        token = strtok_r(NULL,";\n\0", &rest);
    }

    // Se check for 1, não houve um erro em algum dos campos
    if (check) {
        char *flightId = get_passenger_flight_id(passenger);
        insert_passenger(flightId, passenger,get_passenger_table(hashTable));
        set_user_flights(user, flight);
        free(tmpLine);
        tmpLine = NULL;
        free(flightId);
        flightId = NULL;
    } else {
        create_error_file_and_print_line("/passengers_errors.csv", line, argSize);//é suposto ir para "../Resusltados/passengers_errors.csv"
        free(tmpLine);
        tmpLine = NULL;
        free_passengers(passenger);
        passenger = NULL;
        return;
    }
}

//cria o parser
void parser(char *argv, HashTable *hashTable, int argSize){

    char *line = NULL;
    size_t len = 0;
    size_t read;

    char *user_path = malloc(argSize + 20);

    memset(user_path,'\0',argSize + 20);

    strncpy(user_path,argv,argSize);

    strncat(user_path,"/users.csv",12);

    user_path[12 + argSize] = '\0';

    FILE *user_file = fopen(user_path, "r"); 

    if(user_file != NULL) {
        while((read = getline(&line, &len, user_file)) != -1) {
            parse_user_line(line, hashTable, argSize);
        }
        if(line) free(line);
        line = NULL;
    }

    fclose(user_file);
    free(user_path);
    user_path = NULL;
    
    sort_users_table(get_user_table(hashTable));
    
    char *flight_path = malloc(argSize + 20);

    memset(flight_path,'\0',argSize + 20);

    strncpy(flight_path,argv,argSize);

    strncat(flight_path,"/flights.csv",14);

    flight_path[14 + argSize] = '\0';

    FILE *flight_file = fopen(flight_path, "r"); 

    if(flight_file != NULL){
        while((read = getline(&line, &len, flight_file)) != -1) {
            parse_flight_line(line,hashTable, argSize);
        }
        if(line) free(line);
        line = NULL;
    }

    fclose(flight_file);
    free(flight_path);
    flight_path = NULL;

    char *reservation_path = malloc(argSize + 20);

    memset(reservation_path,'\0',argSize + 20);

    strncpy(reservation_path,argv,argSize);

    strncat(reservation_path,"/reservations.csv",19);

    reservation_path[19 + argSize] = '\0';


    FILE *reservation_file = fopen(reservation_path, "r"); 

    if(reservation_file != NULL){
        while((read = getline(&line, &len, reservation_file)) != -1) {
            parse_reservation_line(line,hashTable, argSize);
        }
        if(line) free(line);
        line = NULL;
    }

    fclose(reservation_file);
    free(reservation_path);
    reservation_path = NULL;

    int size_passenger = get_flight_table_size(get_flight_table(hashTable));
    complete_hash_table(hashTable, size_passenger);

    char *passenger_path = malloc(argSize + 20);

    memset(passenger_path,'\0',argSize + 20);

    strncpy(passenger_path,argv,argSize);

    strncat(passenger_path,"/passengers.csv",17);

    passenger_path[17 + argSize] = '\0';

    FILE *passenger_file = fopen(passenger_path, "r"); 

    if(passenger_file != NULL){
        while((read = getline(&line, &len, passenger_file)) != -1) {
            parse_passenger_line(line,hashTable/*, passengerTable*/,argSize);
        }
        if(line) free(line);
        line = NULL;
    }

    fclose(passenger_file);
    free(passenger_path);
    passenger_path = NULL;

}
