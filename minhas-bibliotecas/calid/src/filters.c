#include "helps.c"


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
