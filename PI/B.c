#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_COZINHEIROS 1000 // Define o número máximo de cozinheiros

typedef struct Cozinheiro { // Define a estrutura Cozinheiro
    char alcunha[100]; // String para a alcunha do cozinheiro
    int peso; // Peso do cozinheiro em kg
    int altura; // Altura do cozinheiro em cm
} Cozinheiro;

// Função para comparar dois cozinheiros de acordo com os critérios do grande Passadini
int comparar_cozinheiros(const void* a, const void* b) {
    Cozinheiro* cozinheiro_a = (Cozinheiro*) a; // Converte o ponteiro void* para Cozinheiro*
    Cozinheiro* cozinheiro_b = (Cozinheiro*) b; // Converte o ponteiro void* para Cozinheiro*

    // Compara os pesos dos cozinheiros
    if (abs(cozinheiro_a->peso - 90) < abs(cozinheiro_b->peso - 90)) {
        return -1; // Retorna -1 se o primeiro cozinheiro estiver mais próximo do peso ideal
    } else if (abs(cozinheiro_a->peso - 90) > abs(cozinheiro_b->peso - 90)) {
        return 1; // Retorna 1 se o segundo cozinheiro estiver mais próximo do peso ideal
    }

    // Compara as alturas dos cozinheiros
    if (cozinheiro_a->altura > cozinheiro_b->altura) {
        return -1; // Retorna -1 se o primeiro cozinheiro for mais alto
    } else if (cozinheiro_a->altura < cozinheiro_b->altura) {
        return 1; // Retorna 1 se o segundo cozinheiro for mais alto
    }

    // Compara as alcunhas dos cozinheiros (em ordem alfabética)
    return strcmp(cozinheiro_a->alcunha, cozinheiro_b->alcunha);
}

int main() {
    Cozinheiro cozinheiros[MAX_COZINHEIROS]; // Cria um array de cozinheiros
    int num_cozinheiros; // Variável para armazenar o número de cozinheiros
    if (scanf("%d", &num_cozinheiros) != 1){
        return 1;
    } // Lê o número de cozinheiros

    // Lê as informações de cada cozinheiro
    for (int i = 0; i < num_cozinheiros; i++) {
        if (scanf("%s %d %d", cozinheiros[i].alcunha, &cozinheiros[i].peso, &cozinheiros[i].altura) != 1){
            return 1;
        }
    }

    // Ordena os cozinheiros de acordo com os critérios do grande Passadini
    qsort(cozinheiros, num_cozinheiros, sizeof(Cozinheiro), comparar_cozinheiros);

    // Imprime os cozinheiros ordenados
    for (int i = 0; i < num_cozinheiros; i++) {
        printf("%s %d %d\n", cozinheiros[i].alcunha, cozinheiros[i].peso, cozinheiros[i].altura);
    }

    return 0; // Retorna 0
}

