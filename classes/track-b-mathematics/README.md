# Track B — Mathematics & Theoretical Foundations

[← Classes](../README.md) · [Maps](../../maps/) · [Roadmap](../../roadmap/) · [NOW](../../roadmap/NOW.md)

> Estruturas matemáticas usadas para modelar computação, dinâmica, informação e representação.

## Currículo

| ID | Masterclass | Status | Observação |
|---|---|:---:|---|
| B01 | Matemática Discreta e Lógica | ⬜ | base formal de computação |
| B02 | Álgebra Linear | ⬜ | base para ML, geometria e sistemas |
| B03 | Cálculo Multivariável | ⬜ | derivadas, integrais, campos |
| B04 | Probabilidade e Estatística | ⬜ | incerteza e inferência |
| B05 | Equações Diferenciais | ⬜ | evolução contínua no tempo |
| B06 | Topologia | 🧭 | continuidade, espaços, invariantes |
| B07 | Topologia Algébrica e TDA | ⬜ | homologia, complexos, persistência |
| B08 | Geometria Diferencial | ⬜ | variedades, métricas, curvatura |
| B09 | Sistemas Dinâmicos | 🧭 | estados, estabilidade, atratores, caos |
| B10 | Teoria da Informação | ⬜ | entropia, informação, divergências |
| B11 | Otimização | ⬜ | convexidade, gradientes, restrições |
| B12 | Teoria da Computação | ⬜ | autômatos, computabilidade, complexidade |
| B13 | Análise Real | ⬜ | rigor para cálculo, EDOs e geometria |
| B14 | Álgebra Abstrata | ⬜ | grupos, anéis, corpos e estruturas algébricas |
| B15 | Teoria da Medida e Análise Funcional | ⬜ | medida, integração e espaços de funções |
| B16 | Sistemas Complexos e Ciência de Redes | ⬜ | emergência, redes e dinâmica coletiva |

## Dependências para aprofundamento

```text
B13 Análise Real ─────────────► B03/B05/B08 em maior rigor
B14 Álgebra Abstrata ─────────► B07 Topologia Algébrica
B15 Medida / Funcional ───────► probabilidade avançada, física, EDPs
                                e análise de espaços de funções

B09 Sistemas Dinâmicos ───────┐
B10 Teoria da Informação ─────┼──► B16 Sistemas Complexos / Redes
B04 Probabilidade ────────────┘
```

## Trilha geométrica/dinâmica

```text
B03 Cálculo
   │
   ├──► B05 Equações Diferenciais ──► B09 Sistemas Dinâmicos
   │
   └──► B08 Geometria Diferencial
                  ▲
                  │
B06 Topologia ────┴──► B07 Topologia Algébrica / TDA
```

## Por que separar B06 e B07?

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
