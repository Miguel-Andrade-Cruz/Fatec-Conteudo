# Conversor de bases em C

Como método de estudo para cnoversão de bases (e também para não ter que fazer á mão
os exercícios), esse mini projeto tem o objetivo de automatizar a conversão de
números entre as bases:

- Decimal
- Octal
- Hexadecimal
- Binária

---

Procurei uma interface simples, tanto para digitar os valores de base e número quanto
para mostrar o resultado final.


## Fluxo de funcionamento

1. O usuário insere os valores de base atual, número e base desejada.
2. Esses dados são validados, tratados e agrupados em uma única estrutura,
onde mais tarde será guardada também o resultado do cálculo.
3. É identificado a conversão desejada e as operações necessárias são feitas.
4. Com o resultado calculado, usa-se dela e das demais informações para compor
o resultado final.


---

# Funcionalidades

1. Para qualquer conversão efetuada, o seu resultado na base decimal é registrado.
2. Graças ao design utilizado, é possível implementar outras bases numéricas com poucas
mudanças em funções genéricas, como validações de input.
3. Seu modo de utilização por estrutura de dado manipulada permite alterar os valores
da estrutura quando quiser, habilitando para existência de funções de edição e remoção
por exemplo.

---

## Limitações

1. O maior núemero possível para conversão é o 65.535 em base 10, pro ser o maior
número possível de se representar no sistema binário com 16 dígitos.

2. É necessário digitar os caracteres hexadecimais alfabéticos (A - F) como maiúsculas
pra serem reconhecidos.



