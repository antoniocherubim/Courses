# Python Masterclass — Lista de Exercícios de Revisão

**Total: 545 exercícios.**

> Banco de exercícios para revisar o conteúdo de `python_masterclass.md`.
>
> A proposta não é ensinar Python do zero, mas verificar se os conceitos continuam disponíveis na memória e se você consegue aplicá-los sem consultar documentação.

## Como usar este caderno

Faça uma primeira tentativa **sem consultar a masterclass**. Marque cada exercício conforme o nível de segurança da resposta:

- `0` — não sei / não lembro;
- `1` — lembro parcialmente ou preciso testar/consultar;
- `2` — consigo explicar ou implementar com segurança.

Tipos de exercício usados ao longo do arquivo:

- **[C] Conceito** — explique com suas próprias palavras;
- **[S] Semântica** — preveja comportamento, saída ou exceção antes de executar;
- **[I] Implementação** — escreva uma solução curta;
- **[D] Debug/refatoração** — encontre o problema e proponha uma correção;
- **[A] Arquitetura** — escolha abstrações e justifique trade-offs.

Quando um exercício pedir código, prefira um arquivo pequeno e executável. Para os exercícios de semântica, escreva primeiro sua previsão e só depois rode o programa.

---

# 1. Filosofia e modelo mental

- [ ] **EX-001** **[C]** Explique o que significa dizer que, em Python, “tudo é objeto”. Dê exemplos envolvendo funções, classes, módulos e tipos.
- [ ] **EX-002** **[C]** Compare *duck typing* com tipagem baseada explicitamente em herança nominal.
- [ ] **EX-003** **[C]** Explique EAFP e LBYL. Dê um caso em que EAFP é mais natural e um caso em que uma verificação prévia é preferível.
- [ ] **EX-004** **[D]** Receba um trecho com vários `hasattr`, `if key in dict` e verificações redundantes antes de operações seguras. Reescreva-o em estilo EAFP quando apropriado.
- [ ] **EX-005** **[C]** Explique por que “Python é dinamicamente tipado” não significa “Python não tem tipos”.
- [ ] **EX-006** **[A]** Para uma API que aceita objetos “graváveis”, decida entre exigir uma classe-base, um `Protocol` ou simplesmente documentar que o objeto deve possuir `.write()`.

# 2. Execução, nomes, objetos e identidade

- [ ] **EX-007** **[C]** Explique a diferença entre variável como “caixa” e nome como *binding* para um objeto. Qual modelo descreve melhor Python?
- [ ] **EX-008** **[S]** Preveja o resultado de atribuições sucessivas como `a = [1]`, `b = a`, `a.append(2)` e `a = [3]`. Explique o estado de cada nome a cada etapa.
- [ ] **EX-009** **[C]** Diferencie identidade, igualdade e equivalência de valor. Relacione `is`, `==` e `id()`.
- [ ] **EX-010** **[D]** Encontre o erro conceitual em código que usa `is` para comparar strings ou números recebidos externamente.
- [ ] **EX-011** **[C]** Explique por que pequenos inteiros ou algumas strings podem parecer ter identidades reutilizadas e por que não se deve depender disso.
- [ ] **EX-012** **[S]** Determine quais operações alteram um objeto mutável existente e quais apenas fazem um nome apontar para outro objeto.
- [ ] **EX-013** **[C]** Explique aliasing e descreva pelo menos dois bugs comuns causados por aliases inesperados.
- [ ] **EX-014** **[I]** Escreva uma função que modifique intencionalmente uma lista recebida e outra que devolva uma nova lista sem modificar a original. Documente a diferença contratual.
- [ ] **EX-015** **[S]** Analise passagem de argumentos para uma função que recebe uma lista e um inteiro e modifica ambos localmente. Explique por que os efeitos observáveis diferem.
- [ ] **EX-016** **[C]** Explique por que a frase “Python passa argumentos por referência” é imprecisa. Descreva o modelo de *call by sharing* / passagem de referências a objetos.

# 3. Tipos fundamentais

- [ ] **EX-017** **[C]** Explique por que `int` em Python não sofre overflow de tamanho fixo como um inteiro C comum, e qual custo isso implica.
- [ ] **EX-018** **[S]** Preveja resultados envolvendo `//`, `%` e operandos negativos. Verifique a relação entre quociente e resto.
- [ ] **EX-019** **[C]** Explique a representação aproximada de `float` e por que `0.1 + 0.2 == 0.3` é problemático.
- [ ] **EX-020** **[I]** Compare valores `float` de forma robusta usando uma tolerância apropriada.
- [ ] **EX-021** **[C]** Explique quando `Decimal`, `Fraction` ou `float` é a escolha mais apropriada.
- [ ] **EX-022** **[C]** Mostre como criar e operar números complexos em Python e explique o papel de `j`.
- [ ] **EX-023** **[C]** Explique por que `bool` é uma subclasse de `int` e dê uma consequência prática dessa relação.
- [ ] **EX-024** **[S]** Classifique como truthy ou falsy: `0`, `0.0`, `0j`, `''`, `[]`, `{}`, `set()`, `None`, objetos customizados sem métodos especiais e objetos com `__len__` retornando zero.
- [ ] **EX-025** **[C]** Diferencie `None`, `NotImplemented` e `Ellipsis`. Dê um uso legítimo de cada um.
- [ ] **EX-026** **[I]** Crie uma API em que `None` seja um valor válido e, portanto, seja necessário um sentinel próprio para representar “argumento não fornecido”.

# 4. Expressões e operadores

- [ ] **EX-027** **[S]** Resolva manualmente uma expressão que combine `**`, operadores unários, multiplicação, soma, comparações, `not`, `and` e `or`. Justifique pela precedência.
- [ ] **EX-028** **[C]** Explique a diferença entre `/` e `//` e o contrato de `divmod()`.
- [ ] **EX-029** **[S]** Compare `a < b < c` com `a < b and b < c`, incluindo quantas vezes cada operando pode ser avaliado.
- [ ] **EX-030** **[C]** Explique por que `and` e `or` retornam operandos, e não necessariamente `bool`.
- [ ] **EX-031** **[I]** Use curto-circuito para fornecer um valor fallback; depois explique por que esse padrão falha quando valores falsy são entradas válidas.
- [ ] **EX-032** **[I]** Use o operador walrus em um laço ou compreensão onde ele reduza trabalho repetido sem comprometer a legibilidade.
- [ ] **EX-033** **[C]** Explique operações bitwise em inteiros e implemente funções simples para ligar, desligar e testar um bit de uma máscara.
- [ ] **EX-034** **[D]** Corrija uma expressão cuja lógica esteja errada por precedência de operadores e torne a intenção explícita com parênteses.

# 5. Controle de fluxo

- [ ] **EX-035** **[I]** Reescreva uma sequência de `if/elif` com guard clauses para reduzir aninhamento.
- [ ] **EX-036** **[C]** Explique exatamente como funciona um `for` em termos do protocolo de iteração.
- [ ] **EX-037** **[I]** Percorra duas coleções em paralelo com `zip` e trate explicitamente comprimentos diferentes quando isso for um erro.
- [ ] **EX-038** **[S]** Explique quando o bloco `else` de um `for` ou `while` é executado e quando não é.
- [ ] **EX-039** **[I]** Use `for ... else` para buscar um item e distinguir “encontrado” de “não encontrado” sem variável-sentinela adicional.
- [ ] **EX-040** **[C]** Diferencie `break`, `continue` e `pass`; dê um exemplo em que cada um é semanticamente apropriado.
- [ ] **EX-041** **[I]** Faça unpacking com starred target para separar primeiro elemento, miolo e último elemento de uma sequência.
- [ ] **EX-042** **[S]** Preveja o efeito de unpacking aninhado e identifique os casos que levantam `ValueError`.

# 6. Funções

- [ ] **EX-043** **[C]** Diferencie parâmetros posicionais, nomeados, positional-only e keyword-only.
- [ ] **EX-044** **[I]** Projete uma assinatura que use `/` e `*` deliberadamente para proteger uma API contra chamadas ambíguas.
- [ ] **EX-045** **[S]** Para uma assinatura contendo `/`, parâmetros comuns, `*args`, keyword-only e `**kwargs`, classifique várias chamadas como válidas ou inválidas sem executá-las.
- [ ] **EX-046** **[I]** Escreva uma função que aceite argumentos arbitrários com `*args` e `**kwargs`, mas valide uma interface mínima claramente.
- [ ] **EX-047** **[C]** Explique a diferença entre `*` em definição de função, chamada, unpacking e construção de coleções.
- [ ] **EX-048** **[D]** Corrija o clássico bug de argumento default mutável e explique por que ele ocorre.
- [ ] **EX-049** **[C]** Explique quando argumentos default são avaliados e como usar isso conscientemente, inclusive para caching/sentinels quando adequado.
- [ ] **EX-050** **[C]** Explique por que um “retorno múltiplo” é normalmente uma única tupla.
- [ ] **EX-051** **[I]** Passe uma função como argumento, armazene-a em uma estrutura e retorne outra função a partir de uma função.
- [ ] **EX-052** **[C]** Compare `lambda` com `def`: capacidades, limitações e impacto na legibilidade/debugging.
- [ ] **EX-053** **[I]** Escreva docstrings para uma função pública com parâmetros, retorno, exceções e comportamento importante.
- [ ] **EX-054** **[D]** Refatore uma função com muitos boolean flags posicionais para uma interface mais clara usando parâmetros nomeados, enums ou funções separadas.

# 7. Escopos, closures e decorators

