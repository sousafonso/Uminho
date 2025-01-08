// Uma queue, como a tradução diz é uma fila, ou seja, o primeiro a entrar é o primeiro a ser analizado
// Na stack inserimos coisas e essas são as ultimas a sair, ou seja, é como se fosse uma pilha onde se acrescentam coisas sempre acima do anterior

#include <stdio.h>


// Relembre o tipo LInt usado para representar listas ligadas de inteiros.
typedef struct slist {
    int valor;
    struct slist * prox;
} * LInt;

LInt newLInt (int x, LInt xs) { // esta  função cria logo uma caixa com um valor e um apontador
   LInt r = malloc (sizeof(struct slist));
   if (r!=NULL) {
      r->valor = x; r->prox = xs;
   }
return r; }

typedef struct slist* LInt;

// No caso das stacks, os elementos são inseridos e removidos do início da lista.
typedef LInt Stack;

/*
    No caso das queues, e de forma a tornar as operações de adição/remoção de um elemento eficientes (e com uma eficácia que não depende do tamanho da queue), 
    é costume usar dois endereços: um para cada uma das extremidades da lista. 
    A inserção é feita no final da lista e a remoção do início.
 */

typedef struct {
         LInt inicio,fim;
} Queue; // A queue tem um apontador para o início e outro para o fim da lista e segue a regra First In First Out (FIFO)
// É de notar que os apontadores podem ser iguais quando a lista só tem um elemento ou quando é vazia
// Sabemos que a Queue é NULL quando ou o primeiro é NULL ou quando o último é NULL

Stack s;

// ******** 1 ********

void initStack (Stack *s){ // função que começa com a stack vazia
    *s = NULL;
}

int SisEmpty (Stack s){ // função que verifica se uma stack está vazia
    if (s == NULL) return 1; // estas duas linhas podiam ser abreviadas para:
    return 0;                 // return (s == NULL); 
}

int push (Stack *s, int x){ // função que insere x no topo/início da stack
   LInt aux = newLInt (x, *s);
   if (aux == NULL) return 1;

   *s = aux;
   return 0;
}

int pop (Stack *s, int *x){ // função que remove o conteúdo e a memória do topo/início da stack 
    if (SisEmpty(*s)) return 1;

    LInt aux;
    *x = (*s) -> valor; // guardar o valor

    aux = aux -> prox; // a stack depois de eliminar o primeiro elemento (o do topo), a stack deve começar no elemento a seguir (prox)

    free (*s);

    *s = aux;
}

int top (Stack s, int *x){ // esta função consulta o primeiro elemento
    if (SisEmpty(s)) return 1;
    *x = s -> valor;
}

// ******** 2 ********

void initQueue (Queue *q){ // função que inicia uma queue
    q -> inicio = NULL;
    q -> fim = NULL;
}

int QisEmpty (Queue q){ // função que verifica se é vazia
    return (q.inicio = NULL);
}

int enqueue (Queue *q, int x){ // função que insere elemento no final da lista
    LInt aux = newLInt(x, NULL);
    if (QisEmpty(*q)){ // se a lista for fazia faz isto
        q -> inicio = aux;
        q -> fim = aux;
    }

    else{
        q -> fim -> prox = aux;
        q -> fim = aux; // o fim tem de apontar para o novo elemento naturalmente
    }

    return 0;
}

int dequeue (Queue *q, int *x){ // função que remove o primeiro elemento da queue/lista
    if (QisEmpty(*q)) return -1;

    *x = q -> inicio -> valor;
    LInt aux = q -> inicio;
    q -> inicio = q -> inicio -> prox;


    free (aux);
    return 0;
}

int front (Queue q, int *x){
    if (q.inicio == NULL) return -1;
    *x = q.inicio -> valor;

    return 0;
}


typedef LInt QueueC;
// ******** 3 ********

// nas queues ciclicas, os prox têm sempre valor e não NULL como era costume
void initDeque (QueueC *q){
    *q = NULL;
    return 0;
}

int DisEmpty (QueueC q){
    return (q == NULL);
}

int enqueueC (QueueC *q, int x){
    if (*q == NULL){
        *q = newLInt(x, NULL);
        (*q) -> prox = *q;
    }
    else{
        (*q) -> prox = newLInt(x, (*q) -> prox);
        *q = (*q) -> prox;
    }
    return 0;
}

int dequeueC (QueueC *q, int *x){
    if (DisEmpty(q)) return -1;
    if (*q == (*q) -> prox){
        *x = (*q) -> valor;
        free (*q);
    }
    else {
        *x = (*q) -> valor;
        LInt aux = (*q) -> prox;
        (*q) -> prox = aux -> prox;
        free (aux);
    }
    return 0;
}

int frontC (QueueC q, int *x){
    
}
