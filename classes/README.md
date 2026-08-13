# Masterclasses — Índice e Roadmap

[← README principal](../README.md)

Este diretório contém as masterclasses do repositório. A numeração representa a **ordem principal recomendada**, mas algumas trilhas podem ser estudadas em paralelo.

---

## Sequência principal

```text
Fundamentos de programação
        │
        ▼
Python → C++ → C
                │
                ▼
      Algoritmos e Estruturas
                │
                ▼
             Assembly
                │
                ▼
     Arquitetura de Computadores
                │
                ▼
     Memória e Representação
                │
                ▼
       Sistemas Operacionais
                │
                ▼
              Linux
                │
                ▼
            Containers
                │
                ▼
              Redes
                │
                ▼
          Concorrência
                │
                ▼
           Compiladores
                │
                ▼
           Performance
```

Depois dessa base, as trilhas de **infraestrutura**, **segurança**, **computação científica** e **IA** ficam muito mais conectadas.

---

# I — Linguagens e algoritmos

## 01 — [Python](01-python/)

**Status:** ✅ disponível  
**Pré-requisitos:** lógica de programação  
**Objetivo:** dominar Python como linguagem de alto nível sem perder de vista seu modelo de objetos e runtime.

Conecta-se depois com:

```text
Runtimes / CPython
Machine Learning
Automação
Sistemas de IA
```

---

## 02 — [C++ e Programação Orientada a Objetos](02-cpp-poo/)

**Status:** ✅ disponível  
**Pré-requisitos:** lógica de programação  
**Objetivo:** aprender C++, POO, STL e gerenciamento de recursos, preparando terreno para C++ de sistemas.

Conecta-se depois com:

```text
C++
↓
Assembly
↓
Performance / Systems Programming
```

---

## 03 — [Linguagem C](03-c/)

**Status:** 🟡 em estudo/expansão  
**Pré-requisitos:** lógica de programação  
**Objetivo:** tornar explícitos memória, ponteiros, layout de dados, compilação e custo das operações.

Esta é uma das principais pontes para as camadas inferiores:

```text
C
├── memória
├── Assembly
├── SO
└── estruturas de dados
```

---

## 04 — [Algoritmos e Estruturas de Dados em C](04-algoritmos-estruturas-dados/)

**Status:** 🟡 em estudo/expansão  
**Pré-requisito recomendado:** [03 — C](03-c/)  
**Objetivo:** estudar algoritmos junto de seus custos temporais e espaciais e de sua representação concreta em memória.

---

# II — Máquina e hardware

## 05 — [Assembly x86-64](05-assembly/)

**Status:** ✅ disponível  
**Pré-requisito recomendado:** [03 — C](03-c/)  
**Objetivo:** entender registradores, instruções, memória, ABI, stack, syscalls e a ponte entre código compilado e ISA.

Fluxo mental:

```text
C / C++
↓
Assembly
↓
Machine Code
↓
ISA
```

---

## 06 — [Arquitetura de Computadores](06-arquitetura-computadores/)

**Status:** ✅ disponível  
**Pré-requisito recomendado:** [05 — Assembly](05-assembly/)  
**Objetivo:** entender como a máquina executa as instruções: lógica digital, ALU, datapath, controle, caches, pipeline, execução fora de ordem, multicore e CPU/GPU.

Fluxo mental:

```text
Assembly
↓
ISA
↓
Decode
↓
Datapath / execução
↓
microarquitetura
↓
circuitos
```

---

## 07 — Memória e Representação de Dados

**Status:** ⬜ planejada  
**Pré-requisitos recomendados:** 03, 05 e 06

Tópicos centrais:

```text
bits / bytes
hexadecimal
signed / unsigned
complemento de dois
IEEE 754
endianness
alignment / padding
layout de objetos
stack / heap
cache lines
virtual memory
page tables
TLB
```

Objetivo: consolidar memória como eixo comum entre linguagens, hardware e sistema operacional.

---

# III — Sistema operacional e Linux

## 08 — Sistemas Operacionais

**Status:** ⬜ planejada  
**Pré-requisitos recomendados:** 05–07

Tópicos:

