#include <stdio.h>
#include <string.h>
#include "filters.c"

void define_fmt_specifier(Type ipt_type, char *fmt_specifier) {
    
    switch (ipt_type) {
        
        case INT:
            strcpy(fmt_specifier, "%d");
            break;
        
        case FLOAT:
            strcpy(fmt_specifier, "%d");
            break;
        
        case CHAR:
            strcpy(fmt_specifier, "%d");
            break;
    }
    return;
}


void scan(Field *field) {
    
    char fmt_specifier[3];
    int tests, passed;
    do {
        
        define_fmt_specifier(field->ipt.type, fmt_specifier);
        printf("%s", field->descrp);
        scanf(fmt_specifier, field->ipt.value);
        
        tests = passed = 0;
        for (int i = 0; i < 2; i++) {
            
            Checkit verify = field->filters[i].verifier;
            Any bound = field->filters[i].bound;
            int ok = verify(field->ipt, bound);
            
            tests++;
            passed += ok;
        }
        
    } while (tests / passed);
}
