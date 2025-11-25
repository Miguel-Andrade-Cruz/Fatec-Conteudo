#include "wrap_type.c"
#include <string.h>

// Resolve null character for both conversions


int char_to_int(char character) {
    
    const int BITMASK = 0x0F;
    if (character >= 'A') {
        return character - 'A' + 10;
    }
    return character & BITMASK;
}


char int_to_char(int integer) {
    
    const int NUMERIC_BITMASK = 0x30;
    const int ALPHA_BITMASK = 0x40;
    
    if (integer < 10) return integer | NUMERIC_BITMASK;
    return (integer - 9) | ALPHA_BITMASK;
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
