#include <stdio.h>
#include <stdlib.h>

typedef struct pedido {
    int numero;
    int tempo_pronto;
    int tempo_confeccao;
    int lucro;
} Pedido;

int cmpfunc(const void *a, const void *b) {
    Pedido *pedido_a = (Pedido *)a;
    Pedido *pedido_b = (Pedido *)b;
    return pedido_a->tempo_pronto - pedido_b->tempo_pronto;
}

int main() {
    int n;
    scanf("%d", &n);

    Pedido *pedidos = malloc(n * sizeof(Pedido));
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &pedidos[i].numero, &pedidos[i].tempo_pronto, &pedidos[i].tempo_confeccao, &pedidos[i].lucro);
    }

    qsort(pedidos, n, sizeof(Pedido), cmpfunc);

    int tempo_atual = 0;
    int lucro_total = 0;
    for (int i = 0; i < n; i++) {
        if (pedidos[i].tempo_pronto >= tempo_atual + pedidos[i].tempo_confeccao) {
            tempo_atual += pedidos[i].tempo_confeccao;
            lucro_total += pedidos[i].lucro;
        }
    }

    printf("%d\n", lucro_total);
    free(pedidos);
    return 0;
}
