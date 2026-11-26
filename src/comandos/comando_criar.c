#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int criar(int contagem_argumentos, char *vetor_argumentos[]) {
    if (contagem_argumentos > 3) {
        printf("Quantidade de argumentos excedida.\n");
        return EXIT_FAILURE;
    }

    char *nome_arquivo = vetor_argumentos[1];
    char *conteudo = vetor_argumentos[2];

    if (strchr(nome_arquivo, '/') != NULL || strchr(nome_arquivo, '\\') != NULL) {
        printf("Nome do arquivo invalido. Nao deve conter '/' ou '\\'.\n");
        return EXIT_FAILURE;
    }

    FILE *arq = fopen(nome_arquivo, "w");

    if (arq == NULL) {
        perror(strcat("Erro ao criar arquivo '", strcat(nome_arquivo, "'.")));
        return EXIT_FAILURE;
    }

    fprintf(arq, "%s", conteudo);

    if (fclose(arq) != 0) {
        perror(strcat("Erro ao fechar '", strcat(nome_arquivo, "'.")));
        return EXIT_FAILURE;
    }

    printf("Arquivo '%s' criado!\n", nome_arquivo);

    return EXIT_SUCCESS;
}
