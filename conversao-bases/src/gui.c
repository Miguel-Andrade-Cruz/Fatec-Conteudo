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

void slide_left(char *array) {
    
    int offset = 0;
    while (array[offset] == '0') {
        offset++;
    }
    
    int i = 0;
    while (array[i + offset] != '\0') {
        array[i] = array[i + offset];
        i++;
    }
    array[i] = '\0';
    
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
        "\n Número: %s  Base numérica: %d \n Número: %s  Base numérica: %d \n",
        current_char_output,
        package->current_base,
        target_char_output,
        package->target_base
    );
    
    return;
}