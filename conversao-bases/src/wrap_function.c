#include <stdio.h>
#include "translators.c"


int get_base(char get_current) {
    
    int base;
    do {
        if (get_current == 'c') { printf("Insira a base numérica atual:  "); }
        if (get_current == 't') { printf("Insira a base numérica desejada:  "); }
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


void slide_right(char *array) {
    
    char placeholder[LIMIT_MAX] = {0};
    int algarisms_used = 0;
    while (array[algarisms_used] != '\0') algarisms_used++;
    
    int offset = LIMIT_MAX - algarisms_used;
    for (int i = 0; i < algarisms_used; i++) {
        
        placeholder[i + offset] = array[i];
    }
    
    memcpy(array, placeholder, sizeof(placeholder) / sizeof(char));
    return;
}


void get_number(int size, int *returned) {
    
    int char_counter;
    
    char hold[LIMIT_MAX] = {0};
    do {
        char_counter = 0;
        
        printf("Insira o número:  ");
        scanf("%s", hold);
        
        while (hold[char_counter] != '\0') char_counter++;        
    } while (char_counter > size || valid_number(hold) == 0);
    
    slide_right(hold);
    chars_to_ints(hold, returned);
    
    return;
}


void pack_input(ConversionPackage *package) {
    
    package->current_base = get_base('c');
    package->target_base = get_base('t');
    package->size = get_alg_limit(package->current_base);
    
    get_number(package->size, package->current_number);
    
    return;
}