#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cesar(char *tipo, char* modo, char *conteudo, int deslocamento) {
    if (deslocamento < 0 || deslocamento > 25) {
        printf("Deslocamento imputado invalido. Utilize entre 0 e 25.");
        return EXIT_FAILURE;
    }
    
    switch (modo[1]) {
        case 't':
            int i = 0;
            while (i < 3) {
                conteudo[i] = conteudo[i] + deslocamento;
                i++;
            }
            break;

        /* case 'f':
            FILE *arq = fopen(conteudo, "w");

            if (arq == NULL) {
                perror("Arquivo nao encontrado.\n");
                return EXIT_FAILURE;
            }

            int caractere;
            while ((caractere = fgetc(arq)) != EOF) {
                fprintf(arq, "%c", caractere + deslocamento);
            }

            if (fclose(arq) != 0) {
                perror("Erro ao fechar o arquivo");
                return EXIT_FAILURE;
            }
            break; */
    }
}
