#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int separarArgumentos(char *comando, char **vetor_argumentos);

int main() {
    char *comando;
    char **vetor_argumentos;

    fgets(comando, 100, stdin);

    separarArgumentos(comando, vetor_argumentos);
}
/* Funcao que separa os argumentos imputados pelo usuario no terminal.
  Precisa do comando imputado e um vetor de ponteiros para guardar os argumentos
  Retorna justamente a quantidade de argumentos + 1 (o proprio comando, ex: cat, ajuda, etc.) */
int separarArgumentos(char *comando, char **vetor_argumentos) {
    char *argumento = strtok(comando, " "); // Separa pelos 'espaços'

    // Loop while que analisa todos os argumentos
    while (argumento != NULL) {
        printf("%s\n", argumento); // Printa próprio argumento
        argumento = strtok(NULL, " "); //Avança para próximo argumento
    }
}
