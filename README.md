# Terminal em C

Terminal simplificado desenvolvido em C do **Projeto Integrador II - Cibersegurança e Criptografia** (Escola Politécnica, PUC-Campinas, Professor Felix Carvalho Rodrigues).
Ele lê as linhas que o usuário digitar, executando os comandos contemplados pelo escopo do projeto. Funciona até o usuário utilizar `CTRL + C` ou o comando `sair`.

## Integrantes e suas funções

| **Nome** | **E-mail** | **Função** |
| --- | --- | --- |
| Alexandre Guidotti | alexandre.gcf1@puccampinas.edu.br | Desenvolveu comando_criar e comando_cesar |
| Ana Beatriz Sá | ana.bpps@puccampinas.edu.br | Desenvolveu comando_cat, comando_ajuda e comando_ec, documentação, junto à revisão/correção do projeto |
| Arthur Dimarzio | arthur.ad@puccampinas.edu.br | Desenvolveu main e comando_cesar, assim como gerenciou o andamento do projeto |
| Denise Porta | denise.vp1@puccampinas.edu.br | Desenvolveu comando_cat, comando_ajuda e comando_ec, junto à revisão/correção do projeto |
| Marina Oliveira | marina.oar@puccampinas.edu.br | Desenvolveu comando_cat, comando_ajuda e comando_ec, junto à revisão/correção do projeto |
| Pedro Porta | pedro.vp2@puccampinas.edu.br | Desenvolveu comando_sair e organizou main com escolherFuncao() |

## Escopo dos comandos suportados

| Comando | Explicação curta |
|---|---|
| **`ajuda`** | Lista os comandos e demonstra como utilizá-los |
| **`sair`** | Encerra o programa |
| **`ec`** | Imprime na tela o texto digitado |
| **`criar`** | Cria um arquivo com o texto informado |
| **`cat`** | Exibe o conteúdo de um ou mais arquivos |
| **`cesar cifrar`** | Cifra um texto/arquivo com a Cifra de César |
| **`cesar decifrar`** | Decifra um texto/arquivo com a Cifra de César |


## Requisitos mínimos
* Compilador para linguagem C; `gcc` foi o utilizado durante desenvolvimento.


## Compilação

Primeiramente, baixe o código ou clone o repositório a partir do comando:

```console
git clone https://github.com/arthur-pucc/projeto-integrador-terminal.git
cd projeto-integrador-terminal
```


### Linux / macOS:

```console
gcc src/*.c src/comandos/*.c -o terminal
```


### Windows

```console
gcc src/main.c src/parser.c src/escolhedor_de_funcao.c src/comandos/comando_ajuda.c src/comandos/comando_sair.c src/comandos/comando_ec.c src/comandos/comando_criar.c src/comandos/comando_cat.c src/comandos/comando_cesar.c -o terminal.exe
```


## Como executar o terminal:
A partir do terminal:

| Sistema | Comando |
| --- | --- |
| Windows (PowerShell) | **`.\terminal.exe`** |
| Windows (cmd) | **`terminal.exe`** |
| Linux / macOS | **`./terminal`** |

A partir de agora, o terminal escuta os comandos digitados pelo usuário até o comando `sair` ser executado ou o atalho `CTRL + C` ser utilizado.


---


## Como o código funciona

1. `main.c` lê o que o usuário digitou com `fgets`.
2. `separarArgumentos()` (em `parser.c`) quebra a linha nos espaços, respeitando o que está entre aspas, guarda um ponteiro para cada termo em `vetor_argumentos` e retorna quantos termos encontrou.
3. `main.c` compara o primeiro termo (`vetor_argumentos[0]`) com o nome de cada comando e chama `escolherFuncao`, responsavel por apontar a função correspondente, passando `(contagem_argumentos, vetor_argumentos)`.
4. Cada comando valida os próprios argumentos, executa a ação e devolve `EXIT_SUCCESS` ou `EXIT_FAILURE`.



## Comandos

### **`ajuda`**
Lista todos os comandos suportados e, caso especificado, demonstra como podem ser utilizados.

```bash
ajuda [comando]
```

#### Exemplo:

```bash
> ajuda sair
Encerra o terminal.
Sintaxe: sair
Exemplo: sair
```

#### Erros:
* Comando fora do escopo retorna **Comando desconhecido: `<comando>`**.
* Argumentos excessivos, por exemplo, mais de um comando indicado, retorna **Quantidade de argumentos excedida**.


