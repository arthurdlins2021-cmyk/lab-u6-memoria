#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int qtd;
    double *vetor;
    double total = 0.0;

    printf("Quantas notas? ");
    scanf("%d", &qtd);

    vetor = (double *) malloc(qtd * sizeof(double));
    if (vetor == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    for (int idx = 0; idx < qtd; idx++) {
        scanf("%lf", &vetor[idx]);
        total += vetor[idx];
    }

    printf("Media: %.2f\n", total / qtd);

    free(vetor);
    return 0;
}
