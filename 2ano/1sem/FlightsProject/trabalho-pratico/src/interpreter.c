#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/DataStore.h"
#include "../include/interpreter.h"
#include "../include/queries.h"

int contador_master = 1;
extern int coisa, qquery;
extern double Exec[10];
extern int nvezes[10];
extern int qual_query[501];

void interpreta(const HashTable *hashTable, char *line){

    //copiar a linha do comando para outro array
    char line_copy[200];
    strcpy(line_copy, line); 


    //query10
    if(line[0] == '1' && line[1] == '0'){
        qquery = 9;
        nvezes[9]++;
        qual_query[contador_master++] = 10;

        //criar 3 arrays com o comprimento do comando, ano, mês
        int nquery = 0,nyear = 0, nmonth = 0;
        for(; line[nquery] != ' ' && line[nquery] != '\n' && line[nquery] != '\0'; nquery++);
        for(; line[nyear + nquery + 1] != ' ' && line[nyear + nquery + 1] != '\0'; nyear++);
        for(; line[nmonth + nyear + nquery + 2] != ' ' && line[nmonth + nyear + nquery + 2] != '\0'; nmonth++);

        char year[nyear + 1], month[nmonth + 1];
        year[nyear] = '\0';
        month[nmonth] = '\0';

        //colocar em cada array a informação correspondente
        if(nyear != 0){

        for(int j = 0; j < nyear; j++){
          year[j] = line[j + nquery + 1];
           }         
        }
        
        if(nmonth != 0){
        
        for(int j = 0; j < nmonth; j++){
          month[j] = line[j + nquery + nyear + 2];
           }
        }


        //mandar para a query10
        if(nyear != 0 && nmonth != 0){query10(hashTable/*, passengerTable*/, year, month, nquery - 1);}
        if(nyear != 0 && nmonth == 0){query10(hashTable /*,passengerTable*/, year, NULL, nquery - 1);}
        if(nyear == 0){query10(hashTable /*,passengerTable*/, NULL, NULL, nquery - 1);}    

    }


    //query1
    else if(line[0] == '1'){
        qquery = 0;
        nvezes[0]++;
        qual_query[contador_master++] = 1;


        int nquery = 1;
        if(line[1] == 'F'){nquery = 2;}
    
      char *token = strtok(line, " \0");
        while (token != NULL) {

            //Verifica se o token não é 1 ou 1F, e passa para a query1 quando não for 1 ou 1F
            if (strcmp(token, "1") != 0 && strcmp(token, "1F") != 0) {
                query1(hashTable, token, nquery/*, passengerTable*/);
                break;
            }
            token = strtok(NULL, " \0");
        }
    }
    

    //query2
    else if(line[0] == '2'){
        qquery = 1;
        nvezes[1]++;
        qual_query[contador_master++] = 2;
         
         //criar 3 arrays com o comprimento do comando, id, type
        int nquery = 0,nid = 0, ntype = 0;
        for(; line[nquery] != ' '; nquery++);
        for(; line[nid + nquery + 1] != ' ' && line[nid + nquery + 1] != '\0'; nid++);
        for(; line[ntype + nid + nquery + 2] != ' ' && line[ntype + nid + nquery + 2] != '\0'; ntype++);

        char id[nid + 1], type[ntype + 1];
        id[nid] = '\0';
        type[ntype] = '\0';

        //colocar em cada array a informação correspondente
        if(nid != 0){

        for(int j = 0; j < nid; j++){
          id[j] = line[j + nquery + 1];
           }         
        }
        
        if(ntype != 0){
        
        for(int j = 0; j < ntype; j++){
          type[j] = line[j + nquery + nid + 2];
           }
        }

        //mandar para a query2
        if(ntype != 0){query2(hashTable, id, type, nquery/*, passengerTable*/);}
        else if(ntype == 0){query2(hashTable, id, NULL, nquery/*, passengerTable*/);}
    }


    //query3
    else if(line[0] == '3'){
        qquery = 2;
        nvezes[2]++;
        qual_query[contador_master++] = 3;

        int nquery = 1;
        if(line[1] == 'F'){nquery = 2;}

        char *token = strtok(line, " \0");
          while (token != NULL) {
            //Verifica se o token não é 3, e passa para a query1 quando não for 3
            if (strcmp(token, "3") != 0 && strcmp(token, "3F") != 0) {
                query3(hashTable, token, nquery);
                break;
            }
            token = strtok(NULL, " \0");
        }

    }


    //query4
    else if(line[0] == '4'){
        qquery = 3;
        nvezes[3]++;
        qual_query[contador_master++] = 4;

        int nquery = 1;
        if(line[1] == 'F'){nquery = 2;}

        char *token = strtok(line, " \0");
          while (token != NULL) {
            //Verifica se o token não é 4, e passa para a query4 quando não for 4 (hotel id)
            if (strcmp(token, "4") != 0 && strcmp(token, "4F") != 0) {
                query4(hashTable, token, nquery);
                break;
            }
            token = strtok(NULL, " \0");
        }
    }


    //query5
    else if(line[0] == '5'){
        qquery = 4;
        nvezes[4]++;
        qual_query[contador_master++] = 5;

        //criar 4 arrays com o comprimento do comando, nome, begin date, end date
        int nquery = 0,nname = 0, nbegin = 0, nend = 0;
        for(; line[nquery] != ' '; nquery++);
        for(; line[nname + nquery + 1] != ' '; nname++);
        for(; line[nbegin + nname + nquery + 3] != '\"'; nbegin++);
        for(; line[nbegin + nname + nend + nquery + 6] != '\"'; nend++);

        char name[nname + 1], begin_date[nbegin + 1], end_date[nend + 1];
        name[nname] = '\0';
        begin_date[nbegin] = '\0';
        end_date[nend] = '\0';

        //colocar em cada array a informação correspondente
        for(int j = 0; j < nname; j++){
          name[j] = line[j + nquery + 1];
        }

        for(int j = 0; j < nbegin; j++){
        begin_date[j] = line[j + nquery + nname + 2 + 1];//o +1 é para mandar sem aspas
        }

        for(int j = 0; j < nend; j++){
        end_date[j] = line[j + nquery + nname + nbegin + 5 + 1];//o +1 é para mandar sem aspas
        }
        
        query5(hashTable, name, begin_date, end_date, nquery);
    
    }


    //query6
    else if(line[0] == '6'){
        qquery = 5;
        nvezes[5]++;
        qual_query[contador_master++] = 6;

        //criar 3 arrays com o comprimento do comando, ano, número de top N
        int nquery = 0,nyear = 0, nnum = 0;
        for(; line[nquery] != ' '; nquery++);
        for(; line[nyear + nquery + 1] != ' '; nyear++);
        for(; line[nnum + nyear + nquery + 2] != ' ' && line[nnum + nyear + nquery + 2] != '\0'; nnum++);

        char year[nyear + 1], topnum[nnum + 1];
        year[nyear] = '\0';
        topnum[nnum] = '\0'; 

        //colocar em cada array a informação correspondente
        for(int j = 0; j < nyear; j++){
          year[j] = line[j + nquery + 1];
        }

        for(int j = 0; j < nnum; j++){
        topnum[j] = line[j + nquery + nyear + 2];
        }

        int m = atoi(topnum);
        
        query6(hashTable/*, passengerTable*/, year, m, nquery);
    }


    //query7
    else if(line[0] == '7'){
        qquery = 6;
        nvezes[6]++;
        qual_query[contador_master++] = 7;

        int nquery = 1;
        if(line[1] == 'F'){nquery = 2;}

          //o N pode ser 7
          char *token = strtok(line, " \0");
          int i = 0;

          while (token != NULL) {
            
            //para no segundo ciclo (quando obtém o N)
            if (i == 1) {
                //if (uno == 1) query7(hashTable, atoi(token), nquery), uno = 0;
                query7(hashTable, atoi(token), nquery);
                break;
            }

            i++;
            token = strtok(NULL, " \0");
        }
    }

    //query8
    else if(line[0] == '8'){
        qquery = 7;
        nvezes[7]++;
        qual_query[contador_master++] = 8;

        //criar 4 arrays com o comprimento do comando, userID, begin date, end date
        int nquery = 0,nuserid = 0, nbegin = 0, nend = 0;
        for(; line[nquery] != ' '; nquery++);
        for(; line[nuserid + nquery + 1] != ' '; nuserid++);
        for(; line[nbegin + nuserid + nquery + 2] != ' '; nbegin++);
        for(; line[nbegin + nuserid + nend + nquery + 3] != ' ' && line[nbegin + nuserid + nend + nquery + 3] != '\0'; nend++);

        char userid[nuserid + 1], begin_date[nbegin + 1], end_date[nend + 1];
        userid[nuserid] = '\0';
        begin_date[nbegin] = '\0';
        end_date[nend] = '\0';

        //colocar em cada array a informação correspondente
        for(int j = 0; j < nuserid; j++){
        userid[j] = line[j + nquery + 1];
        }

        for(int j = 0; j < nbegin; j++){
        begin_date[j] = line[j + nquery + nuserid + 2];
        }

        for(int j = 0; j < nend; j++){
        end_date[j] = line[j + nquery + nuserid + nbegin + 3];
        }
        
        query8(hashTable, userid, begin_date, end_date, nquery);
    }

    //query9
    else if(line[0] == '9'){
        qquery = 8;
        nvezes[8]++;
        qual_query[contador_master++] = 9;

      //criar 2 arrays com o comprimento do comando e do prefixo
      int nquery = 0,nprefix = 0;
      for(; line[nquery] != ' '; nquery++);

      if(line[nquery + 1] == '\"'){
          for(;line[nprefix + nquery + 2] != '\"'; nprefix++);

      } else {
          for(; line[nprefix + nquery + 1] != '\0'; nprefix++);

      }

      char prefix[nprefix + 1];
      prefix[nprefix] = '\0';

      //colocar o prefixo no array
      if(line[nquery + 1] == '\"'){
          for(int j = 0; j < nprefix; j++){
          prefix[j] = line[j + nquery + 2];
          }
      } else {
          for(int j = 0; j < nprefix; j++){
          prefix[j] = line[j + nquery + 1];
          }
      }

        query9(hashTable, prefix, nquery);
      
    }
}

