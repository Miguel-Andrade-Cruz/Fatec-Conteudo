#include "types.c"
#include <stdio.h>


int _more_than_partial(TypedValue value_pack, TypedValue bound_pack) { // Chekcup type signature
    
    float value;
    if (value_pack.type == T_INT) {
        value = (float)*value_pack.value.V_INT;
        
    } else if (value_pack.type == T_FLOAT) {
       value = *value_pack.value.V_FLOAT;   
    }
    
    float bound = (float)*bound_pack.value.V_INT;
    
    printf("Valor inserido --maior--: %f (17 validations)\n", value);
    // int valid = value > bound;
    // printf("é maior: %d ( 18 validations)\n", valid);
    
    return value > bound;
}

Rule more_than(int limit) {

    Any bound = {.V_INT = &limit};
    Rule rule = {
        .bound = {.value = bound, .type = T_INT},
        .action = _more_than_partial
    };
    
    return rule;
}

// ------------------------------

int _less_than_partial(TypedValue value_pack, TypedValue bound_pack) {
    
    float value;
    if (value_pack.type == T_INT) {
        value = (float)*value_pack.value.V_INT;
        
    } else if (value_pack.type == T_FLOAT) {
       value = *value_pack.value.V_FLOAT;   
    }
    
    float bound = (float)*bound_pack.value.V_INT;

    printf("Valor inserido --menor--: %f (49 validations)\n", value);
    // int valid = value < bound;
    // printf("é menor: %d ( 49 validations)\n", valid);

    return value < bound;
}

Rule less_than(int limit) {
    
    Any bound = {.V_INT = &limit};
    Rule rule = {
        .bound = {.value = bound, .type = T_INT},
        .action = _less_than_partial
    };
    
    return rule;
}