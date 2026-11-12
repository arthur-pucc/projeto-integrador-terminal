#include <stdio.h>
#include <stdlib.h>
#include <string.h>
<<<<<<< HEAD
#include "comandos_cli.h" /* Utiliza o arquivo como biblioteca, sendo possível utilizar os comandos dos arquivos dentro do projeto. */

#define True 1
#define False 0
#define MAX_SIZE 4096

int main() {
    while (True) {
        char comando[MAX_SIZE];

        fgets(comando, sizeof(comando), stdin);

        char *argumentos = strtok(comando, " "); /* Divide string 'comando' por espaço, conseguindo separar os argumentos. */
        argumentos = strtok(NULL, " "); /* Ignora primeiro elemento da separação, que é o próprio comando (cat, ajuda, etc.) */

        if (strncmp(comando, "cat", 3) == 0) {
            while (argumentos != NULL) {
                argumentos[strlen(argumentos) - 1] = '\0';

                comando_cat(argumentos);

                argumentos = strtok(NULL, " ");
            }
=======
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
        } else {
            printf("%s", vetor_argumentos[0]);
>>>>>>> test/parser
        }
    }
}
