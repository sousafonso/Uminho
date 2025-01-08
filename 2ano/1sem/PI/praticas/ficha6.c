/*
Stack (ou pilha) que s ̃ao buffers em que o pr ́oximo elemento a ser retirado  ́e o u ́ltimo 
que foi acrescen- tado (Last In First Out). As operac ̧ ̃oes de acrescentar/retirar 
s ̃ao normalmente referidas como push/pop.
*/

/*
Queue (ou fila) que s ̃ao buffers em que o pr ́oximo elemento a ser 
retirado  ́e o que foi acrescentado h ́a mais tempo (First In First Out). 
As operac ̧ ̃oes de acrescentar/retirar s ̃ao normalmente referidas como enqueue/dequeue.
*/


#define Max 4

// 1
struct stack{
    int sp; // stack pointer
    int values [Max];
};

typedef struct stack *SStack;

void Sinit (SStack s){
    (*s).sp = 0;
} // s -> sp substitui a seguinte notação: *s.sp

int SisEmpty (SStack s){
    if ((*s).sp == 0) return 1;
    else return 0;
}

int Spush (SStack s, int x){
    if ((*s).sp == Max) return 1;
    (*s).values[(*s).sp] = x; // s -> values[s -> sp] = x
    (*s). sp++;
    return 0;
}

int Spop (SStack s, int *x) {
    // se a stack ta vazia devolvo 1;

    if (SisEmpty(s)) return 1;

    *x = (*s).values[(*s).sp-1];
    s -> sp = s -> sp -1;

    return 0;
}   

int Stop (SStack s, int *x){
    if (SisEmpty(s)) return 1;
    *x = (*s).values[Max];

    return 0;
}

// 2
struct staticQueue {
    int front; //inicio
    int length; //tamanho
    int values [Max];
  } QUEUE, *SQueue;

void SinitQueue (SQueue q){
    q -> tamanho = 0;
}

int SisEmptyQ (SQueue q){
    return q -> tamanho == 0;
}

int Senqueue (SQueue q, int x){
    if (q -> inicio +  q -> tamanho > Max) return 1;
    q -> values[q -> inicio + q -> tamanho++] = x;
    return 0;
}


int Sdequeue (SQueue q, int *x){
    if (SisEmpty q == 0) return 1;
    *x = q->valores[(q->inicio)++];
        (q->tamanho)--;
        return 0;
}



// 3
struct dinStack {
int size; // capacidade da stack
int sp;
int *values;
};

typedef struct dinStack *DStack; 

void aumenta (DStack s) {

    int *novo_array = malloc ( 2 * s->size * sizeof (int));

    for (int i=0; i<s->size; i++) {
        novo_array[i] = s-> values[i]; 
    }

    free (s->values);
    s->size = 2*(s->size);
    s->values = novo_array;
} 

// a)

void DinitStack (DStack s) {
    s -> values = malloc (3 * sizeof (int)); 
    s -> size = 3;
    s -> sp = 0;
}


// b)

int DisEmpty (DStack s) {
    if (s->sp == 0) return 1;
    return 0;
}


// c)
int Dpush (DStack s, int x) {

    if (s->sp == s ->size) aumenta (s);
    (s->values[(s->sp)]) == x;
    (s->sp) ++;

return 0;
}