- kernel e user space;
- processos e threads;
- syscalls;
- scheduling;
- memória virtual;
- page faults;
- file descriptors;
- pipes;
- signals;
- IPC;
- filesystems;
- `mmap`;
- sincronização;
- proteção e privilégio.

---

## 09 — Linux Systems

**Status:** ⬜ planejada  
**Pré-requisito recomendado:** 08

Tópicos:

- `/proc` e `/sys`;
- usuários, grupos e permissões;
- capabilities;
- processos e sinais;
- filesystem e mounts;
- devices;
- systemd;
- serviços e logs;
- shell;
- namespaces;
- observabilidade.

---

## 10 — Containers e Docker Internals

**Status:** ⬜ planejada  
**Pré-requisitos recomendados:** 08 e 09

Tópicos:

```text
Linux process
↓
namespaces
+
cgroups
+
capabilities
+
seccomp
+
filesystem layers
↓
OCI runtime
↓
containerd / Docker
```

Inclui Docker operacional, mas o foco é compreender **containers como mecanismos do Linux**.

---

# IV — Comunicação e concorrência

## 11 — Redes de Computadores

**Status:** ⬜ planejada  
**Pré-requisitos recomendados:** 08–09

Trilha:

```text
socket
↓
TCP / UDP
↓
IP
↓
Ethernet
↓
interface de rede
```

Inclui DNS, HTTP, TLS, routing, NAT, firewalls e análise de pacotes.

---

## 12 — Concorrência e Programação Paralela

**Status:** ⬜ planejada  
**Pré-requisitos recomendados:** 06–08

Tópicos:

- processos e threads;
- race conditions;
- mutexes e semáforos;
- atomics;
- memory ordering;
- deadlocks;
- lock-free;
- false sharing;
- thread pools;
- paralelismo de dados.

---

# V — Linguagens, toolchains e performance

## 13 — Compiladores

**Status:** ⬜ planejada  
**Pré-requisitos recomendados:** 03, 05 e 06

