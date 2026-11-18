#include <stdio.h>
#include <stdlib.h>

int *cria_sequencia(int n) {
    int *lista = (int *) malloc(n * sizeof(int));
    if (lista == NULL) {
        return NULL;
    }

    for (int k = 0; k < n; k++) {
        lista[k] = k + 1;
    }

    return lista;
}

int main(void) {
    int tamanho = 5;
    int *numeros = cria_sequencia(tamanho);

    if (numeros == NULL) {
        return 1;
    }

    for (int k = 0; k < tamanho; k++) {
        printf("%d", numeros[k]);
        if (k < tamanho - 1) {
            printf(" ");
        }
    }
    printf("\n");

    free(numeros);
    return 0;
}
