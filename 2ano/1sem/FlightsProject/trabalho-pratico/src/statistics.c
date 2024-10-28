#include "../include/DataStore.h"
#include "../include/statistics.h"
#include "../include/flights.h"
#include "../include/users.h"
#include "../include/reservations.h"
#include "../include/passengers.h"
#include "../include/queries.h"
#include "ctype.h"

static int is_number(char x){
    if(x >= '0' && x <= '9') return 1;
    return 0;
}

int are_numbers(char *num){
    for(int i = 0; num[i]; i++) if(!is_number(num[i])) return 0;
    return 1;
}

int check_email(char *email){
    int username = 0;
    for(; email[username] != '@' && email[username]; username++);
    if(username < 1 || email[username] == '\0') return 0;
    int format = username + 1;

    for(; email[format] != '.' && email[format]; format++);
    if(format - username < 2 || email[format] == '\0') return 0;
    int domain = format + 1;

    for(; email[domain]; domain++);
    if(domain - format < 3) return 0;

    return 1;
}

int check_country_code(char *code){
    int i = 0;
    for(; code[i] && isalpha(code[i]); i++);
    if(i == 2) return 1;
    return 0;
}

int check_origem_destino(char *code){
    int i = 0;
    for(; code[i]; i++);
    if(i == 3) return 1;
    return 0;
}

int check_account_status(char *line){
    if(line == NULL) return 0;
    char * aux = strdup(line);
    if(aux == NULL) return -1;
    if(tolower(aux[0]) == 'a' || tolower(aux[0]) == 'i'){
        for(int i = 0; i < strlen(aux); i++){
            aux[i] = tolower(aux[i]);
        }
    }
    if(strcmp(aux,"active") == 0 || strcmp(aux,"inactive") == 0){
        free(aux);
        return 1;
    }
    free(aux);
    return 0;
}

int check_airports(char *origem, char *dest) {
    int i = 0;
    for (; origem[i] && dest[i] && origem[i] == dest[i]; i++);
    if (origem[i] || dest[i]) {
        return 0;
    }
    return 1;
}

int check_hotel_stars(char *star){
    if(star[0] >= '1' && star[0] <= '5' && !star[1]) return 1;
    return 0;
}

int check_city_tax(char *tax){
    int i = 0;
    for(; tax[i] >= '0' && tax[i] <= '9' && tax[i]; i++);
    if(tax[i]) return 0;
    return 1;
}

int check_price_per_night(char *price){
    int i = 0;
    for(; price[i] >= '0' && price[i] <= '9'; i++);
    if(price[i]) return 0;
    return 1;
}

int check_includes_breakfast(char *line){
    if(line == NULL) return 1;
    char * aux = strdup(line);
    if(aux == NULL) return -1;
    if(strcmp(aux,"1") == 0 || strcmp(aux,"0") == 0){
        free(aux);
        return 1;
    }

    if(tolower(aux[0]) == 't' || tolower(aux[0]) == 'f'){
        for(int i = 0; i < strlen(aux); i++){
            aux[i] = tolower(aux[i]);
        }
    }
    if(strcmp(aux,"true") == 0 || strcmp(aux,"false") == 0 || strcmp(aux,"t") == 0 || strcmp(aux,"f") == 0){
        free(aux);
        return 1;
    }
    free(aux);
    return 0;
}

int check_hotel_rating(char *rating) {
    if (!rating[0] || (rating[0] >= '1' && rating[0] <= '5' && !rating[1])) {
        return 1;
    }
    return 0;
}

void make_upper(char *doIt){
    for(int i = 0; i < strlen(doIt); i++){
        doIt[i] = toupper(doIt[i]);
    }
}

int is_within_range(int num, int min, int max){
    return (num >= min && num <= max);
}

int check_date_format2(char *date){
    int year, month, day;
    if(sscanf(date, "%d/%d/%d", &year, &month, &day) != 3) return 0;
    if(date[4] != '/' || date[7] != '/') return 0;
    if(!is_within_range(year, 1, 9999)) return 0;
    if(!is_within_range(month, 1, 12)) return 0;
    if(!is_within_range(day, 1, 31)) return 0;
    return 1;
}

int is_date_correct(char *date_str){
    return check_date_format2(date_str);
}

int check_time_format(char *time_str){
    int hour, minute, second;
    int year, month, day;
    if(sscanf(time_str, "%d/%d/%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second) != 6) return 0;
    if(time_str[4] != '/' || time_str[7] != '/' || time_str[10] != ' ' || time_str[13] != ':' || time_str[16] != ':') return 0;
    if(!is_within_range(year, 1, 9999)) return 0;
    if(!is_within_range(month, 1, 12)) return 0;
    if(!is_within_range(day, 1, 31)) return 0; // mudar para 30
    if(!is_within_range(hour, 0, 23)) return 0;
    if(!is_within_range(minute, 0, 59)) return 0;
    if(!is_within_range(second, 0, 59)) return 0;
    return 1;
}

int check_if_reserv_flight_or_user(char *id){

    //reservation
    if(id[0] == 'B' && id[1] == 'o' && id[2] == 'o' && id[3] == 'k' && (isdigit(id[4]) != 0)){ //se id[4] for um digito, retorna um valor diferente de 0
        return 1;
    }


    //flight
    int f = 0;
    int n = strlen(id);
    for(int i = 0; i < n; i++){
        if(isdigit(id[i]) == 0){
            f = 1;
            break;
        }
    }
    if(f == 0)return 2;

    //user
    else if(f == 1)return 3;

    return 0;
}

int correct_breakfast(char *breakfast){
    if(breakfast == NULL || breakfast[0] == '0' || breakfast[0] == 'f') return 0;
    else return 1;
}

int check_active(char *status){
    char * aux = strdup(status);
     for(int i = 0; i < strlen(aux); i++){
        aux[i] = tolower(aux[i]);
     }

    if(strcmp(aux,"active") == 0){
        free(aux);
        aux = NULL;
        return 1;

    } else if(strcmp(aux,"inactive") == 0){
        free(aux);
        aux = NULL;
        return 2;
    }

    return 0;
}

int compara_reservation_id(char *currentId, char *nextId){

    char idcurrent[11], idnext[11];

    idcurrent[10] = '\0';
    idnext[10] = '\0';
    int j = 4, jj = 4;
    for(int i = 0; i < 10; i++) j++, idcurrent[i] = currentId[j];
    for(int i = 0; i < 10; i++) jj++,idnext[i] = nextId[jj];

    return atoi(idcurrent) - atoi(idnext);
}

int check_type(char *type){
    if(type == NULL) return 0;
    else if(strcmp(type, "flights") == 0) return 1;
    else if (strcmp(type, "reservations") == 0) return 2;
    return -1;
}

int airport_already_exists(const Flights *flight, char *origem){
    for(;get_next_flight(flight); flight = get_next_flight(flight)){
        char *flightOrigin = get_origem(flight);
        if(strcmp(flightOrigin, origem) == 0){
            free(flightOrigin);
            flightOrigin = NULL;
            return 1;
        }
        free(flightOrigin);
        flightOrigin = NULL;
    }
    return 0;
}