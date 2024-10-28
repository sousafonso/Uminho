#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <ncurses.h>

#include "../include/output.h"
#include "../include/DataStore.h"

extern int inter;
extern int coisa;

//Variável global para contar ficheiros
int Contaficheiros = 0;

//criar um ficheiro de output
char* create_file(){
  Contaficheiros++;

    //Gerar nome do ficheiro
    char* filename = (char*)malloc(64);
    snprintf(filename, 64, "Resultados/command%d_output.txt", Contaficheiros);

    return filename;
}

char* create_file_INT(){

    char* filename = (char*)malloc(64);
    snprintf(filename, 64, "Resultados/outputINT.txt");

    return filename;
}

//Query1 siu
//output da query1 quando o id é de um user
void output_to_file_1U(char *name, char sex, int age, char *country_code, char *passport, int num_flights, int num_reservations, double total_spent, int checkF) {

   if(inter != 1) Contaficheiros++;

    //Gerar nome do ficheiro
    char filename[64];
    if (inter != 1) snprintf(filename, sizeof(filename), "Resultados/command%d_output.txt", Contaficheiros);
    else if (inter == 1) snprintf(filename, sizeof(filename), "Resultados/outputINT.txt"); //modo interativo no terminal

    FILE *file = fopen(filename, "a");

    if (name != NULL && country_code != NULL && passport != NULL && age != -1){ //é válido

    if (file != NULL) {
        //Escrever informação no ficheiro
      if(checkF == 1){
        coisa = 1;
        fprintf(file, "%s;", name);
        fprintf(file, "%c;", sex);
        fprintf(file, "%d;", age);
        fprintf(file, "%s;", country_code);
        fprintf(file, "%s;", passport);
        fprintf(file, "%d;", num_flights);
        fprintf(file, "%d;", num_reservations);
        fprintf(file, "%.3f\n", total_spent);

      } else if(checkF == 2){
        coisa = 1;
        fprintf(file, "--- 1 ---\n");
        fprintf(file, "name: %s\n", name);
        fprintf(file, "sex: %c\n", sex);
        fprintf(file, "age: %d\n", age);
        fprintf(file, "country_code: %s\n", country_code);
        fprintf(file, "passport: %s\n", passport);
        fprintf(file, "number_of_flights: %d\n", num_flights);
        fprintf(file, "number_of_reservations: %d\n", num_reservations);
        fprintf(file, "total_spent: %.3f\n", total_spent);
      }
   
    }
    }
    fclose(file);
}

//output da query1 quando o id é de um flight
void output_to_file_1F(char *companhia, char *avião, char *origem, char *destino, char *partida_est, char *chegada_est, int num_passageiros, int tempo_atraso, int checkF) {

    if(inter != 1) Contaficheiros++;

    //Gerar nome do ficheiro
    char filename[64];
    if (inter != 1) snprintf(filename, sizeof(filename), "Resultados/command%d_output.txt", Contaficheiros);
    else if (inter == 1) snprintf(filename, sizeof(filename), "Resultados/outputINT.txt"); //modo interativo no terminal

    FILE *file = fopen(filename, "a");

    if (companhia != NULL && avião != NULL && origem != NULL && destino != NULL && partida_est != NULL && chegada_est != NULL && num_passageiros != -1){ //é válido

    if (file != NULL) {
        //Escrever informação no ficheiro
      if(checkF == 1){
        coisa = 1;
        coisa = 1;
        fprintf(file, "%s;", companhia);
        fprintf(file, "%s;", avião);
        fprintf(file, "%s;", origem);
        fprintf(file, "%s;", destino);
        fprintf(file, "%s;", partida_est);
        fprintf(file, "%s;", chegada_est);
        fprintf(file, "%d;", num_passageiros);
        fprintf(file, "%d\n", tempo_atraso);

      } else if(checkF == 2){
        coisa = 1;
        coisa = 1;
        fprintf(file, "--- 1 ---\n");
        fprintf(file, "airline: %s\n", companhia);
        fprintf(file, "plane_model: %s\n", avião);
        fprintf(file, "origin: %s\n", origem);
        fprintf(file, "destination: %s\n", destino);
        fprintf(file, "schedule_departure_date: %s\n", partida_est);
        fprintf(file, "schedule_arrival_date: %s\n", chegada_est);
        fprintf(file, "passengers: %d\n", num_passageiros);
        fprintf(file, "delay: %d\n", tempo_atraso);
      }

    }        
    }
    fclose(file);
}

