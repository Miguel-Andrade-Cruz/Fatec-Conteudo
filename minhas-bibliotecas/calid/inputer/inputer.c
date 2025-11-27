#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../d_type/d_type.c"

typedef struct {
    
    Outputer value;
    ipt_type type;
    char *msg;
} Inputer;

typedef struct {
    int qtd;
    Inputer *arr[];
} InputerSet;

void clean_inputs(InputerSet *inputs) {
    free(inputs);
    return;
}


InputerSet* group_inputs(Inputer inputs[], int size) {
    InputerSet *inputer_set = malloc(sizeof(InputerSet) + size * sizeof(Inputer));
    
    inputer_set->qtd = size;
    for (int i = 0; i < size; i++) {
        
        inputer_set->arr[i] = &inputs[i];
    }
    
    return inputer_set;
}



char takechar(Inputer *ipt) {
    char value = ipt->value.v_char;
    return value;    
}

float takefloat(Inputer *ipt) {
    float value = ipt->value.v_float;
    return value;    
}

int takeint(Inputer *ipt) {
    int value = ipt->value.v_int;
    return value;    
}



int checklist(Inputer *ipt_sketch, Needs *checker) {
    int passed_check = 0;
    Validator *current_checker;
    
    for (int i = 0; i < checker->qtd; i++) {
        current_checker = checker->arr[i];
        passed_check += current_checker->action(ipt_sketch->value, current_checker->state);
    }
    if (passed_check < checker->qtd) {
        return 0;
    }
    return 1;
}

void pull(InputerSet *ipt_set_sketch, Needs *checker) {

    // TODO: Fazer iteração sobre inputs
    for (int i = 0; i < ipt_set_sketch->qtd; i++) {
        
            Inputer *ipt_sketch = ipt_set_sketch->arr[i];
        do {
            
            printf("%s", ipt_sketch->msg);
            
            char format_specifier[3];
            // TODO FEATURE: Fazer um enum para format specifiers 
            switch (ipt_sketch->type) {
                case T_FLOAT:
                    strcpy(format_specifier, "%f");
                    break;
                case T_CHAR:
                    strcpy(format_specifier, "%c");
                    break;
                case T_INT:
                    strcpy(format_specifier, "%d");
                    break;
            }
            
            scanf(format_specifier, &(ipt_sketch->value));
        } while (checklist(ipt_sketch, checker) == 0);
    }

    return;
}
