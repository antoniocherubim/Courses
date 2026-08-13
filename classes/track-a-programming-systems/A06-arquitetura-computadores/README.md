# Masterclass de Arquitetura de Computadores
## Da lógica digital à CPU moderna

> Um caderno de estudo e consulta para entender como instruções Assembly se transformam em operações físicas dentro de um computador.

[← A05 Assembly](../A05-assembly/) · [↑ Track A](../README.md) · Próxima: **A07 — Memória e Representação de Dados**

---

# Sumário

1. Objetivo e mapa mental
2. Arquitetura, ISA e microarquitetura
3. Bits e álgebra booleana
4. Portas lógicas
5. Circuitos combinacionais
6. Somadores, multiplexadores e decoders
7. Circuitos sequenciais, clock e flip-flops
8. Registradores e register file
9. Memória: SRAM, DRAM e barramentos
10. ALU e flags
11. Datapath
12. Unidade de controle
13. Fetch–Decode–Execute
14. Construindo uma CPU mínima
15. ISA, machine code e Assembly
16. RISC vs CISC
17. x86-64 e modos de endereçamento
18. Stack, call e ret no hardware
19. Interrupções, exceções e privilégios
20. Hierarquia de memória
21. Caches e localidade
22. Cache lines e associatividade
23. Memória virtual, MMU e TLB
24. Pipeline
25. Hazards, forwarding e stalls
26. Branch prediction
27. Superscalar
28. Out-of-order execution
29. Register renaming e retirement
30. Micro-ops
31. SIMD
32. Multicore e cache coherence
33. Memory ordering e atomics
34. I/O, MMIO, DMA e PCIe
35. CPU vs GPU
36. Performance: latência, throughput e IPC
37. Compute-bound vs memory-bound
38. Assembly visto de dentro da CPU
39. C/C++ e Python vistos de baixo
40. Experimentos no Linux
41. Mini-projetos
42. Roteiro de estudo
43. Cheat sheet
44. Glossário
45. Conclusão

---

# 1. Objetivo e mapa mental

Depois de Assembly, a pergunta natural é:

> O que a CPU realmente faz quando executa uma instrução?

Ao ler:

```asm
add rax, rbx
```

o modelo arquitetural é simplesmente:

```text
RAX ← RAX + RBX
```

Mas queremos entender o caminho físico e lógico por trás disso:

```text
transistores
    ↓
portas lógicas
    ↓
circuitos combinacionais e sequenciais
    ↓
registradores + ALU
    ↓
datapath + unidade de controle
    ↓
ISA
    ↓
machine code
    ↓
Assembly
    ↓
C / C++
    ↓
Python / runtimes / ML
```

O objetivo desta aula não é decorar componentes, e sim construir um modelo mental contínuo da máquina.

---

# 2. Arquitetura, ISA e microarquitetura

É importante separar três níveis.

## ISA — Instruction Set Architecture

É o contrato visível ao software. Define:

- registradores;
- instruções;
- tipos de operandos;
- encoding;
- modos de endereçamento;
- comportamento de exceções;
- privilégios;
- modelo arquitetural de memória.

Exemplos:

```text
x86-64
AArch64
RISC-V
```

## Organização

É como grandes blocos são dispostos:

- caches;
- barramentos/interconexões;
- ALUs;
- unidades de load/store;
- controladores;
- memória.

## Microarquitetura

É a implementação concreta de uma ISA.

Duas CPUs diferentes podem executar a mesma ISA e possuir internamente pipelines, caches e schedulers totalmente diferentes.

```text
ISA = o que a CPU promete fazer
microarquitetura = como uma CPU específica faz isso
```

---

# 3. Bits e álgebra booleana

O computador digital abstrai fenômenos elétricos em estados lógicos:

```text
LOW  → 0
HIGH → 1
```

Fisicamente existem faixas de tensão válidas; 0 e 1 são uma abstração.

Operações fundamentais:

```text
NOT
AND
OR
XOR
```

## NOT

```text
A | ¬A
--+---
0 | 1
1 | 0
```

## AND

```text
A B | A AND B
----+--------
0 0 | 0
0 1 | 0
1 0 | 0
1 1 | 1
```

## OR

```text
A B | A OR B
----+-------
0 0 | 0
0 1 | 1
1 0 | 1
1 1 | 1
```

## XOR

```text
A B | A XOR B
----+--------
0 0 | 0
0 1 | 1
1 0 | 1
1 1 | 0
```

XOR aparece em somadores, paridade, criptografia e manipulação de bits.

---

# 4. Portas lógicas

Portas lógicas implementam operações booleanas fisicamente.

```text
A ──┐
    ├── AND ── Y
B ──┘
```

ou:

```text
A ──┐
    ├── XOR ── Y
B ──┘
```

Portas NAND e NOR são universais: em princípio, toda lógica digital pode ser construída apenas com uma delas.

Essa é uma ideia central: sistemas enormes surgem da composição de primitivas extremamente simples.

---

# 5. Circuitos combinacionais

Um circuito combinacional possui saída determinada pelas entradas atuais:

```text
output = f(inputs)
```

Não guarda estado.

Exemplos:

- somadores;
- comparadores;
- multiplexadores;
- decoders;
- partes da ALU.

---

# 6. Somadores, multiplexadores e decoders

## Half adder

Soma dois bits.

```text
SUM   = A XOR B
CARRY = A AND B
```

```text
A B | SUM CARRY
----+----------
0 0 |  0    0
0 1 |  1    0
1 0 |  1    0
1 1 |  0    1
```

## Full adder

Adiciona:

```text
A + B + carry-in
```

e produz:

```text
sum + carry-out
```

Encadeando full adders podemos somar palavras inteiras.

```text
bit 0 → bit 1 → bit 2 → ...
```

Um ripple-carry adder é fácil de compreender, embora CPUs reais usem circuitos mais sofisticados para reduzir atraso.

## Multiplexador

Seleciona uma entre várias entradas:

```text
A ──┐
    ├── MUX ── Y
B ──┘    ▲
         │
       select
```

MUXes permitem que sinais de controle escolham o caminho dos dados.

## Decoder

Transforma um código em uma seleção:

```text
00 → linha 0
01 → linha 1
10 → linha 2
11 → linha 3
```

Isso aparece na seleção de registradores, memória e instruções.

---

# 7. Circuitos sequenciais, clock e flip-flops

Circuitos sequenciais possuem estado:

```text
next_state = f(current_state, inputs)
```

Sem estado não existiriam:

- registradores;
- contadores;
- memória;
- máquinas de estados;
- execução sequencial de programas.

## Flip-flop

Um flip-flop armazena um bit.

Com vários podemos formar registradores.

## Clock

Um clock fornece uma referência temporal:

```text
__|‾‾|__|‾‾|__|‾‾|__
```

Em um modelo simples:

```text
lógica calcula próximo estado
↓
borda do clock
↓
novo estado é registrado
```

Uma frequência de 4 GHz significa cerca de quatro bilhões de ciclos por segundo, não quatro bilhões de instruções por segundo.

---

# 8. Registradores e register file

Registradores armazenam valores usados diretamente pela CPU.

Em x86-64 você conhece:

```text
RAX RBX RCX RDX
RSI RDI RBP RSP
R8 ... R15
RIP
```

Um conjunto de registradores pode ser organizado como um register file:

```text
     read index A
          │
          ▼
    ┌───────────┐
    │ Register  │──► read A
    │   File    │──► read B
    └───────────┘
          ▲
          │
      write data
```

O programa enxerga registradores arquiteturais. Uma CPU moderna pode possuir mais registradores físicos do que aqueles expostos pela ISA.

---

# 9. Memória: SRAM, DRAM e barramentos

Podemos inicialmente modelar memória como:

```text
address → value
```