//output da query1 quando o id é de uma reserva
void output_to_file_1R(char *hotel_id, char *hotel_name, int stars, char *begin_date, char *end_date, char *breakfast, int num_noites, double total_price, int checkF) {

    if(inter != 1) Contaficheiros++;

    //Gerar nome do ficheiro
    char filename[64];
    if (inter != 1) snprintf(filename, sizeof(filename), "Resultados/command%d_output.txt", Contaficheiros);
    else if (inter == 1) snprintf(filename, sizeof(filename), "Resultados/outputINT.txt"); //modo interativo no terminal

    FILE *file = fopen(filename, "a");
    if (hotel_id != NULL && hotel_name != NULL && begin_date != NULL && end_date != NULL && breakfast){ //é válido

    if (file != NULL) {
        //Escrever informação no ficheiro
      if(checkF == 1){
        coisa = 1;
        coisa = 1;
        fprintf(file, "%s;", hotel_id);
        fprintf(file, "%s;", hotel_name);
        fprintf(file, "%d;", stars);
        fprintf(file, "%s;", begin_date);
        fprintf(file, "%s;", end_date);
        fprintf(file, "%s;", breakfast);
        fprintf(file, "%d;", num_noites);
        fprintf(file, "%.3f\n", total_price);

      } else if(checkF == 2){
        coisa = 1;
        coisa = 1;
        fprintf(file, "--- 1 ---\n");
        fprintf(file, "hotel_id: %s\n", hotel_id);
        fprintf(file, "hotel_name: %s\n", hotel_name);
        fprintf(file, "hotel_stars: %d\n", stars);
        fprintf(file, "begin_date: %s\n", begin_date);
        fprintf(file, "end_date: %s\n", end_date);
        fprintf(file, "includes_breakfast: %s\n", breakfast);
        fprintf(file, "nights: %d\n", num_noites);
        fprintf(file, "total_price: %.3f\n", total_price);
      }

    } 
    }
    fclose(file);
}

void output_to_file_2(char *id, char *date, char *type, int checkF, int siu, char *filename){

  if(filename != NULL){

    FILE *file = fopen(filename, "a");

    if (type == NULL && file != NULL && id != NULL && siu != 0) {
      //Escrever informação no ficheiro
      if(checkF == 1){
        coisa = 1;
        fprintf(file, "%s;", id);
        fprintf(file, "%s\n", date);

      } else if(checkF == 2){
        coisa = 1;
        if(siu != 1) fprintf(file, "\n");
        fprintf(file, "--- %d ---\n", siu);
        fprintf(file, "id: %s\n", id);
        fprintf(file, "date: %s\n", date);
      }
    }
    
    //Flights e reservations
    else if (file != NULL && id != NULL && siu != 0) {
        //Escrever informação no ficheiro
      if(checkF == 1){
        coisa = 1;
        fprintf(file, "%s;", id);
        fprintf(file, "%s;", date);
        fprintf(file, "%s\n", type);

      } else if(checkF == 2){
        coisa = 1;
        if(siu != 1) fprintf(file, "\n");
        fprintf(file, "--- %d ---\n", siu);
        fprintf(file, "id: %s\n", id);
        fprintf(file, "date: %s\n", date);
        fprintf(file, "type: %s\n", type); 
      }

        
    }
    fclose(file);
  }
}


