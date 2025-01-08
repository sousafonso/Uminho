#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LInt_nodo {
     int valor;
     struct LInt_nodo *prox;
} *LInt;

typedef struct ABin_nodo {
     int valor;
     struct ABin_nodo *esq, *dir;
} *ABin;

// 1

int pesquisa (int a[], int N, int x){
    if (N == 0) return 1;
    while(N > 0){
        if (a[N] == x) return N;
        N--;
    }
    return -1;
}

// 2

void roda (LInt *l){
    LInt aux = *l;
    LInt cauda = l -> prox;
    while (cauda -> prox == NULL){
        cauda = cauda -> prox;
        l = l -> prox;
    }
    aux = cauda -> valor;
    l -> prox = NULL;
    l = aux;

    return 0;
}