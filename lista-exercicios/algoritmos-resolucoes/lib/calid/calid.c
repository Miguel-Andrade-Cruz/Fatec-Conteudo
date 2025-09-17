
// Hub all the separate modules in one include file

#include "./validator/validator.c"


void clean_all(InputerSet *inputs, Needs *validators) {
    
    clean_inputs(inputs);
    clean_validators(validators);
    return;
}
