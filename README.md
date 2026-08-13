# Courses

Repositório pessoal de estudo e consulta, organizado como uma trilha progressiva de fundamentos de computação, programação, sistemas, matemática e inteligência artificial.

A proposta deste repositório não é apenas acumular anotações sobre tecnologias isoladas. O objetivo é construir um modelo mental contínuo da computação, conectando:

```text
Matemática
    ↓
Algoritmos
    ↓
Linguagens de alto nível
    ↓
C / C++
    ↓
Assembly
    ↓
ISA
    ↓
Arquitetura de Computadores
    ↓
Sistema Operacional
    ↓
Containers / Redes / Sistemas Distribuídos
    ↓
Machine Learning
    ↓
Sistemas de IA
```

Cada masterclass funciona como:

- material de estudo;
- caderno de consulta;
- referência rápida;
- base para experimentos;
- ponto de conexão com as demais áreas.

---

# Estrutura do repositório

```text
Courses/
│
├── README.md
│
└── classes/
    │
    ├── 01-python/
    ├── 02-cpp-poo/
    ├── 03-c/
    ├── 04-algoritmos-estruturas-dados/
    ├── 05-assembly/
    ├── 06-arquitetura-computadores/
    ├── 07-memoria-representacao-dados/
    ├── 08-sistemas-operacionais/
    ├── 09-linux-systems/
    ├── 10-containers-docker/
    ├── 11-redes-computadores/
    ├── 12-concorrencia-paralelismo/
    ├── 13-compiladores/
    ├── 14-performance-engineering/
    ├── 15-bancos-dados-internals/
    ├── 16-sistemas-distribuidos/
    ├── 17-seguranca-sistemas/
    ├── 18-criptografia/
    ├── 19-algebra-linear-computacional/
    ├── 20-calculo-numerico/
    ├── 21-redes-neurais-do-zero/
    ├── 22-gpu-cuda/
    ├── 23-runtimes-vms/
    ├── 24-cpp-systems/
    ├── 25-arquitetura-sistemas-ia/
    └── 26-teoria-computacao/
```

Cada pasta pode conter:

```text
README.md
examples/
exercises/
notes/
assets/
```

Exemplo:

```text
classes/
└── 05-assembly/
    ├── README.md
    ├── examples/
    ├── exercises/
    └── notes/
```

---

# Convenção de organização

Cada curso recebe um número que representa sua posição principal na trilha:

```text
05-assembly
06-arquitetura-computadores
07-memoria-representacao-dados
```

O arquivo principal da masterclass fica como:

```text
classes/<curso>/README.md
```

Assim, ao entrar em qualquer pasta pelo GitHub, o conteúdo da aula já aparece automaticamente.

Arquivos complementares podem ser organizados em:

```text
examples/
exercises/
notes/
assets/
```

---

# Mapa geral de aprendizado

A sequência completa está dividida em grandes camadas.

---

## Camada 1 — Linguagens e fundamentos de programação

Objetivo:

> adquirir fluência para expressar algoritmos em diferentes níveis de abstração.

### 01 — Python

**Status:** concluída

Tópicos principais:

- sintaxe;
- tipos;
- estruturas de dados;
- funções;
- iteradores;
- generators;
- decorators;
- orientação a objetos;
- exceções;
- módulos;
- typing;
- async;
- ecossistema da linguagem.

Pasta:

```text
classes/01-python/
```

---

### 02 — C++ e Programação Orientada a Objetos

**Status:** concluída

Tópicos principais:

- sintaxe C++;
- classes;
- objetos;
- encapsulamento;
- herança;
- polimorfismo;
- templates;
- STL;
- referências;
- ponteiros;
- RAII;
- fundamentos de C++ moderno.

Pasta:

```text
classes/02-cpp-poo/
```

---

### 03 — C

**Status:** em estudo

Objetivo:

> aprender a programar próximo da máquina e compreender explicitamente memória e representação.

Tópicos:

- tipos;
- arrays;
- strings;
- structs;
- ponteiros;
- aritmética de ponteiros;
- memória;
- `malloc`;
- `calloc`;
- `realloc`;
- `free`;
- compilação;
- headers;
- linking;
- undefined behavior.

Pasta:

```text
classes/03-c/
```

---

### 04 — Algoritmos e Estruturas de Dados em C

**Status:** em estudo

Objetivo:

