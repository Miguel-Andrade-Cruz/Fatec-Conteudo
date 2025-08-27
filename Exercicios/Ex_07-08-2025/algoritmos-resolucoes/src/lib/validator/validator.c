#include <stdlib.h>

#include "../validator/validator.h"


int _v_is_signed(Outputer target, Outputer mode) {
    if (mode.v_char == 'm') {
        return target.v_int >= 0;
        
    } else if (mode.v_char == 'l') {
        return target.v_int <= 0;
        
    } else if (mode.v_char == 'z') {
        return target.v_int != 0;
    }
    
    return -1;
}

Validator* is_signed(char mode) {
    Outputer state = {.v_char = mode};
    Validator *is_signed;
    
    is_signed->state = state;
    is_signed->action = _v_is_signed;
 
    return is_signed;
}



int _v_less_than(Outputer target, Outputer limit) {
    
    return target.v_float < limit.v_float;
}

Validator* less_than(float limit) {
    Outputer state = {.v_float = limit};
    Validator *_less_than = malloc(sizeof(Validator));
    
    _less_than->state = state;
    _less_than->action = _v_less_than;
    
    return _less_than;
}


int _v_greater_than(Outputer target, Outputer limit) {
    return target.v_float > limit.v_float;
}

Validator* greater_than(float limit) {
    Outputer state = {.v_float = limit};
    Validator *_greater_than = malloc(sizeof(Validator));
    
    _greater_than->state = state;
    _greater_than->action = _v_greater_than;
    
    return _greater_than;
}