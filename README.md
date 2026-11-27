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
3. `main.c` chama a funcao `escolherComando()`, o qual compara o primeiro termo (`vetor_argumentos[0]`) com o nome de cada comando, apontado e chamando a função correspondente, passando `(contagem_argumentos, vetor_argumentos)`.
4. Cada comando valida os próprios argumentos, executa a ação e devolve `EXIT_SUCCESS` ou `EXIT_FAILURE`.

## Sintaxe da linha de comando

* Os termos são separados por espaços. Espaços extras no início, no meio ou no fim da linha são ignorados.
* Um texto com espaços deve ficar entre aspas duplas (`"ola mundo"`) ou simples (`'ola mundo'`). As aspas não fazem parte do texto.
* Dentro de um texto entre aspas não é possível usar o mesmo tipo de aspa. Para escrever `"`, use aspas simples em volta, e vice-versa.
* Cada linha aceita no máximo 20 termos, contando o próprio comando, e até 4095 caracteres.
* Linhas vazias são ignoradas.

| Situação | Mensagem |
| --- | --- |
| Comando inexistente | `xyz: comando desconhecido` |
| Aspas duplas não fechadas | `Aspas duplas nao fechadas` |
| Aspas simples não fechadas | `Aspas simples nao fechadas` |
| Mais de 20 termos na linha | `Argumentos demais (maximo de 20 por linha)` |

Nesses casos a linha é ignorada e o terminal continua aberto.

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
* Comando inexistente retorna `ajuda: <comando>: comando desconhecido`.
* Mais de um comando informado retorna `ajuda: informe apenas um comando`.


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
* Falta de texto retorna **ec: informe ao menos um texto**


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
* Texto com espaços e sem aspas retorna `criar: quantidade de argumentos excedida`.
* Falta do nome ou do texto, ou nome vazio (`""`), retorna `criar: informe o nome do arquivo e o texto`.
* Nome contendo `/` ou `\` retorna `criar: <arquivo>: nome do arquivo nao deve conter '/' ou '\'`.
* Arquivo que não pode ser criado retorna `criar: <arquivo>: nao foi possivel criar o arquivo: <motivo>`.
* Falha ao gravar o texto retorna `criar: <arquivo>: nao foi possivel gravar o arquivo: <motivo>`.


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
* Falta de indicação de arquivo retorna `cat: informe pelo menos um arquivo`.
* Arquivo inexistente retorna `cat: <arquivo>: arquivo nao encontrado`.
* Arquivo que não pode ser aberto (por exemplo, sem permissão) retorna `cat: <arquivo>: nao foi possivel abrir o arquivo: <motivo>`.
* Arquivo que não pode ser lido (por exemplo, uma pasta) retorna `cat: <arquivo>: nao foi possivel ler o arquivo: <motivo>`.


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
* Quantidade de termos diferente de cinco retorna `cesar: quantidade de argumentos invalida`.
* Modo diferente de `cifrar` e `decifrar` retorna `cesar: <modo>: modo invalido`.
* Tipo diferente de `-t` e `-f` retorna `cesar: <tipo>: argumento invalido`.
* Deslocamento fora de 0 a 25 retorna `cesar: <deslocamento>: deslocamento deve estar entre 0 e 25`.
* Deslocamento que não é um número (inclusive negativo) retorna `cesar: <deslocamento>: deslocamento nao e um numero valido`.
* Deslocamento vazio (`""`) retorna `cesar: deslocamento esta vazio`.
* Arquivo de entrada (tipo `-f`) inexistente retorna `cesar: <arquivo>: arquivo nao encontrado`.
* Nome do arquivo de saída com mais de 255 caracteres retorna `cesar: <arquivo>: nome para arquivo muito longo`.
* Falha ao abrir ou ler o arquivo de entrada retorna `cesar: <arquivo>: nao foi possivel abrir o arquivo: <motivo>` ou `nao foi possivel ler o arquivo: <motivo>`.
* Falha ao criar ou gravar o arquivo de saída retorna `cesar: <arquivo>.cifrado: nao foi possivel criar o arquivo: <motivo>` ou `nao foi possivel gravar o arquivo: <motivo>`.


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
* Quantidade de termos diferente de cinco retorna `cesar: quantidade de argumentos invalida`.
* Modo diferente de `cifrar` e `decifrar` retorna `cesar: <modo>: modo invalido`.
* Tipo diferente de `-t` e `-f` retorna `cesar: <tipo>: argumento invalido`.
* Deslocamento fora de 0 a 25 retorna `cesar: <deslocamento>: deslocamento deve estar entre 0 e 25`.
* Deslocamento que não é um número (inclusive negativo) retorna `cesar: <deslocamento>: deslocamento nao e um numero valido`.
* Deslocamento vazio (`""`) retorna `cesar: deslocamento esta vazio`.
* Arquivo de entrada (tipo `-f`) inexistente retorna `cesar: <arquivo>: arquivo nao encontrado`.
* Nome do arquivo de saída com mais de 255 caracteres retorna `cesar: <arquivo>: nome para arquivo muito longo`.
* Falha ao abrir ou ler o arquivo de entrada retorna `cesar: <arquivo>: nao foi possivel abrir o arquivo: <motivo>` ou `nao foi possivel ler o arquivo: <motivo>`.
* Falha ao criar ou gravar o arquivo de saída retorna `cesar: <arquivo>.decifrado: nao foi possivel criar o arquivo: <motivo>` ou `nao foi possivel gravar o arquivo: <motivo>`.
