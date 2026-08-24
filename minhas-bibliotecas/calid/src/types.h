

typedef int ( *Validator )(int, int); // TODO: Adicionar novo tipo para o tipo de variavel


typedef struct {
    Validator *verify;
    int value; // TODO: Adicionar novo tipo para o tipo de variavel
} Checklist;


typedef struct {
    char *question;
    char *question_err;
    int *destiny_ptr; // TODO: Adicionar novo tipo para o tipo de variavel
    Checklist *checklist;
} Form;









// typedef enum {

//     INT,
//     CHAR,
//     FLOAT,
//     STR
// } Type;

// typedef union {

//     int v_int;
//     char v_char;
//     float v_float;
//     char *v_str;
// } Generic;

// typedef struct{

//     Type type;
//     Generic value;
// } Any;

// typedef int ( *Checkit )(Any, Any);


// typedef struct {

//     Checkit verifier;
//     Any bound;
// } Filter;


// typedef struct {

//     char *descrp;
//     Any ipt;
//     Filter *filters;
// } Field;