## SRAM

Rápida, cara e pouco densa. Muito usada em caches.

## DRAM

Mais lenta, densa e barata. Usada como memória principal.

Daí surge a hierarquia:

```text
registradores
↓
cache SRAM
↓
DRAM
```

## Barramentos

Em uma CPU didática podemos separar:

```text
data bus
address bus
control bus
```

Em sistemas modernos as interconexões são mais complexas, mas a ideia permanece: componentes precisam transportar dados e sinais.

---

# 10. ALU e flags

ALU significa Arithmetic Logic Unit.

Executa operações como:

```text
ADD
SUB
AND
OR
XOR
SHIFT
COMPARE
```

Modelo:

```text
A ─────┐
       ▼
    ┌─────┐
    │ ALU │──► result
    └─────┘
       ▲
B ─────┘

operation ─► controle
```

A ALU também pode produzir flags:

```text
ZF = Zero
CF = Carry
SF = Sign
OF = Overflow
```

Assim:

```text
cmp
↓
subtração/ALU
↓
flags
↓
je / jne / jl / ...
```

---

# 11. Datapath

O datapath é o caminho pelo qual os dados fluem.

```text
Register File
   │      │
   ▼      ▼
      ALU
       │
       ▼
    result
       │
       └────► Register File
```

Com memória:

```text
Registers
   ↓
  ALU ─────► endereço
   ↓             ↓
resultado      Memory
   └─────────────┘
         ↓
      write-back
```

Uma forma útil de pensar em CPU é:

> datapath move e transforma dados; controle decide quais caminhos usar.

---

# 12. Unidade de controle

A unidade de controle interpreta instruções e gera sinais.

Para uma instrução fictícia:

```text
ADD R1, R2
```

poderíamos gerar:

```text
read_a       = R1
read_b       = R2
alu_operation= ADD
write_dst    = R1
write_enable = 1
```

Fluxo:

```text
instruction bits
      ↓
control unit
      ↓
control signals
      ↓
datapath
```

Controle pode ser implementado por lógica fixa ou, em certas arquiteturas, por microcódigo.

---

# 13. Fetch–Decode–Execute

O modelo clássico:

## Fetch

Buscar os bytes apontados pelo Program Counter.

## Decode

Descobrir opcode, operandos e modo de endereçamento.

## Execute

Executar a operação.

## Write-back

Guardar resultado quando necessário.

```text
PC
↓
FETCH
↓
Instruction Register
↓
DECODE
↓
EXECUTE
↓
WRITE BACK
↓
PC atualizado
```

Em x86-64 o registrador arquitetural associado ao PC é o RIP.

---

# 14. Construindo uma CPU mínima

Imagine esta ISA:

```text
LOAD  R1, addr
STORE R1, addr
ADD   R1, R2
SUB   R1, R2
JMP   addr
JZ    addr
HALT
```

Precisamos de:

```text
Program Counter
Instruction Register
Register File
ALU
Memory
Control Unit
```

`LOAD R1, 100` pode ser decomposto didaticamente em:

```text
MAR ← 100
MDR ← Memory[MAR]
R1  ← MDR
```

`ADD R1, R2`:

```text
ALU_A  ← R1
ALU_B  ← R2
ALU_OP ← ADD
R1     ← ALU_RESULT
```

`JZ 200`:

```text
if ZF == 1:
    PC ← 200
```

É aqui que Assembly deixa de parecer uma linguagem misteriosa. Ele é uma codificação para comandar um datapath.

---

# 15. ISA, machine code e Assembly

ISA é a interface entre hardware e software.

```text
Assembly
↓ assembler
machine code
↓ CPU decoder
operações internas
```

A CPU não lê:

```asm
add rax, rbx
```

Ela lê bytes que a ISA define como aquela instrução.

Assembly é a representação humana desses bytes e operações.

---

# 16. RISC vs CISC

## RISC

Historicamente associado a:

