#include <stdio.h>
#include <stdlib.h>

int comando_cat(const char *nome_arquivo){
    FILE *arq = fopen(nome_arquivo, "r");

    if(arq == NULL){
        printf("arquivo nao encontrado\n");
        return EXIT_FAILURE;
    }

    int c;
    while((c = fgetc(arq)) != EOF){
        printf("%c", c);
    }

    if(fclose(arq) != 0){
        perror("Erro ao fechar o arquivo");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}