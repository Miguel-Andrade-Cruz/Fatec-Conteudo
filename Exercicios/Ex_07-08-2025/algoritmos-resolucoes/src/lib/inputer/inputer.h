#ifndef INPUT_SKETCH_H
#define INPUT_SKETCH_H

#include "../d_type/d_type.h"
#include "../validator/validator.h"


typedef struct {
    
    Outputer value;
    ipt_type type;
    char *msg;
} Inputer;

void pull(Inputer *ipt_sketch, Validator *checker[], int lenght);

#endif