- instruções regulares;
- formatos mais simples;
- filosofia load/store;
- muitos registradores.

Exemplos:

```text
ARM
RISC-V
```

## CISC

Historicamente associado a:

- instruções mais complexas;
- muitos modos de endereçamento;
- encoding variável.

Exemplo:

```text
x86
```

A distinção é menos rígida em CPUs modernas. x86, por exemplo, frequentemente decodifica instruções complexas em micro-ops mais simples.

---

# 17. x86-64 e modos de endereçamento

x86-64 permite endereços como:

```asm
mov rax, [rbx + rcx*8 + 16]
```

O endereço efetivo é:

```text
RBX + RCX*8 + 16
```

CPUs modernas possuem hardware dedicado à geração de endereços, frequentemente descrito como AGU — Address Generation Unit.

Isso ajuda a executar arrays e structs eficientemente.

---

# 18. Stack, call e ret no hardware

`call` em x86 altera o fluxo e salva um endereço de retorno.

Conceitualmente:

```text
RSP -= 8
[RSP] = return_address
RIP = function_address
```

`ret` faz aproximadamente:

```text
RIP = [RSP]
RSP += 8
```

Mas stack frames, argumento em registradores e registradores preservados são em grande parte regras de ABI, não propriedades universais da CPU.

---

# 19. Interrupções, exceções e privilégios

## Interrupções

Eventos tipicamente externos:

```text
timer
rede
teclado
dispositivo
```

## Exceções

Eventos associados à instrução atual:

```text
divisão por zero
page fault
invalid opcode
```

Modelo:

```text
programa
↓
evento
↓
CPU salva/organiza contexto
↓
handler
↓
retorno
```

## Privilégios

Simplificando x86:

```text
Ring 3 → user mode
Ring 0 → kernel mode
```

Uma syscall usa mecanismos definidos pela arquitetura para entrar controladamente no kernel.

---

# 20. Hierarquia de memória

Princípio fundamental:

> memória rápida tende a ser pequena e cara; memória grande tende a ser mais lenta.

```text
Registers
   ↓
L1 Cache
   ↓
L2 Cache
   ↓
L3 Cache
   ↓
DRAM
   ↓
SSD
   ↓
armazenamento remoto
```

Boa parte da engenharia de performance consiste em evitar que a CPU espere dados.

---

# 21. Caches e localidade

Cache mantém cópias de dados provavelmente úteis.

## Localidade temporal

Algo usado agora pode ser usado novamente em breve.

## Localidade espacial

Se um endereço foi usado, endereços próximos podem ser usados logo.

Por isso:

```c
for (size_t i = 0; i < n; ++i)
    sum += a[i];
```

tende a conversar muito bem com caches.

---

# 22. Cache lines e associatividade

Caches transferem blocos chamados cache lines. Em muitas arquiteturas x86 modernas uma linha possui 64 bytes, mas não trate isso como uma lei universal.

Se `a[0]` é carregado, vários bytes vizinhos podem vir junto.

## Mapeamento

### Direct-mapped

Cada bloco possui um único local possível.

### Fully associative

Pode ocupar qualquer linha.

### Set-associative

Compromisso comum em CPUs reais.

Conceitos:

```text
tag
index
offset
```

## Escritas

`write-through`: propaga imediatamente para nível inferior.

`write-back`: mantém linha modificada e escreve depois; usa dirty state.

---

# 23. Memória virtual, MMU e TLB

Processos usam normalmente endereços virtuais.

```text
virtual address
↓
MMU
↓
page tables
↓
physical address
```

Consultar tabelas de página para cada acesso seria caro.

Por isso existe o TLB:

```text
virtual address
↓
TLB hit?
├── sim → tradução rápida
└── não → page table walk
```

Isso conecta diretamente arquitetura de computadores a sistemas operacionais.

---

# 24. Pipeline

Modelo didático de cinco fases:

```text
IF  = Instruction Fetch
ID  = Decode
EX  = Execute
MEM = Memory
WB  = Write Back
```

