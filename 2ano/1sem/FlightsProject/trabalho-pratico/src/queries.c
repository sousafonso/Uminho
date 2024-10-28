#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <ncurses.h>
#include <iconv.h>

#include "../include/queries.h"
#include "../include/DataStore.h"
#include "../include/parser.h"
#include "../include/statistics.h"
#include "../include/flights.h"
#include "../include/users.h"
#include "../include/reservations.h"
#include "../include/passengers.h"
#include "../include/windows.h"
#include "../include/time.h"
#include "../include/math.h"
#include "../include/sort.h"
#include "../include/aeroportos.h"
#include "../include/totalatrasos.h"
#include "../include/procura.h"
#include "../include/metrics.h"

extern int inter;//, uno;
int coisa = 0;

//query1
void query1 (const HashTable *hashTable, char *id, int checkF){
    //reserva
    if(check_if_reserv_flight_or_user(id) == 1){
        Reservations *resr = find_reservation(id, get_reservation_table(hashTable));
        
        char *resrId = get_reservation_id(resr);
        unsigned int resrPPN = get_price_per_night(resr);
        char *resrBeginDate = get_begin_date(resr);
        char *resrEndDate = get_end_date(resr);
        unsigned int resrTax = get_tax(resr);
        char *resrHotelId = get_hotel_id(resr);
        char *resrHotelName = get_hotel_name(resr);
        unsigned int resrStars = get_stars(resr);
        char *resrBreak =get_breakfast(resr);
        
        if(resr != NULL){
        int num_noites = days_time(resrBeginDate, resrEndDate);
        double total_price = reserve_cost(resrPPN, num_noites, resrTax);
        int has_breakfast = correct_breakfast(resrBreak);

        char *fileINT = NULL;
        if(inter == 1) fileINT = create_file_INT();
        
        if(has_breakfast) output_to_file_1R(resrHotelId, resrHotelName, resrStars, resrBeginDate, resrEndDate, "True", num_noites, total_price, checkF);
        else output_to_file_1R(resrHotelId, resrHotelName, resrStars, resrBeginDate, resrEndDate, "False", num_noites, total_price, checkF);

        if(inter == 1) Windows(), remove(fileINT);
        if (fileINT){
        free(fileINT);
        fileINT = NULL;
        }

        } else if (resr == NULL){
        output_to_file_1R(resrHotelId, resrHotelName, resrStars, resrBeginDate, resrEndDate, NULL, -1, -1, checkF); //days_time retorna -1 se begin ou end date for null    
        }

        free(resrId);
        resrId = NULL;
        free(resrBeginDate);
        resrBeginDate = NULL;
        free(resrEndDate);
        resrEndDate = NULL;
        free(resrHotelId);
        resrHotelId = NULL;
        free(resrHotelName);
        resrHotelName = NULL;
        free(resrBreak);
        resrBreak = NULL;
    }


    //flight
    else if(check_if_reserv_flight_or_user(id) == 2){
        Flights *resf = find_flight(id, get_flight_table(hashTable));
        
        char *resfArr = get_arr(resf);
        char *resfRarr = get_rarr(resf);
        char *resfAirline = get_airline(resf);
        char *resfModel = get_model(resf);
        char *resfOrigem = get_origem(resf);
        char *resfDestino = get_destino(resf);
        char *resfDep = get_dep(resf);
        char *resfRDep = get_rdep(resf);

        if(resf != NULL){
            int num_passageiros = get_passenger_node_occupied(get_passenger_node(get_passenger_table(hashTable), atoi(id)));
            int tempo_atraso = calculate_tempo_atraso(resfDep, resfRDep);

            char *fileINT = NULL;
            if(inter == 1) fileINT = create_file_INT();

           output_to_file_1F(resfAirline, resfModel, resfOrigem, resfDestino, resfDep, resfArr, num_passageiros, tempo_atraso, checkF);

           if(inter == 1) Windows(), remove(fileINT);
           if (fileINT){
           free(fileINT);
           fileINT = NULL;
           }

        } else if(resf == NULL){
           output_to_file_1F(resfAirline, resfModel, resfOrigem, resfDestino, resfDep, resfArr, -1, -1, checkF);
        }


        free(resfArr);
        resfArr = NULL;
        free(resfRarr);
        resfRarr = NULL;
        free(resfAirline);
        resfAirline = NULL;
        free(resfModel);
        resfModel = NULL;
        free(resfOrigem);
        resfOrigem = NULL;
        free(resfDestino);
        resfDestino = NULL;
        free(resfDep);
        resfDep = NULL;
        free(resfRDep);
        resfRDep = NULL;
    } 


    //user
    else if(check_if_reserv_flight_or_user(id) == 3){
        Users *resu = find_user(id, get_user_table(hashTable));
        
        char *resuName = get_user_name(resu);
        char resuSex = get_user_sex(resu);
        char *resuCountry = get_user_country_code(resu);
        char *resuBirth = get_user_birth_date(resu);
        char *resuPassport = get_user_passport(resu);
        char *resuStatus = get_user_status(resu);
        int verificaActive = 0;

        if(resu != NULL){
        verificaActive = check_active(resuStatus);
        }

        if(resu != NULL && verificaActive == 1){
            int age = calculate_age(resuBirth);
            int num_flights = get_current_user_flight(resu);
            double values[2];
            calculate_NumAndPrice_Reservations(resu, values);
            int num_reservations = (int) values[0];
            double total_spent = values[1];

            char *fileINT = NULL;
            if(inter == 1) fileINT = create_file_INT();

            output_to_file_1U(resuName, resuSex, age, resuCountry, resuPassport, num_flights, num_reservations, total_spent, checkF);

            if(inter == 1) Windows(), remove(fileINT);
            if (fileINT){
            free(fileINT);
            fileINT = NULL;
            }

        } else if (resu == NULL || verificaActive != 1){
            output_to_file_1U(resuName, resuSex, -1, resuCountry, resuPassport, -1, -1, -1, checkF);
        }

        free(resuName);
        resuName = NULL;
        free(resuCountry);
        resuCountry = NULL;
        free(resuBirth);
        resuBirth = NULL;
        free(resuPassport);
        resuPassport = NULL;
        free(resuStatus);
        resuStatus = NULL;
    }

}

