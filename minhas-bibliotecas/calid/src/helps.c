#include "types.h"



void field(char *descrp, Generic **valueptr, Type ipt_type, Field *new_field) {
    
    new_field->descrp = descrp;
    new_field->ipt.type = ipt_type;
    
    *valueptr = &new_field->ipt.value;
    
    return;
}


Filter filter(Checkit veriifer, int bound) {
    
    return (Filter) {.verifier = veriifer, .bound = bound};
}

void apply(Field *field, Filter filters[]) {
    
    field->filters = filters;
    return;
}