> compreender não apenas os algoritmos, mas como suas estruturas existem fisicamente na memória.

Tópicos:

- análise assintótica;
- arrays;
- listas;
- pilhas;
- filas;
- árvores;
- heaps;
- hash tables;
- grafos;
- busca;
- ordenação;
- recursão;
- union-find;
- tries;
- algoritmos clássicos.

Pasta:

```text
classes/04-algoritmos-estruturas-dados/
```

---

# Camada 2 — Conversando com a máquina

Esta camada conecta código de alto nível à execução física.

---

### 05 — Assembly x86-64

**Status:** concluída

Objetivo:

> entender como programas são representados em instruções próximas da ISA.

Principais tópicos:

- registradores;
- memória;
- `mov`;
- aritmética;
- bitwise;
- flags;
- jumps;
- stack;
- `call`;
- `ret`;
- System V AMD64 ABI;
- syscalls;
- ELF;
- linker;
- GDB;
- `objdump`;
- machine code;
- SIMD;
- C ↔ Assembly.

Pasta:

```text
classes/05-assembly/
```

---

### 06 — Arquitetura de Computadores

**Status:** concluída

Objetivo:

> compreender como o hardware executa as instruções vistas em Assembly.

Principais tópicos:

- lógica booleana;
- portas;
- flip-flops;
- registradores;
- ALU;
- clock;
- datapath;
- unidade de controle;
- CPU mínima;
- ISA;
- cache;
- pipeline;
- branch prediction;
- superscalar;
- out-of-order execution;
- register renaming;
- SIMD;
- multicore;
- GPU;
- PCIe;
- DMA.

Pasta:

```text
classes/06-arquitetura-computadores/
```

---

### 07 — Memória e Representação de Dados

**Status:** planejada

Objetivo:

> compreender como dados existem fisicamente e logicamente na máquina.

Tópicos:

- bits e bytes;
- hexadecimal;
- complemento de dois;
- signed vs unsigned;
- IEEE 754;
- endianness;
- alignment;
- padding;
- object layout;
- stack;
- heap;
- cache lines;
- locality;
- pointers;
- aliasing;
- virtual memory;
- page tables;
- TLB.

Pasta:

```text
classes/07-memoria-representacao-dados/
```

---

# Camada 3 — Sistema Operacional e ambiente de execução

---

### 08 — Sistemas Operacionais

**Status:** planejada

Objetivo:

> compreender como o sistema operacional cria a abstração de processos, memória e recursos.

Tópicos:

- kernel;
- user space;
- syscalls;
- processos;
- threads;
- scheduler;
- virtual memory;
- page faults;
- IPC;
- signals;
- file descriptors;
- pipes;
- filesystem;
- mmap;
- synchronization;
- protection rings.

Pasta:

```text
classes/08-sistemas-operacionais/
```

---

### 09 — Linux Systems

**Status:** planejada

Objetivo:

> conhecer Linux como plataforma de execução, administração e desenvolvimento.

Tópicos:

- processos;
- `/proc`;
- `/sys`;
- users/groups;
- permissions;
- capabilities;
- filesystem;
- mounts;
- systemd;
- services;
- logs;
- signals;
- devices;
- namespaces;
- networking;
- shell;
- observabilidade.

Pasta:

```text
classes/09-linux-systems/
```

---

### 10 — Containers e Docker Internals

**Status:** planejada

Objetivo:

> compreender containers como processos Linux isolados, não como máquinas virtuais mágicas.

Tópicos:

- namespaces;
- cgroups;
- capabilities;
- seccomp;
- OverlayFS;
- images;
- layers;
- container filesystem;
- OCI;
- `runc`;
- containerd;
- Docker Engine;
- Docker CLI;
- Compose;
- networking;
- volumes;
- rootless containers;
- segurança de containers.

Pasta:

```text
classes/10-containers-docker/
```

---

# Camada 4 — Comunicação e execução concorrente

---

### 11 — Redes de Computadores

**Status:** planejada

Objetivo:

> seguir dados desde um socket até os pacotes que atravessam uma rede.

Tópicos:

- Ethernet;
- MAC;
- ARP;
- IPv4/IPv6;
- routing;
- ICMP;
- UDP;
- TCP;
- sockets;
- DNS;
- HTTP;
- TLS;
- NAT;
- firewalls;
- packet capture;
- Wireshark;
- network namespaces.

