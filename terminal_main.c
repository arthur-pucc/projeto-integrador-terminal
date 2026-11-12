#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
        }
    }
}
