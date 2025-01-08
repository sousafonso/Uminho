#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


#define MAXLINE 1000

typedef struct lligada {
    int valor;
    struct lligada *prox;
} Nodo, *LInt;


// 1
int length (LInt l){
    if(l == NULL) return 0;
    else return (1 + length(l->prox));
}

// 2
void freeL (LInt l){
    LInt aux = l;
    l = l -> prox;
    free (aux);
}

// 3
void imprimeL(LInt l) {
    while(l != NULL) {
        printf("%d\n",l->valor);
        l = l->prox;
    }
}

// 4
LInt reverseL2(LInt l) {
    LInt prox = l->prox;
    l->prox = NULL;
    while(prox) {
        LInt temp = prox->prox;
        prox->prox = l;
        l = prox;
        prox = temp;
    }
    return l;
}

// 5
void insertOrd (LInt* l, int x) {
    LInt aux = malloc(sizeof(struct lligada));
    aux -> valor = x;
    aux -> prox = NULL;
    LInt prev = NULL;
    for(;*l && (*l)->valor < x; prev = (*l), l = &((*l)->prox));
    if(prev) {
        aux->prox = (*l);
        prev->prox = aux;
    }
    else {
        aux->prox = (*l);
        *l = aux;
    }
}

// 6
int removeOneOrd(LInt *l, int x) {
    LInt prev = NULL;
    for(;*l && x != (*l)->valor; prev = *l, l = &((*l)->prox)); // este ciclo permite avançar na lista até encontrar um elemento igual a x
    if(!(*l)) return 1; // se eventualmente chegarmos ao fim da lista, retorna 1
    if(!prev) (*l) = (*l)->prox;
    else prev->prox = (*l)->prox;
    return 0;
}

int removeOneOrd2(LInt* l, int x) {
    if((*l)->valor == x) {
        LInt aux = (*l);
        (*l) = (*l)->prox;
        free(aux);
        return 0;
    }
    LInt prev = (*l);
    while(prev->prox) {
        LInt list = prev->prox;
        if(list->valor == x) {
            prev->prox = list->prox;
            free(list);
            return 0;
        }
        prev = prev->prox;
    }
    return 1;
}

// 7
void merge(LInt* r, LInt a, LInt b) {
    if(!a && !b) return;
    if(b == NULL || a != NULL && a->valor < b->valor) {
        (*r) = a; // coloca o valor de a na posiçãp atual
        merge(&((*r)->prox),a->prox,b);
    }
    else {
        (*r) = b; // coloca o valor de b na posição atual
        merge(&((*r)->prox),a,b->prox);
    }
}

// 8
void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
    if (l->valor < x){
        *mx = x;
        *Mx = NULL;
        splitQS(l->prox, x, &((*mx)->prox), Mx);
    }
    else {
        *mx = NULL;
        *Mx = x;
        splitQS(l->prox, x, mx, &((*Mx)->prox));
    }
}

// 9 
LInt parteAmeio (LInt *l){
    int meio = length (*l) / 2; // dividir a lista a meio   
    if(meio == 0) return NULL;
    LInt y = (*l);
    LInt prev = NULL;
    for(int i = 0; i < meio; i++) {
        prev = (*l);  
        (*l) = (*l)->prox; // o apontador avança uma casa para a frente
    }
    prev->prox = NULL;
    return y;
}

// 10
int removeAll (LInt *l, int x){
    int rem = 0; // contador de remoções
    LInt prev = NULL; // criar uma caixa vazia
    while(*l) {
        if((*l)->valor == x) {
            if(!prev) (*l) = (*l)->prox;
            else prev->prox = (*l)->prox;
            rem++;
        }
        else {
            prev = (*l);
            l = &((*l)->prox);
        }
    }
    return rem;
}

// 11
int removeDups(LInt *l){
    int rem = 0;
    for(;*l; l = &((*l)->prox)) {
        LInt prevAux = (*l), aux = (*l)->prox; // o prevAux é o primeiro elemento da lista que vai ser comparado com o aux (este vai andar para a frente através do ciclo que se segue)
        for(; aux; aux = prevAux->prox) {
            if(aux->valor == (*l)->valor) {
                prevAux->prox = aux->prox;
                rem++;
                free(aux);
            }
            else prevAux = aux;
        }
    }
    return rem;
}

