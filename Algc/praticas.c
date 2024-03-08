 /*
    AULA SOBRE GRAFOS - ficha 4
 */
 
#include <stdio.h>
#define NV 10

typedef struct aresta {
int dest; int custo;
struct aresta *prox;
} *LAdj, *GrafoL [NV];

typedef int GrafoM [NV][NV];

// ****** 1 ******
void fromM(GrafoM in, GrafoL out){
    int i, j;
    LAdj aux;
    for(i = 0; i < NV; i++){
        aux = out[i];
        for(j = 0; j < NV; j++){
            if(in[i][j] != 0){
                aux->dest = j;
                aux->custo = in[i][j];
                aux = aux->prox;
            }
        }
    }
}

/*
    para cada célula in[i][j], realizamos uma série de operações de tempo constante. 
    Como temos NV^2 células, a complexidade de tempo total é O(NV^2).
*/

// ****** 2 ******
void inverte(GrafoL GL, GrafoL GL_invertido) {
    int i;
    LAdj aux;
    for(i = 0; i < NV; i++) {
        aux = GL[i];
        while(aux != NULL) {
            aux->dest = i;
            aux = aux->prox;
        }
    }
}

/*
    O (V + E) vezes, onde V é o número de vértices e E é o número de arestas.
*/

// ****** 3 ******
int inDegree (GrafoL g){
    int i, j, count = 0;
    LAdj aux;
    for(i = 0; i < NV; i++){ // V vezes
        aux = g[i];
        while(aux != NULL){ // V + E vezes
            count++;
            aux = aux->prox;
        }
    }
    return count;
}

/*
    O algoritmo percorre todos os vértices do grafo, e para cada vértice percorre todas as arestas que partem desse vértice. 
    Assim, a complexidade de tempo é O(V (V + E)).
*/

// ****** 4 ******
int colorOK(GrafoL g, int cor[]) {
    int i, j;
    LAdj aux;
    
    for (i = 0; i < NV; i++) {
        aux = g[i];
        while (aux != NULL) {
            int v = i; // current vertex
            int u = aux->dest; // adjacent vertex
            
            if (cor[v] == cor[u]) {
                return 0; // invalid coloring
            }
            
            aux = aux->prox;
        }
    }
    
    return 1; // valid coloring
}

/*
    Relativamente à procura, associamos o valor 0 para não visitado, 1 para visitado e -1 para atualmente a ser visitado.
    Vertices adjacentes são aqueles que estão ligados por uma aresta.
    Associamos a variável or à origem e a variável dest ao destino. Associamos tmb o array v aos visitados, o array l
    aos comprimentos e o array p aos pais.
*/

int DF (GrafoL g, int or, int v[], int p[], int l[]){
    int i;
    for (i=0; i<NV; i++) { // são iniciados os arrays
        v[i]= 0;
        p[i] = -1;
        l[i] = -1;
    }
    p[or] = -1; l[or] = 0;
    return DFRec (g, or,v,p,1);
}

int DFRec (GrafoL g, int or, int v[], int p[], int l[]){
    int i; LAdj a;
    i = 1;
    v[or] = -1;
    for (a=g[or]; a!=NULL; a=a->prox) {
        if (v[a->dest] == 0) {
            p[a->dest] = or;
            l[a->dest] = l[or] + 1;
            i = i + DFRec (g, a->dest, v, p, l);
        }
    }
}

int componentes (GrafoL g, int c[]){
    int i, r, v[NV], p[NV], l[NV], j;
    for (i=0; i<NV; i++) c[i] = -1;
    for (i = 0, i < N, i++) {
        if (c[i] == -1) {
            DF (g, i, v, p, l);
            for (j = 0; j < N; j++) {
                if (v[j] == 1) {cd
                
                    c[j] = r;
                }
            }
            r++;
        }
    }
    return r;
}

int maisLonga (GrafoL g, int or, int p[]){
    int i, v[NV], l[NV], m = or, p[NV], r;
    DF (g, or, v, p, l);
    for (i = 0; i < NV; i++) {
        if (l[i] > l[m]) {
            m = i;
        }
    }
    r = l[m];
    while (m!=-1) {
        p[l[m]] = m;
        m = p[m];
    }
    return r;
}

/**
 * @brief     Os primeiros dois ciclos for calculam para todos os vértices
 *            o pai inDegree
 *            O 4 ciclo seleciona os que têm inDegree 0 e colocá-los na fila (queue)
 *            O ultimo ciclo while, enquanto a queue nao for vazia, retir ao vertice v e acrescente a ord
 *            para todos os subjacentes a v, se inDegree for 0, acrescentar à queue
*/
void ordTop (GrafoL g, int ord[]){
    int inD [NV], i, frente, fim;
    LAdj a;
    for (i = 0; i < NV; i++) {
        inD[i] = 0;
    }
    for (i = 0; i < NV; i++) {
        for (a = g[i]; a != NULL; a = a->prox) {
            inD[a->dest]++;
        }
    }
    frente = 0; fim = 0;
    for (i = 0; i < NV; i++) {
        if (inD[i] == 0) {
            ord[fim++] = i;
        }
    }
    while (frente != fim) {
        int v = ord[frente++];
        for (a = g[v]; a != NULL; a = a->prox) {
            int u = a->dest;
            inD[u]--;
            if (inD[u] == 0) {
                ord[fim++] = u;
            }
        }
    }
}

