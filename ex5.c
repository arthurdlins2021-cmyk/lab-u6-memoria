#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *v = (int *) malloc(5 * sizeof(int));
    if (v == NULL) {
        return 1;
    }

    v[0] = 10;
    v[1] = 20;
    v[2] = 30;
    v[3] = 40;
    v[4] = 50;

    printf("%d\n", v[2]);

    free(v);
    v = NULL;

    return 0;
}