Sem pipeline:

```text
I1: IF ID EX MEM WB
I2:                IF ID EX MEM WB
```

Com pipeline:

```text
cycle: 1  2  3  4  5  6  7
I1:    IF ID EX MEM WB
I2:       IF ID EX MEM WB
I3:          IF ID EX MEM WB
```

O ganho principal é throughput.

---

# 25. Hazards, forwarding e stalls

## Data hazard

```asm
add rax, rbx
sub rcx, rax
```

A segunda instrução depende da primeira.

## Control hazard

```asm
cmp rax, rbx
je destino
```

A próxima instrução depende do branch.

## Structural hazard

Duas operações precisam do mesmo recurso.

## Forwarding

Resultado é encaminhado diretamente entre estágios.

## Stall

Pipeline espera. Uma bolha pode ser inserida.

---

# 26. Branch prediction

Branches impedem saber imediatamente o próximo PC.

```asm
cmp eax, 0
je .zero
```

A CPU prediz:

```text
taken?
not taken?
qual destino?
```

e continua trabalhando especulativamente.

Se errar:

```text
trabalho especulativo descartado
+
pipeline redirecionado
```

Isso é uma branch misprediction.

---

# 27. Superscalar

Uma CPU superscalar pode executar múltiplas operações por ciclo quando há recursos e independência.

```text
cycle N:
  integer add
  load
  SIMD op
```

Assim, 4 GHz não significam uma instrução por ciclo. IPC pode ser maior ou menor que 1 dependendo do workload.

---

# 28. Out-of-order execution

Considere:

```asm
load rax, [mem1]
add  rbx, rcx
imul rdx, rsi
add  r8, rax
```

Se o load demora, as operações independentes podem ser executadas enquanto ele espera.

```text
program order
↓
analysis of dependencies
↓
execution when operands/resources are ready
```

A CPU preserva o comportamento arquitetural esperado.

---

# 29. Register renaming e retirement

Registradores da ISA são nomes arquiteturais.

Internamente:

```text
RAX versão 1 → P17
RAX versão 2 → P42
```

Register renaming remove dependências falsas e aumenta paralelismo.

## Retirement

Mesmo executando fora de ordem, os resultados precisam tornar-se oficialmente visíveis de maneira controlada.

```text
execute out of order
↓
retire/commit in architectural order
```

Isso permite recuperação de branch misprediction e exceções precisas.

---

# 30. Micro-ops

Uma instrução x86 pode ser decodificada em operações internas menores:

```text
x86 instruction
↓
decoder
↓
µops
↓
rename/schedule
↓
execution units
```

Logo:

> uma linha Assembly não corresponde necessariamente a uma única operação física interna.

---

# 31. SIMD

SIMD significa Single Instruction, Multiple Data.

Em vez de:

```text
a0+b0
a1+b1
a2+b2
a3+b3
```

operamos conceitualmente em:

```text
[a0 a1 a2 a3] + [b0 b1 b2 b3]
```

Em x86 aparecem registradores/famílias como:

```text
XMM / SSE
YMM / AVX
ZMM / AVX-512
```

É central para:

- álgebra linear;
- ML;
- multimídia;
- criptografia;
- computação científica.

---

# 32. Multicore e cache coherence

Uma CPU pode ter vários cores:

```text
Core 0 ─┐
Core 1 ─┼──► cache compartilhado / RAM
Core 2 ─┤
Core 3 ─┘
```

Cada core pode possuir caches privados.

Problema:

```text
Core 0 cache: x = 10
Core 1 cache: x = 10
```

Core 0 escreve `x = 20`. Como Core 1 descobre?

Protocolos de coerência coordenam estados. Um protocolo clássico é MESI:

```text
Modified
Exclusive
Shared
Invalid
```

---

# 33. Memory ordering e atomics

Mesmo que o código-fonte mostre:

```c
a = 1;
b = 2;
```

