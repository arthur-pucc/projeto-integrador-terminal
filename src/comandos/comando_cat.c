#include <stdio.h>
#include <stdlib.h>

static int lerArquivo(const char *nome_arquivo);

int cat(int contagem_argumentos, char *vetor_argumentos[]) {
    for (int i = 1; i < contagem_argumentos; i++) {
        lerArquivo(vetor_argumentos[i]);
    }
}

static int lerArquivo(const char *nome_arquivo) {
    FILE *arq = fopen(nome_arquivo, "r");

    if (arq == NULL) {
        perror("Arquivo nao encontrado.\n");
        return EXIT_FAILURE;
    }
    
    int caractere;
    while ((caractere = fgetc(arq)) != EOF) {
        printf("%c", caractere);
    }

    printf("\n");

    if (fclose(arq) != 0) {
        perror("Erro ao fechar o arquivo");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
