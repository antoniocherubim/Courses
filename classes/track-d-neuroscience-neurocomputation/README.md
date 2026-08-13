# Track D — Neuroscience & Neurocomputation

[← Classes](../README.md) · [Maps](../../maps/) · [Roadmap](../../roadmap/) · [NOW](../../roadmap/NOW.md)

> Da biofísica do neurônio à dinâmica coletiva, representação e computação em populações neurais.

Este track deve manter um recorte **computacional e quantitativo**. O foco não é cobrir toda a neuroanatomia, mas estudar os mecanismos necessários para compreender processamento, memória, dinâmica e representação.

## Currículo

| ID | Masterclass | Status | Pré-requisitos recomendados |
|---|---|:---:|---|
| D01 | Fundamentos de Neurociência Computacional | 🧭 | B02–B05 |
| D02 | Modelos Biofísicos de Neurônios | ⬜ | D01, B05 |
| D03 | Código Neural e Dinâmica Populacional | 🧭 | D01, B02/B04 |
| D04 | Sinapses, Plasticidade e Aprendizado | ⬜ | D01–D03 |
| D05 | Redes Recorrentes e Redes de Atratores | 🧭 | D03, B09 |
| D06 | Sistemas Dinâmicos Neurais | 🧭 | B05/B09, D02/D03 |
| D07 | Neural Manifolds e Geometria das Representações | 🧭 | B02/B08, D03/D06 |
| D08 | Neurociência Topológica e TDA | ⬜ | B06/B07, D03/D07 |
| D09 | Spiking Neural Networks e Computação Neuromórfica | ⬜ | D02–D04 |
| D10 | Memória, Engramas e Representações Distribuídas | 🧭 | D03–D06 |

## Caminho principal

```text
neurônio
↓
dinâmica da membrana
↓
sinapses
↓
população
↓
espaço de estados
↓
atratores / trajetórias
↓
representação
↓
manifolds / topologia
```

## Ponte matemática

```text
B05 EDOs ──────────────► D02/D06
B09 Sistemas Dinâmicos ► D05/D06
B08 Geometria ─────────► D07
B06/B07 Topologia ─────► D08
B10 Informação ────────► D03/D10
```

## Filosofia

Quando termos como **manifold**, **atrator**, **dimensionalidade** ou **topologia** aparecerem na literatura de neurociência, a meta é sempre distinguir:

```text
definição matemática rigorosa
vs.
uso aproximado / operacional na neurociência
```

Isso evita transformar metáforas geométricas em afirmações matemáticas fortes sem justificativa.
