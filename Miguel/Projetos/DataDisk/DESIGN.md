# DataDisk

*Banco de dados em arquivo com interface direta em lingugem C*

> Inspirado no desafio passado no primeiro semestre da disciplina laboratório de hardware, o projeto DataDisk surge para  testar os limites de conhecimento da linguagem C e extendê-los ao longo do desenvovilmento.


### Requisitos funcionais
- [ ] Inserir, editar, buscar e deletar registros do banco de dados
- [ ] Permitir encadeamento de filtros de busca
- [ ] Indexação de colunas
- [ ] Procedures
- [ ] Operadores `AND`, `OR` e `NOT`
- [ ] Tipos de dado

### Requisitos não funcionais
- [ ] Interface simples de utilizar

## Metodologia
Para todas as funções desenvolvidas, haverá testes para aprová-lo. Os testes para cada função devem estar prontos antes do começo do desenvovilvmento da função que ele testa.

## Rota de desenvolvimento
- [ ] Estabelecer padrões:
  - [x] Tamanho máximo do campo |-> 128
  - [x] Estrutura de dados:
    - [x] Campo
    - [x] Linha
    - [x] Índice

- [ ] Funções de I/O com o arquivo de dados
> Formar uma inteface para tratamento de erros e previsibilidade
  - [ ] Inserir
  - [ ] Editar
  - [ ] Buscar
  - [ ] Deletar
- [ ] Operadores, condições e filtros:
  - [ ] `AND`, `OR`, `NOT`
  - [ ] `IF`, `ELSE`
- [ ] Tipos de dado