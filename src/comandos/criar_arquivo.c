#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char nome[100];
    printf("Nome do arquivo: ");
    scanf("%99s", nome);
    FILE *arq = fopen(nome, "w");
    if (arq == NULL) {
        printf("Erro ao criar o arquivo\n");
        return 1;
    }
    char palavra[100];
    int primeira = 1;
    printf("Digite as palavras (digite fim para terminar):\n");
    while (scanf("%99s", palavra) == 1 && strcmp(palavra, "fim") != 0) {
        if (primeira == 0) {
            fprintf(arq, " ");
        }
        fprintf(arq, "%s", palavra);
        primeira = 0;
    }
    fclose(arq);
    printf("Arquivo criado!\n");
    return 0;
}