//query2
void query2 (const HashTable *hashTable, char *id, char *type, int checkF) {
    //output_to_file_rip();
    //return;
    int flag = check_type(type);

    Users *user = find_user(id, get_user_table(hashTable));
    char *userStatus = get_user_status(user);

    if(user == NULL || check_active(userStatus) != 1){
        char *filenamequery2 = NULL;
        if (inter != 1) filenamequery2 = create_file();
        output_to_file_2(NULL, NULL, NULL, checkF, 0, filenamequery2);
        free(userStatus);
        userStatus = NULL;
        if (filenamequery2 != NULL){
            free(filenamequery2);
            filenamequery2 = NULL;
        }
        return;
    }

    free(userStatus);
    userStatus = NULL;
    
    if(flag == 1){
        Flights **flights = get_user_flights(user);
        int flightSize = get_current_user_flight(user);

        Flights **flights_list = malloc(sizeof(Flights *) * flightSize);
        for(int i = 0; i < flightSize; i++) {
            char *currentID = get_flight_id(flights[i]);
            char *date = get_dep(flights[i]);

            flights_list[i] = new_flight();
            set_F_flight_id(flights_list[i], currentID);
            set_F_dep(flights_list[i], date);

            free(currentID);
            currentID = NULL;
            free(date);
            date = NULL;
        }

        flight_sort(flights_list, 0, flightSize - 1);

        char *filenamequery2 = NULL;
        if (inter != 1) filenamequery2 = create_file();
        else if (inter == 1) filenamequery2 = create_file_INT();

        for(int siu = 0; siu < flightSize;){
            char *currentID = get_flight_id(flights_list[siu]);
            char *date = get_dep(flights_list[siu]);
            char short_dep[11];
            if (date) {
                strncpy(short_dep, date, 10);
                short_dep[10] = '\0';
            }

            siu++;
            output_to_file_2(currentID, short_dep, NULL, checkF, siu, filenamequery2);
            free(date);
            date = NULL;
            free(currentID);
            currentID = NULL;
        }
        if(inter == 1) Windows(), remove(filenamequery2);
        if (filenamequery2 != NULL){
            free(filenamequery2);
            filenamequery2 = NULL;
        }
        
        for(int i = 0; i < flightSize; i++) free_flight(flights_list[i]);
        free(flights_list);

    } else if(flag == 2){
        Reservations **reservations = get_user_reservations(user);
        int reservationSize = get_current_user_reservation(user);

        Reservations **reservations_list = malloc(sizeof(Reservations *) * reservationSize);

        for(int i = 0; i < reservationSize; i++) {
            char *currentID = get_reservation_id(reservations[i]);
            char *date = get_begin_date(reservations[i]);

            reservations_list[i] = new_reservation();
            set_R_reservation_id(reservations_list[i], currentID);
            set_R_begin_date(reservations_list[i], date);

            free(currentID);
            currentID = NULL;
            free(date);
            date = NULL;
        }

        reservation_sort(reservations_list, 0, reservationSize - 1);

        char *filenamequery2 = NULL;
        if (inter != 1) filenamequery2 = create_file();
        else if (inter == 1) filenamequery2 = create_file_INT();

        for(int siu = 0; siu < reservationSize;){
            char *currentID = get_reservation_id(reservations_list[siu]);
            char *date = get_begin_date(reservations_list[siu]);

            siu++;
            output_to_file_2(currentID, date, NULL, checkF, siu, filenamequery2);
            free(date);
            date = NULL;
            free(currentID);
            currentID = NULL;
        }
        if(inter == 1) Windows(), remove(filenamequery2);
        if (filenamequery2 != NULL){
            free(filenamequery2);
            filenamequery2 = NULL;
        }
        for(int i = 0; i < reservationSize; i++) free_reservation(reservations_list[i]);
        free(reservations_list);

    } else {
        //output_to_file_rip();
        //return;
        Reservations **reservations = get_user_reservations(user);
        int reservationSize = get_current_user_reservation(user);

        Reservations **reservations_list = malloc(sizeof(Reservations *) * reservationSize);

        for(int i = 0; i < reservationSize; i++) {
            char *currentID = get_reservation_id(reservations[i]);
            char *date = get_begin_date(reservations[i]);

            reservations_list[i] = new_reservation();
            set_R_reservation_id(reservations_list[i], currentID);
            set_R_begin_date(reservations_list[i], date);

            free(currentID);
            currentID = NULL;
            free(date);
            date = NULL;
        }

        reservation_sort(reservations_list, 0, reservationSize - 1);

        Flights **flights = get_user_flights(user);
        int flightSize = get_current_user_flight(user);

        Flights **flights_list = malloc(sizeof(Flights *) * flightSize);
        for(int i = 0; i < flightSize; i++) {
            char *currentID = get_flight_id(flights[i]);
            char *date = get_dep(flights[i]);

            flights_list[i] = new_flight();
            set_F_flight_id(flights_list[i], currentID);
            set_F_dep(flights_list[i], date);

            free(currentID);
            currentID = NULL;
            free(date);
            date = NULL;
        }

        flight_sort(flights_list, 0, flightSize - 1);


        char *filenamequery2 = NULL;
        if (inter != 1) filenamequery2 = create_file();
        else if (inter == 1) filenamequery2 = create_file_INT();

        for(int siu = 0,numF = 0,numR = 0; siu < reservationSize + flightSize;){
            siu++;

            if(numF < flightSize && numR < reservationSize){
                char *currentFID = get_flight_id(flights_list[numF]);
                char *dateF = get_dep(flights_list[numF]);
                char *currentRID = get_reservation_id(reservations_list[numR]);
                char *dateR = get_begin_date(reservations_list[numR]);

                if (days_time_all(dateR, dateF) >= 0) { 
                    char short_dep[11];
                    strncpy(short_dep, dateF, 10);
                    short_dep[10] = '\0';
                    output_to_file_2(currentFID, short_dep, "flight", checkF, siu, filenamequery2);
                    numF++;
                } else {
                    output_to_file_2(currentRID, dateR, "reservation", checkF, siu, filenamequery2);
                    numR++;
                }

                free(dateR);
                dateR = NULL;
                free(currentRID);
                currentRID = NULL;
                free(dateF);
                dateF = NULL;
                free(currentFID);
                currentFID = NULL;
            } else if(numF < flightSize){
                char *currentFID = get_flight_id(flights_list[numF]);
                char *dateF = get_dep(flights_list[numF]);
                char short_dep[11];
                strncpy(short_dep, dateF, 10);
                short_dep[10] = '\0';
                
                output_to_file_2(currentFID, short_dep, "flight", checkF, siu, filenamequery2);
                numF++;

                free(dateF);
                dateF = NULL;
                free(currentFID);
                currentFID = NULL;
            } else if(numR < reservationSize){
                char *currentRID = get_reservation_id(reservations_list[numR]);
                char *dateR = get_begin_date(reservations_list[numR]);

                output_to_file_2(currentRID, dateR, "reservation", checkF, siu, filenamequery2);
                numR++;
                

                free(dateR);
                dateR = NULL;
                free(currentRID);
                currentRID = NULL;
            }
        }

        if(inter == 1) Windows(), remove(filenamequery2);
        if (filenamequery2 != NULL){
            free(filenamequery2);
            filenamequery2 = NULL;
        }

        for(int i = 0; i < flightSize; i++) free_flight(flights_list[i]);
        free(flights_list);

        for(int i = 0; i < reservationSize; i++) free_reservation(reservations_list[i]);
        free(reservations_list);
    }
    
    free(userStatus);
    userStatus = NULL;
}

