#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int deslocar(char caractere, int deslocamento);
static int converterStringParaInt(char *numero);

int cesar(int contagem_argumentos, char *vetor_argumentos[]) {
    if (contagem_argumentos > 5) {
        perror("Quantidade de argumentos excedida.");
        return EXIT_FAILURE;
    }
    
    int deslocamento = converterStringParaInt(vetor_argumentos[4]);
    
    if (deslocamento < 0 || deslocamento > 25) {
        perror("Deslocamento aplicado invalido.");
        return EXIT_FAILURE;
    }
    
    if (strcmp(vetor_argumentos[1], "decifrar") == 0) {
        deslocamento = deslocamento * -1;
    } else if (strcmp(vetor_argumentos[1], "cifrar") == 0) {
    } else {
        perror("Comando Invalido");
        return EXIT_FAILURE;
    }

    if (vetor_argumentos[2][1] == 't') {
        char *texto = vetor_argumentos[3];
        int i = 0;
        
        while (texto[i] != '\0') {
            texto[i] = deslocar(texto[i], deslocamento);
            i++;
        }

        printf("%s\n", texto);
    } else if (vetor_argumentos[2][1] == 'f') {
        // funcao para arquivo
    } else {
        perror("Argumento invalido");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

static int deslocar(char caractere, int deslocamento) {
    deslocamento = (deslocamento % 26) + 26;
    int base;

    if (caractere >= 'a' && caractere <= 'z') {
        base = 'a';
    } else if (caractere >= 'A' && caractere <= 'Z') {
        base = 'A';
    } else {
        return caractere;
    }

    return base + ((caractere - base + deslocamento) % 26);
}

static int converterStringParaInt(char *numero) {
    int i = 0;

    int numero_convertido = 0;

    while (numero[i] != '\0') {
        int digito = numero[i];
        
        numero_convertido = numero_convertido * 10;
        numero_convertido = numero_convertido + digito - '0';

        i++;
    }

    return numero_convertido;
}
