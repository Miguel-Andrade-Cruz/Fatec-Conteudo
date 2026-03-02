#ifndef CALID_H
#define CALID_H

#include <string.h>

typedef enum {
    CHAR,
    INT,
    FLOAT
} Type;

typedef union {

    char *a_char;
    int *a_int;
    float *a_float;
} AnyTypes;

typedef struct {
    AnyTypes value;
    Type type;
} Any;


typedef int (*Validator)(Any bound, Any input);


typedef struct {

    Validator validator;
    Any bound;
} Rule;

typedef Rule* (Checker)(Any delimiter);

typedef struct {
    Rule *requests[5];
} RuleSet;

typedef struct {

    RuleSet *requests;
    Any pointer;
} FormField;

typedef struct {
    
    int fields_qtd;
    FormField *form_fields;
} Form;


Checker capitalized()

void fill_form(Form *form);

#endif