//query3
void query3 (const HashTable *hashTable, char *id, int checkF){
    //output_to_file_rip();
    //return;
    double average = hotel_average_rating(hashTable, id);

    char *fileINT = NULL;
    if(inter == 1 && average != -1) fileINT = create_file_INT();

    output_to_file_3(average, checkF);

    if(inter == 1 && average != -1) Windows(), remove(fileINT);
    if (fileINT){
        free(fileINT);
        fileINT = NULL;
    }
}

//query4
void query4 (const HashTable *hashTable, char *id, int checkF){
    //output_to_file_rip();
    //return;
    ReservationNode *reservationNode = get_reservation_node(get_reservation_table(hashTable), atoi(id + 3));
    char *filenamequery4 = NULL;
    if (inter != 1) filenamequery4 = create_file();
    else if (inter == 1) filenamequery4 = create_file_INT();

    if(reservationNode == NULL){
        output_to_file_4(NULL, NULL, NULL, NULL, -1, -1, checkF, filenamequery4, -1);
        if (filenamequery4){
            free(filenamequery4);
            filenamequery4 = NULL;
        }
       return;
    }

    Reservations **reservations = get_all_reservations(reservationNode);
    int reservSize = get_reservation_node_occupied(reservationNode);

    Reservations **list = malloc(sizeof(Reservations *) * reservSize);

    for(int i = 0; i < reservSize; i++) {
        char *beginDate = get_begin_date(reservations[i]);
        char *endDate = get_end_date(reservations[i]);
        char *userID = get_reserv_user_id(reservations[i]);
        unsigned int rating = get_rating(reservations[i]);
        char *reservationId = get_reservation_id(reservations[i]);
        unsigned int PPN = get_price_per_night(reservations[i]);
        unsigned int tax = get_tax(reservations[i]);

        list[i] = new_reservation();
        set_R_begin_date(list[i], beginDate);
        set_R_end_date(list[i], endDate);
        set_R_user_id(list[i], userID);
        set_R_rating(list[i], rating);
        set_R_reservation_id(list[i], reservationId);
        set_R_price_per_night(list[i], PPN);
        set_R_tax(list[i], tax);

        free(beginDate);
        beginDate = NULL;
        free(endDate);
        endDate = NULL;
        free(userID);
        userID = NULL;
        free(reservationId);
        reservationId = NULL;
    }

    reservation_sort(list, 0, reservSize - 1);

    for(int siu = 0; siu < reservSize;){
        char *beginDate = get_begin_date(list[siu]);
        char *endDate = get_end_date(list[siu]);
        char *userID = get_reserv_user_id(list[siu]);
        unsigned int rating = get_rating(list[siu]);
        char *reservationId = get_reservation_id(list[siu]);
        unsigned int PPN = get_price_per_night(list[siu]);
        unsigned int tax = get_tax(list[siu]);
        double total_price = reserve_cost(PPN, days_time(beginDate, endDate), tax); 
            
        siu++;
        output_to_file_4(reservationId, beginDate, endDate, userID, rating, total_price, checkF, filenamequery4, siu);

        free(beginDate);
        beginDate = NULL;
        free(endDate);
        endDate = NULL;
        free(userID);
        userID = NULL;
        free(reservationId);
        reservationId = NULL;
    }

    for(int i = 0; i < reservSize; i++) free_reservation(list[i]);
    free(list);
    
    if(inter == 1 && coisa == 1) Windows(), remove(filenamequery4);
    if (filenamequery4){
        free(filenamequery4);
        filenamequery4 = NULL;
    }
}

