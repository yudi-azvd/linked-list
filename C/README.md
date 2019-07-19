<!-- trash -->
# Calculadora
_Ainda em desenvolvimento_. Esse projeto é a revitalização de um antigo trabalho
de Estrutura de Dados para o qual era necessário implementar uma calculadora em C
~~porque quem é programador de verdade programa em C.~~. A calculadora executa algumas
operações básicas utilizando listas lincadas, pilhas e conversão entre as formas infixa
e pós-fixa.

Mais informações sobre esse trabalho podem ser encontradas no arquivo `./C/docs/calculadora.pdf.`

## O que ela faz?
Por enquanto, nada. Acabei de terminar a implementação de lista. Tá funcionando. Só rodar os testes.

## Dependendências
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
$ cd calculator/C/build
$ cmake ..
$ make
```

É normal demorar um pouco pra compilar porque os testes são realizados utilizando
o framework [Catch2](https://github.com/catchorg/Catch2).

### Executar
```
$ ./nome_do_executavel
```

## Fazendo
Implementação de uma "biblioteca" de lista lincada genérica. Está em `lib/list`
(ainda estou aprendendo como organizar os arquivos).


## A fazer
Ainda tem muita coisa pra fazer. Nem sei listar. Tenho que organizar um
quadro Scrum/Kanbam.
