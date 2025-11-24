#include <stdio.h>
#include "wrap_function.c"

void get_current_base_message() {
    printf("Base do número digitado: \n");
    return;
}

void get_target_base_message() {
    printf("Base a ser convertida: \n");
    return;
}

void get_number_to_convert_message() {
    printf("Número a ser convertido: \n");
    return;
}


void show_output(ConversionPackage *package) {

    char current_char_output[LIMIT_MAX];
    char target_char_output[LIMIT_MAX];    
     
    ints_to_chars(package->current_number, current_char_output);
    ints_to_chars(package->target_number, target_char_output);
    
    printf(
        "\n Número: %s  Base numérica: %d \n Número: %s  Base numérica: %d \n",
        current_char_output,
        package->current_base,
        target_char_output,
        package->target_base
    );
    
    return;
}