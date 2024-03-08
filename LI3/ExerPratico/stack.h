#ifndef STACK_H #define STACK_H
#include "node.h"

typedef struct stack {
    int size;
    Node* top;
    void (*elemPrint) (void*);
} Stack;

void (*elemPrint) (void *); // função para imprimir um elemento da stack
Stack* stackCreate(void (*elemPrint) (void *));
void stackPush (Stack* stack, void* data);
void* stackPop (Stack* stack); void stackPrint (Stack* stack);

#endif