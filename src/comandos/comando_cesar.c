#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int deslocar(char caractere, int deslocamento);
static int converterStringParaInt(char *numero);

int cesar(int contagem_argumentos, char *vetor_argumentos[]) {
    const char *modo = vetor_argumentos[1]; // Aceita APENAS cifrar/decifrar.
    const char *tipo = vetor_argumentos[2]; // Aceita APENAS -t/-f.
    char *conteudo = vetor_argumentos[3]; // Traz o texto a ser transformado ou o nome do arquivo para transformar
    int deslocamento = converterStringParaInt(vetor_argumentos[4]);

    if (contagem_argumentos != 5) {
        printf("Quantidade de argumentos invalida.");
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

    if (strcmp(tipo, "-t") == 0) {
        int i = 0;
        
        while (conteudo[i] != '\0') {
            conteudo[i] = deslocar(conteudo[i], deslocamento);
            i++;
        }

        printf("%s\n", conteudo);
    } else if (strcmp(tipo, "-f") == 0) { // Aqui, 'conteudo' é o NOME do arquivo que será lido.
        FILE *arquivo_origem = fopen(conteudo, "r");

        if (arquivo_origem == NULL) {
            perror("Erro ao tentar ler arquivo.");
            return EXIT_FAILURE;
        }

        int caractere;
        char *nome_arquivo_destino;
        
        if (strcmp(modo, "cifrar") == 0) {
            nome_arquivo_destino = strcat(conteudo, ".cifrado");
        } else {
            nome_arquivo_destino = strcat(conteudo, ".decifrado");
        }

        FILE *arquivo_destino = fopen(nome_arquivo_destino, "w");

        if (arquivo_destino == NULL) {
            if (strcmp(modo, "cifrar") == 0) {
                perror("Erro ao tentar criar arquivo cifrado.");
                return EXIT_FAILURE;
            } else {
                perror("Erro ao tentar criar arquivo decifrado.");
                return EXIT_FAILURE;

            }
        }
        
        while ((caractere = deslocar(fgetc(arquivo_origem), deslocamento)) != EOF) {
            fputc(caractere, arquivo_destino);
        }

        if (fclose(arquivo_origem) != 0) {
            perror("Erro ao fechar arquivo origem.");
            return EXIT_FAILURE;
        }

        if (fclose(arquivo_destino) != 0) {
            perror("Erro ao fechar arquivo destino.");
            return EXIT_FAILURE;
        }

        printf("Arquivo %s criado!\n", nome_arquivo_destino);
    } else {
        printf("Argumento invalido.\n");
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
        
        if (digito < '0' || digito > '9') {
            printf("Parametro nao e um numero valido.\n");
            return EXIT_FAILURE;
        }

        numero_convertido = numero_convertido * 10;
        numero_convertido = numero_convertido + digito - '0';

        i++;
    }

    return numero_convertido;
}
