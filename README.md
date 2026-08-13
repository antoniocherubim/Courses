# Courses

Base multidisciplinar de conhecimento: classes, exercícios, projetos, mapas conceituais e trilhas de estudo conectando computação, matemática, IA, neurociência e ciências naturais.

> **Conhecimento organizado, conectado e compartilhado.**

---

## Como navegar

Este repositório possui três níveis complementares:

```text
TRACKS
áreas de estudo
│
├── MAPS
│   conceitos que atravessam várias áreas
│
└── ROADMAP
    visão de longo prazo, prioridades e dependências
```

### 1. Tracks — onde estudar

| Track | Área |
|---|---|
| [A](classes/track-a-programming-systems/) | Programming & Systems |
| [B](classes/track-b-mathematics/) | Mathematics & Theoretical Foundations |
| [C](classes/track-c-scientific-computing-ml/) | Scientific Computing & Machine Learning |
| [D](classes/track-d-neuroscience-neurocomputation/) | Neuroscience & Neurocomputation |
| [E](classes/track-e-infrastructure-distributed/) | Infrastructure & Distributed Systems |
| [F](classes/track-f-ai-cognitive-systems/) | AI & Cognitive Systems |
| [G](classes/track-g-physics/) | Physics |
| [H](classes/track-h-chemistry/) | Chemistry |
| [I](classes/track-i-biology-biotechnology/) | Biology & Biotechnology |

**[Ver todas as classes e dependências →](classes/README.md)**

### 2. Maps — como relacionar

Os mapas não são cursos. Eles conectam ideias recorrentes entre disciplinas.

**[Abrir mapas conceituais →](maps/README.md)**

**[Mapa de escalas e invariantes →](maps/scales-structures-invariants.md)**

Exemplos:

```text
memória
├── RAM / cache
├── memória virtual
├── memória neural
├── memória em sistemas de IA
└── dependência histórica de um sistema

informação
├── bits
├── entropia
├── comunicação
├── genética
├── código neural
└── representação

dinâmica
├── sistemas dinâmicos
├── circuitos
├── neurodinâmica
├── cinética química
├── ecologia
└── otimização
```

### 3. Roadmap — para onde avançar

O roadmap registra:

- o que já está estruturado;
- o que está em estudo;
- conhecimento parcial ainda não externalizado;
- próximos fundamentos;
- expansões de longo prazo;
- dependências e convergências entre áreas.

**[Abrir roadmap pessoal de conhecimento →](roadmap/README.md)**

**[Fronteira atual →](roadmap/NOW.md)**

O roadmap também contém:

- [`BASELINE`](roadmap/BASELINE.md) — conhecimento prévio;
- [`NOW`](roadmap/NOW.md) — fronteira atual.

---

## Estado atual

A base prática está concentrada no Track A:

| ID | Class | Estado |
|---|---|:---:|
| A01 | Python | 📘 |
| A02 | C++ e POO | 📘 |
| A03 | C | 🟡 |
| A04 | Algoritmos e Estruturas de Dados em C | 🟡 |
| A05 | Assembly x86-64 | 📘 |
| A06 | Arquitetura de Computadores | 📘 |

Legenda:

```text
📘 estruturado      → existe material principal utilizável no repositório
🟡 em estruturação → existe material, mas ainda está sendo ampliado/revisado
🧭 a externalizar  → há familiaridade/estudo prévio, mas o conhecimento ainda não foi organizado como class
⬜ planejado        → conteúdo futuro ainda não estruturado
```

> Os status descrevem o estado do conhecimento **no repositório**, não uma certificação de domínio pessoal.

---

## Estrutura

```text
Courses/
├── README.md
├── ARCHITECTURE.md
│
├── classes/
│   ├── README.md
│   ├── TEMPLATE.md
│   ├── track-a-programming-systems/
│   ├── track-b-mathematics/
│   ├── track-c-scientific-computing-ml/
│   ├── track-d-neuroscience-neurocomputation/
│   ├── track-e-infrastructure-distributed/
│   ├── track-f-ai-cognitive-systems/
│   ├── track-g-physics/
│   ├── track-h-chemistry/
│   └── track-i-biology-biotechnology/
│
├── maps/
│   ├── README.md
│   ├── knowledge-graph.md
│   └── scales-structures-invariants.md
│
└── roadmap/
    ├── README.md
    ├── BASELINE.md
    └── NOW.md
```

Uma class física só deve existir quando houver conteúdo real:

```text
A05-assembly/
├── README.md
├── examples/      # quando necessário
├── exercises/     # quando necessário
├── projects/      # quando necessário
├── notes/         # quando necessário
└── assets/        # quando necessário
```

Não criar pastas vazias para cursos futuros.

---

## Princípio

O objetivo não é manter tudo na memória.

É construir uma estrutura externa que permita responder:

```text
O que eu sei?
↓
Onde esse conhecimento está?
↓
Do que ele depende?
↓
Com o que ele se conecta?
↓
Qual é a próxima lacuna importante?
↓
Como o mesmo padrão reaparece em outra escala?
```

A unidade fundamental deste repositório não é a aula isolada.

É a **relação entre conhecimentos**.