//output da query3
void output_to_file_3(double average, int checkF) {
    if(inter != 1) Contaficheiros++;

    //Gerar nome do ficheiro
    char filename[64];
    if (inter != 1) snprintf(filename, sizeof(filename), "Resultados/command%d_output.txt", Contaficheiros);
    else if (inter == 1) snprintf(filename, sizeof(filename), "Resultados/outputINT.txt"); //modo interativo no terminal

    FILE *file = fopen(filename, "a");

    if (file != NULL && average != -1) {
        //Escrever informação no ficheiro
      if(checkF == 1){
        coisa = 1;
        fprintf(file, "%.3f\n", average);

      } else if(checkF == 2){
        coisa = 1;
        fprintf(file, "--- 1 ---\n");
        fprintf(file, "rating: %.3f\n", average);
      }

        
    }
    fclose(file);
}

//escrever o output da query 4
void output_to_file_4(char *reservationId, char *beginDate, char *endDate, char *userID, unsigned int rating, double total_price, int checkF, char *filename, int siu) {

    FILE *file = fopen(filename, "a");
    
    if (file != NULL && reservationId != NULL && userID != NULL && total_price != -1) {
        //Escrever informação no ficheiro
      if(checkF == 1){
        coisa = 1;
        fprintf(file, "%s;", reservationId);
        fprintf(file, "%s;", beginDate);
        fprintf(file, "%s;", endDate);
        fprintf(file, "%s;", userID);
        fprintf(file, "%d;", rating);
        fprintf(file, "%.3f\n", total_price);

      } else if(checkF == 2){
        coisa = 1;
        if(siu != 1) fprintf(file, "\n");
        fprintf(file, "--- %d ---\n", siu);
        fprintf(file, "id: %s\n", reservationId);
        fprintf(file, "begin_date: %s\n", beginDate);  
        fprintf(file, "end_date: %s\n", endDate);
        fprintf(file, "user_id: %s\n", userID);
        fprintf(file, "rating: %d\n", rating);
        fprintf(file, "total_price: %.3f\n", total_price);
      }

        
    }
    fclose(file);
}

//escrever o output da query5
void output_to_file_5(char* id, char* schedule_departure_date,char* destination ,char* airline ,char* plane_model, int checkF, char* filename, int siu) {

    FILE *file = fopen(filename, "a");

    if (file != NULL) {
        //Escrever informação no ficheiro
      if(checkF == 1){
        coisa = 1;
        fprintf(file, "%s;", id);
        fprintf(file, "%s;", schedule_departure_date);
        fprintf(file, "%s;", destination);
        fprintf(file, "%s;", airline);
        fprintf(file, "%s\n", plane_model);

      } else if(checkF == 2){
        coisa = 1;
        if(siu != 1) fprintf(file, "\n");
        fprintf(file, "--- %d ---\n", siu);
        fprintf(file, "id: %s\n", id);
        fprintf(file, "schedule_departure_date: %s\n", schedule_departure_date);
        fprintf(file, "destination: %s\n", destination);
        fprintf(file, "airline: %s\n", airline);
        fprintf(file, "plane_model: %s\n", plane_model);
        }

    }
    fclose(file);
}

//escrever o output da query6
void output_to_file_6(char* aeroporto, int total_passageiros, int checkF, char* filename, int siu) {
  
    FILE *file = fopen(filename, "a");

    if (file != NULL && aeroporto != NULL) {
        //Escrever informação no ficheiro
      if(checkF == 1){
        coisa = 1;
        fprintf(file, "%s;", aeroporto);
        fprintf(file, "%d\n", total_passageiros);

      } else if(checkF == 2){
        coisa = 1;
        if(siu != 1) fprintf(file, "\n");
        fprintf(file, "--- %d ---\n", siu);
        fprintf(file, "name: %s\n", aeroporto);
        fprintf(file, "passengers: %d\n", total_passageiros);  
        }

    }
    fclose(file);
}

//escrever o output da query7
void output_to_file_7(char* aeroporto, double mediana, int checkF, char* filename, int siu) {
    
    FILE *file = fopen(filename, "a");

    if (file != NULL) {
        //Escrever informação no ficheiro
      if(checkF == 1){
        coisa = 1;
        fprintf(file, "%s;", aeroporto);
        fprintf(file, "%.0f\n", mediana);

      } else if(checkF == 2){
        coisa = 1;
        if(siu != 1) fprintf(file, "\n");
        fprintf(file, "--- %d ---\n", siu);
        fprintf(file, "name: %s\n", aeroporto);
        fprintf(file, "median: %.0f\n", mediana);  
        }

    }
    fclose(file);
}

