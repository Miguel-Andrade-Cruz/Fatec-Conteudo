#include "middleware.h"

void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}


void ask_for_string(char *string) {
    
    printf("Insira uma string (máximo 10 caracteres):  ");
    scanf("%s", string);
    clear_buffer();
    return;
}


void to_lowercase_conversion(char *string) {
    
    for (int i_char = 0; i_char < STRING_SIZE; i_char++) {
        if (string[i_char] == 0x20) {
            continue;
        } else if (string[i_char] == '\0') {
            i_char = STRING_SIZE;
            
        } else {
            string[i_char] += 0x20;
        }
    }
    return;
}


void show_string(char *string) {
    
    printf("Assim ficou a string em caixa baixa: %s", string);
    return;
}