// 12
int removeMaiorL(LInt *l) {
    int max = (*l)->valor;
    LInt prev = NULL;
    LInt maxPrev = NULL;
    LInt maxL = (*l);
    LInt list = (*l);
    for(;list; list = list->prox) {
        if(list->valor > max) {
            maxPrev = prev;
            maxL = list;
            max = list->valor;
        }
        prev = list;
    }
    if(!maxPrev) (*l) = (*l)->prox;
    else maxPrev->prox = maxL->prox;
    return max;
}

// 13
void init (LInt *l) {
    LInt prev = NULL;
    for(;(*l)->prox;prev = *l, l = &((*l)->prox));
    if(!prev) {
        free(*l);
        *l = NULL;
    }
    else {
        prev->prox = NULL;
        free(*l);
    }
}

void init2(LInt *lista) {
    if (*lista == NULL || (*lista)->prox == NULL) {
        // Caso a lista esteja vazia ou tenha apenas um elemento,
        // não há nada para remover
        return;
    }

    LInt atual = *lista;

    // Percorre a lista até o penúltimo elemento
    while (atual->prox->prox != NULL) {
        atual = atual->prox;
    }

    // Libera a memória do último elemento
    free(atual->prox);
    atual->prox = NULL;
}

// 14

void appendL (LInt *l, int x) {
    LInt new = malloc(sizeof(struct lligada));
    new->valor = x;
    new->prox = NULL;
    if(!(*l)) (*l) = new;
    else {
        for(;(*l)->prox; l = &((*l)->prox));
        (*l)->prox = new;
    }
}

void appendL2(LInt *lista, int valor) {
    LInt novoElemento = malloc(sizeof(Nodo)); // é criada uma lista nova
    novoElemento->valor = valor; // adiciona-se o valor a essa nova lista
    novoElemento->prox = NULL; // o apontador tem de ser nulo pq vai ser o ultimo

    if (*lista == NULL) {
        // Se a lista estiver vazia, o novo elemento será o primeiro
        *lista = novoElemento; // ou seja, o apontador da lista vai apontar para o novo elemento
        return;
    }

    LInt atual = *lista; // o apontador da lista atual é o mesmo que o da lista base

    // Percorre a lista até o último elemento
    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    // Ajusta o ponteiro do último elemento para o novo elemento
    atual->prox = novoElemento;
}

// 15

void concatL (LInt *a, LInt b) {
    if(*a) concatL(&((*a)->prox),b);
    else (*a) = b;
}

void concatL2(LInt *a, LInt b) {
    if (*a == NULL) {
        // Se a lista a for vazia, b será o primeiro elemento de a
        *a = b;
    } else {
        LInt atual = *a; // o apontador de uma nova lista tem o mesmo que o apontador da lista a

        // Percorre a lista a até o último elemento
        while (atual->prox != NULL) {
            atual = atual->prox;
        }

        // Acrescenta a lista b ao final da lista a
        atual->prox = b; // basta o ultimo apontador da lista a apontar para o da lista b
    }
}

// 16

LInt cloneL (LInt l) {
    if(!l) return NULL; 
    LInt new = malloc(sizeof(struct lligada));
    new->valor = l->valor;
    new->prox = cloneL(l->prox);
    return new;
}

LInt cloneL2 (LInt l) {
    LInt list = NULL, temp = NULL;
    while(l) {
        LInt new = malloc(sizeof(struct lligada));
        new->valor = l->valor;
        new->prox = NULL;
        if(list == NULL) list = temp = new;
        else temp = temp->prox = new;
        l = l->prox;
    }
    return list;
}

LInt cloneL3(LInt lista) {
    if (lista == NULL) {
        return NULL;
    }

    LInt novaLista = malloc(sizeof(Nodo));
    novaLista->valor = lista->valor;
    novaLista->prox = NULL;

    LInt atual = novaLista;
    lista = lista->prox;

    while (lista != NULL) {
        atual->prox = malloc(sizeof(Nodo));
        atual = atual->prox;
        atual->valor = lista->valor;
        atual->prox = NULL;
        lista = lista->prox;
    }

    return novaLista;
}

