#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int criar(int contagem_argumentos, char *vetor_argumentos[]) {
    if (contagem_argumentos > 3) {
        printf("Quantidade de argumentos excedida.\n");
        return EXIT_FAILURE;
    }

    if (strchr(vetor_argumentos[1], '/') != NULL || strchr(vetor_argumentos[1], '\\') != NULL) {
        printf("Nome do arquivo invalido. Nao deve conter '/' ou '\\'.\n");
        return EXIT_FAILURE;
    }

    FILE *arq = fopen(vetor_argumentos[1], "w");

    if (arq == NULL) {
        perror(strcat("Erro ao criar arquivo '", strcat(vetor_argumentos[1], "'.")));
        return EXIT_FAILURE;
    }

    fprintf(arq, "%s", vetor_argumentos[2]);

    if (fclose(arq) != 0) {
        perror(strcat("Erro ao fechar '", strcat(vetor_argumentos[1], "'.")));
        return EXIT_FAILURE;
    }

    printf("Arquivo '%s' criado!\n", vetor_argumentos[1]);

    return EXIT_SUCCESS;
}