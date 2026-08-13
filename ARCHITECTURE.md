# Repository Architecture

O repositório separa três funções que antes estavam misturadas no README principal.

## `classes/` — conhecimento disciplinar

Uma class ensina um tópico com profundidade suficiente para servir como material de estudo e consulta.

> Os IDs são identificadores estáveis dentro de cada track. Eles ajudam a navegação e as dependências, mas não representam uma ordem temporal obrigatória de estudo.

Exemplos:

```text
A05 Assembly
B08 Topologia
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

O mapa não substitui as classes. Ele registra relações, diferenças de significado e caminhos entre elas.

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

## Fontes e níveis de afirmação

As classes são sínteses de estudo e consulta.

Ao integrar ciência, matemática, neurociência e IA, distinguir explicitamente quando relevante:

- definição formal;
- resultado estabelecido / evidência empírica;
- modelo;
- hipótese;
- interpretação;
- analogia ou metáfora.

Livros, papers, aulas, canais e documentações devem ser registrados como referências, não tratados automaticamente como autoridade única.
