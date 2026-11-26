#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int criar(int contagem_argumentos, char *vetor_argumentos[]) {
    if (contagem_argumentos > 3) {
        fprintf(stderr, "criar: quantidade de argumentos excedida\n");
        fprintf(stderr, "Textos com espacos devem ficar entre aspas\n");
        fprintf(stderr, "Uso: criar <nome_arquivo> <texto>\n");
        return EXIT_FAILURE;
    } else if (contagem_argumentos < 3) {
        fprintf(stderr, "criar: informe o nome do arquivo e o texto\n");
        fprintf(stderr, "Uso: criar <nome_arquivo> <texto>\n");
        return EXIT_FAILURE;
    }

    char *nome_arquivo = vetor_argumentos[1];
    char *conteudo = vetor_argumentos[2];

    if (strchr(nome_arquivo, '/') != NULL || strchr(nome_arquivo, '\\') != NULL) {
        fprintf(stderr, "criar: %s: nome do arquivo nao deve conter '/' ou '\\'\n", nome_arquivo);
        return EXIT_FAILURE;
    }

    FILE *arquivo = fopen(nome_arquivo, "w");

    if (arquivo == NULL) {
        fprintf(stderr, "criar: %s: nao foi possivel criar o arquivo: %s\n", nome_arquivo, strerror(errno));
        return EXIT_FAILURE;
    }

    fprintf(arquivo, "%s", conteudo);

    if (fclose(arquivo) != 0) {
        fprintf(stderr, "criar: %s: nao foi possivel gravar o arquivo: %s\n", nome_arquivo, strerror(errno));
        return EXIT_FAILURE;
    }

    printf("Arquivo '%s' criado!\n", nome_arquivo);

    return EXIT_SUCCESS;
}
