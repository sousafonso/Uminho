#include "../include/totalatrasos.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct totalatrasos {
    int *atrasos;
    int size;
    int current;
} TotalAtrasos;

int *get_atrasos(const TotalAtrasos *totalAtrasos){
    if(totalAtrasos && totalAtrasos->atrasos) return totalAtrasos->atrasos;
    else return 0;
}

int get_size(const TotalAtrasos *totalAtrasos){
    if(totalAtrasos && totalAtrasos->size) return totalAtrasos->size;
    else return 0;
}

int get_current(const TotalAtrasos *totalAtrasos){
    if(totalAtrasos && totalAtrasos->current) return totalAtrasos->current;
    else return 0;
}

void set_atraso(TotalAtrasos *totalAtrasos, int atraso){
    if(totalAtrasos){
        int size = totalAtrasos->size;
        int new = totalAtrasos->current;
        if (new == size){ 
            totalAtrasos->size *= 2;
            totalAtrasos->atrasos = realloc(totalAtrasos->atrasos, sizeof(int) * size * 2);
        }
                
        totalAtrasos->atrasos[new] = atraso;
        totalAtrasos->current++;
    }
}

void set_size(TotalAtrasos *totalAtrasos, int size){
    if(totalAtrasos) totalAtrasos->size = size;
}

void set_current(TotalAtrasos *totalAtrasos, int current){
    if(totalAtrasos) totalAtrasos->current = current;
}

TotalAtrasos *new_atraso(void){
    TotalAtrasos *totalAtrasos = (TotalAtrasos *)malloc(sizeof(TotalAtrasos));
    totalAtrasos->atrasos = malloc(1024 * sizeof(int));
    totalAtrasos->size = 1024;
    totalAtrasos->current = 0;
    return totalAtrasos;
}

void free_atrasos(TotalAtrasos *totalAtrasos){
    if(totalAtrasos != NULL) {
        if(totalAtrasos->atrasos != NULL) free(totalAtrasos->atrasos);
        free(totalAtrasos);
    }
}