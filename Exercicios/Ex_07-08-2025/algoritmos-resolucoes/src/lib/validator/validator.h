#ifndef VALIDATOR_H
#define VALIDATOR_H

#include "../d_type/d_type.h"

typedef int (*Checker)(Outputer, Outputer);

typedef struct {
    
    Outputer state;
    Checker action;
} Validator;


Validator* is_signed(char mode);
Validator* less_than(float limit);
Validator* greater_than(float lmit);

#endif