#include "middleware.h"
// #define DEBUG


void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}


void ask_for_two_strings(char *str_one, char * str_two) {
    
    printf("Insira a primeira string (máximo 10 carcteres):  ");
    scanf("%s", str_one);
    clear_buffer();
    
    printf("Insira a segunda string (máximo 10 carcteres):  ");
    scanf("%s", str_two);
    clear_buffer();
    
    #ifdef DEBUG
    printf("[DEBUG] FIRST STRING: %s < ask_for_two_strings > -[ ln 12 ]-\n", str_one);
    printf("[DEBUG] SECOND STRING: %s < ask_for_two_strings > -[ ln 12 ]-\n", str_two);
    #endif
    return;
}


int string_comparator(char *str_one, char * str_two) {
    
    int is_equal;
    int equal_chars_qtd = 0;
    for (int i_char = 0; i_char < STRING_SIZE; i_char++) {
        
        if (str_one[i_char] == str_two[i_char]) {
            equal_chars_qtd++;
        }
    }
    is_equal = equal_chars_qtd == STRING_SIZE;
    
    #ifdef DEBUG
    printf("[DEBUG] IS_EQUAL: %d < string_comparator > -[ ln 30 ]-\n", is_equal);
    #endif
    return is_equal
}


void show_comparison_result(int is_equal) {
    
    if (is_equal == 1) {
        printf("As duas strings são iguais\n");
    } else {
        printf("Há diferenças entre as strings\n");
    }
    return;
}