- [ ] **EX-055** **[C]** Explique a regra LEGB e identifique em qual escopo cada nome é resolvido em um exemplo aninhado.
- [ ] **EX-056** **[S]** Preveja quando uma atribuição dentro de função cria um local e quando causa `UnboundLocalError`.
- [ ] **EX-057** **[I]** Use `global` em um exemplo mínimo e depois reestruture o código para evitar estado global desnecessário.
- [ ] **EX-058** **[I]** Use `nonlocal` para construir um contador baseado em closure.
- [ ] **EX-059** **[C]** Explique o que uma closure preserva e como inspecionar seus valores capturados.
- [ ] **EX-060** **[S]** Reproduza o problema de late binding ao criar lambdas em um laço e preveja o resultado.
- [ ] **EX-061** **[D]** Corrija late binding de duas maneiras diferentes e explique o mecanismo de cada solução.
- [ ] **EX-062** **[I]** Implemente um decorator simples de logging ou medição de tempo.
- [ ] **EX-063** **[C]** Explique a ordem de aplicação de múltiplos decorators.
- [ ] **EX-064** **[I]** Preserve nome, docstring e metadata de uma função decorada com `functools.wraps`.
- [ ] **EX-065** **[I]** Implemente um decorator parametrizado, por exemplo `@retry(times=3)` ou `@require_role(...)`.
- [ ] **EX-066** **[I]** Implemente um objeto-classe que funcione como decorator e mantenha estado entre chamadas; compare com closure.

# 8. Coleções e comprehensions

- [ ] **EX-067** **[C]** Compare lista, tupla, dict, set e frozenset em mutabilidade, ordenação, hashing e casos de uso.
- [ ] **EX-068** **[S]** Diferencie `append`, `extend`, `insert`, concatenação e unpacking ao construir listas.
- [ ] **EX-069** **[D]** Explique por que `list.sort()` atribuído a uma variável frequentemente produz um bug e compare com `sorted()`.
- [ ] **EX-070** **[C]** Explique em quais condições uma tupla é hashable.
- [ ] **EX-071** **[I]** Use unpacking de dicionários e o operador `|` para combinar configurações com precedência definida.
- [ ] **EX-072** **[C]** Explique a preservação da ordem de inserção em `dict` e por que isso não o transforma em uma estrutura ordenada por chave.
- [ ] **EX-073** **[I]** Use operações de conjunto para união, interseção, diferença e diferença simétrica em um problema de permissões ou tags.
- [ ] **EX-074** **[C]** Dê um caso real em que `frozenset` é necessário ou superior a `set`.
- [ ] **EX-075** **[I]** Transforme um laço simples em list, set e dict comprehensions adequadas.
- [ ] **EX-076** **[D]** Receba uma comprehension excessivamente complexa e refatore-a para código legível.
- [ ] **EX-077** **[I]** Use uma comprehension aninhada para achatar uma estrutura simples e depois escreva a versão com laços explícitos.
- [ ] **EX-078** **[I]** Use `Counter` para contagem e operações entre multiconjuntos.
- [ ] **EX-079** **[I]** Compare uma solução com `defaultdict`, `dict.setdefault` e verificação explícita de chave.
- [ ] **EX-080** **[I]** Use `deque` para fila eficiente e explique por que remover do início de uma lista é diferente em complexidade.
- [ ] **EX-081** **[I]** Crie um `namedtuple` e compare-o com tupla comum, `dataclass` e `NamedTuple` tipado.

# 9. Iteradores e geradores

- [ ] **EX-082** **[C]** Diferencie iterável, iterador e generator. Dê exemplos de objetos que pertencem a cada categoria.
- [ ] **EX-083** **[I]** Implemente uma classe iterável cujo `__iter__` devolva um iterador separado.
- [ ] **EX-084** **[I]** Implemente um objeto que seja seu próprio iterador com `__iter__` e `__next__`.
- [ ] **EX-085** **[S]** Explique o papel de `StopIteration` e por que normalmente não é tratado manualmente em um `for`.
- [ ] **EX-086** **[I]** Reescreva um iterador manual como generator usando `yield`.
- [ ] **EX-087** **[C]** Explique lazy evaluation e compare memória/comportamento de uma list comprehension com uma generator expression.
- [ ] **EX-088** **[I]** Construa um pipeline lazy para processar um arquivo ou fluxo grande sem carregá-lo inteiro em memória.
- [ ] **EX-089** **[I]** Use `yield from` para delegar a outro iterável/generator.
- [ ] **EX-090** **[C]** Explique `send`, `throw` e `close` em generators e identifique quando evitá-los em favor de abstrações mais simples.
- [ ] **EX-091** **[I]** Use `itertools.chain`, `islice`, `pairwise` e `product` em quatro pequenos problemas adequados.
- [ ] **EX-092** **[C]** Explique por que reutilizar um iterador já consumido pode produzir resultados inesperados.
- [ ] **EX-093** **[D]** Encontre um bug causado por testar um generator com `in` ou `list()` antes de reutilizá-lo, e corrija o fluxo.

# 10. Exceções e gerenciamento de recursos

- [ ] **EX-094** **[C]** Explique a ordem e o propósito de `try`, `except`, `else` e `finally`.
- [ ] **EX-095** **[D]** Refatore um `except Exception:` amplo para capturar somente exceções que podem ser tratadas naquele nível.
- [ ] **EX-096** **[C]** Explique a diferença entre `raise`, `raise exc` e lançar uma nova exceção.
- [ ] **EX-097** **[I]** Use exception chaining explícito com `raise NovaExcecao(...) from exc`.
- [ ] **EX-098** **[C]** Explique quando `from None` é apropriado ao converter uma exceção de baixo nível em uma exceção de domínio.
- [ ] **EX-099** **[I]** Crie uma pequena hierarquia de exceções customizadas para um domínio.
- [ ] **EX-100** **[C]** Explique `ExceptionGroup` e `except*` e dê um cenário em que múltiplas falhas independentes precisam ser preservadas.
- [ ] **EX-101** **[I]** Use `with` para garantir liberação de um recurso mesmo quando ocorre exceção.
- [ ] **EX-102** **[I]** Implemente um context manager com `__enter__` e `__exit__`, incluindo uma decisão explícita sobre suprimir ou não uma exceção.
- [ ] **EX-103** **[I]** Reimplemente o mesmo context manager com `contextlib.contextmanager`.
- [ ] **EX-104** **[I]** Use `ExitStack` para gerenciar quantidade dinâmica de recursos/context managers.
- [ ] **EX-105** **[D]** Analise código que abre vários arquivos manualmente e possui retornos antecipados; torne o gerenciamento de recursos seguro.

# 11. Módulos, pacotes e imports

- [ ] **EX-106** **[C]** Explique o que é um módulo Python e quais objetos importantes aparecem em seu namespace durante a execução.
- [ ] **EX-107** **[C]** Compare `import modulo`, `from modulo import nome` e aliases. Discuta legibilidade, colisões e monkey patching.
- [ ] **EX-108** **[I]** Monte um pacote pequeno com dois submódulos e um `__init__.py` que exponha uma API pública reduzida.
- [ ] **EX-109** **[C]** Diferencie imports absolutos e relativos e explique quando relativos tornam uma estrutura interna mais clara ou mais frágil.
- [ ] **EX-110** **[S]** Explique os possíveis valores de `__name__` quando um arquivo é executado diretamente e quando é importado.
- [ ] **EX-111** **[I]** Estruture um módulo executável usando `if __name__ == "__main__":` sem misturar a lógica de domínio com a CLI.
- [ ] **EX-112** **[C]** Explique `sys.modules` e o cache de imports. O corpo de um módulo é executado quantas vezes em imports normais?
- [ ] **EX-113** **[D]** Diagnostique um circular import entre dois módulos e resolva-o por reorganização de responsabilidades, não apenas movendo um import para dentro de uma função.
- [ ] **EX-114** **[I]** Use `importlib` para carregar dinamicamente um módulo/plugin cujo nome venha de configuração confiável.
- [ ] **EX-115** **[C]** Explique por que imports com efeitos colaterais importantes dificultam testes, inicialização e previsibilidade.

# 12. Programação orientada a objetos

- [ ] **EX-116** **[I]** Crie uma classe simples com atributos de instância, métodos e invariantes definidos no construtor.
- [ ] **EX-117** **[C]** Explique o que `self` representa e por que ele é explícito em Python.
- [ ] **EX-118** **[S]** Analise um atributo de classe mutável compartilhado por várias instâncias e preveja os efeitos de alterações feitas por cada objeto.
- [ ] **EX-119** **[C]** Diferencie atributo de classe e atributo de instância, incluindo a ordem de lookup quando ambos têm o mesmo nome.
- [ ] **EX-120** **[I]** Crie um construtor alternativo usando `@classmethod`.
- [ ] **EX-121** **[C]** Dê um caso em que `@staticmethod` faz sentido e um em que uma função de módulo seria melhor.
- [ ] **EX-122** **[C]** Explique a convenção `_nome` e o name mangling de `__nome`. Por que nenhum deles equivale a `private` de C++/Java?
- [ ] **EX-123** **[I]** Implemente uma propriedade que valide atribuições sem alterar a interface pública de leitura/escrita.
- [ ] **EX-124** **[D]** Refatore uma classe “God object” que instancia diretamente banco, logger e cliente HTTP para receber dependências externamente.
- [ ] **EX-125** **[A]** Compare herança e composição para modelar “Carro tem Motor” e “Quadrado é Retângulo”; discuta substituibilidade.
- [ ] **EX-126** **[I]** Modele um pequeno objeto de domínio por composição, mantendo responsabilidades separadas.
- [ ] **EX-127** **[A]** Identifique em um design quando uma classe está apenas agrupando funções sem possuir estado/coerência suficientes para justificar sua existência.

# 13. Modelo de dados do Python

