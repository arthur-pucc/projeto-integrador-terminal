# Terminal em C

Terminal simplificado desenvolvido em C do **Projeto Integrador II - Cibersegurança e Criptografia**(Escola Politécnica, PUC-Campinas, Professor Felix Carvalho Rodrigues).
Ele lê as linhas que o usuário digitar, executando os comandos contemplados pelo escopo do projeto. Funciona até o usuário utilizar 'CTRL + C' ou utilizar o comando sair.

## Escopo dos comandos suportados

| Comando | Explicação curta |
|---|---|
| **`cat`** | Exibe o conteúdo de um ou mais arquivos |


## Requisitos mínimos
* Compilador para linguagem C, como o `gcc`
* `git`

## Compilação

### Windows / Linux / Mac:

```console
git clone https://github.com/arthur-pucc/projeto-integrador-terminal.git
cd projeto-integrador-terminal
gcc terminal_main.c comando_cat.c -o programa.exe
```


## Como executar o terminal:

```console
./programa.exe
```
A partir de agora, o terminal escuta os comandos imputados pelo usuário até o comando `sair` ser executado ou o atalho `CTRL + C` ser utilizado.


---


## Comandos

### **`cat`**
Imprime no terminal o conteúdo do(s) arquivo(s) dado(s).

```bash
cat <arquivo> [arquivo ...]
```

#### Exemplo:

```bash
cat meu_arquivo.txt
```

#### Erros:
* Arquivo inexistente retorna **arquivo nao encontrado**.