#include <stdio.h>

int proximo_id(void) {
    static int atual = 0;
    atual = atual + 1;
    return atual;
}

int main(void) {
    int cont = 0;
    while (cont < 5) {
        printf("%d", proximo_id());
        if (cont < 4) {
            printf(" ");
        }
        cont++;
    }
    printf("\n");
    return 0;
}