/*

    COPILOT VERSION

void ordTop(GrafoL g, int ord[]) {
    int indegree[NV] = {0}; // array to store the indegree of each vertex
    int queue[NV]; // queue to store vertices with indegree 0
    int front = 0, rear = 0; // front and rear pointers for the queue
    int count = 0; // count of visited vertices
    
    // Calculate the indegree of each vertex
    for (int i = 0; i < NV; i++) {
        LAdj aux = g[i];
        while (aux != NULL) {
            indegree[aux->dest]++;
            aux = aux->prox;
        }
    }
    
    // Enqueue vertices with indegree 0
    for (int i = 0; i < NV; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }
    
    // Perform topological sorting
    while (front != rear) {
        int v = queue[front++];
        ord[count++] = v; // add vertex to the topological ordering
        
        // Decrease the indegree of adjacent vertices
        LAdj aux = g[v];
        while (aux != NULL) {
            int u = aux->dest;
            indegree[u]--;
            
            // Enqueue vertices with indegree 0
            if (indegree[u] == 0) {
                queue[rear++] = u;
            }
            
            aux = aux->prox;
        }
    }
}
*/

int dijkstraSP (GrafoL g, int or, int dest, int p[], int l[]){
    int i, v[NV], min, minV;
    for (i = 0; i < NV; i++) {
        v[i] = 0;
        p[i] = -1;
        l[i] = -1;
    }
    p[or] = -1; l[or] = 0;
    while (1) {
        min = -1;
        for (i = 0; i < NV; i++) {
            if (v[i] == 0 && l[i] != -1) {
                if (min == -1 || l[i] < min) {
                    min = l[i];
                    minV = i;
                }
            }
        }
        if (min == -1) {
            break;
        }
        v[minV] = 1;
        for (LAdj a = g[minV]; a != NULL; a = a->prox) {
            int u = a->dest;
            if (v[u] == 0) {
                if (l[u] == -1 || l[minV] + a->custo < l[u]) {
                    l[u] = l[minV] + a->custo;
                    p[u] = minV;
                }
            }
        }
    }
    return l[dest];
}

/**
 * @brief     excentricidade - mais longe do centro
 *            calcula a maior distância do centro
*/
int excentricidadeV (GrafoL g, int v){
    int i, p[NV], l[NV], max = 0;
    for (i = 0; i < NV; i++) {
        int d = dijkstraSP (g, v, i, p, l);
        if (d > max) {
            max = d;
        }
    }
    return max;
}


int floydWarshal (GrafoM g, int p[][NV]){
    int i, j, k;
    for (i = 0; i < NV; i++) {
        for (j = 0; j < NV; j++) {
            p[i][j] = -1;
        }
    }
    for (i = 0; i < NV; i++) {
        for (j = 0; j < NV; j++) {
            if (g[i][j] != 0) {
                p[i][j] = i;
            }
        }
    }
    for (k = 0; k < NV; k++) {
        for (i = 0; i < NV; i++) {
            for (j = 0; j < NV; j++) {
                if (g[i][k] != 0 && g[k][j] != 0) {
                    if (g[i][j] == 0 || g[i][k] + g[k][j] < g[i][j]) {
                        g[i][j] = g[i][k] + g[k][j];
                        p[i][j] = p[k][j];
                    }
                }
            }
        }
    }
}
/**
 * @brief     diametro - maior excentricidade
*/

int diametro (GrafoL g){
    int i, max = 0;
    for (i = 0; i < NV; i++) {
        int e = excentricidadeV (g, i);
        if (e > max) {
            max = e;
        }
    }
    return max;
}

/*
    SLIDES
*/

typedef int Elem;

typedef struct {
    int used;
    int size;
    Elem *value;
} Heap;

void initHeap (Heap *h, int size){
    h->used = 0;
    h->size = size;
    h->value = malloc (sizeof (Elem) * size);
}

int insertHeap (Heap *h, Elem x){
    if (h->used == h->size) {
        h->size *= 2;
        h->value = realloc (h->value, sizeof (Elem) * h->size);
    }
    h->value[h->used] = x;
    h->used++;
    return h->used - 1;
}

int extractMin (Heap *h, Elem *x){
    if (h->used == 0) {
        return 0;
    }
    int i, min = 0;
    for (i = 1; i < h->used; i++) {
        if (h->value[i] < h->value[min]) {
            min = i;
        }
    }
    *x = h->value[min];
    h->value[min] = h->value[h->used - 1];
    h->used--;
    return 1;
}

int minHeapOK (Heap *h){
    int i;
    for (i = 0; i < h->used; i++) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < h->used && h->value[l] < h->value[i]) {
            return 0;
        }
        if (r < h->used && h->value[r] < h->value[i]) {
            return 0;
        }
    }
    return 1;
}