Pasta:

```text
classes/11-redes-computadores/
```

---

### 12 — Concorrência e Programação Paralela

**Status:** planejada

Objetivo:

> compreender execução simultânea e os problemas causados por estado compartilhado.

Tópicos:

- processos;
- threads;
- race conditions;
- mutex;
- semaphore;
- condition variables;
- atomics;
- memory ordering;
- lock-free;
- deadlocks;
- false sharing;
- thread pools;
- task scheduling;
- data parallelism.

Pasta:

```text
classes/12-concorrencia-paralelismo/
```

---

# Camada 5 — Como linguagens viram programas

---

### 13 — Compiladores

**Status:** planejada

Objetivo:

> seguir código-fonte até o executável.

Fluxo principal:

```text
source
↓
lexer
↓
tokens
↓
parser
↓
AST
↓
semantic analysis
↓
IR
↓
optimization
↓
code generation
↓
Assembly
↓
object file
↓
linker
↓
executable
```

Tópicos:

- lexical analysis;
- parsing;
- grammars;
- AST;
- semantic analysis;
- IR;
- SSA;
- optimizations;
- code generation;
- assembler;
- linker;
- loader;
- ELF;
- symbols;
- relocations.

Pasta:

```text
classes/13-compiladores/
```

---

### 14 — Performance Engineering

**Status:** planejada

Objetivo:

> responder com evidências à pergunta: "por que este programa está lento?"

Tópicos:

- benchmarking;
- profiling;
- flame graphs;
- `perf`;
- cache misses;
- branch misses;
- memory bandwidth;
- allocations;
- SIMD;
- compiler optimization;
- vectorization;
- CPU-bound;
- memory-bound;
- latency;
- throughput;
- roofline model.

Pasta:

```text
classes/14-performance-engineering/
```

---

# Camada 6 — Armazenamento e sistemas distribuídos

---

### 15 — Bancos de Dados por Dentro

**Status:** planejada

Objetivo:

> entender como bancos realmente armazenam, indexam e protegem dados.

Tópicos:

- pages;
- B-trees;
- B+ trees;
- hash indexes;
- buffer pool;
- WAL;
- transactions;
- ACID;
- isolation;
- MVCC;
- locks;
- query planner;
- joins;
- storage engines;
- PostgreSQL internals.

Pasta:

```text
classes/15-bancos-dados-internals/
```

---

### 16 — Sistemas Distribuídos

**Status:** planejada

Objetivo:

> compreender sistemas que precisam continuar funcionando apesar de rede, concorrência e falhas.

Tópicos:

- partial failure;
- clocks;
- ordering;
- replication;
- consensus;
- leader election;
- leases;
- retries;
- idempotency;
- queues;
- eventual consistency;
- CAP;
- distributed transactions;
- fault tolerance.

Pasta:

```text
classes/16-sistemas-distribuidos/
```

---

# Camada 7 — Segurança

---

### 17 — Segurança de Sistemas

**Status:** planejada

Tópicos:

- memória insegura;
- buffer overflow;
- stack corruption;
- ASLR;
- NX;
- stack canaries;
- ROP;
- privilege boundaries;
- sandboxing;
- Linux capabilities;
- process isolation;
- authentication;
- authorization;
- secure coding.

Pasta:

```text
classes/17-seguranca-sistemas/
```

---

### 18 — Criptografia para Programadores

**Status:** planejada

Tópicos:

- entropy;
- random numbers;
- hashes;
- MAC;
- authenticated encryption;
- symmetric cryptography;
- public-key cryptography;
- signatures;
- key exchange;
- nonces;
- certificates;
- PKI;
- TLS;
- key management.

Pasta:

```text
classes/18-criptografia/
```

---

# Camada 8 — Computação científica e Machine Learning

---

### 19 — Álgebra Linear Computacional

**Status:** planejada

Objetivo:

> entender como álgebra linear é executada eficientemente por computadores.

Tópicos:

- vectors;
- matrices;
- matrix multiplication;
- memory layout;
- BLAS;
- decompositions;
- sparse matrices;
- numerical stability;
- SIMD;
- parallel computation;
- GPU acceleration.

Pasta:

```text
classes/19-algebra-linear-computacional/
```

---

### 20 — Cálculo Numérico e Computação Científica

**Status:** planejada

Tópicos:

