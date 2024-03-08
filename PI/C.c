#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pedido {
    int numero;
    char dificuldade;
    int preco;
};

int compararPedidos(const void *p1, const void *p2) {
    struct Pedido *pedido1 = (struct Pedido*)p1;
    struct Pedido *pedido2 = (struct Pedido*)p2;
    
    if (pedido1->preco == pedido2->preco) {
        if (pedido1->dificuldade == pedido2->dificuldade) {
            return pedido1->numero - pedido2->numero;
        }
        return pedido1->dificuldade - pedido2->dificuldade;
    }
    return pedido2->preco - pedido1->preco;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1){
        return 1;
    }

    struct Pedido pedidos[n];

    for (int i = 0; i < n; i++) {
        if (scanf("%d %c %d", &pedidos[i].numero, &pedidos[i].dificuldade, &pedidos[i].preco) != 1){
            return 1;
        }
    }

    qsort(pedidos, n, sizeof(struct Pedido), compararPedidos);

    for (int i = 0; i < n; i++) {
        printf("%d %c %d\n", pedidos[i].numero, pedidos[i].dificuldade, pedidos[i].preco);
    }

    return 0;
}

