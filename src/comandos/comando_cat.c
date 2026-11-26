#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

static int lerArquivo(const char *nome_arquivo);

int cat(int contagem_argumentos, char *vetor_argumentos[]) {
    if (contagem_argumentos == 1) {
        fprintf(stderr, "cat: informe pelo menos um arquivo\n");
        fprintf(stderr, "Uso: cat <arquivo> [arquivo ...]\n");
        return EXIT_FAILURE;
    }

    for (int i = 1; i < contagem_argumentos; i++) {
        lerArquivo(vetor_argumentos[i]);
    }

    printf("\n");

    return EXIT_SUCCESS;
}

static int lerArquivo(const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "r");

    if (arquivo == NULL) {
        fprintf(stderr, "cat: %s: nao foi possivel abrir o arquivo: %s\n", nome_arquivo, strerror(errno));
        return EXIT_FAILURE;
    }

    int caractere;
    while ((caractere = fgetc(arquivo)) != EOF) {
        printf("%c", caractere);
    }

    if (ferror(arquivo)) {
        fprintf(stderr, "cat: %s: nao foi possivel ler o arquivo: %s\n", nome_arquivo, strerror(errno));
        return EXIT_FAILURE;
    }

    if (fclose(arquivo) != 0) {
        fprintf(stderr, "cat: %s: nao foi possivel fechar o arquivo: %s\n", nome_arquivo, strerror(errno));
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