- floating point;
- approximation error;
- conditioning;
- numerical stability;
- root finding;
- interpolation;
- differentiation;
- integration;
- linear systems;
- optimization;
- iterative methods;
- eigenvalues.

Pasta:

```text
classes/20-calculo-numerico/
```

---

### 21 — Redes Neurais do Zero

**Status:** planejada

Objetivo:

> compreender redes neurais desde as equações até sua execução na máquina.

Sequência sugerida:

```text
Python puro
↓
C++
↓
Assembly gerado
↓
SIMD / GPU
```

Tópicos:

- perceptron;
- dense layers;
- activations;
- loss;
- gradient descent;
- chain rule;
- backpropagation;
- initialization;
- normalization;
- optimizers;
- convolutions;
- attention;
- transformers.

Pasta:

```text
classes/21-redes-neurais-do-zero/
```

---

### 22 — GPU Computing e CUDA

**Status:** planejada

Objetivo:

> entender como workloads paralelos e ML realmente utilizam GPUs.

Tópicos:

- CPU vs GPU;
- kernels;
- threads;
- blocks;
- grids;
- warps;
- memory hierarchy;
- global memory;
- shared memory;
- registers;
- coalescing;
- synchronization;
- occupancy;
- tensor cores;
- matrix multiplication.

Pasta:

```text
classes/22-gpu-cuda/
```

---

# Camada 9 — Linguagens e runtimes avançados

---

### 23 — Runtimes e Máquinas Virtuais

**Status:** planejada

Objetivo:

> entender o que existe entre uma linguagem de alto nível e a CPU.

Tópicos:

- interpreters;
- bytecode;
- virtual machines;
- CPython;
- JVM;
- JIT;
- garbage collection;
- reference counting;
- object representation;
- dynamic dispatch;
- runtime memory management.

Pasta:

```text
classes/23-runtimes-vms/
```

---

### 24 — C++ para Systems Programming

**Status:** planejada

Objetivo:

> avançar do C++ orientado a objetos para C++ de infraestrutura e alto desempenho.

Tópicos:

- RAII;
- ownership;
- move semantics;
- templates;
- concepts;
- smart pointers;
- allocators;
- memory model;
- concurrency;
- zero-cost abstractions;
- error handling;
- ABI;
- systems design.

Pasta:

```text
classes/24-cpp-systems/
```

---

# Camada 10 — Sistemas de Inteligência Artificial

---

### 25 — Arquitetura de Sistemas de IA

**Status:** planejada

Objetivo:

> compreender como modelos deixam de ser experimentos isolados e se tornam sistemas.

Tópicos:

- inference runtimes;
- model serving;
- batching;
- quantization;
- KV cache;
- embeddings;
- retrieval;
- vector databases;
- model routing;
- scheduling;
- tool execution;
- memory systems;
- distributed inference;
- observability;
- fault tolerance;
- agent runtimes.

Pasta:

```text
classes/25-arquitetura-sistemas-ia/
```

---

# Camada 11 — Fundamentos teóricos

---

### 26 — Teoria da Computação

**Status:** planejada

Objetivo:

> entender os limites e fundamentos formais da própria computação.

Tópicos:

- formal languages;
- automata;
- regular languages;
- context-free grammars;
- Turing machines;
- computability;
- decidability;
- reductions;
- complexity;
- P vs NP;
- lambda calculus.

Pasta:

```text
classes/26-teoria-computacao/
```

---

# Trilha principal recomendada

A sequência central para compreender computadores de baixo para alto nível é:

```text
01 Python
   ↓
02 C++ / POO
   ↓
03 C
   ↓
04 Algoritmos e Estruturas de Dados
   ↓
05 Assembly
   ↓
06 Arquitetura de Computadores
   ↓
07 Memória e Representação de Dados
   ↓
08 Sistemas Operacionais
   ↓
09 Linux Systems
   ↓
10 Containers / Docker
   ↓
11 Redes
   ↓
12 Concorrência
   ↓
13 Compiladores
   ↓
14 Performance Engineering
   ↓
15 Bancos de Dados
   ↓
16 Sistemas Distribuídos
   ↓
17 Segurança
```

---

# Trilha de Machine Learning e IA

Pode ser estudada em paralelo depois que Python e matemática básica estiverem confortáveis:

```text
Python
  ↓
Álgebra Linear
  ↓
Cálculo Numérico
  ↓
Redes Neurais do Zero
  ↓
GPU / CUDA
  ↓
Arquitetura de Sistemas de IA
```

