#include <stdio.h>
#include <stdlib.h>

int ec(int contagem_argumentos, char *vetor_argumentos[]) {
    if (contagem_argumentos == 1) {
        fprintf(stderr, "ec: informe ao menos um texto\n");
        fprintf(stderr, "Uso: ec <texto> [texto ...]\n");
        return EXIT_FAILURE;
    }

    for (int i = 1; i < contagem_argumentos; i++) {
        printf("%s", vetor_argumentos[i]);
        if (i < contagem_argumentos - 1) printf(" ");
    }

    printf("\n");

    return EXIT_SUCCESS;
}
