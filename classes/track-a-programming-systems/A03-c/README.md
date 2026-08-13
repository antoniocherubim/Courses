# Class — Linguagem C

> Um caderno de estudo e consulta sobre a linguagem C.
>
> Objetivo: entender não apenas *como escrever código em C*, mas também **o que o computador está fazendo** e como os dados são representados e manipulados na memória.

[← A02 C++ e POO](../A02-cpp-poo/) · [↑ Track A](../README.md) · [Próxima → A04 Algoritmos](../A04-algoritmos-estruturas-dados/)

---

# Sumário

1. [Como pensar em C](#1-como-pensar-em-c)
2. [Compilação e execução](#2-compilação-e-execução)
3. [Estrutura básica de um programa C](#3-estrutura-básica-de-um-programa-c)
4. [Tipos, variáveis e representação](#4-tipos-variáveis-e-representação)
5. [Operadores](#5-operadores)
6. [Entrada e saída](#6-entrada-e-saída)
7. [Controle de fluxo](#7-controle-de-fluxo)
8. [Funções](#8-funções)
9. [Escopo, duração e linkage](#9-escopo-duração-e-linkage)
10. [Arrays](#10-arrays)
11. [Strings](#11-strings)
12. [Ponteiros](#12-ponteiros)
13. [Arrays e ponteiros](#13-arrays-e-ponteiros)
14. [Ponteiros para ponteiros](#14-ponteiros-para-ponteiros)
15. [`const` e const-correctness](#15-const-e-const-correctness)
16. [Structs](#16-structs)
17. [Enums, unions e typedef](#17-enums-unions-e-typedef)
18. [Memória dinâmica](#18-memória-dinâmica)
19. [Modelo de memória](#19-modelo-de-memória)
20. [Arquivos](#20-arquivos)
21. [Pré-processador e headers](#21-pré-processador-e-headers)
22. [Compilação separada](#22-compilação-separada)
23. [Ponteiros para função](#23-ponteiros-para-função)
24. [Bits e representação binária](#24-bits-e-representação-binária)
25. [Erros clássicos e comportamento indefinido](#25-erros-clássicos-e-comportamento-indefinido)
26. [Debugging e ferramentas](#26-debugging-e-ferramentas)

---

# 1. Como pensar em C

C é uma linguagem relativamente pequena.

A dificuldade não está na quantidade de sintaxe, mas no fato de que C expõe diretamente conceitos que linguagens de nível mais alto escondem:

- endereços de memória;
- representação binária;
- tamanho dos tipos;
- alocação e desalocação;
- layout de arrays;
- passagem de argumentos;
- representação de strings;
- comportamento indefinido;
- custo real das operações.

Uma boa forma de pensar em C é:

```text
código C
   ↓
operações sobre dados
   ↓
dados armazenados em memória
   ↓
endereços + bytes + instruções
```

Em Python, você normalmente pensa:

```python
x = [1, 2, 3]
```

Em C, você deve se perguntar:

```text
Onde esses valores estão?
Quantos bytes cada elemento ocupa?
Os elementos são contíguos?
Quem é responsável por liberar a memória?
Qual endereço aponta para o primeiro elemento?
```

Esse é precisamente o motivo pelo qual estudar C ajuda a entender computadores.

---

# 2. Compilação e execução

Um programa em C não é normalmente executado diretamente.

O fluxo simplificado é:

```text
arquivo .c
   ↓
pré-processador
   ↓
compilador
   ↓
assembly
   ↓
assembler
   ↓
arquivo objeto (.o)
   ↓
linker
   ↓
executável
```

Exemplo:

```bash
gcc programa.c -o programa
./programa
```

Uma compilação recomendada durante estudos:

```bash
gcc -std=c17 \
    -Wall \
    -Wextra \
    -Wpedantic \
    -Wshadow \
    -Wconversion \
    -g \
    programa.c \
    -o programa
```

Para detectar muitos erros de memória:

```bash
gcc -std=c17 \
    -Wall -Wextra -Wpedantic \
    -g \
    -fsanitize=address,undefined \
    programa.c \
    -o programa
```

## 2.1 Pré-processador

Processa diretivas iniciadas por `#`.

Exemplo:

```c
#include <stdio.h>
#define PI 3.141592653589793
```

## 2.2 Compilador

Transforma C em uma representação de baixo nível.

## 2.3 Assembler

Transforma assembly em código objeto.

## 2.4 Linker

Liga seus objetos com bibliotecas e resolve símbolos externos.

Por exemplo, a chamada:

```c
printf("Olá\n");
```

é declarada em `stdio.h`, mas sua implementação está na biblioteca padrão de C.

---

# 3. Estrutura básica de um programa C

```c
#include <stdio.h>

int main(void) {
    printf("Hello, world!\n");
    return 0;
}
```

`main` é o ponto de entrada convencional.

Outra forma:

```c
int main(int argc, char *argv[]) {
    ...
}
```

onde:

- `argc` = quantidade de argumentos;
- `argv` = array de strings com os argumentos.

Exemplo:

```bash
./programa arquivo.txt 10
```

pode produzir:

```text
argc = 3

argv[0] = "./programa"
argv[1] = "arquivo.txt"
argv[2] = "10"
```

---

# 4. Tipos, variáveis e representação

## 4.1 Tipos inteiros básicos

```c
char
short
int
long
long long
```

Podem ser:

```c
signed
unsigned
```

Exemplo:

```c
unsigned int idade = 25;
long long populacao = 8000000000LL;
```

O padrão C não fixa universalmente o número de bits de todos esses tipos.

Por isso existe:

```c
#include <stdint.h>
```

com tipos como:

```c
int8_t
uint8_t
int16_t
uint16_t
int32_t
uint32_t
int64_t
uint64_t
```

quando disponíveis.

## 4.2 `sizeof`

Retorna o tamanho em bytes:

```c
printf("%zu\n", sizeof(int));
```

`sizeof` retorna `size_t`.

## 4.3 Ponto flutuante

```c
float
double
long double
```

Normalmente:

```c
float  x = 3.14f;
double y = 3.14;
```

Não trate ponto flutuante como matemática real exata.

Exemplo:

```c
0.1 + 0.2
```

pode não possuir representação binária exata.

## 4.4 `char`

`char` representa uma unidade de caractere/byte.

```c
char c = 'A';
```

O literal `'A'` representa um valor numérico associado à codificação da execução.

## 4.5 Booleanos

```c
#include <stdbool.h>

bool ativo = true;
```

---

# 5. Operadores

## 5.1 Aritméticos

```c
+
-
*
/
%
```

Divisão entre inteiros:

```c
5 / 2
```

resultado:

```text
2
```

Para resultado real:

```c
5.0 / 2.0
```

resultado:

```text
2.5
```

## 5.2 Relacionais

```c
==
!=
<
>
<=
>=
```

## 5.3 Lógicos

```c
&&
||
!
```

## 5.4 Incremento e decremento

```c
i++;
i--;
++i;
--i;
```

Diferença:

```c
int a = i++;
```

usa o valor anterior de `i`.

```c
int a = ++i;
```

incrementa antes de usar.

Não escreva expressões desnecessariamente complicadas envolvendo múltiplos efeitos colaterais.

## 5.5 Atribuição composta

```c
x += 5;
x -= 3;
x *= 2;
x /= 4;
```

## 5.6 Operadores bit a bit

```c
&
|
^
~
<<
>>
```

São diferentes de:

```c
&&
||
```

---

# 6. Entrada e saída

Biblioteca:

```c
#include <stdio.h>
```

## 6.1 `printf`

```c
int idade = 25;

printf("Idade: %d\n", idade);
```

Formatos comuns:

```text
%d   int
%u   unsigned int
%ld  long
%lld long long
%f   double no printf
%c   char
%s   string
%p   ponteiro
%zu  size_t
```

Exemplo:

```c
printf("%p\n", (void *)&idade);
```

## 6.2 `scanf`

```c
int x;

scanf("%d", &x);
```

O `&x` significa:

> passe o endereço de `x` para que `scanf` possa modificar a variável.

Sempre verifique o retorno:

```c
if (scanf("%d", &x) != 1) {
    fprintf(stderr, "Entrada inválida\n");
}
```

## 6.3 Preferência por `fgets`

Para entrada textual, `fgets` geralmente é mais controlável:

```c
char buffer[100];

if (fgets(buffer, sizeof buffer, stdin) != NULL) {
    printf("%s", buffer);
}
```

Depois você pode converter usando funções como:

```c
strtol
strtod
```

---

# 7. Controle de fluxo

## 7.1 `if`

```c
if (idade >= 18) {
    printf("Maior de idade\n");
} else {
    printf("Menor de idade\n");
}
```

## 7.2 `switch`

```c
switch (opcao) {
    case 1:
        printf("Cadastrar\n");
        break;

    case 2:
        printf("Listar\n");
        break;

    default:
        printf("Opção inválida\n");
}
```

Sem `break`, ocorre *fall-through*.

## 7.3 `while`

```c
while (condicao) {
    ...
}
```

## 7.4 `do while`

Executa pelo menos uma vez:

```c
do {
    ...
} while (condicao);
```

## 7.5 `for`

```c
for (int i = 0; i < 10; i++) {
    printf("%d\n", i);
}
```

Mentalmente:

```c
inicialização;

while (condição) {
    corpo;
    atualização;
}
```

## 7.6 `break`

Sai do laço.

## 7.7 `continue`

Pula para a próxima iteração.

---

# 8. Funções

```c
int soma(int a, int b) {
    return a + b;
}
```

Uso:

```c
int resultado = soma(2, 3);
```

## 8.1 Protótipos

```c
int soma(int a, int b);

int main(void) {
    printf("%d\n", soma(2, 3));
}

int soma(int a, int b) {
    return a + b;
}
```

## 8.2 C usa passagem por valor

Isto é fundamental.

```c
void alterar(int x) {
    x = 100;
}
```

não altera:

```c
int n = 10;
alterar(n);
```

porque a função recebe uma cópia.

Para alterar a variável original:

```c
void alterar(int *x) {
    *x = 100;
}
```

Uso:

```c
int n = 10;
alterar(&n);
```

Agora:

```text
n == 100
```

---

# 9. Escopo, duração e linkage

São conceitos diferentes.

## 9.1 Escopo

Determina onde um nome pode ser usado.

```c
{
    int x = 10;
}
```

`x` deixa de estar visível fora do bloco.

## 9.2 Duração de armazenamento

Determina por quanto tempo o objeto existe.

Uma variável local normal:

```c
void f(void) {
    int x = 0;
}
```

tem duração automática.

Uma variável `static` local:

```c
void contador(void) {
    static int x = 0;
    x++;
    printf("%d\n", x);
}
```

mantém o valor entre chamadas.

## 9.3 Linkage

Relaciona nomes entre unidades de compilação.

Uma variável global:

```c
int contador;
```

pode possuir linkage externo.

Com:

```c
static int contador;
```

fica restrita à unidade de compilação.

---

# 10. Arrays

```c
int numeros[5];
```

Memória conceitual:

```text
+----+----+----+----+----+
| n0 | n1 | n2 | n3 | n4 |
+----+----+----+----+----+
```

Os elementos são contíguos.

Inicialização:

```c
int numeros[5] = {10, 20, 30, 40, 50};
```

ou:

```c
int numeros[] = {10, 20, 30};
```

## 10.1 Índices

```c
numeros[0]
numeros[1]
...
```

Não existe verificação automática de limites.

Isto é incorreto:

```c
int v[5];
v[5] = 10;
```

Os índices válidos são:

```text
0, 1, 2, 3, 4
```

## 10.2 Quantidade de elementos

Dentro do mesmo escopo do array:

```c
size_t n = sizeof v / sizeof v[0];
```

Mas isso **não funciona** depois que o array foi convertido em ponteiro ao ser passado para uma função.

---

# 11. Strings

C não possui um tipo `string` embutido.

Uma string é convencionalmente:

> uma sequência de `char` terminada pelo byte `'\0'`.

```c
char nome[] = "Antonio";
```

Memória conceitual:

```text
A n t o n i o \0
```

## 11.1 Biblioteca `<string.h>`

Funções comuns:

```c
strlen
strcmp
strcpy
strncpy
strcat
memcpy
memmove
memset
```

Exemplo:

```c
size_t tamanho = strlen(nome);
```

`strlen` não conta o terminador `'\0'`.

## 11.2 Comparação

Errado:

```c
if (a == b)
```

para comparar conteúdo de strings.

Correto:

```c
if (strcmp(a, b) == 0)
```

## 11.3 Cuidado com buffers

```c
char destino[5];
strcpy(destino, "abcdef");
```

causa escrita além do limite.

Esse tipo de erro está por trás de muitas vulnerabilidades clássicas em C.

---

# 12. Ponteiros

Ponteiro é uma variável que armazena um endereço.

```c
int x = 10;
int *p = &x;
```

Visualmente:

```text
x
+------+
|  10  |
+------+
 0x1000

p
+--------+
| 0x1000 |
+--------+
```

## 12.1 `&`

Obtém o endereço:

```c
&x
```

## 12.2 `*`

Ao declarar:

```c
int *p;
```

significa:

> `p` é ponteiro para `int`.

Ao usar:

```c
*p
```

significa:

> acesse o objeto apontado por `p`.

Exemplo:

```c
int x = 10;
int *p = &x;

*p = 20;
```

Agora:

```text
x == 20
```

## 12.3 Ponteiro nulo

```c
int *p = NULL;
```

Nunca desreferencie:

```c
*p
```

quando `p == NULL`.

## 12.4 Tipo do ponteiro importa

```c
int *
double *
char *
struct Pessoa *
```

O tipo informa ao compilador:

- como interpretar os bytes;
- quanto avançar em aritmética de ponteiros;
- que tipo resulta de `*p`.

---

# 13. Arrays e ponteiros

Arrays e ponteiros são relacionados, mas **não são a mesma coisa**.

```c
int v[3] = {10, 20, 30};
```

Em muitas expressões, `v` é convertido em:

```c
&v[0]
```

Assim:

```c
v[1]
```

é equivalente conceitualmente a:

```c
*(v + 1)
```

Logo:

```c
a[b]
```

é definido em termos de:

```c
*(a + b)
```

## 13.1 Aritmética de ponteiros

Se:

```c
int *p;
```

então:

```c
p + 1
```

avança por:

```text
sizeof(int)
```

bytes, não apenas um byte.

---

# 14. Ponteiros para ponteiros

```c
int x = 10;
int *p = &x;
int **pp = &p;
```

Visualmente:

```text
pp → p → x
```

Uso:

```c
**pp = 50;
```

altera `x`.

São comuns em:

- funções que precisam modificar um ponteiro;
- arrays de strings;
- listas;
- árvores;
- APIs de alocação;
- `argv`.

Exemplo:

```c
void criar(int **p) {
    *p = malloc(sizeof **p);
}
```

---

# 15. `const` e const-correctness

```c
const int x = 10;
```

`x` não deve ser modificado.

Com ponteiros:

```c
const int *p;
```

`p` pode mudar, mas não devemos modificar `*p` por ele.

```c
int *const p = &x;
```

o endereço armazenado em `p` não pode mudar.

```c
const int *const p = &x;
```

nem o ponteiro nem o objeto apontado devem ser modificados por esse acesso.

Regra prática:

Use `const` em parâmetros que a função apenas lê.

```c
int soma_array(const int *v, size_t n);
```

---

# 16. Structs

Uma `struct` agrupa campos.

```c
struct Pessoa {
    char nome[100];
    int idade;
};
```

Uso:

```c
struct Pessoa p;

p.idade = 25;
```

Inicialização:

```c
struct Pessoa p = {
    .nome = "Antonio",
    .idade = 25
};
```

## 16.1 Ponteiro para struct

```c
struct Pessoa *ptr = &p;
```

Pode usar:

```c
(*ptr).idade
```

ou, preferencialmente:

```c
ptr->idade
```

## 16.2 Structs como base das estruturas de dados

Lista encadeada:

```c
struct Node {
    int valor;
    struct Node *proximo;
};
```

Árvore:

```c
struct Node {
    int valor;
    struct Node *esquerda;
    struct Node *direita;
};
```

Grafos, tabelas hash, heaps e praticamente todas as estruturas compostas em C dependem fortemente de `struct`.

---

# 17. Enums, unions e typedef

## 17.1 `enum`

```c
enum Estado {
    PARADO,
    EXECUTANDO,
    FINALIZADO
};
```

Uso:

```c
enum Estado estado = EXECUTANDO;
```

## 17.2 `typedef`

```c
typedef unsigned long ulong;
```

Com struct:

```c
typedef struct {
    char nome[100];
    int idade;
} Pessoa;
```

Agora:

```c
Pessoa p;
```

## 17.3 `union`

Todos os membros compartilham a mesma região de memória.

```c
union Valor {
    int inteiro;
    double real;
};
```

Uma `union` é útil quando um objeto pode representar formatos diferentes em momentos diferentes.

Normalmente é usada junto com uma tag:

```c
enum Tipo {
    TIPO_INT,
    TIPO_DOUBLE
};

struct Valor {
    enum Tipo tipo;

    union {
        int inteiro;
        double real;
    } dado;
};
```

---

# 18. Memória dinâmica

Biblioteca:

```c
#include <stdlib.h>
```

## 18.1 `malloc`

```c
int *p = malloc(sizeof *p);
```

Sempre verifique:

```c
if (p == NULL) {
    ...
}
```

## 18.2 `calloc`

```c
int *v = calloc(n, sizeof *v);
```

Reserva espaço para `n` elementos e inicializa os bytes com zero.

## 18.3 `realloc`

```c
int *novo = realloc(v, novo_tamanho * sizeof *v);
```

Forma segura:

```c
int *temp = realloc(v, novo_tamanho * sizeof *v);

if (temp != NULL) {
    v = temp;
}
```

Não faça diretamente:

```c
v = realloc(v, novo_tamanho);
```

se perder `v` em caso de falha for um problema.

## 18.4 `free`

```c
free(p);
p = NULL;
```

`free(NULL)` é permitido.

## 18.5 Ownership

Uma das perguntas mais importantes em C:

> Quem é dono desta memória?

Para cada alocação, deveria existir uma política clara de liberação.

Exemplo:

```c
int *criar_array(size_t n) {
    return malloc(n * sizeof(int));
}
```

Quem chama precisa saber que recebeu uma alocação que deverá liberar:

```c
int *v = criar_array(100);

...

free(v);
```

---

# 19. Modelo de memória

Modelo simplificado de um processo:

```text
endereços altos
+-----------------------+
|        Stack          |
|          ↓            |
|                       |
|          ↑            |
|         Heap          |
+-----------------------+
| Dados globais/static  |
+-----------------------+
| Código / text         |
+-----------------------+
endereços baixos
```

Esse desenho é conceitual; detalhes reais dependem do sistema.

## 19.1 Stack

Normalmente contém:

- parâmetros;
- variáveis locais;
- endereços de retorno;
- frames de chamadas.

Exemplo:

```c
void f(void) {
    int x = 10;
}
```

`x` normalmente vive no frame de `f`.

## 19.2 Heap

Memória obtida dinamicamente:

```c
malloc
calloc
realloc
```

## 19.3 Memória estática

Variáveis globais e `static`.

---

# 20. Arquivos

```c
#include <stdio.h>
```

Abrindo:

```c
FILE *arquivo = fopen("dados.txt", "r");
```

Verifique:

```c
if (arquivo == NULL) {
    perror("fopen");
    return 1;
}
```

Feche:

```c
fclose(arquivo);
```

## 20.1 Modos comuns

```text
r   leitura
w   escrita, truncando
a   append

rb
wb
ab
```

## 20.2 Leitura

```c
char linha[256];

while (fgets(linha, sizeof linha, arquivo) != NULL) {
    printf("%s", linha);
}
```

## 20.3 Escrita

```c
fprintf(arquivo, "valor=%d\n", 42);
```

## 20.4 Dados binários

```c
fread
fwrite
```

---

# 21. Pré-processador e headers

## 21.1 `#include`

```c
#include <stdio.h>
```

Headers do sistema normalmente usam `<...>`.

Headers do projeto:

```c
#include "lista.h"
```

## 21.2 Macros

```c
#define TAMANHO 100
```

Macros com argumentos:

```c
#define QUADRADO(x) ((x) * (x))
```

Mesmo assim:

```c
QUADRADO(i++)
```

é perigoso porque `i++` pode ser avaliado mais de uma vez.

Sempre prefira funções quando possível.

## 21.3 Include guards

```c
#ifndef LISTA_H
#define LISTA_H

...

#endif
```

---

# 22. Compilação separada

Estrutura:

```text
projeto/
├── main.c
├── lista.c
└── lista.h
```

`lista.h`:

```c
#ifndef LISTA_H
#define LISTA_H

void lista_imprimir(void);

#endif
```

`lista.c`:

```c
#include <stdio.h>
#include "lista.h"

void lista_imprimir(void) {
    printf("Lista\n");
}
```

`main.c`:

```c
#include "lista.h"

int main(void) {
    lista_imprimir();
    return 0;
}
```

Compilando:

```bash
gcc -c lista.c
gcc -c main.c
gcc lista.o main.o -o programa
```

Ou:

```bash
gcc main.c lista.c -o programa
```

---

# 23. Ponteiros para função

Funções também possuem endereços.

```c
int soma(int a, int b) {
    return a + b;
}
```

Ponteiro:

```c
int (*operacao)(int, int) = soma;
```

Uso:

```c
int resultado = operacao(2, 3);
```

Muito usados em:

- callbacks;
- comparadores;
- dispatch;
- máquinas de estado;
- APIs genéricas.

Exemplo clássico:

```c
qsort
```

```c
int comparar(const void *a, const void *b) {
    const int x = *(const int *)a;
    const int y = *(const int *)b;

    return (x > y) - (x < y);
}
```

---

# 24. Bits e representação binária

## 24.1 AND

```c
x & mask
```

## 24.2 OR

```c
x | mask
```

## 24.3 XOR

```c
x ^ mask
```

## 24.4 NOT

```c
~x
```

## 24.5 Shift

```c
x << 1
x >> 1
```

Para manipulação de bits, tipos `unsigned` são geralmente mais previsíveis.

## 24.6 Flags

```c
#define FLAG_READ  (1u << 0)
#define FLAG_WRITE (1u << 1)
#define FLAG_EXEC  (1u << 2)

unsigned permissoes = FLAG_READ | FLAG_WRITE;
```

Testando:

```c
if (permissoes & FLAG_WRITE) {
    ...
}
```

---

# 25. Erros clássicos e comportamento indefinido

C permite fazer muita coisa.

Isso significa que também permite escrever programas cujo comportamento não é definido pela linguagem.

## 25.1 Acesso fora do array

```c
int v[5];
v[100] = 10;
```

## 25.2 Uso depois de `free`

```c
int *p = malloc(sizeof *p);

free(p);

*p = 10;
```

## 25.3 Double free

```c
free(p);
free(p);
```

## 25.4 Ponteiro não inicializado

```c
int *p;
*p = 10;
```

## 25.5 Retornar endereço de variável local

Errado:

```c
int *f(void) {
    int x = 10;
    return &x;
}
```

`x` deixa de existir quando `f` retorna.

## 25.6 Overflow de inteiro com sinal

Overflow de inteiro *signed* pode resultar em comportamento indefinido.

Por exemplo, não faça:

```c
if (a + b > INT_MAX)
```

para detectar overflow, porque a soma problemática já aconteceu.

Cheque antes:

```c
#include <limits.h>
#include <stdbool.h>

bool soma_segura_int(int a, int b, int *resultado) {
    if (b > 0 && a > INT_MAX - b) {
        return false;
    }

    if (b < 0 && a < INT_MIN - b) {
        return false;
    }

    *resultado = a + b;
    return true;
}
```

## 25.7 Uso de variável não inicializada

```c
int x;
printf("%d\n", x);
```

## 25.8 `sizeof(pointer)` confundido com tamanho do array

```c
void f(int v[]) {
    printf("%zu\n", sizeof v);
}
```

Aqui `v` é tratado como ponteiro.

---

# 26. Debugging e ferramentas

## 26.1 Warnings

Não ignore warnings.

Compile com:

```bash
-Wall -Wextra -Wpedantic
```

## 26.2 Sanitizers

```bash
-fsanitize=address,undefined
```

AddressSanitizer ajuda a encontrar:

- buffer overflow;
- use-after-free;
- acessos inválidos.

UndefinedBehaviorSanitizer detecta diversas operações indefinidas.

## 26.3 GDB

Compilar:

```bash
gcc -g programa.c -o programa
```

Abrir:

```bash
gdb ./programa
```

Comandos fundamentais:

```text
break main
run
next
step
print x
display x
continue
backtrace
quit
```

## 26.4 Valgrind

Em sistemas onde estiver disponível:

```bash
valgrind --leak-check=full ./programa
```

Útil principalmente para investigar vazamentos e acessos de memória.


---

[← A02 C++ e POO](../A02-cpp-poo/) · [↑ Track A](../README.md) · [Próxima → A04 Algoritmos](../A04-algoritmos-estruturas-dados/)
