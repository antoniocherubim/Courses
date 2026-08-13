# Courses

Repositório pessoal de **masterclasses, notas e exercícios**, organizado como uma trilha progressiva para compreender computação de ponta a ponta — da programação de alto nível ao hardware e, depois, a sistemas distribuídos e inteligência artificial.

A ideia central é estudar cada abstração junto da camada que existe abaixo dela:

```text
Matemática
    ↓
Algoritmos
    ↓
Python / C++
    ↓
C
    ↓
Assembly
    ↓
ISA
    ↓
Arquitetura de Computadores
    ↓
Sistema Operacional
    ↓
Linux / Containers / Redes
    ↓
Sistemas Distribuídos
    ↓
Machine Learning / GPU
    ↓
Sistemas de IA
```

> **Pergunta-guia:** qual abstração está sendo construída nesta camada, quanto ela custa e o que realmente acontece abaixo dela?

---

## Navegação rápida

| # | Masterclass | Status | Camada |
|---:|---|:---:|---|
| 01 | [Python](classes/01-python/) | ✅ | Linguagem de alto nível |
| 02 | [C++ e Programação Orientada a Objetos](classes/02-cpp-poo/) | ✅ | Linguagem / abstrações |
| 03 | [Linguagem C](classes/03-c/) | 🟡 | Baixo nível / memória |
| 04 | [Algoritmos e Estruturas de Dados em C](classes/04-algoritmos-estruturas-dados/) | 🟡 | Algoritmos / estruturas |
| 05 | [Assembly x86-64](classes/05-assembly/) | ✅ | ISA / baixo nível |
| 06 | [Arquitetura de Computadores](classes/06-arquitetura-computadores/) | ✅ | Hardware / microarquitetura |
| 07 | Memória e Representação de Dados | ⬜ | Memória |
| 08 | Sistemas Operacionais | ⬜ | Kernel / processos |
| 09 | Linux Systems | ⬜ | Sistemas |
| 10 | Containers e Docker Internals | ⬜ | Isolamento / runtime |
| 11 | Redes de Computadores | ⬜ | Comunicação |
| 12 | Concorrência e Paralelismo | ⬜ | Execução |
| 13 | Compiladores | ⬜ | Linguagens / toolchain |
| 14 | Performance Engineering | ⬜ | Otimização |
| 15 | Bancos de Dados por Dentro | ⬜ | Persistência |
| 16 | Sistemas Distribuídos | ⬜ | Distribuição |
| 17 | Segurança de Sistemas | ⬜ | Segurança |
| 18 | Criptografia para Programadores | ⬜ | Segurança |
| 19 | Álgebra Linear Computacional | ⬜ | Computação científica |
| 20 | Cálculo Numérico | ⬜ | Computação científica |
| 21 | Redes Neurais do Zero | ⬜ | Machine Learning |
| 22 | GPU Computing / CUDA | ⬜ | Computação paralela |
| 23 | Runtimes e Máquinas Virtuais | ⬜ | Linguagens / runtime |
| 24 | C++ para Systems Programming | ⬜ | Sistemas / performance |
| 25 | Arquitetura de Sistemas de IA | ⬜ | IA / infraestrutura |
| 26 | Teoria da Computação | ⬜ | Fundamentos teóricos |

**Legenda:** ✅ disponível · 🟡 em estudo/expansão · ⬜ planejada

Para objetivos, pré-requisitos e a sequência detalhada, veja **[classes/README.md](classes/README.md)**.

---

## Trilhas

### Como a máquina funciona

```text
C
↓
Assembly
↓
Machine Code / ISA
↓
Arquitetura de Computadores
↓
Memória
↓
Sistema Operacional
```

### Sistemas e infraestrutura

```text
Sistemas Operacionais
↓
Linux
↓
Containers
↓
Redes
↓
Concorrência
↓
Bancos de Dados
↓
Sistemas Distribuídos
↓
Segurança
```

### Machine Learning e IA

```text
Python
↓
Álgebra Linear Computacional
↓
Cálculo Numérico
↓
Redes Neurais do Zero
↓
GPU / CUDA
↓
Arquitetura de Sistemas de IA
```

As trilhas convergem. Um objetivo importante do repositório é conseguir seguir uma operação por várias camadas:

```text
modelo matemático
↓
algoritmo
↓
Python / C++
↓
runtime / bibliotecas nativas
↓
Assembly / ISA
↓
CPU ou GPU
↓
memória / I/O
```

---

## Estrutura

```text
Courses/
├── README.md
└── classes/
    ├── README.md
    ├── 01-python/
    │   ├── README.md
    │   └── exercises/
    ├── 02-cpp-poo/
    │   ├── README.md
    │   └── exercises/
    ├── 03-c/
    │   └── README.md
    ├── 04-algoritmos-estruturas-dados/
    │   └── README.md
    ├── 05-assembly/
    │   └── README.md
    └── 06-arquitetura-computadores/
        └── README.md
```

Quando necessário, cada curso pode crescer para:

```text
<curso>/
├── README.md       # masterclass principal
├── exercises/      # exercícios
├── examples/       # exemplos executáveis
├── projects/       # mini-projetos
├── notes/          # notas complementares
└── assets/         # diagramas e imagens
```

Não é necessário criar diretórios vazios antecipadamente.

---

## Convenções

- `README.md` é sempre a entrada principal de uma masterclass.
- Pastas usam prefixo numérico para preservar a ordem da trilha.
- Exemplos executáveis devem ficar fora do texto principal quando crescerem demais.
- Uma aula pode ser estudada fora da ordem, mas seus pré-requisitos devem permanecer claros.
- Conteúdo factual dependente de versão deve indicar a versão relevante quando necessário.
- O foco é **entender conceitos**, não decorar APIs ou comandos.

---

## Método de estudo

Para cada masterclass:

1. entender o modelo mental;
2. reproduzir exemplos;
3. modificar os exemplos e observar o efeito;
4. descer uma camada de abstração;
5. usar ferramentas reais de inspeção;
6. implementar pelo menos um pequeno projeto;
7. registrar dúvidas e descobertas;
8. voltar ao conteúdo após experiência prática.

Exemplos de perguntas úteis:

```text
Onde esse dado está?

Quem possui essa memória?

Que representação binária está sendo usada?

Que instruções isso pode gerar?

Isso toca o kernel?

Isso copia dados?

Qual cache é relevante?

Isso é compute-bound ou memory-bound?

Essa abstração é necessária nesta camada?
```

---

## Objetivo

A meta não é memorizar todas as tecnologias.

É construir capacidade para olhar um sistema e identificar:

```text
em qual camada o problema existe
↓
qual abstração está sendo usada
↓
o que ela esconde
↓
qual custo ela introduz
↓
como inspecionar o comportamento real
```

Programação deixa então de ser uma coleção de linguagens e frameworks e passa a ser a compreensão de um único sistema em diferentes níveis de abstração.