- [ ] **EX-128** **[C]** Explique a diferença de papéis entre `__new__` e `__init__` e quando sobrescrever `__new__` é realmente necessário.
- [ ] **EX-129** **[I]** Implemente `__repr__` e `__str__` com objetivos distintos para uma classe de domínio.
- [ ] **EX-130** **[C]** Explique como `__bool__` e `__len__` participam de truthiness e qual tem precedência.
- [ ] **EX-131** **[I]** Faça um objeto container suportar `len()`, `in` e indexação de maneira coerente.
- [ ] **EX-132** **[I]** Faça uma classe customizada ser iterável sem expor diretamente sua estrutura interna.
- [ ] **EX-133** **[I]** Torne uma instância callable com `__call__` e justifique quando isso é melhor que um método nomeado.
- [ ] **EX-134** **[C]** Explique a relação entre `__eq__`, `__hash__`, mutabilidade e uso como chave de `dict`/membro de `set`.
- [ ] **EX-135** **[D]** Corrija uma classe mutável que implementa `__hash__` com base em campos que podem mudar após inserção em um set.
- [ ] **EX-136** **[I]** Implemente comparação de ordem coerente para um value object; decida entre métodos manuais, `functools.total_ordering` ou dataclass ordering.
- [ ] **EX-137** **[I]** Implemente operadores aritméticos em uma classe e lide corretamente com operandos desconhecidos retornando `NotImplemented`.
- [ ] **EX-138** **[C]** Explique a diferença entre `NotImplemented` e lançar `NotImplementedError` em um método especial.
- [ ] **EX-139** **[I]** Implemente as variantes refletidas de um operador (`__radd__`, por exemplo) quando fizer sentido.
- [ ] **EX-140** **[I]** Implemente um context manager por meio dos métodos especiais do data model.
- [ ] **EX-141** **[I]** Personalize conversões ou formatação com `__int__`, `__float__` ou `__format__` em um tipo apropriado.
- [ ] **EX-142** **[C]** Descreva, em alto nível, a sequência de busca envolvida em `obj.attr` e relacione-a a descriptors, instância e classe.
- [ ] **EX-143** **[A]** Projete um pequeno tipo “Pythonic” que se comporte como uma coleção nativa em vez de expor vários métodos `get_*` artificiais.

# 14. Herança, composição, ABCs e Protocols

- [ ] **EX-144** **[I]** Crie uma hierarquia de herança simples onde a classe derivada estenda comportamento da base com `super()`.
- [ ] **EX-145** **[C]** Explique por que `super()` não significa simplesmente “chame meu pai”. Relacione-o ao MRO.
- [ ] **EX-146** **[S]** Para uma hierarquia em diamante, determine a MRO sem executar `Class.mro()` e depois confira.
- [ ] **EX-147** **[I]** Construa uma hierarquia de herança múltipla cooperativa em que todos os `__init__` usem `super()` corretamente.
- [ ] **EX-148** **[D]** Encontre o ponto em que uma classe da cadeia chama diretamente uma base e quebra cooperative inheritance.
- [ ] **EX-149** **[A]** Decida se um problema deve usar herança múltipla, mixins ou composição e justifique o custo de cada alternativa.
- [ ] **EX-150** **[I]** Defina uma ABC com um método abstrato e implemente duas subclasses concretas.
- [ ] **EX-151** **[C]** Explique o que uma ABC oferece em runtime e o que ela comunica para leitores/type checkers.
- [ ] **EX-152** **[I]** Defina um `Protocol` estrutural e faça classes não relacionadas satisfazê-lo sem herança explícita.
- [ ] **EX-153** **[C]** Explique `@runtime_checkable`, suas limitações e por que `isinstance` contra um Protocol não valida toda a semântica da interface.
- [ ] **EX-154** **[A]** Escolha entre ABC e Protocol para uma biblioteca pública que deve aceitar implementações de terceiros.
- [ ] **EX-155** **[A]** Refatore um sistema excessivamente acoplado a uma classe concreta para depender de uma interface mínima.

# 15. Descriptors, properties e controle de atributos

- [ ] **EX-156** **[C]** Explique o protocolo descriptor: `__get__`, `__set__` e `__delete__`.
- [ ] **EX-157** **[I]** Implemente um descriptor reutilizável que valide valores positivos em vários atributos de várias classes.
- [ ] **EX-158** **[C]** Diferencie data descriptor e non-data descriptor.
- [ ] **EX-159** **[S]** Dado um atributo com mesmo nome no `__dict__` da instância e em um descriptor da classe, preveja qual valor vence para data e non-data descriptors.
- [ ] **EX-160** **[C]** Explique por que funções definidas em classes viram métodos bound ao serem acessadas por uma instância.
- [ ] **EX-161** **[S]** Inspecione `Classe.metodo` e `instancia.metodo` e explique `__self__`, `__func__` e binding.
- [ ] **EX-162** **[C]** Mostre conceitualmente por que `property` é implementável como descriptor.
- [ ] **EX-163** **[I]** Use `__getattr__` para fornecer um fallback controlado apenas para atributos inexistentes.
- [ ] **EX-164** **[D]** Implemente/logue acesso com `__getattribute__` sem causar recursão infinita.
- [ ] **EX-165** **[D]** Implemente `__setattr__` com validação sem recursão infinita.
- [ ] **EX-166** **[C]** Explique o que `__slots__` muda em layout de instâncias, `__dict__`, herança e memória.
- [ ] **EX-167** **[A]** Compare property, descriptor e simples validação explícita em método para três campos com a mesma regra de validação.

# 16. Dataclasses e modelos de dados

- [ ] **EX-168** **[I]** Transforme uma classe de dados verbosa em `@dataclass` preservando comportamento relevante.
- [ ] **EX-169** **[D]** Corrija um campo mutável compartilhado usando `field(default_factory=...)`.
- [ ] **EX-170** **[C]** Explique o que `frozen=True` garante e o que ele não torna profundamente imutável.
- [ ] **EX-171** **[I]** Combine `slots=True` com uma dataclass e avalie os efeitos na representação das instâncias.
- [ ] **EX-172** **[C]** Explique como `order=True` escolhe os campos comparados e quais pré-condições existem para gerar ordenação.
- [ ] **EX-173** **[I]** Exclua um campo de comparação/repr quando ele não fizer parte da identidade lógica do objeto.
- [ ] **EX-174** **[I]** Use `InitVar` para receber um valor necessário apenas durante a inicialização.
- [ ] **EX-175** **[I]** Use `__post_init__` para validar invariantes ou derivar um campo.
- [ ] **EX-176** **[A]** Decida entre dataclass, `NamedTuple`, dict, classe comum e Pydantic-like external validation para diferentes fronteiras de sistema.
- [ ] **EX-177** **[C]** Liste sinais de que uma dataclass deixou de ser apenas um value/data object e talvez mereça uma classe de domínio explícita.

# 17. Typing moderno

- [ ] **EX-178** **[C]** Explique o papel das type hints em Python e por que elas não fazem validação automática em runtime.
- [ ] **EX-179** **[I]** Tipifique corretamente uma função que recebe/retorna listas, dicts, sets e tuplas usando tipos built-in parametrizados.
- [ ] **EX-180** **[I]** Use a sintaxe moderna de union (`A | B`) e explique a relação com `Optional`.
- [ ] **EX-181** **[C]** Compare `Any` e `object`: que operações o type checker permite em cada caso?
- [ ] **EX-182** **[I]** Defina um type alias moderno e use-o em uma API com tipos compostos.
- [ ] **EX-183** **[I]** Escreva uma função genérica usando a sintaxe de type parameters moderna do Python 3.12+.
- [ ] **EX-184** **[I]** Restrinja um parâmetro de tipo por bound/protocolo para permitir apenas objetos com uma determinada capacidade.
- [ ] **EX-185** **[I]** Use `Literal` para restringir modos válidos de uma função e discuta quando um `Enum` seria melhor.
- [ ] **EX-186** **[C]** Diferencie `Final` e imutabilidade real em runtime.
- [ ] **EX-187** **[I]** Marque corretamente um atributo de classe com `ClassVar` em uma dataclass ou classe tipada.
- [ ] **EX-188** **[I]** Modele um payload de dicionário com `TypedDict`, incluindo campos obrigatórios e não obrigatórios.
- [ ] **EX-189** **[I]** Defina um `Protocol` genérico ou simples para desacoplar uma função de implementações concretas.
- [ ] **EX-190** **[I]** Tipifique um callback com `Callable` e identifique a limitação de `Callable[[...], ...]` para assinaturas complexas.
- [ ] **EX-191** **[I]** Use `ParamSpec` para tipar um decorator que preserve a assinatura de parâmetros da função decorada.
- [ ] **EX-192** **[I]** Use `Self` em um método fluent/factory que retorna a instância ou subtipo correto.
- [ ] **EX-193** **[C]** Explique `Never` e use `assert_never` para tornar um branch de pattern/union exaustivo para o type checker.
- [ ] **EX-194** **[I]** Demonstre narrowing com `isinstance`, `is None`, guards e controle de fluxo.
- [ ] **EX-195** **[C]** Compare `TypeGuard` e `TypeIs`, incluindo o tipo de narrowing que cada mecanismo comunica.
- [ ] **EX-196** **[D]** Receba uma função infestada de `Any` e casts; redesenhe suas fronteiras de tipos para reduzir perda de informação.
- [ ] **EX-197** **[A]** Defina onde typing estático termina e onde validação de entrada externa deve começar em uma API/web service.

# 18. Pattern matching

- [ ] **EX-198** **[I]** Use `match` para despachar valores literais e compare com uma pequena cadeia de `if/elif`.
- [ ] **EX-199** **[I]** Faça matching de uma sequência separando cabeça e cauda.
- [ ] **EX-200** **[I]** Extraia campos relevantes de um mapping pattern ignorando chaves extras.
- [ ] **EX-201** **[I]** Crie uma dataclass e use class pattern para extrair atributos.
- [ ] **EX-202** **[C]** Explique o papel de `__match_args__` no positional class matching.
- [ ] **EX-203** **[I]** Use OR patterns para combinar casos equivalentes.
- [ ] **EX-204** **[I]** Use um guard `if` em um `case` sem mover toda a lógica para dentro do pattern.
- [ ] **EX-205** **[S]** Explique por que `case nome:` captura qualquer valor em vez de comparar com uma variável existente e como comparar constantes corretamente.
- [ ] **EX-206** **[D]** Refatore um `match` usado apenas como um dicionário de dispatch para uma estrutura mais simples quando apropriado.
- [ ] **EX-207** **[A]** Dê três situações em que structural pattern matching melhora clareza e duas em que ele seria abuso.

# 19. Programação funcional