//query5
void query5 (const HashTable *hashTable, char *flight_origin, char *begin_date, char *end_date, int checkF){
    //output_to_file_rip();
    //return;
    Flights **list = find_flights_by_origin_and_date(hashTable, flight_origin, begin_date, end_date);
    int size = 0;
    for(;list[size];size++);
    flight_sort(list,0,size - 1);
    
    char *filenamequery5 = NULL;
    if (inter != 1) filenamequery5 = create_file();
    else if (inter == 1) filenamequery5 = create_file_INT();

    if (size == 0){
     FILE *file = fopen(filenamequery5, "a");
     fclose(file);
    }

    for(int siu = 0; siu < size;){
        char *flightId = get_flight_id(list[siu]);
        char *depDate = get_dep(list[siu]);
        char *destino = get_destino(list[siu]);
        char *airline = get_airline(list[siu]);
        char *planeModel = get_model(list[siu]);
        
        siu++;
        output_to_file_5(flightId, depDate, destino, airline, planeModel, checkF, filenamequery5, siu);
        free(flightId);
        flightId = NULL;
        free(depDate);
        depDate = NULL;
        free(destino);
        destino = NULL;
        free(airline);
        airline = NULL;
        free(planeModel);   
        planeModel = NULL;     
    }
    if(inter == 1 && coisa == 1) Windows(), remove(filenamequery5);
    if (filenamequery5){
        free(filenamequery5);
        filenamequery5 = NULL;
    }
    free(list);
}

