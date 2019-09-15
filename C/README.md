<!-- trash -->
# Calculadora em C
_Ainda em desenvolvimento_. Esse projeto é a revitalização de um antigo trabalho
de Estrutura de Dados para o qual era necessário implementar uma calculadora em C
~~porque quem é programador de verdade programa em C~~. A calculadora executa algumas
operações básicas utilizando listas lincadas, pilhas e conversão entre as formas infixa
e pós-fixa.


## O que ela faz?
Não é um aplicativo. Está mais para uma biblioteca. Mas por enquanto, ela avalia
algumas expressões simples que podem ser declaradas em `main/main.c`

![gif da calculadora](/C/resources/calculator.gif)


## Dependendências
* git
* gcc
* g++
* [CMake](https://cmake.org/)
* make


## Como usar
(na verdade, só baixar mesmo. Não funciona nada ainda)


### Baixe o repositório
Abra o terminal e digite:

```
$ git clone https://github.com/y-azvd/calculator.git
```

Ou clique no botão verde no diretório raíz desse repositório.

### Depois de ter baixado
```
$ cd calculator/C
$ mkdir build
$ cd build/
$ cmake ..
$ make
```

É normal demorar um pouco pra compilar porque os testes são realizados utilizando
o framework [Catch2](https://github.com/catchorg/Catch2). Mas é só na primeira vez.


### Executar
```
$ ./calculator
```

## Fazendo
Melhorando o algoritmo de avaliação.


## A fazer
Ainda tem muita coisa pra fazer. Nem sei listar. Tenho que organizar um
quadro Scrum/Kanbam.
