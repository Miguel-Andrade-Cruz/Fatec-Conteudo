#include <stdio.h>
#include <string.h>
#include "translators.c"


int get_base(char get_current) {
    
    int base;
    do {
        if (get_current == 'c') { printf("Insira a base numérica atual:  \n"); }
        if (get_current == 't') { printf("Insira a base numérica desejada:  \n"); }
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


int valid_number(char *maybe) {
    
    int BITMASK_PADRONIZE = 0b00001111;
    for (int i = 0; i < LIMIT_MAX; i++) {
        int algarism_padronized = maybe[i] & BITMASK_PADRONIZE;
        
        if (algarism_padronized < 0 && algarism_padronized > 15) {
            return 0;
        }
    }
    
    return 1;
}


void get_number(int *returned) {
    
    char hold[LIMIT_MAX] = {0};
    do {
        printf("Insira o número:  \n");
        scanf("%s", hold);
    } while (valid_number(hold) == 0);
        
    chars_to_ints(hold, returned);
    return;
}


void clean(char *raw) {
    
    int algarisms_used = 0;
    while (raw[algarisms_used] != '\0') algarisms_used++;
    
    int offset = LIMIT_MAX - algarisms_used;
    for (int i = 0; i < algarisms_used; i++) {
        
        raw[i + offset] = raw[i];
        raw[i] = '\0';
    }
    
    return;
}



void pack_input(ConversionPackage *package) {
    
    package->current_base = get_base(1);
    package->target_base = get_base(0);
    package->size = get_alg_limit(package->current_base);
    
    get_number(package->current_number);
    package->current_algarism_qtd = sizeof(package->current_number) / sizeof(int);

    return;
}