outros cores podem interagir com stores, caches, buffers e reordenações de maneira sutil.

Existem dois níveis de transformação a lembrar:

```text
compiler reordering
CPU reordering
```

Por isso C/C++ possuem memory model e operações atômicas.

Em x86 encontramos recursos como:

```asm
lock add ...
cmpxchg ...
```

Esses mecanismos sustentam mutexes, semáforos e estruturas lock-free.

---

# 34. I/O, MMIO, DMA e PCIe

## MMIO

Memory-Mapped I/O faz certos endereços representarem registradores de dispositivos.

```text
CPU store
↓
endereço MMIO
↓
dispositivo
```

## DMA

Direct Memory Access permite transferência entre dispositivo e RAM com pouca intervenção direta da CPU.

Exemplo:

```text
NIC recebe pacote
↓
DMA
↓
buffer em RAM
↓
interrupção
↓
kernel
```

## PCI Express

Interconexão comum para:

- GPU;
- NVMe;
- placas de rede;
- aceleradores.

Em GPU discreta:

```text
CPU RAM
  ↕
 PCIe
  ↕
GPU VRAM
```

Mover dados pode ser parte importante do custo de ML.

---

# 35. CPU vs GPU

CPU:

```text
poucos cores sofisticados
baixa latência
branch prediction forte
controle complexo
```

GPU:

```text
muitos elementos de execução
alto throughput
paralelismo massivo
```

CPU é excelente em:

- controle;
- branches;
- tarefas irregulares;
- baixa latência.

GPU é excelente em:

- operações regulares;
- álgebra linear;
- grandes lotes;
- paralelismo de dados.

---

# 36. Performance: latência, throughput e IPC

## Latência

Tempo para uma operação terminar.

## Throughput

Quantidade concluída por unidade de tempo.

## IPC

Instructions Per Cycle.

Uma aproximação clássica:

```text
tempo ≈ instruções × ciclos/instrução × tempo/ciclo
```

Na prática, caches, dependências, branches e paralelismo tornam tudo mais dinâmico.

## Clock não é tudo

Uma CPU de 4 GHz não é automaticamente mais rápida que uma de 3 GHz.

Também importam:

```text
IPC
cache
memory latency/bandwidth
branch predictor
execution width
workload
```

---

# 37. Compute-bound vs memory-bound

Um workload pode estar limitado por unidades de computação:

```text
compute-bound
```

ou por movimentação de dados:

```text
memory-bound
```

Um loop simples pode passar mais tempo esperando memória do que fazendo `add`.

Essa mudança de perspectiva é essencial:

> performance não é apenas reduzir instruções; muitas vezes é mover menos dados e mover dados melhor.

---

# 38. Assembly visto de dentro da CPU

Considere:

```asm
add rax, rbx
```

No nível ISA:

```text
RAX ← RAX + RBX
```

Em uma CPU didática:

```text
RAX ─┐
     ├──► ALU ADD ───► RAX
RBX ─┘
```

Em uma CPU moderna, conceitualmente pode haver:

```text
instruction cache
↓
fetch
↓
decode
↓
micro-op
↓
register rename
↓
scheduler
↓
physical registers
↓
integer ALU
↓
result
↓
retirement
```

Essas duas visões são úteis. A primeira ensina computação; a segunda explica performance real.

---

# 39. C/C++ e Python vistos de baixo

## C/C++

```c
int x = a + b;
```

pode virar algo como:

```asm
mov eax, edi
add eax, esi
```

Mas o compilador pode:

- eliminar variáveis;
- inlinear funções;
- reordenar operações;
- vetorizar;
- manter tudo em registradores.

## Python

```python
x = a + b
```

pode atravessar:

```text
Python bytecode/runtime
↓
type dispatch
↓
funções nativas
↓
machine code
↓
CPU
```

Já uma operação NumPy/PyTorch pode entrar rapidamente em código nativo vetorizado ou GPU.

