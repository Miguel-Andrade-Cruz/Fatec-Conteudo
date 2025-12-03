#include "conversion_package.c"


int char_to_int(char character) {
    
    const int offset = 10;
    
    if (character >= 'A') {
        return character - 'A' + offset;
    }
    return character & TO_INT_BITMASK;
}

char int_to_char(int integer) {
    
    const int offset = 9;
    
    if (integer < 10) return integer | TO_CHAR_DIGIT_BITMASK;
    return (integer - offset) | TO_CHAR_ALPHA_BITMASK;
}


void chars_to_ints(char *before_vector, int *after_vector) {
    
    for (int i = 0; i < LIMIT_MAX; i++) {
        
        after_vector[i] = char_to_int(before_vector[i]);
    }
    return;
}


void ints_to_chars(int *before_vector, char *after_vector) {
    
    for (int i = 0; i < LIMIT_MAX; i++) {
        
        after_vector[i] = int_to_char(before_vector[i]);
    }
    after_vector[LIMIT_MAX + 1] = '\0';
    
    return;
}
