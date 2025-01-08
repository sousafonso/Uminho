#include <stdio.h>
#include <string.h>

// 1
int contaVogais (char *s){
    char frase[strlen s];
    int contador;

    for (int i = 0; frase[i] != '\n'; i++){
        if (frase [i] = 'A' || frase [i] = 'E' || frase [i] = 'I' || frase [i] = 'O' || frase [i] = 'U' || frase [i] = 'a' || frase [i] = 'e' || frase [i] = 'i' || frase [i] = 'o' || frase [i] = 'u'){
            contador++;
        }
    }
    return 0;
}

// 2
int retiraVogaisRep (char *s){
    char frase[strlen s];
    int contador;

    for (int j = 0; frase [j] != '\n'; j++){
        if (frase[j] == frase[j+1] && (frase [j] = 'A' || frase [j] = 'E' || frase [j] = 'I' || frase [j] = 'O' || frase [j] = 'U' || frase [j] = 'a' || frase [j] = 'e' || frase [j] = 'i' || frase [j] = 'o' || frase [j] = 'u')){
            frase[j+1] = frase[j+2];
            contador++;
        }
    }
    return 0;
}

// 3
int duplicaVogais (char *s){
    char frase[2 * (int) strlen s];

    for (int k = 0; frase[k] != '\n'; k++){
        if (frase [k] = 'A' || frase [k] = 'E' || frase [k] = 'I' || frase [k] = 'O' || frase [k] = 'U' || frase [k] = 'a' || frase [k] = 'e' || frase [k] = 'i' || frase [k] = 'o' || frase [k] = 'u'){
            // inacabado
        }
    }
}

// 4
int ordenado (int v[], int N){
    for (int i = 0; i < N; i++){
        if (v[i] < v[i++]){
            break;
        }
        else return 1;
    }
    return 0;
}

int partition (int v[], int N, int x){
    int i;
     
    for(i = 0, i<N, i++){
        if (v[i]<x) break;
        else v[n-1] = v[i]; break;
    }
    
    return 0;
}