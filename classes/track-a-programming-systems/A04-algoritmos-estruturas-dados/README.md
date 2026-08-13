# Class — Algoritmos e Estruturas de Dados em C

> Um caderno de estudo e consulta para algoritmos e estruturas de dados implementados em C.
>
> Objetivo: aprender a organizar e transformar dados com correção e eficiência, mantendo visíveis os custos de tempo e memória. A [class de Linguagem C](../A03-c/) é o pré-requisito recomendado.

[← A03 C](../A03-c/) · [↑ Track A](../README.md) · [Próxima → A05 Assembly](../A05-assembly/)

---

# Sumário

1. [Fundamentos de algoritmos](#1-fundamentos-de-algoritmos)
2. [Complexidade assintótica](#2-complexidade-assintótica)
3. [Correção de algoritmos](#3-correção-de-algoritmos)
4. [Recursão](#4-recursão)
5. [Busca](#5-busca)
6. [Ordenação](#6-ordenação)
7. [Estruturas de dados: visão geral](#7-estruturas-de-dados-visão-geral)
8. [Arrays dinâmicos](#8-arrays-dinâmicos)
9. [Listas encadeadas](#9-listas-encadeadas)
10. [Pilhas](#10-pilhas)
11. [Filas](#11-filas)
12. [Deque](#12-deque)
13. [Tabelas hash](#13-tabelas-hash)
14. [Árvores binárias](#14-árvores-binárias)
15. [Árvores de busca binária](#15-árvores-de-busca-binária)
16. [Árvores balanceadas](#16-árvores-balanceadas)
17. [Heaps e filas de prioridade](#17-heaps-e-filas-de-prioridade)
18. [Grafos](#18-grafos)
19. [Busca em largura e profundidade](#19-busca-em-largura-e-profundidade)
20. [Union-Find / Disjoint Set](#20-union-find--disjoint-set)
21. [Padrões algorítmicos importantes](#21-padrões-algorítmicos-importantes)
22. [Como escolher uma estrutura de dados](#22-como-escolher-uma-estrutura-de-dados)
23. [Projeto e organização de código em C](#23-projeto-e-organização-de-código-em-c)
24. [Checklist mental para provas e implementação](#24-checklist-mental-para-provas-e-implementação)
25. [Ordem recomendada de estudo](#25-ordem-recomendada-de-estudo)
26. [Bibliografia](#26-bibliografia)

---

# 1. Fundamentos de algoritmos

Um algoritmo é uma sequência finita e bem definida de passos para resolver uma classe de problemas.

Um algoritmo deve ser analisado em pelo menos quatro dimensões:

1. correção;
2. tempo;
3. memória;
4. simplicidade/manutenibilidade.

Exemplo: encontrar maior elemento.

```c
int maximo(const int *v, size_t n) {
    int maior = v[0];

    for (size_t i = 1; i < n; i++) {
        if (v[i] > maior) {
            maior = v[i];
        }
    }

    return maior;
}
```

A ideia fundamental é:

```text
varrer os elementos uma única vez
```

---

# 2. Complexidade assintótica

Queremos entender como o custo cresce quando a entrada cresce.

## 2.1 Big-O

Limite superior assintótico.

Exemplo:

```text
O(n)
```

## 2.2 Big-Omega

Limite inferior assintótico:

```text
Ω(n)
```

## 2.3 Big-Theta

Limite assintótico apertado:

```text
Θ(n)
```

## 2.4 Complexidades comuns

Da melhor para a pior, aproximadamente:

```text
O(1)
O(log n)
O(n)
O(n log n)
O(n²)
O(n³)
O(2^n)
O(n!)
```

## 2.5 Exemplos

### Constante

```c
x = v[10];
```

```text
O(1)
```

### Linear

```c
for (size_t i = 0; i < n; i++) {
    ...
}
```

```text
O(n)
```

### Quadrática

```c
for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
        ...
    }
}
```

```text
O(n²)
```

### Logarítmica

```c
while (n > 1) {
    n /= 2;
}
```

```text
O(log n)
```

## 2.6 Ignore constantes assintoticamente

```text
3n + 7
```

é:

```text
O(n)
```

Mas isso não significa que constantes não importam na prática.

---

# 3. Correção de algoritmos

Não basta funcionar em alguns testes.

Precisamos raciocinar sobre todos os casos válidos.

## 3.1 Pré-condição

O que deve ser verdadeiro antes.

Exemplo:

```text
array está ordenado
```

para busca binária.

## 3.2 Pós-condição

O que garantimos depois.

Exemplo:

```text
retorna o índice do elemento ou -1 se não existir
```

## 3.3 Invariante de laço

Propriedade verdadeira antes/depois de cada iteração.

Exemplo ao buscar máximo:

```text
antes da iteração i,
maior é o maior valor de v[0..i-1]
```

Esse tipo de raciocínio é extremamente poderoso.

---

# 4. Recursão

Uma função recursiva chama a si mesma.

Exemplo:

```c
unsigned long long fatorial(unsigned int n) {
    if (n <= 1) {
        return 1;
    }

    return n * fatorial(n - 1);
}
```

Toda recursão precisa de:

1. caso base;
2. progresso em direção ao caso base.

## 4.1 Pilha de chamadas

```c
fatorial(4)
```

gera conceitualmente:

```text
fatorial(4)
  fatorial(3)
    fatorial(2)
      fatorial(1)
```

Cada chamada ocupa um frame.

Recursões muito profundas podem causar stack overflow.

## 4.2 Recursão versus iteração

Fatorial iterativo:

```c
unsigned long long fatorial(unsigned int n) {
    unsigned long long resultado = 1;

    for (unsigned int i = 2; i <= n; i++) {
        resultado *= i;
    }

    return resultado;
}
```

Recursão é especialmente natural para:

- árvores;
- divide-and-conquer;
- DFS;
- backtracking.

---

# 5. Busca

## 5.1 Busca linear

```c
int busca_linear(const int *v, size_t n, int alvo) {
    for (size_t i = 0; i < n; i++) {
        if (v[i] == alvo) {
            return (int)i;
        }
    }

    return -1;
}
```

Complexidade:

```text
O(n)
```

## 5.2 Busca binária

Requer array ordenado.

```c
int busca_binaria(const int *v, size_t n, int alvo) {
    size_t inicio = 0;
    size_t fim = n;

    while (inicio < fim) {
        size_t meio = inicio + (fim - inicio) / 2;

        if (v[meio] == alvo) {
            return (int)meio;
        }

        if (v[meio] < alvo) {
            inicio = meio + 1;
        } else {
            fim = meio;
        }
    }

    return -1;
}
```

Complexidade:

```text
O(log n)
```

A cada passo eliminamos aproximadamente metade do espaço de busca.

---

# 6. Ordenação

Ordenação aparece constantemente em algoritmos.

Propriedades importantes:

- complexidade;
- estabilidade;
- uso de memória adicional;
- comportamento no pior caso;
- adaptação a entradas quase ordenadas.

---

## 6.1 Bubble Sort

Ideia:

> trocar vizinhos fora de ordem repetidamente.

```c
void bubble_sort(int *v, size_t n) {
    for (size_t fim = n; fim > 1; fim--) {
        bool trocou = false;

        for (size_t i = 0; i + 1 < fim; i++) {
            if (v[i] > v[i + 1]) {
                int temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;

                trocou = true;
            }
        }

        if (!trocou) {
            break;
        }
    }
}
```

Complexidade típica:

```text
O(n²)
```

Didaticamente útil, mas raramente é a melhor escolha prática.

---

## 6.2 Selection Sort

A cada passo:

> encontre o menor restante e coloque na posição correta.

```c
void selection_sort(int *v, size_t n) {
    for (size_t i = 0; i < n; i++) {
        size_t menor = i;

        for (size_t j = i + 1; j < n; j++) {
            if (v[j] < v[menor]) {
                menor = j;
            }
        }

        int temp = v[i];
        v[i] = v[menor];
        v[menor] = temp;
    }
}
```

Complexidade:

```text
O(n²)
```

Faz relativamente poucas trocas.

---

## 6.3 Insertion Sort

Mantém um prefixo ordenado.

```c
void insertion_sort(int *v, size_t n) {
    for (size_t i = 1; i < n; i++) {
        int chave = v[i];
        size_t j = i;

        while (j > 0 && v[j - 1] > chave) {
            v[j] = v[j - 1];
            j--;
        }

        v[j] = chave;
    }
}
```

Pior caso:

```text
O(n²)
```

Mas é excelente para:

- arrays pequenos;
- entradas quase ordenadas;
- etapas internas de algoritmos híbridos.

---

## 6.4 Merge Sort

Estratégia:

```text
divida
ordene as metades
intercale
```

Complexidade:

```text
O(n log n)
```

Precisa normalmente de memória auxiliar `O(n)` para arrays.

É estável quando implementado adequadamente.

---

## 6.5 Quick Sort

Estratégia:

1. escolha pivô;
2. particione;
3. elementos menores de um lado;
4. maiores do outro;
5. recorra.

Média:

```text
O(n log n)
```

Pior caso:

```text
O(n²)
```

Na prática pode ser extremamente eficiente.

---

## 6.6 Heap Sort

Usa um heap.

Complexidade:

```text
O(n log n)
```

Memória adicional:

```text
O(1)
```

para implementação in-place tradicional.

---

## 6.7 Comparação simplificada

| Algoritmo | Melhor | Médio | Pior | Memória extra | Estável |
|---|---:|---:|---:|---:|---|
| Bubble | O(n) | O(n²) | O(n²) | O(1) | sim |
| Selection | O(n²) | O(n²) | O(n²) | O(1) | não |
| Insertion | O(n) | O(n²) | O(n²) | O(1) | sim |
| Merge | O(n log n) | O(n log n) | O(n log n) | O(n) | sim |
| Quick | O(n log n) | O(n log n) | O(n²) | O(log n) típico | não |
| Heap | O(n log n) | O(n log n) | O(n log n) | O(1) | não |

---

# 7. Estruturas de dados: visão geral

Uma estrutura de dados é uma forma organizada de representar dados para favorecer determinadas operações.

Nenhuma estrutura é universalmente melhor.

A pergunta correta é:

> Quais operações precisam ser rápidas?

Exemplos:

| Estrutura | Boa para |
|---|---|
| Array | acesso por índice |
| Lista | inserção/remoção via nós conhecidos |
| Pilha | LIFO |
| Fila | FIFO |
| Hash table | lookup médio rápido |
| BST | dados ordenados |
| Heap | mínimo/máximo |
| Grafo | relações gerais |

---

# 8. Arrays dinâmicos

Array convencional:

```c
int v[100];
```

tem capacidade fixa.

Um array dinâmico pode guardar:

```c
typedef struct {
    int *dados;
    size_t tamanho;
    size_t capacidade;
} Vetor;
```

Invariante:

```text
0 <= tamanho <= capacidade
```

Quando cheio:

```text
capacidade nova ≈ capacidade antiga * 2
```

Isso torna inserção no final:

```text
O(1) amortizado
```

mesmo que algumas inserções específicas custem `O(n)` por causa do `realloc`.

## 8.1 Crescimento geométrico

Se crescermos:

```text
1
2
4
8
16
32
...
```

não realocamos a cada inserção.

Essa é a base de estruturas como:

```text
std::vector
ArrayList
list dinâmicas internas de runtimes
```

---

# 9. Listas encadeadas

## 9.1 Lista simplesmente encadeada

```c
typedef struct Node {
    int valor;
    struct Node *proximo;
} Node;
```

Visualmente:

```text
head
 ↓
+---+---+    +---+---+    +---+------+
| 5 | •----->| 8 | •----->| 2 | NULL |
+---+---+    +---+---+    +---+------+
```

## 9.2 Inserção no início

```c
bool lista_push_front(Node **head, int valor) {
    Node *novo = malloc(sizeof *novo);

    if (novo == NULL) {
        return false;
    }

    novo->valor = valor;
    novo->proximo = *head;

    *head = novo;

    return true;
}
```

Complexidade:

```text
O(1)
```

## 9.3 Busca

```c
Node *lista_buscar(Node *head, int alvo) {
    for (Node *atual = head; atual != NULL; atual = atual->proximo) {
        if (atual->valor == alvo) {
            return atual;
        }
    }

    return NULL;
}
```

Complexidade:

```text
O(n)
```

## 9.4 Liberação

```c
void lista_destruir(Node **head) {
    Node *atual = *head;

    while (atual != NULL) {
        Node *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    *head = NULL;
}
```

Observe a ordem:

```text
salvar próximo
liberar atual
avançar
```

Depois de `free(atual)`, não podemos confiar em `atual->proximo`.

---

# 10. Pilhas

Pilha segue:

```text
LIFO
Last In, First Out
```

Operações:

```text
push
pop
top/peek
is_empty
```

Exemplo:

```text
push(10)
push(20)
push(30)

top → 30
pop → 30
pop → 20
```

Pode ser implementada com:

- array;
- array dinâmico;
- lista encadeada.

Aplicações:

- pilha de chamadas;
- parsing;
- undo;
- DFS;
- avaliação de expressões;
- balanceamento de delimitadores.

---

# 11. Filas

Fila segue:

```text
FIFO
First In, First Out
```

Operações:

```text
enqueue
dequeue
front
is_empty
```

Aplicações:

- BFS;
- filas de tarefas;
- buffers;
- schedulers;
- processamento de eventos.

## 11.1 Fila circular em array

Em vez de mover todos os elementos após uma remoção:

```text
[ ][ ][ ][ ][ ]
 ↑
head

tail
```

mantemos índices:

```c
size_t inicio;
size_t fim;
size_t tamanho;
```

e usamos módulo:

```c
fim = (fim + 1) % capacidade;
```

---

# 12. Deque

Deque significa:

```text
double-ended queue
```

Permite:

- inserir no início;
- inserir no fim;
- remover do início;
- remover do fim.

Pode ser usado em:

- sliding window;
- BFS especializado;
- caches;
- algoritmos monotônicos.

---

# 13. Tabelas hash

Objetivo:

> mapear uma chave para uma posição.

Conceitualmente:

```text
chave
 ↓
hash(chave)
 ↓
índice
 ↓
bucket
```

Exemplo:

```text
"antonio" → 918273 → bucket 5
```

## 13.1 Operações médias

Com boa implementação:

```text
inserção  O(1) médio
busca     O(1) médio
remoção   O(1) médio
```

Pior caso:

```text
O(n)
```

## 13.2 Colisões

Duas chaves podem produzir o mesmo bucket.

Estratégias:

### Separate chaining

Cada bucket contém uma lista.

```text
bucket 0 → ...
bucket 1 → A → B → C
bucket 2 → ...
```

### Open addressing

Os elementos ficam no próprio array.

Estratégias:

```text
linear probing
quadratic probing
double hashing
```

## 13.3 Load factor

```text
α = quantidade_de_elementos / quantidade_de_buckets
```

Quando a tabela fica cheia demais, é comum fazer `rehash`.

---

# 14. Árvores binárias

Cada nó possui no máximo dois filhos.

```c
typedef struct Node {
    int valor;
    struct Node *esquerda;
    struct Node *direita;
} Node;
```

Exemplo:

```text
        10
       /  \
      5    20
     / \
    2   8
```

## 14.1 Percursos

### Pré-ordem

```text
raiz
esquerda
direita
```

### Em ordem

```text
esquerda
raiz
direita
```

### Pós-ordem

```text
esquerda
direita
raiz
```

Implementação em ordem:

```c
void inorder(const Node *raiz) {
    if (raiz == NULL) {
        return;
    }

    inorder(raiz->esquerda);
    printf("%d\n", raiz->valor);
    inorder(raiz->direita);
}
```

---

# 15. Árvores de busca binária

BST mantém:

```text
valores menores → esquerda
valores maiores → direita
```

Exemplo:

```text
        10
       /  \
      5    15
     / \     \
    2   8     20
```

Busca:

```c
Node *bst_buscar(Node *raiz, int alvo) {
    while (raiz != NULL) {
        if (alvo == raiz->valor) {
            return raiz;
        }

        if (alvo < raiz->valor) {
            raiz = raiz->esquerda;
        } else {
            raiz = raiz->direita;
        }
    }

    return NULL;
}
```

Complexidade depende da altura `h`:

```text
O(h)
```

Árvore balanceada:

```text
h ≈ log n
```

Árvore degenerada:

```text
h ≈ n
```

---

# 16. Árvores balanceadas

Uma BST comum pode virar:

```text
1
 \
  2
   \
    3
     \
      4
```

Isso se comporta como uma lista.

Estruturas balanceadas mantêm altura próxima de:

```text
O(log n)
```

Exemplos:

- AVL;
- Red-Black Tree.

## 16.1 AVL

Para cada nó, controla-se o fator de balanceamento:

```text
altura(esquerda) - altura(direita)
```

normalmente limitado a:

```text
-1, 0, +1
```

Quando necessário, executam-se rotações.

---

# 17. Heaps e filas de prioridade

Um heap binário é normalmente representado por um array.

Max-heap:

```text
pai >= filhos
```

Min-heap:

```text
pai <= filhos
```

Para índice `i`, usando indexação começando em zero:

```text
filho esquerdo = 2*i + 1
filho direito  = 2*i + 2
pai            = (i - 1) / 2
```

## 17.1 Operações

```text
peek        O(1)
inserção    O(log n)
remoção     O(log n)
heapify     O(n)
```

Aplicações:

- filas de prioridade;
- Dijkstra;
- scheduling;
- top-k;
- heap sort.

---

# 18. Grafos

Um grafo:

```text
G = (V, E)
```

onde:

```text
V = vértices
E = arestas
```

Pode ser:

- direcionado;
- não direcionado;
- ponderado;
- não ponderado;
- cíclico;
- acíclico.

## 18.1 Matriz de adjacência

```text
    A B C
A   0 1 1
B   1 0 0
C   1 0 0
```

Memória:

```text
O(V²)
```

Teste de aresta:

```text
O(1)
```

## 18.2 Lista de adjacência

```text
A → B → C
B → A
C → A
```

Memória:

```text
O(V + E)
```

Normalmente melhor para grafos esparsos.

---

# 19. Busca em largura e profundidade

## 19.1 BFS — Breadth-First Search

Usa uma fila.

Explora por níveis.

```text
origem
 ↓
distância 1
 ↓
distância 2
 ↓
distância 3
```

Em grafos não ponderados, encontra caminhos mínimos em número de arestas.

Complexidade:

```text
O(V + E)
```

com lista de adjacência.

## 19.2 DFS — Depth-First Search

Usa:

- recursão; ou
- pilha explícita.

Explora profundamente antes de voltar.

Aplicações:

- detecção de ciclos;
- componentes conexos;
- ordenação topológica;
- backtracking;
- análise de árvores.

Complexidade:

```text
O(V + E)
```

---

# 20. Union-Find / Disjoint Set

Mantém conjuntos disjuntos.

Operações:

```text
find(x)
union(a, b)
```

Muito útil em:

- Kruskal;
- conectividade dinâmica;
- agrupamento de componentes.

Otimizações:

```text
path compression
union by rank/size
```

produzem custo amortizado extremamente baixo.

---

# 21. Padrões algorítmicos importantes

Mais importante que memorizar algoritmos isolados é reconhecer padrões.

## 21.1 Brute force

Testar possibilidades diretamente.

É frequentemente o ponto inicial correto.

## 21.2 Two pointers

Dois índices percorrendo uma estrutura.

Exemplo:

```text
i →          ← j
```

Útil em:

- arrays ordenados;
- particionamento;
- pares;
- substrings.

## 21.3 Sliding window

Mantém uma janela:

```text
[l ........ r]
```

e atualiza incrementalmente.

Muito útil para:

- subarrays;
- substrings;
- somas em janelas;
- frequência de elementos.

## 21.4 Divide and conquer

```text
dividir
resolver subproblemas
combinar
```

Exemplos:

- merge sort;
- quicksort;
- busca binária.

## 21.5 Greedy

A cada etapa escolhe uma opção localmente promissora.

É preciso provar que escolhas locais levam à solução global.

## 21.6 Backtracking

Explora possibilidades e desfaz decisões.

```text
escolhe
explora
desfaz
```

Exemplos:

- sudoku;
- permutações;
- N-rainhas.

## 21.7 Dynamic Programming

Usado quando existem:

- subproblemas sobrepostos;
- estrutura ótima reutilizável.

Ideias:

```text
memoization
tabulation
```

Não confunda DP com "usar array".

DP é uma estratégia de decomposição e reutilização de soluções.

---

# 22. Como escolher uma estrutura de dados

Pergunte:

## Preciso de acesso por índice rápido?

Use:

```text
array / vetor dinâmico
```

## Preciso inserir/remover frequentemente no início?

Considere:

```text
lista
deque
```

## Preciso de LIFO?

```text
pilha
```

## Preciso de FIFO?

```text
fila
```

## Preciso buscar por chave rapidamente?

```text
hash table
```

## Preciso manter elementos ordenados?

```text
árvore balanceada
```

## Preciso sempre obter mínimo/máximo?

```text
heap
```

## Preciso representar relações arbitrárias?

```text
grafo
```

---

# 23. Projeto e organização de código em C

Uma estrutura razoável:

```text
projeto/
├── include/
│   ├── lista.h
│   ├── fila.h
│   └── arvore.h
│
├── src/
│   ├── lista.c
│   ├── fila.c
│   ├── arvore.c
│   └── main.c
│
├── tests/
│   └── ...
│
├── Makefile
└── README.md
```

## 23.1 Interface versus implementação

Header:

```c
typedef struct Lista Lista;

Lista *lista_criar(void);
void lista_destruir(Lista *lista);

bool lista_inserir(Lista *lista, int valor);
```

Implementação:

```c
struct Lista {
    ...
};
```

Isso permite esconder detalhes internos.

É uma forma de encapsulamento em C.

## 23.2 Tipo opaco

No header:

```c
typedef struct Grafo Grafo;
```

O usuário da API sabe que `Grafo` existe, mas não conhece seu layout.

Isso aproxima C de conceitos de abstração encontrados em POO.

---

# 24. Checklist mental para provas e implementação

Quando receber um problema, pense nesta ordem:

## 1. Qual é a entrada?

```text
quantidade?
tipo?
limites?
ordenada?
pode repetir?
```

## 2. Qual é a saída?

```text
valor?
índice?
estrutura?
sim/não?
caminho?
```

## 3. Qual propriedade posso explorar?

```text
dados ordenados?
grafo acíclico?
valores positivos?
intervalos?
repetições?
```

## 4. Qual seria a solução ingênua?

Descobrir o brute force ajuda a entender o problema.

## 5. Qual é a complexidade dela?

```text
O(n)?
O(n²)?
O(2^n)?
```

## 6. Existe uma estrutura melhor?

Pergunte se você precisa de:

```text
lookup       → hash
mínimo       → heap
ordenação    → árvore/sort
FIFO         → fila
LIFO         → pilha
conectividade→ union-find
```

## 7. Quais são os invariantes?

Antes de codificar, escreva mentalmente o que precisa permanecer verdadeiro.

## 8. Quais casos extremos existem?

Sempre pense em:

```text
n = 0
n = 1
todos iguais
já ordenado
ordem inversa
valor mínimo
valor máximo
duplicatas
NULL
falha de malloc
```

## 9. Quem possui a memória?

Para cada ponteiro:

```text
quem criou?
quem pode modificar?
quem deve liberar?
quanto tempo deve existir?
```

## 10. Posso provar que termina?

Especialmente para:

- recursão;
- loops complexos;
- busca;
- backtracking.

---

# 25. Ordem recomendada de estudo

A ideia é estudar em camadas.

---

## Camada 1 — C essencial

Domine:

1. compilação;
2. tipos;
3. operadores;
4. `if`;
5. `for`;
6. `while`;
7. funções;
8. arrays.

Você deve conseguir escrever pequenos programas sem consultar sintaxe constantemente.

---

## Camada 2 — Modelo de memória

Depois domine:

1. endereço;
2. ponteiros;
3. `&`;
4. `*`;
5. arrays e ponteiros;
6. strings;
7. structs;
8. stack versus heap;
9. `malloc`;
10. `free`.

Esta é a etapa em que C começa a fazer sentido de verdade.

---

## Camada 3 — Algoritmos fundamentais

Estude:

1. análise de complexidade;
2. invariantes;
3. busca linear;
4. busca binária;
5. insertion sort;
6. selection sort;
7. merge sort;
8. quicksort;
9. recursão.

---

## Camada 4 — Estruturas lineares

Implemente conceitualmente:

1. vetor dinâmico;
2. lista simplesmente encadeada;
3. lista duplamente encadeada;
4. pilha;
5. fila;
6. deque.

Aqui ponteiros deixam de ser teoria.

---

## Camada 5 — Estruturas associativas e árvores

Estude:

1. hash tables;
2. árvores binárias;
3. BST;
4. AVL;
5. heaps;
6. filas de prioridade.

---

## Camada 6 — Grafos

Estude:

1. representação;
2. matriz de adjacência;
3. lista de adjacência;
4. BFS;
5. DFS;
6. componentes conexos;
7. ciclos;
8. shortest path;
9. MST;
10. union-find.

---

## Camada 7 — Projeto real em C

Por fim, pratique:

- múltiplos `.c`;
- headers;
- APIs;
- ownership;
- tipos opacos;
- Makefiles;
- sanitizers;
- GDB;
- testes.

O objetivo final é olhar para:

```c
Node **head
```

ou:

```c
void *data
```

ou:

```c
int (*cmp)(const void *, const void *)
```

e enxergar imediatamente a estrutura de memória e o fluxo de dados envolvidos.

---

# 26. Bibliografia

## Linguagem C

### Brian Kernighan & Dennis Ritchie
**The C Programming Language**

O clássico.

É curto e extremamente denso.

---

### Jens Gustedt
**Modern C**

Excelente para compreender C de forma mais moderna e rigorosa.

---

### K. N. King
**C Programming: A Modern Approach**

Muito didático e completo.

---

## Algoritmos e Estruturas de Dados

### Thomas H. Cormen, Charles Leiserson, Ronald Rivest, Clifford Stein
**Introduction to Algorithms — CLRS**

Referência teórica extremamente abrangente.

---

### Robert Sedgewick
**Algorithms in C**

Especialmente interessante por implementar diretamente as estruturas e algoritmos em C.

---

### Jon Bentley
**Programming Pearls**

Excelente para desenvolver raciocínio algorítmico.

---

# Mapa conceitual final

```text
                    COMPUTADOR
                        │
                        ▼
                 memória + CPU
                        │
                        ▼
                   linguagem C
          ┌─────────────┼─────────────┐
          ▼             ▼             ▼
       tipos         ponteiros      funções
          │             │             │
          └───────┬─────┴─────┬───────┘
                  ▼           ▼
               arrays       structs
                  │           │
                  └─────┬─────┘
                        ▼
                estruturas de dados
                        │
        ┌───────────────┼────────────────┐
        ▼               ▼                ▼
      listas          árvores          grafos
        │               │                │
        └───────────────┼────────────────┘
                        ▼
                    algoritmos
                        │
          ┌─────────────┼──────────────┐
          ▼             ▼              ▼
        busca         ordenação      travessia
          │             │              │
          └─────────────┼──────────────┘
                        ▼
                  complexidade
                        │
                        ▼
              engenharia de software
```

---

# Ideia central

A grande conexão entre as três matérias é:

```text
C explica como os dados existem.

Estruturas de Dados explicam como organizá-los.

Algoritmos explicam como transformá-los eficientemente.
```

Quando essas três coisas se encaixam, você começa a enxergar um programa não apenas como código, mas como:

```text
estado
+
memória
+
transformações
+
custos
```

Esse é um dos melhores caminhos para realmente aprender a "conversar com a máquina".

---

[← A03 C](../A03-c/) · [↑ Track A](../README.md) · [Próxima → A05 Assembly](../A05-assembly/)
