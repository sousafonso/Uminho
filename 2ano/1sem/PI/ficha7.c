#include <stdio.h>

typedef struct celula {
    char *palavra;
    int ocorr;
    struct celula * prox;
} * Palavras;

void libertaLista (Palavras l) {
    Palavras aux;
    while (l != NULL) {
        aux = l;
        l = l->prox;
        free(aux->palavra);
        free(aux);
    }
}

Palavras quantasP (Palavras l){
    Palavras aux = l;
    int count = 0;
    while (aux != NULL) {
        count++;
        aux = aux->prox;
    }
    return count;
}

void listaPal (Palavras l){
    Palavras aux = l;
    while (aux != NULL) {
        printf("%s %d\n", aux->palavra, aux->ocorr);
        aux = aux->prox;
    }
}

char * ultima (Palavras l){
    Palavras aux = l;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    return aux->palavra;
}

Palavras acrescentaInicio (Palavras l, char *p){
    Palavras nova = malloc(sizeof(struct celula));
    nova->palavra = p;
    nova->ocorr = 1;
    nova->prox = l;
    return nova;
}

Palavras acrescentaFim (Palavras l, char *p){
    Palavras aux = l;
    Palavras nova = malloc(sizeof(struct celula));
    nova->palavra = p;
    nova->ocorr = 1;
    nova->prox = NULL;
    if (l == NULL) {
        return nova;
    }
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = nova;
    return l;
}

Palavras acrescenta (Palavras l, char *p){
    Palavras aux = l;
    while (aux != NULL) {
        if (strcmp(aux->palavra, p) == 0) {
            aux->ocorr++;
            return l;
        }
        aux = aux->prox;
    }
    return acrescentaFim(l, p);
}

struct celula * maisFreq (Palavras l){
    Palavras aux = l;
    Palavras maisFreq = l;
    while (aux != NULL) {
        if (aux->ocorr > maisFreq->ocorr) {
            maisFreq = aux;
        }
        aux = aux->prox;
    }
    return maisFreq;
}