//query6
void query6 (const HashTable *hashTable, char *year, int M, int checkF){

    // Encontrar todos os voos com a data estimada de partida no ano
    char *filenamequery6 = NULL;
    if(M > 0){
        int currentOrigin = 0;
        int sizeOrigins = 100;
        char *origins = (char *)malloc(sizeOrigins * sizeof(char));
        memset(origins, '\0', sizeOrigins * sizeof(char));

        int currentAirport = 0;
        int max_airports = 33;
        int *total_passengers = malloc(max_airports * sizeof(int));
        for(int j = 0; j < max_airports; j++) total_passengers[j] = 0;

        FlightsTable *flightsTable = get_flight_table(hashTable);
        int size = get_flight_table_size(flightsTable);
        for(int i = 0; i < size; i++){
            // Percorrer a lista encadeada correspondente até encontrar o aeroporto com o nome correspondente
            Flights* current = get_flight_node(flightsTable, i);

            while (current != NULL) {
                char *depDate = get_dep(current);

                if(strncmp(depDate, year, 4) == 0){
                    
                    if(currentAirport >= max_airports - 1){
                        sizeOrigins += 30;
                        origins = realloc(origins, sizeOrigins * sizeof(char));
                        memset(origins + currentOrigin, '\0', 30 * sizeof(char));

                        max_airports += 10;
                        total_passengers = realloc(total_passengers, max_airports * sizeof(int));
                        for(int j = currentAirport; j < max_airports; j++) total_passengers[j] = 0;
                    }

                    char *origem = get_origem(current);
                    char *destino = get_destino(current);
                
                    int currentOrigem = current_aeroporto(origins, origem);
                    int currentDestino = current_aeroporto(origins, destino);

                    if(currentOrigem == -1) {
                        new_airport(origins, origem);
                        currentOrigem = currentAirport;
                        currentAirport++;
                        currentOrigin += 3;
                    }

                    if(currentDestino == -1) {
                        new_airport(origins, destino);
                        currentDestino = currentAirport;
                        currentAirport++;
                        currentOrigin += 3;
                    }
                
                    char *flightId = get_flight_id(current);
                    int passengers = get_passenger_node_occupied(get_passenger_node(get_passenger_table(hashTable), atoi(flightId)));
                    total_passengers[currentOrigem] += passengers;
                    total_passengers[currentDestino] += passengers;
                    
                    free(origem);
                    origem = NULL;
                    free(destino);
                    destino = NULL;
                    free(flightId);
                    flightId = NULL;

                }
                free(depDate);
                depDate = NULL;
                current = get_next_flight(current);
            }
        }
        if (inter != 1) filenamequery6 = create_file();
        else if (inter == 1) filenamequery6 = create_file_INT();
        
        sort_arrays(origins, total_passengers, 0, currentAirport - 1);

        for(int siu = 0; siu < currentAirport && siu < M; siu++){
            char *aux = get_current_airport(origins + 3*siu);
            output_to_file_6(aux, total_passengers[siu], checkF, filenamequery6, siu+1);
            free(aux);
            aux = NULL;
        }
        free(origins);
        origins = NULL;
        free(total_passengers);
    } else{
        if (inter != 1) filenamequery6 = create_file();
        else if (inter == 1) filenamequery6 = create_file_INT();
        output_to_file_6(NULL, 0, 0, filenamequery6, 0);
    }
    if(inter == 1 && coisa == 1) Windows(), remove(filenamequery6);

    if (filenamequery6){
        free(filenamequery6);
        filenamequery6 = NULL;
    }
}

