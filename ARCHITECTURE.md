# Repository Architecture

O repositório separa três funções que antes estavam misturadas no README principal.

## `classes/` — conhecimento disciplinar

Uma masterclass ensina um tópico com profundidade suficiente para servir como material de estudo e consulta.

Exemplos:

```text
A05 Assembly
B06 Topologia
D03 Código Neural
G03 Termodinâmica
```

## `maps/` — conhecimento relacional

Um mapa conecta um conceito que reaparece em várias disciplinas.

Exemplos:

```text
informação
memória
dinâmica
energia
escala
adaptação
```

O mapa não substitui as masterclasses. Ele registra relações, diferenças de significado e caminhos entre elas.

## `roadmap/` — conhecimento sobre o próprio aprendizado

Contém:

- estado do conhecimento;
- prioridades;
- dependências;
- convergências;
- visão de longo prazo.

## Regra de decisão

```text
"quero aprender X"
→ classes/

"quero relacionar X entre áreas"
→ maps/

"quero decidir quando ou por que estudar X"
→ roadmap/
```

Essa separação mantém o README raiz curto e permite que o repositório cresça por anos sem virar uma lista linear gigantesca.
