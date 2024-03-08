#include <stdio.h>
#include <stdlib.h>

typedef struct xixi{
    double numero;
    struct xixi *prox;
} Xixi;

Xixi* init_list(list){
    list = NULL;
    return list;
}

int coco (list){
    double valor;
    while(scanf("%lf", &valor) != 0){
        insert_node(valor, list);
    }
    return 0;
}

void insert_node (double valor, Xixi *list){
    
}

