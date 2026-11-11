#include <stdio.h>
#include <string.h>

void ajuda(char comando[])
{
    if(strcmp(comando, "") == 0) {
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
        return;
    }
    else if (strcmp(comando, "ajuda") == 0){
        printf("Lista de comandos.\n");
        printf("Sintaxe: ajuda <comando>\n");
        printf("Exmplo: ajuda cat\n");
    }
    else if (strcmp(comando, "sair") == 0){
        printf("Encerra o terminal\n");
        printf("Sintaxe: sair\n");
        printf("Exemplo: sair\n");
    }
    else if (strcmp(comando, "ec") == 0){
        printf("Repete o texto\n");
        printf("Sintaxe: ec <texto>\n");
        printf("Exemplo: ec \"ola mundo\"\n");
        printf("Sem texto, informe o restante.\n");
    }
    else if (strcmp(comando, "criar") == 0){
        printf("Cria um arquivo com texto infirmado.\n");
        printf("Sintaxe: criar <arquivo> <texto>\n");
        printf("Exemplo: criar msg.txt \"ola mundo\"\n");
        printf("Se o arquivo existir, seu conteudo sera substituido.\n");
        printf("O nome deve ser informado sem barra.\n");
        printf("Nome vazio, texto ausente.\n");
    }
    else if (strcmp(comando, "cat") == 0){
        printf("Mostra o conteudo de um arquivo.\n");
        printf("Sintaxe: cat <arquivo>\n");
        printf("Exemplo: Se o arquivo nao existir, informa: arquivo nao encontrado.\n");
    }
    else if (strcmp(comando, "cesar") == 0 ||
             strcmp(comando, "cesar cifrar") == 0 ||
             strcmp(comando, "cesar decifrar") == 0){
        printf("Cifra ou decifra textos e arquivos com cifra de Cesar.\n");
        printf("Sintaxe:\n");
        printf("    cesar cifrar -t <texto> <deslocamento>\n");
        printf("    cesar cifrar -f <texto> <deslocamento>\n");
        printf("    cesar decifrar -t <texto> <deslocamento>\n");
        printf("    cesar decifrar -f <texto> <deslocamento>\n");
        printf("-t: recebe texto e informa resultado\n");
        printf("-f: recebe texto e informa resultado\n");
        printf("Deslocamento: numero inteiro de 0 a 25\n");  
        printf("Maiusculos e minusculos sao preservados\n");
        printf("Espacos, numeros e pontuacao nao mudam\n");
        printf("Exemplos:\n");
        printf("    cesar cifrar -t ABC 3   -> DEF\n");    
        printf("    cesar decifrar -t DEF 3   -> ABC\n");
        printf("    cesar cifrar -f msg.txt 3   -> msg.txt.cifrado\n");
        printf("    cesar decifrar -f msg.txt 3   -> msg.txt.decifrado\n");
        printf("Falta de argumentos, deslocamento invalido\n");
        printf("Inexistente gera um aviso.\n");
    }
    else{
        printf("Comando desconhecido: %s\n", comando);
        printf("Digite ajuda para ver os comandos disponiveis.\n");
    }

}