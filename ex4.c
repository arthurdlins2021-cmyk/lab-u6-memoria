#include <stdlib.h>

void aloca(void) {
    int *bloco = (int *) malloc(1000 * sizeof(int));
    if (bloco != NULL) {
        bloco[0] = 1;
        free(bloco);
    }
}

int main(void) {
    aloca();
    return 0;
}
