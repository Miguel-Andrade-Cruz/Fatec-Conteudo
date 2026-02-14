// #include <stdio.h>
#include "validations.c"


int checklist(Guard *guard) {

    int is_valid = 1;
    
    TypedValue value_pack = guard->value;
    
    // printf("Qunatdade de regra: %d (11 inspec.c)\n", guard->requires_size);
    
    for (int i = 0; i < guard->requires_size; i++) {
        
        // printf("Pegando o requisito %d ... (15 inspec.c)", i);
        
        Rule next_requirement = guard->requires[i];
        TypedValue bound_pack = guard->requires->bound;
        
        if (next_requirement.action(value_pack, bound_pack) == 0) {
            is_valid = 0;
        }
    }
    return is_valid;
}


int inspec(Guard *guard) {
    
    char *format_specifier;
    switch (guard->value.type) {

        case T_INT: {
            
            format_specifier = "%d";
            break;
        }
        case T_FLOAT: {
            
            format_specifier = "%f";
            break;
        }
        case T_CHAR: {
            
            format_specifier = "%c";
            break;
        }
    }

    // printf("Olha, pelo menos o format specifier tá indo... (51 inspec.c)\n");
    do {
    if (scanf(format_specifier, guard->value.value) == 0)
            while (getchar() != '\n');    

    } while (checklist(guard) == 0);

    return 1;
}