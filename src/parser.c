#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Funcao que separa os argumentos imputados pelo usuario no terminal.
  Precisa do comando imputado e um vetor de ponteiros para guardar os argumentos
  Retorna justamente a quantidade de argumentos + 1 (o proprio comando, ex: cat, ajuda, etc.) */
int separarArgumentos(char *comando, char *vetor_argumentos[], int qtde_argumentos_max) {
    int contagem_argumentos = 0;

    comando[strlen(comando) - 1] = '\0';
    int length = strlen(comando); // Necessário pois strlen() é alterado quando joga '\0' para delimitação

    // Error Handler pra argumentos além do limite
    for (int i = 0; i < length; i++) {
        if (contagem_argumentos > qtde_argumentos_max + 1) {
            printf("Quantidade de argumentos invalida.\nQuantidade maxima: %d\n", qtde_argumentos_max);
            exit(EXIT_FAILURE);
        }

        if (comando[i] == '\0') break; // Acaba ao final da string principal do comando
        
        while (comando[i] == ' ') continue; // Ignora espaços seguidos
        
        switch (comando[i]) {
            case '"': // Delimitador na "
                i++;
                vetor_argumentos[contagem_argumentos] = &comando[i];
                
                while (comando[i] != '"') {
                    i++;

                    // Error Handler que identifica se aspas foram fechadas ou não
                    if (comando[i] == '\0') {
                        printf("Entrada invalida.\n");
                        exit(EXIT_FAILURE);
                    }
                }

                break;

            case '\'': // Delimitador na '
                i++;
                vetor_argumentos[contagem_argumentos] = &comando[i];
                
                while (comando[i] != '\'') {
                    i++;
                    
                    // Error Handler que identifica se aspas foram fechadas ou não
                    if (comando[i] == '\0') {
                        printf("Entrada invalida.\n");
                        exit(EXIT_FAILURE);
                    }
                }

                break;

            default: // Delimitador no espaço
                vetor_argumentos[contagem_argumentos] = &comando[i];
                while (comando[i] != ' ' && comando[i] != '\0') i++;
                break;
        }

        contagem_argumentos++;
        comando[i] = '\0'; // Delimitação de cada argumento
    }

    return contagem_argumentos;
}