- [ ] **EX-208** **[C]** Explique funções de primeira classe e higher-order functions com exemplos da própria stdlib.
- [ ] **EX-209** **[I]** Use `map`/`filter` em um problema e escreva a versão equivalente com comprehension; escolha a mais clara e justifique.
- [ ] **EX-210** **[I]** Use `functools.partial` para adaptar uma função genérica a uma interface mais específica.
- [ ] **EX-211** **[C]** Explique `reduce` e dê um exemplo em que ele é apropriado e outro em que `sum`, `any`, `all` ou um laço é melhor.
- [ ] **EX-212** **[I]** Use `lru_cache` em uma função pura cara e teste cache hits/misses.
- [ ] **EX-213** **[C]** Compare `functools.cache` e `lru_cache`, inclusive implicações de crescimento de memória.
- [ ] **EX-214** **[I]** Implemente múltiplas versões de uma operação com `singledispatch`.
- [ ] **EX-215** **[A]** Identifique em um pipeline quais partes podem ser funções puras e quais precisam viver no “imperative shell”.

# 20. Strings, bytes e Unicode

- [ ] **EX-216** **[C]** Explique a diferença fundamental entre `str` e `bytes` e onde deve ocorrer encode/decode.
- [ ] **EX-217** **[S]** Preveja o resultado ou erro ao tentar concatenar/comparar `str` e `bytes` de formas diferentes.
- [ ] **EX-218** **[I]** Leia bytes de uma fonte, decodifique explicitamente em UTF-8, processe texto e codifique novamente na fronteira.
- [ ] **EX-219** **[I]** Use f-strings com especificadores de largura, alinhamento, precisão e formatação numérica.
- [ ] **EX-220** **[C]** Explique as flags `!r`, `!s` e `!a` em f-strings.
- [ ] **EX-221** **[C]** Explique a ideia de template strings/t-strings do Python 3.14+ e em que elas diferem conceitualmente de uma f-string imediatamente renderizada.
- [ ] **EX-222** **[C]** Explique raw strings, inclusive a limitação de terminar uma raw string com número ímpar de backslashes.
- [ ] **EX-223** **[I]** Demonstre duas strings visualmente iguais com representações Unicode diferentes e normalize-as antes de comparar.
- [ ] **EX-224** **[C]** Compare `lower()` e `casefold()` em comparação caseless de texto Unicode.
- [ ] **EX-225** **[A]** Defina uma política clara de texto/bytes para uma aplicação que lê arquivos, chama HTTP e grava dados em banco.

# 21. Arquivos, caminhos e serialização

- [ ] **EX-226** **[I]** Use `pathlib.Path` para construir caminhos, testar existência, criar diretórios e percorrer arquivos sem concatenar strings manualmente.
- [ ] **EX-227** **[C]** Explique por que `pathlib` costuma ser preferível a manipulação de caminhos com strings e onde `os` ainda é útil.
- [ ] **EX-228** **[I]** Leia e escreva texto com encoding explícito e explique por que depender do encoding default pode ser frágil.
- [ ] **EX-229** **[I]** Use `open()` em modos texto e binário e explique `r`, `w`, `a`, `x`, `b` e `+`.
- [ ] **EX-230** **[I]** Serializa e desserializa uma estrutura JSON, tratando tipos que não são representáveis diretamente.
- [ ] **EX-231** **[I]** Leia e escreva CSV com `csv.DictReader`/`DictWriter`, lidando corretamente com newline e headers.
- [ ] **EX-232** **[C]** Explique por que `pickle` não deve desserializar dados não confiáveis.
- [ ] **EX-233** **[I]** Leia configuração TOML com a stdlib e modele uma etapa separada de validação dos valores.
- [ ] **EX-234** **[I]** Use `tempfile` para criar arquivo/diretório temporário com cleanup automático.
- [ ] **EX-235** **[A]** Escolha entre JSON, CSV, TOML, pickle e formato próprio para cinco cenários distintos e justifique interoperabilidade, segurança e fidelidade de tipos.

# 22. Datas, horários e fusos

- [ ] **EX-236** **[C]** Diferencie `date`, `time`, `datetime` e `timedelta`.
- [ ] **EX-237** **[C]** Explique datetime naive versus aware e os riscos de misturá-los.
- [ ] **EX-238** **[I]** Obtenha um horário aware em UTC e converta-o para outro fuso com `zoneinfo.ZoneInfo`.
- [ ] **EX-239** **[S]** Analise um cálculo que adiciona horas perto de uma transição de horário de verão e explique por que “24 horas” e “mesma hora amanhã” podem ser conceitos diferentes.
- [ ] **EX-240** **[I]** Faça aritmética com `timedelta` e compare datas de forma timezone-aware.
- [ ] **EX-241** **[I]** Faça round-trip de um datetime por representação ISO 8601.
- [ ] **EX-242** **[C]** Explique por que `time.monotonic()` é mais adequado que relógio civil para medir duração/timeout.
- [ ] **EX-243** **[A]** Defina uma estratégia de armazenamento e apresentação de timestamps para uma aplicação usada em múltiplos fusos.

# 23. Regex

- [ ] **EX-244** **[I]** Compile um padrão reutilizado e use `search`, `match`, `fullmatch`, `findall` e `sub` conscientemente.
- [ ] **EX-245** **[C]** Diferencie grupo de captura, grupo não capturante e grupo nomeado.
- [ ] **EX-246** **[I]** Extraia partes de uma linha estruturada usando grupos nomeados e converta os valores para tipos apropriados.
- [ ] **EX-247** **[D]** Corrija uma regex que usa `.*` de forma gananciosa demais.
- [ ] **EX-248** **[C]** Explique quando usar `re.escape` em conteúdo que será incorporado a um padrão.
- [ ] **EX-249** **[A]** Receba a tarefa “parsear HTML/JSON/linguagem de programação com regex” e explique por que uma parser/biblioteca específica normalmente é a abstração adequada.

# 24. Concorrência, paralelismo e asyncio

- [ ] **EX-250** **[C]** Diferencie concorrência e paralelismo com exemplos concretos.
- [ ] **EX-251** **[A]** Para tarefas CPU-bound e I/O-bound, escolha entre código síncrono, threads, processos e asyncio e justifique.
- [ ] **EX-252** **[I]** Execute várias operações I/O-bound com `threading` ou `ThreadPoolExecutor` e agregue seus resultados.
- [ ] **EX-253** **[C]** Explique race condition e implemente um exemplo mínimo que exija sincronização.
- [ ] **EX-254** **[I]** Proteja uma região crítica com `Lock`; depois identifique como reduzir o tamanho da região crítica.
- [ ] **EX-255** **[C]** Explique o GIL no CPython tradicional e por que ele não elimina a necessidade de locks.
- [ ] **EX-256** **[C]** Explique o que muda e o que não muda com builds free-threaded de CPython moderno.
- [ ] **EX-257** **[I]** Compare `ThreadPoolExecutor` e `ProcessPoolExecutor` usando uma função I/O-bound e uma CPU-bound.
- [ ] **EX-258** **[C]** Explique custos e restrições de multiprocessing: serialização, startup, memória e estado compartilhado.
- [ ] **EX-259** **[I]** Escreva uma coroutine simples e execute-a com `asyncio.run`.
- [ ] **EX-260** **[C]** Explique a diferença entre chamar uma função `async def`, criar uma coroutine object, agendá-la como task e aguardá-la.
- [ ] **EX-261** **[I]** Crie múltiplas tasks e aguarde-as concorrentemente.
- [ ] **EX-262** **[I]** Compare `asyncio.gather` com `TaskGroup`, especialmente em propagação/cancelamento de falhas.
- [ ] **EX-263** **[I]** Use timeout em uma operação async e trate o caso de expiração sem deixar recursos abandonados.
- [ ] **EX-264** **[C]** Explique cancelamento cooperativo em asyncio e o papel de `CancelledError`.
- [ ] **EX-265** **[D]** Encontre uma chamada bloqueante (`time.sleep`, I/O síncrono pesado etc.) dentro de código async e corrija-a com API assíncrona ou offloading adequado.
- [ ] **EX-266** **[I]** Implemente um async iterator e consuma-o com `async for`.
- [ ] **EX-267** **[I]** Implemente ou use um async context manager com `async with`.
- [ ] **EX-268** **[C]** Explique a motivação dos subinterpreters e como eles se diferenciam conceitualmente de threads e processos.
- [ ] **EX-269** **[A]** Desenhe a estratégia de concorrência de um crawler que faz milhares de requisições, parsing moderado e etapas CPU-bound ocasionais.

# 25. Subprocessos e interação com o sistema

- [ ] **EX-270** **[I]** Execute um comando simples com `subprocess.run`, capture stdout/stderr e verifique o exit status.
- [ ] **EX-271** **[C]** Explique por que uma lista de argumentos costuma ser preferível a uma única string de shell.
- [ ] **EX-272** **[D]** Corrija código vulnerável a shell injection que interpola input do usuário em um comando.
- [ ] **EX-273** **[C]** Explique quando `shell=True` é realmente necessário e quais responsabilidades extras ele impõe.
- [ ] **EX-274** **[I]** Passe um ambiente modificado a um subprocesso sem destruir desnecessariamente o ambiente herdado.
- [ ] **EX-275** **[I]** Use `shutil` para copiar, mover e remover arquivos/diretórios de forma apropriada.
- [ ] **EX-276** **[A]** Escolha entre API Python nativa, `os`, `shutil` e subprocesso externo para quatro tarefas de sistema.
- [ ] **EX-277** **[D]** Torne robusto um wrapper de CLI: timeout, códigos de retorno, encoding, stderr e erro de executável ausente.

# 26. Introspecção, metaprogramação e metaclasses

