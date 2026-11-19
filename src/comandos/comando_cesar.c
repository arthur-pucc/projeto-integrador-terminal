#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int deslocar(char caractere, int deslocamento);
static int converterStringParaInt(char *numero);

int cesar(int contagem_argumentos, char *vetor_argumentos[]) {
    const char *modo = vetor_argumentos[1]; // Aceita APENAS cifrar/decifrar.
    const char tipo = vetor_argumentos[2][1]; // Aceita APENAS -t/-f. // Acessa ultimo caractere (o [1]) para facilitar comparação (evita usar a funcao strcmp)
    char *conteudo = vetor_argumentos[3];
    int deslocamento = converterStringParaInt(vetor_argumentos[4]);

    if (contagem_argumentos > 5) {
        printf("Quantidade de argumentos excedida.");
        return EXIT_FAILURE;
    }
    
    if (deslocamento < 0 || deslocamento > 25) {
        printf("Deslocamento aplicado invalido.");
        return EXIT_FAILURE;
    }
    
    // Inverte sinal do deslocamento quando é decifrar.
    if (strcmp(modo, "decifrar") == 0) {
        deslocamento = deslocamento * -1;
    } else if (strcmp(modo, "cifrar") != 0) {
        printf("Comando Invalido");
        return EXIT_FAILURE;
    }

    if (tipo == 't') {
        int i = 0;
        
        while (conteudo[i] != '\0') {
            conteudo[i] = deslocar(conteudo[i], deslocamento);
            i++;
        }

        printf("%s\n", conteudo);
    } else if (tipo == 'f') {
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
        const int digito = numero[i];
        
        numero_convertido = numero_convertido * 10;
        numero_convertido = numero_convertido + digito - '0';

        i++;
    }

    return numero_convertido;
}