//query7
void query7 (const HashTable *hashTable, int M, int checkF){

    // Encontrar todos os voos com a data estimada de partida no ano
    int currentOrigin = 0;
    int sizeOrigins = 100;
    char *origins = (char *)malloc(sizeOrigins * sizeof(char));
    memset(origins, '\0', sizeOrigins * sizeof(char));

    int currentAirport = 0;
    int max_airports = 33;
    double *mediana_atrasos = malloc(max_airports * sizeof(double));
    for(int j = 0; j < max_airports; j++) mediana_atrasos[j] = 0;

    TotalAtrasos **totalAtrasos = malloc(max_airports * sizeof(TotalAtrasos *));
    for(int j = 0; j < max_airports; j++) totalAtrasos[j] = new_atraso();

    FlightsTable *flightsTable = get_flight_table(hashTable);
    int size = get_flight_table_size(flightsTable);
    for(int i = 0; i < size; i++){
        // Percorrer a lista encadeada correspondente até encontrar o aeroporto com o nome correspondente
        Flights* current = get_flight_node(flightsTable, i);

        while (current != NULL) {
            if(currentAirport == max_airports){
                sizeOrigins += 30;
                origins = realloc(origins, sizeOrigins * sizeof(char));
                memset(origins + currentOrigin, '\0', 30 * sizeof(char));

                max_airports += 10;
                mediana_atrasos = realloc(mediana_atrasos, max_airports * sizeof(double));
                for(int j = currentAirport; j < max_airports; j++) mediana_atrasos[j] = 0;

                totalAtrasos = realloc(totalAtrasos, max_airports * sizeof(TotalAtrasos *));
                for(int j = currentAirport; j < max_airports; j++) totalAtrasos[j] = new_atraso();
            }

            char *origem = get_origem(current);
            char *origem_dep = get_dep(current);
            char *origem_rdep = get_rdep(current);

            int currentOrigem = current_aeroporto(origins, origem);
            if(currentOrigem == -1) {
                    new_airport(origins, origem);
                    currentOrigem = currentAirport;
                    currentAirport++;
                    currentOrigin++;
                }
            int atraso = calculate_tempo_atraso(origem_dep, origem_rdep);
            
            set_atraso(totalAtrasos[currentOrigem], atraso);

            free(origem);
            origem = NULL;
            free(origem_dep);
            origem_dep = NULL;
            free(origem_rdep);
            origem_rdep = NULL;

            current = get_next_flight(current);
        }
    }
    char *filenamequery7 = NULL;
    if (inter != 1/* && uno != 1*/) filenamequery7 = create_file();
    else if (inter == 1/* && uno != 1*/) filenamequery7 = create_file_INT();
    
    for(int j = 0; j < currentAirport; j++) {
        int *aux = get_atrasos(totalAtrasos[j]);
        int count = get_current(totalAtrasos[j]);

        sort_int_array(aux, 0, count - 1);

        // Calcula a mediana com base no número par ou ímpar de elementos
        if (count % 2 == 1) {
            // Ímpar: mediana é o elemento do meio
            mediana_atrasos[j] = (double)aux[count / 2];
        } else if (count > 0) {
            // Par: mediana é a média dos dois elementos do meio
            mediana_atrasos[j] = (double)(aux[count / 2 - 1] + aux[count / 2]) / 2;
        } else {
            // Sem atrasos: mediana é zero
            mediana_atrasos[j] = 0.0;
        }
    }

    sort_arrays_double(origins, mediana_atrasos, 0, currentAirport - 1);

    if(/*uno != */1){ //1ª vez dataset pequeno dá mal??
    for(int siu = 0; siu < currentAirport && siu < M; siu++){
        char *aux = get_current_airport(origins + 3*siu);
        output_to_file_7(aux, mediana_atrasos[siu], checkF, filenamequery7, siu+1);
        free(aux);
        aux = NULL;
    }
    if(inter == 1 && coisa == 1) Windows(), remove(filenamequery7);
    }

    for(int i = 0; i < max_airports; i++) {
        free_atrasos(totalAtrasos[i]);
    }
    free(totalAtrasos);
    free(mediana_atrasos);
    free(origins);
    origins = NULL;
    free(filenamequery7);
    filenamequery7 = NULL;
}