- [ ] **EX-278** **[I]** Inspecione tipo, atributos, MRO e namespace de objetos/classes usando ferramentas básicas como `type`, `dir`, `vars` e `getattr`.
- [ ] **EX-279** **[I]** Use `inspect.signature` para examinar parâmetros de uma callable.
- [ ] **EX-280** **[I]** Use `inspect` para detectar funções, métodos ou coroutines em uma pequena ferramenta de introspecção.
- [ ] **EX-281** **[C]** Explique a frase “classes são objetos e normalmente instâncias de `type`”.
- [ ] **EX-282** **[I]** Crie dinamicamente uma classe com `type(name, bases, namespace)` e compare com a sintaxe `class`.
- [ ] **EX-283** **[C]** Explique em que etapas uma metaclass participa da criação de classes.
- [ ] **EX-284** **[I]** Implemente uma metaclass mínima que registre subclasses/classes criadas.
- [ ] **EX-285** **[A]** Reescreva um uso simples de metaclass com `__init_subclass__` e avalie qual solução é mais simples.
- [ ] **EX-286** **[I]** Use `__init_subclass__` para validar ou registrar subclasses automaticamente.
- [ ] **EX-287** **[C]** Explique para que serve `__class_getitem__` e sua relação com sintaxe como `MinhaClasse[T]`.
- [ ] **EX-288** **[C]** Explique em alto nível o propósito de `__mro_entries__` e por que ele é um recurso avançado raro.
- [ ] **EX-289** **[A]** Liste critérios concretos para decidir que um problema realmente justifica metaprogramação em vez de código explícito.

# 27. Memória, garbage collector e cópias

- [ ] **EX-290** **[C]** Explique contagem de referências no CPython e por que ela não resolve sozinha ciclos.
- [ ] **EX-291** **[I]** Crie um ciclo de referências e use `gc` para inspecionar/coletar objetos relacionados.
- [ ] **EX-292** **[C]** Explique a função do garbage collector cíclico e por que detalhes de coleta não devem ser usados como contrato portátil da linguagem.
- [ ] **EX-293** **[I]** Use `weakref` em um cache/registro que não deve manter objetos vivos sozinho.
- [ ] **EX-294** **[C]** Diferencie referência forte e fraca e dê dois casos de uso de referências fracas.
- [ ] **EX-295** **[S]** Preveja o resultado de `copy.copy` em uma lista aninhada e identifique quais níveis continuam compartilhados.
- [ ] **EX-296** **[S]** Compare o mesmo exemplo com `copy.deepcopy` e discuta objetos que não devem/precisam ser copiados profundamente.
- [ ] **EX-297** **[D]** Corrija um bug causado por cópia rasa de configuração aninhada antes de mutações locais.
- [ ] **EX-298** **[C]** Explique por que depender de `__del__` ou destruição imediata para fechar recursos é frágil.
- [ ] **EX-299** **[A]** Escolha entre cópia, imutabilidade, compartilhamento deliberado e copy-on-write conceitual para um objeto grande usado em múltiplas etapas.

# 28. Performance e profiling

- [ ] **EX-300** **[C]** Explique por que melhorar complexidade assintótica costuma superar micro-otimizações de sintaxe.
- [ ] **EX-301** **[D]** Substitua uma busca repetida em lista por uma estrutura mais apropriada e analise a complexidade antes/depois.
- [ ] **EX-302** **[I]** Use `timeit` para comparar duas implementações pequenas sem tirar conclusões a partir de uma única execução manual.
- [ ] **EX-303** **[I]** Use `cProfile` para encontrar hotspots de um programa e diferencie tempo cumulativo de tempo próprio.
- [ ] **EX-304** **[C]** Faça um “profile mental” de um pipeline: I/O, alocações, loops Python, chamadas de rede e serialização. Diga o que mediria primeiro.
- [ ] **EX-305** **[I]** Compare um laço Python com um built-in equivalente (`sum`, `min`, `join`, etc.) e meça quando fizer sentido.
- [ ] **EX-306** **[C]** Compare generator e lista em memória, reuso, latência e custo total; explique por que generator não é automaticamente mais rápido.
- [ ] **EX-307** **[C]** Avalie quando `__slots__` pode economizar memória e por que isso raramente deve ser a primeira otimização.
- [ ] **EX-308** **[A]** Explique quando vetorização, extensão nativa ou biblioteca especializada pode superar otimização de loops Python.
- [ ] **EX-309** **[A]** Receba uma tarefa lenta e escreva uma ordem de investigação baseada em medição antes de escolher threads/processos/async/cache.

# 29. Testes

- [ ] **EX-310** **[A]** Organize uma estrutura de testes para um pacote com código em layout `src`.
- [ ] **EX-311** **[I]** Escreva um teste equivalente usando `unittest` e `pytest`; compare boilerplate e recursos.
- [ ] **EX-312** **[I]** Parametrize vários casos de uma função pura.
- [ ] **EX-313** **[I]** Crie uma fixture para um recurso temporário e garanta teardown apropriado.
- [ ] **EX-314** **[I]** Use mocking para substituir uma fronteira externa (HTTP, relógio, filesystem ou e-mail), não uma função interna arbitrária.
- [ ] **EX-315** **[D]** Refatore um teste que mocka quase todas as chamadas internas e quebra após qualquer refatoração.
- [ ] **EX-316** **[C]** Diferencie unit test, integration test, end-to-end e teste de contrato em termos de escopo e confiança.
- [ ] **EX-317** **[A]** Escolha quais partes de um serviço precisam de testes unitários e quais merecem teste de integração com banco real/efêmero.
- [ ] **EX-318** **[C]** Explique “teste comportamento, não implementação” com um exemplo em que verificar chamadas internas é prejudicial.
- [ ] **EX-319** **[I]** Teste uma função que levanta exceção, incluindo mensagem ou atributos relevantes sem acoplar demais o teste.
- [ ] **EX-320** **[I]** Teste código dependente de tempo ou aleatoriedade injetando a dependência em vez de usar sleeps/retries instáveis.
- [ ] **EX-321** **[D]** Diagnostique um teste flaky e proponha como remover dependência de ordem, tempo, rede ou estado global.

# 30. Logging

- [ ] **EX-322** **[I]** Configure logging básico de uma aplicação sem espalhar `print()` por código de biblioteca.
- [ ] **EX-323** **[C]** Explique quando usar DEBUG, INFO, WARNING, ERROR e CRITICAL.
- [ ] **EX-324** **[I]** Registre uma exceção preservando traceback com a API adequada do logger.
- [ ] **EX-325** **[C]** Explique lazy formatting de logging e compare `logger.info("x=%s", x)` com interpolação antecipada.
- [ ] **EX-326** **[D]** Identifique e remova segredos/PII sensível de logs de autenticação ou requests.
- [ ] **EX-327** **[A]** Projete campos de logging estruturado para request id, tenant, operação, duração e resultado.
- [ ] **EX-328** **[D]** Corrija uma biblioteca que chama `basicConfig` globalmente ao ser importada.
- [ ] **EX-329** **[A]** Defina a diferença entre logs, métricas e traces e escolha o sinal principal para quatro tipos de incidente.

# 31. Packaging, ambientes e projetos

- [ ] **EX-330** **[I]** Crie e ative um virtual environment, instale uma dependência e explique o que o ambiente isola e o que não isola.
- [ ] **EX-331** **[C]** Explique a diferença entre instalar uma distribuição/pacote e importar um módulo; os nomes precisam ser iguais?
- [ ] **EX-332** **[I]** Esboce um `pyproject.toml` mínimo com metadados e sistema de build.
- [ ] **EX-333** **[A]** Explique as vantagens e os custos do layout `src/` em comparação com pacote no diretório raiz.
- [ ] **EX-334** **[I]** Faça uma instalação editable de um projeto local e explique o fluxo de desenvolvimento que ela habilita.
- [ ] **EX-335** **[C]** Diferencie dependências de runtime, desenvolvimento/teste e opcionais.
- [ ] **EX-336** **[C]** Explique o problema que lockfiles tentam resolver e diferencie biblioteca reutilizável de aplicação quanto ao pinning de dependências.
- [ ] **EX-337** **[I]** Defina um CLI entry point no projeto sem exigir que o usuário invoque diretamente um arquivo `.py`.
- [ ] **EX-338** **[I]** Faça um pacote executável com `python -m pacote` usando `__main__.py`.
- [ ] **EX-339** **[A]** Desenhe a estrutura de diretórios de um pacote publicável com fonte, testes, documentação e configuração de ferramentas.
- [ ] **EX-340** **[D]** Diagnostique um projeto que “funciona apenas quando executado da raiz” por imports/path hacks e corrija seu packaging.
- [ ] **EX-341** **[C]** Explique por que editar `sys.path` dentro do código de aplicação normalmente indica um problema estrutural.

# 32. Qualidade de código e estilo

- [ ] **EX-342** **[C]** Explique os papéis distintos de formatter, linter e type checker.
- [ ] **EX-343** **[C]** Resuma o propósito de PEP 8 e PEP 257 sem tratar nenhuma delas como substituto de bom design.
- [ ] **EX-344** **[D]** Refatore nomes vagos como `data`, `temp`, `x`, `manager` e `utils` em um trecho onde nomes de domínio possam tornar o código autoexplicativo.
- [ ] **EX-345** **[D]** Divida uma função longa porque ela contém responsabilidades distintas, não simplesmente para atingir um limite arbitrário de linhas.
- [ ] **EX-346** **[A]** Identifique um caso em que fragmentar demais uma sequência linear de lógica piora a leitura.
- [ ] **EX-347** **[D]** Troque comentários que narram “o que” o código faz por nomes/estrutura claros e preserve apenas comentários que expliquem “por quê”.
- [ ] **EX-348** **[I]** Escreva uma docstring útil para uma API pública sem repetir linha a linha a implementação.
- [ ] **EX-349** **[A]** Monte um conjunto mínimo de checks de qualidade para CI de um projeto Python moderno e justifique cada ferramenta/categoria.

# 33. Segurança e armadilhas comuns

