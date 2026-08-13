# Courses

Repositório pessoal de **masterclasses, notas, exercícios e projetos de estudo**, organizado como um mapa de conhecimento em tracks independentes, mas conectados.

O objetivo não é acumular tecnologias isoladas. É construir um modelo mental no qual seja possível subir e descer pelas camadas:

```text
matemática
    ↓
algoritmos e modelos
    ↓
linguagens
    ↓
runtime / compilador
    ↓
sistema operacional
    ↓
hardware
```

e também atravessar domínios:

```text
matemática ─────────────┐
                       ▼
neurociência ───► representação ───► inteligência
                       ▲
                       │
computação ────────────┘
```

---

# Tracks

| Track | Área | Estado |
|---|---|:---:|
| [A](classes/track-a-programming-systems/) | Programming & Systems | 🟡 ativo |
| [B](classes/track-b-mathematics/) | Mathematics & Theoretical Foundations | 🧭 roadmap |
| [C](classes/track-c-scientific-computing-ml/) | Scientific Computing & Machine Learning | 🧭 roadmap |
| [D](classes/track-d-neuroscience-neurocomputation/) | Neuroscience & Neurocomputation | 🧭 roadmap |
| [E](classes/track-e-infrastructure-distributed/) | Infrastructure & Distributed Systems | 🧭 roadmap |
| [F](classes/track-f-ai-cognitive-systems/) | AI & Cognitive Systems | 🧭 roadmap |

**[Abrir mapa completo das masterclasses →](classes/README.md)**

---

# Por que tracks?

Uma sequência linear funciona bem no início:

```text
Python → C → Assembly → Arquitetura
```

mas deixa de representar bem o aprendizado quando entram tópicos como:

```text
Topologia
Neurocomputação
Sistemas Distribuídos
GPU
Teoria da Informação
Sistemas Cognitivos
```

Esses assuntos possuem **dependências cruzadas**, não uma única ordem.

Por isso cada aula recebe agora um identificador estável:

```text
A05  Assembly
B06  Topologia
D07  Neural Manifolds
E05  Sistemas Distribuídos
F05  Arquiteturas Cognitivas
```

Adicionar uma aula ao Track B não altera a numeração do Track A.

---

# Mapa de alto nível

```text
                    ┌─────────────────────────┐
                    │ B — Mathematics         │
                    └────────────┬────────────┘
                                 │
                  ┌──────────────┼──────────────┐
                  ▼              ▼              ▼
       ┌────────────────┐ ┌──────────────┐ ┌────────────────┐
       │ A — Programming│ │ C — Sci/ML   │ │ D — Neuro     │
       │     & Systems  │ │              │ │ computation    │
       └────────┬───────┘ └──────┬───────┘ └────────┬───────┘
                │                │                  │
                └────────┬───────┴──────────┬───────┘
                         ▼                  ▼
              ┌──────────────────┐   ┌──────────────────┐
              │ E — Infra &      │   │ F — AI &        │
              │ Distributed      │──►│ Cognitive       │
              └──────────────────┘   └──────────────────┘
```

O grafo é uma orientação, não uma barreira. Cursos podem ser estudados em paralelo quando os pré-requisitos necessários já estiverem dominados.

---

# Estrutura

```text
Courses/
├── README.md
└── classes/
    ├── README.md
    │
    ├── track-a-programming-systems/
    │   ├── README.md
    │   ├── A01-python/
    │   ├── A02-cpp-poo/
    │   ├── A03-c/
    │   ├── A04-algoritmos-estruturas-dados/
    │   ├── A05-assembly/
    │   └── A06-arquitetura-computadores/
    │
    ├── track-b-mathematics/
    │   └── README.md
    │
    ├── track-c-scientific-computing-ml/
    │   └── README.md
    │
    ├── track-d-neuroscience-neurocomputation/
    │   └── README.md
    │
    ├── track-e-infrastructure-distributed/
    │   └── README.md
    │
    └── track-f-ai-cognitive-systems/
        └── README.md
```

Cursos planejados aparecem nos READMEs dos tracks, mas **a pasta física só é criada quando a masterclass existir**.

---

# Estrutura de uma masterclass

Comece simples:

```text
A05-assembly/
└── README.md
```

Expanda quando houver conteúdo:

```text
A05-assembly/
├── README.md
├── exercises/
├── examples/
├── projects/
├── notes/
└── assets/
```

Não criar diretórios vazios por antecipação.

---

# Convenção de IDs

```text
Axx  Programming & Systems
Bxx  Mathematics & Theoretical Foundations
Cxx  Scientific Computing & Machine Learning
Dxx  Neuroscience & Neurocomputation
Exx  Infrastructure & Distributed Systems
Fxx  AI & Cognitive Systems
```

Exemplos:

```text
A06-arquitetura-computadores
B06-topologia
C05-redes-neurais-do-zero
D07-neural-manifolds
E02-containers-docker
F05-arquiteturas-cognitivas
```

O ID é parte estável do curso.

---

# Método de estudo

Para cada masterclass:

1. entender o modelo mental;
2. reproduzir os exemplos;
3. alterar os exemplos e observar o comportamento;
4. conectar o conteúdo aos seus pré-requisitos;
5. descer pelo menos uma camada de abstração;
6. usar ferramentas reais de inspeção quando aplicável;
7. implementar ao menos um exercício ou mini-projeto;
8. registrar dúvidas e descobertas;
9. voltar à aula depois da prática.

Perguntas recorrentes:

```text
Que objeto matemático está sendo usado?

Onde esse dado existe?

Como ele é representado?

Que transformação está sendo aplicada?

Que invariantes são preservados?

Qual é o custo computacional?

Que abstração está escondendo a implementação?

O que existe imediatamente abaixo desta camada?
```

---

# Princípio do repositório

A meta não é saber o nome de todas as ferramentas.

É conseguir olhar para um problema e identificar:

```text
qual estrutura está envolvida
↓
em qual camada ela existe
↓
qual abstração a representa
↓
qual implementação a realiza
↓
qual custo e quais limitações ela possui
```

O repositório é um **mapa vivo de formação**, não uma checklist que precisa ser concluída estritamente da esquerda para a direita.
