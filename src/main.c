#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/comandos.h" /* Utiliza o arquivo como biblioteca, sendo possível utilizar os comandos dos arquivos dentro do projeto. */
#include "../include/parser.h"

#define MAX_SIZE 4096
#define MAX_ARGUMENTS 5

int main() {
    while (1) {
        char *vetor_argumentos[MAX_ARGUMENTS];
        char *comando;

        fgets(comando, MAX_SIZE, stdin);

        int contagem_argumentos = separarArgumentos(comando, vetor_argumentos, MAX_ARGUMENTS);

        if (strcmp(vetor_argumentos[0], "cat") == 0) {
            cat(contagem_argumentos, vetor_argumentos);
        } else if (strcmp(vetor_argumentos[0], "sair") == 0) {
            sair();
        }
    }
}
