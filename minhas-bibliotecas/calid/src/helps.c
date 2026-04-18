#include <stdio.h>
#include "types.h"

// ---------------------------------------------------------
void clear_buffer();

int strsize(char *str);

void field(char *descrp, Generic **valueptr, Type ipt_type, Field *new_field);

Filter filter(Checkit veriifer, Generic bound, Type type);

void apply(Field *field, Filter *filters);
// ---------------------------------------------------------




void field(char *descrp, Generic **valueptr, Type ipt_type, Field *new_field) {
    
    new_field->descrp = descrp;
    new_field->ipt.type = ipt_type;
    
    *valueptr = &new_field->ipt.value;
    
    return;
}


Filter filter(Checkit veriifer, Generic bound, Type type) {
    
    Filter add_filter = {
        .verifier = veriifer
    };
    
    Any filter_bound = {.type = type};
    switch (type) {
        
        case INT:
            filter_bound.value.v_int = bound.v_int;
            add_filter.bound = filter_bound;
            break;
            
        case FLOAT:
            filter_bound.value.v_float = bound.v_float;
            add_filter.bound = filter_bound;
        break;
            
        case CHAR:
            filter_bound.value.v_char = bound.v_char;
            add_filter.bound = filter_bound;
            break;
            
        case STR:
            filter_bound.value.v_str = bound.v_str;
            add_filter.bound = filter_bound;
            break;

    }
    
    return add_filter;
}


void apply(Field *field, Filter *filters) {
    
    field->filters = filters;
    return;
}


int strsize(char *str) {
    
    int i = 0;
    int *size = &i;
    while (str[i] != '\0') {
        i++;
    }
    return *size;
}


void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}
