# Calid: Validação de inputs sem preocupação

## Como funciona?

Calid possui três componentes principais:

- `Inputer`:
  Estrutura responsável por encapsular os metadados do input
    - Mensagem de exibição;
    - Tipo de dado a ser inserido.

- `Validator`:
  Estrutura simuladora de uma *função parcial
  > *Funções parciais são aquelas que implementam funcionalidade de uma função mãe,
  com um ou mais valores já estabelecidos por padrão. Análogo a seguir uma receita de
 bolo de uma mistura pré feita.

- `pull`:
  Quem de fato pede input do usuário e aplica os Validators conforme informações do inputer
  até todos os requisitos serem satisfeitos.
  
  
  
## API (Interface de utilização):

1. Declare uma variável do tipo `Inputer`, passando uma mensagem e um *tipo:
`Inputer preco_banana = {.msg = "Insira o preço da banana:\n, .type = T_FLOAT}; `

> * Siga a tabela para inserir o tipo certo de input:
> | Tipo de dado | Enumerador |
> |--|--|
> | número inteiro | `T_INT` |
> | número decimal (real) | `T_FLOAT` |
> | caractere único | `T_CHAR` |

2. Declare ponteiros atribuindo as validações desejadas:
`Validator *maior_que_1_real = greater_than(1);`

3. Declare uma array contendo todas as validações que deseja:
`Validator *checagens[] = {maior_que_1_real};`

4.Calcule a quantidade de validações e salve em uma variável:
`int quantidade_validacoes = sizeof(checagens) / sizeof(checagens[0]);`

4. Chame a função `pull` passando a referência para seu `Inputer`,
a lista de `Validators` e o tamanho do array calculado:
`pull(&preco_banana, checagens, quantidade_validacoes);`
