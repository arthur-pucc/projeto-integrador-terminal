#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_ARGUMENTS 10

int separarArgumentos(char *comando, char *vetor_argumentos[]);

int main() {
    char *comando;
    char *vetor_argumentos[MAX_ARGUMENTS];

    fgets(comando, 100, stdin);

    int contagem_argumentos = separarArgumentos(comando, vetor_argumentos);

    printf("%s", vetor_argumentos[0]);

    return EXIT_SUCCESS;
}
/* Funcao que separa os argumentos imputados pelo usuario no terminal.
  Precisa do comando imputado e um vetor de ponteiros para guardar os argumentos
  Retorna justamente a quantidade de argumentos + 1 (o proprio comando, ex: cat, ajuda, etc.) */
int separarArgumentos(char *comando, char *vetor_argumentos[]) {
    char *argumento = strtok(comando, " "); // Separa pelos 'espaços'
    int contagem_argumentos = 0;

    // Loop while que analisa todos os argumentos
    while (argumento != NULL && contagem_argumentos < MAX_ARGUMENTS) {
        vetor_argumentos[contagem_argumentos] = argumento; // Salva comando / argumento no vetor de ponteiros
        argumento = strtok(NULL, " "); //Avança para próximo argumento
        contagem_argumentos++;
    }

    return contagem_argumentos;
}