- [ ] **EX-350** **[C]** Explique por que `eval`/`exec` sobre input não confiável é execução de código e não mero parsing.
- [ ] **EX-351** **[D]** Substitua um uso de `eval` para ler dados simples por parser seguro apropriado.
- [ ] **EX-352** **[C]** Explique o risco de desserialização arbitrária com pickle e onde uma origem “confiável” ainda pode deixar de ser confiável.
- [ ] **EX-353** **[D]** Corrija uma query SQL construída por concatenação/interpolação usando parâmetros da biblioteca de banco.
- [ ] **EX-354** **[D]** Corrija uma chamada de shell construída com input externo e remova `shell=True` se não for necessário.
- [ ] **EX-355** **[A]** Defina como uma aplicação deve receber e armazenar secrets sem commitá-los no repositório ou imprimi-los em logs.
- [ ] **EX-356** **[S]** Explique novamente o bug de mutable default arguments e reconheça uma situação em que estado persistente em default foi intencional, porém pouco legível.
- [ ] **EX-357** **[S]** Preveja o comportamento de `matrix = [[0] * 3] * 3` após alterar `matrix[0][0]` e explique o aliasing.
- [ ] **EX-358** **[I]** Construa a matriz anterior corretamente sem compartilhar linhas.
- [ ] **EX-359** **[D]** Substitua comparações `is`/`is not` incorretas, preservando o uso correto para sentinels como `None`.
- [ ] **EX-360** **[D]** Corrija código que remove/adiciona itens à mesma coleção durante sua iteração e explique os riscos.
- [ ] **EX-361** **[D]** Encontre um `except Exception: pass` que mascara falhas e redesenhe tratamento, logging ou propagação.
- [ ] **EX-362** **[C]** Explique por que `assert` não deve validar input externo nem invariantes que precisam sobreviver a execução otimizada.
- [ ] **EX-363** **[D]** Corrija uma aplicação que mistura datetimes naive e aware.
- [ ] **EX-364** **[C]** Explique por que dinheiro normalmente não deve ser representado por `float`; implemente uma alternativa com `Decimal` ou unidades inteiras.
- [ ] **EX-365** **[D]** Remova efeitos colaterais pesados de import de um módulo e mova inicialização para uma fronteira explícita.

# 34. Recursos modernos do Python 3.12–3.14

- [ ] **EX-366** **[I]** Reescreva uma classe/função genérica antiga baseada em `TypeVar` para a sintaxe de type parameters do Python 3.12+ quando apropriado.
- [ ] **EX-367** **[C]** Explique por que a nova sintaxe genérica pode tornar a declaração mais local e legível sem mudar a natureza runtime dos tipos.
- [ ] **EX-368** **[I]** Escreva uma f-string usando expressões que eram mais restritas em versões antigas e verifique a versão mínima necessária.
- [ ] **EX-369** **[C]** Descreva as melhorias do REPL moderno e separe ergonomia de REPL de mudanças semânticas da linguagem.
- [ ] **EX-370** **[C]** Compare o estado do free-threaded CPython em 3.13 e 3.14 e explique por que “sem GIL” não significa “todo programa ganha paralelismo automaticamente”.
- [ ] **EX-371** **[A]** Liste bibliotecas/extensões que você verificaria antes de migrar uma aplicação para um build free-threaded.
- [ ] **EX-372** **[C]** Explique deferred evaluation de annotations no Python moderno e como isso afeta ferramentas que introspectam anotações em runtime.
- [ ] **EX-373** **[I]** Compare uma f-string e uma template string do Python 3.14+ em um caso onde preservar estrutura/interpolações seja útil.
- [ ] **EX-374** **[C]** Explique o problema que subinterpreters tentam resolver e suas fronteiras de isolamento/compartilhamento.
- [ ] **EX-375** **[I]** Identifique a API de stdlib moderna para trabalhar com Zstandard e compare o caso de uso com gzip/lzma em alto nível.
- [ ] **EX-376** **[A]** Defina a versão mínima de Python de um pacote fictício e decida quais recursos modernos podem ser usados sem fallback.
- [ ] **EX-377** **[D]** Receba código moderno que precisa rodar em 3.11 e identifique cada construção incompatível, propondo equivalentes quando possível.

# 35. Idiomas Pythonic

- [ ] **EX-378** **[D]** Reescreva um laço baseado em índices desnecessários para iterar diretamente sobre valores.
- [ ] **EX-379** **[I]** Use `enumerate` quando índice e valor são realmente necessários.
- [ ] **EX-380** **[I]** Use `zip` para percorrer estruturas paralelas e explique quando `strict=True` é útil.
- [ ] **EX-381** **[I]** Faça swap de duas variáveis sem temporária e explique o unpacking envolvido.
- [ ] **EX-382** **[D]** Troque uma cadeia de comparações `x == a or x == b...` por membership em estrutura adequada.
- [ ] **EX-383** **[D]** Simplifique testes explícitos como `len(items) > 0` e `flag == True` quando truthiness expressa corretamente a intenção.
- [ ] **EX-384** **[I]** Use `any` para detectar se pelo menos um item satisfaz uma condição com curto-circuito.
- [ ] **EX-385** **[I]** Use `all` para validar uma propriedade de todos os elementos e explique o resultado em iterável vazio.
- [ ] **EX-386** **[I]** Use `next(iterator, default)` para uma busca simples sem `try/except StopIteration` explícito.
- [ ] **EX-387** **[I]** Compare `dict.get`, acesso direto e tratamento de `KeyError`; escolha conforme ausência seja normal ou excepcional.
- [ ] **EX-388** **[C]** Compare `setdefault` e `defaultdict`, incluindo efeitos colaterais de criar a chave.
- [ ] **EX-389** **[I]** Faça merge de dicts com `|` e `**`, explicando precedência de chaves repetidas.
- [ ] **EX-390** **[D]** Substitua fechamento manual de arquivo/recurso por context manager.
- [ ] **EX-391** **[A]** Decida quando uma comprehension permanece legível e quando deve virar loop explícito.
- [ ] **EX-392** **[D]** Migre manipulação manual de paths baseada em strings para `pathlib`.
- [ ] **EX-393** **[I]** Modele um value object imutável/semimutável com dataclass e invariantes claros.
- [ ] **EX-394** **[D]** Refatore código profundamente aninhado usando guard clauses.
- [ ] **EX-395** **[D]** Transforme verificações prévias frágeis de arquivo/chave/atributo em EAFP quando isso evitar condições de corrida ou duplicação.
- [ ] **EX-396** **[D]** Substitua chamadas como `connect(host, True, False, 3)` por argumentos nomeados ou uma API mais expressiva.
- [ ] **EX-397** **[A]** Pegue um trecho “Java/C++ escrito em Python” com getters, setters, loops indexados e factories desnecessárias e torne-o idiomático sem sacrificar clareza.

# 36. Padrões arquiteturais úteis em Python

- [ ] **EX-398** **[I]** Defina uma porta de armazenamento como `Protocol` e injete duas implementações em um serviço.
- [ ] **EX-399** **[A]** Explique dependency inversion em termos de direção de dependências, não em termos de “usar interfaces em todo lugar”.
- [ ] **EX-400** **[I]** Implemente um Repository mínimo que esconda detalhes de persistência de uma camada de domínio.
- [ ] **EX-401** **[A]** Identifique quando Repository apenas duplica sem valor uma API já suficientemente abstrata do storage.
- [ ] **EX-402** **[I]** Implemente uma service layer que coordene duas dependências e mantenha regras fora de handlers HTTP/CLI.
- [ ] **EX-403** **[I]** Crie um value object que valide invariantes no momento da construção e evite `str`/`int` sem semântica espalhados pelo domínio.
- [ ] **EX-404** **[I]** Implemente Strategy com funções ou objetos intercambiáveis; compare ambas as formas.
- [ ] **EX-405** **[I]** Implemente uma Factory quando a escolha/criação concreta exigir lógica suficiente para justificar a abstração.
- [ ] **EX-406** **[I]** Crie um Registry para plugins/handlers e evite um grande `if/elif` central.
- [ ] **EX-407** **[I]** Escreva um Adapter que converta a API de um cliente externo para uma interface interna estável.
- [ ] **EX-408** **[A]** Separe command e query em uma API onde uma função atualmente modifica estado e retorna múltiplas visões do sistema ao mesmo tempo.
- [ ] **EX-409** **[I]** Modele um domain event imutável e um mecanismo simples de publicação/consumo sem acoplá-lo a um broker específico.
- [ ] **EX-410** **[C]** Explique “functional core, imperative shell” e classifique funções de um pequeno sistema entre núcleo e fronteira.
- [ ] **EX-411** **[A]** Compare exceções, valores de resultado e eventos para comunicar diferentes tipos de resultado/falha entre camadas.
- [ ] **EX-412** **[D]** Refatore uma camada de domínio que importa framework web, ORM e cliente HTTP diretamente.
- [ ] **EX-413** **[A]** Dado um projeto de 1.000 linhas, argumente quais desses padrões você deliberadamente não introduziria ainda e por quê.

# 37. Biblioteca padrão — mapa mental