### **`sair`**
Encerra o terminal.

```bash
> sair
Tchau!
```


### **`ec`**
Repete o texto indicado como argumento. Textos com espaços podem ficar entre aspas simples ou duplas pois são ignoradas na impressão do texto.

```bash
ec <texto>
```


#### Exemplo:

```bash
> ec ola mundo
ola mundo
```

#### Erros:
* Falta de texto retorna **Sem texto. Digite algo depois do comando.**


### **`criar`**
Cria um arquivo com o texto informado. Seu nome não pode conter `/` ou `\`, ou seja, o arquivo será criado diretamente na pasta de onde o **`terminal`** foi executado.

```bash
criar <nome_arquivo> <texto>
```

#### Exemplo:

```bash
> criar meu_arquivo.txt "Olá mundo! Esse é meu novo arquivo!"
Arquivo 'meu_arquivo.txt' criado!
```

#### Erros:
* Texto informado que **possui** espaço e **não** está entre aspas retorna **Quantidade de argumentos excedida**.
* Nome de arquivo contendo `/` ou `\` retorna **Nome do arquivo invalido. Nao deve conter '/' ou '\'.**
* Falha inesperada ao criar arquivo retorna **Erro ao criar arquivo '<nome_arquivo>'.**


### **`cat`**
Imprime no terminal o conteúdo do(s) arquivo(s) dado(s).

```bash
cat <arquivo> [arquivo ...]
```

#### Exemplo:

```bash
> cat meu_arquivo.txt
Olá mundo! Esse é meu novo arquivo!
```

#### Erros:
* Arquivo inexistente retorna **Arquivo nao encontrado**.
* Falta de indicação de arquivo retorna **Por favor, informe o nome de um arquivo.**


### **`cesar cifrar`**
Cifra um texto/arquivo com a Cifra de César a partir de dado deslocamento entre 0 e 25. Deslocamento move para DIREITA, como positivo.
Apenas letras são cifradas; números, letras com acento e caracteres especiais são mantidos.
Com tipo `-f`, um arquivo `<nome_arquivo>.cifrado` é criado.

```bash
cesar cifrar -t <texto> <deslocamento>
cesar cifrar -f <nome_arquivo> <deslocamento>
```

#### Exemplo:

```bash
> cesar cifrar -t ABC 3
DEF

> cesar cifrar -f meu_arquivo.txt 1
Arquivo meu_arquivo.txt.cifrado criado!
```

#### Erros:
* Quantidade de argumentos não segue estrutura já descrita retorna **Quantidade de argumentos invalida.**
* Deslocamento não está entre 0 e 25 retorna **Deslocamento aplicado invalido.**
* Deslocamento indicado não é um número válido retorna **Parametro nao e um numero valido**.
* Tipo diferente de `-t` e `-f` retorna **Argumento invalido.**
* Arquivo de entrada (tipo `-f`) inexistente retorna **Erro ao tentar ler arquivo**.
* Falha inesperada ao criar o arquivo `.cifrado` retorna **Erro ao tentar criar arquivo cifrado**.


### **`cesar decifrar`**
Decifra um texto/arquivo com a Cifra de César a partir de dado deslocamento entre 0 e 25. Deslocamento move para ESQUERDA, como negativo.
Apenas letras são decifradas; números, letras com acento e caracteres especiais são mantidos.
Com tipo `-f`, um arquivo `<nome_arquivo>.decifrado` é criado.

```bash
cesar decifrar -t <texto> <deslocamento>
cesar decifrar -f <nome_arquivo> <deslocamento>
```

#### Exemplo:

```bash
> cesar decifrar -t DEF 3
ABC

> cesar decifrar -f meu_arquivo.txt.cifrado 1
Arquivo meu_arquivo.txt.cifrado.decifrado criado!
```

#### Erros:
* Quantidade de argumentos não segue estrutura já descrita retorna **Quantidade de argumentos invalida.**
* Deslocamento não está entre 0 e 25 retorna **Deslocamento aplicado invalido.**
* Deslocamento indicado não é um número válido retorna **Parametro nao e um numero valido**.
* Tipo diferente de `-t` e `-f` retorna **Argumento invalido.**
* Arquivo de entrada (tipo `-f`) inexistente retorna **Erro ao tentar ler arquivo**.
* Falha inesperada ao criar o arquivo `.cifrado` retorna **Erro ao tentar criar arquivo decifrado**.
