# Calculadora
~~Quem é programador de verdade programa em C.~~

## O que ela faz?
Bem, ainda nada. Não tá pronta.
<!-- Bem, é só uma calculadora. -->

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

É normal demorar um pouco pra compilar porque os testes são realizados utilizando o framework [Catch2](https://github.com/catchorg/Catch2).

## Fazendo
Implementação de uma "biblioteca" de lista lincada genérica. Está em `lib/list` (ainda estou aprendendo como organizar os arquivos).


<!-- how to C libraries
  https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_C_libraries.html

  function pointers inside struct
  - https://stackoverflow.com/questions/1350376/function-pointer-as-a-member-of-a-c-struct
  - https://www.youtube.com/watch?v=ReVeUvwTGdU&t=130 -->
