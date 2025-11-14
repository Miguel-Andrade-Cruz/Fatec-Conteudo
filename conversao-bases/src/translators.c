#include "wrap_type.c"

// Resolve null character for both conversions


int char_to_int(char character) {
    
    int BITMASK = 0b00001111;

    return character & BITMASK;
}

char int_to_char(int integer) {
    
    int NUMERIC_BITMASK = 0b00110000;
    int ALPHA_BITMASK = 0b01000000;
    
    if (integer < 9) return integer | NUMERIC_BITMASK;
    
    return integer | ALPHA_BITMASK;
}



void chars_to_ints(char *before_vector, int *after_vector, int size) {
    
    for (int i = 0; i < size; i++) {
        
        after_vector[i] = char_to_int(before_vector[i]);
    }
    return;
}


void ints_to_chars(int *before_vector, char *afer_vector, int size) {
    
    
    for (int i = 0; i < size; i++) {
        
        afer_vector[i] = int_to_char(before_vector[i]);
    }
    return;
}
