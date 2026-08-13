# Track D — Neuroscience & Neurocomputation

[← Classes](../README.md) · [Maps](../../maps/) · [Roadmap](../../roadmap/) · [NOW](../../roadmap/NOW.md)

> Da biofísica do neurônio à dinâmica coletiva, representação e computação em populações neurais.

Este track deve manter um recorte **computacional e quantitativo**. O foco não é cobrir toda a neuroanatomia, mas estudar os mecanismos necessários para compreender processamento, memória, dinâmica e representação.

## Currículo

| ID | Masterclass | Status | Pré-requisitos recomendados |
|---|---|:---:|---|
| D01 | Fundamentos de Neurociência Computacional | 🧭 | I01/I05/I06, B02–B06 |
| D02 | Modelos Biofísicos de Neurônios | ⬜ | D01, I01/I06, B06 |
| D03 | Código Neural e Dinâmica Populacional | 🧭 | D01, B02/B04/B13 |
| D04 | Sinapses, Plasticidade e Aprendizado | ⬜ | D01–D03, I02 |
| D05 | Redes Recorrentes e Redes de Atratores | 🧭 | D03, B11 |
| D06 | Sistemas Dinâmicos Neurais | 🧭 | B06/B11, D02/D03 |
| D07 | Neural Manifolds e Geometria das Representações | 🧭 | B02/B10, D03/D06 |
| D08 | Neurociência Topológica e TDA | ⬜ | B08/B09, D03/D07 |
| D09 | Spiking Neural Networks e Computação Neuromórfica | ⬜ | D02–D04 |
| D10 | Memória, Engramas e Representações Distribuídas | 🧭 | D03–D06, I02, B13 |

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
I01 Biologia Celular ──────────────► D01/D02
I02 Biologia Molecular ────────────► D04/D10
I05 Desenvolvimento/Anatomia ──────► D01
I06 Fisiologia ────────────────────► D01/D02
B06 EDOs ──────────────────────────► D02/D06
B11 Sistemas Dinâmicos ────────────► D05/D06
B10 Geometria Diferencial ─────────► D07
B08/B09 Topologia/TDA ─────────────► D08
B13 Informação ────────────────────► D03/D10
```

## Filosofia

Quando termos como **manifold**, **atrator**, **dimensionalidade** ou **topologia** aparecerem na literatura de neurociência, a meta é sempre distinguir:

```text
definição matemática rigorosa
vs.
uso aproximado / operacional na neurociência
```

Isso evita transformar metáforas geométricas em afirmações matemáticas fortes sem justificativa.
