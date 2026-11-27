#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "../include/chooser.h" /* Utiliza o arquivo como biblioteca, sendo possível utilizar os comandos dos arquivos dentro do projeto. */
#include "../include/parser.h"

#define MAX_SIZE 4096
#define MAX_ARGUMENTS 20

int main() {
    while (1) {
        char *vetor_argumentos[MAX_ARGUMENTS];
        char comando[MAX_SIZE];

        if (fgets(comando, MAX_SIZE, stdin) == NULL) {
            if (ferror(stdin)) { // Trata erros incomuns
                fprintf(stderr, "terminal: erro ao ler entrada: %s\n", strerror(errno));
                return EXIT_FAILURE;
            }
            printf("\n"); // Trata CTRL + D
            return EXIT_SUCCESS;
        }
        

        if (comando[0] == '\n') {
            continue; // Ignora Enters puros, evitando Segmentation Fault com fget vazio
        } else if (comando[strlen(comando) - 1] == '\n') {
            comando[strlen(comando) - 1] = '\0';
        }

        int contagem_argumentos = separarArgumentos(comando, vetor_argumentos, MAX_ARGUMENTS);

        if (contagem_argumentos < 1) continue;

        escolherComando(contagem_argumentos, vetor_argumentos);
    }
}