Por isso conhecer arquitetura melhora inclusive a forma de escrever código de alto nível.

---

# 40. Experimentos no Linux

## Ver sua CPU

```bash
lscpu
```

Observe:

```text
Architecture
CPU(s)
Thread(s) per core
Core(s) per socket
cache sizes
flags
```

## Informações detalhadas

```bash
cat /proc/cpuinfo
```

## Caches

```bash
lscpu -C
```

## Gerar Assembly

```bash
gcc -O0 -S -masm=intel programa.c -o O0.s
gcc -O3 -march=native -S -masm=intel programa.c -o O3.s
```

## Disassembly

```bash
objdump -d -Mintel programa
```

## Hardware counters

Quando disponível:

```bash
perf stat ./programa
```

Observe métricas como:

```text
cycles
instructions
branches
branch-misses
cache-misses
```

## Experimento de cache

Compare um array percorrido sequencialmente com acessos aleatórios.

## Experimento de matriz

Em armazenamento row-major, compare:

```c
for (i)
    for (j)
        use(a[i][j]);
```

com:

```c
for (j)
    for (i)
        use(a[i][j]);
```

Meça a diferença.

---

# 41. Mini-projetos

## 1 — ALU de 8 bits em software

Implemente em C ou Python:

```text
ADD SUB AND OR XOR SHL SHR
```

e calcule:

```text
ZF CF SF OF
```

## 2 — CPU mínima

Implemente em simulador, HDL ou software:

```text
PC
Instruction Register
Register File
ALU
RAM
Control Unit
```

ISA:

```text
LOAD
STORE
ADD
SUB
JMP
JZ
HALT
```

## 3 — Emulador + assembler próprio

Crie algo como:

```text
MOV R1, 10
MOV R2, 20
ADD R1, R2
HALT
```

Faça um assembler transformar isso em bytes e um emulador executar os bytes.

## 4 — Cache locality

Compare ordens de acesso em arrays/matrizes grandes.

## 5 — Branch prediction

Compare uma condição previsível com dados aleatórios e use `perf stat`.

## 6 — Vetorização automática

Escreva:

```c
void add(const float *a, const float *b, float *c, size_t n) {
    for (size_t i = 0; i < n; ++i)
        c[i] = a[i] + b[i];
}
```

Compare Assembly em `-O0` e `-O3 -march=native`.

## 7 — Multiplicação de matrizes

Implemente versão ingênua e depois experimente:

```text
loop reordering
blocking/tiling
SIMD
```

Esse projeto é uma ponte excelente para machine learning.

---

# 42. Roteiro de estudo

## Fase 1 — Lógica digital

```text
bits
boolean algebra
gates
MUX
decoder
adder
flip-flop
clock
```

Meta: entender como bits podem ser transformados e armazenados.

## Fase 2 — CPU mínima

```text
registers
ALU
PC
memory
datapath
control unit
```

Meta: desenhar no papel uma CPU capaz de executar uma ISA pequena.

## Fase 3 — ISA

```text
opcode
machine code
registers
addressing
branches
stack
```

Meta: compreender Assembly como interface do hardware.

## Fase 4 — Memória

```text
SRAM
DRAM
cache
cache lines
locality
virtual memory
TLB
```

Meta: compreender por que memória domina muitos gargalos.

## Fase 5 — CPU moderna

```text
pipeline
branch prediction
superscalar
out-of-order
register renaming
retirement
micro-ops
```

Meta: abandonar a ideia de uma instrução completamente executada antes da próxima.

## Fase 6 — Paralelismo e I/O

```text
SIMD
multicore
coherence
atomics
DMA
PCIe
GPU
```

Meta: entender como o computador moderno escala execução e movimentação de dados.

---

# 43. Cheat sheet

## Da física ao software

```text
transistor
↓
gate
↓
combinational/sequential logic
↓
register + ALU
↓
datapath + control
↓
CPU
↓
ISA
↓
Assembly
↓
C/C++
↓
runtimes / Python
```