```text
source
↓
lexer
↓
parser
↓
AST
↓
semantic analysis
↓
IR / SSA
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

---

## 14 — Performance Engineering

**Status:** ⬜ planejada  
**Pré-requisitos recomendados:** 06, 07, 12 e 13

Objetivo: medir antes de otimizar.

Tópicos:

- benchmarking;
- profiling;
- `perf`;
- flame graphs;
- caches;
- branch prediction;
- allocations;
- SIMD;
- vectorization;
- memory bandwidth;
- latência e throughput;
- compute-bound vs memory-bound.

---

# VI — Persistência e distribuição

## 15 — Bancos de Dados por Dentro

**Status:** ⬜ planejada  
**Pré-requisitos recomendados:** 07–09 e fundamentos de SQL

Tópicos:

- pages;
- B/B+ trees;
- indexes;
- buffer pools;
- WAL;
- transactions;
- ACID;
- MVCC;
- locking;
- query planner;
- PostgreSQL internals.

---

## 16 — Sistemas Distribuídos

**Status:** ⬜ planejada  
**Pré-requisitos recomendados:** 08, 11, 12 e 15

Tópicos:

- partial failure;
- clocks e ordering;
- replication;
- consensus;
- leader election;
- leases;
- retries;
- idempotency;
- queues;
- consistency;
- CAP;
- fault tolerance.

---

# VII — Segurança

## 17 — Segurança de Sistemas

**Status:** ⬜ planejada  
**Pré-requisitos recomendados:** 03, 05, 08–11

Tópicos:

- memory safety;
- buffer overflow;
- stack corruption;
- ASLR;
- NX;
- canaries;
- ROP;
- privilege boundaries;
- sandboxing;
- capabilities;
- isolamento;
- secure coding.

---

## 18 — Criptografia para Programadores

**Status:** ⬜ planejada  
**Pré-requisitos recomendados:** matemática discreta básica e 11

Tópicos:

- entropia e aleatoriedade;
- hashes;
- MACs;
- criptografia simétrica;
- AEAD;
- criptografia assimétrica;
- assinaturas;
- key exchange;
- certificados;
- PKI;
- TLS;
- gerenciamento de chaves.

---

# VIII — Computação científica e Machine Learning

## 19 — Álgebra Linear Computacional

**Status:** ⬜ planejada  
**Objetivo:** conectar álgebra linear à forma como computadores realmente executam operações matriciais.

Inclui:

- layout de matrizes;
- multiplicação matricial;
- BLAS;
- decomposições;
- matrizes esparsas;
- estabilidade numérica;
- SIMD;
- paralelismo.

---

## 20 — Cálculo Numérico e Computação Científica

**Status:** ⬜ planejada

Inclui:

- floating point;
- erro e condicionamento;
- estabilidade;
- raízes;
- interpolação;
- derivação e integração numérica;
- sistemas lineares;
- otimização;
- métodos iterativos.

---

## 21 — Redes Neurais do Zero

**Status:** ⬜ planejada  
**Pré-requisitos recomendados:** 01, 19 e 20

Implementação didática em camadas:

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
- MLP;
- ativações;
- losses;
- backpropagation;
- gradient descent;
- inicialização;
- normalização;
- otimização;
- convoluções;
- attention;
- transformers.

---

## 22 — GPU Computing / CUDA

**Status:** ⬜ planejada  
**Pré-requisitos recomendados:** 06, 12, 19 e C/C++

Tópicos:

- arquitetura CPU vs GPU;
- kernels;
- grids, blocks e threads;
- warps;
- hierarchy de memória;
- shared/global memory;
- coalescing;
- occupancy;
- synchronization;
- matrix multiplication;
- tensor cores.

---

# IX — Runtimes e programação de sistemas

## 23 — Runtimes e Máquinas Virtuais

**Status:** ⬜ planejada  
**Pré-requisitos recomendados:** 05, 07, 08 e 13

Tópicos:

- interpreters;
- bytecode;
- CPython;
- JVM;
- JIT;
- garbage collection;
- reference counting;
- object representation;
- dynamic dispatch.

---

## 24 — C++ para Systems Programming

**Status:** ⬜ planejada  
**Pré-requisitos recomendados:** 02, 05–08 e 12

Tópicos:

- RAII em profundidade;
- ownership;
- move semantics;
- templates/concepts;
- allocators;
- memory model;
- atomics;
- zero-cost abstractions;
- ABI;
- desenho de bibliotecas e runtimes.

---

# X — Sistemas de IA

## 25 — Arquitetura de Sistemas de IA

**Status:** ⬜ planejada  
**Pré-requisitos recomendados:** 10–16 e 19–23 conforme o tópico

Tópicos:

- inference runtimes;
- model serving;
- batching;
- quantization;
- KV cache;
- embeddings;
- retrieval;
- model routing;
- scheduling;
- tool execution;
- memory systems;
- distributed inference;
- observabilidade.

---

# XI — Fundamentos formais

## 26 — Teoria da Computação

**Status:** ⬜ planejada

Tópicos:

- autômatos;
- linguagens formais;
- gramáticas;
- máquinas de Turing;
- computabilidade;
- decidibilidade;
- reduções;
- complexidade;
- P vs NP;
- lambda calculus.

Esta aula não precisa necessariamente ser a última. Pode ser estudada em paralelo conforme a matemática amadurecer.

---

# Dependências resumidas

```text
01 Python ───────────────────────────────┐
                                        ├──► 21 Redes Neurais
19 Álgebra Linear ─► 20 Numérico ──────┘
                              │
                              └──► 22 GPU ─► 25 Sistemas de IA


03 C ─► 04 Algoritmos
  │
  └──► 05 Assembly ─► 06 Arquitetura ─► 07 Memória ─► 08 SO ─► 09 Linux
                                                        │          │
                                                        │          └──► 10 Containers
                                                        │
                                                        ├──► 11 Redes
                                                        └──► 12 Concorrência

05 + 06 ─► 13 Compiladores
06 + 07 + 12 + 13 ─► 14 Performance

08 + 11 + 12 + 15 ─► 16 Distribuídos
03 + 05 + 08 + 11 ─► 17 Segurança
```

---

# Próxima aula lógica

Depois de **06 — Arquitetura de Computadores**, a próxima masterclass principal é:

> **07 — Memória e Representação de Dados**

Ela deve consolidar, em um único lugar, conceitos que já apareceram em C, Assembly e Arquitetura antes de entrarmos em Sistemas Operacionais.
