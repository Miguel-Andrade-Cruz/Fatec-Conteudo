#include "wrap_type.c"

// Resolve null character for both conversions


int char_to_int(char character) {
    
    int CONVERT_BITMASK = 0b00001111;
    return character & CONVERT_BITMASK;
}

char int_to_char(int integer) {

    int CONVERT_BITMASK = 0b01000000;
    int offset = 9;
    
    return (integer - offset) | CONVERT_BITMASK;
}



void chars_to_ints(ConversionPackage *package, int *int_vector) {
    
    for (int i = 0; i < package->size; i++) {
        
        int_vector[i] = char_to_int(package->current_number[i]);
    }
    
    return;
}


void ints_to_chars(ConversionPackage *package, char *char_vector) {
    
    
    for (int i = 0; i < package->size; i++) {
        
        char_vector[i] = package->current_number[i];
    }
    
    return;
}
