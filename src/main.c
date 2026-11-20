#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/chooser.h" /* Utiliza o arquivo como biblioteca, sendo possível utilizar os comandos dos arquivos dentro do projeto. */
#include "../include/parser.h"

#define MAX_SIZE 4096
#define MAX_ARGUMENTS 5

int main() {
    while (1) {
        char *vetor_argumentos[MAX_ARGUMENTS];
        char comando[MAX_SIZE];

        fgets(comando, MAX_SIZE, stdin);

        int contagem_argumentos = separarArgumentos(comando, vetor_argumentos, MAX_ARGUMENTS);

        escolherComando(contagem_argumentos, vetor_argumentos);

    }
}
