#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define TAMANHO_MAX_NOME_ARQUIVO 256

static int deslocar(char caractere, int deslocamento);
static int converterStringParaInt(char *numero, int *resultado);

int cesar(int contagem_argumentos, char *vetor_argumentos[]) {
    if (contagem_argumentos != 5) {
        fprintf(stderr, "cesar: quantidade de argumentos invalida\n");
        fprintf(stderr, "Uso: cesar <cifrar|decifrar> <-t texto | -f arquivo> <deslocamento>\n");
        return EXIT_FAILURE;
    }
    
    const char *modo = vetor_argumentos[1]; // Aceita APENAS cifrar/decifrar.
    const char *tipo = vetor_argumentos[2]; // Aceita APENAS -t/-f.
    char *conteudo = vetor_argumentos[3]; // Traz o texto a ser transformado ou o nome do arquivo para transformar
    int deslocamento;

    if (converterStringParaInt(vetor_argumentos[4], &deslocamento) == EXIT_FAILURE) return EXIT_FAILURE;

    if (deslocamento < 0 || deslocamento > 25) {
        fprintf(stderr, "cesar: %d: deslocamento deve estar entre 0 e 25\n", deslocamento);
        return EXIT_FAILURE;
    }
    
    // Inverte sinal do deslocamento quando é decifrar.
    if (strcmp(modo, "decifrar") == 0) {
        deslocamento = deslocamento * -1;
    } else if (strcmp(modo, "cifrar") != 0) {
        fprintf(stderr, "cesar: %s: modo invalido\n", modo);
        fprintf(stderr, "Uso: cesar <cifrar|decifrar> <-t texto | -f arquivo> <deslocamento>\n");
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
            fprintf(stderr, "cesar: %s: nao foi possivel abrir o arquivo: %s\n", conteudo, strerror(errno));
            return EXIT_FAILURE;
        }

        int caractere;
        char nome_arquivo_destino[TAMANHO_MAX_NOME_ARQUIVO];
        
        if (strcmp(modo, "cifrar") == 0) {
            snprintf(nome_arquivo_destino, TAMANHO_MAX_NOME_ARQUIVO, "%s.cifrado", conteudo);
        } else {
            snprintf(nome_arquivo_destino, TAMANHO_MAX_NOME_ARQUIVO, "%s.decifrado", conteudo);
        }

        FILE *arquivo_destino = fopen(nome_arquivo_destino, "w");

        if (arquivo_destino == NULL) {
            fprintf(stderr, "cesar: %s: nao foi possivel criar o arquivo: %s\n", nome_arquivo_destino, strerror(errno));
            return EXIT_FAILURE;
        }
        
        while ((caractere = deslocar(fgetc(arquivo_origem), deslocamento)) != EOF) {
            fputc(caractere, arquivo_destino);
        }
        
        if (ferror(arquivo_origem)) {
            fprintf(stderr, "cesar: %s: nao foi possivel ler o arquivo: %s\n", conteudo, strerror(errno));
            return EXIT_FAILURE;
        }

        if (ferror(arquivo_destino)) {
            fprintf(stderr, "cesar: %s: nao foi possivel gravar o aquivo: %s\n", nome_arquivo_destino, strerror(errno));
            return EXIT_FAILURE;
        }

        if (fclose(arquivo_origem) != 0) {
            fprintf(stderr, "cesar: %s: nao foi possivel fechar o arquivo: %s\n", conteudo, strerror(errno));
            return EXIT_FAILURE;
        }

        if (fclose(arquivo_destino) != 0) {
            fprintf(stderr, "cesar: %s: nao foi possivel gravar o arquivo: %s\n", nome_arquivo_destino, strerror(errno));
            return EXIT_FAILURE;
        }

        printf("Arquivo '%s' criado!\n", nome_arquivo_destino);
    } else {
        fprintf(stderr, "cesar: %s: argumento invalido\n", tipo);
        fprintf(stderr, "Uso: cesar <cifrar|decifrar> <-t texto | -f arquivo> <deslocamento>\n");
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

static int converterStringParaInt(char *numero, int *resultado) {
    int i = 0;
    int numero_convertido = 0;

    while (numero[i] != '\0') {
        if (i == 0 && (numero[i] == '-' || numero[i] == '+')) i++;

        const int digito = numero[i];
        
        if (digito < '0' || digito > '9') {
            fprintf(stderr, "cesar: %s: deslocamento nao e um numero valido\n", numero);
            return EXIT_FAILURE;
        }

        numero_convertido = numero_convertido * 10;
        numero_convertido = numero_convertido + digito - '0';

        i++;
    }

    if (numero[0] == '-') numero_convertido = numero_convertido * -1;

    *resultado = numero_convertido;
    
    return EXIT_SUCCESS;
}
