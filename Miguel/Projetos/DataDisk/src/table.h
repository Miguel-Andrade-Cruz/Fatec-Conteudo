#include <stdio.h>

typedef enum {
    INT,
    VARCHAR,
    FLOAT,
    DATE,
} DATATYPE;

typedef struct {
    char alias[50];
    DATATYPE type;
} Field;

typedef struct {
    void *value;
} FieldValue;

// typedef struct {
//     FieldValue entries[];
// } Entry;

typedef struct index_t index_t;
struct index_t {
    index_t *parent;
    void *indexed;
    fpos_t *entry_ptr;
};

typedef struct {
    char *indexed;
    Field column[];
} table;