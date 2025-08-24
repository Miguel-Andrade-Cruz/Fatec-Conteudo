#ifndef inputer
#define inputer

#include <stdio.h>

typedef enum {
    FLOAT,
    INT,
    CHAR
} InputType;

typedef union {
    int ipt_int;
    float ipt_float;
    char ipt_char;
} Holder;


typedef struct {
    Holder holder;
    InputType input_type;
} Recipe;




void inputer(Recipe recipe, char *msg, Validator *validator) {
    // Recieves an input recipe containing a pointer and
    // a type, and performs a STDIN read until the user
    // input satisfies the validator.
    
    printf("%s", msg);
    
    
    
    return;
}

#endif