Com a trilha de sistemas por baixo:

```text
C / C++
   ↓
Assembly
   ↓
Arquitetura
   ↓
Performance
```

As duas eventualmente se encontram:

```text
              Machine Learning
                    │
                    ▼
Python ───► C/C++ ───► SIMD / CUDA
                    │
                    ▼
                 CPU / GPU
```

---

# Trilha de infraestrutura

```text
Sistemas Operacionais
        ↓
Linux
        ↓
Containers
        ↓
Redes
        ↓
Bancos de Dados
        ↓
Sistemas Distribuídos
        ↓
Segurança
```

---

# Trilha "como a máquina funciona"

Para revisar apenas o eixo mais fundamental:

```text
C
↓
Assembly
↓
Machine Code
↓
ISA
↓
CPU
↓
Caches
↓
RAM
↓
Sistema Operacional
```

Essa trilha deve permitir responder perguntas como:

```text
O que acontece quando executo uma função?

Onde uma variável existe?

Como um array é percorrido?

Por que um cache miss custa caro?

Como um syscall entra no kernel?

Como um container é isolado?

Como bytes atravessam a rede?

Como uma matriz chega a uma GPU?
```

---

# Método de estudo

Para cada masterclass:

1. ler a teoria;
2. reproduzir os exemplos;
3. experimentar modificações;
4. observar o comportamento real;
5. conectar o tópico com a camada anterior;
6. criar pelo menos um pequeno projeto;
7. manter notas adicionais na pasta do curso.

A pergunta central deve ser:

> **Qual abstração está sendo construída nesta camada e o que existe imediatamente abaixo dela?**

Exemplo:

```text
Python list
↓
PyObject / runtime
↓
C
↓
memory allocation
↓
virtual memory
↓
physical memory
```

ou:

```text
docker run
↓
container runtime
↓
namespaces + cgroups
↓
Linux kernel
↓
process
```

---

# Estado atual

| # | Masterclass | Status |
|---:|---|---|
| 01 | Python | ✅ Concluída |
| 02 | C++ e POO | ✅ Concluída |
| 03 | C | 🟡 Em estudo |
| 04 | Algoritmos e Estruturas de Dados | 🟡 Em estudo |
| 05 | Assembly x86-64 | ✅ Concluída |
| 06 | Arquitetura de Computadores | ✅ Concluída |
| 07 | Memória e Representação de Dados | ⬜ Planejada |
| 08 | Sistemas Operacionais | ⬜ Planejada |
| 09 | Linux Systems | ⬜ Planejada |
| 10 | Containers e Docker | ⬜ Planejada |
| 11 | Redes de Computadores | ⬜ Planejada |
| 12 | Concorrência e Paralelismo | ⬜ Planejada |
| 13 | Compiladores | ⬜ Planejada |
| 14 | Performance Engineering | ⬜ Planejada |
| 15 | Bancos de Dados Internals | ⬜ Planejada |
| 16 | Sistemas Distribuídos | ⬜ Planejada |
| 17 | Segurança de Sistemas | ⬜ Planejada |
| 18 | Criptografia | ⬜ Planejada |
| 19 | Álgebra Linear Computacional | ⬜ Planejada |
| 20 | Cálculo Numérico | ⬜ Planejada |
| 21 | Redes Neurais do Zero | ⬜ Planejada |
| 22 | GPU / CUDA | ⬜ Planejada |
| 23 | Runtimes e Máquinas Virtuais | ⬜ Planejada |
| 24 | C++ para Systems Programming | ⬜ Planejada |
| 25 | Arquitetura de Sistemas de IA | ⬜ Planejada |
| 26 | Teoria da Computação | ⬜ Planejada |

---

# Princípio deste repositório

Este repositório parte de uma ideia simples:

> **Programar não é apenas conhecer sintaxe. É entender as camadas de abstração que transformam uma ideia em computação real.**

Por isso, sempre que possível, os cursos devem conectar:

```text
conceito
↓
implementação
↓
runtime
↓
sistema operacional
↓
hardware
```

A meta final não é decorar todas as tecnologias.

É conseguir olhar para um problema e entender:

```text
em qual camada ele pertence,
qual abstração está sendo usada,
qual custo ela possui,
e o que realmente acontece abaixo dela.
```
