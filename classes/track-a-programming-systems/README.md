# Track A — Programming & Systems

[← Classes](../README.md) · [Maps](../../maps/) · [Roadmap](../../roadmap/) · [NOW](../../roadmap/NOW.md)

> Do código de alto nível à máquina, ao sistema operacional e aos runtimes.

## Currículo

| ID | Class | Status | Pré-requisitos |
|---|---|:---:|---|
| A01 | [Python](A01-python/) | 📘 | — |
| A02 | [C++ e POO](A02-cpp-poo/) | 📘 | lógica de programação |
| A03 | [Linguagem C](A03-c/) | 🟡 | lógica de programação |
| A04 | [Algoritmos e Estruturas de Dados em C](A04-algoritmos-estruturas-dados/) | 🟡 | A03 |
| A05 | [Assembly x86-64](A05-assembly/) | 📘 | A03 recomendado |
| A06 | [Arquitetura de Computadores](A06-arquitetura-computadores/) | 📘 | A05 recomendado |
| A07 | Memória e Representação de Dados | ⬜ | A03, A05, A06 |
| A08 | Sistemas Operacionais | ⬜ | A05–A07 |
| A09 | Linux Systems | ⬜ | A08 |
| A10 | Concorrência e Programação Paralela | ⬜ | A06–A08 |
| A11 | Compiladores | ⬜ | A03, A05, A06 |
| A12 | Performance Engineering | ⬜ | A06, A07, A10, A11 |
| A13 | Runtimes e Máquinas Virtuais | ⬜ | A05, A07, A08, A11 |
| A14 | C++ para Systems Programming | ⬜ | A02, A05–A10 |

## Eixo principal

```text
A03 C
 ↓
A05 Assembly
 ↓
A06 Arquitetura
 ↓
A07 Memória
 ↓
A08 Sistemas Operacionais
 ↓
A09 Linux
```

A01 e A02 continuam importantes, mas não precisam bloquear o percurso vertical de baixo nível.

## Resultado esperado

Ao avançar neste track, deve ser possível seguir uma operação:

```text
código
↓
compilador/runtime
↓
Assembly
↓
ISA
↓
CPU
↓
memória
↓
kernel
```

e entender onde cada abstração começa e termina.
