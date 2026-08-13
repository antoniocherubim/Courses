# Masterclass de C++ e Programação Orientada a Objetos

> Guia de estudo, consulta e prática — do básico da linguagem ao C++ moderno e à Programação Orientada a Objetos.

[← Python](../01-python/) · [↑ Índice](../README.md) · [Próxima → C](../03-c/)

---

## Sumário

1. [Como pensar em C++](#1-como-pensar-em-c)
2. [Estrutura mínima de um programa](#2-estrutura-mínima-de-um-programa)
3. [Variáveis, tipos e escopo](#3-variáveis-tipos-e-escopo)
4. [Entrada, saída e operadores](#4-entrada-saída-e-operadores)
5. [Condicionais](#5-condicionais)
6. [Laços de repetição](#6-laços-de-repetição)
7. [Funções](#7-funções)
8. [Arrays, `std::array` e `std::vector`](#8-arrays-stdarray-e-stdvector)
9. [Referências e ponteiros](#9-referências-e-ponteiros)
10. [Memória automática e dinâmica](#10-memória-automática-e-dinâmica)
11. [Introdução à Programação Orientada a Objetos](#11-introdução-à-programação-orientada-a-objetos)
12. [Classes e objetos](#12-classes-e-objetos)
13. [Encapsulamento](#13-encapsulamento)
14. [Construtores e destrutores](#14-construtores-e-destrutores)
15. [`this`, `const` e métodos](#15-this-const-e-métodos)
16. [Composição](#16-composição)
17. [Herança](#17-herança)
18. [Polimorfismo](#18-polimorfismo)
19. [Classes abstratas e interfaces](#19-classes-abstratas-e-interfaces)
20. [Sobrecarga de funções e operadores](#20-sobrecarga-de-funções-e-operadores)
21. [Templates](#21-templates)
22. [STL](#22-stl)
23. [Iteradores e algoritmos](#23-iteradores-e-algoritmos)
24. [Exceções](#24-exceções)
25. [RAII e gerenciamento seguro de recursos](#25-raii-e-gerenciamento-seguro-de-recursos)
26. [Smart pointers](#26-smart-pointers)
27. [Cópia e movimento](#27-cópia-e-movimento)
28. [Princípios de design em POO](#28-princípios-de-design-em-poo)
29. [Erros comuns em C++](#29-erros-comuns-em-c)
30. [Projeto exemplo completo](#30-projeto-exemplo-completo)
31. [Exercícios progressivos](#31-exercícios-progressivos)
32. [Roadmap de estudo](#32-roadmap-de-estudo)
33. [Cheat sheet](#33-cheat-sheet)

---

# 1. Como pensar em C++

C++ é uma linguagem que combina diferentes paradigmas:

- programação procedural;
- programação orientada a objetos;
- programação genérica;
- programação funcional;
- programação de baixo nível;
- programação de alto desempenho.

Isso significa que C++ não obriga você a resolver tudo com classes.

Uma boa regra é:

> Use a ferramenta mais simples que represente corretamente o problema.

C++ também oferece muito controle sobre:

- memória;
- tempo de vida dos objetos;
- cópias;
- referências;
- recursos;
- desempenho.

Esse controle é poderoso, mas exige disciplina.

---

# 2. Estrutura mínima de um programa

```cpp
#include <iostream>

using namespace std;

int main() {
    cout << "Hello, world!" << endl;

    return 0;
}
```

## `#include`

Inclui declarações de bibliotecas.

```cpp
#include <iostream>
```

permite usar:

```cpp
cout
cin
endl
```

Outros exemplos:

```cpp
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
```

---

## `main`

Todo programa C++ executável começa por:

```cpp
int main() {
}
```

O retorno:

```cpp
return 0;
```

indica que o programa terminou normalmente.

---

# 3. Variáveis, tipos e escopo

## Tipos básicos

```cpp
int idade = 20;
double altura = 1.75;
float temperatura = 25.5f;
char letra = 'A';
bool ativo = true;
```

Strings:

```cpp
#include <string>

string nome = "Antonio";
```

---

## Declaração

```cpp
int x;
```

## Inicialização

```cpp
int x = 10;
```

Preferencialmente:

```cpp
int x{10};
```

A inicialização com `{}` ajuda a evitar certas conversões perigosas.

---

## Escopo

```cpp
int global = 10;

int main() {
    int local = 20;

    if (true) {
        int interna = 30;
    }
}
```

`global` pode ser acessada amplamente.

`local` existe apenas dentro de `main`.

`interna` existe apenas dentro do bloco do `if`.

Regra prática:

> Declare uma variável no menor escopo possível.

---

# 4. Entrada, saída e operadores

## Saída

```cpp
cout << "Valor: " << x << endl;
```

## Entrada

```cpp
cin >> x;
```

Exemplo:

```cpp
int idade;

cout << "Digite sua idade: ";
cin >> idade;
```

---

## Operadores aritméticos

```cpp
a + b
a - b
a * b
a / b
a % b
```

Atenção:

```cpp
5 / 2
```

com dois `int` resulta em:

```text
2
```

Enquanto:

```cpp
5.0 / 2
```

resulta em:

```text
2.5
```

---

## Operadores relacionais

```cpp
==
!=
>
<
>=
<=
```

---

## Operadores lógicos

```cpp
&&   // e
||   // ou
!    // não
```

Exemplo:

```cpp
if (idade >= 18 && idade < 60) {
    cout << "Adulto";
}
```

---

# 5. Condicionais

## `if`

```cpp
if (x > 0) {
    cout << "Positivo";
}
```

## `if / else`

```cpp
if (x >= 0) {
    cout << "Nao negativo";
}
else {
    cout << "Negativo";
}
```

## `else if`

```cpp
if (nota >= 90) {
    cout << "A";
}
else if (nota >= 80) {
    cout << "B";
}
else if (nota >= 70) {
    cout << "C";
}
else {
    cout << "Reprovado";
}
```

---

## `switch`

Útil quando queremos comparar uma variável com valores discretos.

```cpp
switch (opcao) {
    case 1:
        cout << "Cadastrar";
        break;

    case 2:
        cout << "Listar";
        break;

    default:
        cout << "Opcao invalida";
}
```

---

# 6. Laços de repetição

## `while`

```cpp
int i = 0;

while (i < 5) {
    cout << i << endl;
    i++;
}
```

---

## `do...while`

Executa o bloco pelo menos uma vez.

```cpp
int numero;

do {
    cout << "Digite um numero positivo: ";
    cin >> numero;
} while (numero <= 0);
```

Muito útil para validação de entrada.

---

## `for`

```cpp
for (int i = 0; i < 5; i++) {
    cout << i << endl;
}
```

O `for` acima é equivalente a:

```cpp
int i = 0;

while (i < 5) {
    cout << i << endl;
    i++;
}
```

---

# 7. Funções

Funções dividem o programa em partes menores.

```cpp
int soma(int a, int b) {
    return a + b;
}
```

Uso:

```cpp
int resultado = soma(10, 20);
```

---

## Função `void`

Não retorna valor:

```cpp
void mensagem() {
    cout << "Ola!" << endl;
}
```

---

## Passagem por valor

```cpp
void dobrar(int x) {
    x *= 2;
}
```

Isso não altera a variável original.

```cpp
int n = 5;
dobrar(n);

cout << n;
```

continua imprimindo:

```text
5
```

---

## Passagem por referência

```cpp
void dobrar(int& x) {
    x *= 2;
}
```

Agora:

```cpp
int n = 5;
dobrar(n);

cout << n;
```

imprime:

```text
10
```

---

## Referência constante

Quando queremos evitar cópia sem permitir modificação:

```cpp
void mostrar(const string& texto) {
    cout << texto << endl;
}
```

Esse padrão aparece constantemente em C++ moderno.

---

# 8. Arrays, `std::array` e `std::vector`

## Array tradicional

```cpp
int numeros[5];
```

Posições:

```text
0 1 2 3 4
```

Exemplo:

```cpp
int numeros[5] = {10, 20, 30, 40, 50};

cout << numeros[0];
```

---

## Percorrendo

```cpp
for (int i = 0; i < 5; i++) {
    cout << numeros[i] << endl;
}
```

---

## `std::array`

```cpp
#include <array>

array<int, 5> numeros = {1, 2, 3, 4, 5};
```

É normalmente mais conveniente e seguro que arrays C tradicionais.

---

## `std::vector`

```cpp
#include <vector>

vector<int> numeros;
```

Adicionar:

```cpp
numeros.push_back(10);
numeros.push_back(20);
```

Acessar:

```cpp
cout << numeros[0];
```

Tamanho:

```cpp
cout << numeros.size();
```

Percorrer:

```cpp
for (int numero : numeros) {
    cout << numero << endl;
}
```

---

# 9. Referências e ponteiros

Este é um dos assuntos mais importantes de C++.

## Referência

```cpp
int x = 10;

int& referencia = x;

referencia = 20;
```

Agora:

```cpp
cout << x;
```

imprime:

```text
20
```

A referência funciona como outro nome para a mesma variável.

---

## Ponteiro

```cpp
int x = 10;

int* ponteiro = &x;
```

`&x` significa:

> endereço de `x`.

`ponteiro` armazena esse endereço.

---

## Desreferenciamento

```cpp
cout << *ponteiro;
```

`*ponteiro` significa:

> valor armazenado no endereço apontado.

Podemos alterar:

```cpp
*ponteiro = 50;
```

Agora:

```cpp
x == 50
```

---

## Visualização mental

```text
x
+------+
|  10  |
+------+
0x1000


ponteiro
+--------+
| 0x1000 |
+--------+
```

Então:

```cpp
*ponteiro
```

segue o endereço e acessa o valor.

---

## `nullptr`

Ponteiro que não aponta para objeto algum:

```cpp
int* p = nullptr;
```

Prefira:

```cpp
nullptr
```

a:

```cpp
NULL
```

---

# 10. Memória automática e dinâmica

## Memória automática

```cpp
void funcao() {
    int x = 10;
}
```

`x` é destruído automaticamente ao sair da função.

---

## Memória dinâmica

Forma antiga:

```cpp
int* p = new int(10);

delete p;
```

Array dinâmico:

```cpp
int* numeros = new int[10];

delete[] numeros;
```

Hoje, normalmente evitamos `new` e `delete` diretamente.

Preferimos:

- `std::vector`;
- `std::string`;
- `std::unique_ptr`;
- `std::shared_ptr`.

---

# 11. Introdução à Programação Orientada a Objetos

Programação Orientada a Objetos organiza programas em entidades que combinam:

- estado;
- comportamento.

Exemplo conceitual:

```text
ContaBancaria
|
+-- saldo
+-- titular
|
+-- depositar()
+-- sacar()
+-- consultarSaldo()
```

O objeto contém dados e operações relacionadas a esses dados.

---

## Classe vs objeto

Classe:

> modelo ou definição.

Objeto:

> instância concreta da classe.

Exemplo:

```cpp
class Pessoa {
};
```

Essa é a classe.

```cpp
Pessoa p1;
Pessoa p2;
```

`p1` e `p2` são objetos.

---

# 12. Classes e objetos

```cpp
#include <iostream>
#include <string>

using namespace std;

class Pessoa {
public:
    string nome;
    int idade;

    void apresentar() {
        cout << "Meu nome e " << nome
             << " e tenho " << idade
             << " anos." << endl;
    }
};

int main() {
    Pessoa pessoa;

    pessoa.nome = "Ana";
    pessoa.idade = 25;

    pessoa.apresentar();

    return 0;
}
```

---

## Estado

```cpp
string nome;
int idade;
```

representa dados do objeto.

---

## Comportamento

```cpp
void apresentar()
```

representa uma ação que o objeto pode realizar.

---

# 13. Encapsulamento

Uma classe normalmente não deve permitir acesso irrestrito aos seus dados internos.

Exemplo ruim:

```cpp
class Conta {
public:
    double saldo;
};
```

Qualquer código pode fazer:

```cpp
conta.saldo = -1000000;
```

Melhor:

```cpp
class Conta {
private:
    double saldo;

public:
    void depositar(double valor) {
        if (valor > 0) {
            saldo += valor;
        }
    }

    double getSaldo() const {
        return saldo;
    }
};
```

Agora a classe controla suas próprias regras.

---

## Modificadores de acesso

### `public`

Pode ser acessado externamente.

### `private`

Só pode ser acessado pela própria classe.

### `protected`

Pode ser acessado pela classe e classes derivadas.

---

# 14. Construtores e destrutores

Construtor inicializa o objeto.

```cpp
class Pessoa {
private:
    string nome;
    int idade;

public:
    Pessoa(string nomeInicial, int idadeInicial) {
        nome = nomeInicial;
        idade = idadeInicial;
    }
};
```

Uso:

```cpp
Pessoa pessoa("Ana", 25);
```

---

## Lista de inicialização

Forma preferida:

```cpp
Pessoa(string nomeInicial, int idadeInicial)
    : nome(nomeInicial),
      idade(idadeInicial) {
}
```

---

## Construtor padrão

```cpp
Pessoa() {
    nome = "Desconhecido";
    idade = 0;
}
```

---

## Destrutor

```cpp
~Pessoa() {
    cout << "Objeto destruido" << endl;
}
```

É executado automaticamente quando o objeto deixa de existir.

Destrutores são fundamentais para RAII.

---

# 15. `this`, `const` e métodos

## `this`

Dentro de um método, `this` aponta para o próprio objeto.

```cpp
class Pessoa {
private:
    string nome;

public:
    Pessoa(string nome) {
        this->nome = nome;
    }
};
```

Aqui existem dois `nome`:

```text
nome        parâmetro
this->nome  atributo
```

---

## Métodos `const`

```cpp
double getSaldo() const {
    return saldo;
}
```

O `const` significa que o método promete não alterar o estado do objeto.

---

## Objeto constante

```cpp
const Pessoa pessoa("Ana", 25);
```

Só pode chamar métodos marcados como `const`.

---

# 16. Composição

Composição significa:

> um objeto contém outro objeto.

Exemplo:

```cpp
class Motor {
public:
    void ligar() {
        cout << "Motor ligado" << endl;
    }
};

class Carro {
private:
    Motor motor;

public:
    void ligar() {
        motor.ligar();
    }
};
```

Um `Carro` **tem um** `Motor`.

Isso é uma relação:

```text
HAS-A
```

Composição costuma ser preferível à herança quando a relação natural é "tem um".

---

# 17. Herança

Herança representa uma relação:

```text
IS-A
```

Exemplo:

```cpp
class Animal {
public:
    void respirar() {
        cout << "Respirando" << endl;
    }
};

class Cachorro : public Animal {
public:
    void latir() {
        cout << "Au au!" << endl;
    }
};
```

Agora:

```cpp
Cachorro cachorro;

cachorro.respirar();
cachorro.latir();
```

`Cachorro` herda características de `Animal`.

---

## Construtores em herança

```cpp
class Animal {
protected:
    string nome;

public:
    Animal(string nome)
        : nome(nome) {
    }
};

class Cachorro : public Animal {
public:
    Cachorro(string nome)
        : Animal(nome) {
    }
};
```

---

# 18. Polimorfismo

Polimorfismo significa:

> tratar objetos diferentes por uma interface comum.

Exemplo:

```cpp
class Animal {
public:
    virtual void emitirSom() {
        cout << "Som generico" << endl;
    }
};
```

Classes derivadas:

```cpp
class Cachorro : public Animal {
public:
    void emitirSom() override {
        cout << "Au au!" << endl;
    }
};

class Gato : public Animal {
public:
    void emitirSom() override {
        cout << "Miau!" << endl;
    }
};
```

Uso:

```cpp
Animal* animal = new Cachorro();

animal->emitirSom();
```

Saída:

```text
Au au!
```

Isso acontece por causa de:

```cpp
virtual
```

---

## `override`

```cpp
void emitirSom() override
```

indica explicitamente que o método sobrescreve um método virtual da classe base.

Isso permite ao compilador detectar erros.

---

## Destrutor virtual

Classes usadas polimorficamente devem normalmente ter destrutor virtual:

```cpp
virtual ~Animal() = default;
```

---

# 19. Classes abstratas e interfaces

Uma função virtual pura:

```cpp
virtual void executar() = 0;
```

torna a classe abstrata.

Exemplo:

```cpp
class Forma {
public:
    virtual double area() const = 0;

    virtual ~Forma() = default;
};
```

Não podemos fazer:

```cpp
Forma forma;
```

Mas podemos criar subclasses:

```cpp
class Retangulo : public Forma {
private:
    double largura;
    double altura;

public:
    Retangulo(double largura, double altura)
        : largura(largura),
          altura(altura) {
    }

    double area() const override {
        return largura * altura;
    }
};
```

---

# 20. Sobrecarga de funções e operadores

## Sobrecarga de função

```cpp
int soma(int a, int b) {
    return a + b;
}

double soma(double a, double b) {
    return a + b;
}
```

O compilador escolhe a versão adequada.

---

## Sobrecarga de operador

```cpp
class Vetor2D {
public:
    double x;
    double y;

    Vetor2D(double x, double y)
        : x(x), y(y) {
    }

    Vetor2D operator+(const Vetor2D& outro) const {
        return Vetor2D(
            x + outro.x,
            y + outro.y
        );
    }
};
```

Uso:

```cpp
Vetor2D a(1, 2);
Vetor2D b(3, 4);

Vetor2D c = a + b;
```

---

# 21. Templates

Templates permitem programação genérica.

```cpp
template<typename T>
T maior(T a, T b) {
    return a > b ? a : b;
}
```

Uso:

```cpp
cout << maior(10, 20);
cout << maior(2.5, 1.3);
```

---

## Template de classe

```cpp
template<typename T>
class Caixa {
private:
    T valor;

public:
    Caixa(T valor)
        : valor(valor) {
    }

    T getValor() const {
        return valor;
    }
};
```

Uso:

```cpp
Caixa<int> a(10);
Caixa<string> b("Hello");
```

---

# 22. STL

STL significa:

> Standard Template Library.

Ela fornece estruturas e algoritmos prontos.

Algumas estruturas importantes:

```text
vector
array
deque
list
map
unordered_map
set
unordered_set
stack
queue
```

---

## `vector`

```cpp
vector<int> numeros = {5, 2, 8, 1};
```

---

## `map`

Relaciona chave e valor.

```cpp
#include <map>

map<string, int> idades;

idades["Ana"] = 25;
idades["Carlos"] = 30;
```

---

## `unordered_map`

Sem ordenação por chave, normalmente com acesso médio O(1).

```cpp
#include <unordered_map>
```

---

## `set`

Mantém valores únicos:

```cpp
set<int> numeros;

numeros.insert(10);
numeros.insert(10);
numeros.insert(20);
```

O `10` aparece apenas uma vez.

---

# 23. Iteradores e algoritmos

## `std::sort`

```cpp
#include <algorithm>

vector<int> numeros = {5, 2, 8, 1};

sort(numeros.begin(), numeros.end());
```

Resultado:

```text
1 2 5 8
```

Decrescente:

```cpp
sort(
    numeros.begin(),
    numeros.end(),
    greater<int>()
);
```

---

## Range-based `for`

```cpp
for (int numero : numeros) {
    cout << numero << endl;
}
```

Por referência:

```cpp
for (int& numero : numeros) {
    numero *= 2;
}
```

Sem cópia:

```cpp
for (const int& numero : numeros) {
    cout << numero << endl;
}
```

---

## Lambda

```cpp
sort(
    numeros.begin(),
    numeros.end(),
    [](int a, int b) {
        return a > b;
    }
);
```

A lambda:

```cpp
[](int a, int b) {
    return a > b;
}
```

é uma função anônima.

---

# 24. Exceções

Exceções representam erros excepcionais.

```cpp
try {
    if (idade < 0) {
        throw invalid_argument("Idade invalida");
    }
}
catch (const exception& erro) {
    cout << erro.what() << endl;
}
```

---

## Não use exceção para fluxo normal

Evite:

```cpp
throw
```

para coisas que podem ser tratadas naturalmente com:

```cpp
if
```

Exceções são mais adequadas a condições realmente excepcionais.

---

# 25. RAII e gerenciamento seguro de recursos

RAII significa:

> Resource Acquisition Is Initialization.

É uma das ideias centrais de C++.

A ideia:

> o tempo de vida de um recurso deve estar ligado ao tempo de vida de um objeto.

Exemplo com arquivo:

```cpp
#include <fstream>

void escrever() {
    ofstream arquivo("dados.txt");

    arquivo << "Hello";
}
```

Quando `arquivo` sai de escopo, seu destrutor fecha o arquivo automaticamente.

Não precisamos fazer gerenciamento manual.

---

## Recursos podem ser

- memória;
- arquivo;
- conexão de rede;
- mutex;
- socket;
- handle do sistema operacional.

RAII torna o código muito mais seguro.

---

# 26. Smart pointers

## `unique_ptr`

Representa propriedade exclusiva.

```cpp
#include <memory>

unique_ptr<int> numero = make_unique<int>(10);
```

Não precisamos:

```cpp
delete numero;
```

A memória é liberada automaticamente.

---

## Exemplo com objetos

```cpp
unique_ptr<Animal> animal =
    make_unique<Cachorro>();
```

---

## `shared_ptr`

Permite propriedade compartilhada.

```cpp
shared_ptr<int> valor =
    make_shared<int>(10);
```

Internamente mantém contador de referências.

---

## `weak_ptr`

Observa um objeto gerenciado por `shared_ptr` sem possuir o objeto.

Ajuda a evitar ciclos de referência.

---

## Regra prática

Prefira:

```text
objeto normal
↓
unique_ptr
↓
shared_ptr
```

Nessa ordem.

Não use `shared_ptr` automaticamente para tudo.

---

# 27. Cópia e movimento

C++ distingue entre copiar e mover objetos.

## Cópia

```cpp
string a = "hello";
string b = a;
```

Agora existem duas strings independentes.

---

## Movimento

```cpp
string a = "uma string muito grande";

string b = std::move(a);
```

Em vez de copiar todo o conteúdo, os recursos internos podem ser transferidos.

---

## Construtor de cópia

```cpp
Classe(const Classe& outro);
```

---

## Operador de atribuição por cópia

```cpp
Classe& operator=(const Classe& outro);
```

---

## Construtor de movimento

```cpp
Classe(Classe&& outro);
```

---

## Operador de atribuição por movimento

```cpp
Classe& operator=(Classe&& outro);
```

---

## Regra dos 0

No C++ moderno, a melhor situação geralmente é não precisar implementar manualmente:

- destrutor;
- cópia;
- movimento.

Use tipos que já gerenciam recursos corretamente:

```cpp
string
vector
unique_ptr
```

---

# 28. Princípios de design em POO

## Encapsulamento

Proteja invariantes internos.

```cpp
class Conta {
private:
    double saldo;
};
```

---

## Coesão

Uma classe deve ter uma responsabilidade bem definida.

Ruim:

```text
Usuario
├── autentica
├── envia email
├── calcula imposto
├── acessa banco
└── gera PDF
```

Isso concentra responsabilidades demais.

---

## Acoplamento

Quanto mais classes dependem diretamente umas das outras, mais difícil fica modificar o sistema.

Prefira interfaces claras.

---

## Composição sobre herança

Antes de escrever:

```cpp
class A : public B
```

pergunte:

> A realmente É UM B?

Se a relação for:

> A TEM UM B

use composição.

---

## SOLID

### S — Single Responsibility Principle

Uma classe deve ter uma razão principal para mudar.

### O — Open/Closed Principle

Aberta para extensão, fechada para modificação.

### L — Liskov Substitution Principle

Uma classe derivada deve poder substituir sua classe base sem quebrar o comportamento esperado.

### I — Interface Segregation Principle

Prefira interfaces pequenas e específicas.

### D — Dependency Inversion Principle

Dependa de abstrações, não de implementações concretas.

---

# 29. Erros comuns em C++

## 1. Variável não inicializada

Ruim:

```cpp
int x;

cout << x;
```

Prefira:

```cpp
int x = 0;
```

---

## 2. Confundir `=` com `==`

```cpp
if (x = 10)
```

faz atribuição.

O correto para comparação:

```cpp
if (x == 10)
```

---

## 3. Acessar array fora dos limites

```cpp
int numeros[5];

numeros[5] = 10;
```

É inválido.

As posições são:

```text
0 1 2 3 4
```

---

## 4. Ponteiro nulo

```cpp
int* p = nullptr;

cout << *p;
```

Isso é comportamento indefinido.

---

## 5. `new` sem `delete`

```cpp
int* p = new int(10);
```

sem:

```cpp
delete p;
```

causa vazamento de memória.

No C++ moderno, prefira evitar `new` diretamente.

---

## 6. Object slicing

```cpp
Animal animal = Cachorro();
```

A parte específica de `Cachorro` pode ser perdida.

Para polimorfismo, use referência ou ponteiro:

```cpp
Animal& animal
```

ou:

```cpp
Animal* animal
```

---

## 7. Esquecer destrutor virtual

Se uma classe base será usada polimorficamente:

```cpp
class Animal {
public:
    virtual ~Animal() = default;
};
```

---

# 30. Projeto exemplo completo

Vamos montar um pequeno sistema orientado a objetos.

## Objetivo

Gerenciar uma biblioteca com diferentes tipos de itens.

---

## Classe base

```cpp
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class ItemBiblioteca {
protected:
    string titulo;

public:
    ItemBiblioteca(const string& titulo)
        : titulo(titulo) {
    }

    virtual void exibir() const = 0;

    virtual ~ItemBiblioteca() = default;
};
```

---

## Livro

```cpp
class Livro : public ItemBiblioteca {
private:
    string autor;

public:
    Livro(
        const string& titulo,
        const string& autor
    )
        : ItemBiblioteca(titulo),
          autor(autor) {
    }

    void exibir() const override {
        cout << "Livro: "
             << titulo
             << " - "
             << autor
             << endl;
    }
};
```

---

## Revista

```cpp
class Revista : public ItemBiblioteca {
private:
    int edicao;

public:
    Revista(
        const string& titulo,
        int edicao
    )
        : ItemBiblioteca(titulo),
          edicao(edicao) {
    }

    void exibir() const override {
        cout << "Revista: "
             << titulo
             << " - edicao "
             << edicao
             << endl;
    }
};
```

---

## Biblioteca

```cpp
class Biblioteca {
private:
    vector<unique_ptr<ItemBiblioteca>> itens;

public:
    void adicionar(
        unique_ptr<ItemBiblioteca> item
    ) {
        itens.push_back(move(item));
    }

    void listar() const {
        for (const auto& item : itens) {
            item->exibir();
        }
    }
};
```

---

## `main`

```cpp
int main() {
    Biblioteca biblioteca;

    biblioteca.adicionar(
        make_unique<Livro>(
            "Effective Modern C++",
            "Scott Meyers"
        )
    );

    biblioteca.adicionar(
        make_unique<Revista>(
            "C++ Monthly",
            42
        )
    );

    biblioteca.listar();

    return 0;
}
```

Aqui temos:

- encapsulamento;
- herança;
- polimorfismo;
- classe abstrata;
- composição;
- `vector`;
- `unique_ptr`;
- RAII;
- `override`;
- métodos `const`.

---

# 31. Exercícios progressivos

## Nível 1 — fundamentos

### Exercício 1

Leia 5 números e mostre:

- maior;
- menor;
- média.

---

### Exercício 2

Leia números positivos até o usuário digitar `0`.

Mostre:

- quantidade;
- soma;
- média.

---

### Exercício 3

Crie um programa que simule um jogo de adivinhação.

---

## Nível 2 — arrays e funções

### Exercício 4

Leia 10 números em um array e imprima em ordem inversa.

---

### Exercício 5

Escreva uma função:

```cpp
int maior(int a, int b);
```

---

### Exercício 6

Escreva:

```cpp
void ordenar(int& a, int& b);
```

que garanta:

```text
a >= b
```

---

## Nível 3 — classes

### Exercício 7 — Pessoa

Crie:

```cpp
class Pessoa
```

com:

```text
nome
idade
```

e um método:

```cpp
apresentar()
```

---

### Exercício 8 — Conta bancária

Implemente:

```cpp
class ContaBancaria
```

com:

```text
titular
saldo
```

Métodos:

```text
depositar
sacar
consultarSaldo
```

Não permita saldo negativo.

---

### Exercício 9 — Produto

Crie:

```cpp
class Produto
```

com:

```text
nome
preco
quantidade
```

Método:

```cpp
double valorEstoque() const;
```

---

## Nível 4 — composição

### Exercício 10 — Carro e Motor

```text
Carro TEM UM Motor
```

Implemente:

```cpp
class Motor
class Carro
```

---

### Exercício 11 — Pedido

```text
Pedido
├── Cliente
└── Produtos
```

Use composição.

---

## Nível 5 — herança

### Exercício 12

Crie:

```text
Animal
├── Cachorro
└── Gato
```

Cada animal deve implementar:

```cpp
emitirSom()
```

---

### Exercício 13

Crie:

```text
Funcionario
├── Desenvolvedor
├── Designer
└── Gerente
```

Implemente:

```cpp
calcularSalario()
```

polimorficamente.

---

## Nível 6 — C++ moderno

### Exercício 14

Substitua arrays tradicionais por:

```cpp
vector
```

---

### Exercício 15

Crie objetos dinamicamente usando:

```cpp
unique_ptr
```

---

### Exercício 16

Use:

```cpp
sort
```

com uma lambda para ordenar objetos.

---

# 32. Roadmap de estudo

Uma sequência recomendada:

## Etapa 1

Dominar:

```text
variáveis
if
while
do while
for
funções
```

---

## Etapa 2

Aprender profundamente:

```text
arrays
vector
string
referências
```

---

## Etapa 3

Entender memória:

```text
endereços
ponteiros
stack
heap
tempo de vida
```

---

## Etapa 4

Entrar em POO:

```text
classes
objetos
private
public
construtores
métodos
```

---

## Etapa 5

Modelagem:

```text
encapsulamento
composição
responsabilidades
invariantes
```

---

## Etapa 6

Polimorfismo:

```text
herança
virtual
override
classe abstrata
```

---

## Etapa 7

C++ moderno:

```text
vector
algoritmos
lambda
RAII
unique_ptr
move
```

---

## Etapa 8

Arquitetura e design:

```text
SOLID
interfaces
baixo acoplamento
alta coesão
design orientado a domínio
```

---

# 33. Cheat sheet

## Entrada

```cpp
cin >> x;
```

## Saída

```cpp
cout << x << endl;
```

## Condicional

```cpp
if (condicao) {

}
else {

}
```

## `while`

```cpp
while (condicao) {

}
```

## `do...while`

```cpp
do {

} while (condicao);
```

## `for`

```cpp
for (int i = 0; i < n; i++) {

}
```

## Função

```cpp
int soma(int a, int b) {
    return a + b;
}
```

## Referência

```cpp
int& ref = x;
```

## Ponteiro

```cpp
int* p = &x;
```

## Classe

```cpp
class MinhaClasse {
private:
    int valor;

public:
    MinhaClasse(int valor)
        : valor(valor) {
    }

    int getValor() const {
        return valor;
    }
};
```

## Herança

```cpp
class Filho : public Pai {

};
```

## Método virtual

```cpp
virtual void executar();
```

## Sobrescrita

```cpp
void executar() override;
```

## Função virtual pura

```cpp
virtual void executar() = 0;
```

## Vetor

```cpp
vector<int> numeros;
```

## Adicionar

```cpp
numeros.push_back(10);
```

## Percorrer

```cpp
for (const auto& numero : numeros) {

}
```

## Ordenar

```cpp
sort(numeros.begin(), numeros.end());
```

## Smart pointer

```cpp
auto objeto = make_unique<Classe>();
```

---

# Conclusão

Aprender C++ bem não significa decorar sintaxe.

O objetivo é construir uma compreensão progressiva de:

```text
dados
    ↓
estado
    ↓
funções
    ↓
objetos
    ↓
relações entre objetos
    ↓
tempo de vida
    ↓
recursos
    ↓
abstrações
    ↓
arquitetura
```

A Programação Orientada a Objetos começa com classes, mas não termina nelas.

O ponto mais importante é aprender a modelar sistemas em termos de:

- responsabilidades;
- invariantes;
- interfaces;
- dependências;
- tempo de vida;
- propriedade dos recursos.

Em C++ isso fica especialmente evidente porque a linguagem não esconde completamente memória, cópia e destruição dos objetos.

Quanto melhor você entende esses mecanismos, mais natural se torna projetar software robusto.

---

## Próximos tópicos para aprofundamento

Depois deste material, vale estudar separadamente:

- compilação e linking;
- headers `.h` / `.hpp`;
- separação entre `.hpp` e `.cpp`;
- namespaces;
- `constexpr`;
- `enum class`;
- `auto`;
- structured bindings;
- conceitos de C++20;
- ranges;
- concorrência;
- mutex;
- threads;
- atomics;
- profiling;
- templates avançados;
- metaprogramação;
- design patterns;
- arquitetura de software;
- testes unitários;
- CMake.

---

> **Regra de ouro em C++ moderno:** faça o compilador e os tipos trabalharem a seu favor. Prefira construir abstrações que tornem estados inválidos difíceis ou impossíveis de representar.

---

[← Python](../01-python/) · [↑ Índice](../README.md) · [Próxima → C](../03-c/)
