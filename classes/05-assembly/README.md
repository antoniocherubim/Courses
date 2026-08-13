# Masterclass de Assembly — da linguagem de máquina ao x86-64 no Linux

> Um caderno de estudo e consulta para quem quer entender o que acontece entre C/C++, o sistema operacional e a CPU.

---

## Sumário

1. [O que é Assembly — e o que ele não é](#1-o-que-é-assembly--e-o-que-ele-não-é)
2. [A pilha de abstrações: Python → C → Assembly → CPU](#2-a-pilha-de-abstrações-python--c--assembly--cpu)
3. [ISA, Assembly e microarquitetura](#3-isa-assembly-e-microarquitetura)
4. [Por que x86-64?](#4-por-que-x86-64)
5. [Preparando o ambiente no Linux](#5-preparando-o-ambiente-no-linux)
6. [Seu primeiro programa Assembly](#6-seu-primeiro-programa-assembly)
7. [Registradores](#7-registradores)
8. [Tamanhos de dados](#8-tamanhos-de-dados)
9. [Movendo dados: `mov`](#9-movendo-dados-mov)
10. [Memória, endereços e dereferência](#10-memória-endereços-e-dereferência)
11. [Endianness](#11-endianness)
12. [Aritmética](#12-aritmética)
13. [Operações bit a bit](#13-operações-bit-a-bit)
14. [`lea`: uma das instruções mais importantes](#14-lea-uma-das-instruções-mais-importantes)
15. [Flags e o registrador RFLAGS](#15-flags-e-o-registrador-rflags)
16. [Comparações e saltos](#16-comparações-e-saltos)
17. [Loops](#17-loops)
18. [Arrays](#18-arrays)
19. [Strings](#19-strings)
20. [A stack](#20-a-stack)
21. [`call`, `ret` e chamadas de função](#21-call-ret-e-chamadas-de-função)
22. [System V AMD64 ABI](#22-system-v-amd64-abi)
23. [Stack frames e variáveis locais](#23-stack-frames-e-variáveis-locais)
24. [Syscalls no Linux](#24-syscalls-no-linux)
25. [C ↔ Assembly](#25-c--assembly)
26. [Assembly gerado pelo compilador](#26-assembly-gerado-pelo-compilador)
27. [Otimização e o que o compilador elimina](#27-otimização-e-o-que-o-compilador-elimina)
28. [Assembly e orientação a objetos](#28-assembly-e-orientação-a-objetos)
29. [ELF, assembler, linker e loader](#29-elf-assembler-linker-e-loader)
30. [GDB: olhando a CPU trabalhar](#30-gdb-olhando-a-cpu-trabalhar)
31. [Objdump, readelf e nm](#31-objdump-readelf-e-nm)
32. [Machine code](#32-machine-code)
33. [Memória virtual](#33-memória-virtual)
34. [Floating point e SIMD](#34-floating-point-e-simd)
35. [CPU moderna: além de fetch/decode/execute](#35-cpu-moderna-além-de-fetchdecodeexecute)
36. [Concorrência e instruções atômicas](#36-concorrência-e-instruções-atômicas)
37. [Ring 3, Ring 0 e instruções privilegiadas](#37-ring-3-ring-0-e-instruções-privilegiadas)
38. [Intel vs AT&T](#38-intel-vs-att)
39. [Erros mentais comuns](#39-erros-mentais-comuns)
40. [Roteiro de estudo recomendado](#40-roteiro-de-estudo-recomendado)
41. [Mini projetos](#41-mini-projetos)
42. [Cheat sheet](#42-cheat-sheet)
43. [Glossário](#43-glossário)
44. [Conclusão](#44-conclusão)

---

# 1. O que é Assembly — e o que ele não é

Assembly é uma representação textual, feita para humanos, das instruções que uma determinada arquitetura de processador oferece.

Em C:

```c
int soma(int a, int b) {
    return a + b;
}
```

Uma versão simplificada em Assembly x86-64 pode ser:

```asm
mov eax, edi
add eax, esi
ret
```

A CPU, porém, não lê as palavras `mov`, `add` e `ret`.

Ela recebe **bytes** que representam essas instruções.

Portanto:

```text
C
↓ compilador
Assembly
↓ assembler
machine code
↓
CPU
```

Assembly também não é uma única linguagem universal.

Existem Assemblies diferentes para diferentes ISAs:

- x86
- x86-64 / AMD64
- ARM
- AArch64
- RISC-V
- MIPS
- AVR
- PowerPC
- etc.

Os conceitos fundamentais são parecidos, mas os registradores, instruções e convenções mudam.

---

# 2. A pilha de abstrações: Python → C → Assembly → CPU

Uma operação aparentemente simples:

```python
x = a + b
```

pode atravessar várias camadas:

```text
Python
    ↓
runtime / interpretador
    ↓
C
    ↓
código de máquina
    ↓
ISA
    ↓
CPU
    ↓
micro-operações
    ↓
circuitos digitais
    ↓
transistores
```

Em Python, `a + b` pode envolver:

- resolução de tipos;
- consulta a métodos especiais;
- criação de objetos;
- gerenciamento de referências;
- alocação de memória;
- tratamento de exceções.

Em C:

```c
int x = a + b;
```

o compilador já conhece o tipo.

Em Assembly, você está muito mais próximo de algo como:

```asm
mov eax, edi
add eax, esi
```

Assembly ajuda a enxergar onde as abstrações desaparecem.

---

# 3. ISA, Assembly e microarquitetura

É importante separar três coisas.

## 3.1 ISA — Instruction Set Architecture

A ISA é o **contrato entre software e processador**.

Ela define coisas como:

- registradores disponíveis;
- instruções;
- formatos de instrução;
- modos de endereçamento;
- comportamento das flags;
- modelo de memória;
- instruções privilegiadas.

x86-64 é uma ISA.

AArch64 é outra.

RISC-V é outra.

## 3.2 Assembly

Assembly é a representação simbólica dessa ISA.

Por exemplo:

```asm
add rax, rbx
```

é uma forma humana de expressar uma operação da ISA x86-64.

## 3.3 Microarquitetura

Dois processadores podem executar a mesma ISA de maneiras internas completamente diferentes.

Por exemplo:

```text
AMD Zen
Intel Core
```

podem executar o mesmo programa x86-64, apesar de possuírem pipelines, caches, unidades de execução e estratégias internas diferentes.

Assim:

```text
ISA = o que a CPU promete fazer
microarquitetura = como uma CPU específica faz isso
```

---

# 4. Por que x86-64?

Este material usa **x86-64 no Linux**.

Motivos:

- é extremamente comum em desktops e servidores;
- possui excelente tooling;
- GCC, Clang, GDB e binutils trabalham muito bem com ela;
- permite estudar diretamente programas C/C++;
- existe enorme quantidade de software real para investigar.

A sintaxe principal será **Intel**.

Quando necessário, compararemos com a sintaxe GNU/AT&T.

---

# 5. Preparando o ambiente no Linux

Ferramentas úteis:

```text
gcc
g++
nasm
gdb
objdump
readelf
nm
ld
as
```

Em distribuições Debian/Ubuntu/Mint, normalmente os pacotes relevantes são:

```bash
sudo apt install build-essential nasm gdb binutils
```

Verifique:

```bash
gcc --version
nasm -v
gdb --version
objdump --version
```

---

# 6. Seu primeiro programa Assembly

Vamos escrever diretamente para Linux sem usar libc.

Crie:

```text
hello.asm
```

Conteúdo:

```asm
global _start

section .data
    msg db "Hello, machine!", 10
    len equ $ - msg

section .text

_start:
    mov rax, 1
    mov rdi, 1
    lea rsi, [rel msg]
    mov rdx, len
    syscall

    mov rax, 60
    xor rdi, rdi
    syscall
```

Monte:

```bash
nasm -f elf64 hello.asm -o hello.o
```

Faça o linking:

```bash
ld hello.o -o hello
```

Execute:

```bash
./hello
```

Saída:

```text
Hello, machine!
```

O interessante é que aqui não há:

```c
printf(...)
```

nem:

```c
main(...)
```

Nós conversamos diretamente com o kernel através de **syscalls**.

A primeira chamada:

```asm
mov rax, 1
```

seleciona a syscall `write`.

Depois:

```asm
mov rdi, 1
```

define o file descriptor `stdout`.

Então:

```asm
lea rsi, [rel msg]
```

coloca o endereço da mensagem em `rsi`.

E:

```asm
mov rdx, len
```

define quantos bytes serão escritos.

Finalmente:

```asm
syscall
```

entra no kernel.

---

# 7. Registradores

Registradores são pequenas áreas de armazenamento dentro da CPU.

Eles são extremamente rápidos.

Em x86-64 temos registradores de propósito geral como:

```text
RAX
RBX
RCX
RDX
RSI
RDI
RBP
RSP

R8
R9
R10
R11
R12
R13
R14
R15
```

Além deles existem registradores especiais:

```text
RIP      instruction pointer
RFLAGS   flags
XMM0...  SIMD / floating point
YMM0...  AVX
ZMM0...  AVX-512
```

## 7.1 Subregistradores

Um mesmo registrador pode ser acessado em diferentes tamanhos.

Para `RAX`:

```text
RAX   64 bits
EAX   32 bits
AX    16 bits
AL     8 bits
AH     8 bits históricos
```

Visualmente:

```text
63                                  0
┌────────────────────────────────────┐
│                RAX                 │
└────────────────────────────────────┘
                    ┌────────────────┐
                    │      EAX       │
                    └────────────────┘
                            ┌────────┐
                            │   AX   │
                            └────────┘
                                ┌────┐
                                │ AL │
                                └────┘
```

Um detalhe muito importante de x86-64:

```asm
mov eax, 1
```

zera automaticamente os 32 bits superiores de `rax`.

Depois dessa instrução:

```text
RAX = 0x0000000000000001
```

---

# 8. Tamanhos de dados

Terminologia comum:

| Nome | Bits | Bytes |
|---|---:|---:|
| byte | 8 | 1 |
| word | 16 | 2 |
| dword | 32 | 4 |
| qword | 64 | 8 |

Exemplos:

```asm
mov al, 1
mov ax, 1
mov eax, 1
mov rax, 1
```

Quando o tamanho não é óbvio, NASM permite:

```asm
mov byte  [rax], 1
mov word  [rax], 1
mov dword [rax], 1
mov qword [rax], 1
```

O tamanho da operação importa.

---

# 9. Movendo dados: `mov`

A instrução mais frequente que você verá é:

```asm
mov destino, origem
```

Exemplos:

```asm
mov rax, 10
mov rbx, rax
```

Depois:

```text
RAX = 10
RBX = 10
```

Apesar do nome "move", o valor original normalmente não desaparece.

Na prática é mais parecido com uma **cópia**.

## 9.1 Registrador ← imediato

```asm
mov rax, 42
```

## 9.2 Registrador ← registrador

```asm
mov rbx, rax
```

## 9.3 Registrador ← memória

```asm
mov rax, [rbx]
```

## 9.4 Memória ← registrador

```asm
mov [rbx], rax
```

Uma regra importante:

x86 geralmente não permite uma instrução `mov` arbitrária de memória para memória.

Isto não é válido:

```asm
mov [rax], [rbx]
```

Normalmente você usa um registrador intermediário:

```asm
mov rcx, [rbx]
mov [rax], rcx
```

---

# 10. Memória, endereços e dereferência

Esta é provavelmente a ideia mais importante de Assembly.

Considere:

```asm
mov rax, 0x1000
```

Agora `rax` contém o número:

```text
0x1000
```

Mas:

```asm
mov rbx, [rax]
```

significa:

> Leia da memória no endereço armazenado em `rax`.

Então:

```text
RAX
 │
 │ contém 0x1000
 ▼

memória
0x1000 ──► algum valor
```

Os colchetes significam **dereferência**.

Compare com C:

```c
long *p;
long x = *p;
```

Conceitualmente:

```asm
mov rax, p
mov rbx, [rax]
```

Essa relação é fundamental:

```text
C pointer      Assembly address
*p             [register]
&p             address
```

---

# 11. Endianness

x86-64 é **little-endian**.

Considere:

```text
0x12345678
```

Na memória ele será armazenado como:

```text
endereço     byte
0x1000       78
0x1001       56
0x1002       34
0x1003       12
```

O byte menos significativo fica no menor endereço.

Isso aparece constantemente ao:

- examinar memória no debugger;
- analisar protocolos;
- interpretar arquivos binários;
- trabalhar com redes;
- fazer engenharia reversa.

---

# 12. Aritmética

## 12.1 Soma

```asm
add rax, rbx
```

equivale conceitualmente a:

```c
rax = rax + rbx;
```

## 12.2 Subtração

```asm
sub rax, rbx
```

## 12.3 Incremento

```asm
inc rax
```

## 12.4 Decremento

```asm
dec rax
```

## 12.5 Negação

```asm
neg rax
```

## 12.6 Multiplicação

Uma forma comum:

```asm
imul rax, rbx
```

ou:

```asm
imul rax, rbx, 10
```

## 12.7 Divisão

Divisão em x86 é um pouco menos intuitiva.

Para divisão unsigned:

```asm
div rbx
```

usa implicitamente:

```text
RDX:RAX
```

como dividendo.

Para divisão signed:

```asm
idiv rbx
```

Antes de uma divisão signed de 64 bits, frequentemente aparece:

```asm
cqo
idiv rbx
```

`cqo` estende o sinal de `rax` para `rdx:rax`.

Depois:

```text
RAX = quociente
RDX = resto
```

---

# 13. Operações bit a bit

Estas instruções conectam diretamente Assembly à representação binária.

## AND

```asm
and rax, rbx
```

## OR

```asm
or rax, rbx
```

## XOR

```asm
xor rax, rbx
```

Uma construção extremamente comum:

```asm
xor eax, eax
```

zera `eax`, portanto também `rax`.

## NOT

```asm
not rax
```

## Shift à esquerda

```asm
shl rax, 1
```

Aproximadamente:

```text
rax *= 2
```

se não houver overflow relevante.

## Shift lógico à direita

```asm
shr rax, 1
```

Preenche com zeros.

## Shift aritmético à direita

```asm
sar rax, 1
```

preserva o bit de sinal.

---

# 14. `lea`: uma das instruções mais importantes

`lea` significa:

```text
Load Effective Address
```

Considere:

```asm
lea rax, [rbx + 8]
```

Ela **não lê a memória em `[rbx + 8]`**.

Ela calcula o endereço:

```text
rax = rbx + 8
```

Compare:

```asm
mov rax, [rbx + 8]
```

Aqui a memória é lida.

Já:

```asm
lea rax, [rbx + 8]
```

apenas calcula o endereço.

## 14.1 `lea` como aritmética

Compiladores usam `lea` também para contas.

Por exemplo:

```asm
lea rax, [rdi + rdi*4]
```

calcula:

```text
rax = 5 * rdi
```

sem acessar memória.

Isso é um ótimo exemplo de por que o nome da instrução nem sempre revela todos os seus usos práticos.

---

# 15. Flags e o registrador RFLAGS

Muitas instruções atualizam bits especiais no registrador `RFLAGS`.

Flags importantes:

```text
ZF  Zero Flag
CF  Carry Flag
SF  Sign Flag
OF  Overflow Flag
```

## Zero Flag

É ativada quando o resultado é zero.

## Sign Flag

Reflete o bit de sinal do resultado.

## Carry Flag

Importante para operações unsigned.

## Overflow Flag

Importante para overflow signed.

Essas flags alimentam saltos condicionais.

---

# 16. Comparações e saltos

Assembly normalmente implementa:

```c
if (a == b)
```

através de:

```asm
cmp rax, rbx
je iguais
```

`cmp` faz internamente algo equivalente a:

```text
rax - rbx
```

mas descarta o resultado e preserva as flags.

## 16.1 Igualdade

```asm
cmp rax, rbx
je iguais
```

## 16.2 Diferença

```asm
jne diferentes
```

## 16.3 Signed

```text
jl   menor
jle  menor ou igual
jg   maior
jge  maior ou igual
```

## 16.4 Unsigned

```text
jb   below
jbe  below or equal
ja   above
jae  above or equal
```

Essa distinção é importante.

O mesmo padrão de bits pode significar coisas diferentes dependendo de você interpretá-lo como signed ou unsigned.

---

# 17. Loops

Em linguagem de alto nível:

```c
for (int i = 0; i < 10; i++) {
    ...
}
```

Uma tradução conceitual:

```asm
xor rcx, rcx

.loop:
    cmp rcx, 10
    jge .done

    ; corpo

    inc rcx
    jmp .loop

.done:
```

Assembly não precisa de `for`, `while` ou `do while`.

Essas estruturas são abstrações construídas a partir de:

```text
comparações
+
saltos
```

---

# 18. Arrays

Considere em C:

```c
long a[10];

x = a[i];
```

Cada `long` ocupa 8 bytes.

Portanto:

```text
endereço de a[i] =
base + i * 8
```

Em x86-64:

```asm
mov rax, [rdi + rcx*8]
```

Um modo de endereçamento x86 pode ter a forma:

```text
base + index * scale + displacement
```

onde `scale` pode ser:

```text
1
2
4
8
```

Exemplo:

```asm
mov eax, [rbx + rcx*4 + 16]
```

Isso é perfeito para arrays e structs.

---

# 19. Strings

Assembly não possui uma abstração universal de "string" como Python.

Uma string normalmente é simplesmente:

```text
bytes na memória
+
alguma convenção
```

Em C:

```c
char *s = "abc";
```

usa uma string terminada em zero:

```text
61 62 63 00
 a  b  c \0
```

Em NASM:

```asm
msg db "abc", 0
```

Já uma syscall como `write` não exige terminador `\0`.

Ela recebe:

```text
ponteiro + tamanho
```

Por isso:

```asm
msg db "abc"
len equ $ - msg
```

funciona perfeitamente.

---

# 20. A stack

A stack é uma região de memória usada intensamente durante execução de funções.

O registrador:

```text
RSP
```

é o **stack pointer**.

Ele aponta para o topo atual da stack.

Em x86-64, a stack cresce normalmente em direção a endereços menores.

## 20.1 `push`

```asm
push rax
```

conceitualmente:

```text
rsp -= 8
[rsp] = rax
```

## 20.2 `pop`

```asm
pop rax
```

conceitualmente:

```text
rax = [rsp]
rsp += 8
```

Visualmente:

```text
endereços maiores
┌─────────────┐
│             │
├─────────────┤
│ valor antigo│
├─────────────┤ ← RSP
│ topo        │
└─────────────┘
endereços menores
```

---

# 21. `call`, `ret` e chamadas de função

Considere:

```asm
call soma
```

`call` faz aproximadamente duas coisas:

1. salva o endereço de retorno na stack;
2. pula para `soma`.

Conceitualmente:

```text
push endereço_da_próxima_instrução
jmp soma
```

Depois:

```asm
ret
```

recupera esse endereço da stack e continua a execução.

Conceitualmente:

```text
pop RIP
```

Isso explica por que corromper a stack pode alterar o fluxo de execução de um programa.

---

# 22. System V AMD64 ABI

No Linux x86-64, programas normalmente seguem a **System V AMD64 ABI**.

Ela define como funções conversam entre si.

## 22.1 Argumentos inteiros e ponteiros

Os primeiros argumentos são passados em:

```text
1º  RDI
2º  RSI
3º  RDX
4º  RCX
5º  R8
6º  R9
```

Argumentos adicionais vão para a stack.

## 22.2 Valor de retorno

Normalmente:

```text
RAX
```

Exemplo C:

```c
long soma(long a, long b);
```

entrada:

```text
RDI = a
RSI = b
```

retorno:

```text
RAX
```

Então:

```asm
global soma

soma:
    mov rax, rdi
    add rax, rsi
    ret
```

## 22.3 Caller-saved

Registradores que a função chamada pode modificar:

```text
RAX
RCX
RDX
RSI
RDI
R8
R9
R10
R11
```

Se o chamador precisa preservar algum deles, é responsabilidade dele.

## 22.4 Callee-saved

A função chamada deve restaurar estes se modificá-los:

```text
RBX
RBP
R12
R13
R14
R15
```

## 22.5 Stack alignment

Antes de uma instrução `call`, a stack deve estar adequadamente alinhada, normalmente em 16 bytes segundo a ABI.

Como `call` empilha um endereço de retorno de 8 bytes, na entrada de uma função típica:

```text
RSP mod 16 = 8
```

Esse detalhe torna-se importante ao chamar código que usa SIMD ou funções da libc.

## 22.6 Red zone

A ABI System V AMD64 define uma região de 128 bytes abaixo de `rsp` chamada **red zone**.

Funções leaf podem usá-la temporariamente sem ajustar `rsp`.

Não confunda isso com uma regra universal de todas as plataformas.

---

# 23. Stack frames e variáveis locais

Um prólogo clássico:

```asm
push rbp
mov rbp, rsp
sub rsp, 32
```

Cria espaço para variáveis locais.

Por exemplo:

```text
[rbp - 8]
[rbp - 16]
[rbp - 24]
```

podem representar variáveis locais.

No final:

```asm
mov rsp, rbp
pop rbp
ret
```

ou:

```asm
leave
ret
```

`leave` equivale aproximadamente a:

```asm
mov rsp, rbp
pop rbp
```

Compiladores modernos frequentemente omitem `rbp` como frame pointer quando a otimização está ativada.

Assim, não pense que toda função precisa ter:

```asm
push rbp
mov rbp, rsp
```

Isso é uma convenção comum, não uma necessidade da CPU.

---

# 24. Syscalls no Linux

Uma syscall é uma chamada do programa em user space para o kernel.

Em Linux x86-64:

```text
RAX = número da syscall

RDI = arg1
RSI = arg2
RDX = arg3
R10 = arg4
R8  = arg5
R9  = arg6
```

Depois:

```asm
syscall
```

Observe que isso **não é igual à calling convention de funções comuns**.

O quarto argumento de uma função normal usa:

```text
RCX
```

mas o quarto argumento de syscall usa:

```text
R10
```

## 24.1 `write`

Número:

```text
1
```

Assinatura conceitual:

```c
write(fd, buffer, count)
```

Assembly:

```asm
mov rax, 1
mov rdi, 1
lea rsi, [rel msg]
mov rdx, len
syscall
```

## 24.2 `exit`

Número:

```text
60
```

```asm
mov rax, 60
xor rdi, rdi
syscall
```

---

# 25. C ↔ Assembly

Essa é uma das melhores formas de aprender.

## 25.1 Chamar Assembly a partir de C

Arquivo:

```text
soma.asm
```

```asm
global soma

section .text

soma:
    mov rax, rdi
    add rax, rsi
    ret
```

C:

```c
#include <stdio.h>

extern long soma(long a, long b);

int main(void) {
    printf("%ld\n", soma(10, 20));
    return 0;
}
```

Monte:

```bash
nasm -f elf64 soma.asm -o soma.o
```

Compile:

```bash
gcc main.c soma.o -o programa
```

Execute:

```bash
./programa
```

Saída:

```text
30
```

Aqui você está usando a ABI para fazer C e Assembly conversarem.

## 25.2 Chamar C a partir de Assembly

Um exemplo didático usando `printf`:

```asm
default rel

global main
extern printf

section .rodata
    fmt db "resultado = %ld", 10, 0

section .text

main:
    push rbp
    mov rbp, rsp

    mov rsi, 42
    lea rdi, [rel fmt]

    xor eax, eax
    call printf

    xor eax, eax

    pop rbp
    ret
```

Monte:

```bash
nasm -f elf64 main.asm -o main.o
```

Link com GCC:

```bash
gcc -no-pie main.o -o programa
```

`xor eax, eax` antes de uma função variádica como `printf` possui significado definido pela ABI: informa quantos registradores vetoriais foram usados para argumentos variádicos de ponto flutuante.

---

# 26. Assembly gerado pelo compilador

Crie:

```c
int quadrado(int x) {
    return x * x;
}
```

Peça Assembly ao GCC:

```bash
gcc -S -masm=intel quadrado.c -o quadrado.s
```

Sem otimização:

```bash
gcc -O0 -S -masm=intel quadrado.c -o quadrado_O0.s
```

Com otimização:

```bash
gcc -O2 -S -masm=intel quadrado.c -o quadrado_O2.s
```

Compare os arquivos.

Uma função extremamente simples pode virar algo semelhante a:

```asm
mov eax, edi
imul eax, edi
ret
```

A melhor pergunta ao estudar Assembly não é:

> "Como eu escreveria isso manualmente?"

mas também:

> "Por que o compilador escolheu essas instruções?"

---

# 27. Otimização e o que o compilador elimina

Considere:

```c
int f(void) {
    int x = 10;
    int y = 20;
    return x + y;
}
```

Sem otimização, você pode ver variáveis armazenadas na stack.

Com otimização, o compilador pode simplesmente retornar:

```asm
mov eax, 30
ret
```

As variáveis:

```text
x
y
```

deixaram de existir em runtime.

Isso ensina uma lição profunda:

> Variáveis de uma linguagem de alto nível são abstrações do programa-fonte, não necessariamente entidades físicas persistentes na máquina.

## 27.1 Constant folding

```c
return 10 * 20;
```

pode virar:

```asm
mov eax, 200
ret
```

## 27.2 Dead-code elimination

```c
int x = calcular_algo();
x = 10;
return x;
```

Se `calcular_algo()` não tiver efeitos observáveis, o compilador pode removê-lo.

## 27.3 Inlining

Uma função:

```c
int dobro(int x) {
    return x * 2;
}
```

pode desaparecer completamente como chamada.

Seu corpo é inserido diretamente no chamador.

## 27.4 Strength reduction

Uma multiplicação pode se transformar em shift ou `lea`, mas não assuma que isso sempre ocorre.

CPUs modernas possuem multiplicadores rápidos, e o compilador decide conforme o contexto.

---

# 28. Assembly e orientação a objetos

Assembly não conhece diretamente:

```text
classe
objeto
método
herança
encapsulamento
```

Essas são abstrações da linguagem.

Considere C++:

```cpp
class Contador {
public:
    int valor;

    void incrementar() {
        valor++;
    }
};
```

Uma chamada:

```cpp
c.incrementar();
```

pode ser entendida conceitualmente como:

```c
incrementar(&c);
```

O endereço do objeto é passado implicitamente como:

```text
this
```

No ABI x86-64, esse ponteiro geralmente acaba no primeiro registrador de argumento.

Em Linux System V:

```text
RDI = this
```

Uma implementação simplificada:

```asm
incrementar:
    add dword [rdi], 1
    ret
```

Isso é extremamente útil para desmistificar orientação a objetos.

## 28.1 Funções virtuais

Uma classe polimórfica frequentemente possui um ponteiro para uma tabela virtual:

```text
objeto
│
├── vptr ─────► vtable
│              ├── metodo1
│              ├── metodo2
│              └── metodo3
│
└── dados
```

Uma chamada virtual pode envolver:

1. carregar `vptr`;
2. acessar a entrada correta da vtable;
3. fazer uma chamada indireta.

Assembly mostra que "polimorfismo" acaba se transformando em ponteiros, offsets e chamadas indiretas.

---

# 29. ELF, assembler, linker e loader

No Linux, executáveis normalmente usam o formato:

```text
ELF
```

O pipeline:

```text
source
  ↓
assembler/compiler
  ↓
object file (.o)
  ↓
linker
  ↓
ELF executable
  ↓
loader do sistema operacional
  ↓
processo em execução
```

## 29.1 Sections

Em arquivos objeto você encontrará seções como:

```text
.text
.data
.rodata
.bss
```

### `.text`

Código executável.

### `.data`

Dados inicializados e mutáveis.

### `.rodata`

Dados somente leitura.

### `.bss`

Dados não inicializados ou inicializados em zero.

## 29.2 Symbols

Um símbolo é um nome associado a algo como:

```text
função
variável global
label
```

Por exemplo:

```asm
global soma
```

torna `soma` visível ao linker.

## 29.3 Relocations

Se um arquivo objeto referencia algo cujo endereço ainda não é conhecido:

```asm
call printf
```

o assembler pode criar uma **relocation**.

Depois o linker resolve essa referência.

## 29.4 Dynamic linking

Bibliotecas como:

```text
libc.so
```

podem ser carregadas dinamicamente.

Conceitos que aparecem nesse contexto:

```text
PLT
GOT
dynamic loader
shared objects
PIC
PIE
```

Você não precisa dominar isso no primeiro contato, mas deverá reconhecer os termos.

---

# 30. GDB: olhando a CPU trabalhar

Compile um programa com símbolos de debug:

```bash
gcc -g programa.c -o programa
```

Abra:

```bash
gdb ./programa
```

Configure sintaxe Intel:

```gdb
set disassembly-flavor intel
```

## Comandos essenciais

Breakpoint:

```gdb
break main
```

Executar:

```gdb
run
```

Desmontar:

```gdb
disassemble main
```

Ver registradores:

```gdb
info registers
```

Ver uma instrução:

```gdb
x/i $rip
```

Executar uma instrução:

```gdb
stepi
```

ou:

```gdb
si
```

Pular sobre uma instrução/chamada:

```gdb
nexti
```

Ver stack:

```gdb
x/16gx $rsp
```

Ver memória como bytes:

```gdb
x/32bx $rsp
```

Ver memória como string:

```gdb
x/s endereço
```

Ver valor hexadecimal:

```gdb
p/x $rax
```

## Experimento importante

Pare em `main`:

```gdb
break main
run
```

Depois:

```gdb
info registers
x/8gx $rsp
x/i $rip
```

Execute:

```gdb
stepi
```

e observe:

```text
RIP
RSP
RAX
RDI
RSI
```

mudando instrução por instrução.

Esse tipo de experiência ensina mais que memorizar dezenas de instruções.

---

# 31. Objdump, readelf e nm

## Disassembly

```bash
objdump -d -Mintel programa
```

## Símbolos

```bash
nm programa
```

Para C++:

```bash
nm -C programa
```

A opção `-C` faz demangling dos nomes C++.

## Header ELF

```bash
readelf -h programa
```

## Seções

```bash
readelf -S programa
```

## Símbolos

```bash
readelf -s programa
```

## Relocations

```bash
readelf -r objeto.o
```

## Program headers

```bash
readelf -l programa
```

Essas ferramentas mostram a transição entre código-fonte e executável real.

---

# 32. Machine code

Assembly ainda é texto para humanos.

Considere:

```asm
mov eax, 1
```

Ela pode ser codificada em bytes como:

```text
B8 01 00 00 00
```

A CPU recebe bytes, não a palavra `mov`.

Você pode observar bytes com:

```bash
objdump -d programa
```

Saída típica:

```text
b8 01 00 00 00    mov eax,0x1
```

O lado esquerdo:

```text
b8 01 00 00 00
```

é machine code.

O lado direito:

```text
mov eax,0x1
```

é disassembly.

## 32.1 Instruções de tamanho variável

x86 possui instruções de tamanho variável.

Uma instrução pode ocupar poucos bytes ou muitos bytes.

Isso torna o decoder x86 relativamente complexo em comparação com algumas arquiteturas RISC.

## 32.2 Opcode

Um opcode identifica uma operação.

Mas em x86 a codificação completa pode incluir:

```text
prefixes
opcode
ModR/M
SIB
displacement
immediate
```

Você não precisa decorar isso inicialmente.

O importante é saber que cada linha Assembly possui uma representação binária concreta.

---

# 33. Memória virtual

Quando seu programa acessa:

```text
0x7fffffffe000
```

esse valor normalmente não é um endereço físico de RAM.

É um **endereço virtual**.

O sistema operacional e a MMU traduzem:

```text
virtual address
      ↓
page tables
      ↓
physical address
```

Isso permite:

- isolamento entre processos;
- proteção de memória;
- paginação;
- compartilhamento controlado;
- memory mapping.

## 33.1 Stack e heap não são "tipos de RAM"

São regiões organizadas no espaço de endereçamento virtual do processo.

Um layout simplificado:

```text
endereços altos

┌────────────────────┐
│ stack              │
│ ↓                  │
├────────────────────┤
│                    │
│ mmap / libraries   │
│                    │
├────────────────────┤
│ ↑ heap             │
├────────────────────┤
│ .bss               │
├────────────────────┤
│ .data              │
├────────────────────┤
│ .rodata            │
├────────────────────┤
│ .text              │
└────────────────────┘

endereços baixos
```

ASLR pode fazer os endereços variarem entre execuções.

---

# 34. Floating point e SIMD

Em x86-64 moderno, números de ponto flutuante normalmente usam registradores:

```text
XMM0
XMM1
...
```

Historicamente existia a unidade:

```text
x87
```

mas SSE/SSE2 e extensões posteriores são mais comuns hoje.

## 34.1 Escalar

Exemplos:

```asm
addss xmm0, xmm1
```

soma floats de 32 bits.

```asm
addsd xmm0, xmm1
```

soma doubles de 64 bits.

## 34.2 SIMD

SIMD significa:

```text
Single Instruction, Multiple Data
```

Uma única instrução opera sobre vários elementos.

Por exemplo, conceitualmente:

```text
[1,2,3,4]
+
[5,6,7,8]
=
[6,8,10,12]
```

Registradores:

```text
XMM = 128 bits
YMM = 256 bits
ZMM = 512 bits
```

Famílias:

```text
SSE
SSE2
AVX
AVX2
AVX-512
```

Isso é particularmente importante em:

- álgebra linear;
- multimídia;
- machine learning;
- processamento científico;
- criptografia.

---

# 35. CPU moderna: além de fetch/decode/execute

O modelo introdutório é:

```text
fetch
 ↓
decode
 ↓
execute
```

Ele é útil, mas CPUs modernas fazem muito mais.

## 35.1 Pipeline

Várias instruções podem estar em fases diferentes simultaneamente.

Conceitualmente:

```text
I1: fetch decode execute retire
I2:       fetch decode execute retire
I3:             fetch decode execute retire
```

## 35.2 Out-of-order execution

A CPU pode executar instruções fora da ordem original quando dependências permitem.

Ela preserva o comportamento arquitetural esperado.

## 35.3 Branch prediction

Ao encontrar:

```asm
cmp ...
jne ...
```

a CPU pode tentar prever o caminho antes de saber o resultado.

Se acertar, ganha tempo.

Se errar, trabalho especulativo precisa ser descartado.

## 35.4 Register renaming

Registradores arquiteturais como:

```text
RAX
RBX
```

não correspondem necessariamente a um único registrador físico fixo internamente.

A CPU pode renomeá-los dinamicamente para permitir maior paralelismo.

## 35.5 Micro-ops

Uma instrução x86 complexa pode ser decodificada internamente em operações menores:

```text
x86 instruction
      ↓
micro-ops
      ↓
execution units
```

Portanto:

> Assembly descreve o comportamento arquitetural, não necessariamente cada operação física interna.

---

# 36. Concorrência e instruções atômicas

Com vários cores, memória compartilhada se torna mais complexa.

Uma operação como:

```c
contador++;
```

não é necessariamente atômica.

Ela pode virar:

```text
load
increment
store
```

Outra thread pode interferir entre essas etapas.

x86 possui mecanismos como:

```asm
lock add ...
lock xadd ...
cmpxchg ...
```

Também existem fences:

```text
mfence
lfence
sfence
```

Esses assuntos se conectam a:

- atomics de C/C++;
- mutexes;
- lock-free programming;
- cache coherence;
- memory ordering.

Não tente substituir as abstrações corretas de concorrência de C/C++ por Assembly manual sem compreender profundamente o memory model.

---

# 37. Ring 3, Ring 0 e instruções privilegiadas

Seu programa normal executa em user mode.

Em x86:

```text
Ring 3 → user space
Ring 0 → kernel
```

Algumas operações não podem ser executadas diretamente por um programa comum.

Exemplos conceituais:

- configurar certas estruturas da CPU;
- manipular diretamente certos mecanismos de memória;
- controlar hardware protegido.

Então o programa faz:

```asm
syscall
```

e o kernel realiza a operação privilegiada.

Essa separação é parte essencial da segurança do sistema operacional.

---

# 38. Intel vs AT&T

Você encontrará duas sintaxes muito comuns em x86.

## 38.1 Intel

```asm
mov rax, rbx
add rax, 10
mov rcx, [rax + 8]
```

Ordem:

```text
destino, origem
```

## 38.2 AT&T

```asm
movq %rbx, %rax
addq $10, %rax
movq 8(%rax), %rcx
```

Ordem:

```text
origem, destino
```

Diferenças típicas:

| Intel | AT&T |
|---|---|
| `rax` | `%rax` |
| `10` | `$10` |
| `[rax+8]` | `8(%rax)` |
| destino, origem | origem, destino |

GCC tradicionalmente usa AT&T:

```bash
gcc -S programa.c
```

Mas você pode pedir Intel:

```bash
gcc -S -masm=intel programa.c
```

Para começar, Intel costuma ser mais direta.

---

# 39. Erros mentais comuns

## 39.1 "Assembly é linguagem de máquina"

Não exatamente.

Assembly é uma representação textual das instruções.

Machine code são os bytes.

## 39.2 "Cada variável C vira um endereço de memória"

Não.

Ela pode:

- ficar em registrador;
- ficar na stack;
- ser incorporada como constante;
- ser eliminada completamente.

## 39.3 "Um registrador é uma variável"

Só como aproximação didática.

Registradores são recursos físicos/arquiteturais que o compilador reutiliza o tempo todo.

## 39.4 "`mov` sempre acessa memória"

Não.

```asm
mov rax, rbx
```

não acessa memória.

## 39.5 "`lea` lê memória"

Não.

```asm
lea rax, [rbx]
```

calcula um endereço.

## 39.6 "Stack é administrada magicamente pela CPU"

A CPU fornece `rsp`, `push`, `pop`, `call`, `ret`, mas o formato de stack frames e passagem de argumentos é em grande parte definido pela ABI e pelos compiladores.

## 39.7 "Assembly é sempre mais rápido que C"

Não.

Compiladores modernos são extremamente bons em otimização.

Assembly manual pode facilmente ficar pior que o código gerado por GCC ou Clang.

## 39.8 "Aprender todas as instruções é o objetivo"

Não.

O objetivo principal é aprender o **modelo da máquina**.

Você consulta instruções específicas quando precisar.

---

# 40. Roteiro de estudo recomendado

O melhor caminho é aprender Assembly junto de C.

## Fase 1 — Modelo da máquina

Domine:

```text
bits
bytes
hexadecimal
signed/unsigned
endianness
registradores
memória
endereços
```

Depois:

```text
mov
add
sub
and
or
xor
shifts
```

Meta:

> Conseguir acompanhar valores mudando em registradores e memória.

---

## Fase 2 — Controle de fluxo

Aprenda:

```text
RFLAGS
cmp
test

jmp
je
jne
jg
jge
jl
jle
ja
jae
jb
jbe
```

Traduza:

```text
if
else
while
for
```

para Assembly.

Meta:

> Entender que estruturas de controle são construídas a partir de comparações e saltos.

---

## Fase 3 — Stack e funções

Aprenda:

```text
rsp
rbp
push
pop
call
ret
```

Depois:

```text
System V AMD64 ABI
argument registers
caller-saved
callee-saved
stack alignment
```

Meta:

> Conseguir olhar uma função compilada e identificar argumentos, retorno e stack frame.

---

## Fase 4 — C ↔ Assembly

Escreva funções simples em C:

```text
soma
máximo
fatorial
soma de array
strlen
```

Compile:

```bash
gcc -O0 -S -masm=intel arquivo.c
```

Depois:

```bash
gcc -O2 -S -masm=intel arquivo.c
```

Compare.

Meta:

> Começar a prever aproximadamente o Assembly que o compilador produzirá.

---

## Fase 5 — Debugger

Use GDB.

Aprenda a observar:

```text
RIP
RSP
RAX
RDI
RSI
RDX
```

e memória.

Meta:

> Conseguir executar um programa instrução por instrução.

---

## Fase 6 — SO e executáveis

Aprenda:

```text
syscalls
ELF
sections
symbols
relocations
dynamic linking
virtual memory
```

Ferramentas:

```text
objdump
readelf
nm
gdb
```

Meta:

> Entender o caminho de um arquivo `.c` até um processo Linux em execução.

---

## Fase 7 — CPU moderna

Apenas depois da base:

```text
cache
pipeline
branch prediction
out-of-order execution
SIMD
memory ordering
```

Meta:

> Entender a diferença entre a ISA aparente e a CPU física que executa o programa.

---

# 41. Mini projetos

Não é necessário fazer todos de uma vez.

## Projeto 1 — Hello sem libc

Objetivo:

```text
Assembly → syscall → kernel
```

Imprima uma mensagem usando somente:

```asm
write
exit
```

---

## Projeto 2 — Funções matemáticas

Implemente em Assembly funções chamadas por C:

```c
long soma(long a, long b);
long max(long a, long b);
long abs_long(long x);
```

---

## Projeto 3 — Soma de array

Assinatura:

```c
long sum_array(const long *a, unsigned long n);
```

Possível implementação:

```asm
global sum_array

section .text

sum_array:
    xor rax, rax
    xor rcx, rcx

.loop:
    cmp rcx, rsi
    jae .done

    add rax, [rdi + rcx*8]
    inc rcx
    jmp .loop

.done:
    ret
```

Observe a relação:

```text
rdi = ponteiro
rsi = tamanho
rcx = índice
rax = acumulador
```

---

## Projeto 4 — `strlen`

Entrada:

```text
RDI = ponteiro para string
```

Saída:

```text
RAX = tamanho
```

Uma versão simples:

```asm
global my_strlen

section .text

my_strlen:
    xor rax, rax

.loop:
    cmp byte [rdi + rax], 0
    je .done

    inc rax
    jmp .loop

.done:
    ret
```

---

## Projeto 5 — Descobrir o que o compilador fez

Pegue funções C/C++ pequenas e use:

```bash
gcc -O0 -S -masm=intel
gcc -O1 -S -masm=intel
gcc -O2 -S -masm=intel
gcc -O3 -S -masm=intel
```

Compare:

- stack usage;
- inlining;
- loops;
- vetorização;
- eliminação de código.

---

## Projeto 6 — Caminhar pelo programa com GDB

Compile:

```bash
gcc -g -O0 programa.c -o programa
```

No GDB:

```gdb
set disassembly-flavor intel
break main
run
disassemble main
info registers
x/16gx $rsp
stepi
```

Tente narrar em linguagem humana o que cada instrução faz.

---

## Projeto 7 — Mini CPU

Depois de compreender bem Assembly, construa uma CPU mínima em simulador, HDL ou software.

Uma ISA imaginária:

```text
LOAD R1, 10
LOAD R2, 20
ADD  R1, R2
STORE R1, 0x100
HALT
```

Componentes:

```text
Program Counter
Instruction Register
Register File
ALU
RAM
Control Unit
```

Esse projeto fecha a lacuna:

```text
"Como a CPU entende Assembly?"
```

porque você implementa o mecanismo que interpreta as instruções.

---

# 42. Cheat sheet

## Registradores gerais

```text
RAX RBX RCX RDX
RSI RDI RBP RSP
R8  R9  R10 R11
R12 R13 R14 R15
```

## Argumentos de função — System V AMD64

```text
1 → RDI
2 → RSI
3 → RDX
4 → RCX
5 → R8
6 → R9
```

Retorno:

```text
RAX
```

## Syscalls Linux x86-64

```text
número → RAX

arg1 → RDI
arg2 → RSI
arg3 → RDX
arg4 → R10
arg5 → R8
arg6 → R9
```

## Movimento

```asm
mov dst, src
lea dst, [address]
```

## Aritmética

```asm
add
sub
inc
dec
neg
imul
div
idiv
```

## Bitwise

```asm
and
or
xor
not
shl
shr
sar
```

## Comparação

```asm
cmp
test
```

## Saltos

```text
jmp

je  jne

jl  jle
jg  jge

jb  jbe
ja  jae
```

## Stack

```asm
push
pop
call
ret
```

## Flags importantes

```text
ZF → zero
CF → carry
SF → sign
OF → signed overflow
```

## GDB

```gdb
set disassembly-flavor intel
break main
run
disassemble main
info registers
x/i $rip
x/16gx $rsp
stepi
nexti
```

## Ferramentas

```bash
gcc
nasm
ld
gdb
objdump
readelf
nm
```

---

# 43. Glossário

### ABI

Application Binary Interface.

Define como componentes binários conversam: calling convention, layout de dados, registradores preservados etc.

### Assembler

Programa que transforma Assembly em machine code/arquivo objeto.

### Assembly

Representação textual das instruções de uma ISA.

### Calling convention

Regras para argumentos, retorno, registradores e stack em chamadas de função.

### Callee

Função que está sendo chamada.

### Caller

Função que chama outra.

### Endianness

Ordem dos bytes usados para representar valores multibyte em memória.

### ELF

Formato comum de executáveis e arquivos objeto no Linux.

### Flag

Bit de estado modificado por operações da CPU e usado por instruções condicionais.

### ISA

Instruction Set Architecture.

Contrato de instruções visível ao software.

### Linker

Combina arquivos objeto e resolve símbolos.

### Loader

Carrega um executável no espaço de endereçamento de um processo.

### Machine code

Bytes executáveis pela CPU segundo uma ISA.

### Microarquitetura

Implementação física/interna de uma ISA por uma família ou geração de CPUs.

### Opcode

Parte da codificação de uma instrução que identifica a operação.

### Register

Armazenamento muito rápido exposto pela ISA.

### Relocation

Informação usada para corrigir referências cujo endereço ainda não era conhecido no momento da montagem/compilação.

### Stack

Região de memória usada segundo determinadas convenções para chamadas, dados temporários e variáveis locais.

### Stack frame

Área da stack associada a uma invocação de função.

### Syscall

Mecanismo usado por um programa em user space para solicitar serviços ao kernel.

### Virtual address

Endereço visto pelo processo, traduzido pela MMU e pelo sistema operacional para memória física.

---

# 44. Conclusão

Aprender Assembly não significa abandonar linguagens de alto nível.

O objetivo é conseguir **subir e descer as camadas de abstração**.

Quando você vê:

```python
resultado = a + b
```

deve saber que existe uma enorme infraestrutura por baixo.

Quando vê:

```c
int resultado = a + b;
```

deve começar a imaginar registradores e instruções.

Quando vê:

```asm
mov eax, edi
add eax, esi
```

deve conseguir imaginar:

```text
registradores
flags
instruction pointer
pipeline
```

E quando observa os bytes:

```text
89 F8
01 F0
```

deve reconhecer que chegou à fronteira da ISA.

O mapa mental final é:

```text
algoritmo
   ↓
linguagem de alto nível
   ↓
runtime / compilador
   ↓
Assembly
   ↓
machine code
   ↓
ISA
   ↓
microarquitetura
   ↓
circuitos digitais
   ↓
transistores
```

O valor de Assembly está menos em escrever grandes aplicações manualmente e mais em remover a sensação de magia das camadas inferiores do computador.

A partir daí, temas que antes parecem separados começam a se conectar:

```text
C / C++
compiladores
sistemas operacionais
debugging
segurança
performance
redes
arquitetura de computadores
machine learning de alto desempenho
```

Tudo converge para a mesma máquina.

---

## Regra de ouro

Ao estudar Assembly, não tente decorar a arquitetura inteira.

Para cada trecho, faça quatro perguntas:

1. **Que valores existem nos registradores?**
2. **Que endereços de memória estão sendo acessados?**
3. **Qual instrução mudará o fluxo de execução?**
4. **Qual abstração de C/C++ isso está implementando?**

Se você consegue responder essas quatro perguntas, está realmente aprendendo Assembly.
