#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ajuda(int contagem_argumentos, char *vetor_argumentos[]) {
    char *comando = vetor_argumentos[1];

    if (contagem_argumentos > 2 && !(strcmp(comando, "cesar") == 0 && contagem_argumentos == 3)) {
        printf("Quantidade de argumentos excedida.\n");
        return EXIT_FAILURE;
    }

    if (contagem_argumentos == 1) {
        printf("Todos os comandos:\n");
        printf("ajuda           - Lista os comandos.\n");
        printf("sair            - Encerra o terminal\n");
        printf("ec              - Repete um texto.\n");
        printf("criar           - Cria um arquivo.\n");
        printf("cat             - Mostra o conteudo.\n");
        printf("cesar cifrar    - Cifrar texto.\n");
        printf("cesar decifrar  - Decifrar texto.\n");
        printf("\nUse ajuda <comando> para ver a sintaxe e um exemplo.\n");
        printf("Exemplo: ajuda cesar\n");
    } else if (strcmp(comando, "ajuda") == 0) {
        printf("Lista todos os comandos.\n");
        printf("Sintaxe: ajuda <comando>\n");
        printf("Exmplo: ajuda cat\n");
    } else if (strcmp(comando, "sair") == 0) {
        printf("Encerra o terminal.\n");
        printf("Sintaxe: sair\n");
        printf("Exemplo: sair\n");
    } else if (strcmp(comando, "ec") == 0) {
        printf("Repete o(s) texto(s) imputado(s).\n");
        printf("Sintaxe: ec <texto> [..texto]\n");
        printf("Exemplo: ec \"ola mundo\"\n");
    } else if (strcmp(comando, "criar") == 0) {
        printf("Cria um arquivo com o texto informado.\n");
        printf("Sintaxe: criar <arquivo> <texto>\n");
        printf("    ** Se o arquivo existir, seu conteudo sera substituido.\n");
        printf("    ** O nome deve ser informado sem barra.\n");
        printf("Exemplo: criar msg.txt \"ola mundo\"\n");
    } else if (strcmp(comando, "cat") == 0) {
        printf("Concatena o conteudo dos arquivos indicados e demonstra o resultado final na tela.\n");
        printf("Sintaxe: cat <arquivo> [..arquivo]\n");
        printf("Exemplo: cat msg.txt\n");
    } else if (strcmp(comando, "cesar") == 0) {
        printf("Cifra ou decifra textos e arquivos com a Cifra de Cesar.\n");
        printf("Sintaxe:\n");
        printf("    cesar cifrar -t <texto> <deslocamento>\n");
        printf("    cesar cifrar -f <arquivo> <deslocamento>\n");
        printf("    cesar decifrar -t <texto> <deslocamento>\n");
        printf("    cesar decifrar -f <arquivo> <deslocamento>\n\n");
        printf("-t: recebe texto e informa resultado.\n");
        printf("-f: recebe nome de arquivo e guarda seu resultado dentro do arquivo.\n");
        printf("Deslocamento: numero inteiro de 0 a 25, o qual representa quantas LETRAS deve avancar/recuar.\n");
        printf("    ** Maiusculos e minusculos sao preservados\n");
        printf("    ** Espacos, numeros e pontuacao nao passam pela cifra.\n");
        printf("Exemplos:\n");
        printf("    cesar cifrar -t ABC 3         -> DEF\n");
        printf("    cesar decifrar -t DEF 3       -> ABC\n");
        printf("    cesar cifrar -f msg.txt 3     -> msg.txt.cifrado\n");
        printf("    cesar decifrar -f msg.txt 3   -> msg.txt.decifrado\n");
    } else {
        printf("Comando desconhecido: %s\n", comando);
        printf("Digite ajuda para ver todos os comandos disponiveis.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
