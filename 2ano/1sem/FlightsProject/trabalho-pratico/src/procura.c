#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/procura.h"
#include "../include/DataStore.h"
#include "../include/time.h"
#include "../include/flights.h"
#include "../include/statistics.h"

//Encontrar os voos por origem e data
Flights **find_flights_by_origin_and_date (const HashTable *hashTable, char *flight_origin, char *entry_date, char *final_date) {
    // Calcular o índice do array usando a função de hash
    int maxF = get_flight_table_size(get_flight_table(hashTable));
    Flights **sameOrigin = malloc(sizeof(Flights *) * maxF);
    for(int i = 0; i < maxF; i++)sameOrigin[i] = NULL;
    int currentOrigin = 0;
    
    FlightsTable *flightsTable = get_flight_table(hashTable);
    int size = get_flight_table_size(flightsTable);
    for(int i = 0; i < size; i++){
        // Percorrer a lista encadeada correspondente até encontrar o aeroporto com o nome correspondente
        Flights* current = get_flight_node(flightsTable, i);

        
        while (current != NULL) {
            char *origem = get_origem(current);
            char *departure_date = get_dep(current);
            if (strcmp(origem, flight_origin) == 0 && seconds_time_all(entry_date, departure_date) >= 0 && seconds_time_all(departure_date, final_date)>= 0) {
                sameOrigin[currentOrigin] = current;
                currentOrigin++;           
            }
            current = get_next_flight(current);
            free(origem);
            origem = NULL;
            free(departure_date);
            departure_date = NULL;
        }
    }
    return sameOrigin;
}

// Função auxiliar para encontrar usuários por prefixo
Users **find_users_by_prefix(const HashTable *hashTable, char *prefix) {
    int maxU = 1024;
    Users **head = malloc(sizeof(Users *) * maxU);
    for(int i = 0; i < maxU; i++)head[i] = NULL;
    int currentUser = 0;

    UsersTable *usersTable = get_user_table(hashTable);
    int size = get_user_table_occupied(usersTable);
    for (int prekey = 0; prekey < size; prekey++) {
        Users **user_list = get_first_user(get_user_node(usersTable, prekey));
        int userSize = get_user_node_occupied(get_user_node(usersTable, prekey));
        for(int i = 0; i < userSize; i++){
            Users *user = user_list[i];
            char *currentName = get_user_name(user);
            char *currentStatus = get_user_status(user);

            // Verifica se o nome do usuário começa com o prefixo
            if (strncmp(currentName, prefix, strlen(prefix)) == 0 && check_active(currentStatus) == 1) {

                if(currentUser == maxU){
                    maxU *= 2;
                    head = realloc(head, sizeof(Users *) * maxU);
                    for(int i = maxU/2; i < maxU; i++)head[i] = NULL;
                }

                head[currentUser] = user;
                currentUser++;
            }

            free(currentName);
            currentName = NULL;
            free(currentStatus);
            currentStatus = NULL;
        }
    }

    return head;
}