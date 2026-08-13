# Python Class — Caderno de Referência

> Um guia de consulta de **Python moderno** para quem já possui base na linguagem.
>
> Foco principal: Python 3.12–3.14, com observações quando um recurso depende de uma versão recente.
>
> Atualizado para **Python 3.14.6** (série 3.14).

[↑ Track A](../README.md) · [↑ Courses](../../../README.md) · [Próxima → A02 C++ e POO](../A02-cpp-poo/)

---

## Sumário

1. [Filosofia e modelo mental](#1-filosofia-e-modelo-mental)
2. [Execução, nomes, objetos e identidade](#2-execução-nomes-objetos-e-identidade)
3. [Tipos fundamentais](#3-tipos-fundamentais)
4. [Expressões e operadores](#4-expressões-e-operadores)
5. [Controle de fluxo](#5-controle-de-fluxo)
6. [Funções](#6-funções)
7. [Escopos, closures e decorators](#7-escopos-closures-e-decorators)
8. [Coleções e comprehensions](#8-coleções-e-comprehensions)
9. [Iteradores e geradores](#9-iteradores-e-geradores)
10. [Exceções e gerenciamento de recursos](#10-exceções-e-gerenciamento-de-recursos)
11. [Módulos, pacotes e imports](#11-módulos-pacotes-e-imports)
12. [Programação orientada a objetos](#12-programação-orientada-a-objetos)
13. [Modelo de dados do Python](#13-modelo-de-dados-do-python)
14. [Herança, composição, ABCs e Protocols](#14-herança-composição-abcs-e-protocols)
15. [Descriptors, properties e controle de atributos](#15-descriptors-properties-e-controle-de-atributos)
16. [Dataclasses e modelos de dados](#16-dataclasses-e-modelos-de-dados)
17. [Typing moderno](#17-typing-moderno)
18. [Pattern matching](#18-pattern-matching)
19. [Programação funcional](#19-programação-funcional)
20. [Strings, bytes e Unicode](#20-strings-bytes-e-unicode)
21. [Arquivos, caminhos e serialização](#21-arquivos-caminhos-e-serialização)
22. [Datas, horários e fusos](#22-datas-horários-e-fusos)
23. [Regex](#23-regex)
24. [Concorrência, paralelismo e asyncio](#24-concorrência-paralelismo-e-asyncio)
25. [Subprocessos e interação com o sistema](#25-subprocessos-e-interação-com-o-sistema)
26. [Introspecção, metaprogramação e metaclasses](#26-introspecção-metaprogramação-e-metaclasses)
27. [Memória, garbage collector e cópias](#27-memória-garbage-collector-e-cópias)
28. [Performance e profiling](#28-performance-e-profiling)
29. [Testes](#29-testes)
30. [Logging](#30-logging)
31. [Packaging, ambientes e projetos](#31-packaging-ambientes-e-projetos)
32. [Qualidade de código e estilo](#32-qualidade-de-código-e-estilo)
33. [Segurança e armadilhas comuns](#33-segurança-e-armadilhas-comuns)
34. [Recursos modernos do Python 3.12–3.14](#34-recursos-modernos-do-python-312314)
35. [Idiomas Pythonic](#35-idiomas-pythonic)
36. [Padrões arquiteturais úteis em Python](#36-padrões-arquiteturais-úteis-em-python)
37. [Biblioteca padrão — mapa mental](#37-biblioteca-padrão--mapa-mental)
38. [Checklist de revisão](#38-checklist-de-revisão)
39. [Referências oficiais](#39-referências-oficiais)

---

# 1. Filosofia e modelo mental

Python é uma linguagem:

- de alto nível;
- multiparadigma;
- dinamicamente tipada;
- fortemente tipada;
- com gerenciamento automático de memória;
- orientada a objetos em seu modelo de dados;
- com funções de primeira classe;
- com suporte forte a programação funcional, procedural e assíncrona.

O ponto mais importante para entender Python profundamente é:

> **Variáveis não são caixas que contêm valores. Nomes referenciam objetos.**

```python
x = [1, 2, 3]
y = x

y.append(4)

print(x)  # [1, 2, 3, 4]
```

`x` e `y` são dois nomes apontando para o mesmo objeto.

## 1.1 Tudo é objeto

Em Python, praticamente tudo é objeto:

```python
42
"hello"
len
print
int
object
MinhaClasse
```

Funções podem ser armazenadas, passadas e retornadas:

```python
def dobro(x):
    return x * 2

f = dobro
print(f(10))
```

Classes também são objetos:

```python
class User:
    pass

print(type(User))  # <class 'type'>
```

## 1.2 EAFP em vez de LBYL

Python frequentemente prefere **EAFP**:

> Easier to Ask Forgiveness than Permission.

Em vez de:

```python
if key in mapping:
    value = mapping[key]
```

muitas vezes:

```python
try:
    value = mapping[key]
except KeyError:
    value = None
```

Isso não significa usar exceções indiscriminadamente. Significa que operações normais podem ser tentadas diretamente quando a falha é uma possibilidade natural da interface.

## 1.3 Duck typing

> Se o objeto se comporta como o necessário, seu tipo nominal pode ser irrelevante.

```python
def tamanho(obj):
    return len(obj)
```

Funciona com strings, listas, tuplas, sets, objetos customizados que implementem `__len__`, etc.

---

# 2. Execução, nomes, objetos e identidade

## 2.1 Binding de nomes

```python
x = 10
```

Atribuição faz um **binding** do nome `x` ao objeto inteiro `10`.

```python
x = 10
x = "dez"
```

O nome muda de referência. O nome em si não possui um tipo fixo.

## 2.2 Identidade versus igualdade

```python
x == y
```

Compara valores, via `__eq__`.

```python
x is y
```

Compara identidade: se são exatamente o mesmo objeto.

Use `is` principalmente para singletons:

```python
if value is None:
    ...
```

Evite:

```python
if value == None:
    ...
```

## 2.3 `id()`

```python
x = []
y = x

print(id(x) == id(y))  # True
```

`id()` identifica um objeto durante sua vida no processo.

Não trate o valor numérico de `id()` como API estável.

## 2.4 Mutabilidade

Objetos mutáveis comuns:

- `list`
- `dict`
- `set`
- `bytearray`
- instâncias de classes normalmente

Imutáveis comuns:

- `int`
- `float`
- `bool`
- `complex`
- `str`
- `bytes`
- `tuple`
- `frozenset`

A imutabilidade é do objeto, não do nome.

```python
x = 10
x += 1
```

O inteiro `10` não foi modificado. `x` passou a referenciar outro objeto.

## 2.5 Alias

```python
a = [1, 2]
b = a
```

`a` e `b` são aliases.

```python
b += [3]
print(a)  # [1, 2, 3]
```

Para listas, `+=` normalmente modifica in-place via `__iadd__`.

Compare com tuplas:

```python
a = (1, 2)
b = a
b += (3,)

print(a)  # (1, 2)
print(b)  # (1, 2, 3)
```

---

# 3. Tipos fundamentais

## 3.1 Números inteiros

Python possui inteiros de precisão arbitrária:

```python
x = 10**100
```

Bases:

```python
binario = 0b1010
hexadecimal = 0xFF
octal = 0o755
```

Separadores:

```python
population = 8_000_000_000
```

## 3.2 Float

`float` normalmente usa IEEE 754 double precision.

```python
0.1 + 0.2 == 0.3  # False
```

Para comparação numérica aproximada:

```python
from math import isclose

isclose(0.1 + 0.2, 0.3)
```

Para dinheiro, considere `decimal.Decimal`.

```python
from decimal import Decimal

price = Decimal("19.90")
```

Crie `Decimal` a partir de strings quando precisão decimal importar.

## 3.3 Complexos

```python
z = 3 + 4j

z.real
z.imag
abs(z)
```

## 3.4 Booleanos

`bool` é subclasse de `int`:

```python
isinstance(True, int)  # True
True + True            # 2
```

Mas semanticamente use booleanos como booleanos.

## 3.5 Truthiness

Valores falsy comuns:

```python
False
None
0
0.0
0j
""
[]
{}
set()
()
```

```python
if collection:
    ...
```

é preferível a:

```python
if len(collection) > 0:
    ...
```

## 3.6 Strings

```python
name = "Alice"
message = f"Hello, {name}!"
```

Strings são imutáveis e sequências Unicode.

Métodos úteis:

```python
text.strip()
text.lower()
text.upper()
text.casefold()
text.startswith("abc")
text.endswith("xyz")
text.replace("a", "b")
text.split(",")
" ".join(parts)
```

`casefold()` é mais agressivo que `lower()` para comparações Unicode independentes de caixa.

## 3.7 `None`

`None` representa ausência de valor.

```python
result = None
```

É singleton:

```python
result is None
```

## 3.8 `Ellipsis`

```python
...
```

é o objeto `Ellipsis`.

Aparece em:

- stubs;
- slicing multidimensional;
- APIs customizadas;
- placeholders.

---

# 4. Expressões e operadores

## 4.1 Operadores aritméticos

```python
+  -  *  /  //  %  **
```

```python
7 / 2   # 3.5
7 // 2  # 3
7 % 2   # 1
2 ** 10 # 1024
```

## 4.2 Divmod

```python
q, r = divmod(17, 5)
```

Equivale conceitualmente a quociente e resto.

## 4.3 Comparações encadeadas

```python
0 <= x < 10
```

melhor que:

```python
0 <= x and x < 10
```

## 4.4 Operadores booleanos

```python
and
or
not
```

`and` e `or` retornam operandos, não necessariamente `bool`.

```python
name = supplied_name or "anonymous"
```

## 4.5 Curto-circuito

```python
obj is not None and obj.run()
```

A segunda expressão só é avaliada se a primeira for truthy.

## 4.6 Operador walrus `:=`

```python
while chunk := file.read(8192):
    process(chunk)
```

Também útil para evitar computações repetidas:

```python
if (n := len(items)) > 10:
    print(f"Too many items: {n}")
```

Use com parcimônia; não sacrifique legibilidade.

## 4.7 Operadores bitwise

```python
& | ^ ~ << >>
```

Também são reutilizados por alguns tipos e bibliotecas para DSLs.

## 4.8 Precedência

Quando houver qualquer chance de ambiguidade humana, prefira parênteses.

```python
result = (a + b) * c
```

---

# 5. Controle de fluxo

## 5.1 `if`

```python
if score >= 90:
    grade = "A"
elif score >= 80:
    grade = "B"
else:
    grade = "C"
```

Expressão condicional:

```python
status = "adult" if age >= 18 else "minor"
```

## 5.2 `for`

Python itera sobre iteráveis, não apenas índices.

```python
for item in items:
    process(item)
```

Quando precisa de índice:

```python
for index, item in enumerate(items):
    ...
```

## 5.3 `zip`

```python
for name, score in zip(names, scores):
    ...
```

Python moderno permite validar comprimentos:

```python
for name, score in zip(names, scores, strict=True):
    ...
```

`strict=True` lança `ValueError` se os iteráveis terminarem em momentos diferentes.

## 5.4 `while`

```python
while condition:
    ...
```

## 5.5 `break`, `continue`, `pass`

```python
for item in items:
    if should_skip(item):
        continue
    if should_stop(item):
        break
```

`pass` é instrução vazia.

## 5.6 `for ... else`

O bloco `else` roda se o loop terminar **sem `break`**.

```python
for user in users:
    if user.id == target:
        found = user
        break
else:
    found = None
```

É útil para busca sem flag auxiliar.

## 5.7 Unpacking

```python
x, y = point
```

Extended unpacking:

```python
first, *middle, last = values
```

Swap:

```python
a, b = b, a
```

---

# 6. Funções

## 6.1 Definição

```python
def add(a, b):
    return a + b
```

Sem `return`, a função retorna `None`.

## 6.2 Argumentos posicionais e nomeados

```python
def connect(host, port=5432):
    ...

connect("localhost", 5432)
connect(host="localhost", port=5432)
```

## 6.3 Parâmetros somente posicionais `/`

```python
def ratio(x, y, /):
    return x / y
```

```python
ratio(10, 2)
```

mas não:

```python
ratio(x=10, y=2)
```

Útil quando nomes dos parâmetros não fazem parte da API pública.

## 6.4 Parâmetros somente nomeados `*`

```python
def request(url, *, timeout=10, retries=3):
    ...
```

```python
request(url, timeout=5)
```

Isso melhora clareza e torna APIs mais estáveis.

## 6.5 Assinatura completa

```python
def func(pos_only, /, positional_or_keyword, *, keyword_only):
    ...
```

## 6.6 `*args` e `**kwargs`

```python
def f(*args, **kwargs):
    print(args)
    print(kwargs)
```

- `args`: tupla;
- `kwargs`: dict.

## 6.7 Unpacking em chamadas

```python
args = (1, 2)
kwargs = {"debug": True}

func(*args, **kwargs)
```

## 6.8 Argumentos default são avaliados uma vez

Armadilha clássica:

```python
def append_item(item, items=[]):
    items.append(item)
    return items
```

O mesmo objeto `items` é reutilizado.

Prefira:

```python
def append_item(item, items=None):
    if items is None:
        items = []
    items.append(item)
    return items
```

Ou, com dataclasses, `default_factory`.

## 6.9 Retorno múltiplo

```python
def stats(values):
    return min(values), max(values)

minimum, maximum = stats(values)
```

Tecnicamente retorna uma tupla.

## 6.10 Funções são objetos

```python
def greet(name):
    return f"Hello {name}"

handlers = {
    "greet": greet,
}

handlers["greet"]("Alice")
```

## 6.11 Lambda

```python
key = lambda user: user.age
```

Útil para expressões pequenas, especialmente argumentos como `key=`.

Para lógica significativa, prefira `def`.

## 6.12 Docstrings

```python
def normalize(value: float) -> float:
    """Normalize a value to the expected range."""
    ...
```

A docstring fica disponível em:

```python
normalize.__doc__
```

---

# 7. Escopos, closures e decorators

## 7.1 Regra LEGB

Busca de nomes:

1. Local
2. Enclosing
3. Global
4. Builtins

```python
x = "global"

def outer():
    x = "enclosing"

    def inner():
        x = "local"
        print(x)
```

## 7.2 `global`

```python
counter = 0

def increment():
    global counter
    counter += 1
```

Use com cautela; estado global dificulta testes e raciocínio.

## 7.3 `nonlocal`

```python
def make_counter():
    count = 0

    def increment():
        nonlocal count
        count += 1
        return count

    return increment
```

## 7.4 Closures

Uma closure preserva referências ao ambiente léxico:

```python
def multiplier(factor):
    def multiply(value):
        return value * factor
    return multiply

triple = multiplier(3)
print(triple(10))
```

## 7.5 Late binding em closures

Armadilha:

```python
functions = [lambda: i for i in range(3)]

[f() for f in functions]  # [2, 2, 2]
```

A closure captura o nome `i`, não seu valor naquele instante.

Uma solução:

```python
functions = [lambda i=i: i for i in range(3)]
```

## 7.6 Decorators

Um decorator recebe um objeto e retorna outro.

```python
def log_calls(func):
    def wrapper(*args, **kwargs):
        print(f"calling {func.__name__}")
        return func(*args, **kwargs)
    return wrapper

@log_calls
def add(a, b):
    return a + b
```

Equivale a:

```python
def add(a, b):
    return a + b

add = log_calls(add)
```

## 7.7 Preserve metadata com `functools.wraps`

```python
from functools import wraps

def log_calls(func):
    @wraps(func)
    def wrapper(*args, **kwargs):
        return func(*args, **kwargs)
    return wrapper
```

## 7.8 Decorator com argumentos

```python
from functools import wraps


def retry(times):
    def decorator(func):
        @wraps(func)
        def wrapper(*args, **kwargs):
            last_error = None
            for _ in range(times):
                try:
                    return func(*args, **kwargs)
                except Exception as exc:
                    last_error = exc
            raise last_error
        return wrapper
    return decorator
```

## 7.9 Decorators de classe

```python
def register(cls):
    REGISTRY[cls.__name__] = cls
    return cls
```

---

# 8. Coleções e comprehensions

## 8.1 Listas

```python
items = [1, 2, 3]
```

Operações frequentes:

```python
items.append(x)
items.extend(iterable)
items.insert(i, x)
items.pop()
items.remove(x)
items.sort()
items.reverse()
```

Slicing:

```python
items[start:stop:step]
items[::-1]
```

Cópia superficial:

```python
copy = items[:]
copy = items.copy()
```

## 8.2 Tuplas

```python
point = (10, 20)
```

Uma tupla de um elemento exige vírgula:

```python
single = (42,)
```

## 8.3 Dicts

```python
user = {
    "name": "Alice",
    "age": 30,
}
```

Acesso:

```python
user["name"]
user.get("name")
user.get("country", "Brazil")
```

Iteração:

```python
for key in user:
    ...

for key, value in user.items():
    ...
```

Merge:

```python
merged = defaults | overrides
```

Atualização in-place:

```python
defaults |= overrides
```

`dict` preserva ordem de inserção como garantia da linguagem.

## 8.4 Sets

```python
values = {1, 2, 3}
```

Set vazio:

```python
values = set()
```

Operações:

```python
a | b  # união
a & b  # interseção
a - b  # diferença
a ^ b  # diferença simétrica
```

## 8.5 `frozenset`

Set imutável e hashable quando seus elementos também são hashable.

```python
permissions = frozenset({"read", "write"})
```

## 8.6 Comprehensions

Lista:

```python
squares = [x * x for x in range(10)]
```

Com filtro:

```python
evens = [x for x in values if x % 2 == 0]
```

Set:

```python
unique_lengths = {len(word) for word in words}
```

Dict:

```python
index = {user.id: user for user in users}
```

Generator expression:

```python
total = sum(x * x for x in values)
```

## 8.7 Comprehensions aninhadas

```python
pairs = [(x, y) for x in xs for y in ys]
```

Se ficar difícil de ler, use loops explícitos.

## 8.8 `collections`

### `Counter`

```python
from collections import Counter

counts = Counter("banana")
counts.most_common(2)
```

### `defaultdict`

```python
from collections import defaultdict

groups = defaultdict(list)
for item in items:
    groups[item.category].append(item)
```

### `deque`

```python
from collections import deque

queue = deque()
queue.append(item)
queue.popleft()
```

`deque` é ideal para operações eficientes nas duas extremidades.

### `namedtuple`

Ainda útil em APIs simples, embora `dataclass` seja frequentemente mais expressiva.

---

# 9. Iteradores e geradores

## 9.1 Iterável versus iterador

Iterável: objeto que pode produzir um iterador.

Iterador: objeto que produz itens via `__next__()` até lançar `StopIteration`.

```python
items = [1, 2, 3]
iterator = iter(items)

next(iterator)
next(iterator)
```

## 9.2 Protocolo

Um iterador implementa:

```python
__iter__()
__next__()
```

Exemplo:

```python
class Countdown:
    def __init__(self, start):
        self.current = start

    def __iter__(self):
        return self

    def __next__(self):
        if self.current <= 0:
            raise StopIteration
        value = self.current
        self.current -= 1
        return value
```

## 9.3 Geradores

```python
def countdown(start):
    while start > 0:
        yield start
        start -= 1
```

`yield` transforma a função em generator function.

O estado local é suspenso entre yields.

## 9.4 Lazy evaluation

Geradores calculam valores sob demanda.

```python
def read_large_file(path):
    with open(path) as file:
        for line in file:
            yield line.rstrip("\n")
```

Permite trabalhar com fluxos maiores que a memória.

## 9.5 `yield from`

```python
def flatten(groups):
    for group in groups:
        yield from group
```

Também delega parte do protocolo de generators.

## 9.6 Métodos de generator

Generators suportam:

```python
gen.send(value)
gen.throw(exc)
gen.close()
```

Na prática moderna, coroutines com `async`/`await` substituíram muitos usos antigos de generators como coroutines.

## 9.7 `itertools`

Ferramentas importantes:

```python
from itertools import (
    chain,
    count,
    cycle,
    repeat,
    islice,
    product,
    permutations,
    combinations,
    groupby,
    pairwise,
)
```

### `chain`

```python
for x in chain(a, b, c):
    ...
```

### `islice`

```python
first_100 = islice(stream, 100)
```

### `pairwise`

```python
for left, right in pairwise(values):
    ...
```

### `product`

```python
for x, y in product(xs, ys):
    ...
```

---

# 10. Exceções e gerenciamento de recursos

## 10.1 Estrutura básica

```python
try:
    result = operation()
except ValueError as exc:
    handle(exc)
else:
    use(result)
finally:
    cleanup()
```

- `except`: roda em erro compatível;
- `else`: roda se não houve exceção;
- `finally`: roda sempre.

## 10.2 Capture exceções específicas

Prefira:

```python
except FileNotFoundError:
    ...
```

Evite:

```python
except Exception:
    pass
```

Silenciar erros amplos geralmente esconde bugs.

## 10.3 `raise`

```python
raise ValueError("invalid age")
```

Re-raise:

```python
except ValueError:
    log.exception("invalid input")
    raise
```

## 10.4 Exception chaining

```python
try:
    parse(raw)
except ValueError as exc:
    raise ConfigurationError("invalid configuration") from exc
```

Use `from exc` para preservar causalidade explícita.

Para suprimir contexto:

```python
raise PublicError("invalid") from None
```

## 10.5 Exceções customizadas

```python
class DomainError(Exception):
    pass

class UserNotFound(DomainError):
    pass
```

Crie hierarquias quando consumidores precisam reagir a categorias de erro.

## 10.6 Exception groups

Python moderno suporta grupos de exceções:

```python
try:
    ...
except* ValueError as group:
    ...
```

Relacionados a `ExceptionGroup`, especialmente úteis em concorrência estruturada.

## 10.7 Context managers

```python
with open("data.txt") as file:
    data = file.read()
```

O protocolo usa:

```python
__enter__
__exit__
```

## 10.8 Criando context manager com classe

```python
class Transaction:
    def __enter__(self):
        self.begin()
        return self

    def __exit__(self, exc_type, exc, tb):
        if exc is None:
            self.commit()
        else:
            self.rollback()
```

## 10.9 `contextlib.contextmanager`

```python
from contextlib import contextmanager

@contextmanager
def transaction(db):
    db.begin()
    try:
        yield db
    except Exception:
        db.rollback()
        raise
    else:
        db.commit()
```

## 10.10 `ExitStack`

Útil quando a quantidade de context managers é dinâmica.

```python
from contextlib import ExitStack

with ExitStack() as stack:
    files = [stack.enter_context(open(path)) for path in paths]
    ...
```

---

# 11. Módulos, pacotes e imports

## 11.1 Módulo

Um arquivo `.py` normalmente é um módulo.

```text
project/
└── math_utils.py
```

```python
import math_utils
```

## 11.2 Formas de import

```python
import math
from math import sqrt
import numpy as np
```

Evite:

```python
from module import *
```

## 11.3 Pacote

Estrutura típica:

```text
app/
├── pyproject.toml
└── src/
    └── myapp/
        ├── __init__.py
        ├── api.py
        └── services/
            ├── __init__.py
            └── users.py
```

## 11.4 Imports absolutos

```python
from myapp.services.users import UserService
```

## 11.5 Imports relativos

```python
from .users import UserService
from ..config import settings
```

Úteis internamente, mas imports absolutos costumam ser mais explícitos em arquiteturas grandes.

## 11.6 `__name__`

Ao executar diretamente:

```python
__name__ == "__main__"
```

Padrão:

```python
def main():
    ...

if __name__ == "__main__":
    main()
```

## 11.7 Import cache

Módulos importados são armazenados em:

```python
sys.modules
```

Normalmente o corpo de um módulo é executado uma vez por processo/import context.

## 11.8 Circular imports

Sintoma comum de módulos excessivamente acoplados.

Soluções possíveis:

- reorganizar responsabilidades;
- extrair tipos compartilhados;
- importar localmente quando apropriado;
- usar `TYPE_CHECKING` para imports apenas de typing.

```python
from typing import TYPE_CHECKING

if TYPE_CHECKING:
    from myapp.models import User
```

## 11.9 `importlib`

Import dinâmico:

```python
from importlib import import_module

module = import_module("myapp.plugins.foo")
```

Útil em sistemas de plugins.

---

# 12. Programação orientada a objetos

## 12.1 Classes e instâncias

```python
class User:
    def __init__(self, name: str):
        self.name = name

    def greet(self) -> str:
        return f"Hello, {self.name}"
```

```python
user = User("Alice")
user.greet()
```

## 12.2 `self`

`self` é a instância passada explicitamente ao método.

```python
user.greet()
```

é conceitualmente próximo de:

```python
User.greet(user)
```

## 12.3 Atributos de instância versus classe

```python
class User:
    species = "Homo sapiens"

    def __init__(self, name):
        self.name = name
```

`species` pertence ao namespace da classe.

`name` normalmente pertence à instância.

Cuidado com mutáveis como atributos de classe:

```python
class Bad:
    items = []
```

Todas as instâncias compartilham `items`.

## 12.4 Métodos de instância

```python
class Account:
    def deposit(self, amount):
        self.balance += amount
```

## 12.5 `@classmethod`

Recebe a classe como primeiro argumento.

```python
class User:
    def __init__(self, name):
        self.name = name

    @classmethod
    def from_email(cls, email):
        name = email.split("@", 1)[0]
        return cls(name)
```

Muito útil para alternative constructors.

## 12.6 `@staticmethod`

Não recebe automaticamente instância nem classe.

```python
class Geometry:
    @staticmethod
    def distance(a, b):
        ...
```

Use quando a função pertence conceitualmente ao namespace da classe, mas não depende do estado dela.

Não use `staticmethod` apenas para evitar criar módulo auxiliar.

## 12.7 Encapsulamento em Python

Python não possui `private` rígido como C++/Java.

Convenções:

```python
_name       # interno / não público
__name      # name mangling
```

Name mangling:

```python
class Example:
    def __init__(self):
        self.__secret = 42
```

Internamente se torna aproximadamente:

```python
_Example__secret
```

Isso evita colisões acidentais em subclasses; não é segurança.

## 12.8 `property`

```python
class Circle:
    def __init__(self, radius):
        self._radius = radius

    @property
    def radius(self):
        return self._radius

    @radius.setter
    def radius(self, value):
        if value < 0:
            raise ValueError("radius must be non-negative")
        self._radius = value
```

Uma vantagem de Python é poder começar com atributo simples e depois evoluir para property mantendo a interface de acesso.

## 12.9 Composição

```python
class Engine:
    def start(self):
        ...

class Car:
    def __init__(self, engine: Engine):
        self.engine = engine
```

Frequentemente prefira composição a hierarquias profundas.

## 12.10 Injeção de dependência simples

Python normalmente não precisa de frameworks pesados de DI.

```python
class UserService:
    def __init__(self, repository, mailer):
        self.repository = repository
        self.mailer = mailer
```

Dependências são passadas diretamente.

---

# 13. Modelo de dados do Python

O **data model** é uma das partes mais importantes da linguagem.

A sintaxe Python é conectada a métodos especiais, os chamados *dunder methods*.

## 13.1 Construção

```python
__new__
__init__
```

`__new__` cria a instância.

`__init__` inicializa uma instância já criada.

```python
class Example:
    def __new__(cls, *args, **kwargs):
        instance = super().__new__(cls)
        return instance

    def __init__(self, value):
        self.value = value
```

Normalmente você só implementa `__init__`.

## 13.2 Representação

```python
__repr__
__str__
```

```python
class User:
    def __init__(self, name):
        self.name = name

    def __repr__(self):
        return f"User(name={self.name!r})"

    def __str__(self):
        return self.name
```

Regra útil:

- `repr`: representação para desenvolvedores/debug;
- `str`: representação para usuários.

## 13.3 Verdade

```python
__bool__
```

Se ausente, Python pode usar `__len__`.

## 13.4 Tamanho

```python
__len__
```

## 13.5 Containers

```python
__getitem__
__setitem__
__delitem__
__contains__
```

```python
obj[key]
obj[key] = value
del obj[key]
key in obj
```

## 13.6 Iteração

```python
__iter__
__next__
```

## 13.7 Callables

```python
__call__
```

```python
class Multiplier:
    def __init__(self, factor):
        self.factor = factor

    def __call__(self, value):
        return value * self.factor
```

```python
triple = Multiplier(3)
triple(10)
```

## 13.8 Comparações

```python
__eq__
__ne__
__lt__
__le__
__gt__
__ge__
```

`functools.total_ordering` pode derivar comparações restantes a partir de algumas operações, embora impleméntá-las explicitamente possa ser mais eficiente.

## 13.9 Hashing

```python
__hash__
```

Regra conceitual:

> Objetos iguais devem possuir o mesmo hash.

Objetos mutáveis usados em igualdade por conteúdo normalmente não devem ser hashable.

## 13.10 Operadores

```python
__add__
__sub__
__mul__
__truediv__
__floordiv__
__mod__
__pow__
```

Versões reflected:

```python
__radd__
__rsub__
...
```

Versões in-place:

```python
__iadd__
__imul__
...
```

## 13.11 Context manager

```python
__enter__
__exit__
```

Assíncrono:

```python
__aenter__
__aexit__
```

## 13.12 Conversões

```python
__int__
__float__
__complex__
__bytes__
__index__
```

## 13.13 Formatação

```python
__format__
```

Permite controlar:

```python
f"{obj:custom_spec}"
```

## 13.14 Attribute access

```python
__getattribute__
__getattr__
__setattr__
__delattr__
```

Detalhes na seção de descriptors.

---

# 14. Herança, composição, ABCs e Protocols

## 14.1 Herança simples

```python
class Animal:
    def speak(self):
        raise NotImplementedError

class Dog(Animal):
    def speak(self):
        return "woof"
```

## 14.2 `super()`

```python
class Employee(Person):
    def __init__(self, name, salary):
        super().__init__(name)
        self.salary = salary
```

`super()` não significa simplesmente “classe pai”. Ele segue o **MRO**.

## 14.3 MRO

Method Resolution Order:

```python
MyClass.__mro__
```

ou:

```python
MyClass.mro()
```

Em herança múltipla, Python usa C3 linearization.

## 14.4 Herança múltipla

```python
class LoggingMixin:
    def log(self, message):
        print(message)

class Service(LoggingMixin, BaseService):
    ...
```

Mixins pequenos e ortogonais são um uso comum.

Evite grandes árvores de herança múltipla com estado complexo.

## 14.5 Cooperative inheritance

Para que `super()` funcione corretamente em hierarquias cooperativas, classes devem respeitar chamadas compatíveis ao próximo elemento do MRO.

## 14.6 ABC

```python
from abc import ABC, abstractmethod

class Repository(ABC):
    @abstractmethod
    def get(self, user_id):
        ...
```

Uma subclasse que não implementar os métodos abstratos continua abstrata.

## 14.7 Protocols

Typing estrutural:

```python
from typing import Protocol

class Writer(Protocol):
    def write(self, data: str) -> int:
        ...
```

Qualquer objeto compatível com essa interface pode satisfazer `Writer` para type checkers.

É duck typing formalizado estaticamente.

## 14.8 `runtime_checkable`

```python
from typing import Protocol, runtime_checkable

@runtime_checkable
class Closeable(Protocol):
    def close(self) -> None:
        ...
```

Permite certos `isinstance` checks estruturais em runtime.

Use apenas quando realmente precisa de runtime checking.

## 14.9 ABC versus Protocol

**ABC:**

- relação nominal;
- subclasses explicitamente participam da hierarquia;
- pode conter implementação compartilhada.

**Protocol:**

- relação estrutural;
- consumidor se importa com capacidades;
- desacopla interfaces de herança.

---

# 15. Descriptors, properties e controle de atributos

Descriptors explicam boa parte da “mágica” da orientação a objetos em Python.

## 15.1 Protocolo descriptor

Um descriptor pode implementar:

```python
__get__
__set__
__delete__
```

Exemplo:

```python
class Positive:
    def __set_name__(self, owner, name):
        self.name = name

    def __get__(self, instance, owner):
        if instance is None:
            return self
        return instance.__dict__[self.name]

    def __set__(self, instance, value):
        if value <= 0:
            raise ValueError("must be positive")
        instance.__dict__[self.name] = value


class Product:
    price = Positive()

    def __init__(self, price):
        self.price = price
```

## 15.2 Data descriptor versus non-data descriptor

Data descriptor implementa `__set__` ou `__delete__` além de `__get__`.

Non-data descriptor implementa apenas `__get__`.

Isso afeta precedência na resolução de atributos.

## 15.3 Métodos são descriptors

Quando uma função está no corpo da classe:

```python
class User:
    def greet(self):
        ...
```

acessar:

```python
user.greet
```

produz um **bound method** graças ao descriptor protocol da função.

## 15.4 `property` é descriptor

```python
@property
```

é uma abstração construída sobre descriptors.

## 15.5 `__getattr__`

Chamado apenas quando lookup normal falha.

```python
class Config:
    def __getattr__(self, name):
        raise AttributeError(name)
```

## 15.6 `__getattribute__`

Intercepta **todo** acesso a atributos.

```python
class Example:
    def __getattribute__(self, name):
        return super().__getattribute__(name)
```

É fácil causar recursão infinita aqui.

## 15.7 `__setattr__`

```python
class Example:
    def __setattr__(self, name, value):
        super().__setattr__(name, value)
```

## 15.8 `__slots__`

```python
class Point:
    __slots__ = ("x", "y")

    def __init__(self, x, y):
        self.x = x
        self.y = y
```

Pode:

- reduzir memória por instância;
- impedir atributos arbitrários;
- alterar detalhes de introspecção.

Não use como otimização prematura. Meça primeiro.

---

# 16. Dataclasses e modelos de dados

## 16.1 Básico

```python
from dataclasses import dataclass

@dataclass
class User:
    name: str
    age: int
```

Gera automaticamente métodos como `__init__` e `__repr__`, conforme configuração.

## 16.2 Defaults

```python
@dataclass
class Config:
    host: str = "localhost"
    port: int = 5432
```

## 16.3 `default_factory`

```python
from dataclasses import dataclass, field

@dataclass
class Team:
    members: list[str] = field(default_factory=list)
```

Evita defaults mutáveis compartilhados.

## 16.4 Frozen

```python
@dataclass(frozen=True)
class Point:
    x: float
    y: float
```

É uma aproximação prática de imutabilidade, não uma barreira absoluta contra toda manipulação interna.

## 16.5 Slots

```python
@dataclass(slots=True)
class Point:
    x: float
    y: float
```

## 16.6 Ordering

```python
@dataclass(order=True)
class Version:
    major: int
    minor: int
```

## 16.7 Campos excluídos de comparação

```python
@dataclass
class Item:
    id: int
    cache: dict = field(default_factory=dict, compare=False, repr=False)
```

## 16.8 `InitVar`

Permite parâmetros de inicialização que não viram campos normais.

```python
from dataclasses import InitVar, dataclass

@dataclass
class User:
    name: str
    password: InitVar[str]

    def __post_init__(self, password):
        self.password_hash = hash_password(password)
```

## 16.9 `__post_init__`

```python
@dataclass
class Rectangle:
    width: float
    height: float

    def __post_init__(self):
        if self.width < 0 or self.height < 0:
            raise ValueError("dimensions must be non-negative")
```

## 16.10 Quando não usar dataclass

Não transforme toda classe em dataclass.

Ela é ótima quando a identidade da classe é fortemente baseada em seus dados.

Classes com comportamento complexo e invariantes fortes às vezes ficam mais claras com implementação manual.

---

# 17. Typing moderno

Type hints são metadados. Python continua dinamicamente tipado em runtime salvo quando alguma ferramenta explicitamente interpreta as anotações.

## 17.1 Básico

```python
def add(a: int, b: int) -> int:
    return a + b
```

## 17.2 Tipos built-in parametrizados

Python moderno:

```python
list[str]
dict[str, int]
tuple[int, str]
set[float]
```

Em código atual, normalmente não é necessário usar `typing.List`, `typing.Dict`, etc.

## 17.3 Union

```python
str | None
int | float
```

Em vez de:

```python
Optional[str]
Union[int, float]
```

Embora essas formas antigas ainda apareçam em bases existentes.

## 17.4 `Any`

```python
from typing import Any
```

`Any` efetivamente desliga boa parte da checagem para aquele valor.

Use conscientemente.

## 17.5 `object`

```python
def consume(value: object) -> None:
    ...
```

`object` significa “algum objeto, sem assumir capacidades específicas”.

É mais seguro que `Any` quando você não precisa operar arbitrariamente sobre ele.

## 17.6 Type aliases

Forma tradicional:

```python
UserId = int
```

Python 3.12+ possui statement `type`:

```python
type UserId = int
```

Alias genérico moderno:

```python
type Pair[T] = tuple[T, T]
```

## 17.7 Genéricos modernos

Python 3.12+:

```python
class Box[T]:
    def __init__(self, value: T):
        self.value = value

    def get(self) -> T:
        return self.value
```

Função genérica:

```python
def first[T](items: list[T]) -> T:
    return items[0]
```

Forma anterior ainda muito comum:

```python
from typing import TypeVar, Generic

T = TypeVar("T")

class Box(Generic[T]):
    ...
```

## 17.8 Bounded type parameters

```python
class Entity:
    ...


def save[T: Entity](entity: T) -> T:
    ...
```

## 17.9 `Literal`

```python
from typing import Literal

Mode = Literal["read", "write"]
```

## 17.10 `Final`

```python
from typing import Final

MAX_RETRIES: Final = 3
```

## 17.11 `ClassVar`

```python
from typing import ClassVar

@dataclass
class User:
    table_name: ClassVar[str] = "users"
    name: str
```

## 17.12 `TypedDict`

```python
from typing import TypedDict

class UserPayload(TypedDict):
    name: str
    age: int
```

Útil para dicionários com estrutura conhecida.

## 17.13 Campos opcionais em `TypedDict`

```python
from typing import NotRequired, TypedDict

class Config(TypedDict):
    host: str
    timeout: NotRequired[float]
```

## 17.14 `Protocol`

```python
from typing import Protocol

class Reader(Protocol):
    def read(self, size: int = -1) -> str:
        ...
```

## 17.15 `Callable`

```python
from collections.abc import Callable

Handler = Callable[[str], int]
```

Para assinaturas complexas, `Protocol` frequentemente documenta melhor.

## 17.16 `ParamSpec`

Útil em decorators tipados:

```python
from collections.abc import Callable
from typing import ParamSpec, TypeVar

P = ParamSpec("P")
R = TypeVar("R")


def decorator(func: Callable[P, R]) -> Callable[P, R]:
    ...
```

## 17.17 `Self`

```python
from typing import Self

class Builder:
    def configure(self, value: int) -> Self:
        self.value = value
        return self
```

## 17.18 `Never`

```python
from typing import Never

def fail(message: str) -> Never:
    raise RuntimeError(message)
```

## 17.19 `assert_never`

Ajuda a verificar exaustividade com type checkers.

```python
from typing import assert_never
```

## 17.20 Type narrowing

```python
def process(value: str | None):
    if value is None:
        return

    reveal_type(value)  # type checker: str
```

## 17.21 `TypeGuard` e `TypeIs`

Servem para funções que refinam tipos para ferramentas estáticas.

`TypeIs` foi introduzido para expressar certos refinamentos de forma mais precisa.

## 17.22 Anotações não substituem validação

```python
def set_age(age: int):
    ...
```

não impede automaticamente:

```python
set_age("abc")
```

Validação runtime é responsabilidade de sua aplicação ou de ferramentas específicas.

---

# 18. Pattern matching

Structural pattern matching usa `match` / `case`.

## 18.1 Literais

```python
match status:
    case 200:
        result = "ok"
    case 404:
        result = "not found"
    case _:
        result = "other"
```

## 18.2 Sequence patterns

```python
match point:
    case [0, 0]:
        ...
    case [x, 0]:
        ...
    case [x, y]:
        ...
```

## 18.3 Mapping patterns

```python
match payload:
    case {"type": "user", "id": user_id}:
        ...
```

Campos extras podem existir.

## 18.4 Class patterns

```python
@dataclass
class Point:
    x: int
    y: int

match point:
    case Point(x=0, y=y):
        ...
```

## 18.5 Positional class matching

Dataclasses geram `__match_args__` por padrão em muitos casos:

```python
match point:
    case Point(0, y):
        ...
```

## 18.6 OR pattern

```python
case 401 | 403:
    ...
```

## 18.7 Guard

```python
case Point(x, y) if x == y:
    ...
```

## 18.8 Capture não é comparação

Isto captura:

```python
case value:
```

Não compara com uma variável existente chamada `value`.

Constantes qualificadas podem ser usadas em value patterns.

## 18.9 Quando usar

`match` é excelente para:

- interpretar estruturas heterogêneas;
- ASTs;
- protocolos;
- mensagens/eventos;
- parsers;
- estados com estrutura clara.

Não substitua todo `if` simples por `match`.

---

# 19. Programação funcional

Python não é linguagem funcional pura, mas suporta muitos padrões funcionais.

## 19.1 Funções de primeira classe

```python
def apply(func, value):
    return func(value)
```

## 19.2 Higher-order functions

```python
map
filter
sorted(key=...)
min(key=...)
max(key=...)
```

Frequentemente comprehensions são mais legíveis que `map`/`filter`.

## 19.3 `functools.partial`

```python
from functools import partial

int_base_2 = partial(int, base=2)
int_base_2("1010")
```

## 19.4 `reduce`

```python
from functools import reduce
```

Útil em alguns folds, mas muitas reduções possuem funções específicas mais claras:

```python
sum(values)
min(values)
max(values)
all(values)
any(values)
```

## 19.5 `lru_cache`

```python
from functools import lru_cache

@lru_cache(maxsize=1024)
def expensive(x):
    ...
```

## 19.6 `cache`

```python
from functools import cache

@cache
def fib(n):
    ...
```

Cache ilimitado; use apenas quando domínio é controlado.

## 19.7 `singledispatch`

```python
from functools import singledispatch

@singledispatch
def serialize(value):
    raise TypeError(type(value))

@serialize.register
def _(value: int):
    return str(value)
```

Despacha com base no tipo do primeiro argumento.

---

# 20. Strings, bytes e Unicode

## 20.1 `str` versus `bytes`

- `str`: texto Unicode;
- `bytes`: sequência de bytes.

```python
text = "olá"
data = text.encode("utf-8")
restored = data.decode("utf-8")
```

## 20.2 Não misture texto e bytes sem fronteira clara

I/O de rede, compressão, hashes e protocolos binários normalmente trabalham com bytes.

Aplicação e UI normalmente trabalham com `str`.

Converta explicitamente nas fronteiras.

## 20.3 F-strings

```python
name = "Alice"
age = 30
message = f"{name} is {age} years old"
```

Debug syntax:

```python
f"{value=}"
```

Formatação:

```python
f"{price:.2f}"
f"{ratio:.2%}"
f"{value:08d}"
```

## 20.4 Conversion flags

```python
f"{obj!r}"
f"{obj!s}"
f"{obj!a}"
```

## 20.5 Template strings — Python 3.14+

Python 3.14 introduz **t-strings** (*template string literals*).

```python
name = "Alice"
template = t"Hello {name}"
```

Diferentemente de f-strings, o objetivo não é produzir imediatamente uma `str`, mas preservar estrutura suficiente para processamento customizado.

São úteis para construir APIs seguras e estruturadas para casos como:

- templating;
- escaping;
- geração de SQL/HTML por bibliotecas;
- DSLs.

Consulte `string.templatelib` ao usar esse recurso.

## 20.6 Raw strings

```python
pattern = r"\d+\s+\w+"
```

Muito úteis para regex e caminhos com backslashes.

## 20.7 Unicode normalization

```python
import unicodedata

normalized = unicodedata.normalize("NFC", text)
```

Duas strings visualmente iguais podem ter sequências Unicode diferentes.

## 20.8 `casefold`

```python
left.casefold() == right.casefold()
```

Melhor que `lower()` para comparações Unicode case-insensitive em vários contextos.

---

# 21. Arquivos, caminhos e serialização

## 21.1 `pathlib`

Prefira `pathlib.Path` em código moderno.

```python
from pathlib import Path

path = Path("data") / "users.json"
```

Operações:

```python
path.exists()
path.is_file()
path.is_dir()
path.name
path.stem
path.suffix
path.parent
path.resolve()
```

## 21.2 Leitura e escrita simples

```python
text = path.read_text(encoding="utf-8")
path.write_text("hello", encoding="utf-8")
```

Bytes:

```python
data = path.read_bytes()
path.write_bytes(data)
```

## 21.3 `open`

```python
with open("file.txt", "r", encoding="utf-8") as file:
    ...
```

Modos comuns:

```text
r  leitura
w  sobrescreve
x  cria apenas se não existir
a  append
b  binário
+  leitura e escrita
```

## 21.4 JSON

```python
import json

text = json.dumps(data)
data = json.loads(text)
```

Arquivos:

```python
with open("data.json", "w", encoding="utf-8") as file:
    json.dump(data, file, ensure_ascii=False, indent=2)
```

## 21.5 CSV

```python
import csv

with open("data.csv", newline="", encoding="utf-8") as file:
    reader = csv.DictReader(file)
    for row in reader:
        ...
```

## 21.6 `pickle`

```python
import pickle
```

**Nunca desserialize pickle de fonte não confiável.**

Pickle pode executar código arbitrário durante deserialização.

## 21.7 TOML

Python possui leitura TOML na biblioteca padrão:

```python
import tomllib

with open("pyproject.toml", "rb") as file:
    config = tomllib.load(file)
```

`tomllib` é leitura, não escrita.

## 21.8 `tempfile`

```python
from tempfile import TemporaryDirectory

with TemporaryDirectory() as directory:
    ...
```

Evite criar temporários manualmente quando a biblioteca padrão já gerencia nomes e cleanup de forma segura.

---

# 22. Datas, horários e fusos

## 22.1 `datetime`

```python
from datetime import datetime, date, time, timedelta
```

## 22.2 Naive versus aware

`datetime` naive não possui timezone associado.

`datetime` aware possui informação de fuso.

Para sistemas distribuídos, prefira armazenar instantes em UTC e converter para apresentação.

## 22.3 UTC

```python
from datetime import datetime, UTC

now = datetime.now(UTC)
```

## 22.4 `zoneinfo`

```python
from zoneinfo import ZoneInfo

sp = ZoneInfo("America/Sao_Paulo")
local = datetime.now(sp)
```

## 22.5 `timedelta`

```python
expires_at = now + timedelta(hours=2)
```

## 22.6 ISO 8601

```python
text = dt.isoformat()
dt = datetime.fromisoformat(text)
```

## 22.7 Tempo monotônico

Para medir duração, prefira relógio monotônico:

```python
from time import perf_counter

start = perf_counter()
...
elapsed = perf_counter() - start
```

Não use relógio civil para benchmark/duração.

---

# 23. Regex

```python
import re
```

## 23.1 Compile padrões reutilizados

```python
EMAIL = re.compile(r"^[^@]+@[^@]+\.[^@]+$")
```

## 23.2 Funções comuns

```python
re.search(pattern, text)
re.match(pattern, text)
re.fullmatch(pattern, text)
re.findall(pattern, text)
re.finditer(pattern, text)
re.sub(pattern, replacement, text)
re.split(pattern, text)
```

## 23.3 Grupos

```python
match = re.search(r"(\d{4})-(\d{2})-(\d{2})", text)
if match:
    year, month, day = match.groups()
```

Named groups:

```python
r"(?P<year>\d{4})-(?P<month>\d{2})-(?P<day>\d{2})"
```

## 23.4 Regex não é parser universal

Para gramáticas complexas, dados estruturados ou HTML completo, use parser adequado.

---

# 24. Concorrência, paralelismo e asyncio

É importante separar:

- concorrência;
- paralelismo;
- I/O-bound;
- CPU-bound.

## 24.1 Concorrência

Múltiplas tarefas progridem durante o mesmo período.

Não implica execução simultânea em múltiplos cores.

## 24.2 Paralelismo

Trabalho ocorre simultaneamente.

## 24.3 Threads

```python
from threading import Thread

thread = Thread(target=worker)
thread.start()
thread.join()
```

Threads compartilham memória.

São muito úteis para I/O bloqueante.

## 24.4 Locks

```python
from threading import Lock

lock = Lock()

with lock:
    mutate_shared_state()
```

## 24.5 GIL

Na implementação CPython tradicional, o **Global Interpreter Lock** impede múltiplas threads de executarem bytecode Python simultaneamente dentro de um mesmo interpreter.

Isso não torna threads inúteis:

- I/O libera/cede execução;
- extensões nativas podem liberar GIL;
- threads continuam úteis para concorrência bloqueante.

## 24.6 Free-threaded CPython

Python recente possui uma configuração **free-threaded**, que permite executar Python sem o GIL tradicional.

Na série 3.14, free-threaded Python é oficialmente suportado, embora o ecossistema e o perfil de performance ainda devam ser considerados caso a caso.

Código thread-safe continua sendo responsabilidade do desenvolvedor.

“Sem GIL” não significa “sem race conditions”.

## 24.7 `concurrent.futures`

### Thread pool

```python
from concurrent.futures import ThreadPoolExecutor

with ThreadPoolExecutor(max_workers=8) as executor:
    results = list(executor.map(fetch, urls))
```

### Process pool

```python
from concurrent.futures import ProcessPoolExecutor

with ProcessPoolExecutor() as executor:
    results = list(executor.map(cpu_heavy, inputs))
```

Processos isolam memória e têm custo maior de comunicação/serialização.

## 24.8 Multiprocessing

```python
from multiprocessing import Process, Queue
```

Adequado quando isolamento e paralelismo de processo são desejados.

Lembre que comportamento de criação de processos varia por plataforma/start method.

## 24.9 Asyncio

```python
import asyncio

async def main():
    ...

asyncio.run(main())
```

## 24.10 Coroutine

```python
async def fetch_data():
    await asyncio.sleep(1)
    return {"ok": True}
```

Chamar `fetch_data()` produz um coroutine object; não executa até ser awaited/agendado.

## 24.11 Criando tasks

```python
async def main():
    task = asyncio.create_task(fetch_data())
    result = await task
```

## 24.12 Concorrência com `gather`

```python
results = await asyncio.gather(
    fetch(a),
    fetch(b),
    fetch(c),
)
```

## 24.13 `TaskGroup`

Concorrência estruturada:

```python
async with asyncio.TaskGroup() as tg:
    task_a = tg.create_task(fetch(a))
    task_b = tg.create_task(fetch(b))

result_a = task_a.result()
result_b = task_b.result()
```

`TaskGroup` oferece semântica de falha e cleanup mais estruturada que tasks soltas.

## 24.14 Timeout

```python
async with asyncio.timeout(5):
    await operation()
```

## 24.15 Cancelamento

Cancelamento é parte normal do fluxo assíncrono.

Não engula `CancelledError` sem entender as consequências.

## 24.16 Blocking dentro de async

Isto bloqueia event loop:

```python
async def bad():
    time.sleep(5)
```

Use:

```python
await asyncio.sleep(5)
```

Para função bloqueante existente:

```python
result = await asyncio.to_thread(blocking_function, arg)
```

## 24.17 Async iterators

```python
async for item in stream:
    ...
```

Protocolo:

```python
__aiter__
__anext__
```

## 24.18 Async context managers

```python
async with resource:
    ...
```

Protocolo:

```python
__aenter__
__aexit__
```

## 24.19 Subinterpreters — Python 3.14+

Python 3.14 adiciona suporte de alto nível na biblioteca padrão para múltiplos interpreters.

O módulo `concurrent.interpreters` expõe recursos relacionados a subinterpreters.

É uma área importante para isolamento e novas formas de concorrência dentro de um processo, mas possui semântica diferente de threads e processos e exige atenção ao compartilhamento de objetos.

---

# 25. Subprocessos e interação com o sistema

## 25.1 `subprocess.run`

```python
import subprocess

result = subprocess.run(
    ["git", "status", "--short"],
    capture_output=True,
    text=True,
    check=True,
)

print(result.stdout)
```

## 25.2 Prefira lista de argumentos

```python
["git", "status"]
```

em vez de construir string shell.

## 25.3 `shell=True`

Use apenas quando precisa explicitamente de recursos do shell e entende os riscos.

Nunca concatene input não confiável em comando shell.

## 25.4 Variáveis de ambiente

```python
import os

value = os.environ.get("API_KEY")
```

## 25.5 `shutil`

```python
import shutil

shutil.copy(src, dst)
shutil.copytree(src, dst)
shutil.move(src, dst)
shutil.rmtree(path)
```

## 25.6 `os` versus `pathlib`

Use `pathlib` para manipulação orientada a caminhos.

Use `os` para vários recursos do sistema operacional e compatibilidade com APIs existentes.

---

# 26. Introspecção, metaprogramação e metaclasses

## 26.1 Introspecção básica

```python
type(obj)
isinstance(obj, SomeType)
issubclass(A, B)
dir(obj)
vars(obj)
getattr(obj, "name")
setattr(obj, "name", value)
hasattr(obj, "name")
callable(obj)
```

## 26.2 `inspect`

```python
import inspect

inspect.signature(func)
inspect.getmembers(obj)
inspect.iscoroutinefunction(func)
inspect.isgeneratorfunction(func)
```

## 26.3 Classes são instâncias de metaclasses

```python
class User:
    pass

print(type(User))  # type
```

A metaclasse padrão é `type`.

## 26.4 Criando classe dinamicamente

```python
User = type(
    "User",
    (object,),
    {"species": "human"},
)
```

Equivalente conceitualmente a uma declaração de classe simples.

## 26.5 Metaclass

```python
class RegistryMeta(type):
    registry = {}

    def __new__(mcls, name, bases, namespace):
        cls = super().__new__(mcls, name, bases, namespace)
        mcls.registry[name] = cls
        return cls


class Plugin(metaclass=RegistryMeta):
    pass
```

## 26.6 Quando evitar metaclasses

Antes de criar uma metaclass, considere:

- decorator de classe;
- `__init_subclass__`;
- descriptor;
- factory;
- registry explícito.

Metaclasses são poderosas, mas aumentam muito o custo cognitivo.

## 26.7 `__init_subclass__`

```python
class Plugin:
    registry = {}

    def __init_subclass__(cls, **kwargs):
        super().__init_subclass__(**kwargs)
        cls.registry[cls.__name__] = cls
```

Frequentemente resolve casos que antes exigiriam metaclass.

## 26.8 `__class_getitem__`

Interpreta:

```python
MyClass[T]
```

É relevante em APIs genéricas e DSLs de tipos.

## 26.9 `__mro_entries__`

Permite participar da construção dinâmica de bases de uma classe em cenários avançados.

É recurso de metaprogramação de baixo nível; raramente necessário em aplicação comum.

---

# 27. Memória, garbage collector e cópias

## 27.1 Contagem de referências

CPython usa contagem de referências como parte central de sua estratégia de gerenciamento de memória.

```python
x = []
y = x
```

Enquanto referências existirem, o objeto permanece alcançável.

## 27.2 Ciclos

```python
a = []
a.append(a)
```

Contagem de referências sozinha não resolve ciclos.

CPython possui garbage collector para detectar certos ciclos de objetos.

## 27.3 `gc`

```python
import gc

gc.collect()
```

Normalmente não force coleta manual sem motivo medido.

Detalhes do GC são implementação/version-specific e podem mudar entre releases.

## 27.4 Referências fracas

```python
import weakref

ref = weakref.ref(obj)
```

Uma weak reference não mantém o objeto vivo por si só.

Útil em:

- caches;
- registries;
- grafos de objetos;
- observers.

## 27.5 Cópia rasa

```python
import copy

clone = copy.copy(obj)
```

Cria novo container externo, mas referências internas podem continuar compartilhadas.

## 27.6 Cópia profunda

```python
clone = copy.deepcopy(obj)
```

Recursivamente tenta copiar a estrutura.

Não é automaticamente a solução correta: identidade compartilhada pode ter significado semântico.

## 27.7 Exemplo

```python
original = [[1], [2]]
shallow = original.copy()
shallow[0].append(99)

print(original)  # [[1, 99], [2]]
```

## 27.8 Evite depender de destruição imediata

CPython frequentemente destrói objetos assim que refcount chega a zero, mas não escreva código portátil dependendo disso.

Para recursos externos, use context managers.

---

# 28. Performance e profiling

Primeira regra:

> **Meça antes de otimizar.**

## 28.1 Complexidade importa mais que micro-otimização

Trocar algoritmo O(n²) por O(n log n) vale muito mais que economizar pequenas chamadas.

## 28.2 Estruturas corretas

Exemplo:

```python
if value in values_list:
```

pode ser O(n).

Se lookup é operação principal:

```python
if value in values_set:
```

em média costuma ser O(1).

## 28.3 `timeit`

```bash
python -m timeit "sum(range(1000))"
```

Em código:

```python
import timeit

timeit.timeit("sum(range(1000))", number=10000)
```

## 28.4 `cProfile`

```bash
python -m cProfile -s cumulative app.py
```

## 28.5 `profile` mental

Investigue:

- I/O;
- chamadas de rede;
- SQL;
- serialização;
- alocação excessiva;
- loops Python pesados;
- conversões desnecessárias;
- estruturas inadequadas;
- cópias grandes.

## 28.6 Built-ins são frequentemente rápidos

```python
sum(values)
min(values)
max(values)
any(values)
all(values)
```

São preferíveis a muitos loops manuais equivalentes, tanto por clareza quanto muitas vezes por implementação otimizada.

## 28.7 Generator versus list

Generator economiza memória quando consumo é streaming.

Mas se os dados serão percorridos repetidamente, materializar uma lista pode ser correto e mais simples.

## 28.8 `__slots__`

Pode reduzir uso de memória para grandes quantidades de instâncias pequenas.

Meça antes.

## 28.9 C extensions e vetorização

Para computação numérica pesada, bibliotecas nativas como NumPy frequentemente vencem loops Python por ordens de grandeza.

O ganho não vem de “Python mais rápido”, e sim de mover o loop para implementação otimizada em código nativo/SIMD/etc.

## 28.10 Paralelismo não é otimização automática

Threads/processos adicionam:

- scheduling;
- sincronização;
- serialização;
- comunicação;
- contenção;
- complexidade.

Só paralelize quando o perfil justificar.

---

# 29. Testes

## 29.1 Estrutura recomendada

```text
project/
├── src/
│   └── myapp/
└── tests/
    ├── test_users.py
    └── test_orders.py
```

## 29.2 `unittest`

```python
import unittest

class TestMath(unittest.TestCase):
    def test_add(self):
        self.assertEqual(1 + 1, 2)
```

## 29.3 `pytest`

Embora não pertença à biblioteca padrão, `pytest` é uma escolha extremamente comum.

```python
def test_add():
    assert add(1, 2) == 3
```

## 29.4 Parametrização

```python
import pytest

@pytest.mark.parametrize(
    ("value", "expected"),
    [
        (2, 4),
        (3, 9),
        (4, 16),
    ],
)
def test_square(value, expected):
    assert square(value) == expected
```

## 29.5 Fixtures

```python
import pytest

@pytest.fixture
def user():
    return User("Alice")
```

## 29.6 Mocking

Biblioteca padrão:

```python
from unittest.mock import Mock, patch
```

```python
mailer = Mock()
mailer.send.return_value = True
```

## 29.7 Evite mockar tudo

Mocks excessivos fazem testes validarem a implementação atual em vez do comportamento relevante.

Prefira:

- objetos reais baratos;
- fakes simples;
- boundaries bem definidos;
- mocks onde side effects externos precisam ser controlados.

## 29.8 Unit versus integration

Unit tests:

- rápidos;
- isolados;
- boa localização de falhas.

Integration tests:

- verificam componentes reais juntos;
- capturam problemas de contratos reais.

Projetos robustos normalmente precisam dos dois.

## 29.9 Teste comportamento, não detalhes internos

Evite teste acoplado a chamadas internas se o contrato público é suficiente.

---

# 30. Logging

Não use `print` como sistema de logging de aplicações reais.

```python
import logging

logger = logging.getLogger(__name__)
```

## 30.1 Níveis

```python
logger.debug(...)
logger.info(...)
logger.warning(...)
logger.error(...)
logger.critical(...)
```

## 30.2 Exceções

Dentro de `except`:

```python
logger.exception("Failed to process request")
```

Inclui traceback.

## 30.3 Lazy formatting

Prefira:

```python
logger.info("User %s connected", user_id)
```

em vez de construir antecipadamente a string se a mensagem pode ser descartada pelo nível de log.

## 30.4 Não logue segredos

Evite registrar:

- senhas;
- tokens;
- API keys;
- cookies de sessão;
- dados pessoais sem necessidade.

## 30.5 Logging estruturado

Em sistemas distribuídos, considere logs estruturados contendo campos como:

```text
request_id
user_id
service
operation
latency_ms
status
```

Sem substituir segurança e políticas de privacidade.

---

# 31. Packaging, ambientes e projetos

## 31.1 Virtual environments

```bash
python -m venv .venv
source .venv/bin/activate
```

Windows PowerShell:

```powershell
.venv\Scripts\Activate.ps1
```

## 31.2 Instalar pacote

```bash
python -m pip install package
```

`python -m pip` reduz ambiguidade sobre qual interpreter está sendo usado.

## 31.3 `pyproject.toml`

É o centro moderno de configuração de projetos Python.

Exemplo mínimo conceitual:

```toml
[build-system]
requires = ["setuptools>=68"]
build-backend = "setuptools.build_meta"

[project]
name = "my-project"
version = "0.1.0"
requires-python = ">=3.12"
dependencies = []
```

## 31.4 Layout `src`

```text
project/
├── pyproject.toml
├── README.md
├── src/
│   └── myproject/
│       ├── __init__.py
│       └── main.py
└── tests/
```

Ajuda a evitar imports acidentais do diretório de trabalho em vez do pacote instalado.

## 31.5 Editable install

```bash
python -m pip install -e .
```

Útil durante desenvolvimento de pacote.

## 31.6 Dependências

Diferencie:

- dependências runtime;
- dependências de desenvolvimento;
- extras opcionais.

Não fixe versões cegamente sem entender seu modelo de deploy e reproducibilidade.

## 31.7 Lockfiles

Ferramentas modernas de gerenciamento de projeto podem produzir lockfiles para ambientes reproduzíveis.

A ferramenta específica pode variar; o conceito importante é separar:

- declaração de compatibilidade;
- resolução concreta reproduzível.

## 31.8 CLI entry points

Projetos podem declarar scripts:

```toml
[project.scripts]
myapp = "myproject.cli:main"
```

Depois de instalado:

```bash
myapp
```

## 31.9 `__main__.py`

Permite:

```bash
python -m myproject
```

Estrutura:

```text
myproject/
├── __init__.py
└── __main__.py
```

---

# 32. Qualidade de código e estilo

## 32.1 PEP 8

PEP 8 é a principal referência histórica de estilo.

Não trate estilo como religião; consistência e legibilidade são os objetivos.

## 32.2 PEP 257

Convenções para docstrings.

## 32.3 Formatter

Um formatter automático reduz debates irrelevantes de estilo.

Black é uma escolha popular; Ruff também possui formatter e tooling amplo.

## 32.4 Linter

Ruff tornou-se uma ferramenta muito popular para linting rápido e consolidação de diversas regras.

Outras ferramentas continuam válidas dependendo do projeto.

## 32.5 Type checker

Opções comuns incluem:

- mypy;
- Pyright;
- ferramentas integradas a IDEs.

A escolha depende do nível de strictness e do ecossistema.

## 32.6 Nomes

```text
snake_case       funções, variáveis, módulos
PascalCase       classes
UPPER_CASE       constantes por convenção
_leading_underscore   interno
```

## 32.7 Funções pequenas, mas não artificialmente fragmentadas

Boa função:

- possui responsabilidade clara;
- nome expressivo;
- contrato compreensível;
- baixa quantidade de efeitos colaterais inesperados.

Não existe limite mágico de linhas.

## 32.8 Comentários

Comentários devem explicar principalmente **por quê**, restrições e decisões não óbvias.

Código já mostra **o quê** na maioria dos casos.

## 32.9 Docstrings versus comentários

Docstring documenta contrato/interface.

Comentário explica detalhe local de implementação.

---

# 33. Segurança e armadilhas comuns

## 33.1 `eval` e `exec`

```python
eval(user_input)
exec(user_input)
```

Nunca faça isso com conteúdo não confiável.

## 33.2 Pickle inseguro

Nunca deserializar pickle não confiável.

## 33.3 SQL injection

Errado:

```python
query = f"SELECT * FROM users WHERE id = {user_input}"
```

Use parametrização oferecida pelo driver/ORM.

## 33.4 Shell injection

Evite:

```python
subprocess.run(f"tool {user_input}", shell=True)
```

Prefira argumentos separados:

```python
subprocess.run(["tool", user_input], check=True)
```

## 33.5 Segredos no código

Não versione:

```python
API_KEY = "..."
```

Use secret management/configuração externa adequada ao ambiente.

## 33.6 Mutable default arguments

Já visto:

```python
def f(items=[]):
    ...
```

É uma das armadilhas mais recorrentes.

## 33.7 Multiplicação de listas aninhadas

Armadilha:

```python
matrix = [[0] * 3] * 3
matrix[0][0] = 1
```

Todas as linhas referenciam a mesma lista interna.

Correto:

```python
matrix = [[0] * 3 for _ in range(3)]
```

## 33.8 `is` para números/strings

Não faça:

```python
x is 100
```

Use:

```python
x == 100
```

Caching/interning de objetos é detalhe de implementação.

## 33.9 Modificar coleção durante iteração

Cuidado:

```python
for key in mapping:
    del mapping[key]
```

Prefira iterar por cópia quando apropriado:

```python
for key in list(mapping):
    ...
```

## 33.10 `except Exception: pass`

Isso transforma bugs em comportamento silencioso.

Capture apenas o que sabe tratar.

## 33.11 `assert` não é validação de input externo

```python
assert user.age >= 18
```

`assert` pode ser removido em execuções otimizadas.

Use exceções explícitas para invariantes que precisam existir em produção.

## 33.12 Timezone naive

Sistemas distribuídos frequentemente quebram por misturar horário local, UTC e timestamps naive.

Defina política temporal explícita.

## 33.13 Float para dinheiro

```python
0.1 + 0.2
```

Para cálculos monetários precisos, use decimal/integer minor units conforme domínio.

## 33.14 Imports com side effects

Módulos que fazem rede, I/O pesado ou inicialização destrutiva durante import dificultam testes e tooling.

Mantenha imports previsíveis sempre que possível.

---

# 34. Recursos modernos do Python 3.12–3.14

Esta seção serve como mapa para features que aparecem em bases modernas e podem não existir em versões antigas.

## 34.1 Python 3.12 — type parameter syntax

```python
class Box[T]:
    ...


def identity[T](value: T) -> T:
    return value


type Pair[T] = tuple[T, T]
```

Simplifica generics e aliases.

## 34.2 Python 3.12 — f-strings mais flexíveis

A gramática de f-strings foi integrada de forma mais completa à gramática da linguagem, eliminando diversas limitações históricas de parsing.

## 34.3 Python 3.13 — REPL melhorado

Python 3.13 introduziu um interactive interpreter modernizado em instalações compatíveis, com recursos como edição multilinha e melhor experiência visual.

## 34.4 Python 3.13 — free-threaded experimental

Python 3.13 introduziu build experimental free-threaded.

## 34.5 Python 3.14 — free-threaded oficialmente suportado

Na série 3.14, o modo free-threaded passou a ser oficialmente suportado.

Isso é importante para o futuro de paralelismo com threads em CPython, mas aplicações ainda precisam avaliar compatibilidade de dependências e performance.

## 34.6 Python 3.14 — deferred annotations

Python 3.14 muda a semântica de avaliação de annotations com a implementação relacionada à PEP 649.

A consequência prática é que anotações deixam de exigir a mesma avaliação eager usada historicamente, reduzindo vários problemas de forward references e imports usados apenas por typing.

Introspecção de annotations deve usar APIs apropriadas em vez de assumir que `__annotations__` contém simplesmente todos os objetos finais já avaliados.

## 34.7 Python 3.14 — template strings

```python
name = "Alice"
template = t"Hello {name}"
```

T-strings preservam estrutura de interpolação para processamento por bibliotecas.

## 34.8 Python 3.14 — subinterpreters na stdlib

A biblioteca padrão passa a oferecer suporte de alto nível relacionado a múltiplos interpreters.

É uma área relevante para arquiteturas concorrentes e isolamento dentro de um processo.

## 34.9 Python 3.14 — Zstandard

Python 3.14 adiciona suporte a Zstandard na biblioteca padrão via:

```python
compression.zstd
```

Útil para compressão moderna sem depender obrigatoriamente de pacote externo para a funcionalidade básica.

## 34.10 Compatibilidade de versões

Se sua aplicação precisa suportar múltiplas versões, defina claramente:

```toml
requires-python = ">=3.12"
```

E teste realmente contra as versões declaradas.

---

# 35. Idiomas Pythonic

## 35.1 Itere sobre valores

Em vez de:

```python
for i in range(len(items)):
    print(items[i])
```

use:

```python
for item in items:
    print(item)
```

## 35.2 Quando precisa de índice

```python
for i, item in enumerate(items):
    ...
```

## 35.3 Iterar em paralelo

```python
for name, age in zip(names, ages, strict=True):
    ...
```

## 35.4 Swap

```python
a, b = b, a
```

## 35.5 Membership

```python
if value in allowed:
    ...
```

## 35.6 Truthiness

```python
if items:
    ...
```

## 35.7 `any`

```python
if any(user.is_admin for user in users):
    ...
```

## 35.8 `all`

```python
if all(task.completed for task in tasks):
    ...
```

## 35.9 `next` com default

```python
user = next((u for u in users if u.id == target), None)
```

## 35.10 `dict.get`

```python
value = mapping.get(key, default)
```

## 35.11 `setdefault`

```python
groups.setdefault(key, []).append(value)
```

Para agrupamento intensivo, `defaultdict` costuma ser mais claro.

## 35.12 Merge de dict

```python
config = defaults | overrides
```

## 35.13 Unpacking

```python
config = {**defaults, **overrides}
```

Ainda útil, especialmente em expressões que misturam construção e expansão.

## 35.14 Context managers

Em vez de:

```python
file = open(path)
try:
    ...
finally:
    file.close()
```

use:

```python
with open(path) as file:
    ...
```

## 35.15 Comprehension quando simples

```python
squares = [x * x for x in values]
```

Não faça comprehension com múltiplos efeitos colaterais ou lógica excessiva.

## 35.16 `pathlib`

```python
config_path = root / "config" / "app.toml"
```

## 35.17 `dataclass` para value objects

```python
@dataclass(frozen=True, slots=True)
class UserId:
    value: int
```

quando uma estrutura explícita melhora domínio e typing.

## 35.18 Guard clauses

Em vez de aninhamento excessivo:

```python
def process(user):
    if user is None:
        return
    if not user.active:
        return
    ...
```

## 35.19 EAFP

```python
try:
    return cache[key]
except KeyError:
    value = compute(key)
    cache[key] = value
    return value
```

## 35.20 Named arguments para flags ambíguas

Ruim:

```python
send(data, True, False, 3)
```

Melhor:

```python
send(data, compress=True, encrypt=False, retries=3)
```

---

# 36. Padrões arquiteturais úteis em Python

## 36.1 Dependency inversion via Protocol

```python
from typing import Protocol

class UserRepository(Protocol):
    def get(self, user_id: int) -> "User | None":
        ...


class UserService:
    def __init__(self, repository: UserRepository):
        self.repository = repository
```

O service não precisa conhecer SQLAlchemy, PostgreSQL ou HTTP.

## 36.2 Repository

Use quando realmente há valor em abstrair persistência e operações de domínio.

Não crie repository genérico apenas para embrulhar cada método do ORM um-a-um.

## 36.3 Service layer

```python
class OrderService:
    def place_order(self, command):
        ...
```

Útil para coordenar regras de negócio e múltiplas dependências.

## 36.4 Value objects

```python
@dataclass(frozen=True, slots=True)
class Money:
    cents: int
    currency: str
```

Podem tornar invariantes explícitas.

## 36.5 Strategy

Em Python, strategy pode ser apenas callable:

```python
from collections.abc import Callable

type Scorer = Callable[[Item], float]
```

Nem todo padrão OO precisa de uma classe formal.

## 36.6 Factory

```python
def create_storage(kind: str) -> Storage:
    match kind:
        case "memory":
            return MemoryStorage()
        case "postgres":
            return PostgresStorage()
        case _:
            raise ValueError(kind)
```

## 36.7 Registry

```python
PLUGINS: dict[str, type[Plugin]] = {}

def register(name):
    def decorator(cls):
        PLUGINS[name] = cls
        return cls
    return decorator
```

## 36.8 Adapter

Faça uma interface externa parecer a interface esperada internamente.

```python
class StripePaymentGateway:
    def __init__(self, client):
        self.client = client

    def charge(self, amount: Money) -> PaymentResult:
        ...
```

## 36.9 Command/query separation

Uma regra útil, não absoluta:

- command muda estado;
- query retorna informação.

APIs ficam mais previsíveis quando uma operação não mistura ambos sem necessidade.

## 36.10 Eventos de domínio

```python
@dataclass(frozen=True)
class OrderPlaced:
    order_id: str
```

Eventos tornam coordenação desacoplada possível, mas introduzem complexidade. Use quando houver benefício arquitetural real.

## 36.11 Functional core, imperative shell

Uma estratégia poderosa em Python:

- núcleo com funções puras/regras determinísticas;
- bordas responsáveis por rede, banco, filesystem, tempo e side effects.

Isso melhora testes e reduz acoplamento.

---

# 37. Biblioteca padrão — mapa mental

A biblioteca padrão é enorme. O objetivo aqui é lembrar **onde procurar**.

## Sistema e arquivos

```text
os
sys
pathlib
shutil
tempfile
subprocess
platform
```

## Dados e coleções

```text
collections
array
heapq
bisect
enum
dataclasses
```

## Iteração e funcional

```text
itertools
functools
operator
```

## Texto

```text
re
string
textwrap
unicodedata
```

## Serialização e formatos

```text
json
csv
tomllib
pickle
sqlite3
```

## Compressão

```text
gzip
bz2
lzma
zipfile
tarfile
compression.zstd   # Python 3.14+
```

## Datas e números

```text
datetime
zoneinfo
time
calendar
math
statistics
decimal
fractions
random
secrets
```

## Concorrência

```text
threading
multiprocessing
concurrent.futures
asyncio
queue
concurrent.interpreters  # Python 3.14+
```

## Rede e protocolos

```text
socket
ssl
http
urllib
email
ipaddress
```

## Programação e introspecção

```text
inspect
importlib
pkgutil
ast
dis
traceback
pdb
code
compileall
```

## Testing e debugging

```text
unittest
unittest.mock
doctest
pdb
trace
tracemalloc
cProfile
timeit
```

## Logging e configuração

```text
logging
configparser
argparse
```

## Criptografia/utilidades seguras básicas

```text
hashlib
hmac
secrets
```

`secrets` deve ser preferido a `random` para tokens e valores imprevisíveis relacionados a segurança.

---

# 38. Checklist de revisão

Ao revisar código Python, pergunte:

## API

- A função/classe tem responsabilidade clara?
- Os nomes são suficientemente expressivos?
- Argumentos booleanos posicionais estão tornando a chamada ambígua?
- Parâmetros keyword-only melhorariam a API?
- Há tipos/Protocol úteis para explicitar contratos?

## Estado

- Existe estado global evitável?
- Um default mutável está sendo compartilhado?
- A classe precisa mesmo ser mutável?
- Composição seria melhor que herança?

## Erros

- As exceções capturadas são específicas?
- O código está escondendo erros?
- Exception chaining preserva a causa?
- A exceção faz parte do contrato público?

## Recursos

- Arquivos/conexões/locks usam context manager?
- Há cleanup seguro em caso de erro?
- Código depende de destruição implícita de objetos?

## Coleções

- A estrutura de dados escolhida corresponde às operações principais?
- `set` resolveria membership melhor?
- `deque` resolveria fila melhor?
- Há cópias desnecessárias de grandes estruturas?

## Concorrência

- O problema é CPU-bound ou I/O-bound?
- Async está sendo usado apenas porque “parece moderno”?
- Existe operação bloqueante no event loop?
- Estado compartilhado está sincronizado corretamente?
- Processos realmente compensam IPC/serialização?

## Performance

- Há perfil/prova de gargalo?
- O problema é algoritmo, I/O ou overhead Python?
- Dá para usar operação built-in ou biblioteca nativa?

## Segurança

- Inputs externos estão validados?
- Queries SQL são parametrizadas?
- Comandos shell evitam concatenação de input?
- Pickle/eval/exec recebem dados confiáveis?
- Logs escondem segredos?

## Testabilidade

- Side effects estão nas bordas?
- Dependências podem ser substituídas sem monkeypatch excessivo?
- Testes verificam comportamento ou detalhes internos?

## Packaging

- `requires-python` está definido?
- O projeto usa ambiente isolado?
- Dependências runtime e dev estão separadas?
- A estrutura de pacote evita imports acidentais?

---

# 39. Referências oficiais

Documentação oficial:

- Python 3.14 Documentation: https://docs.python.org/3.14/
- Language Reference: https://docs.python.org/3.14/reference/
- Standard Library: https://docs.python.org/3.14/library/
- Python Tutorial: https://docs.python.org/3.14/tutorial/
- Python HOWTOs: https://docs.python.org/3.14/howto/
- Data Model: https://docs.python.org/3.14/reference/datamodel.html
- Typing: https://docs.python.org/3.14/library/typing.html
- asyncio: https://docs.python.org/3.14/library/asyncio.html
- Packaging User Guide: https://packaging.python.org/
- Python Enhancement Proposals: https://peps.python.org/

PEPs particularmente úteis:

```text
PEP 8    Style Guide for Python Code
PEP 20   The Zen of Python
PEP 257  Docstring Conventions
PEP 343  The with Statement
PEP 484  Type Hints
PEP 544  Protocols
PEP 557  Data Classes
PEP 572  Assignment Expressions
PEP 585  Built-in Generic Types
PEP 604  Union Type Operator
PEP 612  Parameter Specification Variables
PEP 634  Structural Pattern Matching
PEP 646  Variadic Generics
PEP 673  Self Type
PEP 695  Type Parameter Syntax
PEP 703  Making the GIL Optional
PEP 734  Multiple Interpreters
PEP 750  Template Strings
PEP 779  Free-threaded Python Supported
```

---

# Apêndice A — Cheatsheet de sintaxe

```python
# unpacking
x, y = point
first, *rest = values

# comprehension
[x * 2 for x in values if x > 0]

# dict comprehension
{k: transform(v) for k, v in mapping.items()}

# generator
(x * 2 for x in values)

# walrus
if (match := pattern.search(text)):
    ...

# context manager
with resource() as r:
    ...

# multiple context managers
with open(a) as fa, open(b) as fb:
    ...

# exceptions
try:
    ...
except ValueError as exc:
    ...
else:
    ...
finally:
    ...

# match
match value:
    case {"type": "user", "id": user_id}:
        ...
    case _:
        ...

# async
async def main():
    result = await operation()

# typing moderno
class Box[T]:
    value: T

type UserId = int

# dataclass
@dataclass(slots=True)
class User:
    name: str
```

---

# Apêndice B — Dunder methods mais importantes

```text
Construção
    __new__
    __init__

Representação
    __repr__
    __str__
    __format__

Identidade lógica
    __eq__
    __hash__

Ordenação
    __lt__
    __le__
    __gt__
    __ge__

Truthiness / tamanho
    __bool__
    __len__

Container
    __getitem__
    __setitem__
    __delitem__
    __contains__

Iteração
    __iter__
    __next__

Async iteration
    __aiter__
    __anext__

Call
    __call__

Context manager
    __enter__
    __exit__

Async context manager
    __aenter__
    __aexit__

Attribute access
    __getattribute__
    __getattr__
    __setattr__
    __delattr__

Descriptor
    __get__
    __set__
    __delete__
    __set_name__

Classes
    __init_subclass__
    __class_getitem__

Operadores
    __add__
    __radd__
    __iadd__
    __sub__
    __mul__
    __truediv__
    __floordiv__
    __mod__
    __pow__
```

---

# Apêndice C — Ordem mental para escolher abstrações

Quando estiver modelando algo em Python, tente esta sequência antes de criar uma hierarquia complexa:

```text
valor simples
    ↓
função
    ↓
função + dataclass/value object
    ↓
composição de objetos
    ↓
Protocol / ABC para contrato
    ↓
decorator / descriptor / __init_subclass__
    ↓
herança múltipla controlada
    ↓
metaclass
```

Não é uma regra absoluta. É uma heurística para preservar simplicidade.

---

# Apêndice D — Princípios para código Python profissional

1. **Prefira interfaces pequenas.**
2. **Use tipos para comunicação, não para imitar Java.**
3. **Mantenha side effects nas bordas quando possível.**
4. **Não esconda I/O caro atrás de propriedades aparentemente triviais.**
5. **Não use async sem uma razão de concorrência real.**
6. **Não use classes quando uma função resolve melhor.**
7. **Não use herança quando composição representa melhor a relação.**
8. **Não use metaclass antes de explorar alternativas simples.**
9. **Capture apenas exceções que sabe tratar.**
10. **Meça performance antes de otimizar.**
11. **Conheça o data model: ele explica a linguagem.**
12. **Aproveite a biblioteca padrão.**
13. **Separe contrato de implementação.**
14. **Faça estados inválidos difíceis de representar.**
15. **Escreva código para humanos; o interpreter já entende qualquer sintaxe válida.**

---

> **Resumo mental:** Python fica muito mais previsível quando você deixa de pensar em “variáveis e sintaxe” e passa a pensar em **objetos, protocolos e bindings de nomes**. Iteração, funções, classes, decorators, context managers, operadores, properties e até boa parte do comportamento de tipos são manifestações de protocolos do data model. Dominar esses protocolos é a passagem de “saber Python” para “entender Python”.

---

[↑ Track A](../README.md) · [↑ Courses](../../../README.md) · [Próxima → A02 C++ e POO](../A02-cpp-poo/)