// 17

LInt cloneRev (LInt l) {
    if(!l) return NULL;
    int len = length(l);
    LInt array[len];
    for(int i = len - 1; i >= 0; i--) {
        array[i] = malloc(sizeof(struct lligada));
        array[i]->valor = l->valor;
        if(i < len - 1) array[i]->prox = array[i+1];
        else array[i]->prox = NULL;
        l = l->prox;
    }
    return array[0];
}

LInt cloneRev2 (LInt l) {
    LInt list = NULL;
    while(l) {
        LInt new = malloc(sizeof(struct lligada));
        new->valor = l->valor;
        new->prox = list;
        list = new;
        l = l->prox;
    }
    return list;
} 

// 18

int maximo (LInt l) {
    if(!l->prox) return l->valor;
    int m = maximo(l->prox);
    return m > l->valor ? m : l->valor;
}

int maximo2 (LInt l) {
    if (l == NULL) {
        // Retorna um valor mínimo possível caso a lista seja vazia
        return INT_MIN;
    }

    int max = l->valor; // inicialmente o máximo é considerado o primeiro elemento da lista
    l = l->prox; // o apontador avança

    while (l != NULL) { // este ciclo vai ser executado enquanto não chegar ao ultimo elemento da lista
        if (l->valor > max) { // se o valor atual do apontador for maior que o anterior
            max = l->valor; // o valor máximo é atualizado
        }
        l = l->prox; // o apontador avança

    return max;
}

// 19

int take (int n, LInt *l){
    int i = 0;
    for(;i < n && *l; i++, l = &((*l)->prox));
    if(!(*l)) return i;
    for(;*l;) {
        LInt temp = (*l)->prox;
        free(*l);
        *l = temp;
    }
    return n;
}

int take2(int n, LInt *l) {
    if (*l == NULL) {
        // Se a lista for vazia, o comprimento final é 0
        return 0;
    }

    LInt atual = *l; // é criado um apontador que aponta para o primeiro elemento da lista
    int comprimento = 1; // o comprimento é 1 considerando o primeiro elemento da lista, já que não é vazia

    while (comprimento < n && atual->prox != NULL) {
        atual = atual->prox; // o apontador avança
        comprimento++; // o comprimento aumenta
    }

    LInt proximo = atual->prox;
    atual->prox = NULL; // o último elemento antes do corte tem de ter apontador nulo

    /*
    Após alcançar o n-ésimo nó (ou o final da lista), 
    a função corta a ligação entre o n-ésimo nó e os nós subsequentes, 
    garantindo que o n-ésimo nó seja o último nó da lista. 
    Em seguida, a função libera a memória dos nós subsequentes.

    Ao final do processo, a função retorna o comprimento final da lista.
    */
    while (proximo != NULL) {
        LInt temp = proximo;
        proximo = proximo->prox;
        free(temp);
    }

    return comprimento;
}

// 20

int drop (int n, LInt *l) {
    int i;
    for(i = 0; i < n && (*l); i++) {
        LInt temp = (*l);
        (*l) = (*l)->prox;
        free(temp);
    }
    return i;
}

int drop2(int n, LInt *l) {
    int elementosRemovidos = 0; // contador

    while (*l != NULL && elementosRemovidos < n) { // o ciclo é executado até chegar ao ultimo elemento da lista e até n
        LInt temp = *l; // é criado um apontador para o primeiro elemento da lista
        *l = (*l)->prox; // o apontador da lista avança uma casa
        free(temp); // é libertado o elemento anterior ao do apontador da lista
        elementosRemovidos++;
    }

    return elementosRemovidos;
}

// 21

LInt Nforward (LInt l, int N) {
    for(int i = 0; i < N; i++) {
        l = l->prox;
    }
    return l;
}

// 22

int listToArray (LInt l, int v[], int N) {
    int i;
    for(i = 0; i < N && l; l = l->prox) 
    v[i++] = l->valor;
    return i;
}

// 23

LInt arrayToList (int v[], int N) {
    if(N == 0) return NULL;
    LInt new = malloc(sizeof(struct lligada));
    new->valor = (*v);
    new->prox = arrayToList(v + 1, N - 1);
    return new;
}

// 24

LInt somasAcL (LInt l) {
    int sum = 0;
    LInt list = NULL, temp = NULL;
    for(;l; l = l->prox) {
        sum += l->valor; 
        LInt new = malloc(sizeof(struct lligada));
        new->valor = sum; // coloca o valor da soma no novo nodo criado
        new->prox = NULL; // o apontador será nulo 
        if(!list) list = temp = new;
        else temp = temp->prox = new;
    }
    return list;
}

// 25

void remreps(LInt l) {
    if(l) {
        while(l->prox) {
            if(l->prox->valor == l->valor) {
                LInt temp = l->prox;
                l->prox = temp->prox;
                free(temp);
            }
            else l = l->prox;
        }
    }
}

void remreps2(LInt l) {
    if (l == NULL) {
        return; // Retorna se a lista for vazia
    }

    LInt atual = l; // o novo nodo criado tem o mesmo apontador que o da lista
    LInt proximo; // este nodo vai ser comparado com o anterior (atual)

    while (atual != NULL && atual->prox != NULL) {
        proximo = atual->prox; // o proximo tem de estar sempre uma casa à frente

        if (atual->valor == proximo->valor) { 
            atual->prox = proximo->prox; // se os valores forem iguais, ambos avançam uma casa
            free(proximo); // é libertado o valor repetido seguinte
        } else {
            atual = atual->prox; 
        }
    }
}


// 26

LInt rotateL (LInt l) {
    if(!l || !l->prox) return l;
    int len = length(l);
    LInt array[len];
    for(int i = 0; i < len; i++, l = l->prox) array[i] = l;
    array[0]->prox = NULL;
    array[len - 1]->prox = array[0];
    return array[1];
}

LInt rotateL2 (LInt l) {
    if(!l || !(l->prox)) return l;
    LInt temp = l;
    LInt list = l->prox;
    while(temp->prox) temp = temp->prox; 
    temp->prox = l;
    l->prox = NULL;
    return list;
}

LInt rotateL3(LInt l) {
    if (l == NULL || l->prox == NULL) {
        return l; // Retorna a mesma lista se for vazia ou tiver apenas um elemento
    }

    LInt cabeca = l;
    LInt cauda = l;

    while (cauda->prox != NULL) {
        cauda = cauda->prox;
    } // o apontador da cauda vem percorrer até ao final da lista e chegar ao elemento correspondente

    cauda->prox = cabeca->prox; // o apontador da cauda tem de ser o mesmo que o apontador da cabeça
    cabeca->prox = NULL; // e depois colocar o apontador da cabeça nulo já que é o ultimo

    return cauda;
}

// 27

LInt parte(LInt l) {
    if(!l || !l->prox) return NULL;
    LInt newL = l->prox;
    l->prox = l->prox->prox;
    newL->prox = parte(l->prox);
    return newL;
}

LInt parte2 (LInt l) {
    LInt list = NULL, temp = NULL;
    while(l && l->prox) {
        if(!list) list = temp = l->prox;
        else temp = temp->prox = l->prox;
        l = l->prox = l->prox->prox;
        temp->prox = NULL;
    }
    return list;
}

LInt parte3(LInt l) {
    if (l == NULL || l->prox == NULL) {
        return NULL; // Retorna NULL se a lista for vazia ou tiver apenas um elemento
    }

    LInt l_pares = l->prox;
    LInt l_impares = l;

    LInt current_pares = l_pares;
    LInt current_impares = l_impares;

    while (current_pares != NULL && current_pares->prox != NULL) {
        current_impares->prox = current_pares->prox;
        current_impares = current_impares->prox;
        current_pares->prox = current_impares->prox;
        current_pares = current_pares->prox;
    }

    current_impares->prox = NULL;

    return l_pares;
}


typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

// 28

int altura (ABin){
    if(tree == NULL) return 0;
    return 1 + (altura(tree->esq) > altura(tree->dir) ? altura(tree->esq) : altura(tree->dir));
}

// 29

ABin cloneAB (ABin){
    if(tree == NULL) return NULL;
    ABin new = malloc(sizeof(struct nodo));
    new->valor = tree->valor;
    new->esq = cloneAB(tree->esq);
    new->dir = cloneAB(tree->dir);
    return new;
}

// 30

void mirror (ABin *){
    if((*tree)) {
        ABin temp = (*tree)->esq;
        (*tree)->esq = (*tree)->dir;
        (*tree)->dir = temp;
        mirror(&((*tree)->esq));
        mirror(&((*tree)->dir));
    }
}

// 31

void inorderaux(ABin tree, LInt * list) {
    LInt aux;
    if(tree) {
        inorderaux(tree->dir,list);

        aux = malloc(sizeof(struct lligada));
        aux->valor = tree->valor;
        aux->prox = *list;

        *list = aux;

        inorderaux(tree->esq,list);
    }
}

void inorder (ABin tree, LInt * list) {
    *list = NULL;
    inorderaux(tree,list);
}

// 34

int depth(ABin a, int x) {
    if(!a) return -1; // se a árvore for nula

    if(a->valor == x) return 1; // se a raíz for igual ao elemento x

    int esq = depth(a->esq,x); // fazer o mesmo teste para a esquerda 
    int dir = depth(a->dir,x); // ...

    if(esq == -1 && dir == -1) return -1; // se o elemento estiver ao mesmo nível à esquerda e direita retorna -1 pq nao ha menor
    if(esq == -1) return 1 + dir;
    if(dir == -1) return 1 + esq;
    return esq < dir ? 1 + esq : 1 + dir;
}

// 35

int freeAB (ABin a) {
    if(!a) return 0;
    int n = 1 + freeAB(a->esq) + freeAB(a->dir);
    free(a); // dar free à raíz
    return n;
}

// 36

int pruneAB (ABin *a, int l){
    int n;
    if(!(*a)) return 0;
    
    if(l == 0) {
        n = 1 + pruneAB(&((*a)->esq),0) + pruneAB(&((*a)->dir),0);
        free(*a);
        (*a) = NULL;
    }
    else n = pruneAB(&((*a)->esq),l - 1) + pruneAB(&((*a)->dir),l - 1); // vão diminuindo l e seguindo a árvore para baixo e chegaremos à condição de cima
    
    return n;
}

// 37

int iguaisAB (ABin a, ABin b){
    if(!a && b || !b && a) return 0;
    if(!a && !b || a == b) return 1;
    return a->valor == b->valor && iguaisAB(a->esq,b->esq) && iguaisAB(a->dir,b->dir);
}

// 38

LInt concat(LInt a, LInt b) {
    if(!a) return b;
    LInt temp = a;
    while(temp->prox) temp = temp->prox;
    temp->prox = b;
    return a;
}

LInt nivelL (ABin a, int n) {
    if(!a || n < 1) return NULL;
    if(n == 1) {
        LInt new = malloc(sizeof(struct lligada));
        new->valor = a->valor;
        new->prox = NULL;
        return new;
    }
    else return concat(nivelL(a->esq,n - 1),nivelL(a->dir,n - 1));
} 

// 39

int nivelV (ABin a, int n, int v[]) {
    if(!a || n < 1) return 0;
    if(n == 1) {
        *v = a->valor;
        return 1;
    }
    else {
        int e = nivelV(a->esq,n - 1,v);
        int d = nivelV(a->dir,n - 1,v+e);
        return e + d;
    }
}
x   
// 40

int dumpAbin (ABin a, int v[], int N) {
    int e, d;
    if(a && N) {
        e = dumpAbin(a->esq,v,N);
        if(e < N) {
            v[e] = a->valor;
            return 1 + e + dumpAbin(a->dir,v+e+1,N-e-1);
        }
        else return N;
    }
    else return 0;
}

// 41

ABin somasAcA (ABin a) {
    if(!a) return NULL;
    ABin new = malloc(sizeof(struct nodo));
    new->esq = somasAcA(a->esq);
    new->dir = somasAcA(a->dir);
    new->valor = a->valor + (new->esq ? new->esq->valor : 0) + (new->dir ? new->dir->valor : 0);
    return new;
}