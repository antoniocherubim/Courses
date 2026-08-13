# Track E — Infrastructure & Distributed Systems

[← Mapa geral](../README.md)

> Como processos deixam de viver em uma única máquina e passam a formar serviços confiáveis.

## Sequência

| ID | Masterclass | Status | Pré-requisitos |
|---|---|:---:|---|
| E01 | Redes de Computadores | ⬜ | A08 recomendado |
| E02 | Containers e Docker Internals | ⬜ | A08/A09 |
| E03 | Infrastructure Fundamentals | ⬜ | A09, E01/E02 |
| E04 | Bancos de Dados por Dentro | ⬜ | A07/A08, SQL |
| E05 | Sistemas Distribuídos | ⬜ | A10, E01, E04 |
| E06 | Orquestração e Kubernetes | ⬜ | E02/E05 |
| E07 | Segurança de Sistemas e Infraestrutura | ⬜ | A08/A09, E01/E02 |
| E08 | Criptografia para Programadores | ⬜ | B01/B04, E01 |
| E09 | Observabilidade, Reliability e SRE | ⬜ | E03–E06 |

## Fluxo

```text
processo Linux
↓
container
↓
serviço
↓
rede
↓
persistência
↓
replicação
↓
cluster
↓
observabilidade / segurança
```

Docker é estudado como consequência de mecanismos do Linux:

```text
namespaces
+
cgroups
+
capabilities
+
seccomp
+
filesystem layers
↓
OCI runtime
↓
containerd / Docker
```