//query8
void query8 (const HashTable *hashTable, char *id, char *begin_date, char *end_date, int checkF){
    //output_to_file_rip();
    //return;
    int totalRevenue = hotel_revenue(hashTable, id, begin_date, end_date);

    char *fileINT = NULL;
    if(inter == 1 && totalRevenue != -1) fileINT = create_file_INT();

    output_to_file_8(totalRevenue, checkF);

    if(inter == 1 && totalRevenue != -1) Windows(), remove(fileINT);
    if (fileINT){
        free(fileINT);
        fileINT = NULL;
    }
}

void query9 (const HashTable *hashTable, char *prefix, int checkF){
    //output_to_file_rip();
    //return;
    //sort na list
    Users **list = find_users_by_prefix(hashTable, prefix);
    int userSize = 0;
    for(;list[userSize]; userSize++);
    if(userSize == 0){
        free(list);
        list = NULL;
        
        if (inter != 1) output_to_file_9_2();
        return;
    }
    
    user_sort(list,0,userSize - 1);

    char *filenamequery9 = NULL;
    char *fileINT = NULL;
    if (inter != 1) filenamequery9 = create_file();
    else if (inter == 1) fileINT = create_file_INT();

    for(int siu = 0; siu < userSize;){
        char *tempName = get_user_name(list[siu]);
        char *tempId = get_user_id(list[siu]);
        
        siu++;
        if (inter != 1) output_to_file_9(tempName, tempId, checkF, filenamequery9, siu);
        else if (inter == 1) output_to_file_9(tempName, tempId, checkF, fileINT, siu);
        free(tempName);
        tempName = NULL;
        free(tempId);
        tempId = NULL;  
    }
    if(inter == 1) Windows(), remove(fileINT);

    if (filenamequery9){
        free(filenamequery9);
        filenamequery9 = NULL;
    }
    if (fileINT){
        free(fileINT);
        fileINT = NULL;
    }
    free(list);
}