//output da query8
void output_to_file_8(int totalRevenue, int checkF) { 
    if(inter != 1) Contaficheiros++;

    //Gerar nome do ficheiro
    char filename[64];
    if (inter != 1) snprintf(filename, sizeof(filename), "Resultados/command%d_output.txt", Contaficheiros);
    else if (inter == 1) snprintf(filename, sizeof(filename), "Resultados/outputINT.txt"); //modo interativo no terminal

    FILE *file = fopen(filename, "a");

    if (file != NULL && totalRevenue != -1) {
        //Escrever informação no ficheiro
      if(checkF == 1){
        coisa = 1;
        fprintf(file, "%d\n", totalRevenue);

      } else if(checkF == 2){
        coisa = 1;
        fprintf(file, "--- 1 ---\n");
        fprintf(file, "revenue: %d\n", totalRevenue);
      }
        
    }
    fclose(file);
}

//output da query9
void output_to_file_9(char *userName, char *userId, int checkF, char *filename, int siu) {

    FILE *file = fopen(filename, "a");

    if (file != NULL) {
        //Escrever informação no ficheiro
      if(checkF == 1){
        coisa = 1;
        fprintf(file, "%s;", userId);
        fprintf(file, "%s\n", userName);

      } else if(checkF == 2){
        coisa = 1;
        if(siu != 1) fprintf(file, "\n");
        fprintf(file, "--- %d ---\n", siu);
        fprintf(file, "id: %s\n", userId);
        fprintf(file, "name: %s\n", userName);
      }
    }
    fclose(file);
}


void output_to_file_9_2(){
  Contaficheiros++;

    //Gerar nome do ficheiro
    char filename[64];
    snprintf(filename, sizeof(filename), "Resultados/command%d_output.txt", Contaficheiros);

    FILE *file = fopen(filename, "a");
    fclose(file);
}

void output_to_file_10 (int args, int year_month_day, int new_users, int flights, int total_passengers, int unique_passengers, int new_reservations, int checkF, char *filename, int siu) {
 
    FILE *file = fopen(filename, "a");

    if (file != NULL && new_users != -1 && new_reservations != -1) {
        //Escrever informação no ficheiro
      if(checkF == 1){
        coisa = 1;
        fprintf(file, "%d;", year_month_day);
        fprintf(file, "%d;", new_users);
        fprintf(file, "%d;", flights);
        fprintf(file, "%d;", total_passengers);
        fprintf(file, "%d;", unique_passengers);
        fprintf(file, "%d\n", new_reservations);

      } else if(checkF == 2){
        coisa = 1;
        if(siu != 1) fprintf(file, "\n");
        fprintf(file, "--- %d ---\n", siu);
        if(args == 0) fprintf(file, "year: %d\n", year_month_day);
        if(args == 1) fprintf(file, "month: %d\n", year_month_day);
        if(args == 2) fprintf(file, "day: %d\n", year_month_day);
        fprintf(file, "users: %d\n", new_users);
        fprintf (file, "flights: %d\n", flights);
        fprintf (file, "passengers: %d\n", total_passengers);
        fprintf (file, "unique_passengers: %d\n", unique_passengers);
        fprintf(file, "reservations: %d\n", new_reservations);
      }
        
    }
    fclose(file);
}

//output das queries com erros(n funcionam de todo)
void output_to_file_rip() {

    Contaficheiros++;

    //Gerar nome do ficheiro
    char filename[64];
    snprintf(filename, sizeof(filename), "Resultados/command%d_output.txt", Contaficheiros);

    FILE *file = fopen(filename, "a");

    if (file != NULL) {
        //Escrever informação no ficheiro
        fprintf(file, "siuuu"); 
    }
    fclose(file); 
}