## CPU mínima

```text
PC
Instruction Register
Register File
ALU
Memory
Control Unit
```

## Execução básica

```text
Fetch
Decode
Execute
Memory
Write-back
```

## CPU moderna

```text
Fetch
Predict
Decode
Rename
Schedule
Execute
Retire
```

## Hierarquia

```text
Registers
L1
L2
L3
DRAM
SSD
```

## Paralelismo

```text
ILP     → múltiplas instruções
SIMD    → múltiplos dados
Multicore → múltiplos fluxos/threads
GPU     → paralelismo massivo
```

---

# 44. Glossário

**ALU** — Arithmetic Logic Unit. Executa operações aritméticas e lógicas.

**Branch predictor** — prediz o caminho de desvios para manter o frontend da CPU trabalhando.

**Cache** — memória pequena e rápida que reduz acessos a níveis mais lentos.

**Cache line** — unidade de transferência/armazenamento de dados na cache.

**Clock** — referência temporal usada para sincronizar circuitos sequenciais.

**Control unit** — gera sinais que comandam o datapath.

**Datapath** — caminhos e unidades onde dados são transportados e transformados.

**DMA** — Direct Memory Access; dispositivo transfere dados para/de memória com pouca intervenção da CPU.

**DRAM** — tecnologia tipicamente usada na memória principal.

**Exception** — evento síncrono associado à execução de uma instrução.

**Flip-flop** — elemento digital capaz de armazenar estado.

**IPC** — Instructions Per Cycle.

**ISA** — Instruction Set Architecture, contrato visível entre software e processador.

**Localidade espacial** — tendência de acessar endereços próximos.

**Localidade temporal** — tendência de reutilizar dados recentes.

**MMIO** — Memory-Mapped I/O.

**MMU** — Memory Management Unit.

**Microarquitetura** — implementação concreta de uma ISA.

**Micro-op** — operação interna em que uma instrução pode ser decomposta.

**Out-of-order** — execução de operações quando operandos estão prontos, sem obedecer estritamente à ordem textual interna.

**Pipeline** — sobreposição das fases de várias instruções.

**Register renaming** — mapeamento de registradores arquiteturais em registradores físicos.

**Retirement** — etapa de commit do resultado ao estado arquitetural.

**SIMD** — Single Instruction, Multiple Data.

**SRAM** — memória rápida normalmente usada em caches.

**Superscalar** — capacidade de emitir/executar várias operações por ciclo.

**TLB** — cache de traduções entre endereços virtuais e físicos.

---

# 45. Conclusão

Assembly nos ensina:

```text
o que a máquina deve fazer
```

Arquitetura de computadores nos ensina:

```text
como uma máquina consegue realizar isso
```

Ao encontrar:

```asm
add rax, rbx
```

você deve conseguir alternar entre duas imagens.

## CPU didática

```text
RAX ─┐
     ├──► ALU ───► RAX
RBX ─┘
```

## CPU moderna

```text
I-cache
↓
fetch + prediction
↓
decode
↓
rename
↓
schedule
↓
execution unit
↓
retirement
```

E acima disso:

```text
Python
↓
C/C++ / runtime
↓
Assembly
↓
ISA
↓
microarquitetura
↓
lógica digital
↓
transistores
```

Quando essas camadas deixam de parecer disciplinas separadas, você começa a possuir um modelo mental único do computador.

---

# Regra de ouro

Para cada nova abstração, pergunte:

1. Que estado precisa ser armazenado?
2. Que transformação precisa ser feita sobre os bits?
3. Que caminho os dados percorrem?
4. Que sinais escolhem esse caminho?
5. Qual gargalo físico pode limitar essa operação?

Essas cinco perguntas conectam software, arquitetura e hardware.

---

[← A05 Assembly](../A05-assembly/) · [↑ Track A](../README.md) · Próxima: **A07 — Memória e Representação de Dados**