void query10(const HashTable *hashTable, char *year, char *month, int checkF) {
    //output_to_file_rip();
    //return;
    int siu = 0;

    char *filenamequery10 = NULL;
    if (inter != 1) filenamequery10 = create_file();
    else if (inter == 1) filenamequery10 = create_file_INT();

    if(month == NULL && year == NULL){
        //output_to_file_rip();
       //return;
        int ano = first_year_with_users(hashTable);
        int total_years = 2023 - ano + 1;
        int user[total_years];
        for(int i = 0; i < total_years; i++) user[i] = 0;
        
        int reserv[total_years];
        for(int i = 0; i < total_years; i++) reserv[i] = 0;
        
        Metrics **metrics = malloc(total_years * sizeof(Metrics *));
        for(int i = 0; i < total_years; i++) metrics[i] = new_metric();
        
        all_metrics(hashTable, ano, -1, -1, metrics, user, reserv);

        int first_year = ano;
        while(ano <= 2023){
            siu++;
            output_to_file_10(0, ano, user[ano - first_year], get_voos(metrics[ano - first_year]), get_total_passengers(metrics[ano - first_year]), get_new_passengers(metrics[ano - first_year]), reserv[ano - first_year], checkF, filenamequery10, siu);
            ano++;
        }

        for(int i = 0; i < total_years; i++) free_metric(metrics[i]);
        free(metrics);

    } else if(month == NULL){
        int mes = 1, ano = atoi(year);
        int user[12];
        for(int i = 0; i < 12; i++) user[i] = 0;
        
        int reserv[12];
        for(int i = 0; i < 12; i++) reserv[i] = 0;
        
        Metrics **metrics = malloc(12 * sizeof(Metrics *));
        for(int i = 0; i < 12; i++) metrics[i] = new_metric();
        
        all_metrics(hashTable, ano, 1, -1, metrics, user, reserv);
        
        while(mes <= 12){
            if(get_voos(metrics[mes - 1]) == 0 && reserv[mes - 1] == 0 && user[mes - 1] == 0){
                mes++;
                continue;
            }
            siu++;
            output_to_file_10(1, mes, user[mes - 1], get_voos(metrics[mes - 1]), get_total_passengers(metrics[mes - 1]), get_new_passengers(metrics[mes - 1]), reserv[mes - 1], checkF, filenamequery10, siu);
            mes++;
        }

        for(int i = 0; i < 12; i++) free_metric(metrics[i]);
        free(metrics);

    } else{
        //output_to_file_rip();
        //return;
        int dia = 1, ano = atoi(year), mes = atoi(month);
        int user[31];
        for(int i = 0; i < 31; i++) user[i] = 0;
        
        int reserv[31];
        for(int i = 0; i < 31; i++) reserv[i] = 0;
        
        Metrics **metrics = malloc(31 * sizeof(Metrics *));
        for(int i = 0; i < 31; i++) metrics[i] = new_metric();
        
        all_metrics(hashTable, ano, mes, 1, metrics, user, reserv);
        
        while(dia <= 31){
            if(get_voos(metrics[dia - 1]) == 0 && reserv[dia - 1] == 0 && user[dia - 1] == 0){
                dia++;
                continue;
            }
            siu++;
            output_to_file_10(2, dia, user[dia - 1], get_voos(metrics[dia - 1]), get_total_passengers(metrics[dia - 1]), get_new_passengers(metrics[dia - 1]), reserv[dia - 1], checkF, filenamequery10, siu);
            dia++;
        }
        for(int i = 0; i < 31; i++) free_metric(metrics[i]);
        free(metrics);
    } 
    if(inter == 1 && coisa == 1) Windows(), remove(filenamequery10);
    free(filenamequery10);
    filenamequery10 = NULL;
}