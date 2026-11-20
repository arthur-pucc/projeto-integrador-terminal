#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/comandos.h"

int escolherComando(int contagem_argumentos, char *vetor_argumentos[]) {
    char *comando = vetor_argumentos[0];

    if (strcmp(comando, "") == 0) {
        return EXIT_SUCCESS;
    } else if (comando, "ajuda") == 0) {
       ajuda(contagem_argumentos, vetor_argumentos);
    } else if (comando, "sair") == 0) {
        sair();
    } else if (comando, "ec") == 0) {
        ec(contagem_argumentos, vetor_argumentos);
    } else if (comando, "criar") == 0) {
       criar(contagem_argumentos, vetor_argumentos);
    } else if (comando, "cat") == 0) {
        cat(contagem_argumentos, vetor_argumentos);
    } else if (comando, "cesar") == 0) {
        cesar(contagem_argumentos, vetor_argumentos);
    } else {
        printf("Comando invalido.");
        return EXIT_FAILURE;
    }

}
