## 21/06/2026
Definido as principais estruturas de dados utilizadas no sistema.

### Field:
Identifica o apelido e o tipo de dado guardado.
```c
typedef struct {
    char *alias;
    DATATYPE type;
} Field;

Field new_field = create_field("birth", "date");
```

### Entry
Identifica uma linha da tabela, contendo todos os campos que possui.

```c
typedef struct {
    int id;
    Field fields[];
} Entry;

Entry new_field = create_field("birth", "date");
```

### Index
Identifica on índice de um registro, o índice do próximo e um pointer para o registro.

```c
typedef struct {
    int idx;
    int *entry_ptr;
    int next_idx;
}
```