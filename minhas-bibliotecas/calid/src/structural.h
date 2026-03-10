
typedef enum {
    CHAR,
    INT,
    FLOAT
} Type;

typedef union {

    char *a_char;
    int *a_int;
    float *a_float;
} AnyPointerTypes;

typedef union {

    char a_char;
    int a_int;
    float a_float;
} AnyTypes;


typedef struct {
    AnyPointerTypes value;
    Type type;
} AnyPointer;

typedef struct {
    AnyTypes value;
    Type type;
} Any;


typedef int (*Validator)(Any bound, AnyPointer input);


typedef struct {

    Validator validator;
    Any bound;
} Rule;

typedef struct {

    char *question;
    Rule *requests;
    AnyPointer pointer;
    int rules_qtd;
} FormField;

typedef struct {
    
    int fields_qtd;
    FormField *form_fields;
} Form;
