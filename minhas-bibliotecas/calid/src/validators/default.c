#include <stdio.h> //
#include <string.h>
#include "../functions.h"

int greater_than(Any bound, AnyPointer input) {

    return *input.value.a_float > bound.value.a_float;
}



int less_than(Any bound, AnyPointer input) {

    return *input.value.a_float < bound.value.a_float;
}



int capitalized(Any bound, AnyPointer input) {

    int first_letter = (int)input.value.a_char[0];
    if (first_letter >= 0x41 && first_letter < 0x5B) {
        printf("passou em capitalização"); //
        return 1;
    }
    printf("vixe fio..."); //
    return 0;
}



int max_length(Any bound, AnyPointer input) {

    return strlen(input.value.a_char) > bound.value.a_int;
}



int numeric_only(Any bound, AnyPointer input) {

    for (int c = 0; c < strlen(input.value.a_char); c++) {
        char character = (char)input.value.a_char[c];
        if (character < 0x30 || character > 0x39) {
        return 0;
        }
    }
    return 1;
}
