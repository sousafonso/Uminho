#include "simple.h"

int inc1(int i) {
    return i + 1; // apenas incrementa o valor
}

int inc2(int* i) {
    return *i + 1; // retornar o conteúdo da posição de memória
}