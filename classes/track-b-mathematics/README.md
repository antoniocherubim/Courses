# Track B — Mathematics & Theoretical Foundations

[← Classes](../README.md) · [Maps](../../maps/) · [Roadmap](../../roadmap/) · [NOW](../../roadmap/NOW.md)

> Estruturas matemáticas usadas para modelar computação, dinâmica, informação e representação.

## Currículo

| ID | Masterclass | Estado inicial | Papel |
|---|---|:---:|---|
| B01 | Matemática Discreta e Lógica | 🧭 | prova, estruturas discretas, computação |
| B02 | Álgebra Linear e Geometria Analítica | 🧭 | espaços, transformações, geometria, ML |
| B03 | Cálculo Diferencial e Multivariável | 🧭 | mudança contínua |
| B04 | Probabilidade e Estatística | 🧭 | incerteza e inferência |
| B05 | Análise Real | ⬜ | fundamentos rigorosos do cálculo |
| B06 | Equações Diferenciais | ⬜ | evolução contínua no tempo |
| B07 | Álgebra Abstrata | ⬜ | grupos, anéis, corpos, simetrias |
| B08 | Topologia | 🧭 | continuidade, espaços, invariantes |
| B09 | Topologia Algébrica e TDA | ⬜ | invariantes globais e dados |
| B10 | Geometria Diferencial | 🧭 | variedades, métricas, curvatura |
| B11 | Sistemas Dinâmicos | 🧭 | trajetórias, estabilidade, atratores |
| B12 | Teoria da Medida e Análise Funcional | ⬜ | integração, espaços funcionais |
| B13 | Teoria da Informação | 🧭 | entropia, codificação, inferência |
| B14 | Otimização | 🧭 | busca, restrições, aprendizado |
| B15 | Sistemas Complexos e Ciência de Redes | 🧭 | emergência, redes, organização coletiva |
| B16 | Teoria da Computação | ⬜ | computabilidade e complexidade |
| B17 | Método Científico e Epistemologia | 🧭 | evidência, hipótese, inferência |

## Dependências para aprofundamento

```text
B02 Álgebra Linear ───────────────┐
                                  ├──► B10 Geometria Diferencial
B03 Cálculo ─► B05 Análise ──────┤
        │                         │
        └──► B06 EDOs ─► B11 Dinâmica
                                  │
B08 Topologia ─► B09 TDA ────────┘

B07 Álgebra Abstrata ────────────► B09 Topologia Algébrica

B04 Probabilidade ───────────────► B13 Informação
B05 Análise ─► B12 Medida/Funcional
B11 Dinâmica + B04 ──────────────► B15 Sistemas Complexos
```

Este grafo é um mapa aproximado de dependências conceituais, não uma árvore rígida de pré-requisitos.

## Trilha geométrica/dinâmica

```text
B03 Cálculo
   │
   ├──► B05 Análise Real ──► B06 Equações Diferenciais ──► B11 Sistemas Dinâmicos
   │
   └──► B10 Geometria Diferencial
                  ▲
                  │
B08 Topologia ────┴──► B09 Topologia Algébrica / TDA
```

## Por que separar B08 e B09?

**Topologia** deve primeiro estabelecer:

```text
espaços topológicos
abertos / fechados
continuidade
homeomorfismos
compacidade
conexidade
produto / quociente
```

Depois **Topologia Algébrica e TDA** pode introduzir:

```text
complexos simpliciais
grupo fundamental
homologia
Betti numbers
persistent homology
barcodes / persistence diagrams
```

Isso cria uma base limpa para aplicações posteriores em dados e neurociência.
