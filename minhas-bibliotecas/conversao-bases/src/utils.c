#include <string.h>
#include "translators.c"

int valid_number(char *maybe, int base) {
    
    const int offset = 10;
    
    for (int i = 0; i < LIMIT_MAX; i++) {
        unsigned int algarism_padronized = maybe[i] & TO_INT_BITMASK;
        
        if (algarism_padronized > 'A') {
            algarism_padronized -= 'A' + offset;
        }
        
        if (algarism_padronized < 0 || algarism_padronized >= base) {
            return 0;
        }
    }
    
    return 1;
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


void slide_right(char *array) {
    
    char placeholder[LIMIT_MAX] = {0};
    int algarisms_used = 0;
    while (array[algarisms_used] != '\0') algarisms_used++;
    
    int offset = LIMIT_MAX - algarisms_used;
    for (int i = 0; i < algarisms_used; i++) {
        
        placeholder[i + offset] = array[i];
    }
    
    memcpy(array, placeholder, LIMIT_MAX / sizeof(char));
    return;
}

