#include <stdio.h>
#include "convert.c"


void get_current_base_message() {
    printf("Digite a base atual: ");
    return;
}


void get_target_base_message() {
    printf("Digite a base desejada: ");
    return;
}


void get_number_to_convert_message() {
    printf("Digite o número: ");
    return;
}


int get_base(char get_current) {
    
    int base;
    do {
        if (get_current == 'c') { get_current_base_message(); }
        if (get_current == 't') { get_target_base_message(); }
        scanf("%d", &base);
    } while (   
        base != 2 &&
        base != 8 &&
        base != 10 &&
        base != 16
    );
    
    return base;
}


void get_number(int size, int base, int *returned) {
    
    int char_counter;
    char hold[LIMIT_MAX] = {0};

    do {
        char_counter = 0;
        
        get_number_to_convert_message();
        scanf("%s", hold);
        
        while (hold[char_counter] != '\0') char_counter++;
        
    } while (
        char_counter > size || valid_number(hold, base) == 0
    );

    slide_right(hold);
    chars_to_ints(hold, returned);
    
    return;
}


void pack_input(ConversionPackage *package) {
    
    package->current_base = get_base('c');
    get_number(package->size, package->current_base, package->current_number);
    package->target_base = get_base('t');
    
    package->size = get_alg_limit(package->current_base);
    
    return;
}


void show_output(ConversionPackage *package) {

    char current_char_output[LIMIT_MAX + 1]; // +1 for null terminator
    char target_char_output[LIMIT_MAX + 1]; // +1 for null terminator
     
    ints_to_chars(package->current_number, current_char_output);
    ints_to_chars(package->target_number, target_char_output);
    
    slide_left(current_char_output);
    slide_left(target_char_output);
    
    printf(
        "%s(%d) ==>> %s(%d)",
        current_char_output,
        package->current_base,
        target_char_output,
        package->target_base
    );
    printf("\n");
    
    return;
}