//Modo Interativo
int interpreta_interativo(const HashTable *hashTable, char *line){

    if (strcmp(line, "ajuda") == 0) {
        printf("Lista de comandos disponíveis:\n");
        printf("1 <ID>  |  (Lista o resumo de um utilizador, voo, ou reserva.)\n");
        printf("2 <ID> [flights|reservations]  |  (Lista os voos ou reservas de um utilizador. Se não houver 2º argumento, serão listados os voos e reservas.) \n");
        printf("3 <ID> | (Apresenta a classificação média de um hotel, a partir do seu ID)\n");
        printf("4 <ID> | (Lista as reservas de um hotel, ordenadas por data de início)\n");
        printf("5 <\"nome\"> <\"data_inicio\"> <\"data_fim\"> | (Lista os voos com origem num dado aeroporto, num intervalo de tempo)\n");
        printf("6 <ano> <N> | (Lista os N aeroportos com mais passageiros num dado ano)\n");
        printf("7 <N> | (Lista os N aeroportos com a maior mediana de atrasos)\n");
        printf("8 <ID> <\"data_inicio\"> <\"data_fim\"> | (Lista a receita total de um hotel, num intervalo de tempo)\n");
        printf("9 <\"prefixo\"> | (Lista os utilizadores cujo nome começa por um dado prefixo)\n");
        printf("10 [ano[mês]] | (Apresenta várias métricas como o número de novos utilizadores registados, número de voos, número de passageiros, número de passageiros únicos e número de reservas de acordo com o ano e/ou mês fornecidos)\n");
        printf ("No fim de cada número de comando, podes escrever F para uma forma de output diferente.\n");
        printf("Sair ou q | (Sai do programa)\n");
        
    } else if (strcmp(line, "sair") == 0 || strcmp(line, "q") == 0) {
        printf("A sair...\n");
        return 1;

    } else if (strcmp(line, "siu") == 0 || strcmp(line, "SIU") == 0) {
        printf("O Ronaldo é o melhor.\n");

    } else if (strcmp(line, "Boas") == 0 || strcmp(line, "boas") == 0) {
        printf("Boas, tudo bem?\n");

    } else {

        int flag = 0;
        if(line[0] != '1' && line[0] != '2' && line[0] != '3' && line[0] != '4' && line[0] != '5' && line[0] != '6' && line[0] != '7' && line[0] != '8' && line[0] != '9' && (line[0] != '1' || line[1] != '0')) flag = 1;

        if(flag == 1) {
            printf("Comando não reconhecido. Escreve 'ajuda' para ver os comandos disponíveis.\n");

        } else {
            interpreta(hashTable, line);
            if(coisa == 1) printf("\nComando executado.\n");
            else printf("\nComando executado. Não existem dados que cumprem o critério desse comando.\n");
            coisa = 0;
        }

    }

    return 0;
}