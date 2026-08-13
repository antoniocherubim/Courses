# Masterclasses — Knowledge Map

[← README principal](../README.md)

Este diretório é o índice central do repositório. As aulas são organizadas em **tracks** para evitar que a adição de novos assuntos destrua uma sequência linear já estabelecida.

---

## Tracks

### [Track A — Programming & Systems](track-a-programming-systems/)

```text
linguagens
↓
baixo nível
↓
Assembly / ISA
↓
CPU
↓
memória
↓
SO
↓
runtimes / compiladores
↓
performance
```

### [Track B — Mathematics & Theoretical Foundations](track-b-mathematics/)

```text
lógica / discreta
↓
álgebra / cálculo / probabilidade
↓
EDOs
↓
topologia / geometria
↓
sistemas dinâmicos
↓
informação / otimização
↓
teoria da computação
```

### [Track C — Scientific Computing & Machine Learning](track-c-scientific-computing-ml/)

```text
computação numérica
↓
álgebra linear computacional
↓
computação científica
↓
ML
↓
redes neurais
↓
GPU
```

### [Track D — Neuroscience & Neurocomputation](track-d-neuroscience-neurocomputation/)

```text
neurônio biológico
↓
modelos matemáticos
↓
código neural
↓
dinâmica populacional
↓
plasticidade
↓
atratores
↓
manifolds / topologia
↓
computação neural
```

### [Track E — Infrastructure & Distributed Systems](track-e-infrastructure-distributed/)

```text
rede
↓
containers
↓
infraestrutura
↓
bancos de dados
↓
sistemas distribuídos
↓
orquestração
↓
segurança / observabilidade
```

### [Track F — AI & Cognitive Systems](track-f-ai-cognitive-systems/)

```text
model serving
↓
retrieval / memória
↓
agentes
↓
arquiteturas cognitivas
↓
multimodalidade
↓
avaliação / safety
↓
sistemas distribuídos de IA
```

---

# Dependências cruzadas principais

```text
A03 C ──► A05 Assembly ──► A06 Arquitetura
                              │
                              ├──► A07 Memória
                              └──► C07 GPU

B02 Álgebra Linear ──────────► C02 Álgebra Linear Computacional
B03 Cálculo ─────────────────► C01 Computação Numérica
B04 Probabilidade ───────────► C04/C05 ML

B05 EDOs ──────────────┐
B06 Topologia ─────────┼──► D06/D07/D08 Neurodinâmica e manifolds
B07 Topologia Algébrica┤
B08 Geom. Diferencial ─┤
B09 Sist. Dinâmicos ───┘

A08 SO + A09 Linux ──────────► E02 Containers
A08 SO + E01 Redes ──────────► E03 Infraestrutura
E01 + E04 + A10 ─────────────► E05 Distribuídos

C04/C05/C07 ─────────────────► F01/F02 Sistemas de IA
E05 ─────────────────────────► F08 IA distribuída
D03/D06/D07 ─────────────────► F05 Arquiteturas cognitivas
```

---

# Estado atual da base prática

| ID | Curso | Status |
|---|---|:---:|
| A01 | Python | ✅ existente |
| A02 | C++ e POO | ✅ existente |
| A03 | C | 🟡 existente / em estudo |
| A04 | Algoritmos e Estruturas de Dados em C | 🟡 existente / em estudo |
| A05 | Assembly x86-64 | ✅ existente |
| A06 | Arquitetura de Computadores | ✅ existente |
| demais | roadmap | ⬜ planejado |

Os IDs acima substituem a numeração global antiga `01–26`.
