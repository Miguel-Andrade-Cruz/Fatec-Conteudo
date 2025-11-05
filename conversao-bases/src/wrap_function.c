#include <stdio.h>
#include "wrap_type.c"


int get_base(int get_current) {
    
    int base;
    do {
        if (get_current == 1) { printf("Insira a base numérica atual:  \n"); }
        if (get_current == 0) { printf("Insira a base numérica desejada:  \n"); }
        scanf("%d", &base);
    } while (   
                base != 2 &&
                base != 8 &&
                base != 10 &&
                base != 16
            )
    ;
    
    return base;
}


void get_number(char *number) {
    
    int valid_number(char *maybe); // desenvolver validação
    
    char hold[LIMIT_MAX];
    do {
        printf("Insira o número:  \n");
        scanf("%s", hold);
    } while (valid_number(hold) == 0);
    
    number = hold;
    return;
}


void pack_input(ConversionPackage *package) {
    
    package->current_base = get_base(1);
    package->target_base = get_base(0);
    get_number(package->current_number);
    package->size = get_alg_limit(package->current_base);

    return;
}