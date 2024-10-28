#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <locale.h>
#include <ncurses.h>
#include <time.h>
#include <sys/resource.h>
#include <unistd.h>

#include "../include/parser.h"
#include "../include/interpreter.h"
#include "../include/teste.h"


int inter = 0, qquery = 0; //flag modo batch ou interativo
double Exec[10]; //Tempo de execução
int nvezes[10]; //número de vezes executadas por query
int qual_query[501]; //qual query executada


int main (int argc, char *argv[]) {
    setlocale(LC_COLLATE, "en_US.UTF-8");

    HashTable *hashTable = create_hash_table();
    
    struct timespec start, end;
    double elapsed;
   
    if (argc == 4){

        // Start time
        clock_gettime(CLOCK_REALTIME, &start);
        
        for(int i = 0; i < 500; i++) qual_query[i] = 0;
        for(int i = 0; i < 10; i++) Exec[i] = 0, nvezes[i] = 0;

        char *path1 = argv[1]; // path do ficheiro com os dados de entrada

        int argSize = strlen(path1); 
        parser(path1, hashTable, argSize);

        char *path2 = argv[2]; // path do ficheiro com as queries

        FILE *file2 = fopen(path2, "r"); // abre o ficheiro com as queries

        char *path3 = argv[3]; // path da pasta com os outputs --------------------------------------------------------------

        //passa cada comando para a função interpreta linha a linha
        char *line = NULL;
        size_t len = 0;
        ssize_t read;

          while ((read = getline(&line, &len, file2)) != -1) {

            if (read > 0 && line[read - 1] == '\n') {
                line[read - 1] = '\0';
            }

            line[read - 1] = '\0';

            struct timespec startq, endq;
            double elapsedq;
            // Start time
            clock_gettime(CLOCK_REALTIME, &startq);

            interpreta(hashTable, line);

            // End time
            clock_gettime(CLOCK_REALTIME, &endq);
            elapsedq = (endq.tv_sec - startq.tv_sec) + (endq.tv_nsec - startq.tv_nsec) / 1e9;

            Exec[qquery] += elapsedq;

        }
        printf("\nTempo médio, por comando, de cada query:\n");

        for(int i = 0; i < 10; i++){ 
            Exec[i] = Exec[i] / nvezes[i];
            printf("A query%d foi executada %d vezes e demorou %.6f segundos a ser executada.\n", i+1, nvezes[i], Exec[i]);
        }
        compara_output(path3);// ------------------------------------------------------------------------------------------

        if(line) free(line);
        line = NULL;

        fclose(file2);

    } else if (argc < 2) {

        printf("\nBem-vindo ao modo interativo!\n");
        printf("Escreve 'ajuda' para veres os comandos disponíveis.\n");
        printf("A primeira coisa que escreveres deve ser  o caminho para o dataset a processar.\n");
        
        char *dataset = NULL;
        size_t tamanho_dataset = 0;
        ssize_t caracteres_dataset = 0;

        while(1){

        caracteres_dataset = getline(&dataset, &tamanho_dataset, stdin);

        if (caracteres_dataset > 0 && dataset[caracteres_dataset - 1] == '\n') {
                dataset[caracteres_dataset - 1] = '\0';
            }
            
        if (access(dataset, F_OK) != -1) {
            break;

        } else {
            printf("O caminho não existe. Por favor indica um caminho válido.\n");
            dataset = NULL;
            tamanho_dataset = 0;
            caracteres_dataset = 0;
        }

        }

        parser(dataset, hashTable, caracteres_dataset);

        char *line = NULL;
        size_t tamanho = 0;

        printf("\nGostarias de receber o resultado dos comandos em ficheiros, ou no terminal? (Escreve F ou T)\n");

        char *tipo_de_output = NULL;
        size_t tamanho_tipo = 0;

        ssize_t caracteres_tipo = getline(&tipo_de_output, &tamanho_tipo, stdin);

        if (caracteres_tipo > 0 && tipo_de_output[caracteres_tipo - 1] == '\n') {
                tipo_de_output[caracteres_tipo - 1] = '\0';
            }
        
        if(strcmp(tipo_de_output, "T") == 0 || strcmp(tipo_de_output, "t") == 0 || strcmp(tipo_de_output, "Terminal") == 0 || strcmp(tipo_de_output, "terminal") == 0){
            inter = 1;
        }
         
        if(inter == 1) printf("Os resultados dos comandos vão ser reproduzidos no terminal.\n");
        else printf("Os resultados dos comandos vão ser escritos em ficheiros dentro da pasta Resultados.\n");

        while (1) {
            ssize_t caracteresLidos = getline(&line, &tamanho, stdin);

            if (caracteresLidos == -1) {
                break;
            }

            if (caracteresLidos > 0 && line[caracteresLidos - 1] == '\n') {
                line[caracteresLidos - 1] = '\0';
            }

            int p = interpreta_interativo(hashTable, line/*, passengerTable*/);

            if(p == 1) break;
        }
        if(line) free(line);
        line = NULL;
        if(dataset) free(dataset);
        dataset = NULL;

    } else {

        char *path1 = argv[1]; // path do ficheiro com os dados de entrada

        int argSize = strlen(path1); 
        parser(path1, hashTable, argSize);

        char *path2 = argv[2]; // path do ficheiro com as queries

        FILE *file2 = fopen(path2, "r"); // abre o ficheiro com as queries

        //passa cada comando para a função interpreta linha a linha
        char *line = NULL;
        size_t len = 0;
        ssize_t read;

          while ((read = getline(&line, &len, file2)) != -1) {

            if (read > 0 && line[read - 1] == '\n') {
                line[read - 1] = '\0';
            }
        
            interpreta(hashTable, line);
        }
        if(line) free(line);
        line = NULL;

        fclose(file2);
    }

    free_hash_table(hashTable);
    hashTable = NULL; 

    if (argc == 4){
        
        // Tempo execução total
        clock_gettime(CLOCK_REALTIME, &end);
        elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
        
        printf("\nO programa demorou %.6f segundos a ser executado.\n", elapsed);

        //Memória utilizada
        struct rusage r_usage;
        getrusage(RUSAGE_SELF, &r_usage);
        printf("Memória utilizada: %ld kilobytes\n", r_usage.ru_maxrss);
    }

    return 0;
}

/*
Tempo médio, por comando, de cada query:
A query1 foi executada 180 vezes e demorou 0.000238 segundos a ser executada, no total 0.04284 seg.
A query2 foi executada 50 vezes e demorou 0.000155 segundos a ser executada, no total 0.00775 seg (0.05059).
A query3 foi executada 50 vezes e demorou 0.002578 segundos a ser executada, no total 0.1289 seg (0.17949).
A query4 foi executada 5 vezes e demorou 0.522689 segundos a ser executada, no total 2.613445 seg (2.792935).
A query5 foi executada 50 vezes e demorou 0.022037 segundos a ser executada, no total 1.10185 seg (3.894785).
A query6 foi executada 50 vezes e demorou 0.032705 segundos a ser executada, no total 1.63525 seg (5.530035).
A query7 foi executada 10 vezes e demorou 0.155441 segundos a ser executada, no total 1.55441 seg (7.08445).
A query8 foi executada 50 vezes e demorou 0.045356 segundos a ser executada, no total 2.2678 seg (9.35225).
A query9 foi executada 50 vezes e demorou 0.338691 segundos a ser executada, no total 16.93455 seg (26.2868).
A query10 foi executada 5 vezes e demorou 5.421977 segundos a ser executada, no total 27.109885 seg (53.396685).
*/