#include "helps.c"

int greater_than(Any ipt, Any bound);
int less_than(Any ipt, Any bound);
int limits_to_char(Any ipt, Any bound);
int limits_to_strs(Any ipt, Any bound) {


int greater_than(Any ipt, Any bound) {
    
    switch (ipt.type) {
        
        case INT:
            return ipt.value.v_int > bound.value.v_int;
        case FLOAT:
            return ipt.value.v_float > bound.value.v_float;
        default:
            return -1;
    }
}


int less_than(Any ipt, Any bound) {
    
    switch (ipt.type) {
        
        case INT:
            return ipt.value.v_int < bound.value.v_int;
        
        case FLOAT:
            return ipt.value.v_float < bound.value.v_float;
        
        default:
            return -1;
    }
}


int limits_to_chars(Any ipt, Any bound) {
    
    char ipt_clear = ipt.value.v_char;
    char *bound_clear = bound.value.v_str;
    int size = strsize(bound_clear);
    
    int i = 0;
    while (i < size) {
        
        if (ipt_clear == bound_clear[i]) {
            return 1;
        }
        i++;
    }
    return 0;
}


int limits_to_strs(Any ipt, Any bound) {
    
    
    return 0; //
}