- [ ] **EX-414** **[C]** Para operações de sistema/arquivos, associe problemas a `pathlib`, `os`, `shutil`, `tempfile` e `subprocess` sem consultar o índice.
- [ ] **EX-415** **[C]** Para estruturas de dados, associe problemas a `collections`, `heapq`, `bisect`, `array` e `queue` quando apropriado.
- [ ] **EX-416** **[C]** Para pipelines de iteração/funcional, associe problemas a `itertools`, `functools` e `operator`.
- [ ] **EX-417** **[C]** Para texto, associe casos de uso a `re`, `string`, `textwrap`, `difflib` e módulos de Unicode quando necessário.
- [ ] **EX-418** **[C]** Para serialização/configuração, compare mentalmente `json`, `csv`, `tomllib`, `pickle` e módulos relacionados.
- [ ] **EX-419** **[C]** Para compressão/arquivos compactados, identifique quando procurar `gzip`, `bz2`, `lzma`, `zipfile`, `tarfile` e suporte Zstandard moderno.
- [ ] **EX-420** **[C]** Para datas/números, associe `datetime`, `zoneinfo`, `decimal`, `fractions`, `statistics`, `math` e `random` aos seus domínios.
- [ ] **EX-421** **[C]** Para concorrência, compare mentalmente `threading`, `multiprocessing`, `concurrent.futures`, `asyncio`, `queue` e subinterpreters.
- [ ] **EX-422** **[C]** Para rede/protocolos, identifique módulos da stdlib que você procuraria antes de adicionar dependência externa para URL/HTTP básico/socket/e-mail.
- [ ] **EX-423** **[C]** Para introspecção/programação dinâmica, associe problemas a `inspect`, `importlib`, `types`, `dataclasses`, `enum` e `abc`.
- [ ] **EX-424** **[C]** Para teste/debug, associe problemas a `unittest`, `unittest.mock`, `doctest`, `pdb`, `traceback`, `timeit` e `cProfile`.
- [ ] **EX-425** **[C]** Para configuração/logging/segurança básica, explique quando recorrer a `logging`, `configparser`, `secrets`, `hashlib` e `hmac`.
- [ ] **EX-426** **[I]** Escolha cinco módulos da stdlib que você usa pouco e construa um exemplo mínimo de cada um apenas consultando a documentação oficial depois de tentar lembrar a API.
- [ ] **EX-427** **[A]** Para dez problemas pequenos, decida primeiro se a stdlib já possui uma solução antes de sugerir dependência externa.

# 38. Checklist de revisão profissional

- [ ] **EX-428** **[A]** Revise uma API sua e verifique se nomes, assinaturas, tipos de retorno e exceções formam um contrato coerente.
- [ ] **EX-429** **[A]** Identifique todos os estados mutáveis de um módulo e classifique-os como local, instância, cache, global ou persistente; justifique cada um.
- [ ] **EX-430** **[A]** Faça um mapa das exceções de uma operação: quais são tratáveis localmente, quais devem ser traduzidas e quais devem propagar.
- [ ] **EX-431** **[A]** Liste todos os recursos adquiridos por uma operação (arquivos, conexões, locks, tasks, processos) e prove que cada um é liberado em sucesso e falha.
- [ ] **EX-432** **[A]** Revise as estruturas de dados escolhidas em um trecho e verifique se refletem operações predominantes e complexidade necessária.
- [ ] **EX-433** **[A]** Revise uma área concorrente e identifique estado compartilhado, cancelamento, timeout, backpressure e comportamento em falha parcial.
- [ ] **EX-434** **[A]** Antes de otimizar uma função, escreva hipótese, métrica, benchmark/profile e critério de sucesso.
- [ ] **EX-435** **[A]** Faça threat-model mínimo de uma entrada externa: parsing, comandos, SQL, paths, desserialização, secrets e logs.
- [ ] **EX-436** **[A]** Verifique se uma unidade difícil de testar está acoplada a relógio, rede, filesystem, aleatoriedade ou globais e introduza fronteiras somente onde necessário.
- [ ] **EX-437** **[A]** Verifique se o pacote pode ser instalado do zero em ambiente limpo sem manipulações manuais de path.
- [ ] **EX-438** **[A]** Faça uma revisão final buscando complexidade acidental: abstrações não usadas, wrappers triviais, classes sem estado e metaprogramação desnecessária.
- [ ] **EX-439** **[A]** Pegue um módulo antigo seu e produza um relatório de revisão usando todos os itens anteriores antes de tocar no código.

# 39. Dunder methods e protocolos — revisão concentrada

Sem consultar o apêndice da masterclass, responda quais métodos especiais participam de cada comportamento e implemente alguns deles em tipos pequenos.

- [ ] **EX-440** **[C]** Construção/inicialização de instâncias: diferencie `__new__` e `__init__`.
- [ ] **EX-441** **[C]** Representação textual: diferencie `__repr__`, `__str__` e `__format__`.
- [ ] **EX-442** **[C]** Truthiness e tamanho: relacione `__bool__` e `__len__`.
- [ ] **EX-443** **[C]** Containers: relacione `__getitem__`, `__setitem__`, `__delitem__` e `__contains__`.
- [ ] **EX-444** **[C]** Iteração: relacione `__iter__`, `__next__` e a alternativa por sequência onde aplicável.
- [ ] **EX-445** **[C]** Callables: explique `__call__`.
- [ ] **EX-446** **[C]** Comparações: enumere os rich comparison methods e explique retorno de `NotImplemented`.
- [ ] **EX-447** **[C]** Hashing: explique o contrato entre `__eq__` e `__hash__`.
- [ ] **EX-448** **[C]** Operadores: diferencie métodos normais, refletidos e in-place como `__add__`, `__radd__`, `__iadd__`.
- [ ] **EX-449** **[C]** Context managers síncronos e assíncronos: identifique seus quatro métodos principais.
- [ ] **EX-450** **[C]** Attribute access: diferencie `__getattribute__`, `__getattr__`, `__setattr__` e `__delattr__`.
- [ ] **EX-451** **[C]** Descriptors: recite e explique `__get__`, `__set__`, `__delete__` e `__set_name__`.
- [ ] **EX-452** **[C]** Classes/metaprogramação: explique `__init_subclass__`, `__class_getitem__` e, em alto nível, `__mro_entries__`.
- [ ] **EX-453** **[I]** Crie uma classe que implemente pelo menos oito desses métodos especiais de forma coerente, sem adicioná-los apenas “porque pode”.

# 40. Escolha de abstrações

- [ ] **EX-454** **[A]** Para um conjunto fixo de valores com identidade semântica, escolha entre string constants, `Literal` e `Enum`.
- [ ] **EX-455** **[A]** Para um registro simples de dados, escolha entre dict, `TypedDict`, `NamedTuple`, dataclass e classe comum.
- [ ] **EX-456** **[A]** Para comportamento intercambiável, escolha entre função, closure, callable object, Strategy e `singledispatch`.
- [ ] **EX-457** **[A]** Para interface compartilhada, escolha entre duck typing documentado, Protocol e ABC.
- [ ] **EX-458** **[A]** Para validação de atributos, escolha entre método explícito, property e descriptor.
- [ ] **EX-459** **[A]** Para extensão automática de classes, escolha entre decorator de classe, `__init_subclass__` e metaclass.
- [ ] **EX-460** **[A]** Para coleção de resultados produzidos sob demanda, escolha entre list, generator, iterator customizado e async iterator.
- [ ] **EX-461** **[A]** Para executar trabalho simultâneo, escolha entre threads, processos, asyncio e execução serial.
- [ ] **EX-462** **[A]** Para erros esperados, escolha entre sentinel/`None`, exceção específica e objeto de resultado.
- [ ] **EX-463** **[A]** Para compartilhar estado, compare objeto mutável, objeto imutável, cópia, cache e armazenamento persistente.
- [ ] **EX-464** **[A]** Para plugin architecture, compare registry explícito, imports dinâmicos e mecanismos de entry points do packaging.
- [ ] **EX-465** **[A]** Para cada escolha acima, descreva qual informação adicional faria você mudar de decisão.

# 41. Desafios integradores

Estes exercícios deliberadamente misturam vários capítulos. Não há uma única arquitetura correta; o objetivo é conseguir justificar cada decisão.

