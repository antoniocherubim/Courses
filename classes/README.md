# Classes — Knowledge Map

[← Courses](../README.md) · [Mapas](../maps/) · [Roadmap](../roadmap/)

Cada track representa uma área relativamente estável. As dependências entre eles são explícitas, mas não existe uma única sequência obrigatória.

> Os IDs são identificadores estáveis dentro de cada track. Eles ajudam a navegação e as dependências, mas não representam uma ordem temporal obrigatória de estudo.

---

## Tracks

### [A — Programming & Systems](track-a-programming-systems/)

```text
linguagens → C → Assembly → arquitetura → memória → SO → runtimes / performance
```

### [B — Mathematics & Theoretical Foundations](track-b-mathematics/)

```text
lógica → álgebra / cálculo / probabilidade → EDOs → topologia / geometria → dinâmica / informação
```

### [C — Scientific Computing & Machine Learning](track-c-scientific-computing-ml/)

```text
métodos numéricos → álgebra linear computacional → ML → redes neurais → GPU
```

### [D — Neuroscience & Neurocomputation](track-d-neuroscience-neurocomputation/)

```text
neurônio → biofísica → populações → plasticidade → dinâmica → manifolds / topologia → memória
```

### [E — Infrastructure & Distributed Systems](track-e-infrastructure-distributed/)

```text
redes → containers → infraestrutura → bancos → distribuídos → reliability / security
```

### [F — AI & Cognitive Systems](track-f-ai-cognitive-systems/)

```text
inference → retrieval / memória → agents → arquiteturas cognitivas → multimodalidade → distributed AI
```

### [G — Physics](track-g-physics/)

```text
mecânica → ondas → termodinâmica → eletromagnetismo → estatística → relatividade / quântica
```

### [H — Chemistry](track-h-chemistry/)

```text
estrutura atômica → ligações → termodinâmica / equilíbrio → cinética → orgânica / físico-química → bioquímica
```

### [I — Biology & Biotechnology](track-i-biology-biotechnology/)

```text
célula → molecular / genética → bioquímica → fisiologia → evolução / ecologia → biotecnologia
```

---

## Conexões principais

```text
B — Mathematics ─────────────► todos os tracks quantitativos

B02/B03/B04 ─────────────────► C — Scientific Computing
B06/B10/B11/B13 ─────────────► D — Neurocomputation

A — Programming ─────────────► C, E, F
G — Physics ─► H09 Bioquímica ─► I04/I06
I01/I02/I05/I06 ─────────────► D
I15 Bioinformática ──────────► C, F
D — Neurocomputation ────────► F
E — Infrastructure ──────────► F
```

Isso é apenas o esqueleto disciplinar. Conceitos que atravessam várias áreas ficam em **[maps/](../maps/)**.

---

## Estado da base prática

| ID | Curso | Status |
|---|---|:---:|
| A01 | Python | 📘 |
| A02 | C++ e POO | 📘 |
| A03 | C | 🟡 |
| A04 | Algoritmos e Estruturas de Dados | 🟡 |
| A05 | Assembly x86-64 | 📘 |
| A06 | Arquitetura de Computadores | 📘 |
| demais | roadmap | 🧭 / ⬜ |

Os IDs são estáveis dentro de cada track. Adicionar uma nova aula de física não renumera computação, neurociência ou matemática.
