#include "middleware.h"

void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}


void ask_for_string(char *string) {
    
    printf("Insira uma string (máximo 10 caracteres):  ");
    scanf("%[^\n]s", string);
    clear_buffer();
    return;
}


void to_uppercase_conversion(char *string) {
    
    for (int i_char = 0; i_char < STRING_SIZE; i_char++) {
        
        int is_space = string[i_char] == 0x20;
        int is_upper = string[i_char] >= 0x41 && string[i_char] <= 0x5a;
        
        if (is_space || is_upper) {
            continue;
            
        } else if (string[i_char] == '\0') {
            i_char = STRING_SIZE;
            
        } else {
            
            string[i_char] -= 0x20;
        }
    }
    return;
}


void show_string(char *string) {
    
    printf("A string digita foi: %s\n", string);
    return;
}