- [ ] **EX-466** **[A/I]** Implemente uma pequena biblioteca de `Money`: use `Decimal` ou unidade inteira, moeda explícita, igualdade/hash coerentes, operadores seguros, `repr`, formatação, typing e testes de invariantes.
- [ ] **EX-467** **[A/I]** Implemente uma coleção `EventLog` customizada que seja iterável, suporte `len`, membership, slicing quando fizer sentido, representação útil e serialização JSON na fronteira.
- [ ] **EX-468** **[A/I]** Crie um sistema de plugins no qual plugins satisfaçam um `Protocol`, sejam registrados sem grande `if/elif`, possam ser carregados dinamicamente e tenham erros de inicialização isolados.
- [ ] **EX-469** **[A/I]** Escreva um decorator `retry` profissional: `ParamSpec`, `TypeVar`, `wraps`, política de exceções, backoff injetável, logging e testes sem `sleep` real.
- [ ] **EX-470** **[A/I]** Implemente uma versão síncrona e uma assíncrona de um cliente que consulta várias URLs. Compare interfaces, timeout, concorrência, cancelamento e teste das duas versões.
- [ ] **EX-471** **[A/I]** Construa um pipeline lazy que percorra arquivos grandes, normalize Unicode, filtre linhas por regex, converta registros e grave saída incrementalmente com context managers.
- [ ] **EX-472** **[A/I]** Implemente uma mini CLI empacotada com `pyproject.toml`, entry point, `argparse` ou equivalente de stdlib, logging, exit codes e testes da camada de domínio sem executar subprocessos reais.
- [ ] **EX-473** **[A/I]** Crie um cache LRU para resultados puros, meça impacto com `timeit`/profiling e explique comportamento de memória e invalidação.
- [ ] **EX-474** **[A/I]** Modele uma fila de jobs com dataclasses, enums, Protocol de executor, repository em memória, service layer e eventos de domínio.
- [ ] **EX-475** **[A/I]** Torne o sistema de jobs anterior concorrente para tarefas I/O-bound, definindo explicitamente sincronização, shutdown, falhas parciais e backpressure.
- [ ] **EX-476** **[A/I]** Faça uma variante CPU-bound do sistema anterior e justifique a troca para processos ou outra estratégia, medindo em vez de assumir ganho.
- [ ] **EX-477** **[A/I]** Implemente um parser de configuração TOML que converta dados externos em dataclasses/value objects tipados e produza exceções de configuração com chaining útil.
- [ ] **EX-478** **[A/I]** Construa um cliente de subprocesso seguro que execute uma ferramenta externa, nunca concatene input ao shell, controle ambiente, timeout, encoding, stdout/stderr e traduza erros para exceções de domínio.
- [ ] **EX-479** **[A/I]** Escreva um descriptor `Field` reutilizável com validação e `__set_name__`; compare a solução final com dataclass + `__post_init__` e properties.
- [ ] **EX-480** **[A/I]** Implemente uma hierarquia em diamante com mixins cooperativos; prove a ordem do MRO e escreva um teste que detectaria uma chamada direta à classe-base quebrando a cadeia.
- [ ] **EX-481** **[A/I]** Crie uma API baseada em Protocols que aceite tanto uma classe real quanto um fake de teste sem herança compartilhada.
- [ ] **EX-482** **[A/I]** Modele mensagens de comandos diferentes com dataclasses e processe-as com pattern matching exaustivo, guards e `assert_never` onde o type checker possa ajudar.
- [ ] **EX-483** **[A/I]** Escreva um registry baseado em `__init_subclass__`; depois reimplemente com decorator de classe e compare transparência, import side effects e testabilidade.
- [ ] **EX-484** **[A/I]** Implemente uma estrutura de cache com `weakref` e demonstre em teste que objetos podem ser coletados quando não possuem referências fortes externas.
- [ ] **EX-485** **[A/I]** Faça um experimento de shallow/deep copy com grafo de objetos e escreva invariantes sobre quais referências devem ser compartilhadas ou duplicadas.
- [ ] **EX-486** **[A/I]** Construa um serviço que registra logs estruturados sem vazar secrets; injete request id/contexto e teste que informações sensíveis não aparecem.
- [ ] **EX-487** **[A/I]** Crie testes unitários, de integração e de contrato para a mesma funcionalidade e explique que tipo de falha cada camada detecta melhor.
- [ ] **EX-488** **[A/I]** Pegue uma função que usa `Any`, dicts heterogêneos e retornos ambíguos; evolua-a para TypedDicts/value objects, Protocols e unions discriminadas sem tornar a API artificialmente complexa.
- [ ] **EX-489** **[A/I]** Construa um módulo que funcione em Python 3.12–3.14 e isole opcionalmente uma feature exclusiva do 3.14 sem quebrar import em versões anteriores.
- [ ] **EX-490** **[A/I]** Faça benchmark de um workload com execução serial, threads e processos. Documente CPU, I/O, overhead e por que a opção vencedora venceu naquele caso.
- [ ] **EX-491** **[A/I]** Faça um equivalente async do benchmark para workload I/O-bound e investigue o ponto em que aumentar concorrência piora throughput/latência.
- [ ] **EX-492** **[A/I]** Implemente shutdown gracioso de uma aplicação async com tasks em andamento, cancelamento e cleanup de recursos.
- [ ] **EX-493** **[A/I]** Implemente um async iterator que represente páginas de uma API e pare lazymente quando não houver próximo cursor.
- [ ] **EX-494** **[A/I]** Crie um context manager síncrono e um assíncrono para uma mesma abstração de recurso e compare seus contratos.
- [ ] **EX-495** **[A/I]** Escreva uma classe que usa `__slots__`; compare memória de milhares de instâncias com uma classe comum e valide se a otimização vale a perda de flexibilidade.
- [ ] **EX-496** **[A/I]** Crie um objeto hashable imutável para usar como chave de cache e um objeto mutável deliberadamente unhashable. Explique os contratos de ambos.
- [ ] **EX-497** **[A/I]** Construa uma pequena DSL segura sem `eval`, usando parser/estrutura de dados explícita para representar operações permitidas.
- [ ] **EX-498** **[A/I]** Implemente um import de plugins por nome de módulo vindo de configuração, mas defina uma trust boundary clara para impedir que “configuração” se torne execução arbitrária não autorizada.
- [ ] **EX-499** **[A/I]** Faça uma aplicação que processa datas recebidas em múltiplos fusos, normaliza armazenamento em UTC e preserva o fuso necessário para apresentação/regra de negócio.
- [ ] **EX-500** **[A/I]** Modele um sistema de preços com `Decimal`, timezone-aware validity windows e serialização segura; teste limites de tempo e arredondamento.
- [ ] **EX-501** **[A/I]** Pegue um repositório Python seu e faça profiling real de uma operação. Produza uma mudança de performance justificada por dados e um teste que preserve comportamento.
- [ ] **EX-502** **[A/I]** Pegue outro módulo seu e remova uma abstração desnecessária. Explique por que menos código/indireção é uma melhoria arquitetural naquele caso.
- [ ] **EX-503** **[A/I]** Transforme um script monolítico em pacote instalável com núcleo puro, adapters de I/O, configuração, CLI, logging e testes, evitando introduzir framework desnecessário.
- [ ] **EX-504** **[A/I]** Faça revisão de segurança do projeto anterior procurando injection, desserialização, secrets, path traversal conceitual, permissões, logs e dependências de shell.
- [ ] **EX-505** **[A/I]** Faça revisão final do mesmo projeto usando o checklist profissional do capítulo 38 e registre decisões/trade-offs que você manteria mesmo sabendo alternativas mais sofisticadas.

# 42. Prova oral — sem código

Responda cada questão em voz alta, idealmente em menos de dois minutos. Se você só consegue responder escrevendo/testando, marque como conhecimento ainda não totalmente recuperável.

- [ ] **EX-506** Explique nomes, objetos, mutabilidade e aliasing sem usar a metáfora de caixas.
- [ ] **EX-507** Explique `is` versus `==` e dê o único padrão de comparação por identidade que você usa rotineiramente.
- [ ] **EX-508** Explique mutable default arguments do momento da definição até o bug observado.
- [ ] **EX-509** Explique LEGB, closure, `nonlocal` e late binding em uma única narrativa.
- [ ] **EX-510** Explique o protocolo de iteração desde `iter(obj)` até `StopIteration`.
- [ ] **EX-511** Explique o que `yield` muda na execução de uma função.
- [ ] **EX-512** Explique como decorator é apenas transformação/rebinding de callables.
- [ ] **EX-513** Explique como métodos são produzidos a partir de funções armazenadas em classes.
- [ ] **EX-514** Explique descriptor lookup e a diferença entre data e non-data descriptor.
- [ ] **EX-515** Explique MRO e por que `super()` permite herança cooperativa.
- [ ] **EX-516** Explique ABC versus Protocol versus duck typing puro.
- [ ] **EX-517** Explique o contrato `__eq__`/`__hash__` e por que mutabilidade é perigosa para hash keys.
- [ ] **EX-518** Explique `__getattribute__` versus `__getattr__` sem consultar.
- [ ] **EX-519** Explique `Any` versus `object` para um type checker.
- [ ] **EX-520** Explique `ParamSpec`, `Self`, `Never` e narrowing em termos de informação que o checker preserva.
- [ ] **EX-521** Explique por que typing não substitui validação de dados externos.
- [ ] **EX-522** Explique structural pattern matching e o perigo de `case nome:`.
- [ ] **EX-523** Explique `str` versus `bytes` e onde encode/decode deve acontecer.
- [ ] **EX-524** Explique naive versus aware datetime e sua política padrão para sistemas reais.
- [ ] **EX-525** Explique concorrência versus paralelismo, GIL e free-threaded Python sem slogans simplistas.
- [ ] **EX-526** Explique coroutine, task, event loop e `await`.
- [ ] **EX-527** Explique por que uma chamada síncrona bloqueante dentro de async é um problema.
- [ ] **EX-528** Explique threads versus processos versus asyncio para I/O e CPU-bound.
- [ ] **EX-529** Explique reference counting, cyclic GC e weak references.
- [ ] **EX-530** Explique shallow versus deep copy em termos de grafo de objetos.
- [ ] **EX-531** Explique por que medir vem antes de otimizar.
- [ ] **EX-532** Explique unit versus integration test e por que excesso de mocks reduz confiança.
- [ ] **EX-533** Explique import cache, `sys.modules` e circular imports.
- [ ] **EX-534** Explique por que metaclasses são poderosas e por que você tentaria `__init_subclass__` antes.
- [ ] **EX-535** Explique o papel de `pyproject.toml`, virtualenv, layout `src` e editable install.
- [ ] **EX-536** Explique EAFP, guard clauses e context managers como exemplos de estilo idiomático.
- [ ] **EX-537** Explique três vulnerabilidades clássicas: SQL injection, shell injection e unsafe deserialization.
- [ ] **EX-538** Explique functional core / imperative shell.
- [ ] **EX-539** Explique dependency inversion com Protocol sem transformar toda função em interface.
- [ ] **EX-540** Explique como escolher entre list, set, dict, deque e generator a partir das operações do problema.
- [ ] **EX-541** Explique como escolher entre dict, TypedDict, dataclass, classe comum e value object.
- [ ] **EX-542** Explique o que mudou de forma relevante em Python 3.12–3.14 que você usaria em código novo.
- [ ] **EX-543** Cite de memória pelo menos vinte módulos da stdlib e um uso concreto de cada um.
- [ ] **EX-544** Cite de memória pelo menos vinte dunder methods e o protocolo/comportamento associado a cada um.
- [ ] **EX-545** Descreva sua ordem mental para projetar uma feature Python nova: dados, invariantes, API, erros, recursos, concorrência, testes, performance e packaging.

---

# Critério de domínio sugerido

Some sua pontuação (`0`, `1` ou `2`) dentro de cada seção em vez de olhar apenas a pontuação global.

- **90–100% dos pontos:** domínio forte; consulte o material principalmente para detalhes de API.
- **75–89%:** boa retenção; revise os exercícios marcados com `0` e `1`.
- **50–74%:** conhecimento utilizável, mas com áreas que provavelmente exigem consulta frequente.
- **Abaixo de 50%:** vale reler a seção correspondente da masterclass e repetir apenas aquele bloco.

Um exercício marcado como `2` deveria significar que você consegue **explicar o porquê**, não apenas produzir algo que “funciona”. Para os desafios integradores, dê mais peso à justificativa de trade-offs do que à quantidade de código.

## Método de segunda passada

Depois da primeira revisão:

1. filtre somente exercícios com nota `0`;
2. releia as seções correspondentes da masterclass;
3. resolva-os novamente sem consulta;
4. uma semana depois, repita os exercícios que ficaram em `1`;
5. use os desafios integradores como prova final de retenção e transferência.

Não é necessário resolver todos os desafios integradores para considerar a linguagem revisada. Eles servem para detectar lacunas que exercícios isolados não revelam.
